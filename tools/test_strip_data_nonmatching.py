#!/usr/bin/env python3
"""
test_strip_data_nonmatching.py — offline tests for strip_data_nonmatching.

No pytest required; matches the in-repo style of
`tools/ghidra-mcp-bridge/test_seed.py`. Run with:

    python tools/test_strip_data_nonmatching.py

Exit code 0 on success, 1 on first failure.
"""
from __future__ import annotations

import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import strip_data_nonmatching as m  # noqa: E402


PASSED = 0
FAILED = 0


def check(label: str, cond: bool, detail: str = "") -> None:
    global PASSED, FAILED
    if cond:
        PASSED += 1
    else:
        FAILED += 1
        print(f"FAIL: {label}: {detail}")


# --------------------------------------------------------------------------
# _extract_decls_from_header
# --------------------------------------------------------------------------


def test_extract_simple_extern() -> None:
    src = "extern u32 D_003BBF80;\n"
    decls = m._extract_decls_from_header(src)
    check("simple extern", decls == {"D_003BBF80"}, str(decls))


def test_extract_with_array() -> None:
    src = "extern int D_001234[8];\n"
    decls = m._extract_decls_from_header(src)
    check("extern array", decls == {"D_001234"}, str(decls))


def test_extract_with_multidim_array() -> None:
    src = "extern char D_ABC[8][4][2];\n"
    decls = m._extract_decls_from_header(src)
    check("extern 3d array", decls == {"D_ABC"}, str(decls))


def test_extract_const_pointer() -> None:
    src = "extern const char *D_PTR;\n"
    decls = m._extract_decls_from_header(src)
    check("extern const pointer", decls == {"D_PTR"}, str(decls))


def test_extract_struct() -> None:
    src = "extern struct Foo D_STRUCT;\n"
    decls = m._extract_decls_from_header(src)
    check("extern struct", decls == {"D_STRUCT"}, str(decls))


def test_extract_unsigned() -> None:
    src = "extern unsigned long D_UL;\n"
    decls = m._extract_decls_from_header(src)
    check("extern unsigned long", decls == {"D_UL"}, str(decls))


def test_extract_function_decl_skipped() -> None:
    """Function decls (with parens) must NOT be picked up."""
    src = "extern void D_func_001(int x);\n"
    decls = m._extract_decls_from_header(src)
    check("function decl skipped", decls == set(), str(decls))


def test_extract_skips_block_comments() -> None:
    src = """/* extern u32 D_COMMENT; */ extern u32 D_REAL;\n"""
    decls = m._extract_decls_from_header(src)
    check("skips block comment", decls == {"D_REAL"}, str(decls))


def test_extract_skips_line_comments() -> None:
    src = "// extern u32 D_LINE_COMMENT;\nextern u32 D_REAL;\n"
    decls = m._extract_decls_from_header(src)
    check("skips line comment", decls == {"D_REAL"}, str(decls))


def test_extract_multiple_in_one_file() -> None:
    src = """
#ifndef X_H
#define X_H
extern u32 D_A;
extern char D_B[16];
extern struct Foo D_C;
void f(void);   // not extern data
extern void g(int);  // function decl, skipped
#endif
"""
    decls = m._extract_decls_from_header(src)
    check(
        "multiple decls in one header",
        decls == {"D_A", "D_B", "D_C"},
        str(decls),
    )


# --------------------------------------------------------------------------
# _load_extra_decls
# --------------------------------------------------------------------------


def test_extra_decls_simple() -> None:
    with tempfile.TemporaryDirectory() as td:
        p = Path(td) / "extra.txt"
        p.write_text("D_FOO\n# comment\nD_BAR  # trailing\n\nD_BAZ\n")
        out = m._load_extra_decls(p)
        check(
            "extra decls parse + comments",
            out == {"D_FOO", "D_BAR", "D_BAZ"},
            str(out),
        )


def test_extra_decls_missing_file() -> None:
    out = m._load_extra_decls(Path("/nonexistent/path"))
    check("extra decls missing file → empty", out == set(), str(out))


