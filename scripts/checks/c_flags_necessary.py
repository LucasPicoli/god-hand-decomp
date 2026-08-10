#!/usr/bin/env python3
"""c_flags_necessary.py — every per-TU compiler-flag key must be load-bearing.

Two keys on a ``compile_units[]`` entry change the flag set of ONE translation
unit:

    c_flags_drop   removes a flag from the global ``c_flags`` for that TU
    c_flags_add    appends a flag to the global ``c_flags`` for that TU

Each is a claim about how retail built that TU, and the ELF byte gate alone
cannot check it.  A compiler flag is invisible on most translation units, so a
TU can carry a key it does not need, keep
``cmp build/SLUS_215.03.elf disc_extract/SLUS_215.03`` at rc 0, and still
assert something no byte supports.

This gate closes that hole in both directions.  For every TU that carries a
key it compiles the TU twice through ``compile.py``'s own ``_cc`` — once as
the build does, once with that ONE key neutralised and every other per-TU
setting left alone — and fails when the two objects are byte-identical.  A
flag that changes nothing is not evidence.

The gate does NOT prove the flag is retail's.  The ELF byte gate proves that.
The two together say: retail's bytes need this flag on this TU, and every
function in the TU still matches with it.

THE DISPOSITION RULE for an inert key
-------------------------------------
An inert key is REMOVED.  It is never kept with a recorded reason.

1. Removal is byte-safe by definition.  An inert key moves no object byte, so
   it moves no linked byte, and the ELF gate stays green whichever way the
   question is answered.  That is precisely why it needs a rule: no
   measurement can settle it afterwards.
2. A recorded reason cannot be checked.  The config is the build, not a
   notebook.  Add the key back when a byte needs it.
3. "Inert" is measured on the TU AS IT IS BUILT TODAY — its ``compiler``, its
   ``as`` route, its other per-TU keys and its current source.  A TU whose
   compiler key changes later may need the flag again, and this gate does not
   remember.  A removal is a statement about today's build, not permanent
   knowledge.
4. Re-run the FULL build after every removal, then read
   ``cmp build/SLUS_215.03.elf disc_extract/SLUS_215.03`` unpiped.  ``$?``
   after a pipeline is the last command's status, which turns a failing gate
   green at the observation layer.  If the ELF moves, the measurement was
   wrong: put the key back.

Known limit
-----------
The comparison is the WHOLE object's sha256, which also covers ``.mdebug``,
``.comment`` and the symbol table — bytes the linked image does not carry.  A
flag that moved only those would read here as load-bearing.  Re-measured on
every TU that carries either key today, the whole-object verdict and a verdict
taken over allocated section contents plus the relocation tables agree on all
of them, so the hole is theoretical rather than live.  Re-check it before
widening either vocabulary.

The comparison also assumes the compile is reproducible.  If it were not,
every TU would read as load-bearing and this gate could never fail.  A control
test compiles one unit twice with identical flags and pins that.

Usage:
    python3 scripts/checks/c_flags_necessary.py [-v] [--config PATH]
                                                [--key c_flags_drop|c_flags_add]

Exit codes:
    0  every per-TU flag key is load-bearing.  Also 0 when the unit set was
       determined and no unit carries a key — a vacuous truth, not a no-op.
    1  at least one TU carries an inert (or unreachable) flag key
    2  void verdict — the gate ran and could not form an opinion: the config
       is unreadable or invalid, no C translation unit was discovered, or a
       compile failed while the compiler tree is installed
   77  skipped — the compiler tree is not installed, so nothing can be
       compiled
"""
from __future__ import annotations

import argparse
import dataclasses
import hashlib
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

import compile as cpy  # noqa: E402

# The per-TU keys this gate covers, in report order.  Both are fields of
# compile.CompileUnit and both neutralise to the empty tuple.
KEYS = ("c_flags_drop", "c_flags_add")


def _object_digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _compile(unit: cpy.CompileUnit, cfg: cpy.Config, log: cpy.Logger) -> str:
    """Compile ``unit`` and return the object's sha256."""
    cpy._cc(unit, cfg, log)
    return _object_digest(unit.obj)


def toolchain_present(cfg: cpy.Config) -> bool:
    """Is the unpacked compiler tree available?

    Derived from the config rather than hardcoded.  ``ee_dvp_as`` is the only
    tool entry that points INSIDE the compiler tree, and every C route needs
    that tree for cc1 and ee-as.  A checkout carries the wrapper scripts but
    not the compilers, so this separates "cannot run here" (77) from "ran and
    broke" (2).  A config that declares no such tool cannot be probed, so the
    compile itself decides.
    """
    raw = cfg.raw.get("tools", {}).get("ee_dvp_as")
    if not raw:
        return True
    p = Path(raw)
    if not p.is_absolute():
        p = ROOT / p
    return p.exists()


