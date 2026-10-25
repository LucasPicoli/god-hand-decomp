#!/usr/bin/env python3
"""check_naming_sync.py — naming-propagation consistency ratchet.

CONTRIBUTING rule 3 requires a function's canonical name to land in THREE places in the
same commit:

  1. ``compile_config.json::carved_funcs[].name`` (the carve registry),
  2. ``config/symbol_addrs.txt`` (the splat/labels symbol table, keyed by
     address), and
  3. the defining C translation unit (TU) — either as
     ``INCLUDE_ASM("...", <NAME>);`` (still nonmatching) or as the matched
     C body's ``__attribute__((section(".text.<NAME>")))`` wrapper.

Nothing previously *verified* this agreement, so a rename could land in one
surface and silently diverge from the others.  This
script is the mechanical detector.  **It renames nothing** — it only asserts
agreement and fails (exit 1) on divergence.

It checks agreement, not only that the carve name EXISTS in symbol_addrs:
where a carve's address is present in symbol_addrs, the names must MATCH; and
where a carve owns a real-C / INCLUDE_ASM TU, the carve name must appear in
that TU.

WHAT IS CHECKED
---------------
For every ``carved_funcs[]`` entry that has a ``name`` and a ``vaddr``:

  * **symbol_addrs agreement (hard fail).**  If the carve's ``vaddr`` is
    present in ``config/symbol_addrs.txt`` but the name at that address does
    NOT include the carve name, that is a true divergence -> FAIL.  The
    carve and the symbol table disagree about what lives at one address.

  * **symbol_addrs absence (ratcheted).**  If the carve's ``vaddr`` is ABSENT
    from symbol_addrs entirely, the name is unverifiable there.  On the
    current tree this is a pre-existing, build-passing state for two
    categories (see ALLOWLIST below): library-transplant symbols whose
    canonical name was never seeded, and carves still resolved in-place by a
    ``glabel`` inside ``asm/cod/000000.s``.  These are recorded in the
    committed allowlist ``config/naming_sync_allowlist.txt`` and tolerated.
    Any NEW absence (a fresh carve whose name never reached symbol_addrs) is
    NOT allowlisted and FAILS — the guard against a missing line.

  * **TU agreement (hard fail).**  If the carve owns a ``.c`` TU, the carve
    name must appear in that TU as ``INCLUDE_ASM(..., <NAME>)``,
    ``.text.<NAME>`` (matched-C section wrapper), or a bare token.  A carve
    whose TU never mentions its name is a divergence -> FAIL.

OUT OF BAND / OUT OF SCOPE
--------------------------
  * **Ghidra is explicitly out of band.**  This check reads only the three
    in-tree text surfaces (compile_config.json, symbol_addrs.txt, the C TUs)
    and never talks to a Ghidra process.  symbol_addrs.txt's ghidra-seed block IS read
    (it is committed text), but the live Ghidra database is not.
  * Renaming anything (this is a detector, not a fixer).
  * Local-variable naming (deferred).
  * eu/jp sibling symbol files (us only; a follow-up if this proves useful).
  * ``.s`` TUs (e.g. ``src/cod/eesyscalls.s`` syscall stubs): not C, so the
    TU-scan is skipped; the symbol_addrs axis still applies.

ALLOWLIST
---------
``config/naming_sync_allowlist.txt`` lists carve names whose ``vaddr`` is
legitimately absent from symbol_addrs at the time of the baseline.  Two
documented categories (see that file's header).  The allowlist only excuses
*symbol_addrs absence* — it never excuses a name *mismatch* at a shared
address, nor a TU disagreement; those always fail.

Usage:
    python3 scripts/check_naming_sync.py            # check; exit 1 on divergence
    python3 scripts/check_naming_sync.py --list      # print the divergence report
    python3 scripts/check_naming_sync.py --update     # rewrite the allowlist to the
                                                      # current set of symbol_addrs
                                                      # absences (use ONLY when you have
                                                      # intentionally added/removed an
                                                      # in-place or library carve)

Exit codes: 0 = consistent, 1 = divergence, 77 = skip (no compile_config.json).
"""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "compile_config.json"
SYMBOL_ADDRS = ROOT / "config" / "symbol_addrs.txt"
ALLOWLIST = ROOT / "config" / "naming_sync_allowlist.txt"

# `name = 0xADDR; // type:func ...`  — splat symbol_addrs line shape.
_SYM_LINE = re.compile(
    r"^\s*([A-Za-z_$][A-Za-z0-9_$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;"
)


