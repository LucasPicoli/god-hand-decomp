/* sn-2.95.3-136: quad from short xy pairs, z + 65528, then Draw_Poly_sc. */
extern unsigned int convColor(unsigned int a0);
extern void Draw_Poly_sc(float (*v)[4], unsigned int col);

__attribute__((section(".text.func_0031CB80")))
void func_0031CB80(short *pts, unsigned int col, unsigned int z)
{
    float v[4][4];
    int i = 4;
    float (*p)[4] = v;

    do {
        (*p)[0] = pts[0];
        (*p)[1] = pts[1];
        (*p)[2] = z + 65528.0f;
        (*p)[3] = 1.0f;
        pts += 2;
        p++;
    } while (--i);
    Draw_Poly_sc(v, convColor(col));
}
