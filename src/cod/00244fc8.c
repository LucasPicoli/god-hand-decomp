/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int Forward30F348_31CFE0(void);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_00244FC8")))
void func_00244FC8(void *a0)
{
    char *s1 = (char *)a0;
    int s2v, s0v;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        switch (*(int *)(s1 + 0x564)) {
        default:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xD80) + b;
                s0v = *(int *)(b + 0xD84) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xD88) + b;
                s0v = *(int *)(b + 0xD8C) + b;
            }
            break;
        case 522: case 523: case 524: case 525: case 526:
        case 536:
        case 581: case 582: case 583:
        case 591:
        case 632: case 633:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x8A4) + b;
                s0v = *(int *)(b + 0x8A8) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x8AC) + b;
                s0v = *(int *)(b + 0x8B0) + b;
            }
            break;
        case 517: case 518: case 519:
        case 521:
        case 543:
        case 548:
            if (*(unsigned short *)(s1 + 0x3AC) & 0x200) {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x189C) + b;
                s0v = *(int *)(b + 0x18A0) + b;
            } else {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18A4) + b;
                s0v = *(int *)(b + 0x18A8) + b;
            }
            break;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1);
        func_002A8578(s1, s2v, s0v, 0.0f, 5, gb & 0xFFFF, 0);
        moveMotion(s1);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 1: {
        float r = Turn_dest(s1 + 0x580, *(float *)(s1 + 0x104),
                            *(float *)(s1 + 0x5A8) * 0.39269909f,
                            *(void **)(s1 + 0xF0));
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        int gb, w;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        w = *(int *)(s1 + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xD90) + b;
                s0v = *(int *)(b + 0xD94) + b;
            }
            break;
        case 5: case 6: case 7: case 8: case 9:
        case 19:
        case 64: case 65: case 66:
        case 74:
        case 115: case 116:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x8B4) + b;
                s0v = *(int *)(b + 0x8B8) + b;
            }
            break;
        case 0: case 1: case 2:
        case 4:
        case 26:
        case 31:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18AC) + b;
                s0v = *(int *)(b + 0x18B0) + b;
            }
            break;
        }
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        if ((Forward30F348_31CFE0() & 1) != 0) {
            *(float *)(s1 + 0x600) = 0.0099999998f;
        } else {
            *(float *)(s1 + 0x600) = -0.019999999f;
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 3: {
        char *v580 = s1 + 0x580;
        float r;
        float mag;
        r = Turn_dest(v580, *(float *)(s1 + 0x104),
                      *(float *)(s1 + 0x5A8) * 0.39269909f,
                      *(void **)(s1 + 0xF0));
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        SetField444SignedByFlag434_158288(s1, *(float *)(s1 + 0x5A8) * 1.5f);
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x600) * *(float *)(s1 + 0x5A8);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        mag = capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), v580);
        if (mag < 4.0f) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
        } else if (*(float *)(s1 + 0x598) * *(float *)(s1 + 0x598) < mag) {
            *(unsigned char *)(s1 + 0x2F6) = 6;
        }
        break;
    }
    case 4: {
        int gb, w;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        w = *(int *)(s1 + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xDA0) + b;
                s0v = *(int *)(b + 0xDA4) + b;
            }
            break;
        case 5: case 6: case 7: case 8: case 9:
        case 19:
        case 64: case 65: case 66:
        case 74:
        case 115: case 116:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x8C4) + b;
                s0v = *(int *)(b + 0x8C8) + b;
            }
            break;
        case 0: case 1: case 2:
        case 4:
        case 26:
        case 31:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18BC) + b;
                s0v = *(int *)(b + 0x18C0) + b;
            }
            break;
        }
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 5:
        *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        if (moveMotion(s1) != 0) {
            int fp = *(int *)(s1 + 0xF0);
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x10000;
            *(float *)(fp + 4) = *(float *)(fp + 4) - 10.0f;
            *(char *)(s1 + 0x2F4) = 2;
            *(char *)(s1 + 0x2F5) = 2;
            *(char *)(s1 + 0x2F7) = 1;
            *(char *)(s1 + 0x2F6) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) | 0x400;
        break;
    case 6: {
        int gb, w;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        w = *(int *)(s1 + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0xD98) + b;
                s0v = *(int *)(b + 0xD9C) + b;
            }
            break;
        case 5: case 6: case 7: case 8: case 9:
        case 19:
        case 64: case 65: case 66:
        case 74:
        case 115: case 116:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x8BC) + b;
                s0v = *(int *)(b + 0x8C0) + b;
            }
            break;
        case 0: case 1: case 2:
        case 4:
        case 26:
        case 31:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x18B4) + b;
                s0v = *(int *)(b + 0x18B8) + b;
            }
            break;
        }
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 7:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
