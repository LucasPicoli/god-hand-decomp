"""The per-TU ``as: "sn"`` assembler route (ps2eeas.exe under wibo).

Scope mirrors ``tests/test_dual_compiler_regress.py``: lock in the pure-Python
pieces that decide *which assembler runs stage 3*, so the route cannot be
silently dropped at refactor time.  That is the exact failure this route is
most exposed to — ``_dispatch_sn`` used to strip ``--assembler`` on every SN
compile, which would have assembled an ``as: "sn"`` TU through ee-as and
presented the wrong ``dli`` expansion as this route's output.

Three surfaces:

  (a) ``compile.Config.compile_units`` accepts the new value and still rejects
      anything else;
  (b) ``compile._cc`` forwards the route to the wrapper by value;
  (c) ``ee-cc-wrap._dispatch_sn`` carries 'sn' through to sn-cc-wrap, drops the
      no-op 'ee', and refuses 'gnu' rather than dropping it silently.

The one end-to-end slice (the ``.pushsection`` guard) needs the real toolchain
and skips without it, the same way the monolith-reading tests skip on a
pre-splat checkout.
"""
from __future__ import annotations

import importlib.util
import struct
import subprocess
import sys
import textwrap
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

import compile as cm  # noqa: E402

sys.path.insert(0, str(ROOT / "scripts"))
import ps2eeas_objfix  # noqa: E402

EE_CC_WRAP = ROOT / "scripts" / "ee-cc-wrap.py"
PS2EEAS = (ROOT / "compiler" / "windows" / "ee" / "gcc" / "lib" / "gcc-lib" /
           "ee" / "2.95.2-sn-273a" / "ps2eeas.exe")
WIBO = ROOT / "tools" / "wibo"
CC1 = ROOT / "compiler" / "linux" / "ee" / "gcc" / "lib" / "gcc-lib" / "ee"

requires_toolchain = pytest.mark.skipif(
    not (PS2EEAS.exists() and WIBO.exists() and CC1.is_dir()),
    reason="EE toolchain / ps2eeas.exe / wibo not present (toolchain-free checkout)",
)


@pytest.fixture(scope="module")
def eeccwrap():
    """Load scripts/ee-cc-wrap.py as a module (it is not on sys.path)."""
    name = "ee_cc_wrap"
    spec = importlib.util.spec_from_file_location(name, EE_CC_WRAP)
    mod = importlib.util.module_from_spec(spec)
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod


def _mkcfg(**overrides) -> cm.Config:
    raw = {
        "tools": {}, "include_dirs": [], "defines": [], "c_flags": [],
        "as_flags": [], "dvp_as_flags": [], "linker_scripts": [],
        "linker_flags": [], "asm_sources_glob": [], "c_sources_glob": [],
        "vsm_sources_glob": [], "sdata_overrides": {}, "build_dir": "build",
        "output_elf": "build/out.elf", "output_map": "build/out.map",
        "preserve_in_build": [], "objdiff": {}, "section_flag_overrides": {},
        "carved_funcs": [],
    }
    raw.update(overrides)
    return cm.Config(raw=raw)


# --------------------------------------------------------------------------- #
# (a) compile_config validation
# --------------------------------------------------------------------------- #
class TestAsKeyValidation:
    @pytest.mark.parametrize("route", ["ee", "gnu", "sn"])
    def test_every_supported_route_parses(self, route):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000000.c", "compiler": "cygnus-2.96", "as": route}
        ])
        assert cfg.compile_units["src/cod/000000.c"]["as"] == route

    def test_defaults_to_ee(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000000.c", "compiler": "cygnus-2.96"}
        ])
        assert cfg.compile_units["src/cod/000000.c"]["as"] == "ee"

    def test_unknown_route_raises(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000000.c", "compiler": "cygnus-2.96", "as": "ps2eeas"}
        ])
        with pytest.raises(cm.BuildError):
            _ = cfg.compile_units

    def test_error_names_every_accepted_route(self):
        """A contributor who mistypes the value should learn all three from the
        message, not just the two it used to list."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000000.c", "compiler": "cygnus-2.96", "as": "nope"}
        ])
        with pytest.raises(cm.BuildError) as exc:
            _ = cfg.compile_units
        msg = str(exc.value)
        assert "'ee'" in msg and "'gnu'" in msg and "'sn'" in msg

    def test_sn_route_is_independent_of_the_sn_compiler(self):
        """`compiler: sn-*` must NOT imply `as: "sn"`. 776 TUs use SN cc1 and
        every one assembles byte-exact through ee-as today; ps2eeas loses to
        ee-as on reorder (func_0036D460), so the two keys stay orthogonal."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000000.c", "compiler": "sn-2.95.3-136"}
        ])
        assert cfg.compile_units["src/cod/000000.c"]["as"] == "ee"


