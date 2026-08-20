/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void Obj2810_ClearState_6(void *a0);
extern void SetBytes2F4Mode5_283258(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern int moveMotion(void *a0);
extern int Forward30F348_31CFE0(void);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002DC4B8(void *a0);
extern void func_0026DB00(void *a0, int a1, int a2);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */














__attribute__((section(".text.func_0024ABC0")))
void func_0024ABC0(void *a0)
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
        func_002A8578(s0, *(int *)(v1 + 0x3D9C) + (int)v1,
                      *(int *)(v1 + 0x3DA0) + (int)v1, 0xA, 0.0f, nb, 0);
        if (*(void **)(s0 + 0x748) != 0)
            Obj2810_ClearState_6(*(void **)(s0 + 0x748));
        if (*(void **)(s0 + 0x74C) != 0)
            SetBytes2F4Mode5_283258(*(void **)(s0 + 0x74C));
        if (*(void **)(s0 + 0x750) != 0)
            SetBytes2F4Mode5_283258(*(void **)(s0 + 0x750));
        *(float *)(s0 + 0x600) = 0.0f;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(float *)(s0 + 0x600) = 0.0f;
            break;
        case 2:
            *(float *)(s0 + 0x600) = 5.0f;
            break;
        case 3:
            *(float *)(s0 + 0x600) = 10.0f;
            break;
        case 4:
            *(float *)(s0 + 0x600) = 10.0f;
            break;
        case 5:
            *(float *)(s0 + 0x600) = 15.0f;
            break;
        }
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
        if ((*(unsigned short *)(s0 + 0x3AC) & 0x10) != 0) {
            if (*(float *)(s0 + 0x600) > 0.0f) {
                *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
            } else {
                func_002DC4B8(s0);
            }
        }
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
        func_0026DB00(s0, 1, 0);
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 2) != 0) {
        func_0026DB00(s0, 1, 1);
    }
}