# --------------------------------------------------------------------------- #
# Parsers
# --------------------------------------------------------------------------- #
def parse_symbol_addrs(text: str) -> dict[int, set[str]]:
    """address(int) -> {names declared at that address} from symbol_addrs.txt.

    Comment lines (``// …``) never match the ``name = 0x… ;`` shape, so the
    ghidra-seed banner and the doc header are ignored automatically.
    """
    by_addr: dict[int, set[str]] = {}
    for line in text.splitlines():
        m = _SYM_LINE.match(line)
        if not m:
            continue
        name, addr = m.group(1), int(m.group(2), 16)
        by_addr.setdefault(addr, set()).add(name)
    return by_addr


def carved_entries(cfg: dict) -> list[dict]:
    """Real carve entries (dicts with a ``name``) — skips the ``_comment``
    section-divider pseudo-entries the config interleaves."""
    return [
        e for e in (cfg.get("carved_funcs") or [])
        if isinstance(e, dict) and "name" in e and "vaddr" in e
    ]


def load_allowlist(text: str) -> set[str]:
    """Carve names whose symbol_addrs absence is grandfathered."""
    allowed: set[str] = set()
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        # `<name>` optionally followed by trailing prose after whitespace;
        # take the first token as the carve name.
        allowed.add(line.split()[0])
    return allowed


# --------------------------------------------------------------------------- #
# TU scan
# --------------------------------------------------------------------------- #
def _tu_mentions(name: str, text: str) -> bool:
    """True if the carve name appears in its TU as an INCLUDE_ASM operand, a
    ``.text.<NAME>`` matched-C section wrapper, or a bare identifier token."""
    if re.search(r"INCLUDE_ASM\s*\([^)]*?,\s*" + re.escape(name) + r"\s*\)", text):
        return True
    if (".text." + name) in text:
        return True
    return re.search(r"\b" + re.escape(name) + r"\b", text) is not None


# --------------------------------------------------------------------------- #
# Core
# --------------------------------------------------------------------------- #
def analyse(cfg: dict, sym_text: str, allow: set[str],
            tu_reader) -> dict[str, list]:
    """Return categorised findings.

    ``tu_reader(rel_path) -> str | None`` yields a TU's text (or None if it
    cannot be read); injected so tests can supply a fake filesystem and the
    real run reads from disk.

    Categories:
      * ``mismatch``       — vaddr present in symbol_addrs but name disagrees.
      * ``new_absence``    — vaddr absent from symbol_addrs, not allowlisted.
      * ``tu_disagree``    — owns a .c TU that never mentions the carve name.
      * ``stale_allow``    — allowlisted name no longer absent / no longer a
                             carve (advisory; the allowlist should be pruned).
    """
    by_addr = parse_symbol_addrs(sym_text)
    mismatch: list[tuple[str, str, list[str]]] = []
    new_absence: list[tuple[str, str]] = []
    tu_disagree: list[tuple[str, str]] = []
    absent_names: set[str] = set()

    for e in carved_entries(cfg):
        name = str(e["name"])
        try:
            vaddr = int(str(e["vaddr"]), 16)
        except ValueError:
            # A malformed vaddr is itself a divergence between registry and
            # the hex address model; surface it as a mismatch.
            mismatch.append((name, str(e["vaddr"]), ["<unparseable vaddr>"]))
            continue

        names_here = by_addr.get(vaddr)
        if names_here is None:
            absent_names.add(name)
            if name not in allow:
                new_absence.append((name, e["vaddr"]))
        elif name not in names_here:
            mismatch.append((name, e["vaddr"], sorted(names_here)))

        tu = e.get("tu")
        if tu and str(tu).endswith(".c"):
            text = tu_reader(str(tu))
            if text is None:
                tu_disagree.append((name, f"{tu} (TU unreadable)"))
            elif not _tu_mentions(name, text):
                tu_disagree.append((name, tu))

    stale_allow = sorted(allow - absent_names)
    return {
        "mismatch": mismatch,
        "new_absence": new_absence,
        "tu_disagree": tu_disagree,
        "stale_allow": stale_allow,
    }


ALLOWLIST_HEADER = """\
# config/naming_sync_allowlist.txt
#
# Carve names (compile_config.json::carved_funcs[].name) whose `vaddr` is
# legitimately ABSENT from config/symbol_addrs.txt when the check was introduced.
# Consumed by scripts/check_naming_sync.py (the naming-propagation ratchet).
#
# This allowlist ONLY excuses symbol_addrs *absence*.  It NEVER excuses a name
# *mismatch* at a shared address, nor a carve whose C TU disagrees with its
# name — those always FAIL.
#
# Two grandfathered categories (no NAME divergence; pure absence):
#
#   1. Library-transplant symbols (carved_funcs `lib: true`).  FLIRT/library
#      identification gave these their canonical *library* name (e.g.
#      `_sceSDC`, `_IO_init`, mangled iostream thunks).  The ghidra seed that
#      populated symbol_addrs only knew `func_`/data symbols, so these library
#      names were never seeded there.  The build resolves them via the
#      in-place glabel in asm/cod/000000.s; no symbol_addrs entry is required.
#
#   2. In-place carves still resolved by a `glabel` inside asm/cod/000000.s
#      (a handful of `func_XXXX` carves not yet split into their own `.s`).
#
# A NEW carve whose name never reached symbol_addrs is NOT in this list and
# FAILS the check — that is the guard against a missing line.  Regenerate with
# `python3 scripts/check_naming_sync.py --update` ONLY after an intentional
# in-place / library carve add or removal, and review the diff.
#
# Format: one carve name per line (trailing prose after whitespace ignored).
"""


