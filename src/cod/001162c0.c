/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern void func_00124EC0(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void func_002DB7A8(void);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void func_0012C348(void *a0, int a1);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern char D_005864F0[];
extern char D_00462FC0[];
extern char D_005FEE00[];
extern int D_007474A8;
extern int D_00747A24;

/* sn-2.95.3-136 matched TU. */


























__attribute__((section(".text.func_001162C0")))
void func_001162C0(void *a0) {
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    Obj293_SetByte_53C_2(D_005864F0);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x200;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int b;

        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x8E0) + b, *(int *)(b + 0x8E4) + b,
                      0.0f, 0, 0, 0);
        moveMotion(s1);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xF5, s1, 0, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
        /* fallthrough */
    case 1: {
        float r = Turn_dest(s1 + 0x580, *(float *)(s1 + 0x104),
                            *(float *)(s1 + 0x5A8) * 0.39269909f,
                            *(void **)(s1 + 0xF0));

        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        *(float *)(s1 + 0x338) = -0.1f;
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8E8) + b, *(int *)(b + 0x8EC) + b,
                      0.0f, 0, 0, 0);
        *(short *)(s1 + 0x568) = 10;
        *(float *)(s1 + 0x15C0) = 30.0f;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        *(int *)(s1 + 0x15B0) = 0;
        *(int *)(s1 + 0x15B4) = 0;
        *(int *)(s1 + 0x15B8) = 0;
    }
        /* fallthrough */
    case 3: {
        float rate;
        float mag;
        float mag2;
        float r;
        int lim;

        func_002DB7A8();
        if (*(int *)(s1 + 0x15B8) != 0) {
            *(int *)(s1 + 0x15B8) = *(int *)(s1 + 0x15B8) - 1;
        }
        *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            switch (*(int *)(s1 + 0x15B4)) {
            default:
            case 0: lim = 9; break;
            case 1: lim = 8; break;
            case 2: lim = 7; break;
            case 3: lim = 6; break;
            case 4: lim = 5; break;
            case 5: lim = 4; break;
            case 6: lim = 3; break;
            case 7: lim = 2; break;
            }
            if (*(int *)(s1 + 0x15B0) < lim) {
                *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) + 1;
            }
            if (lim < *(int *)(s1 + 0x15B0)) {
                *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) - 1;
            }
            if (*(int *)(s1 + 0x15B4) < 0) {
                *(int *)(s1 + 0x15B4) = 0;
            }
            if (*(int *)(s1 + 0x15B4) >= 8) {
                *(int *)(s1 + 0x15B4) = 7;
            }
            *(int *)(s1 + 0x15B0) = 0;
            *(int *)(s1 + 0x15B8) = 10;
        } else if (*(int *)(s1 + 0x15B8) <= 0) {
            *(int *)(s1 + 0x15B8) = 5;
            *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) - 1;
            if (*(int *)(s1 + 0x15B4) < 0) {
                *(int *)(s1 + 0x15B4) = 0;
            }
        }
        switch (*(int *)(s1 + 0x15B4)) {
        default:
        case 0: *(float *)(s1 + 0x5A8) = 1.0f; break;
        case 1: *(float *)(s1 + 0x5A8) = 1.2f; break;
        case 2: *(float *)(s1 + 0x5A8) = 1.4f; break;
        case 3: *(float *)(s1 + 0x5A8) = 1.6f; break;
        case 4: *(float *)(s1 + 0x5A8) = 1.8f; break;
        case 5: *(float *)(s1 + 0x5A8) = 2.0f; break;
        case 6: *(float *)(s1 + 0x5A8) = 2.2f; break;
        case 7: *(float *)(s1 + 0x5A8) = 2.5f; break;
        }
        SetField444SignedByFlag434_158288(s1, *(float *)(s1 + 0x5A8));
        rate = (*(float *)(s1 + 0x5A8) - 1.5f) * 0.1f;
        mag = capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), s1 + 0x580);
        if (mag < 0.09f) {
            if (rate < 0.0f) {
                rate = 0.0f;
            }
        }
        r = Turn_dest(s1 + 0x580, *(float *)(s1 + 0x104),
                      *(float *)(s1 + 0x5A8) * 0.39269909f,
                      *(void **)(s1 + 0xF0));
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + r;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        func_00124EC0(s1);
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        *(float *)(s1 + 0x338) = rate;
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (0.0f < *(float *)(s1 + 0x15C0)) {
            *(float *)(s1 + 0x15C0) =
                *(float *)(s1 + 0x15C0) - *(float *)(s1 + 0x5A8);
        }
        mag2 = capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), s1 + 0x580);
        if (mag2 < 0.25f) {
            if (*(float *)(s1 + 0x15C0) <= 0.0f) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
                break;
            }
        }
        if (*(float *)(s1 + 0x598) * *(float *)(s1 + 0x598) < mag2) {
            *(unsigned char *)(s1 + 0x2F6) = 6;
            break;
        }
        *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
        if (*(short *)(s1 + 0x568) <= 0) {
            *(short *)(s1 + 0x568) = 10;
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xF6, s1, 0, 0, 0, 0);
        }
        break;
    }
    case 4: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8F8) + b, *(int *)(b + 0x8FC) + b,
                      0.0f, 0, 0, 0);
        OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
        func_0012C348(s1, 2);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xF7, s1, 0, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
        /* fallthrough */
    case 5:
        *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        if (moveMotion(s1) != 0) {
            *(short *)(s1 + 0x54A) = 0;
            D_00747A24 = D_00747A24 | 8;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 6: {
        int b = *(int *)(s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8F0) + b, *(int *)(b + 0x8F4) + b,
                      0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
