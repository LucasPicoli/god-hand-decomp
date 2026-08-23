/* cygnus-2.96 matched TU. */

extern struct S24 { int w[9]; } D_00766BA8;
extern int D_00766BD0[];
extern int D_00766BD8[];

__attribute__((section(".text.SFD_SetMpvParaTbl")))
void SFD_SetMpvParaTbl(struct S24 *src, int *b, int *c) {
    int i, n;
    D_00766BA8 = *src;
    D_00766BA8.w[4] = 0;
    D_00766BA8.w[8] = 0;
    for (i = 0; i < 2; i++) D_00766BD0[i] = (b[i] + 0x3F) & -0x40;
    n = src->w[7];
    for (i = 0; i < 0x10; i++) {
        if (i < n) D_00766BD8[i] = (c[i] + 0x3F) & -0x40;
        else D_00766BD8[i] = 0;
    }
}
