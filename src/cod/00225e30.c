/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int cCoreSave_getGameLevel(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_00260B30(void *a0);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern char D_00569B70[];

__attribute__((section(".text.func_00225E30")))
void func_00225E30(void *a0)
{
    char *s1 = (char *)a0;

    *(unsigned char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s1);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int r;
        int p1;
        int p2;
        *(unsigned char *)(s1 + 0x1864) = 0;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s1, 0x28, 0, 0x3E, 0, 0x111);
        if (cCoreSave_getGameLevel(D_00569B70) >= 2 &&
            (Forward30F348_31CFE0() & 1)) {
            int w = *(int *)(s1 + 0x304);
            p1 = *(int *)(w + 0x1DF0) + w;
            p2 = *(int *)(w + 0x1DF4) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s1 + 0x304);
                p2 = *(int *)(w2 + 0x1DF8) + w2;
            }
            *(int *)(s1 + 0x5F4) = 0x66;
        } else {
            int w = *(int *)(s1 + 0x304);
            p1 = *(int *)(w + 0x1DE4) + w;
            p2 = *(int *)(w + 0x1DE8) + w;
            if (cCoreSave_getGameLevel(D_00569B70) == 5) {
                int w2 = *(int *)(s1 + 0x304);
                p2 = *(int *)(w2 + 0x1DEC) + w2;
            }
            *(int *)(s1 + 0x5F4) = 0x2C;
        }
        *(int *)(s1 + 0x5FC) = 0;
        func_002A8578(s1, p1, p2, 0.0f, 0xA, r, 0);
        *(int *)(s1 + 0x5F0) = 0x2C;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f);
            break;
        case 2:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f);
            break;
        case 3:
        case 4:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f);
            break;
        case 5:
            break;
        }
        *(int *)(s1 + 0x5F8) = 0;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (*(int *)(s1 + 0x5F0) != 0) {
            int q;
            *(int *)(s1 + 0x5F0) = *(int *)(s1 + 0x5F0) - 1;
            q = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(q + 0xF0),
                                             *(float *)(s1 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s1))
            func_002705D8(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    default:
        break;
    }

    if (*(unsigned short *)(s1 + 0x3AC) & 1)
        func_00260B30(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 2) {
        if (*(int *)(s1 + 0x5F8) == 0) {
            *(int *)(s1 + 0x5F8) = 1;
            func_0026BEF0(s1, 4, 0);
        }
        *(int *)(s1 + 0x5F0) = 0x1E;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f);
            break;
        case 2:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f);
            break;
        case 3:
        case 4:
            *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f);
            break;
        case 5:
            break;
        }
    } else {
        *(int *)(s1 + 0x5F8) = 0;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3)
        *(int *)(s1 + 0x5FC) = 1;
    if (*(int *)(s1 + 0x5FC) != 0)
        *(unsigned int *)(s1 + 0x16D4) &= 0xFFFFFBFFU;
}
