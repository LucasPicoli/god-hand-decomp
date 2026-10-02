/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);
extern char D_00462FC0[];
extern char D_005FEE00[];
extern int D_00747A24;
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void func_0012C348(void *a0, int a1);

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_00115C00")))
void func_00115C00(void *a0)
{
    float va[4], vb[4], vc[4];
    char *s1 = (char *)a0;
    float one;
    float *s;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int t;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x670);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x8B0) + t, *(int *)(t + 0x8B4) + t, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 1: {
        func_00124EC0(s1);
        *(int *)(s1 + 0x15F4) |= 0x2080;
        Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
        *(unsigned short *)(s1 + 0x434) |= 8;
        if (moveMotion(s1) != 0) {
            D_00747A24 |= 8;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
            float *pa = va;
            float *pb;
            s = *(float **)(s1 + 0xF0);
            if (pa != s) {
                va[0] = s[0];
                pa[1] = s[1];
                pa[2] = s[2];
            }
            s = *(float **)(s1 + 0xF0);
            pb = vb;
            if (pb != s) {
                vb[0] = s[0];
                vb[1] = s[1];
                vb[2] = s[2];
            }
            va[1] = va[1] + 0.5f;
            vb[1] = vb[1] - one;
            if (ChkLine(pa, pb, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                int m1 = ~0x80;
                int m2 = ~0x2000;
                (*(float **)(s1 + 0xF0))[1] = vc[1];
                *(unsigned char *)(s1 + 0x2F6) = 2;
                *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) & m1 & m2;
                Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 1);
                *(unsigned short *)(s1 + 0x3AC) &= 0xFFFB;
            }
        }
        if (*(unsigned short *)(s1 + 0x3AC) & 1) {
            *(short *)(s1 + 0x54A) = 0;
            OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
            func_0012C348(s1, 2);
        }
        break;
    }
    case 2: {
        int t = *(int *)(s1 + 0x304);
        int p1 = *(int *)(t + 0x8D0) + t;
        int p2 = *(int *)(t + 0x8D4) + t;
        SetEffectParts(0, 0x2D, s1, 0, 0.0f, 0.0f, 0.0f, 1.0f, -1);
        func_002A8578(s1, p1, p2, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
}
