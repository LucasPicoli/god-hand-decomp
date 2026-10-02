/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern unsigned int Rnd(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern float Adjust_theta(float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void KillEffect(void *a0, int a1, int a2);
extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);

__attribute__((section(".text.func_00278690")))
void func_00278690(void *a0)
{
    char *s0 = (char *)a0;
    float one, f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        float r = 0.0f;
        char *b;
        if (*(unsigned char *)(s0 + 0x2F7) == 0) {
            r = (float)(int)(Rnd() % 0xF0);
        }
        b = *(char **)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x2F7) = 1;
        func_002A8578(s0, *(int *)(b + 0xC) + (int)b, *(int *)(b + 0x10) + (int)b, r, 5, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        if (moveMotion(s0) != 0) {
            if (Rnd() & 1) {
                *(unsigned char *)(s0 + 0x2F6) = 2;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    case 2: {
        char *b = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x14) + (int)b, *(int *)(b + 0x18) + (int)b, 0.0f, 5, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 3:
        if (moveMotion(s0) != 0) {
            if (Rnd() & 1) {
                *(unsigned char *)(s0 + 0x2F6) = 0;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    f = *(float *)(s0 + 0x618);
    if (f < 225.0f || (*(int *)(s0 + 0x1560) & 4) != 0) {
        *(unsigned char *)(s0 + 0x2F7) = 0;
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 1;
    }
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_0011A060")))
void func_0011A060(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float one;
    float buf[4] __attribute__((aligned(16)));

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s2 = *(char **)(s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        if (s2 != 0) {
            VU0_SQC2_VF0(buf, 0);
            buf[0] = 0.0f;
            buf[2] = 0.99630004f;
            buf[1] = 0.0f;
            sceVu0ApplyMatrix(buf, s2 + 0x80, buf);
            *(float *)(*(int *)(s1 + 0xF0) + 0x0) = buf[0];
            *(float *)(*(int *)(s1 + 0xF0) + 0x8) = buf[2];
            *(float *)(s1 + 0x104) = *(float *)(s2 + 0x104) + 3.14159274f;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        cEm00_GetPlMotion(s2, 0x52, 0.0f, 0.0f);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 5, 0, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 5, 0, 0x2A, 0, 0xA);
        *(char *)(s1 + 0x1684) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1)) {
            pl00_clearMotionCam(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    if (func_00123938(s1, 1) != 0) {
        pl00_clearMotionCam(s1, 0, 0);
    } else if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
    }
}

__attribute__((section(".text.func_00248FE0")))
void func_00248FE0(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    int t, p1, p2;
    *(unsigned char *)(s0 + 0x617) = 1;
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x40000;
    if (*(short *)(s0 + 0x54A) <= 0) {
        *(float *)(s0 + 0x54C) = 3.0f;
    }
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x3978) + (int)v;
            p2 = *(int *)(v + 0x397C) + (int)v;
            }
        } else {
            {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x3990) + (int)v;
            p2 = *(int *)(v + 0x3994) + (int)v;
            }
        }
        *(float *)(s0 + 0x1764) = 300.0f;
        func_002A8578(s0, p1, p2, 0.0f, 3, t, 0);
        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) & 0xDFFFFFFF;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    case 2: {
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x3980) + (int)v;
            p2 = *(int *)(v + 0x3984) + (int)v;
            }
        } else {
            {
            char *v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x3998) + (int)v;
            p2 = *(int *)(v + 0x399C) + (int)v;
            }
        }
        KillEffect(s0, 1, 2);
        func_002A8578(s0, p1, p2, 0.0f, 3, t, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 3:
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) <= 0) {
                *(unsigned char *)(s0 + 0x2F7) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F4) = 2;
                break;
            }
            if (func_0026F1D8(s0) != 0) {
                func_00270C78(s0);
                return;
            }
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