def test_collect_skips_untyped_globals_header() -> None:
    with tempfile.TemporaryDirectory() as td:
        inc = Path(td) / "include" / "godhand"
        inc.mkdir(parents=True)
        (inc / "globals.h").write_text("extern char D_00400000[];\n")
        (inc / "cFoo.h").write_text("extern int D_00400010;\n")
        decls, n_inc, _ = m.collect_decls(Path(td) / "include", Path(td) / "none.txt")
        check(
            "globals.h externs do not count as typed decls",
            decls == {"D_00400010"} and n_inc == 1,
            str(decls),
        )


# --------------------------------------------------------------------------
# strip_file
# --------------------------------------------------------------------------


SAMPLE_S = """\
.include "macro.inc"

.section .data, "wa"

nonmatching D_001

dlabel D_001
    /* x */ .word 0x1
enddlabel D_001

nonmatching D_002

dlabel D_002
    /* x */ .word 0x2
enddlabel D_002

nonmatching D_003

dlabel D_003
    /* x */ .word 0x3
enddlabel D_003
"""


def test_strip_no_decls_no_change() -> None:
    stats = m.StripStats()
    out, n = m.strip_file(SAMPLE_S, set(), stats)
    check("no decls → no change", out == SAMPLE_S and n == 0, f"n={n}")


def test_strip_one_decl() -> None:
    stats = m.StripStats()
    out, n = m.strip_file(SAMPLE_S, {"D_002"}, stats)
    check("one decl → one stripped", n == 1, f"n={n}")
    check("D_002 nonmatching gone", "nonmatching D_002" not in out, "")
    check("D_002 dlabel survives", "dlabel D_002" in out, "")
    check("D_001 nonmatching survives", "nonmatching D_001" in out, "")


def test_strip_all_decls() -> None:
    stats = m.StripStats()
    out, n = m.strip_file(SAMPLE_S, {"D_001", "D_002", "D_003"}, stats)
    check("all decls → all stripped", n == 3, f"n={n}")
    check("no nonmatching left", "nonmatching " not in out, "")
    # 3 dlabel + 3 enddlabel = 6 occurrences of "dlabel D_"
    check("all dlabels survive",
          out.count("\ndlabel D_") == 3 and out.count("\nenddlabel D_") == 3,
          f"dlabel={out.count('dlabel D_')}")


def test_strip_unknown_decl_no_op() -> None:
    """Decls naming non-existent symbols don't cause errors."""
    stats = m.StripStats()
    out, n = m.strip_file(SAMPLE_S, {"D_999"}, stats)
    check("unknown decl → no strip", out == SAMPLE_S and n == 0, f"n={n}")


def test_strip_idempotent() -> None:
    stats1 = m.StripStats()
    out1, _ = m.strip_file(SAMPLE_S, {"D_002"}, stats1)
    stats2 = m.StripStats()
    out2, _ = m.strip_file(out1, {"D_002"}, stats2)
    check("strip is idempotent", out1 == out2, "")
    check("second strip → 0 strips", stats2.nonmatching_lines_stripped == 0, "")


def test_strip_with_explicit_size_arg() -> None:
    """`nonmatching D_FOO, 8` style with explicit size."""
    src = "nonmatching D_001, 8\n\ndlabel D_001\n.word 0\n"
    stats = m.StripStats()
    out, n = m.strip_file(src, {"D_001"}, stats)
    check("strips with size arg", n == 1, f"n={n}")
    check("D_001 nonmatching gone", "nonmatching D_001" not in out, "")


def test_strip_seen_count_tracks_all() -> None:
    """seen counter increments for every nonmatching, even when no strip."""
    stats = m.StripStats()
    m.strip_file(SAMPLE_S, set(), stats)
    check("seen=3 with no decls", stats.nonmatching_lines_seen == 3,
          f"seen={stats.nonmatching_lines_seen}")
    check("stripped=0", stats.nonmatching_lines_stripped == 0,
          f"stripped={stats.nonmatching_lines_stripped}")


# --------------------------------------------------------------------------
# end-to-end run() with tmp repo
# --------------------------------------------------------------------------


def _make_tmp_repo(td: Path) -> None:
    """Make a minimal repo layout under `td` for run()."""
    (td / "include").mkdir()
    (td / "config").mkdir()
    (td / "asm" / "data" / "cod").mkdir(parents=True)
    for relpath in m.DATA_SECTION_FILES:
        p = td / relpath
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(SAMPLE_S, encoding="utf-8")


