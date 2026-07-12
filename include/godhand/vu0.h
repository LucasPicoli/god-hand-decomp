/* include/godhand/vu0.h — VU0 (COP2) macromode inline-asm helpers.
 *
 * # Why this header is project-local (not `include/sce/vu0.h`)
 *
 * The SCE PS2 SDK 3.0.20 does not ship a `<sce/vu0.h>` with
 * COP2 macromode intrinsics.  ee-gcc 2.96 has no `__builtin_vu_*`
 * surface either: every VU0 emission in retail code goes through
 * hand-written inline assembly.  This header is therefore a
 * project-local **idiom-stabilising** wrapper, not a vendored SDK
 * stub.  Per the lazy-vendor rule, if a canonical SCE header
 * with these intrinsics ever surfaces, this header is superseded
 * and moved/dropped accordingly.
 *
 * # The pipeline-delay nop convention
 *
 * **Empirically, for the load/store COP2 ops covered
 * here (`sqc2`, `lqc2`), ee-as does NOT auto-insert pipeline
 * nops in any tested mode (`.set noreorder`, `.set reorder`,
 * or default).**  Retail (`func_0027B768`) has 6 back-to-back
 * `sqc2 $vf0, off($s0)` with NO nops between them; a minimal
 * 3-sqc2 standalone .s file assembled with ee-as under each
 * `.set` mode also produces zero inter-op nops.  This
 * falsifies the assumption that ee-as inserts exactly 1 nop
 * per VU0 op for the quadword load/store class.  The universal
 * claim that ee-as inserts pipeline-delay nops even under `.set
 * noreorder` does NOT hold for sqc2/lqc2 in practice.
 *
 * Each macro therefore expands to a `.set noreorder` block
 * containing **only** the COP2 instruction (no extra nop):
 *
 *   .set push ; .set noreorder ; <COP2 op> ; .set pop
 *
 * The `.set noreorder` framing is still load-bearing — it
 * pins instruction order so ee-gcc's scheduler cannot reorder
 * around the inline asm and ee-as's `.set reorder` pass
 * cannot pull an unrelated instruction up into a delay slot
 * inside the macro.  But the explicit nop is dropped because
 * adding it would produce 8 B per macro vs the 4 B retail
 * actually uses, breaking byte equality (8-byte body inflation
 * per quadword zero-init).
 *
 * **Open question** (out of scope here): the q-pipeline ops
 * (`vsqrt`/`vdiv`/`vwaitq`) and some MAC/EFU sequences DO have
 * documented inter-op hazards in the EE Core Architecture
 * Manual.  Whether ee-as inserts nops for those is unverified
 * by the sqc2/lqc2 test.  When the first q-pipeline op surfaces,
 * test it the same way (build + objdump diff) before extending
 * this header with q-pipeline macros.
 *
 * # Scope
 *
 * This header ships only the macros that the active matching
 * tasks need.  Add more on demand; do NOT speculatively populate
 * (lazy-vendor pattern).  Today's covered ops:
 *
 *   VU0_SQC2_VF0(base, off)  -- store $vf0 (hard-zero) quadword
 *   VU0_SQC2(reg, base, off) -- store $vf<reg> quadword
 *   VU0_LQC2(reg, base, off) -- load quadword into $vf<reg>
 *
 * Not covered yet (file a follow-up + add when a real task needs
 * them):
 *
 *   - Vector arithmetic (vadd / vsub / vmul / vmaxw / vminw)
 *   - Q-pipeline ops (vsqrt / vdiv / vwaitq)
 *   - GPR <-> VU0 transfers (qmtc2 / qmfc2 / cfc2 / ctc2)
 *   - Float<->int conversion (vftoi* / vitof*)
 *
 * # Usage
 *
 *   #include "godhand/vu0.h"
 *
 *   void func_0027B768(void *obj) {
 *       VU0_SQC2_VF0(obj, 0x00);
 *       VU0_SQC2_VF0(obj, 0x10);
 *       VU0_SQC2_VF0(obj, 0x20);
 *       ...
 *   }
 *
 * The `"memory"` clobber on the store macros prevents GCC from
 * reordering memory accesses around the inline asm.  The `base`
 * pointer is an input constraint (`"r"`) so GCC will allocate it
 * to any GPR; the offset is a literal integer (`%2`) inlined into
 * the asm template.
 *
 * # Reopen triggers for this header
 *
 *   - First byte-match attempt that fails because the nop count
 *     is wrong: re-investigate the ee-as hazard analyser (skill
 *     § What could still go wrong #1) and adjust.
 *   - A canonical SCE `<sce/vu0.h>` surfaces: supersede + move
 *     this header to `include/sce/vu0.h` with the intrinsic
 *     names from the SDK.
 *   - GCC's clobber list forces a spill not in retail: tighten
 *     the constraint set (e.g. drop `"memory"` if static analysis
 *     proves no aliasing).
 */
