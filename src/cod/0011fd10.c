/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern char D_00462FC0[];
extern unsigned char D_005864F0[];
extern char D_005FEE00[];
extern int D_007474A8;

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern unsigned int Forward30F348_31CFE0(void);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern void func_002DB7A8(void);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f12);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f12);
extern void func_0012C348(void *a0, int a1);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int t0, float f12);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern void func_0012C0F8(void *a0, int a1);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern void func_00124EC0(void *a0);
extern float DoubleFloatMinusHalf_31D020(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void func_0010A438(void *a0);

__attribute__((section(".text.func_0011FD10")))
void func_0011FD10(void *a0)
{
    char *s0 = (char *)a0;
    float buf[4];
    char *s1;
    int f1;
    int f2;
    int lim;

    *(char *)(s0 + 0x648) = 0x1E;
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10000;
    s1 = *(char **)(s0 + 0x694);
    *(char **)(s0 + 0x640) = s1;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        float v;

        ClearField15F4Bit1_124F60(s0, 0, 0);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.100000001f;
        buf[2] = 1.0f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, v);
        switch (Forward30F348_31CFE0() % 3) {
        default:
        case 0: {
            int p = *(int *)(s0 + 0x304);
            f1 = *(int *)(p + 0x140) + p;
            f2 = *(int *)(p + 0x144) + p;
            break;
        }
        case 1: {
            int p = *(int *)(s0 + 0x304);
            f1 = *(int *)(p + 0x4DC) + p;
            f2 = *(int *)(p + 0x4E0) + p;
            break;
        }
        case 2: {
            int p = *(int *)(s0 + 0x304);
            f1 = *(int *)(p + 0x4E4) + p;
            f2 = *(int *)(p + 0x4E8) + p;
            break;
        }
        }
        func_002A8578(s0, f1, f2, 0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56A) = 5;
        *(short *)(s0 + 0x56E) = 0xF;
        *(short *)(s0 + 0x56C) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        if (*(short *)(s0 + 0x56E) != 0 && s1 != 0) {
            char *p;
            char *q;
            p = *(char **)(s0 + 0xF0);
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        *(float *)(s0 + 0x54C) = 5.0f;
        func_002DB7A8();
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (s1 != 0) {
            if ((*(unsigned short *)(s1 + 0x3AC) & 3) != 0) {
                switch (Forward30F348_31CFE0() % 3) {
                default:
                case 0: {
                    int p = *(int *)(s0 + 0x304);
                    f1 = *(int *)(p + 0x140) + p;
                    f2 = *(int *)(p + 0x144) + p;
                    break;
                }
                case 1: {
                    int p = *(int *)(s0 + 0x304);
                    f1 = *(int *)(p + 0x4DC) + p;
                    f2 = *(int *)(p + 0x4E0) + p;
                    break;
                }
                case 2: {
                    int p = *(int *)(s0 + 0x304);
                    f1 = *(int *)(p + 0x4E4) + p;
                    f2 = *(int *)(p + 0x4E8) + p;
                    break;
                }
                }
                func_002A8578(s0, f1, f2, 0.0f, 0, 0, 0);
                moveMotion(s0);
                AddScaledVecToField_100_14F9F0(s0, 1.0f);
                AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
            }
            func_0012C348(s0, 0);
            {
                char *e;
                int bb;
                int lm;
                bb = *(unsigned char *)(s0 + 0x2B4);
                *(int *)buf = bb;
                lm = 4;
                if (lm < bb) {
                    e = *(char **)(*(int *)(s0 + 0x278) + 0x10);
                } else {
                    e = 0;
                }
                if (e != 0) {
                    SetEffectPos(0x58, 0x10, 0, *(void **)(e + 0xF0), -1, 1.0f);
                }
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xA, s0, 0, 0, 0, 0);
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0 && *(int *)(s0 + 0x15B4) != 0) {
            *(int *)(s0 + 0x15B4) = 0;
            func_0012C348(s0, 2);
        } else {
            *(int *)(s0 + 0x15B4) = 1;
        }
        *(short *)(s0 + 0x56A) = *(short *)(s0 + 0x56A) - 1;
        if (*(short *)(s0 + 0x56A) > 0) {
            break;
        }
        *(short *)(s0 + 0x56A) = 0xA;
        if (s1 == 0) {
            break;
        }
        func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 12.0f));
        break;
    case 2: {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.100000001f;
        buf[2] = 1.0f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, v);
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            cEm00_GetPlMotion(s1, 0x26, v, v);
        } else {
            cEm00_GetPlMotion(s1, 0x27, v, v);
        }
        *(int *)(s0 + 0x15B0) = 0;
        *(int *)(s0 + 0x15B8) = 0;
        *(int *)(s0 + 0x15B4) = 4;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0, 0xA, 0, 0x2C, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0, 0x64, 0, 0x1D, 0, 0xA);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 3:
        *(float *)(s0 + 0x54C) = 5.0f;
        func_002DB7A8();
        if (*(int *)(s0 + 0x640) != 0) {
            *(char *)(s0 + 0x648) = 0x1E;
        }
        InvokeVirtualAtField214AndForward_124E68(s0, 0.392699093f);
        if (*(int *)(s0 + 0x15B8) != 0) {
            *(int *)(s0 + 0x15B8) = *(int *)(s0 + 0x15B8) - 1;
        }
        *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            switch (*(int *)(s0 + 0x15B4)) {
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
            if (*(int *)(s0 + 0x15B0) < lim) {
                *(int *)(s0 + 0x15B4) = *(int *)(s0 + 0x15B4) + 1;
            }
            if (lim < *(int *)(s0 + 0x15B0)) {
                *(int *)(s0 + 0x15B4) = *(int *)(s0 + 0x15B4) - 1;
            }
            if (*(int *)(s0 + 0x15B4) < 0) {
                *(int *)(s0 + 0x15B4) = 0;
            }
            if (*(int *)(s0 + 0x15B4) >= 8) {
                *(int *)(s0 + 0x15B4) = 7;
            }
            *(int *)(s0 + 0x15B0) = 0;
            *(int *)(s0 + 0x15B8) = 0xA;
        } else {
            if (*(int *)(s0 + 0x15B8) <= 0) {
                *(int *)(s0 + 0x15B8) = 5;
                *(int *)(s0 + 0x15B4) = *(int *)(s0 + 0x15B4) - 1;
                if (*(int *)(s0 + 0x15B4) < 0) {
                    *(int *)(s0 + 0x15B4) = 0;
                }
            }
        }
        switch (*(int *)(s0 + 0x15B4)) {
        default:
        case 0: *(float *)(s0 + 0x5A8) = 1.0f; break;
        case 1: *(float *)(s0 + 0x5A8) = 1.25f; break;
        case 2: *(float *)(s0 + 0x5A8) = 1.5f; break;
        case 3: *(float *)(s0 + 0x5A8) = 1.75f; break;
        case 4: *(float *)(s0 + 0x5A8) = 2.0f; break;
        case 5: *(float *)(s0 + 0x5A8) = 2.25f; break;
        case 6: *(float *)(s0 + 0x5A8) = 2.5f; break;
        case 7: *(float *)(s0 + 0x5A8) = 3.0f; break;
        }
        SetField444SignedByFlag434_158288(s0, *(float *)(s0 + 0x5A8));
        func_00124EC0(s0);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 3) == 0) {
            break;
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x123, s0, 0, 0, 0, 0);
        VU0_SQC2_VF0(buf, 0x0);
        buf[0] = DoubleFloatMinusHalf_31D020() * 0.200000003f;
        buf[1] = DoubleFloatMinusHalf_31D020() * 0.200000003f + 1.29999995f;
        buf[2] = DoubleFloatMinusHalf_31D020() * 0.200000003f + 0.600000024f;
        sceVu0ApplyMatrix(buf, s0 + 0x80, buf);
        SetEffectPos(0, 0x40, 0, buf, -1, 1.0f);
        break;
    case 4: {
        buf[1] = 0.0f;
        buf[0] = -0.100000001f;
        buf[2] = 1.5f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, buf[1]);
        { int g1; int g2;
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int pa = *(int *)(s0 + 0x304);
            g1 = *(int *)(pa + 0x6AC) + pa;
            g2 = *(int *)(pa + 0x6B0) + pa;
        } else {
            int pb = *(int *)(s0 + 0x304);
            g1 = *(int *)(pb + 0x810) + pb;
            g2 = *(int *)(pb + 0x814) + pb;
        }
        func_002A8578(s0, g1, g2, 0.0f, 3, 0, 0); }
        *(short *)(s0 + 0x56E) = 0xF;
        *(float *)(s0 + 0x54C) = 2.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 5:
        if (*(short *)(s0 + 0x56E) != 0 && s1 != 0) {
            char *q = s1 + 0x550;
            char *p;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        if (*(short *)(s0 + 0x56C) != 0) {
            *(float *)(s0 + 0x54C) = 5.0f;
        }
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            ClearField15F4Bit1_124F60(s0, 0, 0);
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    func_0010A438(s0);
}