def test_run_no_decls_check_clean() -> None:
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        _make_tmp_repo(td)
        rc = m.run(check=True, verbose=False, root=td)
        check("no decls + check → exit 0", rc == 0, f"rc={rc}")


def test_run_with_decl_check_dirty() -> None:
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        _make_tmp_repo(td)
        (td / "include" / "x.h").write_text("extern u32 D_002;\n")
        rc = m.run(check=True, verbose=False, root=td)
        check("decl exists, check → exit 1", rc == 1, f"rc={rc}")
        # files unchanged in --check mode
        for relpath in m.DATA_SECTION_FILES:
            check(
                f"{relpath} unchanged in --check",
                (td / relpath).read_text() == SAMPLE_S,
                "",
            )


def test_run_with_decl_writes() -> None:
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        _make_tmp_repo(td)
        (td / "include" / "x.h").write_text("extern u32 D_002;\n")
        rc = m.run(check=False, verbose=False, root=td)
        check("decl exists, write mode → exit 0", rc == 0, f"rc={rc}")
        # All four data files should have D_002 stripped
        for relpath in m.DATA_SECTION_FILES:
            content = (td / relpath).read_text()
            check(
                f"{relpath}: D_002 nonmatching stripped",
                "nonmatching D_002" not in content,
                "",
            )


def test_run_extra_decls_file_works() -> None:
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        _make_tmp_repo(td)
        (td / "config" / "data_decls_extra.txt").write_text(
            "# extra decls without C headers\nD_001\nD_003\n"
        )
        rc = m.run(check=False, verbose=False, root=td)
        check("extra decls write → exit 0", rc == 0, f"rc={rc}")
        for relpath in m.DATA_SECTION_FILES:
            content = (td / relpath).read_text()
            check(
                f"{relpath}: D_001 stripped",
                "nonmatching D_001" not in content,
                "",
            )
            check(
                f"{relpath}: D_002 still there (no decl)",
                "nonmatching D_002" in content,
                "",
            )


def test_run_idempotent_e2e() -> None:
    """Running twice produces byte-identical files."""
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        _make_tmp_repo(td)
        (td / "include" / "x.h").write_text(
            "extern u32 D_001;\nextern struct A D_002;\nextern char D_003[];\n"
        )
        m.run(check=False, verbose=False, root=td)
        snapshot = {
            relpath: (td / relpath).read_text() for relpath in m.DATA_SECTION_FILES
        }
        rc = m.run(check=True, verbose=False, root=td)
        check("after write, --check → exit 0", rc == 0, f"rc={rc}")
        for relpath, before in snapshot.items():
            check(
                f"{relpath}: byte-identical on rerun",
                (td / relpath).read_text() == before,
                "",
            )


def test_run_skips_missing_files() -> None:
    """Run shouldn't crash when DATA_SECTION_FILES are absent."""
    with tempfile.TemporaryDirectory() as tdstr:
        td = Path(tdstr)
        (td / "include").mkdir()
        rc = m.run(check=True, verbose=False, root=td)
        check("missing data files → exit 0", rc == 0, f"rc={rc}")


# --------------------------------------------------------------------------
# Smoke test against the live repo (only if invoked from repo root)
# --------------------------------------------------------------------------


def test_repo_check_clean_today() -> None:
    """At task-close time, --check against the live repo should be clean.
    Today (M3 close) zero data symbols have C decls, so the policy is a
    no-op and the asm tree is in sync.
    """
    repo = m.REPO_ROOT
    if not (repo / "asm" / "data" / "cod" / "2BBF80.data.s").exists():
        # don't run this test outside a repo with the asm tree present
        check("repo-side check skipped (no asm tree)", True, "")
        return
    rc = m.run(check=True, verbose=False, root=repo)
    check("live repo --check exits 0 today", rc == 0, f"rc={rc}")


def main() -> int:
    funcs = [v for k, v in globals().items() if k.startswith("test_") and callable(v)]
    for f in funcs:
        f()
    print()
    print(f"{PASSED} passed, {FAILED} failed")
    return 0 if FAILED == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
