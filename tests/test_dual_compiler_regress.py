"""Unit tests for the dual-compiler regression harness.

Scope: lock in the pure-Python pieces of
``scripts/checks/dual_compiler_regress.py`` so the harness's
ratchet semantics don't silently regress at refactor time. The
slow end-to-end sweep (compile every src/cod/*.c through both
wrappers, ~2-3 s wall) runs via ``scripts/session_check.sh``;
here we exercise the small pure helpers and run a single-TU
sanity slice that proves the spot-check still holds
(src/cod/0033c8.c cygnus = expected, sn accessor sections =
expected).
"""
from __future__ import annotations

import importlib.util
import struct
import subprocess
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]


# --------------------------------------------------------------------------- #
# Module loader — the harness lives under scripts/checks/ and isn't on
# sys.path by default. Load it once per session.
# --------------------------------------------------------------------------- #
@pytest.fixture(scope="module")
def harness():
    name = "dual_compiler_regress"
    spec = importlib.util.spec_from_file_location(
        name,
        ROOT / "scripts" / "checks" / "dual_compiler_regress.py",
    )
    mod = importlib.util.module_from_spec(spec)
    # Register in sys.modules *before* exec so the dataclass machinery
    # (which looks the class's module up via sys.modules during forward-
    # ref resolution) can find it.
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod


# --------------------------------------------------------------------------- #
# Section classifier — anchor every section kind we care about
# --------------------------------------------------------------------------- #
class TestClassify:
    def test_text_section_is_text(self, harness):
        s = harness.Section(name=".text.func_001234", sh_type=1, sh_size=0x40, sh_off=0x100)
        assert harness._classify(s) == "text"

    def test_plain_text_is_text(self, harness):
        s = harness.Section(name=".text", sh_type=1, sh_size=0, sh_off=0)
        assert harness._classify(s) == "text"

    def test_rel_text_is_rel_text(self, harness):
        s = harness.Section(name=".rel.text.func_001234", sh_type=9, sh_size=0x10, sh_off=0x200)
        assert harness._classify(s) == "rel.text"

    def test_data_kinds(self, harness):
        for name in (".data", ".rodata", ".sdata"):
            s = harness.Section(name=name, sh_type=1, sh_size=0, sh_off=0)
            assert harness._classify(s) == "data", name

    def test_bss_kinds(self, harness):
        for name in (".bss", ".sbss"):
            s = harness.Section(name=name, sh_type=8, sh_size=0, sh_off=0)
            assert harness._classify(s) == "bss", name

    def test_symtab_family(self, harness):
        for name in (".symtab", ".strtab", ".shstrtab"):
            s = harness.Section(name=name, sh_type=2, sh_size=0, sh_off=0)
            assert harness._classify(s) == "symtab", name

    def test_mdebug_is_mdebug(self, harness):
        s = harness.Section(name=".mdebug", sh_type=0x70000005, sh_size=0xf7c, sh_off=0x4c)
        assert harness._classify(s) == "mdebug"

    def test_unknown_falls_through_to_other(self, harness):
        s = harness.Section(name=".weird.section", sh_type=1, sh_size=0, sh_off=0)
        assert harness._classify(s) == "other"


# --------------------------------------------------------------------------- #
# ELF reader — feed it a real expected/build/ artifact and lock in the
# headline shape
# --------------------------------------------------------------------------- #
EXPECTED_0033C8 = ROOT / "expected" / "build" / "src" / "cod" / "0033c8.o"


@pytest.mark.skipif(
    not EXPECTED_0033C8.exists(),
    reason="expected/build artifacts not present (fresh clone)",
)
class TestReadSections:
    def test_reads_elf32_le(self, harness):
        data, secs = harness._read_sections(EXPECTED_0033C8)
        assert data[:4] == b"\x7fELF"
        # Every src/cod/0033c8.o we ever produced has > 20 sections.
        assert len(secs) > 20

    def test_contains_accessor_sections(self, harness):
        _, secs = harness._read_sections(EXPECTED_0033C8)
        names = {s.name for s in secs}
        # These accessor sections are the spot-check anchors.
        assert ".text.Obj33C8_GetByte_D" in names
        assert ".text.Obj33C8_GetField_14" in names
        assert ".text.Obj33C8_GetShort_98" in names

    def test_rejects_non_elf(self, harness, tmp_path):
        bogus = tmp_path / "notelf.o"
        bogus.write_bytes(b"\x00" * 64)
        with pytest.raises(SystemExit):
            harness._read_sections(bogus)