def check(cfg: cpy.Config, log: cpy.Logger, verbose: bool = False,
          keys: tuple[str, ...] = KEYS) -> int:
    try:
        all_units = cpy.discover(cfg)
    except cpy.BuildError as exc:
        # A config the validator rejects is a void verdict, NOT a skip: the
        # gate could not even learn what it was meant to check.
        print(f"c_flags_necessary: VOID — the config is invalid, so no unit "
              f"set could be determined: {exc}", file=sys.stderr)
        return 2
    c_units = [u for u in all_units if u.kind == "c"]
    if not c_units:
        print("c_flags_necessary: VOID — discovered 0 C translation units, so "
              "the gate examined nothing", file=sys.stderr)
        return 2

    todo = [(u, k) for u in c_units for k in keys if getattr(u, k)]
    if not todo:
        names = " or ".join(keys)
        print(f"c_flags_necessary: OK — {len(c_units)} C TU(s) discovered and "
              f"none carries {names}; nothing to check")
        return 0

    if not toolchain_present(cfg):
        print("c_flags_necessary: SKIP — the compiler tree is not installed, "
              "so no translation unit can be compiled")
        return 77

    bad: list[str] = []
    with tempfile.TemporaryDirectory(prefix="cfn-") as td:
        tdp = Path(td)
        for i, (unit, key) in enumerate(todo):
            value = getattr(unit, key)
            flags = " ".join(value)
            # A drop that names a flag the global set does not contain can
            # never fire: the filter is exact-match.  Diagnose it as its own
            # state rather than letting it read as a generic inert key.
            if key == "c_flags_drop":
                absent = [f for f in value if f not in cfg.c_flags]
                if absent:
                    bad.append(
                        f"{unit.rel}: c_flags_drop {absent} names a flag that "
                        f"is not in the global c_flags, so the exact-match "
                        f"filter can never remove it")
                    print(f"  ✗ {unit.rel}  [{flags}] UNREACHABLE — not in "
                          f"c_flags")
                    continue
            try:
                a = _compile(
                    dataclasses.replace(unit, obj=tdp / f"{i}-with.o"),
                    cfg, log)
                b = _compile(
                    dataclasses.replace(unit, obj=tdp / f"{i}-without.o",
                                        **{key: ()}),
                    cfg, log)
            except (cpy.BuildError, OSError) as exc:
                # The compiler tree is installed (checked above), so a failed
                # compile is a broken tree or a broken TU — never a skip.
                print(f"c_flags_necessary: VOID — {unit.rel}: the compile "
                      f"failed while the compiler tree is installed: {exc}",
                      file=sys.stderr)
                return 2
            if a == b:
                bad.append(f"{unit.rel}: {key} [{flags}] is INERT — the object "
                           f"is byte-identical without it")
                print(f"  ✗ {unit.rel}  [{key}: {flags}] inert")
            elif verbose:
                print(f"  ✓ {unit.rel}  [{key}: {flags}] changes the object "
                      f"({a[:16]} != {b[:16]})")

    if bad:
        print(f"\nc_flags_necessary: {len(bad)} inert or unreachable flag "
              f"key(s)")
        for line in bad:
            print(f"  {line}")
        print("\nA per-TU flag that changes no byte is a claim with no "
              "evidence. Remove the key, or show the byte it moves.")
        return 1
    print(f"c_flags_necessary: OK — {len(todo)} per-TU flag key(s) over "
          f"{len({str(u.rel) for u, _ in todo})} TU(s), every one changes its "
          f"object")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--config", default=str(ROOT / "compile_config.json"))
    ap.add_argument("--key", action="append", choices=list(KEYS),
                    help="check only this key (repeatable); default is both")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)
    try:
        cfg = cpy.Config.load(Path(args.config))
    except Exception as exc:  # noqa: BLE001 — a bad config is a void verdict
        print(f"c_flags_necessary: VOID — cannot read config: {exc}",
              file=sys.stderr)
        return 2
    log = cpy.Logger(verbose=False)
    return check(cfg, log, verbose=args.verbose,
                 keys=tuple(args.key) if args.key else KEYS)


if __name__ == "__main__":
    raise SystemExit(main())