#ifndef GODHAND_VU0_H
#define GODHAND_VU0_H

/* VU0_SQC2_VF0(base, off): "zero-init this quadword".
 *
 * Expands to:
 *     .set push
 *     .set noreorder
 *     sqc2  $vf0, off(base)
 *     .set pop
 *
 * $vf0 is hard-zero by VU0 hardware convention (reads as
 * (x=0, y=0, z=0, w=1.0)).  Storing $vf0 zero-fills the
 * 128 bits at base+off in one instruction.  Use for object
 * init, struct zeroing, GS packet header init, etc.
 *
 * `base` is any pointer expression (cast as needed); `off` is a
 * 16-bit-signed literal byte offset.
 */
#define VU0_SQC2_VF0(base, off)                                        \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "sqc2  $vf0, %1(%0)\n"                                         \
        ".set pop\n"                                                   \
        :                                                              \
        : "r"((void *)(base)), "i"((int)(off))                         \
        : "memory")

/* VU0_SQC2(reg, base, off): store $vf<reg> quadword.
 *
 * `reg` is a register-number literal in [1, 31] (use VU0_SQC2_VF0
 * for $vf0 — the zero-init case is the dominant pattern in our
 * corpus and gets its own macro for readability).
 *
 * Expands to:
 *     .set push
 *     .set noreorder
 *     sqc2  $vf<reg>, off(base)
 *     .set pop
 */
#define VU0_SQC2(reg, base, off)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "sqc2  $vf" #reg ", %1(%0)\n"                                  \
        ".set pop\n"                                                   \
        :                                                              \
        : "r"((void *)(base)), "i"((int)(off))                         \
        : "memory")

/* VU0_LQC2(reg, base, off): load quadword into $vf<reg>.
 *
 * Dual of VU0_SQC2.  `reg` is a register-number literal in
 * [1, 31] ($vf0 is read-only by VU0 hardware convention, so
 * loading into it is meaningless).
 *
 * Expands to:
 *     .set push
 *     .set noreorder
 *     lqc2  $vf<reg>, off(base)
 *     .set pop
 *
 * Note: `lqc2` follows the same no-explicit-nop convention as
 * the sqc2 macros (the empirically falsified nop assumption
 * covers stores; loads are expected to follow the same rule
 * but the first lqc2 byte-match attempt should re-confirm
 * before relying on it).  If
 * an `lqc2`-bearing function fails to byte-match because of a
 * missing pipeline nop, revisit the assumption and add an
 * explicit-nop variant.
 */
#define VU0_LQC2(reg, base, off)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "lqc2  $vf" #reg ", %1(%0)\n"                                  \
        ".set pop\n"                                                   \
        :                                                              \
        : "r"((void *)(base)), "i"((int)(off))                         \
        : "memory")

/* VU0_VADD_XYZ(dst, s1, s2): $vf<dst>.xyz = $vf<s1>.xyz + $vf<s2>.xyz.
 * A compute-class COP2 op with no inter-op nop (same empirical finding as the
 * lqc2/sqc2 load/store class — see the header preamble); the `.set noreorder`
 * framing only pins order around the inline asm. */
#define VU0_VADD_XYZ(dst, s1, s2)                                      \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "vadd.xyz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"               \
        ".set pop\n")

/* VU0_VMOVE_XYZW(dst, src): $vf<dst> = $vf<src> (all four fields). */
#define VU0_VMOVE_XYZW(dst, src)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmove.xyzw $vf" #dst ", $vf" #src "\n"                        \
        ".set pop\n")

/* VU0_VMR32_XYZW(dst, src): $vf<dst> = $vf<src> rotated (x<-y<-z<-w<-x). */
#define VU0_VMR32_XYZW(dst, src)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmr32.xyzw $vf" #dst ", $vf" #src "\n"                        \
        ".set pop\n")

/* COP2 accumulator (matrix x vector) ops. Note: the ACC register assembles as
 * bare `ACC` (no `$`) — the disassembler prints it as `$ACC`. The x/y/z
 * broadcast is encoded in the mnemonic, so the second source is a plain $vf. */
#define VU0_VMULAX_XYZW(s1, s2)                                        \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmulax.xyzw ACC, $vf" #s1 ", $vf" #s2 "\n"                    \
        ".set pop\n")
#define VU0_VMADDAY_XYZW(s1, s2)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmadday.xyzw ACC, $vf" #s1 ", $vf" #s2 "\n"                   \
        ".set pop\n")
