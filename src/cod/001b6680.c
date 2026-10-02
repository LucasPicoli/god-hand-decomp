/* SN ProDG ee-gcc 2.95.3 matched TU. */
/* src/cod/001b66.c — single-function carve (sn-2.95.3-136).
 *
 * cOmb5_setActive (0x001B6680, 36 B / 9 insns) — branched-leaf
 * mutator on an $a0 object.  Writes bit 0 (mask 0x1) of the u32 flags
 * word at +0x5B8 from the boolean arg1: set when arg1 != 0, clear
 * otherwise.  The shared field load hoists into the beqz delay slot and
 * both arms modify it in place, so the `*p |= 1` / `*p &= ~1` compound-
 * assignment idiom is what reproduces the exact register allocation
 * (in-place $v0) and the two-return shape.
 *
 * Compiler: sn-2.95.3-136 — cygnus-2.96 over-emits here (40 B vs 36 B).
 * Field name follows the offset convention pending a Ghidra struct name.
 */

__attribute__((section(".text.cOmb5_setActive")))
void cOmb5_setActive(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x5B8) |= 1;
    } else {
        *(int *)(arg0 + 0x5B8) &= ~1;
    }
}
