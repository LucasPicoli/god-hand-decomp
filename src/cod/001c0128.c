/* sn-2.95.3-136 matched TU. */

extern int cDamageManage_CreateDamageGive(int a0, int a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, int a2, float f);
extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void cOmItem_setGetRangeLong(void *a0, int a1);
extern void cOmItem_setScrCheck(void *a0, int a1);
extern int D_00574380;
extern int D_00569B70;

__attribute__((section(".text.func_001C0128")))
int func_001C0128(void *a0)
{
    float buf[4];
    char *s3 = (char *)a0;
    int d;
    long bits;
    int h;
    int r1;
    int r2;
    char *vt;
    char *lvl;

    func_001B6FB8(s3);
    *(float *)(s3 + 0x600) = 0.02f;
    *(float *)(s3 + 0x614) = 0.19999999f;
    *(int *)(s3 + 0x670) = 0x31;
    *(int *)(s3 + 0x610) = 0;
    *(int *)(s3 + 0x618) = 0;
    *(int *)(s3 + 0x630) = 0;
    *(int *)(s3 + 0x634) = 0;
    *(unsigned char *)(s3 + 0x660) = 0;
    *(unsigned char *)(s3 + 0x674) = 0;
    *(unsigned char *)(s3 + 0x675) = 0;
    switch (*(unsigned short *)(s3 + 0x2FE)) {
    case 0x3BC:
        *(float *)(s3 + 0x118) = 4.0f;
        *(float *)(s3 + 0x114) = 4.0f;
        *(float *)(s3 + 0x110) = 4.0f;
        break;
    case 0x3C2: case 0x3C3: case 0x3C4:
    case 0x3D6: case 0x3D7: case 0x3D8:
        *(float *)(s3 + 0x118) = 2.0f;
        *(float *)(s3 + 0x114) = 2.0f;
        *(float *)(s3 + 0x110) = 2.0f;
        break;
    case 0x3DA: case 0x3DB: case 0x3DC: case 0x3DD:
        *(int *)(s3 + 0x670) = 0;
        *(float *)(s3 + 0x118) = 1.5f;
        *(float *)(s3 + 0x114) = 1.5f;
        *(float *)(s3 + 0x110) = 1.5f;
        *(int *)(s3 + 0x5B8) |= 8;
        break;
    case 0x3ED:
        d = cDamageManage_CreateDamageGive((int)&D_00574380, 3, (int)s3);
        *(int *)(s3 + 0x680) = d;
        if (d != 0) {
            *(int *)&buf[0] = 0;
            *(int *)&buf[1] = 0;
            *(int *)&buf[2] = 0;
            buf[3] = 1.0f;
            cDamageUnit_AddDamageCollSphere(d, (int)(s3 + 0x80), (int)buf, 2.5f);
            *(short *)(*(int *)(s3 + 0x680) + 0x46) = 0x52;
            *(int *)(*(int *)(s3 + 0x680) + 0x4C) = 0x50;
            cDamageUnit_SetDamageCollActive(*(void **)(s3 + 0x680), 0);
        }
        break;
    }
    switch (*(unsigned short *)(s3 + 0x2FE)) {
    case 0x3BC:
    case 0x3D9:
    case 0x3E3:
        *(unsigned char *)(s3 + 0x531) = 1;
        break;
    }
    cOmItem_setGetRangeLong(s3, 0);
    cOmItem_setScrCheck(s3, 1);
    *(int *)(s3 + 0x5B8) &= ~0x40;
    bits = *(unsigned int *)(s3 + 0x5B0);
    if (((bits >> 5) & 1) == 0 && *(short *)(s3 + 0x662) == 0) {
        vt = *(char **)(s3 + 0x214);
        lvl = (char *)&D_00569B70;
        h = *(unsigned short *)(s3 + 0x2FE);
        r1 = ((int (*)(void *))*(void **)(vt + 0x84))(s3 + *(short *)(vt + 0x80));
        vt = *(char **)(s3 + 0x214);
        r2 = ((int (*)(void *))*(void **)(vt + 0x8C))(s3 + *(short *)(vt + 0x88));
        *(short *)(s3 + 0x662) = func_001FAFF0(lvl, h, r1, r2,
                                               *(int *)(s3 + 0x560), s3 + 0x676);
    }
    *(int *)(s3 + 0x67C) = *(int *)(s3 + 0x560);
    *(unsigned char *)(s3 + 0x677) = *(unsigned char *)(s3 + 0x676);
    return 1;
}
