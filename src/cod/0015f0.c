#include "include_asm.h"
#include "godhand/drawPrim.h"

/* ── PERMANENT (1 via this TU) — bc1tl+fp-heavy, 0 VU0 — ee-as safe ──── */

/* Draw_Line_sc: bnel+beql+bc1tl+fp-heavy, 0 VU0 insns, 0x1DC B.
 * Assembled via ee-as through this TU's INCLUDE_ASM. bc1tl does not
 * trigger VU0 pipeline nop insertion. */
INCLUDE_ASM("permanent", Draw_Line_sc);

/* Draw one flat quad from four screen-space vertices. */
__attribute__((section(".text.Draw_Poly_sc")))
void Draw_Poly_sc(void *v, int color)
{
    Gp_draw_poly4(v, color, 1, 0, 8, 2);
}

