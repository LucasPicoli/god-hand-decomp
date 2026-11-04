/* sn-2.95.3-136: one-segment line; the game passes (x0, y0) for both ends. */
extern unsigned int func_0031CA58(unsigned int a0);
#include "godhand/drawPrim.h"

__attribute__((section(".text.func_0031C950")))
void func_0031C950(short x0, short y0, short x1, short y1, unsigned int col, unsigned int z)
{
    float v[2][4];

    v[0][0] = x0;
    v[0][1] = y0;
    v[0][2] = z;
    v[0][3] = 1.0f;
    v[1][0] = x0;
    v[1][1] = y0;
    v[1][2] = z;
    v[1][3] = 1.0f;
    Draw_Line_sc(v, 1, func_0031CA58(col), 1);
}