# --------------------------------------------------------------------------- #
# (b) compile._cc forwards the route to the wrapper
# --------------------------------------------------------------------------- #
class TestCcForwardsRoute:
    """``_cc`` builds the wrapper argv. Capture it instead of running it."""

    def _argv_for(self, monkeypatch, route: str) -> list[str]:
        captured: list[list[str]] = []
        monkeypatch.setattr(cm, "run", lambda argv, log, stage=None: captured.append(argv))
        monkeypatch.setattr(cm, "_fix_section_flags", lambda *a, **k: None)
        cfg = _mkcfg(compile_units=[],
                     tools={"ee_cc_wrap": "scripts/ee-cc-wrap.py"})
        unit = cm.CompileUnit(
            src=ROOT / "src" / "cod" / "000000.c",
            obj=ROOT / "build" / "000000.o",
            kind="c",
            rel=Path("src/cod/000000.c"),
            assembler=route,
        )
        cm._cc(unit, cfg, log=None)
        assert captured, "_cc did not invoke run()"
        return captured[0]

    def test_sn_route_is_forwarded(self, monkeypatch):
        assert "--assembler=sn" in self._argv_for(monkeypatch, "sn")

    def test_gnu_route_still_forwarded(self, monkeypatch):
        assert "--assembler=gnu" in self._argv_for(monkeypatch, "gnu")

    def test_default_route_forwards_nothing(self, monkeypatch):
        argv = self._argv_for(monkeypatch, "ee")
        assert not any(a.startswith("--assembler") for a in argv)


# --------------------------------------------------------------------------- #
# (c) the SN dispatch carries the route instead of dropping it
# --------------------------------------------------------------------------- #
class TestSnDispatchForwarding:
    """``_dispatch_sn`` re-execs sn-cc-wrap.py. Capture the forwarded argv."""

    def _forwarded(self, eeccwrap, monkeypatch, argv, assembler):
        seen: list[list[str]] = []

        class _R:
            returncode = 0

        def _fake_run(cmd, **kw):
            seen.append(cmd)
            return _R()

        monkeypatch.setattr(eeccwrap.subprocess, "run", _fake_run)
        eeccwrap._dispatch_sn(argv, assembler)
        assert seen, "_dispatch_sn did not spawn sn-cc-wrap"
        return seen[0]

    def test_compiler_flag_is_stripped(self, eeccwrap, monkeypatch):
        cmd = self._forwarded(
            eeccwrap, monkeypatch,
            ["-c", "--compiler", "sn-2.95.3-136", "-o", "x.o", "x.c"], "ee")
        assert "--compiler" not in cmd and "sn-2.95.3-136" not in cmd

    def test_default_route_is_not_forwarded(self, eeccwrap, monkeypatch):
        cmd = self._forwarded(
            eeccwrap, monkeypatch, ["-c", "--assembler=ee", "-o", "x.o", "x.c"], "ee")
        assert not any(str(a).startswith("--assembler") for a in cmd)

    def test_sn_route_reaches_sn_cc_wrap(self, eeccwrap, monkeypatch):
        """The regression this class exists for: the route used to be stripped
        here unconditionally, so an `as: "sn"` TU on an SN compiler would have
        assembled through ee-as and produced the ee-as `dli` expansion."""
        cmd = self._forwarded(
            eeccwrap, monkeypatch,
            ["-c", "--compiler", "sn-2.95.3-136", "--assembler=sn", "-o", "x.o", "x.c"],
            "sn")
        assert "--assembler" in cmd
        assert cmd[cmd.index("--assembler") + 1] == "sn"
        # ...and exactly once — the original token must not survive alongside
        # the re-appended one.
        assert cmd.count("--assembler") == 1

    def test_gnu_route_on_an_sn_compiler_is_refused(self, eeccwrap, monkeypatch):
        """There is no GNU-as stage in sn-cc-wrap, so 'gnu' here can only be a
        mistake. Dying names it; the old silent strip did not."""
        with pytest.raises(SystemExit):
            self._forwarded(eeccwrap, monkeypatch,
                            ["-c", "--assembler=gnu", "-o", "x.o", "x.c"], "gnu")