#define VU0_VMADDZ_XYZW(dst, s1, s2)                                   \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmaddz.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"            \
        ".set pop\n")

/* Field-masked vector ops used by the cap* distance/magnitude helpers. */
#define VU0_VSUB_XZ(dst, s1, s2)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vsub.xz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"               \
        ".set pop\n")
#define VU0_VMUL_XZ(dst, s1, s2)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmul.xz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"               \
        ".set pop\n")
#define VU0_VADDZ_X(dst, s1, s2)                                       \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vaddz.x $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"              \
        ".set pop\n")

/* Q-pipeline (sqrt) helpers. ee-as encodes `vsqrt Q, $vfNx` differently from
 * retail, so callers emit the exact `.word` for vsqrt; vwaitq/vaddq assemble
 * fine. The bare `Q` register (no `$`) mirrors the ACC convention. */
#define VU0_VWAITQ()                                                   \
    __asm__ __volatile__(".set push\n.set noreorder\nvwaitq\n.set pop\n")
#define VU0_VADDQ_X(dst, s1)                                           \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vaddq.x $vf" #dst ", $vf" #s1 ", Q\n"                        \
        ".set pop\n")

/* xyz-masked ops for the 3D length/distance helpers. */
#define VU0_VMUL_XYZ(dst, s1, s2)                                      \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmul.xyz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"             \
        ".set pop\n")
#define VU0_VSUB_XYZ(dst, s1, s2)                                      \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vsub.xyz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"             \
        ".set pop\n")
#define VU0_VADDY_X(dst, s1)                                           \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vaddy.x $vf" #dst ", $vf" #s1 ", $vf" #s1 "\n"              \
        ".set pop\n")

/* Element-wise min/max (used by vector clamp/sort helpers). */
#define VU0_VMINI_XYZW(dst, s1, s2)                                    \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmini.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"           \
        ".set pop\n")
#define VU0_VMAX_XYZW(dst, s1, s2)                                     \
    __asm__ __volatile__ (                                             \
        ".set push\n.set noreorder\n"                                  \
        "vmax.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n"            \
        ".set pop\n")

/* Full-width (xyzw) arithmetic and float<->fixed conversion. */
#define VU0_VADD_XYZW(dst, s1, s2)                                     \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vadd.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VSUB_XYZW(dst, s1, s2)                                     \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vsub.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VMUL_XYZW(dst, s1, s2)                                     \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmul.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VFTOI4_XYZW(dst, src)                                      \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vftoi4.xyzw $vf" #dst ", $vf" #src "\n.set pop\n")

/* Cross product (outer-product multiply/subtract) and the full matrix-row ops. */
#define VU0_VOPMULA_XYZ(s1, s2)                                        \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vopmula.xyz ACC, $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VOPMSUB_XYZ(dst, s1, s2)                                   \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vopmsub.xyz $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VSUB_W(dst, s1, s2)                                        \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vsub.w $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VMADDAZ_XYZW(s1, s2)                                       \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmaddaz.xyzw ACC, $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VMADDW_XYZW(dst, s1, s2)                                   \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmaddw.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")
#define VU0_VADD_W(dst, s1, s2)                                        \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vadd.w $vf" #dst ", $vf" #s1 ", $vf" #s2 "\n.set pop\n")

/* VU0_LOAD_SCALAR(dst, fval): move a float scalar into $vf<dst> via the
 * mfc1/qmtc2 path (broadcast source for vmulx/vdiv).  Uses $8 as the scratch
 * GPR to match retail's hand-written intrinsics. */
#define VU0_LOAD_SCALAR(dst, fval)                                     \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "mfc1 $8, %0\n"                                                \
        "qmtc2.ni $8, $vf" #dst "\n.set pop\n"                         \
        :: "f"(fval) : "$8")

/* Broadcast-x multiply: $vf<dst> = $vf<s1> * $vf<s2>.x (scalar*vector). */
#define VU0_VMULX_XYZW(dst, s1, s2)                                    \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmulx.xyzw $vf" #dst ", $vf" #s1 ", $vf" #s2 "x\n.set pop\n")
#define VU0_VMULX_XYZ(dst, s1, s2)                                     \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmulx.xyz $vf" #dst ", $vf" #s1 ", $vf" #s2 "x\n.set pop\n")

/* Reciprocal via Q-pipeline: Q = $vf<num>.w / $vf<den>.x (vf0.w == 1.0). */
#define VU0_VDIV_W_X(num, den)                                         \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vdiv Q, $vf" #num "w, $vf" #den "x\n.set pop\n")
#define VU0_VMULQ_XYZW(dst, s1)                                        \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmulq.xyzw $vf" #dst ", $vf" #s1 ", Q\n.set pop\n")
#define VU0_VMULQ_XYZ(dst, s1)                                         \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vmulq.xyz $vf" #dst ", $vf" #s1 ", Q\n.set pop\n")

