/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern char D_00462FC0[];
extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern char D_005FEE00[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void func_00262750(void *a0, int a1);

#include "godhand/vu0.h"







__attribute__((section(".text.func_00239570")))
void func_00239570(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    float one;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;
        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3B38) + p, *(int *)(p + 0x3B3C) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
    case 1:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            int p0;
            (*(short *)(s0 + 0x56E))--;
            q = s1 + 0x550;
            p0 = *(int *)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0; *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0; *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_0011AC80")))
void func_0011AC80(void *a0)
{
    char *s1 = (char *)a0;
    float one;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        char *v0 = *(char **)(s1 + 0x304);
        int p1 = *(int *)(v0 + 0x878) + (int)v0;
        int p2 = *(int *)(v0 + 0x87C) + (int)v0;
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xCF, s1, 0, 0, 0, 0);
        *(float *)(s1 + 0x54C) = 10.0f;
        func_002A8578(s1, p1, p2, 0.0f, 1, 0, 0);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        func_0012C348(s1, 0);
        if (Forward30F348_31CFE0() & 1) {
            CallWithAndClearField698_12AC28(s1);
            func_0012B928(s1);
        }
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 1:
        if (moveMotion(s1) != 0) {
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
    func_00123938(s1, 1);
}

__attribute__((section(".text.func_0023A950")))
void func_0023A950(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p1, p2;
        int m = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        case 0:
        default:
            switch (Forward30F348_31CFE0() % 3) {
            case 0:
            default: {
                char *v = *(char **)(s0 + 0x304);
                p1 = *(int *)(v + 0xC00) + (int)v;
                p2 = *(int *)(v + 0xC04) + (int)v;
                break; }
            case 1: {
                char *v = *(char **)(s0 + 0x304);
                p1 = *(int *)(v + 0xC18) + (int)v;
                p2 = *(int *)(v + 0xC1C) + (int)v;
                break; }
            case 2: {
                char *v = *(char **)(s0 + 0x304);
                p1 = *(int *)(v + 0xC20) + (int)v;
                p2 = *(int *)(v + 0xC24) + (int)v;
                break; }
            }
            break;
        case 1: {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC24) + (int)v;
            break; }
        case 2: {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC28) + (int)v;
            break; }
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, m, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        } else {
            one = 1.0f;
            AddScaledVecToField_100_14F9F0(s0, one);
            AddScaledXfmVecToField_F0_14F928(s0, one);
        }
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_00262750(s0, 0);
    }
}
