/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_002705D8(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_0026AB20(void *a0, int a1, int a2);
extern void func_00260B30(void *a0);
extern char D_00569B70[];

__attribute__((section(".text.func_002349F8")))
void func_002349F8(void *a0)
{
    char *s0 = (char *)a0;

    *(unsigned char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int r;
        int base;
        int p1;
        int p2;
        *(unsigned char *)(s0 + 0x1864) = 0;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        base = *(int *)(s0 + 0x304);
        p1 = *(int *)(base + 0x2030) + base;
        p2 = *(int *)(base + 0x2034) + base;
        if (cCoreSave_getGameLevel(D_00569B70) == 5) {
            int b2 = *(int *)(s0 + 0x304);
            p2 = *(int *)(b2 + 0x2038) + b2;
        }
        func_002A8578(s0, p1, p2, 0.0f, 0xA, r, 0);
        *(int *)(s0 + 0x5F0) = 0x1E;
        StoreMotionParamsBoth_2609A8(s0, 0x28, 0x12, 0x3A, 0, 0x112);
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.75f);
            break;
        case 2:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.8f);
            break;
        case 3:
        case 4:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.9f);
            break;
        case 5:
            break;
        }
        *(int *)(s0 + 0x5F4) = 1;
        *(int *)(s0 + 0x5FC) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (*(int *)(s0 + 0x5F0) != 0) {
            int q;
            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            q = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(q + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s0)) {
            AddScaledVecToField_100_14F9F0(s0, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
            func_002705D8(s0);
            return;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }

    if (*(unsigned short *)(s0 + 0x3AC) & 2) {
        if (*(int *)(s0 + 0x5F4) != 0) {
            *(int *)(s0 + 0x5F4) = 0;
            if (*(int *)(s0 + 0x6EC) != 0) {
                ReleaseField6ECByTag564_26B1E8(s0);
            } else {
                int h = func_0026AA30(s0, 0x362);
                *(int *)(s0 + 0x6EC) = h;
                func_0026AB20(s0, h, 0x362);
            }
        }
    } else {
        *(int *)(s0 + 0x5F4) = 1;
    }
    *(unsigned short *)(s0 + 0x3AC) = *(unsigned short *)(s0 + 0x3AC) & 0xFFFD;
    func_00260B30(s0);
    if (cCoreSave_getGameLevel(D_00569B70) >= 3 && func_0026F1D8(s0) == 0 &&
        (*(unsigned short *)(s0 + 0x3AC) & 0x10) &&
        *(unsigned char *)(s0 + 0x1864) == 0 && func_00262AA8(s0) != 0)
        return;
    if (*(unsigned short *)(s0 + 0x3AC) & 3)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(unsigned int *)(s0 + 0x16D4) &= 0xFFFFFBFFU;
}
