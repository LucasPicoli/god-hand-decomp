#include "godhand/drawPrim.h"

/* Draw one flat quad from four screen-space vertices. */
__attribute__((section(".text.Draw_Poly_sc")))
void Draw_Poly_sc(void *v, int color)
{
    Gp_draw_poly4(v, color, 1, 0, 8, 2);
}

