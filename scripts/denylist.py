"""Shared regex patterns for the project's source-quality lint checks.

Defined once here so every check that uses them stays in agreement instead of
each carrying its own copy that can drift. Each entry is a structural shape; the
checks import the compiled patterns from this module. Storage, not policy — the
patterns are byte-for-byte what the checks used inline before centralization.
"""
from __future__ import annotations

import re

# --- forced-register pin ----------------------------------------------------- #
# A GCC explicit-register local (`register <type> x __asm__("$N")`). Matched
# anywhere on a line (NOT anchored) so a mid-line declaration cannot evade the
# check; callers strip comments first so prose mentions never count.
# GCC accepts three interchangeable spellings of the binding keyword —
# `__asm__`, `__asm`, and plain `asm` — all codegen-identical, so all three
# must be caught. The plain `asm` form in particular evaded BOTH this gate and
# the inline-asm gate (which deliberately exempts register bindings, deferring
# to this checker) until the alternation was added. The `\b` before the group
# stops an identifier that merely ends in `asm` (`foo_asm(`) from matching, and
# `[^;{}]` keeps the `register` and the `asm(` inside one statement so a bare
# `register` storage class on a preceding statement can't fuse with a later call.
FORCED_REG_RE = re.compile(r"\bregister\b[^;{}]*?\b(?:__asm__|__asm|asm)\s*\(")

# --- inline-asm keywords ----------------------------------------------------- #
# Each is anchored or word-bounded so it does not match identifiers that merely
# contain the substring `asm`. Order matters for the error message: the first
# match wins, so the more-specific patterns come first.
INLINE_ASM_PATTERNS: tuple[tuple[str, "re.Pattern[str]"], ...] = (
    ("__asm__", re.compile(r"\b__asm__\b")),
    ("__asm(", re.compile(r"\b__asm\s*\(")),
    ("asm volatile", re.compile(r"\basm\s+volatile\b")),
    ("asm(", re.compile(r"\basm\s*\(")),
    ("#pragma asm", re.compile(r"^\s*#\s*pragma\s+asm\b", re.MULTILINE)),
)

# --- identifier-suffix naming guard ------------------------------------------ #
# A short uppercase-letter + 1-2 digit (+ optional a-f) suffix appended to a
# CamelCase identifier. Two surface variants:
#   CONTENT — scanning free text / diffs: the label may sit mid-identifier
#     (preceded by a lowercase letter, the `<lower>W<NN>` fused form) OR stand
#     alone as its own word (a `W<NN>` token in a commit message). The lead-in
#     therefore accepts a lowercase letter, a word boundary, or string start;
#     it ends on a word boundary. (This comment intentionally uses the `W<NN>`
#     placeholder, never a real `W`+digit literal — otherwise this very file
#     would trip the gate it defines, as the runtime-built test fixtures avoid.)
#   NAME — scanning a single identifier: it may also sit at the very start and
#     ends at end-of-string.
# Case-SENSITIVE (capital `W` only): an uppercase letter + 1-2 digits
# discriminates a real wave label from all-caps acronyms (`HW2`), 3+-digit data
# symbols, and — crucially — ordinary lowercase code (`w2` vars, the vector `.w`
# component), which must never trip the broad net. A bare *lowercase* wave token
# in freeform prose is a deliberate non-catch for that reason; the private
# `snw\d` spelling (denylist_private.PROSE_TOKENS_RE) covers the lowercased form.
WAVE_LABEL_CONTENT_RE = re.compile(r"(?:^|[a-z_]|\b)W\d{1,2}[a-f]?(?=[A-Z]|_|\b)")
WAVE_LABEL_NAME_RE = re.compile(r"(?:^|[a-z_])W\d{1,2}[a-f]?(?=[A-Z]|_|$)")
