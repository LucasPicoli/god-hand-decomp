/* sn-2.95.3-136 matched TU. */

extern void sceVu0UnitMatrix(void *m);
extern void func_0030A2E0(void *a, void *b, void *c);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_0030AA40")))
void func_0030AA40(void *arg, float p1, float p2, float p3, float p4, float p5,
                   float p6, float p7, float p8, float p9) {
    char *s0 = (char *)arg;
    float M[16];
    float den;
    float zs;
    float zo;

    den = -p8 + p9;
    zo = (-p7 * p8 + p6 * p9) / den;
    zs = p9 * p8 * (-p6 + p7) / den;
    sceVu0UnitMatrix(s0);
    *(float *)(s0 + 0x00) = p1;
    *(float *)(s0 + 0x14) = p1;
    *(int *)(s0 + 0x28) = 0;
    *(float *)(s0 + 0x38) = 1.0f;
    *(float *)(s0 + 0x2C) = 1.0f;
    *(int *)(s0 + 0x3C) = 0;
    sceVu0UnitMatrix(M);
    M[0] = p2;
    M[5] = p3;
    M[10] = zs;
    M[12] = p4;
    M[13] = p5;
    M[14] = zo;
    func_0030A2E0(s0, M, s0);
}
