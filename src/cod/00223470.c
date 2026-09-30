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
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);


extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern int D_00569B70;
__attribute__((section(".text.func_00223470")))
void func_00223470(void *a0)
{
    char *s0 = (char *)a0;
    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        {
            char *b = *(char **)(s0 + 0x304);
            a1v = *(int *)(b + 0x6E8) + (int)b;
            a2v = *(int *)(b + 0x6EC) + (int)b;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            v0 = *(char **)(s0 + 0x304);
            a2v = *(int *)(v0 + 0x6F0) + (int)v0;
        }
        func_002A8578(s0, a1v, a2v, 0.0f, 3, gb, 0);
        *(int *)(s0 + 0x5F0) = 0xF;
        *(int *)(s0 + 0x5F4) = 0;
        *(int *)(s0 + 0x5FC) = 0;
        func_0026EE40(s0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        if (*(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) -= 1;
            AddScaledDeltaToField_104_2A7498(s0, *(int *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), *(float *)(s0 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s0) != 0) {
            func_0026EE40(s0, 0, 0);
            if (func_00262AA8(s0) != 0) return;
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(int *)(s0 + 0x5F4) == 0) {
            if (*(unsigned short *)(s0 + 0x3AC) & 2) {
                SetEffect(0x58, 0x29, s0, 0, -1, 0xFFFFFFFF);
                *(int *)(s0 + 0x5F4) = 1;
            }
        }
        break;
    }
    StoreMotionParamsBoth_2609A8(s0, 0, 0xF, 0x4A, -1, 0);
    if (*(unsigned short *)(s0 + 0x3AC) & 1)
        func_00260B30(s0);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
        if (func_0026F1D8(s0) == 0 && (*(unsigned short *)(s0 + 0x3AC) & 0x10) != 0)
            if (func_00262AA8(s0) != 0) return;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 3)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(int *)(s0 + 0x16D4) &= 0xFFFFFBFF;
}
