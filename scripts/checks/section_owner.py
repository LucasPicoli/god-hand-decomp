#!/usr/bin/env python3
"""Every .text.<name> section body in src/ must be unique and owned.

A failed integrate chunk once committed a TU holding three function bodies, two
of them DUPLICATE definitions of functions carved to other files. Nothing
complained. There was no `carved_funcs` entry, so the linker took the monolith
assembly instead. There was no `compile_units` entry, so the file built under the
default key and emitted sections of the wrong size. The build stayed green and
the ELF stayed byte-identical the whole time, because nothing linked the file.

The loss is silent and it is not small: a duplicate body hides work that the
percentage never counts, and a reader believes the function is done.

Two assertions, both cheap:

  A  a `__attribute__((section(".text.NAME")))` body is defined ONCE across src/
  B  that NAME owns a `carved_funcs` entry whose `tu` is that same file

Exit 0 = pass, 1 = a duplicate or an unowned body, 2 = examined nothing.
"""
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
SECTION_RE = re.compile(r'section\s*\(\s*"\.text\.([A-Za-z_]\w*)"\s*\)')


def main() -> int:
    cfg = json.loads((ROOT / "compile_config.json").read_text())
    owner = {e["name"]: e.get("tu") for e in cfg.get("carved_funcs", [])
             if isinstance(e, dict) and e.get("name")}

    seen: dict[str, list[str]] = {}
    for p in sorted((ROOT / "src").rglob("*.c")):
        rel = p.relative_to(ROOT).as_posix()
        for name in SECTION_RE.findall(p.read_text(errors="replace")):
            seen.setdefault(name, []).append(rel)
    if not seen:
        print("section_owner: NO-OP — no .text.<name> section body under src/",
              file=sys.stderr)
        return 2

    dupes = {n: v for n, v in seen.items() if len(v) > 1}
    unowned = {n: v[0] for n, v in seen.items() if n not in owner}
    misowned = {n: (v[0], owner[n]) for n, v in seen.items()
                if n in owner and owner[n] != v[0]}

    print(f"section_owner: {len(seen)} section body/bodies checked "
          f"in {len({f for v in seen.values() for f in v})} file(s)")
    for n, v in sorted(dupes.items()):
        print(f"  DUPLICATE body {n}: " + ", ".join(v))
    for n, f in sorted(unowned.items()):
        print(f"  NO carved_funcs entry: {n} (in {f})")
    for n, (f, t) in sorted(misowned.items()):
        print(f"  OWNER MISMATCH: {n} is in {f} but carved_funcs says tu={t}")

    if dupes or unowned or misowned:
        print("\nA body that no carved_funcs entry owns never reaches the ELF.\n"
              "The linker takes the monolith assembly and the build stays green,\n"
              "so the loss is silent. Delete the orphan body, or add the\n"
              "carved_funcs entry and the compile_units entry in the SAME commit.",
              file=sys.stderr)
        return 1
    print("  every body is unique and owned")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
