#include "include_asm.h"

/* ── PERMANENT (1 via this TU) — bc1tl+fp-heavy, 0 VU0 — ee-as safe ──── */

/* Draw_Line_sc: bnel+beql+bc1tl+fp-heavy, 0 VU0 insns, 0x1DC B.
 * Assembled via ee-as through this TU's INCLUDE_ASM. bc1tl does not
 * trigger VU0 pipeline nop insertion. */
INCLUDE_ASM("permanent", Draw_Line_sc);

/* ── CALL-CHAIN (1) — jal, hardcoded args — nonmatching ───────────────── */

/* Draw_Poly_sc: addiu $sp,-0x10; addiu $a2,1; sd $ra; daddu $a3,0;
 *               addiu $t0,8; jal Gp_draw_poly4; addiu $t1,2; ld $ra; jr; addiu $sp,0x10
 *               0x28 B — hardcoded-arg call chain, INCLUDE_ASM pending match */
INCLUDE_ASM("nonmatching", Draw_Poly_sc);

