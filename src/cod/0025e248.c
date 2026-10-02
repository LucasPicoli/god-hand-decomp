/* sn-2.95.3-136 matched TU. */

extern int Getplayer(void);
extern void SetMotionStep(void *a0, float f12);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00281560(int a0, int a1);
extern void func_00283438(int a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002705D8(void *a0);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern char D_00462FC0[];
extern char D_005CB000[];

#include "godhand/vu0.h"



















__attribute__((section(".text.func_0025E248")))
void func_0025E248(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float buf[4] __attribute__((aligned(16)));
    float v;

    s1 = (char *)Getplayer();
    v = *(float *)(s1 + 0x5A8);
    *(float *)(s0 + 0x5A8) = v;
    SetMotionStep(s0, v);
    *(float *)(s0 + 0x54C) = 3.0f;
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x3E4C) + w, *(int *)(w + 0x3E50) + w,
                      0.0f, 0, 0, 0);
        if (*(int *)(s0 + 0x748) != 0)
            func_00281560(*(int *)(s0 + 0x748), 0);
        if (*(int *)(s0 + 0x74C) != 0)
            func_00283438(*(int *)(s0 + 0x74C), 0);
        if (*(int *)(s0 + 0x750) != 0)
            func_00283438(*(int *)(s0 + 0x750), 0);
        *(short *)(s0 + 0x56A) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto phase1;
    }
    case 2: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x3E54) + w, *(int *)(w + 0x3E58) + w,
                      0.0f, 0, 0, 0);
        if (*(int *)(s0 + 0x748) != 0)
            func_00281560(*(int *)(s0 + 0x748), 1);
        if (*(int *)(s0 + 0x74C) != 0)
            func_00283438(*(int *)(s0 + 0x74C), 1);
        if (*(int *)(s0 + 0x750) != 0)
            func_00283438(*(int *)(s0 + 0x750), 1);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
    case 3:
    phase1:
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6);
        break;
    case 4: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x3E5C) + w, *(int *)(w + 0x3E60) + w,
                      0.0f, 0, 0, 0);
        if (*(int *)(s0 + 0x748) != 0)
            func_00281560(*(int *)(s0 + 0x748), 2);
        if (*(int *)(s0 + 0x74C) != 0)
            func_00283438(*(int *)(s0 + 0x74C), 2);
        if (*(int *)(s0 + 0x750) != 0)
            func_00283438(*(int *)(s0 + 0x750), 2);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(s0))
            func_002705D8(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }

    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            VU0_SQC2_VF0(buf, 0);
            buf[0] = fRand1_1() * 0.1f;
            buf[1] = fRand1_1() * 0.1f + 1.5f;
            buf[2] = fRand0_1() * 0.1f + 0.7f;
            sceVu0ApplyMatrix(buf, s1 + 0x80, buf);
            SetEffectPos(0, 0x4F, 0, buf, -1, 1.0f);
        }
        if (*(short *)(s0 + 0x56A) != 0) {
            if (*(unsigned short *)(s0 + 0x3AC) & 1) {
                int vt = *(int *)(s0 + 0x214);
                short off = *(short *)(vt + 0xA8);
                int (*fp)() = *(int (**)())(vt + 0xAC);
                fp(s0 + off, 0x14, s1, 0, 0);
                if (*(short *)(s0 + 0x54A) <= 0)
                    *(short *)(s0 + 0x54A) = 1;
                cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
            }
            if (*(unsigned short *)(s0 + 0x3AC) & 2) {
                int vt = *(int *)(s0 + 0x214);
                short off = *(short *)(vt + 0xA8);
                int (*fp)() = *(int (**)())(vt + 0xAC);
                fp(s0 + off, 0xC8, s1, 0, 0);
                cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
            }
        }
        *(short *)(s0 + 0x56A) = 0;
    } else {
        *(short *)(s0 + 0x56A) = 1;
    }
}
