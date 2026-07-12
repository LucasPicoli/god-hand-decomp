/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int func_00273960(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern int D_00569B70;

__attribute__((section(".text.func_00229268")))
void func_00229268(void *a0)
{
    char *s1 = (char *)a0;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s1, 0, 0x10, 0x4C, -1, 0);
        v0 = *(char **)(s1 + 0x304);
        a1v = *(int *)(v0 + 0x1E7C) + (int)v0;
        a2v = *(int *)(v0 + 0x1E80) + (int)v0;
        *(int *)(s1 + 0x5F0) = 0xF;
        func_002A8578(s1, a1v, a2v, 0.0f, 0xA, gb, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        *(int *)(s1 + 0x5FC) = 0;
        func_0026EE40(s1, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (*(int *)(s1 + 0x5F0) != 0) {
            char *v0;
            *(int *)(s1 + 0x5F0) -= 1;
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(v0 + 0xF0), *(float *)(s1 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s1) != 0) {
            AddScaledVecToField_100_14F9F0(s1, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
            if (*(unsigned char *)(s1 + 0x1864) == 0 || func_00273960(s1, 6.0f) == 0) {
                func_002705D8(s1);
            }
            return;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
        if (func_00262AA8(s1) != 0) {
            return;
        }
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
