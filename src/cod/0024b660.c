/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_002813F0(void *a0, int a1);
extern void func_002832F8(void *a0, int a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern void func_00260278(void *a0);
extern int D_00569B70;
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_0024B660")))
void func_0024B660(void *a0)
{
    char *s2 = (char *)a0;

    *(int *)(s2 + 0x16D0) |= 0x30400;
    *(float *)(s2 + 0x16E4) = 2700.0f;
    switch (*(unsigned char *)(s2 + 0x2F6)) {
    case 0: {
        int nb;
        char *v1;
        *(char *)(s2 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        v1 = *(char **)(s2 + 0x304);
        func_002A8578(s2, *(int *)(v1 + 0x3E14) + (int)v1,
                      *(int *)(v1 + 0x3E18) + (int)v1, 0.0f, 0xA, nb, 0);
        if (*(void **)(s2 + 0x748) != 0)
            func_002813F0(*(void **)(s2 + 0x748), 0);
        if (*(void **)(s2 + 0x74C) != 0)
            func_002832F8(*(void **)(s2 + 0x74C), 0);
        if (*(void **)(s2 + 0x750) != 0)
            func_002832F8(*(void **)(s2 + 0x750), 0);
        *(int *)(s2 + 0x5F0) = 1;
        *(unsigned char *)(s2 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        *(int *)(s2 + 0x16D0) |= 0x800000;
        if (moveMotion(s2) != 0) {
            *(unsigned char *)(s2 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        if ((*(unsigned short *)(s2 + 0x3AC) & 1) != 0) {
            if (*(int *)(s2 + 0x5F0) != 0) {
                *(int *)(s2 + 0x5F0) = 0;
                if ((Forward30F348_31CFE0() & 1) != 0) {
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                        func_00260278(s2);
                    }
                }
                func_00260278(s2);
            }
        }
        break;
    case 2: {
        int nb;
        char *v1;
        *(char *)(s2 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        v1 = *(char **)(s2 + 0x304);
        func_002A8578(s2, *(int *)(v1 + 0x3E1C) + (int)v1,
                      *(int *)(v1 + 0x3E20) + (int)v1, 0.0f, 0xA, nb, 0);
        if (*(void **)(s2 + 0x748) != 0)
            func_002813F0(*(void **)(s2 + 0x748), 1);
        if (*(void **)(s2 + 0x74C) != 0)
            func_002832F8(*(void **)(s2 + 0x74C), 1);
        if (*(void **)(s2 + 0x750) != 0)
            func_002832F8(*(void **)(s2 + 0x750), 1);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(float *)(s2 + 0x600) = 600.0f;
            break;
        case 2:
            *(float *)(s2 + 0x600) = 300.0f;
            break;
        case 3:
            *(float *)(s2 + 0x600) = 210.0f;
            break;
        case 4:
            *(float *)(s2 + 0x600) = 210.0f;
            break;
        case 5:
            *(float *)(s2 + 0x600) = 150.0f;
            break;
        }
        *(unsigned char *)(s2 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        int n;
        char *tbl;
        *(char *)(s2 + 0x617) = 1;
        moveMotion(s2);
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
            float t = *(float *)(s2 + 0x600) - *(float *)(s2 + 0x5A8);
            *(float *)(s2 + 0x600) = t;
            if (t <= 0.0f) {
                *(unsigned char *)(s2 + 0x2F6) = 6;
            }
        }
        tbl = (char *)&D_005864F0;
        n = func_002919C0(tbl, 0x220, 0x220);
        n += func_002919C0(tbl, 0x220, 0x221);
        n += func_002919C0(tbl, 0x220, 0x222);
        if (n == 0) {
            *(unsigned char *)(s2 + 0x2F6) = 4;
        }
    }
        break;
    case 4: {
        int nb;
        char *v1;
        *(char *)(s2 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        v1 = *(char **)(s2 + 0x304);
        func_002A8578(s2, *(int *)(v1 + 0x3E24) + (int)v1,
                      *(int *)(v1 + 0x3E28) + (int)v1, 0.0f, 0xA, nb, 0);
        if (*(void **)(s2 + 0x748) != 0)
            func_002813F0(*(void **)(s2 + 0x748), 2);
        if (*(void **)(s2 + 0x74C) != 0)
            func_002832F8(*(void **)(s2 + 0x74C), 2);
        if (*(void **)(s2 + 0x750) != 0)
            func_002832F8(*(void **)(s2 + 0x750), 2);
        *(unsigned char *)(s2 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s2) != 0) {
            *(char *)(s2 + 0x2F4) = 0;
            *(unsigned char *)(s2 + 0x2F5) = 0xA1;
            *(char *)(s2 + 0x2F6) = 0;
            *(char *)(s2 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        break;
    case 6: {
        int nb;
        char *v1;
        *(char *)(s2 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        v1 = *(char **)(s2 + 0x304);
        func_002A8578(s2, *(int *)(v1 + 0x3E2C) + (int)v1,
                      *(int *)(v1 + 0x3E30) + (int)v1, 0.0f, 0xA, nb, 0);
        if (*(void **)(s2 + 0x748) != 0)
            func_002813F0(*(void **)(s2 + 0x748), 3);
        if (*(void **)(s2 + 0x74C) != 0)
            func_002832F8(*(void **)(s2 + 0x74C), 3);
        if (*(void **)(s2 + 0x750) != 0)
            func_002832F8(*(void **)(s2 + 0x750), 3);
        *(unsigned char *)(s2 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
        *(char *)(s2 + 0x617) = 1;
        if (moveMotion(s2) != 0) {
            *(unsigned char *)(s2 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        break;
    }
}
