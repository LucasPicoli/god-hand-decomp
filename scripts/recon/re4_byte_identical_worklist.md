# RE4 PS2 byte-identical worklist (uncarved God Hand functions)

Each God Hand function below is byte-for-byte identical to a function in
Resident Evil 4 PS2 (SLUS-21134) — same MIPS R5900 / ee-gcc toolchain, so
they are shared engine/runtime code. Regenerate the source list with
`scripts/recon/re4ps2_fingerprint.py --out FILE` (verdict == byte-identical).

Match approach: write C, compile with the project flags, compare .text bytes.
~30%% match first-try (clean compute-and-return); the rest need register/
schedule tweaks (permuter) or canonical library source. Matched so far:
ADXB_SetAc3DecSmpl, ADXF_CALC_BYTE2SCT, SFTIM_InitTcode, func_00369130, sfmpv_InitComplementPts, mpslib_InitPket, sfxalp_InitHn, sfmps_InitInf, sftrn_InitTrData, func_003B67E8, kputchar, func_003B2B90, func_003217F0, dvci_getnumtr_lower, htci_getnumtr_lower, sfadxt_GetFreeChunk, SFTIM_GetNextItime, func_003A93A8, decode_uleb128, func_002B9DB8, func_002BA3F0.

NEWLIB COMPILER (ee-2.9-991111): the 0x003Bxxxx library region is newlib code,
NOT cygnus. Functions there that look 1 insn short under the default compiler
(cygnus fills the loop branch delay slot; newlib leaves a nop) match exactly when
carved with `{"path":..., "compiler":"ee-2.9-991111"}` in compile_units. Matched
func_003B67E8 (byte memcpy) and kputchar (EE I/O poll) this way. Try this
compiler FIRST for any 0x3Bxxxx near-miss.

Store-order trick (SFTIM_InitTcode/func_00369130): when retail stores struct
fields in an unusual order with one field in the jr delay slot, the ee-gcc
scheduler ROTATES the trailing source store to the front. Write the field that
must land FIRST as the LAST store in source and the rest match byte-for-byte —
no permuter needed. sftim_Tc2TimeN (pure-arithmetic weighted sum) is permuter-
RESISTANT: single expression, full register permutation, plateaus ~600.