/* vnop: VU0 pipeline bubble (explicit in the hand-written intrinsics). */
#define VU0_VNOP()                                                     \
    __asm__ __volatile__(".set push\n.set noreorder\nvnop\n.set pop\n")

/* Reciprocal against the w field: Q = $vf<num>.w / $vf<den>.w (perspective
 * divide by w). */
#define VU0_VDIV_W_W(num, den)                                         \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vdiv Q, $vf" #num "w, $vf" #den "w\n.set pop\n")

/* vftoi0.zw: float->int (0 fractional bits) on the z and w fields only. */
#define VU0_VFTOI0_ZW(dst, src)                                        \
    __asm__ __volatile__ (".set push\n.set noreorder\n"               \
        "vftoi0.zw $vf" #dst ", $vf" #src "\n.set pop\n")

/* --- COP2 -> GPR/FPU result-extraction and raw-encoded q-pipe ops --------- *
 *
 * The cap-magnitude/dot/length helpers read a VU0 scalar result back into a
 * float via the canonical `qmfc2.ni $gpr, $vf` then `mtc1 $f, $gpr` chain --
 * there is no C form for either step under ee-gcc 2.x.  Two qmfc2 shapes occur
 * in retail: bare (the assembler reorder pass schedules around it) and
 * `.set noreorder` framed; keep both so each call site reproduces its exact
 * bytes.  Of the q-pipeline ops only `vsqrt` is mis-encoded by ee-as (a stray
 * fsf=01 bit -- see VU0_VSQRT_Q), so it alone is emitted as a computed `.word`;
 * `vclipw` encodes correctly and uses the real mnemonic. */
#define VU0_QMFC2_NI(out, reg)                                         \
    __asm__ __volatile__("qmfc2.ni %0, $vf" #reg : "=r"(out))
#define VU0_QMFC2_NI_F(out, reg)                                       \
    __asm__ __volatile__(".set push\n.set noreorder\n"                \
        "qmfc2.ni %0, $vf" #reg "\n.set pop\n" : "=r"(out))

/* Move a GPR bit-pattern into an FPU register (tail of the extract idiom). */
#define VU0_MTC1(fout, gpr)                                            \
    __asm__ __volatile__("mtc1 %1, %0" : "=f"(fout) : "r"(gpr))

/* vsqrt Q, $vf<ft><field> -- ee-as mis-encodes vsqrt: it hard-wires a spurious
 * fsf=01 (bit 21) into every vsqrt (`vsqrt Q,$vf4x` -> 0x4A2403BD), while retail
 * always has fsf=00 (0x4A0403BD).  No operand text can zero the stray bit, so
 * the op is emitted as its exact .word, computed from the source register `ft`
 * and its field selector `ftf` (x:0 y:1 z:2 w:3):
 *
 *     word = 0x4A0003BD | (ftf << 23) | (ft << 16)
 *
 * ee-as evaluates the `.word` expression at assembly time -- verified that every
 * retail form reproduces exactly: vf4x 0x4A0403BD (x3), vf5x 0x4A0503BD (x1),
 * vf7w 0x4B8703BD (x4). */
#define VU0_VSQRT_Q(ft, ftf)                                           \
    __asm__ __volatile__(".set push\n.set noreorder\n"                \
        ".word (0x4A0003BD | (" #ftf " << 23) | (" #ft " << 16))\n"   \
        ".set pop\n")
/* Named forms for the fields that occur in retail (all field = x). */
#define VU0_VSQRT_Q_VF4X() VU0_VSQRT_Q(4, 0) /* vsqrt Q, $vf4x */
#define VU0_VSQRT_Q_VF5X() VU0_VSQRT_Q(5, 0) /* vsqrt Q, $vf5x */

/* vclipw.xyz $vf12, $vf12w -- sets the clip flags ($vi18).  ee-as encodes this
 * mnemonic exactly as retail (0x4BCC61FF, verified), so the real mnemonic is
 * used.  Read the flags back with VU0_CFC2_NI(r, 18). */
#define VU0_VCLIPW_XYZ_VF12()                                          \
    __asm__ __volatile__(".set push\n.set noreorder\n"                \
        "vclipw.xyz $vf12, $vf12w\n.set pop\n")

/* Read a COP2 integer/control register ($viN) into a GPR. */
#define VU0_CFC2_NI(out, ireg)                                         \
    __asm__ __volatile__(".set push\n.set noreorder\n"                \
        "cfc2.ni %0, $vi" #ireg "\n.set pop\n" : "=r"(out))

#endif /* GODHAND_VU0_H */
