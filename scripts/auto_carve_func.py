#!/usr/bin/env python3
"""auto_carve_func.py — ensure a single function has a carve entry.

Before a matched function can be integrated, it needs a carve: the
carve helpers in :mod:`scripts.carver` (:func:`_atomic_auto_carve` +
:func:`_auto_carve_uncarved`) write the two things integration requires:

  1. A new ``carved_funcs[]`` entry in ``compile_config.json``.
  2. An ``INCLUDE_ASM("nonmatching", <name>);`` line in the target TU.

Without those two writes, integration rejects the match::

    no carve entry for '<name>' in compile_config.json;
    add one before integrating.

This helper performs exactly that carve for one named function so the
two-step (carve, then integrate) need not be done by hand.

Behaviour:

- Look up the candidate dict from the local target metadata.
- Idempotent: re-running on an already-carved function exits 0 with
  no writes (the underlying ``_auto_carve_uncarved`` returns
  ``"already_carved"``).
- Exit codes:

  * ``0`` — carve already present OR newly written; ``compile_config.json``
    + the TU now have what integration needs.
  * ``2`` — candidate metadata could not be resolved (not in the local
    target metadata, no usable per-function settings, etc.).  Stable rc
    so the bash caller can branch.
  * ``3`` — auto-carve raised :exc:`scripts.carver.CarveError` (I/O
    or structural failure).  The wrapper's ``cleanup_on_fail`` trap
    reverts any partial writes. (Pre-Phase 2 the carve primitive lived
    elsewhere; an earlier refactor moved it to `scripts.carver` and
    reclassified the exception class.)

Stdout: ``carved`` or ``already_carved`` on success, mirroring
:func:`_auto_carve_uncarved`'s return value (handy for the bash log).
Stderr: human-readable diagnostic on failure.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Use the carver module's primitives as the single source of truth so
# this script stays in sync with the carving behaviour.  A later
# refactor moved the carve helpers to ``scripts.carver``; the import
# ``from scripts.carver import ...`` requires the **repo root** (parent
# of ``scripts/``) on ``sys.path`` so the ``scripts`` package is
# discoverable.  When invoked as
# ``python3 scripts/auto_carve_func.py NAME``, Python auto-prepends only
# ``scripts/`` to ``sys.path`` (the script's own directory), which is why
# the pre-extraction bare-module import worked but
# ``from scripts.carver`` does not without this insertion.  Discovered by
# the deferred-smoke validation when worker subprocesses hit
# ``ModuleNotFoundError: scripts``.  We insert ``ROOT`` first and keep
# ``ROOT / "scripts"`` for any legacy bare-module imports that may still
# live downstream.
sys.path.insert(0, str(ROOT))
sys.path.insert(1, str(ROOT / "scripts"))

DECOMP_TARGETS = ROOT / "progress" / "decomp_targets.json"
FUNCTION_ATLAS = ROOT / "progress" / "function_atlas.json"
# Mirrors scripts.carver._DEFAULT_ASM_MODULE — the monolith every uncarved game
# function still lives in. Hard-coded (not imported) to keep this resolver free
# of the heavier carver import at module load.
_MONOLITH_ASM = "asm/cod/000000.s"


def _load_from_decomp_targets(name: str) -> dict | None:
    if not DECOMP_TARGETS.exists():
        return None
    try:
        data = json.loads(DECOMP_TARGETS.read_text())
    except (OSError, json.JSONDecodeError):
        return None
    for c in data.get("candidates", []) or []:
        if c.get("name") == name:
            return c
    return None


def _load_from_atlas(name: str) -> dict | None:
    """Fallback when ``name`` is absent from ``decomp_targets.json``.

    ``decomp_targets.json`` only emits a per-tier *quota* subset of candidates,
    so the vast majority of live monolith functions never appear there — a found
    byte-match for any of them used to fail the carve with "no candidate
    metadata" even though the function is perfectly carveable. Derive the minimal
    carve metadata (address + size) from the full ``function_atlas.json`` instead;
    the boundary is then cross-checked against the real asm by
    ``carver._corrected_size_bytes``, so a slightly-stale size self-corrects.

    Scoped to monolith functions (``asm/cod/000000.s``). A name not present in
    the monolith still fails the carve cleanly downstream, exactly as before.
    """
    if not FUNCTION_ATLAS.exists():
        return None
    try:
        data = json.loads(FUNCTION_ATLAS.read_text())
    except (OSError, json.JSONDecodeError):
        return None
    for f in data.get("functions", []) or []:
        if isinstance(f, dict) and f.get("name") == name and f.get("vaddr"):
            return {
                "name": name,
                "address": f["vaddr"],
                "size_bytes": int(f.get("size", 4)),
                "asm_module_path": _MONOLITH_ASM,
                "include_asm_permanent": False,
                "permanent_reason": "",
                "notes": "atlas-fallback (absent from decomp_targets quota)",
            }
    return None


def load_candidate_dict(name: str) -> dict | None:
    return _load_from_decomp_targets(name) or _load_from_atlas(name)


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("name", help="canonical function name, e.g. ac3cnv_alloc_hndl")
    ap.add_argument(
        "--config",
        default=str(ROOT / "compile_config.json"),
        help="compile_config.json path (default: project root)",
    )
    args = ap.parse_args(argv)

    name = args.name.strip()
    if not name:
        print("auto_carve_func: empty FUNCTION_NAME", file=sys.stderr)
        return 2

    cand = load_candidate_dict(name)
    if cand is None:
        print(
            f"auto_carve_func: no candidate metadata for {name!r}; "
            f"not found in {DECOMP_TARGETS.name}",
            file=sys.stderr,
        )
        return 2

    # Carving primitives now live in `scripts.carver`; this script
    # consumes the module's
    # `CarveSession.carve_one()` (behaviour-preserving — no internal
    # atomic wrap, the caller's rollback handling stays in place). The
    # exception class becomes `CarveError`.
    try:
        from scripts.carver import (  # noqa: PLC0415
            CarveSession,
            CarveError,
        )
    except ImportError as e:
        print(f"auto_carve_func: failed to import scripts.carver: {e}",
              file=sys.stderr)
        return 3

    session = CarveSession(root=ROOT)
    try:
        result = session.carve_one(
            name, cand, config_path=Path(args.config),
        )
    except CarveError as exc:
        print(f"auto_carve_func: {exc}", file=sys.stderr)
        return 3
    except Exception as exc:  # noqa: BLE001
        print(f"auto_carve_func: unexpected: {type(exc).__name__}: {exc}",
              file=sys.stderr)
        return 3

    print(result)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
