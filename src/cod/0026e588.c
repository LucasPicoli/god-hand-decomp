/* sn-2.95.3-136 matched TU. */

extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cEm00_setGoto(void *a0, int a1, int a2, int a3, float f);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0026E588")))
int func_0026E588(void *a0) {
    char *s0 = (char *)a0;
    if (0.0f < *(float *)(s0 + 0x16C0)) return 0;
    if (*(int *)(s0 + 0x1644) & 0x40000000) return 0;
    switch (*(int *)(s0 + 0x564)) {
    case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x211:
    case 0x213: case 0x214: case 0x215: case 0x217: case 0x21C:
    case 0x21F: case 0x220: case 0x221: case 0x222: case 0x223:
    case 0x250: case 0x251: case 0x252: case 0x256: case 0x260:
    case 0x264: case 0x265: case 0x26A: case 0x270: case 0x271:
    case 0x272: case 0x273: case 0x274: case 0x275: case 0x276:
    case 0x278: case 0x279: case 0x27E:
        return 0;
    }
    if (*(float *)(s0 + 0x618) < 16.0f) return 0;
    if (*(int *)(s0 + 0x16EC) > 0) return 0;
    {
        char *vec = s0 + 0x1660;
        char *r = Obj0000_Get_D_00747A94_2DB6B0();
        float mag = capVu0MagnitudeSqXZ(vec, *(void **)(r + 0xF0));
        float sq = *(float *)(s0 + 0x16C8);
        if (mag < sq * sq) return 0;
        *(int *)(s0 + 0x16D0) &= 0xFFFFFFFD;
        cEm00_setGoto(s0, (int)vec, 6, 0, 450.0f);
        *(char *)(s0 + 0x2F7) = 0;
        *(char *)(s0 + 0x2F4) = 0;
        *(char *)(s0 + 0x2F6) = 0;
        *(char *)(s0 + 0x2F5) = 0x13;
        return 1;
    }
}
