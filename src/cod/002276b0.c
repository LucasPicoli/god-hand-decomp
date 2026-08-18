/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void func_00262AA8(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */














__attribute__((section(".text.func_002276B0")))
void func_002276B0(void *a0)
{
    char *s0 = (char *)a0;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    if (*(unsigned char *)(s0 + 0x2F6) == 0) {
        if (*(float *)(s0 + 0x618) < 36.0f) {
            *(char *)(s0 + 0x2F6) = 8;
        }
    }
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v1;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x1F10) + (int)v1,
                      *(int *)(v1 + 0x1F14) + (int)v1, 0xA, 0.0f, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *v0;
        *(int *)(s0 + 0x16D4) |= 0x20000;
        v0 = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(v0 + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    case 2: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x1F18) + (int)v1,
                      *(int *)(v1 + 0x1F1C) + (int)v1, 3, 0.0f, gb, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        char *v0;
        *(int *)(s0 + 0x16D4) |= 0x20000;
        v0 = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(v0 + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F6) = 4;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                *(int *)(s0 + 0x5F0) = 0;
                func_0026BEF0(s0, 9, 0);
            }
        }
        break;
    }
    case 4: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x1F2C) + (int)v1,
                      *(int *)(v1 + 0x1F30) + (int)v1, 0xA, 0.0f, gb, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
        default:
        case 0:
            *(float *)(s0 + 0x600) = 20.0f;
            break;
        case 1:
            *(float *)(s0 + 0x600) = 10.0f;
            break;
        case 2:
        case 3:
            *(float *)(s0 + 0x600) = 5.0f;
            break;
        case 4:
            *(float *)(s0 + 0x600) = 0.0f;
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5: {
        float d;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            *(char *)(s0 + 0x2F6) = 2;
            if (*(float *)(s0 + 0x618) > 225.0f) {
                *(char *)(s0 + 0x2F6) = 6;
            }
            if (*(float *)(s0 + 0x618) < 9.0f) {
                *(char *)(s0 + 0x2F6) = 6;
            }
        }
        break;
    }
    case 6: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x1F24) + (int)v1,
                      *(int *)(v1 + 0x1F28) + (int)v1, 0xA, 0.0f, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(s0) != 0) {
            if (*(float *)(s0 + 0x618) > 25.0f) {
                *(char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                func_002705D8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 8: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x1F34) + (int)v1,
                      *(int *)(v1 + 0x1F38) + (int)v1, 3, 0.0f, gb, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 9: {
        char *v0;
        *(int *)(s0 + 0x16D4) |= 0x20000;
        v0 = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(v0 + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.09817477f);
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                *(int *)(s0 + 0x5F0) = 0;
                func_0026BEF0(s0, 9, 0);
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
            func_00262AA8(s0);
        }
        break;
    }
    default:
        break;
    }
}
