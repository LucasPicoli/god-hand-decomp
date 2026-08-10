#!/usr/bin/env python3
"""registers — the two named registers must stay well formed, current and inert.

The project keeps two registers of the same shape. Each holds named entries and
each entry carries an argument, so the same parser serves both:

  config/retail_authored_asm.txt   code that reaches the ELF as assembly and
                                   COUNTS, because its original author wrote it
                                   in assembly. One entry per unit.
  config/permanent_exceptions.txt  code that sits OUTSIDE the target. One entry
                                   per class, each with the finding that returns
                                   it to scope.

WHY A GATE EXISTS AT ALL. Without it, a `.s` file dropped anywhere under `src/`
scores 100% because it assembles, with no provenance argument made and no
reviewer prompted. The metric cannot tell "the original was assembly, so this is
faithful and done" from "we transcribed it". The first register states the
difference and this gate makes the statement mandatory.

WHY THERE IS NO `--fix`. `carve_allowlist.py` has one because appending an
allowlist line is mechanical and asserts nothing. The repair here is to WRITE A
PROVENANCE ARGUMENT about a twenty-year-old build. A tool must not write that.
A missing entry is a prompt for a human, so this gate reports and stops.

THE SECOND REGISTER IS NEVER A SCREEN. It is a statement about the destination
and it must never be able to block a match. The last time a permanence belief
reached the worklist generators it suppressed 102 functions / 48,912 B, five of
which were already matched. Check E below makes that a hard error: no file under
`scripts/` other than this one may read that path. Staleness of an entry is
REPORTED, never failed — re-entry is auto-stale marking, not a gate.

Checks:
  A  every `.s` under `src/` has an entry, and every entry names a file present
  B  each entry carries the required fields, non-empty
  C  each entry's `functions:` and `bytes:` agree with progress/report.json
  D  each `standard-of-proof:` / `evidence-class:` value is in its vocabulary
  E  no file under `scripts/` except this one reads the permanent register
  F  entries past `stale-after-days:` are REPORTED, not failed

Exit codes follow the session_check convention:
  0   pass  — the sets were genuinely determined and every predicate holds
  2   void  — a register or an input is unreadable, so nothing was examined
  77  skip  — progress/report.json absent, so check C cannot run yet
  1   fail
"""
from __future__ import annotations

import datetime as _dt
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

ASM_REGISTER = ROOT / "config" / "retail_authored_asm.txt"
PERM_REGISTER = ROOT / "config" / "permanent_exceptions.txt"
REPORT = ROOT / "progress" / "report.json"
SRC = ROOT / "src"
SCRIPTS = ROOT / "scripts"

ASM_REQUIRED = ("id", "unit", "representation", "functions", "bytes", "percent",
                "standard-of-proof", "last-tested", "argument", "falsifier")
PERM_REQUIRED = ("id", "functions", "bytes", "percent", "evidence-class",
                 "last-tested", "tested-by", "stale-after-days", "members",
                 "argument", "falsifier")

PROOF_TIERS = ("sdk-artifact", "toolchain-gap", "reasoned")
EVIDENCE_CLASSES = ("nobody-tried", "someone-failed")

_ENTRY = re.compile(r"^\[entry\]\s*$")
_FIELD = re.compile(r"^([a-z][a-z0-9-]*):[ \t]*(.*)$")


def parse(path: Path) -> list[dict[str, str]]:
    """Parse the shared stanza format. Raises ValueError on a malformed line."""
    entries: list[dict[str, str]] = []
    cur: dict[str, str] | None = None
    block: str | None = None
    for lineno, raw in enumerate(path.read_text().splitlines(), 1):
        if raw.lstrip().startswith("#"):
            continue
        if _ENTRY.match(raw):
            cur = {}
            entries.append(cur)
            block = None
            continue
        if not raw.strip():
            block = None
            continue
        if raw[0] in " \t":
            if cur is None or block is None:
                continue                      # prose outside any stanza
            cur[block] = (cur[block] + "\n" + raw.strip()).strip()
            continue
        m = _FIELD.match(raw)
        if not m:
            if cur is None:
                continue                      # header prose
            raise ValueError(f"{path.name}:{lineno}: not a field and not a "
                             f"comment: {raw!r}")
        if cur is None:
            continue
        key, val = m.group(1), m.group(2).strip()
        cur[key] = val
        block = key if not val else None
    return entries


def report_units() -> dict[str, tuple[int, int]] | None:
    """{unit name: (total_functions, total_code)} or None when absent."""
    if not REPORT.exists():
        return None
    data = json.loads(REPORT.read_text())
    out = {}
    for u in data.get("units", []):
        m = u.get("measures") or {}
        if "total_functions" in m and "total_code" in m:
            out[u["name"]] = (int(m["total_functions"]), int(m["total_code"]))
    return out


