/* sn-2.95.3-136 matched TU. */

extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00260B30(void *a0);
extern void Obj293_OrByte_5A3(void *a0, int a1);
extern void Obj293_OrByte_5A4(void *a0, int a1);
extern void Obj293_OrByte_5A5_1(void *a0);
extern void Obj293_ClearBytes_5A0_5A3(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern unsigned char D_005FEE00[];
extern int D_005864F0;
extern char D_00462FC0[];
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */


























/* sn-2.95.3-136 matched TU. */

extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f,
                              int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5,
                          int a6);

__attribute__((section(".text.func_0022C3F8")))
void func_0022C3F8(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    int flag = 0;

    *(int *)(s1 + 0x16D4) |= 4;
    if (*(int *)(s1 + 0x564) == 0x214) {
        char *g = (char *)&D_005864F0;

        s2 = *(char **)(g + 0x564);
    } else {
        char *g = (char *)&D_005864F0;

        s2 = *(char **)(g + 0x560);
    }
    if (*(unsigned char *)(s1 + 0x2F6) == 0xB) {
        char *g = (char *)&D_005864F0;

        if (*(unsigned char *)(g + 0x5A2) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0xC;
        }
    }
    if (s2 != 0) {
        if ((*(long *)(s2 + 0x2F0) & 0xFFFF00000000L) == 0x3C0000000000L) {
            flag = 1;
        } else {
            flag = 0;
        }
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        char *b = *(char **)(s1 + 0x304);

        *(char *)(s1 + 0x1864) = 0;
        func_002A8578(s1, *(int *)(b + 0x10C0) + (int)b,
                      *(int *)(b + 0x10C8) + (int)b, 0.0f, 0xA, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)(Obj0000_Get_Field_424_1595F0(s1) + 0xA),
                           s1, 0, 0, 0, 0);
        *(float *)(s1 + 0x600) = 150.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *m = s1 + 0x580;

        AddScaledDeltaToField_104_2A7498(s1, (int)m,
                                         *(float *)(s1 + 0x5A8) * 0.196349546f);
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (capVu0MagnitudeSqXZ(m, *(void **)(s1 + 0xF0)) < 1.0f) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (s2 == 0 || *(float *)(s1 + 0x600) <= 0.0f) {
            char *g = (char *)&D_005864F0;

            Obj293_ClearBytes_5A0_5A3(g);
            func_002705D8(s1);
        }
        break;
    }
    case 2: {
        char *b = *(char **)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1A98) + (int)b,
                      *(int *)(b + 0x1A9C) + (int)b, 0.0f, 0xA, 0, 0);
        {
            char *g = (char *)&D_005864F0;

            if (*(int *)(s1 + 0x564) == 0x214) {
                Obj293_OrByte_5A3(g, 1);
            } else {
                Obj293_OrByte_5A3(g, 2);
            }
        }
        *(float *)(s1 + 0x600) = 90.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        if (s2 != 0) {
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(s2 + 0xF0),
                                             *(float *)(s1 + 0x5A8) * 0.196349546f);
        }
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (s2 == 0 || *(float *)(s1 + 0x600) <= 0.0f) {
            goto L784;
        }
        {
            char *g = (char *)&D_005864F0;

            if (*(unsigned char *)(g + 0x5A0) != 0) {
                *(unsigned char *)(s1 + 0x2F6) += 1;
            }
        }
        break;
    case 4:
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            *(float *)(s1 + 0x600) = 16.0f;
        } else {
            *(float *)(s1 + 0x600) = 45.0f;
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
        /* fallthrough */
    case 5:
        if (s2 != 0) {
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(s2 + 0xF0),
                                             *(float *)(s1 + 0x5A8) * 0.196349546f);
        }
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (s2 != 0) {
            goto L79C;
        }
    L784:
        {
            char *g = (char *)&D_005864F0;

            Obj293_ClearBytes_5A0_5A3(g);
        }
        func_002705D8(s1);
        break;
    L79C:
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x600) <= 0.0f) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        break;
    case 6: {
        char *b;
        char *g = (char *)&D_005864F0;

        if (*(int *)(s1 + 0x564) == 0x214) {
            Obj293_OrByte_5A4(g, 1);
        } else {
            Obj293_OrByte_5A4(g, 2);
        }
        b = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x1AA0) + (int)b,
                      *(int *)(b + 0x1AA4) + (int)b, 0.0f, 3, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        {
            char *g = (char *)&D_005864F0;

            if (*(unsigned char *)(g + 0x5A1) != 0) {
                *(unsigned char *)(s1 + 0x2F6) += 1;
            }
        }
        break;
    case 8: {
        char *b = *(char **)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1AB0) + (int)b,
                      *(int *)(b + 0x1AB4) + (int)b, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 9:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        goto LA64;
    case 10: {
        char *b = *(char **)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1AC0) + (int)b,
                      *(int *)(b + 0x1AC4) + (int)b, 0.0f, 0, 0, 0);
        *(float *)(s1 + 0x604) = 1.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 11: {
        float acc;
        float theta;
        float turn;

        acc = *(float *)(s1 + 0x604) + *(float *)(s1 + 0x5A8) * 0.0199999996f;
        *(float *)(s1 + 0x604) = acc;
        if (2.0f < acc) {
            *(float *)(s1 + 0x604) = 2.0f;
        }
        SetField444SignedByFlag434_158288(s1, *(float *)(s2 + 0x5A8) *
                                              *(float *)(s1 + 0x604));
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (2.0f <= *(float *)(s1 + 0x604)) {
            theta = Adjust_theta(*(float *)(s1 + 0x104) + 3.14159274f);
            {
                char *o = *(char **)(s1 + 0xF0);
                char *r = Obj0000_Get_D_00747A94_2DB6B0();

                turn = Turn_dest(o, theta, 3.14159274f, *(void **)(r + 0xF0));
            }
            if (Forward30F348_31CFE0() & 1) {
                if (-0.785398185f < turn) {
                    if (turn < -0.261799395f) {
                        char *g = (char *)&D_005864F0;

                        Obj293_OrByte_5A5_1(g);
                        *(float *)(g + 0x59C) = Adjust_theta(theta + turn);
                    }
                }
            }
        }
    LA64:
        if (*(unsigned short *)(s1 + 0x3AC) & 1) {
            StoreMotionParamsBoth_2609A8(s1, 0x28, 0, 0x3F, -1, 0);
            func_00260B30(s1);
        }
        if (flag != 0) {
            break;
        }
        *(unsigned char *)(s1 + 0x2F4) = 1;
        *(unsigned char *)(s1 + 0x2F5) = 0x11;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        return;
    }
    case 12: {
        char *b;
        char *g = (char *)&D_005864F0;

        *(float *)(s1 + 0x104) = *(float *)(g + 0x59C) + 3.14159274f;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        b = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x1AD0) + (int)b,
                      *(int *)(b + 0x1AD4) + (int)b, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 13:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(unsigned short *)(s1 + 0x3AC) & 1) {
            StoreMotionParamsBoth_2609A8(s1, 0x28, 0, 0x3F, -1, 0);
            func_00260B30(s1);
        }
        break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 0x20) {
        Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    }
}
