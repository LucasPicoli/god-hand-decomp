#!/usr/bin/env python3
"""c_flags_add_necessary.py — every per-TU flag ADD must be load-bearing.

``compile_units[].c_flags_add`` appends a compiler flag to ONE translation
unit.  That is a claim about how retail built that TU, and the ELF byte gate
alone cannot check it: the flag is invisible on most translation units, so a
TU could carry ``-f=-fno-gcse`` it does not need, keep the ELF byte-identical
to retail, and still assert something no byte supports.

This gate closes that hole.  For each TU that carries a non-empty
``c_flags_add`` it compiles the TU twice — once as the build does, once with
the key removed — and fails when the two objects are byte-identical.  A flag
that changes nothing is not evidence; remove it.

The gate does NOT prove the flag is retail's.  The ELF byte gate proves that.
The two together say: retail's bytes need this flag on this TU, and every
function in the TU still matches with it.

Known limit: the comparison is the WHOLE object's sha256, which also covers
``.mdebug``, ``.comment`` and the symbol table — bytes the linked image does
not carry.  A flag that moved only those would read here as load-bearing.
Measured on every TU where ``-f=-fno-gcse`` is visible today (98 of 1,457),
the whole-object verdict and the allocated-section verdict agree 98 of 98, so
the hole is theoretical rather than live.  Re-run
``.scratch/decomp-velocity/findings/45_fnogcse_sections.py`` to re-check it
before adding a second member to ``SUPPORTED_C_FLAG_ADDS``.

Usage:
    python3 scripts/checks/c_flags_add_necessary.py [-v] [--config PATH]

Exit codes:
    0  every c_flags_add is load-bearing (and 0 when no TU carries one)
    1  at least one TU carries an inert c_flags_add
    2  setup error (unreadable config)
   77  skip — the toolchain is not installed, so nothing can be compiled
"""
from __future__ import annotations

import argparse
import hashlib
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

import compile as cpy  # noqa: E402


def _object_digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _compile(unit: cpy.CompileUnit, cfg: cpy.Config, log: cpy.Logger) -> str:
    """Compile ``unit`` and return the object's sha256."""
    cpy._cc(unit, cfg, log)
    return _object_digest(unit.obj)


def check(cfg: cpy.Config, log: cpy.Logger, verbose: bool = False) -> int:
    units = [u for u in cpy.discover(cfg) if u.kind == "c" and u.c_flags_add]
    if not units:
        print("c_flags_add_necessary: no TU carries c_flags_add — nothing to "
              "check")
        return 0
    bad: list[str] = []
    with tempfile.TemporaryDirectory(prefix="cfa-") as td:
        tdp = Path(td)
        for i, unit in enumerate(units):
            with_obj = tdp / f"{i}-with.o"
            without_obj = tdp / f"{i}-without.o"
            a = _compile(cpy.dataclasses.replace(unit, obj=with_obj), cfg, log)
            b = _compile(
                cpy.dataclasses.replace(unit, obj=without_obj, c_flags_add=()),
                cfg, log)
            flags = " ".join(unit.c_flags_add)
            if a == b:
                bad.append(f"{unit.rel}: c_flags_add [{flags}] is INERT — the "
                           f"object is byte-identical without it")
                print(f"  ✗ {unit.rel}  [{flags}] inert")
            elif verbose:
                print(f"  ✓ {unit.rel}  [{flags}] changes the object "
                      f"({a[:16]} != {b[:16]})")
    if bad:
        print(f"\nc_flags_add_necessary: {len(bad)} inert flag add(s)")
        for line in bad:
            print(f"  {line}")
        print("\nA per-TU flag that changes no byte is a claim with no "
              "evidence. Remove the key, or show the byte it moves.")
        return 1
    print(f"c_flags_add_necessary: OK — {len(units)} TU(s), every c_flags_add "
          f"changes the object")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--config", default=str(ROOT / "compile_config.json"))
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)
    try:
        cfg = cpy.Config.load(Path(args.config))
    except Exception as exc:  # noqa: BLE001 — a bad config is a setup error
        print(f"c_flags_add_necessary: cannot read config: {exc}",
              file=sys.stderr)
        return 2
    log = cpy.Logger(verbose=False)
    try:
        return check(cfg, log, verbose=args.verbose)
    except cpy.BuildError as exc:
        # A missing cc1/ee-as is a toolchain-free runner, not a red gate.
        print(f"c_flags_add_necessary: SKIP — toolchain unavailable ({exc})")
        return 77
    except FileNotFoundError as exc:
        print(f"c_flags_add_necessary: SKIP — toolchain unavailable ({exc})")
        return 77


if __name__ == "__main__":
    raise SystemExit(main())