# --------------------------------------------------------------------------- #
# End-to-end: the .pushsection guard, on both wrappers
# --------------------------------------------------------------------------- #
@requires_toolchain
class TestPushSectionGuard:
    """ps2eeas cannot parse ``.pushsection``, which is how INCLUDE_ASM brackets
    a carved function. The guard must die with a named reason rather than fall
    back to ee-as, which would emit the wrong bytes and read as bad C."""

    SRC = textwrap.dedent("""
        #include "include_asm.h"
        INCLUDE_ASM("nonmatching", guard_probe_asm);
        int guard_probe(int n) { return n + 1; }
    """)

    def _run(self, tmp_path, *extra):
        src = tmp_path / "guard.c"
        src.write_text(self.SRC)
        return subprocess.run(
            [sys.executable, str(EE_CC_WRAP), "-c", "-O2", "-G0",
             f"-I{ROOT / 'include'}", f"-I{ROOT / 'build' / 'asm'}",
             *extra, "-o", str(tmp_path / "guard.o"), str(src)],
            capture_output=True, text=True, cwd=ROOT)

    def test_guard_fires_on_the_cygnus_route(self, tmp_path):
        p = self._run(tmp_path, "--assembler=sn")
        assert p.returncode != 0
        assert ".pushsection" in p.stderr and "INCLUDE_ASM" in p.stderr

    def test_guard_fires_under_the_sn_dispatch(self, tmp_path):
        p = self._run(tmp_path, "--compiler", "sn-2.95.3-136", "--assembler=sn")
        assert p.returncode != 0
        assert ".pushsection" in p.stderr and "INCLUDE_ASM" in p.stderr


@requires_toolchain
class TestPs2eeasDliExpansion:
    """The route's whole reason to exist: ps2eeas expands the `dli` pseudo-op
    MSB-first (`ori rX,$zero,hi ; dsll ; ori rX,rX,lo`) where ee-as emits
    `lui/ori` plus fixed dsll16 steps. Retail matches ps2eeas at all 551
    strict-chain sites (notes/110). If this ever stops being true, every other
    test here is guarding an empty room."""

    SRC = "long long dli_probe(void) { return 0x1234567890abcdefLL; }\n"

    def _text(self, tmp_path, *extra):
        src = tmp_path / "dli.c"
        src.write_text(self.SRC)
        obj = tmp_path / f"dli{len(extra)}.o"
        p = subprocess.run(
            [sys.executable, str(EE_CC_WRAP), "-c", "-O2", "-G0",
             *extra, "-o", str(obj), str(src)],
            capture_output=True, text=True, cwd=ROOT)
        assert p.returncode == 0, p.stderr
        return obj.read_bytes()

    def test_object_links(self, tmp_path):
        """ps2eeas writes ``.symtab``'s ``sh_info`` one short of the first
        global, and GNU ld refuses the object outright — so the route was
        scorable (the scorer reads sections) but not linkable. The repair runs
        inside the wrapper; this proves an emitted object actually links."""
        obj = tmp_path / "link.o"
        src = tmp_path / "link.c"
        src.write_text(self.SRC)
        c = subprocess.run(
            [sys.executable, str(EE_CC_WRAP), "-c", "-O2", "-G0",
             "--assembler=sn", "-o", str(obj), str(src)],
            capture_output=True, text=True, cwd=ROOT)
        assert c.returncode == 0, c.stderr
        ld = subprocess.run(
            ["mipsel-linux-gnu-ld", "-r", "-o", str(tmp_path / "link.ro"), str(obj)],
            capture_output=True, text=True)
        assert ld.returncode == 0, ld.stderr

    def test_output_is_deterministic(self, tmp_path):
        """ps2eeas leaves `.mdebug` EXTR `es_flags` uninitialised, so the same
        input assembled twice gave two different objects (observed 0xB1C0 vs
        0xC1A0 — a stale heap value, both shifted by a constant 0xFE0). Nothing
        reads it (`.mdebug` is stripped at link, and the ELF is retail-identical
        either way) but `expected/build/<u>.o` compares WHOLE objects, so a TU
        on this route would flap between two hashes forever."""
        import hashlib
        src = tmp_path / "det.c"
        src.write_text(self.SRC)
        hashes = set()
        for i in range(3):
            obj = tmp_path / f"det{i}.o"
            p = subprocess.run(
                [sys.executable, str(EE_CC_WRAP), "-c", "-O2", "-G0",
                 "--assembler=sn", "-o", str(obj), str(src)],
                capture_output=True, text=True, cwd=ROOT)
            assert p.returncode == 0, p.stderr
            hashes.add(hashlib.sha256(obj.read_bytes()).hexdigest())
        assert len(hashes) == 1, f"ps2eeas output is nondeterministic: {hashes}"

    def test_routes_disagree_on_the_immediate_chain(self, tmp_path):
        ee = self._text(tmp_path)
        sn = self._text(tmp_path, "--assembler=sn")
        assert ee != sn, ("ps2eeas and ee-as produced identical objects for a "
                          "`dli` — the route is a no-op and the 551-site class "
                          "is unreachable")


