/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00129578(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);

extern int D_005864F0;
__attribute__((section(".text.func_00113228")))
void func_00113228(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0 &&
        *(unsigned char *)(s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)(s1 + 0x649) = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0xC8, 0x14, 0x26, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0xC8, 0x14, 0x26, 0, 0x123);
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        {
            char *v = *(char **)(s1 + 0x304);
            func_002A8578(s1, *(int *)(v + 0x60C) + (int)v, *(int *)(v + 0x610) + (int)v, 0.0f, 3, 0, 0);
        }
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 1: {
        float one;
        char *e;
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        e = *(char **)(s1 + 0x640);
        if (e != 0) {
            char *vt = *(char **)(e + 0x214);
            char *p = *(char **)(s1 + 0xF0);
            int off = *(short *)(vt + 0x68);
            int (*fp)() = *(int (**)())(vt + 0x6C);
            int r = fp(e + off);
            if (capVu0MagnitudeSqXZ(p, (void *)r) < 1.21f) {
                *(int *)(s1 + 0x330) = 0;
                *(int *)(s1 + 0x338) = 0;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    }
    func_0010A438(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}