def main(argv: list[str]) -> int:
    if "--fix" in argv[1:]:
        print("registers: there is no --fix.")
        print("  A missing entry is repaired by WRITING A PROVENANCE ARGUMENT.")
        print("  That is the one repair a tool must not perform for you.")
        return 1

    for p in (ASM_REGISTER, PERM_REGISTER):
        if not p.exists():
            print(f"VOID: {p.relative_to(ROOT)} is missing; nothing was examined.")
            return 2
    if not SRC.is_dir():
        print("VOID: src/ is missing; the assembly set could not be determined.")
        return 2

    try:
        asm_entries = parse(ASM_REGISTER)
        perm_entries = parse(PERM_REGISTER)
    except ValueError as exc:
        print(f"VOID: {exc}")
        return 2

    fail: list[str] = []
    note: list[str] = []

    # -- A. the `.s` set and the register must be in bijection ---------------
    on_disk = sorted(str(p.relative_to(ROOT)) for p in SRC.rglob("*.s"))
    registered = {e.get("representation", "") for e in asm_entries}
    for p in on_disk:
        if p not in registered:
            fail.append(
                f"UNREGISTERED ASSEMBLY: {p}\n"
                f"    It reaches the ELF as assembly and scores as matched, but no\n"
                f"    entry in config/retail_authored_asm.txt argues that retail\n"
                f"    itself authored it in assembly. Add an entry or write it in C.")
    for e in asm_entries:
        rep = e.get("representation", "")
        if rep and not (ROOT / rep).exists():
            fail.append(f"STALE ENTRY: {ASM_REGISTER.name} entry "
                        f"{e.get('id', '?')} names {rep}, which does not exist.")

    if not asm_entries and not on_disk:
        print("VOID: no assembly units and no entries; the set is undetermined.")
        return 2

    # -- B/D. required fields and closed vocabularies ------------------------
    for e in asm_entries:
        for k in ASM_REQUIRED:
            if not e.get(k, "").strip():
                fail.append(f"{ASM_REGISTER.name} entry {e.get('id', '?')}: "
                            f"field `{k}` is missing or empty.")
        tier = e.get("standard-of-proof", "")
        if tier and tier not in PROOF_TIERS:
            fail.append(f"{ASM_REGISTER.name} entry {e.get('id', '?')}: "
                        f"standard-of-proof `{tier}` is not one of "
                        f"{', '.join(PROOF_TIERS)}.")
    for e in perm_entries:
        for k in PERM_REQUIRED:
            if not e.get(k, "").strip():
                fail.append(f"{PERM_REGISTER.name} entry {e.get('id', '?')}: "
                            f"field `{k}` is missing or empty.")
        ev = e.get("evidence-class", "")
        if ev and ev not in EVIDENCE_CLASSES:
            fail.append(f"{PERM_REGISTER.name} entry {e.get('id', '?')}: "
                        f"evidence-class `{ev}` is not one of "
                        f"{', '.join(EVIDENCE_CLASSES)}.")

    # -- C. the asm register must agree with the number it defends -----------
    units = report_units()
    skipped_c = units is None
    if units is not None:
        for e in asm_entries:
            u = e.get("unit", "")
            if u not in units:
                fail.append(f"{ASM_REGISTER.name} entry {e.get('id', '?')}: "
                            f"unit `{u}` is not in progress/report.json.")
                continue
            nf, nb = units[u]
            if str(nf) != e.get("functions", ""):
                fail.append(f"{ASM_REGISTER.name} entry {e.get('id', '?')}: "
                            f"functions {e.get('functions')} but report.json "
                            f"says {nf}.")
            if str(nb) != e.get("bytes", ""):
                fail.append(f"{ASM_REGISTER.name} entry {e.get('id', '?')}: "
                            f"bytes {e.get('bytes')} but report.json says {nb}.")

    # -- E. the permanent register must stay inert ---------------------------
    me = Path(__file__).resolve()
    # This gate and its wrapper are the only permitted readers.
    exempt = {me, me.with_suffix(".sh")}
    needle = "permanent_exceptions"
    if SCRIPTS.is_dir():
        for p in sorted(SCRIPTS.rglob("*")):
            if not p.is_file() or p.resolve() in exempt:
                continue
            if p.suffix not in (".py", ".sh", ".bash"):
                continue
            try:
                if needle in p.read_text(errors="ignore"):
                    fail.append(
                        f"THE PERMANENT REGISTER IS BEING READ BY "
                        f"{p.relative_to(ROOT)}.\n"
                        f"    It is a statement about the destination, never an "
                        f"input to candidate\n"
                        f"    selection. A permanence belief in a generator "
                        f"suppressed 102 functions\n"
                        f"    / 48,912 B once, five of them already matched. "
                        f"Remove the reference.")
            except OSError:
                continue

    # -- F. staleness is REPORTED, never failed ------------------------------
    today = _dt.date.today()
    for e in perm_entries:
        try:
            when = _dt.date.fromisoformat(e.get("last-tested", ""))
            span = int(e.get("stale-after-days", "0"))
        except ValueError:
            continue
        age = (today - when).days
        if span and age > span:
            note.append(f"STALE (not a failure): entry {e.get('id', '?')} was "
                        f"last tested {age} days ago, over its {span}-day span. "
                        f"Re-run its falsifier.")

    # -- report --------------------------------------------------------------
    for n in note:
        print(n)
    if fail:
        print(f"\nregisters: {len(fail)} problem(s).\n")
        for f in fail:
            print(f"  {f}")
        print("\nThere is no --fix. Write the entry, or write the code in C.")
        return 1

    a_fn = sum(int(e.get("functions", "0") or 0) for e in asm_entries)
    a_b = sum(int(e.get("bytes", "0") or 0) for e in asm_entries)
    p_fn = sum(int(e.get("functions", "0") or 0) for e in perm_entries)
    p_b = sum(int(e.get("bytes", "0") or 0) for e in perm_entries)
    print(f"registers OK.")
    print(f"  retail-authored assembly : {len(asm_entries)} entr(y/ies), "
          f"{a_fn} functions, {a_b} B  [{len(on_disk)} .s file(s) under src/]")
    print(f"  permanent exceptions     : {len(perm_entries)} entr(y/ies), "
          f"{p_fn} functions, {p_b} B  "
          f"[{sum(1 for e in perm_entries if e.get('evidence-class') == 'nobody-tried')}"
          f" of them 'nobody-tried']")
    if skipped_c:
        print("  progress/report.json absent — the entry/metric cross-check "
              "did not run.")
        return 77
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
