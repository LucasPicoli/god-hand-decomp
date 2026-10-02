/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);
extern char D_00462FC0[];

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_001158E8")))
void func_001158E8(void *a0)
{
    float va[4], vb[4], vc[4];
    char *s1 = (char *)a0;
    float *d;
    float *s;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    *(float *)(s1 + 0x54C) = 5.0f;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int t;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        d = (float *)(s1 + 0x490);
        (*(float **)(s1 + 0xF0))[0] = *(float *)(s1 + 0x660);
        (*(float **)(s1 + 0xF0))[2] = *(float *)(s1 + 0x668);
        s = *(float **)(s1 + 0xF0);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x670);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x4CC) + t, *(int *)(t + 0x4D0) + t, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        func_00124EC0(s1);
        *(int *)(s1 + 0x15F4) |= 0x80;
        cCollisionSolidManage_SetActive(D_00462FC0, s1, 0);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x338) + *(float *)(s1 + 0x338);
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
            float *pa = va;
            float *pb;
            s = (float *)(s1 + 0x490);
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
            if (ChkLine(pa, pb, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                (*(float **)(s1 + 0xF0))[1] = vc[1];
                *(unsigned char *)(s1 + 0x2F6) = 2;
            }
        }
        break;
    }
    case 2: {
        int t = *(int *)(s1 + 0x304);
        int p1 = *(int *)(t + 0x4D4) + t;
        int p2 = *(int *)(t + 0x4D8) + t;
        SetEffectParts(0, 0x2D, s1, 0, 0.0f, 0.0f, 0.0f, 1.0f, -1);
        func_002A8578(s1, p1, p2, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
}
