#!/usr/bin/env python3
"""link_symbols.py: every name the link resolves must come from a committed file.

Public CI cannot link the ELF, because the asm half of the link comes from
splat run over the retail executable. So a name that exists only in a local
copy of config/symbol_addrs.txt passes every other CI gate, then breaks the
link on a fresh clone (issue #3: `_IO_getline_info`).

This gate resolves names the way the link does, without the retail ELF:

1. carved_funcs: the carve finds each function by the label splat writes at
   its vaddr. That label is the symbol_addrs.txt name for the address, or
   `func_<VADDR>` when the address has none, and it must equal the entry name.
2. Every src/ TU is compiled with GODHAND_PORT, which turns INCLUDE_ASM into a
   no-op, so each object holds only what its C references. Each global
   undefined symbol must be defined by another TU, bound in the linker script,
   named in symbol_addrs.txt, or be a splat auto name for an address
   symbol_addrs.txt leaves unnamed. A named address gets its name, never the
   auto name.

Ceiling: an auto name passes on its shape. Whether splat writes a label at
that address needs the ELF.

Exit codes: 0 every name resolves, 1 a name does not, 2 a TU failed to
compile, 77 the toolchain is absent (run scripts/setup_toolchain.sh).
"""
from __future__ import annotations

import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
ASSIGN = re.compile(r"^\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;")
# splat auto names. `.L<ADDR>` is a jump label a TU can re-export with
# `.globl` for the INCLUDE_ASM body to define.
AUTO = re.compile(r"^(?:func_|D_|B_|jtbl_|\.L)([0-9A-F]{8})$")


def assignments(path: Path) -> dict[str, int]:
    return {m[1]: int(m[2], 0)
            for m in map(ASSIGN.match, path.read_text().splitlines()) if m}


def unresolved(names: dict[str, int], lcf: dict[str, int], carves: list[dict],
               defined: set[str], undefined: list[tuple[str, str]]) -> list[str]:
    """Return one line per name the link would fail on."""
    label_at = {addr: name for name, addr in names.items()}
    errors = []
    for e in carves:
        if "name" not in e:
            continue
        vaddr = int(e["vaddr"], 16)
        label = label_at.get(vaddr, f"func_{vaddr:08X}")
        if e["name"] != label:
            errors.append(f"carved_funcs: {e['name']} at {vaddr:#010x}, "
                          f"but splat labels that address {label}")
    for sym, unit in undefined:
        if sym in defined or sym in lcf or sym in names:
            continue
        m = AUTO.match(sym)
        if m is None:
            errors.append(f"{unit}: {sym} is defined by no TU and "
                          f"named nowhere in config/symbol_addrs.txt")
        elif int(m[1], 16) in label_at:
            errors.append(f"{unit}: {sym}, but splat labels that address "
                          f"{label_at[int(m[1], 16)]}")
    return sorted(set(errors))


def main() -> int:
    cfg = json.loads((ROOT / "compile_config.json").read_text())
    if shutil.which("readelf") is None or not (ROOT / "compiler").is_dir():
        print("toolchain absent (readelf, compiler/): run scripts/setup_toolchain.sh")
        return 77

    with tempfile.TemporaryDirectory() as tmp:
        conf = Path(tmp) / "compile_config.json"
        conf.write_text(json.dumps(dict(
            cfg, defines=cfg["defines"] + ["GODHAND_PORT"],
            asm_sources_glob=[], carved_funcs=[], build_dir=tmp)))
        r = subprocess.run(
            [sys.executable, "compile.py", "--config", str(conf), "--no-link"],
            cwd=ROOT, capture_output=True, text=True)
        if r.returncode:
            print(*(r.stdout + r.stderr).splitlines()[-40:], sep="\n")
            return 2
        objs = sorted(Path(tmp).rglob("*.o"))
        # readelf, not nm: the SN assembler writes gcc2_compiled. as a LOCAL
        # symbol in the undefined section, and nm lists it as a reference.
        out = subprocess.run(["readelf", "-sW", *objs], check=True,
                             capture_output=True, text=True).stdout

        defined, undefined = set(), []
        for line in out.splitlines():
            if line.startswith("File: "):
                unit = str(Path(line[6:]).relative_to(tmp).with_suffix(""))
                continue
            f = line.split()
            if len(f) < 8 or f[4] not in ("GLOBAL", "WEAK"):
                continue
            if f[-2] != "UND":
                defined.add(f[-1])
            elif f[4] == "GLOBAL":
                undefined.append((f[-1], unit))

    errors = unresolved(assignments(ROOT / "config/symbol_addrs.txt"),
                        assignments(ROOT / "config/SLUS_215.03.lcf"),
                        cfg["carved_funcs"], defined, undefined)
    for err in errors:
        print(err)
    print(f"{len(undefined)} references in {len(objs)} objects: "
          f"{len(errors)} unresolved")
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
