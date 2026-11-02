/* sn-2.95.3-136: line strip from short xy pairs into a VLA of float4, then Draw_Line_sc. */
extern unsigned int func_0031CA58(unsigned int a0);
#include "godhand/drawPrim.h"

__attribute__((section(".text.func_0031CA88")))
void func_0031CA88(short *pts, short n, unsigned int col, unsigned int z)
{
    float v[n][4];
    int i = n;
    float (*p)[4] = v;

    do {
        (*p)[0] = pts[0];
        (*p)[1] = pts[1];
        (*p)[2] = z;
        (*p)[3] = 1.0f;
        pts += 2;
        p++;
    } while (--i);
    Draw_Line_sc(v, n - 1, func_0031CA58(col), 1);
}
