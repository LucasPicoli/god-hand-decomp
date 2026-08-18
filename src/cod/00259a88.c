/* sn-2.95.3-136 matched TU. */

extern float fRand0_1(void);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern void Obj1D00_SetState_7_E_a1(void *a0, int a1);
extern void Obj1D00_SetState_7_10(void *a0);
extern void Obj1D00_SetState_7_12(void *a0);
extern void Obj1D00_SetState_7_14(void *a0);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern unsigned char D_005FEE00[];
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */







extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f,
                               int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5,
                          int a6);
















__attribute__((section(".text.func_00259A88")))
void func_00259A88(void *a0)
{
    char *s1 = (char *)a0;
    int p1;
    int p2;

    switch (*(int *)(s1 + 0x564)) {
    case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
    case 0x22C: case 0x22D: case 0x22E: case 0x22F:
    case 0x248: case 0x249: case 0x24C: case 0x24E: case 0x25A:
        if (*(unsigned char *)(s1 + 0x2F6) == 0) {
            if (fRand0_1() < 0.25f) {
                *(unsigned char *)(s1 + 0x2F6) = 2;
            }
        }
        break;
    case 0x213: case 0x217:
        if (*(unsigned char *)(s1 + 0x2F6) == 0) {
            if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                if (Forward30F348_31CFE0() & 1) {
                    *(unsigned char *)(s1 + 0x2F6) = 8;
                }
            }
        }
        break;
    }

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int nb;

        if (func_002740D8(s1) != 0) {
            if (Forward30F348_31CFE0() & 1) {
                *(char *)(s1 + 0x17C3) = 1;
            } else {
                *(char *)(s1 + 0x17C3) = 0;
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        switch (*(int *)(s1 + 0x564)) {
        default:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x618) + b;
                p2 = *(int *)(b + 0x61C) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x620) + b;
                p2 = *(int *)(b + 0x624) + b;
            }
            break;
        case 0x20A:
        case 0x20B:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x24F:
        case 0x278:
        case 0x279:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB2C) + b;
                p2 = *(int *)(b + 0xB30) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB34) + b;
                p2 = *(int *)(b + 0xB38) + b;
            }
            break;
        case 0x250:
        case 0x251:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB2C) + b;
                p2 = *(int *)(b + 0xB30) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB34) + b;
                p2 = *(int *)(b + 0xB38) + b;
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s1) + 0x23),
                               s1, 0, 0, 0, 0);
            break;
        case 0x260:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB2C) + b;
                p2 = *(int *)(b + 0xB30) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xB34) + b;
                p2 = *(int *)(b + 0xB38) + b;
            }
            break;
        case 0x264:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x326C) + b;
                p2 = *(int *)(b + 0x3270) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x326C) + b;
                p2 = *(int *)(b + 0x3270) + b;
            }
            break;
        case 0x265:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3818) + b;
                p2 = *(int *)(b + 0x381C) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3818) + b;
                p2 = *(int *)(b + 0x381C) + b;
            }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x17A8) + b;
                p2 = *(int *)(b + 0x17AC) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x17A8) + b;
                p2 = *(int *)(b + 0x17AC) + b;
            }
            break;
        case 0x241:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3AEC) + b;
                p2 = *(int *)(b + 0x3AF0) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3AEC) + b;
                p2 = *(int *)(b + 0x3AF0) + b;
            }
            break;
        case 0x209:
        case 0x21F:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x17A8) + b;
                p2 = *(int *)(b + 0x17AC) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x17A8) + b;
                p2 = *(int *)(b + 0x17AC) + b;
            }
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xF54) + b;
                p2 = *(int *)(b + 0xF58) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xF5C) + b;
                p2 = *(int *)(b + 0xF60) + b;
            }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x618) + b;
                p2 = *(int *)(b + 0x61C) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x618) + b;
                p2 = *(int *)(b + 0x61C) + b;
            }
            break;
        case 0x223:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2E7C) + b;
                p2 = *(int *)(b + 0x2E80) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2E7C) + b;
                p2 = *(int *)(b + 0x2E80) + b;
            }
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1380) + b;
                p2 = *(int *)(b + 0x1384) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1388) + b;
                p2 = *(int *)(b + 0x138C) + b;
            }
            break;
        }
        *(float *)(s1 + 0x600) = 1.0f;
        if (*(unsigned char *)(s1 + 0x17C1) != 0) {
            *(float *)(s1 + 0x600) = 1.5f;
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, nb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, *(float *)(s1 + 0x600));
        if (*(unsigned short *)(s1 + 0x3AC) & 8) {
            *(float *)(s1 + 0x54C) = 2.0f;
        }
        break;
    case 2: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1400) + b, *(int *)(b + 0x1404) + b,
                      0.0f, 3, 0, 0);
        *(float *)(s1 + 0x54C) = 10.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        *(int *)(s1 + 0x16D4) |= 0x80000;
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 4: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1408) + b, *(int *)(b + 0x140C) + b,
                      0.0f, 3, 0, 0);
        *(short *)(s1 + 0x568) = 5;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5: {
        char *g;
        float t;

        *(int *)(s1 + 0x16D4) |= 0x80000;
        g = Obj0000_Get_D_00747A94_2DB6B0();
        t = Turn_dest(*(void **)(g + 0xF0), *(float *)(s1 + 0x104),
                      *(float *)(s1 + 0x5A8) * 0.098174773f,
                      *(void **)(s1 + 0xF0));
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + t;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        if (moveMotion(s1) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            if (*(short *)(s1 + 0x568) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 6: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x1410) + b, *(int *)(b + 0x1414) + b,
                      0.0f, 3, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 8:
        if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
            int b = *(int *)(s1 + 0x304);
            char *o = *(char **)(s1 + 0x708);

            p1 = *(int *)(b + 0x2F74) + b;
            p2 = *(int *)(b + 0x2F78) + b;
            if (o != 0) {
                Obj1D00_SetState_7_E_a1(o, 1);
            }
        } else {
            int b = *(int *)(s1 + 0x304);
            char *o = *(char **)(s1 + 0x708);

            p1 = *(int *)(b + 0x2F7C) + b;
            p2 = *(int *)(b + 0x2F80) + b;
            if (o != 0) {
                Obj1D00_SetState_7_E_a1(o, 0);
            }
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        *(float *)(s1 + 0x54C) = 10.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
        /* fallthrough */
    case 9:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0xA;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 10: {
        int b = *(int *)(s1 + 0x304);
        char *o;

        func_002A8578(s1, *(int *)(b + 0x2F94) + b, *(int *)(b + 0x2F98) + b,
                      0.0f, 3, 0, 0);
        o = *(char **)(s1 + 0x708);
        if (o != 0) {
            Obj1D00_SetState_7_14(o);
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 11:
        *(int *)(s1 + 0x16D0) |= 0x800000;
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0xC;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 12: {
        int b = *(int *)(s1 + 0x304);
        char *o;

        func_002A8578(s1, *(int *)(b + 0x2F84) + b, *(int *)(b + 0x2F88) + b,
                      0.0f, 3, 0, 0);
        *(short *)(s1 + 0x568) = 5;
        o = *(char **)(s1 + 0x708);
        if (o != 0) {
            Obj1D00_SetState_7_10(o);
        }
        *(float *)(s1 + 0x600) = 3.0f;
        switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
        case 0:
        default: *(float *)(s1 + 0x604) = 60.0f; break;
        case 1: *(float *)(s1 + 0x604) = 90.0f; break;
        case 2: *(float *)(s1 + 0x604) = 120.0f; break;
        case 3: *(float *)(s1 + 0x604) = 120.0f; break;
        case 4: *(float *)(s1 + 0x604) = 120.0f; break;
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 13: {
        char *g = Obj0000_Get_D_00747A94_2DB6B0();

        AddScaledDeltaToField_104_2A7498(s1, *(int *)(g + 0xF0),
                                         *(float *)(s1 + 0x5A8) * 0.049087387f);
        moveMotion(s1);
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x5A8) * -0.05f;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x600) <= 0.0f) {
            func_0026BEF0(s1, 0x12, 0);
            *(float *)(s1 + 0x600) = 20.0f;
        }
        *(float *)(s1 + 0x604) = *(float *)(s1 + 0x604) - *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x604) <= 0.0f) {
            *(unsigned char *)(s1 + 0x2F6) = 0xE;
        }
        break;
    }
    case 14: {
        int b = *(int *)(s1 + 0x304);
        char *o;

        func_002A8578(s1, *(int *)(b + 0x2F8C) + b, *(int *)(b + 0x2F90) + b,
                      0.0f, 3, 0, 0);
        o = *(char **)(s1 + 0x708);
        if (o != 0) {
            Obj1D00_SetState_7_12(o);
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 15:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F5) = 0x49;
            *(unsigned char *)(s1 + 0x2F6) = 2;
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