def write_allowlist(names: list[str]) -> None:
    lines = [ALLOWLIST_HEADER]
    lines.extend(sorted(names))
    ALLOWLIST.parent.mkdir(parents=True, exist_ok=True)
    ALLOWLIST.write_text("\n".join(lines) + "\n")


def _disk_tu_reader(rel: str) -> str | None:
    p = ROOT / rel
    try:
        return p.read_text(errors="replace")
    except OSError:
        return None


def _current_absences() -> list[str]:
    """Carve names whose vaddr is absent from symbol_addrs (for --update)."""
    cfg = json.loads(CONFIG.read_text())
    by_addr = parse_symbol_addrs(SYMBOL_ADDRS.read_text())
    out = []
    for e in carved_entries(cfg):
        try:
            vaddr = int(str(e["vaddr"]), 16)
        except ValueError:
            continue
        if vaddr not in by_addr:
            out.append(str(e["name"]))
    return out


def main(argv: list[str]) -> int:
    if not CONFIG.exists():
        print("compile_config.json missing — skipping naming-sync check.")
        return 77

    if "--update" in argv:
        names = _current_absences()
        write_allowlist(names)
        print(f"Wrote {ALLOWLIST.relative_to(ROOT)} "
              f"({len(names)} grandfathered symbol_addrs absence(s)).")
        return 0

    cfg = json.loads(CONFIG.read_text())
    sym_text = SYMBOL_ADDRS.read_text() if SYMBOL_ADDRS.exists() else ""
    allow = load_allowlist(ALLOWLIST.read_text()) if ALLOWLIST.exists() else set()
    res = analyse(cfg, sym_text, allow, _disk_tu_reader)

    total = len(carved_entries(cfg))
    fail = res["mismatch"] or res["new_absence"] or res["tu_disagree"]

    if "--list" in argv or not fail:
        print(f"naming-sync: checked {total} carved function(s); "
              f"{len(res['mismatch'])} mismatch, {len(res['new_absence'])} "
              f"un-allowlisted absence, {len(res['tu_disagree'])} TU "
              f"disagreement.")
        if res["stale_allow"]:
            print(f"  note: {len(res['stale_allow'])} allowlist entr(y/ies) "
                  f"no longer absent — prune with --update: "
                  f"{', '.join(res['stale_allow'][:8])}"
                  + (" …" if len(res['stale_allow']) > 8 else ""))
        if not fail and "--list" not in argv:
            print("naming-propagation consistent.")
            return 0
        if not fail:
            return 0

    print("NAMING-PROPAGATION DIVERGENCE", file=sys.stderr)
    print("", file=sys.stderr)
    if res["mismatch"]:
        print("Carve name disagrees with symbol_addrs AT a shared address:",
              file=sys.stderr)
        for name, vaddr, here in res["mismatch"]:
            print(f"    {vaddr}  carve={name!r}  symbol_addrs={here}",
                  file=sys.stderr)
    if res["tu_disagree"]:
        print("Carve name absent from its own C TU:", file=sys.stderr)
        for name, tu in res["tu_disagree"]:
            print(f"    {name}  not found in {tu}", file=sys.stderr)
    if res["new_absence"]:
        print("Carve name absent from symbol_addrs and NOT allowlisted:", file=sys.stderr)
        for name, vaddr in res["new_absence"]:
            print(f"    {name}  @ {vaddr}", file=sys.stderr)
    print("", file=sys.stderr)
    print("CONTRIBUTING rule 3 requires a name to agree across carved_funcs, "
          "config/symbol_addrs.txt, and the C TU in the SAME commit.",
          file=sys.stderr)
    print("This is a DETECTOR — fix the names by hand (do not silence the "
          "check).  A genuinely new in-place/library carve absence can be "
          "grandfathered via", file=sys.stderr)
    print(f"  python3 scripts/check_naming_sync.py --update "
          f"(then review {ALLOWLIST.relative_to(ROOT)}).", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
