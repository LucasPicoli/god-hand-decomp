/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_00462FC0[];
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00129630(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005864F0[];
extern char D_005FEE00[];

__attribute__((section(".text.func_001156D8")))
void func_001156D8(void *a0)
{
    char *s1 = (char *)a0;
    float *d;
    float *s;

    *(float *)(s1 + 0x54C) = 5.0f;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int t;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x670);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x4C4) + t, *(int *)(t + 0x4C8) + t, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        *(int *)(s1 + 0x15F4) |= 0x80;
        cCollisionSolidManage_SetActive(D_00462FC0, s1, 0);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 2: {
        int t;
        d = *(float **)(s1 + 0xF0);
        s = (float *)(s1 + 0x660);
        if (d != s) {
            d[0] = *(float *)(s1 + 0x660);
            d[1] = s[1];
            d[2] = s[2];
        }
        d = (float *)(s1 + 0x490);
        s = *(float **)(s1 + 0xF0);
        if (d != s) {
            *(float *)(s1 + 0x490) = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x670);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x4D4) + t, *(int *)(t + 0x4D8) + t, 0.0f, 0, 0, 0);
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

/* sn-2.95.3-136 matched TU. */





















/* sn-2.95.3-136 matched TU. */























__attribute__((section(".text.func_001120A8")))
void func_001120A8(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x870) + t, *(int *)(t + 0x874) + t,
                      0.0f, 3, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            func_0012BC00(s1, 0x2F, 0);
        }
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        char *g = D_005FEE00;
        cSnd_SeStop(g, *(int *)(s1 + 0x161C));
        *(int *)(s1 + 0x161C) = 0;
        *(int *)(g + 0xB0) &= 0xFFBFFFFF;
        *(int *)(g + 0xAC) &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
