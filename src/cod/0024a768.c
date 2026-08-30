/* sn-2.95.3-136 matched TU. */

extern int Obj2B28_SetField34_To1_ReturnZero(void *);
extern int Obj2B28_SetField34_To2_ReturnZero(void *);
extern int Obj2B28_ReturnZero_F68(void *);
extern int Obj2B28_ReturnZero_F70(void *);
extern int Obj2B28_ReturnZero_F78(void *);
extern int Obj2B28_ReturnZero_FA8(void *);
extern int Obj2B28_ReturnZero_FD0(void *);
extern int Obj2B28_CopyU16_8C2_To38_ReturnZero(void *);
extern int Obj2B28_ReturnZero_FF0(void *);
extern int Obj2B28_ReturnZero_FF8(void *);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void Obj2810_ClearState_4(void *a0);
extern void SetBytes2F4Mode4_283240(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int moveMotion(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_0026DB00(void *a0, int a1, int a2);
extern int D_00569B70;
extern char D_005FEE00[];

/* sn-2.95.3-136 candidate. */






























__attribute__((section(".text.func_002B2638")))
int func_002B2638(void *obj) {
    switch (**(unsigned short **)((char *)obj + 0x8C) & 0xFF00) {
    default:     return 2;
    case 0x8100: return func_002B2A30(obj);
    case 0x8200: return func_002B2A58(obj);
    case 0x8300: return func_002B2AE8(obj);
    case 0x8500: return func_002B2B08(obj);
    case 0xA600: return func_002B2B78(obj);
    case 0xA700: return func_002B2BA8(obj);
    case 0x8700: return Obj2B28_SetField34_To1_ReturnZero(obj);
    case 0x8A00: return Obj2B28_SetField34_To2_ReturnZero(obj);
    case 0xA100:
    case 0xA500: return 0;
    case 0xA200: return func_002B2F38(obj);
    case 0xE100: return Obj2B28_ReturnZero_F68(obj);
    case 0xE000: return Obj2B28_ReturnZero_F70(obj);
    case 0xE200: return Obj2B28_ReturnZero_F78(obj);
    case 0xE400: return func_002B2BD8(obj);
    case 0xE500: return func_002B2C98(obj);
    case 0xD300: return func_002B2F80(obj);
    case 0x8800: return Obj2B28_ReturnZero_FA8(obj);
    case 0x8B00: return func_002B2FB0(obj);
    case 0xD500: return Obj2B28_ReturnZero_FD0(obj);
    case 0xAC00: return Obj2B28_CopyU16_8C2_To38_ReturnZero(obj);
    case 0xD600: return Obj2B28_ReturnZero_FF0(obj);
    case 0xD700: return Obj2B28_ReturnZero_FF8(obj);
    case 0xD800: return func_002B3000(obj);
    case 0x8C00: return func_002B3008(obj);
    case 0x8E00: return func_002B3020(obj);
    case 0xAD00: return func_002B2D28(obj);
    case 0x8F00: return func_002B3038(obj);
    case 0xDA00: return func_002B3050(obj);
    case 0xE700: return func_002B2D88(obj);
    }
}

/* sn-2.95.3-136 matched TU. */

















__attribute__((section(".text.func_0024A768")))
void func_0024A768(void *a0)
{
    char *s0 = (char *)a0;

    *(int *)(s0 + 0x16D0) |= 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int nb;
        char *v1;

        *(char *)(s0 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x3D8C) + (int)v1,
                      *(int *)(v1 + 0x3D90) + (int)v1, 0xA, 0.0f, nb, 0);
        if (*(void **)(s0 + 0x748) != 0)
            Obj2810_ClearState_4(*(void **)(s0 + 0x748));
        if (*(void **)(s0 + 0x74C) != 0)
            SetBytes2F4Mode4_283240(*(void **)(s0 + 0x74C));
        if (*(void **)(s0 + 0x750) != 0)
            SetBytes2F4Mode4_283240(*(void **)(s0 + 0x750));
        StoreMotionParamsBoth_2609A8(s0, 0x32, 0x3B, 0x3E, -1, 0);
        *(float *)(s0 + 0x600) = 0.0f;
        *(short *)(s0 + 0x568) = 0;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        *(int *)(s0 + 0x16D0) |= 0x800000;
        if (moveMotion(s0) != 0) {
            if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                if ((Forward30F348_31CFE0() & 1) != 0) {
                    if (*(float *)(s0 + 0x618) > 64.0f) {
                        *(char *)(s0 + 0x2F4) = 0;
                        *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                        *(char *)(s0 + 0x2F6) = 0;
                        *(char *)(s0 + 0x2F7) = 0;
                        break;
                    }
                }
            }
            *(char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0xA1;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
        float t = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);

        *(float *)(s0 + 0x600) = t;
        if (t <= 0.0f) {
            *(float *)(s0 + 0x600) = 35.0f;
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x1E, s0, 0, 0, 0, 0);
            if ((Forward30F348_31CFE0() & 1) != 0) {
                func_0026BEF0(s0, 0x19, 0);
                func_0026BEF0(s0, 0x19, 2);
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    func_0026BEF0(s0, 0x19, 1);
                    func_0026BEF0(s0, 0x19, 3);
                }
                *(short *)(s0 + 0x568) = 1;
            } else {
                func_0026BEF0(s0, 0x19, 4);
                func_0026BEF0(s0, 0x19, 6);
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    func_0026BEF0(s0, 0x19, 5);
                    func_0026BEF0(s0, 0x19, 7);
                }
                *(short *)(s0 + 0x568) = 0;
            }
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
            func_0026DB00(s0, 5, 0);
        }
    }
}
