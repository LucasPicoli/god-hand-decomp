/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00569B70[];
extern unsigned char D_005FEE00[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_0026BBD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

/* sn-2.95.3-136 matched TU. */

















struct Bf { signed char v : 8; };

__attribute__((section(".text.func_0022BD10")))
void func_0022BD10(void *a0)
{
    char *s0 = (char *)a0;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400;
    *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v1;
        char *s4;
        int s2v, s1v;
        int t;
        int one;
        int raw;
        unsigned char b;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        *(char *)(s0 + 0x2F7) = Forward30F348_31CFE0() & 1;
        v1 = *(char **)(s0 + 0x304);
        s4 = (char *)&D_00569B70;
        s2v = *(int *)(v1 + 0x2330) + (int)v1;
        s1v = *(int *)(v1 + 0x2334) + (int)v1;
        if (cCoreSave_getGameLevel(s4) == 5) {
            char *w = *(char **)(s0 + 0x304);
            s1v = *(int *)(w + 0x2338) + (int)w;
        }
        func_002A8578(s0, s2v, s1v, 0.0f, 3, gb, 0);
        one = 1;
        *(int *)(s0 + 0x5FC) = 0;
        *(float *)(s0 + 0x604) = 35.0f;
        *(int *)(s0 + 0x5F0) = one;
        *(short *)(s0 + 0x568) = one;
        switch (cCoreSave_getGameLevel(s4)) {
        case 1: default:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                *(short *)(s0 + 0x568) = 2;
            }
            break;
        case 2:
            *(short *)(s0 + 0x568) = 2;
            if ((Forward30F348_31CFE0() & 1) != 0) {
                *(short *)(s0 + 0x568) = 3;
            }
            break;
        case 3: case 4:
            *(short *)(s0 + 0x568) = 2;
            if ((Forward30F348_31CFE0() & 1) != 0) {
                *(short *)(s0 + 0x568) = 4;
            }
            break;
        case 5:
            *(short *)(s0 + 0x568) = 4;
            break;
        }
        if ((char)*(unsigned char *)(s0 + 0x1869) < *(short *)(s0 + 0x568)) {
            *(short *)(s0 + 0x568) = (char)*(unsigned char *)(s0 + 0x1869);
        }
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *p;

        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
        p = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(void **)(p + 0xF0), *(float *)(s0 + 0x5A8) * 0.19634955f);
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    case 2: {
        int gb;
        char *v1;
        int s2v, s1v;
        int r;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        *(char *)(s0 + 0x2F7) = Forward30F348_31CFE0() & 1;
        v1 = *(char **)(s0 + 0x304);
        s2v = *(int *)(v1 + 0x233C) + (int)v1;
        s1v = *(int *)(v1 + 0x2340) + (int)v1;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *w = *(char **)(s0 + 0x304);
            s1v = *(int *)(w + 0x2344) + (int)w;
        }
        func_002A8578(s0, s2v, s1v, 0.0f, 3, gb, 0);
        *(int *)(s0 + 0x5FC) = 0;
        *(int *)(s0 + 0x5F0) = 1;
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x23, s0, 0, 0, 0, 0);
        *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        if (*(char *)(s0 + 0x1869) > 0) {
            r = func_0026AA30(s0, 0x36A);
            if (r != 0) {
                func_0026BBD0(s0, r);
            }
        }
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        char *p;

        p = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(void **)(p + 0xF0), *(float *)(s0 + 0x5A8) * 0.19634955f);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x568) > 0) {
                *(unsigned char *)(s0 + 0x2F6) = 2;
            } else {
                *(unsigned char *)(s0 + 0x2F6) = 4;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    case 4: {
        int gb;
        char *v1;
        int s2v, s1v;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        *(char *)(s0 + 0x2F7) = Forward30F348_31CFE0() & 1;
        v1 = *(char **)(s0 + 0x304);
        s2v = *(int *)(v1 + 0x2348) + (int)v1;
        s1v = *(int *)(v1 + 0x234C) + (int)v1;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *w = *(char **)(s0 + 0x304);
            s1v = *(int *)(w + 0x2350) + (int)w;
        }
        func_002A8578(s0, s2v, s1v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5: {
        char *p;

        p = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(void **)(p + 0xF0), *(float *)(s0 + 0x5A8) * 0.19634955f);
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        *(int *)(s0 + 0x5FC) = 1;
    }
    if (*(int *)(s0 + 0x5FC) != 0) {
        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) & 0xFFFFFBFF;
    }
}
