/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void StoreMotionParams_2609E0(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Set_Fields_1884_1894_2609F8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026EE40(void *a0, int a1, int a2);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_00260B30(void *a0);
extern char D_00569B70[];

__attribute__((section(".text.func_002266F0")))
void func_002266F0(void *a0)
{
    char *s0 = (char *)a0;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        int s2v, s0v;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (*(int *)(s0 + 0x564)) {
        default:
        case 0x250:
        case 0x251:
            {
                int b;

                StoreMotionParamsBoth_2609A8(s0, 0x50, 0x1E, 0x3E, -1, 0);
                b = *(int *)(s0 + 0x304);
                s2v = *(int *)(b + 0x19AC) + b;
                s0v = *(int *)(b + 0x19B0) + b;
                *(int *)(s0 + 0x5F0) = 0x64;
            }
            break;
        case 0x260:
            {
                int b;

                StoreMotionParams_2609E0(s0, 0x46, 0x1F, 0x3E, -1, 0);
                Set_Fields_1884_1894_2609F8(s0, 0x46, 0x20, 0x3E, -1, 0);
                b = *(int *)(s0 + 0x304);
                s2v = *(int *)(b + 0x30BC) + b;
                s0v = *(int *)(b + 0x30C0) + b;
                *(int *)(s0 + 0x5F0) = 0x64;
            }
            break;
        case 0x223:
            {
                int b;

                StoreMotionParamsBoth_2609A8(s0, 0x32, 0x21, 0x3E, -1, 0);
                b = *(int *)(s0 + 0x304);
                s2v = *(int *)(b + 0x2E0C) + b;
                s0v = *(int *)(b + 0x2E10) + b;
                *(int *)(s0 + 0x5F0) = 0;
            }
            break;
        }
        func_002A8578(s0, s2v, s0v, 0.0f, 0xA, gb, 0);
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(int *)(s0 + 0x5F0) = 0x46;
            break;
        case 2:
            *(int *)(s0 + 0x5F0) = 0x50;
            break;
        case 3:
            *(int *)(s0 + 0x5F0) = 0x5A;
            break;
        case 4:
            *(int *)(s0 + 0x5F0) = 0x5A;
            break;
        case 5:
            break;
        }
        *(int *)(s0 + 0x5FC) = 0;
        *(int *)(s0 + 0x5F4) = 0x64;
        func_0026EE40(s0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        int n;

        if (*(int *)(s0 + 0x5F0) != 0) {
            char *o;

            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            o = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(o + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634954f);
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F4) >= 0xB)
                *(int *)(s0 + 0x5F4) = 0xA;
        }
        n = *(int *)(s0 + 0x5F4);
        if (n != 0) {
            *(int *)(s0 + 0x16D0) |= 0x800000;
            *(int *)(s0 + 0x5F4) = n - 1;
        }
        if (moveMotion(s0) != 0)
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    default:
        break;
    }
    func_00260B30(s0);
    if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
        if (func_00262AA8(s0) != 0)
            return;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 3)
        *(int *)(s0 + 0x5FC) = 1;
    if (*(int *)(s0 + 0x5FC) != 0)
        *(unsigned int *)(s0 + 0x16D4) &= 0xFFFFFBFFU;
}