Two more reorder levers (cracked sfmpv_InitComplementPts / sfxalp_InitHn):
- BASE POINTERS: when retail addresses sub-fields via `addiu vN,a0,off` and
  indexes off it, write an explicit `T *q = (T*)(p+off); q[i]=...` so the
  compiler recreates that base register (direct `*(T*)(p+off+...)` won't).
- CONSTANT ORDER: when only the constant->register mapping differs, declare the
  constants as NAMED locals in retail's materialisation order; the allocator then
  assigns registers to match. sfxalp_InitHn went from a permuter near-miss
  (base 75) to an exact hand match this way.

SHORT-LOOP NOPs ARE NOT A WALL (sfmps_InitInf matched): ee-gcc cc1 EMITS the
R5900 short-loop nops itself (verified via --print-stage s) — a down-counted
`for(i=N;i>=0;i--)` loop with a small body produces `sw; nop; nop; nop; bgez`.
sfmps_InitInf (34-insn min/max init + 68-word zero loop) matched in full: the
loop+nops reproduce directly; the init-block store SCHEDULE was solved by a
hill-climb over source statement order (cc1's list scheduler is sensitive to
source order as a tiebreaker — the permuter plateaued at the base, but a direct
adjacent-swap hill-climb over the 13 stores reached the exact pre-image), and the
tail by the store-rotation rule. sftrn_InitTrData ALSO matched: its "missing loop nops" was a misdiagnosis — cc1
emits the nops fine; the real diff was a v0/v1 register swap (counter vs loop
pointer). Writing the counter first in the for-init (`for(i=2,q=...;...)`) puts
the counter in $v1 and the pointer in $v0, matching retail. So NO loop-nop wall
exists at all.

| insns | GH addr | RE4 addr | RE4 name |
|------:|---------|----------|----------|
| 8 | 0x00333288 | 0x00184720 |  |
| 9 | 0x003A4E00 | 0x002AEC18 |  |
| 10 | 0x003217F0 | 0x00178448 | what__C9exception |
| 10 | 0x003520B0 | 0x002C9CC8 |  |
| 10 | 0x0035A518 | 0x002D1FC0 |  |
| 10 | 0x00369130 | 0x002DAB40 |  |
| 11 | 0x00334B58 | 0x00197C20 |  |
| 11 | 0x00349F80 | 0x002C11E8 |  |
| 11 | 0x00369158 | 0x002DAB68 |  |
| 12 | 0x003B2B90 | 0x0029EEF0 |  |
| 12 | 0x003B67E8 | 0x002A1FC8 |  |
| 13 | 0x002B9DB8 | 0x00121D20 | log__t8cManager1Z4cMapPce |
| 13 | 0x002BA3F0 | 0x00121D20 | log__t8cManager1Z4cMapPce |
| 13 | 0x0034CCB0 | 0x002C4050 |  |
| 13 | 0x00368EE0 | 0x002DA8F0 |  |
| 13 | 0x00369F70 | 0x002DA8F0 |  |
| 13 | 0x0036D938 | 0x002DA8F0 |  |
| 14 | 0x003B0D48 | 0x0029D980 |  |
| 15 | 0x0035A5E0 | 0x002D2088 |  |
| 15 | 0x0035BB60 | 0x002D3508 |  |
| 15 | 0x0036CB58 | 0x002DE468 |  |
| 16 | 0x003B6468 | 0x002A1C48 |  |
| 16 | 0x003B64A8 | 0x002A1C88 |  |
| 17 | 0x00321938 | 0x00178590 |  |
| 18 | 0x002A7280 | 0x001BB6A0 | arrayFree__t8cManager1Z3cEm |
| 18 | 0x00321D38 | 0x00178990 |  |
| 18 | 0x00338F30 | 0x00188EA8 |  |
| 18 | 0x0035BD88 | 0x002D3718 |  |
| 19 | 0x00339848 | 0x001897C0 |  |
| 19 | 0x003A93A8 | 0x002B2720 |  |
| 20 | 0x00321980 | 0x001785D8 |  |
| 21 | 0x0039AC58 | 0x002E7678 |  |
| 24 | 0x0031DE10 | 0x0017A298 | __muldi3 |
| 30 | 0x003A95A8 | 0x002B28D8 |  |
| 31 | 0x0033D198 | 0x0018F358 |  |
| 34 | 0x00321D80 | 0x001789D8 |  |
| 34 | 0x0034FDF0 | 0x002C7B18 |  |
| 34 | 0x0035DDB0 | 0x002D5718 |  |
| 35 | 0x0035B188 | 0x002D2C18 |  |
| 38 | 0x0035B360 | 0x002D2DF0 |  |
| 39 | 0x0035B2C0 | 0x002D2D50 |  |
| 42 | 0x0035B3F8 | 0x002D2E88 |  |
| 43 | 0x0031FAE8 | 0x00179B20 | __dynamic_cast |
| 43 | 0x0036E208 | 0x002DFA38 |  |
| 43 | 0x003A5148 | 0x002AF3AC |  |
| 46 | 0x003A52F0 | 0x002AF554 |  |
| 50 | 0x003AF310 | 0x002B8A68 |  |
| 52 | 0x0034D318 | 0x002C5260 |  |
| 56 | 0x0032F988 | 0x00195A18 |  |
| 63 | 0x003219D0 | 0x00178628 |  |
| 70 | 0x003A57C4 | 0x002AFA28 |  |
| 72 | 0x0033D9C0 | 0x0018FB80 |  |
| 75 | 0x0031DE78 | 0x00177178 | __pack_d |
| 79 | 0x00327568 | 0x001930E0 |  |
| 81 | 0x00320800 | 0x00176798 |  |
| 93 | 0x00322748 | 0x001793A0 |  |
| 104 | 0x003A54D8 | 0x002AF73C |  |
| 114 | 0x003A5DA0 | 0x002B0008 |  |
| 149 | 0x00366110 | 0x002D7DA8 |  |
| 149 | 0x00366368 | 0x002D8000 |  |
| 173 | 0x0039A2F8 | 0x002E6D18 |  |
| 227 | 0x00340B00 | 0x00199528 |  |
| 281 | 0x003670E8 | 0x002D8AF8 |  |


ATTEMPTED, RESISTANT (2026-06-21 — logic understood, exact match not yet found):
- isnanf (isnanf), SFBUF_UpdateFlowCnt (64-bit hi+borrow pack): tiny
  register-allocation near-misses (~7-word diff, all 3 compilers); mfc1/dsll
  destination regs are compiler-chosen. Permuter-resistant like sftim_Tc2TimeN.
- strrev (strrev), func_0032F988 (big-endian 0x10-byte deserializer):
  longer than my C (retail uses per-field base pointers + load-delay nops +
  a specific byte-read schedule). Need exact upstream source or a big scheduling
  hill-climb; base-pointer reconstruction gets the size close but not exact.
- func_003B6468 (word memcpy): opens with a DEAD `lw v0,0x1C(v1)` off an
  uninitialised v1 — can't reproduce without knowing what emits it.
- kFindAddress (word find/memchr): convoluted movz control flow.
- func_0035BB60 (min/max/sum/count accumulator): diff=2, a daddu/movn scheduler
  tie; func_00368EE0 (cond vcall): retail emits a redundant move all compilers
  drop. Both genuine near-misses.
Large libgcc/libm still untouched: __divdi3 (0x3A region), 0x3A54D8 (104),
0x3A5DA0 (114), 0x366110/0x366368 (149), 0x39A2F8 (173), 0x340B00 (227),
0x3670E8 (281) — these want canonical library source, not hand-derived C.
