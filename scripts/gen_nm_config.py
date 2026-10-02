#!/usr/bin/env python3
"""Generate the NON_MATCHING *scored* build config (config/us-nm/) from the default
matching config.

Matching decomps can't commit a sub-100% function body: it wouldn't reproduce
the retail bytes, so the build would stop being byte-identical. The standard fix
is a two-build setup. A plausible clean-C body that isn't byte-exact yet is kept
behind a guard:

    #ifdef NON_MATCHING
    void *f(void *o) { ...clean C, scores 90-99%... }
    #else
    INCLUDE_ASM("nonmatching", f);     // byte-exact fallback
    #endif

- The DEFAULT build (`python compile.py`) compiles the `#else` INCLUDE_ASM, so the
  linked ELF stays byte-identical to retail.
- This derived `nm` build defines NON_MATCHING and compiles the clean bodies into
  `build-nm/`, so objdiff can score them. `scripts/score_nm.sh` writes that score
  to `progress/report.nm.json`, whose `fuzzy_match_percent` credits the partials.
  `progress/report.json` (the file decomp.dev ingests) stays 100%-exact-only.

config/us-nm/ is a generated artifact (gitignored); regenerate whenever
compile_config.json or objdiff.json changes (scripts/score_nm.sh does this).
"""
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

# --- derive config/us-nm/compile_config.json --------------------------------
c = json.load(open("compile_config.json"))
c["defines"] = sorted(set(c.get("defines", [])) | {"NON_MATCHING"})
c["build_dir"] = "build-nm"
if c.get("output_elf"):
    c["output_elf"] = c["output_elf"].replace("build/", "build-nm/", 1)
if c.get("output_map"):
    c["output_map"] = c["output_map"].replace("build/", "build-nm/", 1)

od = c.setdefault("objdiff", {})
od["name"] = od.get("name", "") + " — NON_MATCHING scored"
od["base_dir"] = "build-nm"
od["objdiff_project"] = "config/us-nm/objdiff.json"
od["report_path"] = "progress/report.nm.json"
od["custom_args"] = ["compile.py", "--config", "config/us-nm/compile_config.json", "--single-file"]

os.makedirs("config/us-nm", exist_ok=True)
with open("config/us-nm/compile_config.json", "w") as f:
    json.dump(c, f, indent=2)
    f.write("\n")
print("wrote config/us-nm/compile_config.json  (defines:", c["defines"], ", build_dir: build-nm)")

# --- derive config/us-nm/objdiff.json from the matching project -------------
# Paths are re-rooted: the project lives at config/us-nm/, so each path gains a
# ../../ prefix; base objects come from build-nm/ instead of build/. build_target
# is false because the matching linker script hardcodes build/ (so --setup can't
# regenerate this for build-nm) — score_nm.sh pre-builds the objects instead.
o = json.load(open("objdiff.json"))
for u in o["units"]:
    if "target_path" in u:
        u["target_path"] = "../../" + u["target_path"]
    if "base_path" in u:
        u["base_path"] = ("../../" + u["base_path"]).replace("../../build/", "../../build-nm/", 1)
o["build_target"] = False
o["name"] = o.get("name", "") + " — NON_MATCHING scored"
with open("config/us-nm/objdiff.json", "w") as f:
    json.dump(o, f, indent=1)
    f.write("\n")
print("wrote config/us-nm/objdiff.json  (", len(o["units"]), "units, base -> build-nm )")
