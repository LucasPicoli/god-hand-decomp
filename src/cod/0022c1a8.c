/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00569B70[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);

extern void func_0026BDD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

__attribute__((section(".text.func_0022C1A8")))
void func_0022C1A8(void *a0)
{
    char *s0 = (char *)a0;
    int r;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400;
    *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v1;
        int s2v, s1v;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        *(char *)(s0 + 0x2F7) = Forward30F348_31CFE0() & 1;
        v1 = *(char **)(s0 + 0x304);
        s2v = *(int *)(v1 + 0x22E0) + (int)v1;
        s1v = *(int *)(v1 + 0x22E4) + (int)v1;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *w = *(char **)(s0 + 0x304);
            s1v = *(int *)(w + 0x22E8) + (int)w;
        }
        func_002A8578(s0, s2v, s1v, 0.0f, 3, gb, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(float *)(s0 + 0x604) = 35.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        *(int *)(s0 + 0x5FC) = 0;
    }
        /* fallthrough */
    case 1: {
        char *p;
        if (*(float *)(s0 + 0x604) > 0.0f) {
            *(float *)(s0 + 0x604) = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8);
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
        }
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
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        if (*(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) = 0;
            if (*(int *)(s0 + 0x564) == 0x276) {
                r = func_0026AA30(s0, 0x373);
            } else {
                r = func_0026AA30(s0, 0x36B);
            }
            if (r != 0) {
                func_0026BDD0(s0, r);
                *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x10000;
            }
        }
    } else {
        *(int *)(s0 + 0x5F0) = 1;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        *(int *)(s0 + 0x5FC) = 1;
    }
    if (*(int *)(s0 + 0x5FC) != 0) {
        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) & 0xFFFFFBFF;
    }
}
