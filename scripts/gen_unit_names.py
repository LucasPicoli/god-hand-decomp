#!/usr/bin/env python3
"""Generate ``progress/unit_names.json`` — the objdiff/decomp.dev display-name
remap.

decomp.dev builds its file tree by splitting each objdiff unit's ``name`` on
``/``.  Our unit names are address-keyed build-object paths
(``asm/cod/000000.part17``, ``src/cod/001004c8``), so the tree's top level is
the build-stage prefix and the leaves are hex.  This remaps the *display* name
to a subsystem-foldered form (``enemy/IsTargetVisibleOrForced``) while the
on-disk ``base_path``/``target_path`` are left untouched — the build is
unaffected.

Pure resolution (``resolve_unit`` / ``compute_display_names``) takes
already-merged dicts so the logic stays trivial and unit-testable; the file
loaders that build those dicts live below.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

# A symbol whose name carries no human meaning (Ghidra auto-name); not a usable
# leaf, so the original unit basename is kept instead.
_AUTO_NAME_RE = re.compile(r"^(func|D|L|lbl|jtbl|jpt|sub|loc|float|dbl)_[0-9A-Fa-f]+$")
# Ghidra appends the function's address as a disambiguating suffix
# (``UpdateBossPhase_10B780``).  Strip it for a clean leaf.  Require >=5 hex so
# we don't clip a real 4-letter hex-ish word (e.g. ``Inter_face``); real
# suffixes are 6-digit ``0x1xxxxx`` text addresses.
_ADDR_SUFFIX_RE = re.compile(r"_[0-9A-Fa-f]{5,8}$")
# A bare hex unit leaf, i.e. the function start vaddr (``src/cod/001004c8``).
_HEX_LEAF_RE = re.compile(r"^[0-9A-Fa-f]{6,8}$")

_BUILD_PREFIXES = ("asm", "src", "rel")


def _is_auto_name(name: str) -> bool:
    return bool(_AUTO_NAME_RE.match(name))


def _clean_leaf(name: str) -> str:
    """Strip a trailing ``_<addr>`` Ghidra disambiguator from a named symbol."""
    return _ADDR_SUFFIX_RE.sub("", name)


def _named_leaf(funcname: str | None, fallback: str) -> str:
    """A clean leaf from *funcname* when it is human-meaningful, else *fallback*."""
    if funcname and not _is_auto_name(funcname):
        return _clean_leaf(funcname)
    return fallback


def _resolve_part_unit(
    basename: str,
    vaddrs: list[int],
    funcname_by_vaddr: dict[int, str],
    folder_by_vaddr: dict[int, str],
) -> str:
    """Name a carved-monolith fragment unit (``asm/cod/<obj>.partN``) from the
    vaddrs of the functions it contains.

    A fragment is the gap between two carves, so it holds zero, one, or several
    un-carved functions.  Naming rule:

    * empty (alignment-only gap)  -> ``cod/_pad/<basename>`` residue bucket
    * otherwise anchor on the first function (vaddr order) the committed symbol
      table names (falling back to the lowest vaddr when none are named), folder
      it by that anchor's subsystem, and append ``(+n)`` for the other functions
      sharing the fragment so the label stays honest about being a cluster.

    Names come *only* from ``funcname_by_vaddr`` (the committed symbol table);
    the manifest carries addresses, not names, so nothing absent from public
    source can surface and a rename in symbol_addrs.txt shows up for free.
    """
    if not vaddrs:
        return f"cod/_pad/{basename}"
    ordered = sorted(vaddrs)
    named = [v for v in ordered
             if (nm := funcname_by_vaddr.get(v)) and not _is_auto_name(nm)]
    anchor = named[0] if named else ordered[0]
    leaf = _named_leaf(funcname_by_vaddr.get(anchor), f"{anchor:08x}")
    folder = folder_by_vaddr.get(anchor, "cod")
    extra = len(vaddrs) - 1
    suffix = f" (+{extra})" if extra > 0 else ""
    return f"{folder}/{leaf}{suffix}"


def resolve_unit(
    name: str,
    funcname_by_vaddr: dict[int, str],
    vaddr_by_funcname: dict[str, int],
    folder_by_vaddr: dict[int, str],
    partfuncs_by_unit: dict[str, list[int]] | None = None,
) -> str:
    """Map one objdiff unit ``name`` to its ``<folder>/<leaf>`` display name.

    Drops the build-stage prefix and routes by subsystem/library folder where
    the unit's start vaddr is known; unresolved engine code falls into the
    ``cod/`` residue folder.  Idempotent: a name with no build-stage head is
    returned unchanged.

    ``partfuncs_by_unit`` (orig unit name -> contained functions) lets carved
    monolith fragments (``asm/cod/<obj>.partN``) be named after the function(s)
    they hold; absent it (or absent the unit) they fall back to ``cod/`` residue.
    """
    parts = name.split("/")
    head = parts[0]

    # Already a display name (no build-stage prefix) -> stable.
    if head not in _BUILD_PREFIXES:
        return name

    # REL units are already meaningfully pathed; keep verbatim.
    if head == "rel":
        return name

    if head == "src" and len(parts) >= 2 and parts[1] == "cod":
        # Already-foldered TU: src/cod/<subsys>/<rest...> -> <subsys>/<rest...>
        if len(parts) >= 4:
            return parts[2] + "/" + "/".join(parts[3:])
        # Flat src/cod/<leaf>: hex leaf resolves to a vaddr; word leaf is residue.
        leaf = parts[2]
        folder = "cod"
        if _HEX_LEAF_RE.match(leaf):
            vaddr = int(leaf, 16)
            leaf = _named_leaf(funcname_by_vaddr.get(vaddr), leaf)
            folder = folder_by_vaddr.get(vaddr, folder)
        return folder + "/" + leaf

    if head == "asm":
        sub = parts[1] if len(parts) >= 2 else ""
        if sub == "nonmatching" and len(parts) == 3:
            func = parts[2]
            vaddr = vaddr_by_funcname.get(func)
            folder = "cod"
            if vaddr is not None:
                leaf = _named_leaf(funcname_by_vaddr.get(vaddr, func), func)
                folder = folder_by_vaddr.get(vaddr, folder)
            else:
                leaf = _named_leaf(func, func)
            return folder + "/" + leaf
        if sub == "data":
            return "data/" + "/".join(parts[2:])
        if sub == "cod":
            basename = "/".join(parts[2:])
            if partfuncs_by_unit is not None and name in partfuncs_by_unit:
                return _resolve_part_unit(
                    basename, partfuncs_by_unit[name],
                    funcname_by_vaddr, folder_by_vaddr,
                )
            return "cod/" + basename
        # Generic asm/<x>/<rest> -> <x>/<rest>
        return sub + "/" + "/".join(parts[2:])

    return name


def compute_display_names(
    units: list[str],
    funcname_by_vaddr: dict[int, str],
    vaddr_by_funcname: dict[str, int],
    folder_by_vaddr: dict[int, str],
    partfuncs_by_unit: dict[str, list[int]] | None = None,
) -> dict[str, str]:
    """Resolve every unit, guaranteeing unique display names.

    On collision the original unit basename is appended, deterministically
    (units are processed in sorted order so the result is input-order-stable).
    """
    out: dict[str, str] = {}
    used: set[str] = set()
    for orig in sorted(units):
        display = resolve_unit(
            orig, funcname_by_vaddr, vaddr_by_funcname, folder_by_vaddr,
            partfuncs_by_unit=partfuncs_by_unit,
        )
        if display in used:
            display = f"{display}__{orig.split('/')[-1]}"
        used.add(display)
        out[orig] = display
    return out


# --------------------------------------------------------------------------- #
# Loaders: on-disk files -> the dicts the resolver consumes
# --------------------------------------------------------------------------- #
_SYM_LINE_RE = re.compile(
    r"^\s*([A-Za-z_$][\w$]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;\s*//\s*type:func\b"
)


def load_symbol_addrs(path: Path) -> tuple[dict[int, str], dict[str, int]]:
    """Parse splat ``symbol_addrs.txt`` ``type:func`` lines into
    ``(funcname_by_vaddr, vaddr_by_funcname)``.  Non-func symbols are ignored —
    the remap only resolves function units."""
    by_vaddr: dict[int, str] = {}
    by_func: dict[str, int] = {}
    if not path.exists():
        return by_vaddr, by_func
    for line in path.read_text().splitlines():
        m = _SYM_LINE_RE.match(line)
        if not m:
            continue
        name, vaddr = m.group(1), int(m.group(2), 16)
        by_vaddr[vaddr] = name
        by_func[name] = vaddr
    return by_vaddr, by_func


def load_folder_map(unit_subsystems_path: Path, function_categories_path: Path) -> dict[int, str]:
    """Merge engine subsystems (``unit_subsystems.json``: ``{subsystems:
    {name: [vaddr]}}``) and library categories (``function_categories.json``:
    ``{categories: {name: [vaddr]}}``) into one ``vaddr -> folder`` map."""
    folder: dict[int, str] = {}
    for path, key in (
        (function_categories_path, "categories"),
        (unit_subsystems_path, "subsystems"),  # engine subsystems win on overlap
    ):
        if not path.exists():
            continue
        data = json.loads(path.read_text())
        for name, addrs in data.get(key, {}).items():
            for a in addrs:
                folder[int(a, 16)] = name
    return folder


def load_part_funcs(path: Path) -> dict[str, list[int]]:
    """Load ``progress/unit_part_funcs.json`` — the carved-monolith fragment
    manifest mapping each ``asm/cod/<obj>.partN`` unit to the vaddrs of the
    functions it contains.  Each vaddr (a ``"0x..."`` string) is normalised to
    ``int`` so the resolver can fold/sort by address.  Missing file -> empty map
    (the resolver then falls back to ``cod/`` residue naming).

    The manifest stores addresses, not names — names come from the committed
    symbol table at resolve time, so nothing absent from public source leaks in.
    Generated locally by ``scripts/gen_part_funcs.py`` from the gitignored
    monolithic asm; committed so the toolchain-free publish path can consume it.
    """
    if not path.exists():
        return {}
    raw = json.loads(path.read_text())
    return {unit: [int(str(v), 0) for v in vaddrs] for unit, vaddrs in raw.items()}


def load_units(objdiff_json_path: Path) -> list[str]:
    """Read the ordered list of *original* unit names from ``objdiff.json``.

    The original name is recovered from ``base_path`` (``build/<orig>.o`` minus
    the leading build dir and ``.o`` suffix), so generation is stable even when
    the ``name`` field has already been remapped by a previous run.  Falls back
    to ``name`` when a unit has no ``base_path``.
    """
    data = json.loads(objdiff_json_path.read_text())
    names: list[str] = []
    for u in data.get("units", []):
        base_path = u.get("base_path")
        if base_path:
            parts = Path(base_path).with_suffix("").parts  # drop ".o"
            names.append("/".join(parts[1:]))              # drop leading build dir
        else:
            names.append(u["name"])
    return names


# --------------------------------------------------------------------------- #
# Entry point: regenerate progress/unit_names.json
# --------------------------------------------------------------------------- #
_ROOT = Path(__file__).resolve().parent.parent


def generate(root: Path = _ROOT) -> dict[str, str]:
    """Compute the remap from the repo's current config and return the
    changed-only ``{orig: display}`` mapping (identity entries are dropped; the
    consumer falls back to the original name)."""
    funcname_by_vaddr, vaddr_by_funcname = load_symbol_addrs(root / "config" / "symbol_addrs.txt")
    folder_by_vaddr = load_folder_map(
        root / "progress" / "unit_subsystems.json",
        root / "progress" / "function_categories.json",
    )
    partfuncs_by_unit = load_part_funcs(root / "progress" / "unit_part_funcs.json")
    units = load_units(root / "objdiff.json")
    full = compute_display_names(
        units, funcname_by_vaddr, vaddr_by_funcname, folder_by_vaddr,
        partfuncs_by_unit=partfuncs_by_unit,
    )
    return {orig: disp for orig, disp in full.items() if disp != orig}


def apply_to_report(report: dict, mapping: dict[str, str]) -> int:
    """Rewrite each unit's ``name`` in *report* via *mapping* (orig -> display),
    in place; return the number changed.  ``measures`` (the scoring) is never
    touched — this is a display-only transform.

    Used at publish time on a *copy* of report.json so the committed report
    keeps its original ``src/cod/<addr>`` names (which the tracker tooling —
    mark_complete, check_tu_complete — resolves to source files by name).
    """
    changed = 0
    for u in report.get("units", []):
        new = mapping.get(u.get("name", ""), u.get("name"))
        if new != u.get("name"):
            u["name"] = new
            changed += 1
    return changed


def main() -> None:
    ap = argparse.ArgumentParser(description="objdiff/decomp.dev unit-name remap")
    ap.add_argument("--root", type=Path, default=_ROOT)
    ap.add_argument(
        "--apply-report",
        nargs=2,
        metavar=("IN", "OUT"),
        help="apply the committed progress/unit_names.json to report IN, write display-named OUT",
    )
    args = ap.parse_args()

    if args.apply_report:
        in_path, out_path = (Path(p) for p in args.apply_report)
        mapping = json.loads((args.root / "progress" / "unit_names.json").read_text())
        report = json.loads(in_path.read_text())
        n = apply_to_report(report, mapping)
        out_path.write_text(json.dumps(report, indent=2) + "\n")
        print(f"wrote {out_path} ({n} unit names remapped for decomp.dev)")
        return

    mapping = generate(args.root)
    out_path = args.root / "progress" / "unit_names.json"
    out_path.write_text(json.dumps(mapping, indent=2, sort_keys=True) + "\n")
    print(f"wrote {out_path} ({len(mapping)} remapped units)")


if __name__ == "__main__":
    main()
