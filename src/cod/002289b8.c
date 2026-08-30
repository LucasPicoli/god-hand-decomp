/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern int Forward30F348_31CFE0(void);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_00569B70[];

__attribute__((section(".text.func_002289B8")))
void func_002289B8(void *a0)
{
    char *s0 = (char *)a0;

    *(unsigned char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        char *sv;
        int r;
        int w;
        int p1;
        int p2;
        *(unsigned char *)(s0 + 0x1864) = 0;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s0, 0x14, 0, 0x37, -1, 0);
        w = *(int *)(s0 + 0x304);
        sv = D_00569B70;
        p1 = *(int *)(w + 0x15F8) + w;
        p2 = *(int *)(w + 0x15FC) + w;
        if (cCoreSave_getGameLevel(sv) == 5) {
            int w2 = *(int *)(s0 + 0x304);
            p2 = *(int *)(w2 + 0x1600) + w2;
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, r, 0);
        *(int *)(s0 + 0x5F0) = 0xF;
        switch (cCoreSave_getGameLevel(sv) - 1) {
        default:
        case 0:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.75f);
            break;
        case 1:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.8f);
            break;
        case 2:
        case 3:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.9f);
            break;
        case 4:
            break;
        }
        *(int *)(s0 + 0x5FC) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (*(int *)(s0 + 0x5F0) != 0) {
            char *p;
            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            p = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(p + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s0))
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 0x10) &&
            *(unsigned char *)(s0 + 0x1864) == 0 &&
            cCoreSave_getGameLevel(D_00569B70) >= 2 &&
            (Forward30F348_31CFE0() & 1))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        break;
    case 2: {
        char *sv;
        int r;
        int w;
        int p1;
        int p2;
        int five;
        *(unsigned char *)(s0 + 0x1864) = 0;
        five = 5;
        r = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s0, 0x14, 3, 0x37, -1, 0);
        w = *(int *)(s0 + 0x304);
        sv = D_00569B70;
        p1 = *(int *)(w + 0x1604) + w;
        p2 = *(int *)(w + 0x1608) + w;
        if (cCoreSave_getGameLevel(sv) == five) {
            int w2 = *(int *)(s0 + 0x304);
            p2 = *(int *)(w2 + 0x160C) + w2;
        }
        func_002A8578(s0, p1, p2, 0.0f, 1, r, 0);
        *(int *)(s0 + 0x5F0) = five;
        switch (cCoreSave_getGameLevel(sv) - 1) {
        default:
        case 0:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.75f);
            break;
        case 1:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.8f);
            break;
        case 2:
        case 3:
            *(int *)(s0 + 0x5F0) = (int)((float)*(int *)(s0 + 0x5F0) * 0.9f);
            break;
        case 4:
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (*(int *)(s0 + 0x5F0) != 0) {
            char *p;
            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            p = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(p + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (moveMotion(s0))
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
    if (*(unsigned char *)(s0 + 0x1864) == 0)
        func_00260B30(s0);
    if (*(unsigned short *)(s0 + 0x3AC) & 3)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(unsigned int *)(s0 + 0x16D4) &= 0xFFFFFBFFU;
}
