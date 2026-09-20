/* include/godhand/gp.h — the SDK's `$gp` accessors, transcribed.
 *
 * # This is not a project intrinsic. It is the vendor's header.
 *
 * SCE's runtime `eekernel.h` (SDK 3.0, lines 154-190) defines `GetGp`, `SetGp`
 * and `SetModuleGp` as `extern __inline__` functions over one inline-assembly
 * statement each.  The bodies below are that source, transcribed.  Retail
 * included this header, so reproducing it reproduces the original source — the
 * same standard this project applies to every other upstream body.
 *
 * # Why `$gp` needs it at all
 *
 * `$gp` holds a base address the ABI reserves.  A caller that invokes an
 * indirect or cross-module routine must save it and restore it, because the
 * callee may replace it.  Retail does exactly that in the SIF RPC path:
 *
 *     0039AB5C  2D808003   daddu  $s0, $gp, $zero
 *     0039AB60  2DE06000   daddu  $gp, $v1, $zero
 *     0039AB7C  2D108003   daddu  $v0, $gp, $zero
 *     0039AB80  2DE00002   daddu  $gp, $s0, $zero
 *
 * No C construct reaches those words.  MEASURED for D-032: the 28 installed
 * `cc1` and `cc1plus` binaries carry no `__builtin_*` naming a global pointer,
 * and the 2,213 objects this project compiles from its own C reference `$gp`
 * zero times.  The build is `-G0`, which switches off the small-data
 * addressing that would otherwise use the register.
 *
 * # THIS IS NOT A FORCED-REGISTER PIN
 *
 * A pin — `register void *p __asm__("$28");` — is bucket 2 under map ticket 21,
 * and D-019 refuses it with a deliberately empty allowlist, because it STEERS
 * an allocation the compiler could make by itself.
 *
 * These accessors steer nothing.  The value moves through an output or an input
 * CONSTRAINT, so the compiler picks the other register — and it picks retail's.
 * `SetGp` + `GetGp` + `SetGp` compiled at `-O2 -G0` under `ee-2.9-991111`:
 *
 *     emitted 0380802d  move s0,gp     retail 0x0039AB5C  2D808003   same word
 *     emitted 0380102d  move v0,gp     retail 0x0039AB7C  2D108003   same word
 *     emitted 0200e02d  move gp,s0     retail 0x0039AB80  2DE00002   same word
 *
 * `scripts/check_forced_regs.py` has nothing to refuse and the zero-pin ratchet
 * stays intact.  D-031 §3 refused an earlier `$gp` proposal on the premise that
 * "reaching `$gp` needs either inline assembly or a forced-register pin".  The
 * premise was wrong about the choice: the vendor reached it with a constraint.
 *
 * # WRITE THE REGISTER NUMBER, NEVER THE NAME
 *
 * `ee-as` under `-mabi=eabi` REJECTS both `$gp` and `$zero`:
 *
 *     Error: absolute expression required `daddu'
 *
 * Only `$28` and `$0` assemble.  The vendor writes `$28` for the same reason.
 * Two wave-24 lanes read the whole route as a dead end on that trap alone.
 */
#ifndef GODHAND_GP_H
#define GODHAND_GP_H

extern void *_gp;

extern __inline__ void *GetGp(void);
extern __inline__ void *GetGp(void)
{
        void *gp;
        __asm__ volatile (
                "move           %0, $28\n"
                : "=r"(gp)
                :
                : "memory"
        );
        return(gp);
}

extern __inline__ void *SetGp(void *newgp);
extern __inline__ void *SetGp(void *newgp)
{
        void *oldgp;
        __asm__ volatile (
                "move           %0, $28\n"
                "move           $28, %1\n"
                : "=&r"(oldgp)
                : "r"(newgp)
                : "memory"
        );
        return(oldgp);
}

extern __inline__ void *SetModuleGp(void);
extern __inline__ void *SetModuleGp(void)
{
        void *oldgp;
        __asm__ volatile (
                "move           %0, $28\n"
                "move           $28, %1\n"
                : "=&r"(oldgp)
                : "r"(&_gp)
                : "memory"
        );
        return(oldgp);
}

/* # BELOW THIS LINE IS PROJECT-LOCAL IDIOM, NOT VENDOR SOURCE
 *
 * Everything above is SCE's `eekernel.h` transcribed.  The two macros below
 * are not in it.  They are here under the same "add on demand, never
 * speculatively" rule `godhand/sync.h` and `godhand/eesyscall.h` follow, and
 * this comment exists so nobody mistakes them for vendor lines.
 *
 * # Why the vendor spelling cannot reach these bytes
 *
 * Retail loads `$gp` STRAIGHT FROM MEMORY, in one word.  `_sceCd_Poff_Intr`
 * at 0x003987C0:
 *
 *     003987EC  2D808003   daddu  $s0, $gp, $zero
 *     003987F0  CCC35C8C   lw     $gp, %lo(D_0077C3CC)($v0)
 *     00398800  2DE00002   daddu  $gp, $s0, $zero
 *
 * `SetGp` takes its new value through an `"r"` CONSTRAINT, so the compiler
 * must materialise it first: `lw $rX, %lo(sym)($v0)` and then the template's
 * `move $28, $rX`.  Two words where retail has one, on every body in this
 * shape.  An `"m"` constraint hands the compiler the address instead and the
 * `lw` inside the template IS retail's word.
 *
 * This is still not a forced-register pin.  `$28` is written by the template,
 * never allocated, and the saved value leaves through `"=&r"`, so the compiler
 * picks that register by itself and picks retail's.  D-019's allowlist stays
 * empty and `scripts/check_forced_regs.py` has nothing to refuse.
 *
 * Measured by wave 31 lane L4 and re-verified from disk by wave 32 lane L5:
 * `_sceCd_Poff_Intr` (84 B) is byte-exact with these and byte-blocked without
 * them, `[reloc-check] OK` on 8 symbol references.  Asked for by five
 * consecutive waves before it shipped. */

/* Save `$gp` into `old`, then load the new one DIRECTLY from `sym`. */
#define GH_SWAPGP_MEM(old, sym)                                                \
    __asm__ __volatile__("move           %0, $28\n"                            \
                         "\tlw            $28, %1"                             \
                         : "=&r"(old)                                          \
                         : "m"(sym))

/* Restore `$gp` from a value already in a register. */
#define GH_PUTGP(v)                                                            \
    __asm__ __volatile__("move           $28, %0"                              \
                         :                                                     \
                         : "r"(v))

#endif /* GODHAND_GP_H */
