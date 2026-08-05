/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_0025FE30(void *a0, int a1, int a2);
extern void cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void Obj0000_Set_Fields_360_364_368_139B68(void *parts, void *obj, int a2, int a3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern int D_00463050;

__attribute__((section(".text.func_0025FA18")))
void func_0025FA18(void *a0) {
    char *s1;
    void *parts;
    void *s3;
    void *s2;
    int v0;
    int p;
    float one;
    char *base;
    int a2v;
    int a3v;
    int b;
    int lim;
    int spill[2];

    s1 = (char *)a0;
    s3 = Obj0000_Get_D_00747A94_2DB6B0();
    p = *(int *)(s1 + 0x214);
    s2 = (*(void *(**)(void *))(p + 0xB4))(s1 + *(short *)(p + 0xB0));
    *(float *)(s1 + 0x54C) = 3.0f;
    if (*(unsigned char *)(s1 + 0x2F6) == 0) {
        switch (*(int *)(s1 + 0x564)) {
        case 0x21A:
        case 0x21B:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x25A:
            *(unsigned char *)(s1 + 0x2F6) = 2;
            break;
        }
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x444) + v0, *(int *)(v0 + 0x448) + v0, 0.0f, 0, 0, 0);
        *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) & 0xFDFF;
        *(unsigned char *)(s1 + 0x617) = 1;
        func_0025FE30(s1, 0x400000, 1);
        cDamageUnit_SetDamageCollActive(s2, 0);
        *(short *)(s1 + 0x568) = 0xDD;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        one = 1.0f;
        *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (*(short *)(s1 + 0x568) != 0) {
            *(unsigned short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
        } else {
            *(unsigned char *)(s1 + 0x2F4) = 2;
            *(unsigned char *)(s1 + 0x2F5) = 2;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    case 2:
        v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x153C) + v0, *(int *)(v0 + 0x1540) + v0, 0.0f, 0, 0, 0);
        *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) & 0xFDFF;
        *(unsigned char *)(s1 + 0x617) = 1;
        func_0025FE30(s1, 0x400000, 1);
        cDamageUnit_SetDamageCollActive(s2, 0);
        *(short *)(s1 + 0x568) = 0x11D;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        base = (char *)&D_00463050;
        cCamManager_setPartsCamera(base, 0);
        parts = base + 0x920;
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x1B;
        if (lim < b) {
            a2v = *(int *)(*(int *)(s1 + 0x278) + 0x6C);
        } else {
            a2v = 0;
        }
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x1C;
        if (lim < b) {
            a3v = *(int *)(*(int *)(s1 + 0x278) + 0x70);
        } else {
            a3v = 0;
        }
        one = 1.0f;
        Obj0000_Set_Fields_360_364_368_139B68(parts, s1, a2v, a3v);
        *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (*(short *)(s1 + 0x568) != 0) {
            *(unsigned short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
        } else {
            ClearField15F4Bit1_124F60(s3, 0, 1);
            *(unsigned char *)(s1 + 0x2F4) = 2;
            *(unsigned char *)(s1 + 0x2F5) = 2;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    }
}
