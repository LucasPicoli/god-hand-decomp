/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00260B30(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_0022B790")))
void func_0022B790(void *a0)
{
    char *s0 = (char *)a0;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v1;
        int a1v, a2v;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s0, 0x14, 0, 0x37, -1, 0);
        v1 = *(char **)(s0 + 0x304);
        a1v = *(int *)(v1 + 0x21F4) + (int)v1;
        a2v = *(int *)(v1 + 0x21F8) + (int)v1;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *w = *(char **)(s0 + 0x304);
            a2v = *(int *)(w + 0x21FC) + (int)w;
        }
        func_002A8578(s0, a1v, a2v, 0.0f, 5, gb, 0);
        *(int *)(s0 + 0x5F0) = 0xA;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        *(int *)(s0 + 0x5FC) = 0;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (*(int *)(s0 + 0x5F0) != 0) {
            char *v0;
            *(int *)(s0 + 0x5F0) -= 1;
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(v0 + 0xF0), *(float *)(s0 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    func_00260B30(s0);
    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        *(int *)(s0 + 0x5FC) = 1;
    }
    if (*(int *)(s0 + 0x5FC) != 0) {
        *(int *)(s0 + 0x16D4) &= 0xFFFFFBFF;
    }
}
