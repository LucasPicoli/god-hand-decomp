"""Make the repo root importable so `import compile` works under pytest.

The build entry point lives at the repo root as ``compile.py``; pytest's
default rootdir is ``tests/``, so we prepend the repo root explicitly here
rather than relying on per-test ``sys.path`` munging.
"""
from __future__ import annotations

import sys
from pathlib import Path

import pytest

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

# --------------------------------------------------------------------------- #
# ``requires_monolith`` marker.
#
# The monolithic disassembly ``asm/cod/000000.s`` is a *generated* artifact
# (splat output from the non-redistributable ELF); it is not committed, so a
# fresh checkout — every CI run, every fork clone before ``make setup`` — does
# not have it.  Any test that reads it (directly, or via ``compile.maybe_carve``)
# must skip when it is absent, otherwise it errors on toolchain-free CI.
#
# Decorate such tests with ``@pytest.mark.requires_monolith`` instead of
# hand-rolling an ``if not …exists(): pytest.skip(...)`` guard — this hook
# applies the skip centrally so a new carve/monolith test cannot silently
# forget it (the historical cause of the "PR-checks red on main" breakage).
# --------------------------------------------------------------------------- #

_MONOLITH = REPO_ROOT / "asm" / "cod" / "000000.s"


def pytest_configure(config: pytest.Config) -> None:
    config.addinivalue_line(
        "markers",
        "requires_monolith: skip when asm/cod/000000.s (pre-splat checkout) is absent",
    )


def pytest_collection_modifyitems(
    config: pytest.Config, items: list[pytest.Item]
) -> None:
    if _MONOLITH.exists():
        return
    skip = pytest.mark.skip(reason="asm/cod/000000.s not present (pre-splat checkout)")
    for item in items:
        if "requires_monolith" in item.keywords:
            item.add_marker(skip)