# --------------------------------------------------------------------------- #
# Section comparator — synthesise two identical files and one diverging
# pair, exercise the OK / MISS / MISSING / EXTRA paths
# --------------------------------------------------------------------------- #
def _section_off_size(obj_path: Path, section_name: str) -> tuple[int, int]:
    """(file_offset, size) of ``section_name`` in ``obj_path`` via readelf -SW.

    Resolved at run time: the 0033c8.o section layout shifts whenever its TU
    gains/loses functions, so a hard-coded byte offset goes stale (the old
    0xfd0 pin fell outside .text.func_0033C918 once the TU grew).
    """
    out = subprocess.check_output(
        ["readelf", "-SW", str(obj_path)], text=True, stderr=subprocess.DEVNULL,
    )
    for line in out.splitlines():
        # Drop the "[ N]" index brackets so the section name is a clean token
        # regardless of one- vs two-digit index spacing.
        toks = line.replace("[", " ").replace("]", " ").split()
        if section_name in toks:
            i = toks.index(section_name)  # name, TYPE, ADDR, OFF, SIZE, ...
            return int(toks[i + 3], 16), int(toks[i + 4], 16)
    raise AssertionError(f"{section_name} not found in {obj_path}")


@pytest.mark.skipif(
    not EXPECTED_0033C8.exists(),
    reason="expected/build artifacts not present (fresh clone)",
)
class TestCompareSections:
    def test_self_compare_is_all_ok(self, harness):
        rows = harness._compare_sections(EXPECTED_0033C8, EXPECTED_0033C8)
        statuses = {status for _, _, status in rows}
        assert statuses == {"OK"}

    def test_byte_flip_produces_miss(self, harness, tmp_path):
        copy = tmp_path / "0033c8.o"
        b = bytearray(EXPECTED_0033C8.read_bytes())
        # Flip a byte in the middle of .text.func_0033C918. Resolve the section's
        # file range at run time (the .o layout shifts as the 0033c8 TU changes);
        # any byte inside the section triggers a MISS on it.
        off, size = _section_off_size(EXPECTED_0033C8, ".text.func_0033C918")
        b[off + size // 2] ^= 0xff
        copy.write_bytes(bytes(b))
        rows = harness._compare_sections(EXPECTED_0033C8, copy)
        statuses = {n: s for n, _, s in rows}
        assert statuses[".text.func_0033C918"] == "MISS"
        # Other sections still byte-equal.
        assert statuses[".text.Obj33C8_GetByte_D"] == "OK"


# --------------------------------------------------------------------------- #
# Verdict + summary aggregation
# --------------------------------------------------------------------------- #
class TestVerdict:
    def test_all_ok_yields_ok(self, harness):
        rows = [
            (".text.foo", "text", "OK"),
            (".text.bar", "text", "OK"),
        ]
        assert harness._tu_verdict(rows) == "OK"

    def test_one_miss_yields_working(self, harness):
        rows = [
            (".text.foo", "text", "OK"),
            (".text.bar", "text", "MISS"),
        ]
        assert harness._tu_verdict(rows) == "WORKING"

    def test_all_miss_yields_miss(self, harness):
        rows = [
            (".text.foo", "text", "MISS"),
            (".text.bar", "text", "MISS"),
        ]
        assert harness._tu_verdict(rows) == "MISS"

    def test_none_yields_fail(self, harness):
        assert harness._tu_verdict(None) == "FAIL"

    def test_summarise_splits_contract_vs_info(self, harness):
        rows = [
            (".text.foo", "text", "OK"),       # contract
            (".text.bar", "text", "MISS"),     # contract
            (".mdebug",   "mdebug", "MISS"),   # informational
            (".symtab",   "symtab", "OK"),     # informational
        ]
        co, ct, io, it = harness._summarise(rows)
        assert (co, ct) == (1, 2)
        assert (io, it) == (1, 2)


# --------------------------------------------------------------------------- #
# Single-TU end-to-end smoke — locks in the
# "src/cod/0033c8.c with sn-2.95.3-136, accessor sections still match"
# spot-check, baked into the harness.
# Skipped when toolchain or expected/build is missing (fresh clone).
# --------------------------------------------------------------------------- #
@pytest.mark.skipif(
    not (ROOT / "tools" / "wibo").exists() or not EXPECTED_0033C8.exists(),
    reason="SN toolchain (wibo) or expected/build not present",
)
def test_0033c8_dual_compiler_spot_check():
    """The smoke spot-check, baked into the harness.

    With cygnus-2.96, src/cod/0033c8.o byte-equals
    expected/build/src/cod/0033c8.o (the load-bearing back-compat
    contract). With sn-2.95.3-136, every named-accessor .text.*
    section still matches (the empirical finding we assert here).
    """
    result = subprocess.run(
        [
            sys.executable,
            str(ROOT / "scripts" / "checks" / "dual_compiler_regress.py"),
            "--only", "0033c8",
            "-v",
        ],
        capture_output=True,
        text=True,
        cwd=str(ROOT),
    )
    assert result.returncode == 0, (
        f"harness exited {result.returncode}:\n"
        f"--- stdout ---\n{result.stdout}\n--- stderr ---\n{result.stderr}"
    )
    out = result.stdout
    # Cygnus must be byte-equal across every section (no MISS in the cyg
    # column for this TU).
    assert "cyg: OK" in out, out

    # Anchor every named accessor explicitly: each must show ``OK`` in
    # the SN column, i.e. the SN cc1 emits identical bytes for the
    # plain integer-accessor shapes that 0033c8.c is a textbook example
    # of. This is the spot-check anchor.
    ACCESSORS = [
        ".text.Obj33C8_SetFields_78_7C",
        ".text.Obj33C8_GetShort_98",
        ".text.Obj33C8_GetField_14",
        ".text.Obj33C8_GetByte_D",
        ".text.Obj33C8_GetField_10",
        ".text.Obj33C8_GetField_18",
        ".text.Obj33C8_GetShort_24",
        ".text.Obj33C8_GetField_28",
        ".text.Obj33C8_GetField_2C_OrZeroIfNull",
        ".text.Obj33C8_GetField_30",
        ".text.Obj33C8_GetField_34",
        ".text.Obj33C8_GetField_CC",
        ".text.Obj33C8_GetShort_E0",
        ".text.Obj33C8_GetShortArrayE2_idx",
    ]
    for name in ACCESSORS:
        # Two `OK` columns on the same line = cygnus AND sn match.
        line = next(
            (ln for ln in out.splitlines() if name in ln),
            None,
        )
        assert line is not None, f"section {name} missing from harness output\n{out}"
        oks = line.count("OK")
        assert oks >= 2, (
            f"section {name} expected to match under both compilers; "
            f"line={line!r}"
        )


# --------------------------------------------------------------------------- #
# CLI surface — `--only` filter, exit codes
# --------------------------------------------------------------------------- #
class TestCli:
    def test_help_runs(self):
        r = subprocess.run(
            [sys.executable,
             str(ROOT / "scripts" / "checks" / "dual_compiler_regress.py"),
             "--help"],
            capture_output=True, text=True, cwd=str(ROOT),
        )
        assert r.returncode == 0
        assert "dual-compiler regression" in r.stdout.lower()

    def test_only_filter_restricts_to_matching_tu(self):
        if not (ROOT / "tools" / "wibo").exists():
            pytest.skip("SN toolchain not present")
        r = subprocess.run(
            [sys.executable,
             str(ROOT / "scripts" / "checks" / "dual_compiler_regress.py"),
             "--only", "0033c8"],
            capture_output=True, text=True, cwd=str(ROOT),
        )
        # Only one TU in the output.
        assert "1 TU" in r.stdout
        assert "0033c8.c" in r.stdout
        assert "001d00.c" not in r.stdout