# --------------------------------------------------------------------------- #
# The object repair, on synthetic ELFs (no toolchain needed)
# --------------------------------------------------------------------------- #
def _elf32(symbol_bindings: list[int], sh_info: int) -> bytes:
    """Minimal ELF32-LE with one SYMTAB section carrying the given bindings."""
    ehsize, shentsize, shnum = 0x34, 0x28, 3   # NULL, .symtab, .shstrtab
    shstr = b"\0.symtab\0.shstrtab\0"
    symtab_off = ehsize
    nsyms = len(symbol_bindings)
    syms = b"".join(
        struct.pack("<IIIBBH", 0, 0, 0, b << 4, 0, 1) for b in symbol_bindings)
    shstr_off = symtab_off + len(syms)
    shoff = shstr_off + len(shstr)
    eh = (b"\x7fELF\x01\x01\x01" + bytes(9) +
          struct.pack("<HHIIIIIHHHHHH", 1, 8, 1, 0, 0, shoff, 0,
                      ehsize, 0, 0, shentsize, shnum, 2))

    def shdr(name, typ, off, size, info, entsize):
        return struct.pack("<IIIIIIIIII", name, typ, 0, 0, off, size,
                           0, info, 4, entsize)

    shdrs = (shdr(0, 0, 0, 0, 0, 0) +
             shdr(1, 2, symtab_off, len(syms), sh_info, 16) +
             shdr(9, 3, shstr_off, len(shstr), 0, 0))
    return eh + syms + shstr + shdrs


class TestPs2eeasObjFix:
    LOCAL, GLOBAL = 0, 1

    def test_low_sh_info_is_corrected(self, tmp_path):
        """The exact shape ps2eeas emits: two extra LOCAL symbols sitting past
        the declared sh_info."""
        obj = tmp_path / "a.o"
        obj.write_bytes(_elf32([self.LOCAL] * 4 + [self.GLOBAL] * 2, sh_info=2))
        assert ps2eeas_objfix.repair_symtab_info(obj) is True
        data = obj.read_bytes()
        shoff, = struct.unpack_from("<I", data, 0x20)
        info, = struct.unpack_from("<I", data, shoff + 0x28 + 0x1C)
        assert info == 4

    def test_correct_object_is_left_alone(self, tmp_path):
        obj = tmp_path / "b.o"
        before = _elf32([self.LOCAL] * 4 + [self.GLOBAL] * 2, sh_info=4)
        obj.write_bytes(before)
        assert ps2eeas_objfix.repair_symtab_info(obj) is False
        assert obj.read_bytes() == before

    def test_unsorted_symtab_is_refused_not_patched(self, tmp_path):
        """A local symbol *after* a global cannot be described by any sh_info.
        Patching anyway would trade one malformed object for another, so this
        must raise rather than write."""
        obj = tmp_path / "c.o"
        before = _elf32([self.LOCAL, self.GLOBAL, self.LOCAL], sh_info=1)
        obj.write_bytes(before)
        with pytest.raises(ps2eeas_objfix.ObjFixError):
            ps2eeas_objfix.repair_symtab_info(obj)
        assert obj.read_bytes() == before

    def test_non_elf_input_raises(self, tmp_path):
        obj = tmp_path / "d.o"
        obj.write_bytes(b"not an elf at all")
        with pytest.raises(ps2eeas_objfix.ObjFixError):
            ps2eeas_objfix.repair_symtab_info(obj)
