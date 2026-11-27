/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"

extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_0012B928(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cHeatSys_SetHeatMode(void *a0, int a1);
extern void func_0010A438(void *a0);
extern unsigned char D_005CB000[];
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern char D_005864F0[];

__attribute__((section(".text.func_00114120")))
void func_00114120(void *a0)
{
    cGameObj *s1 = a0;
    float one;
    s1->hitFlash = 15.0f;
    switch (s1->step) {
    case 0: {
        char *v0;
        int p1, p2;
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        v0 = s1->pack;
        p1 = *(int *)(v0 + 0x10) + (int)v0;
        p2 = *(int *)(v0 + 0x14) + (int)v0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 5, 0x17, 0x2A, 0, 0xA);
        *(char *)((char *)s1 + 0x1684) = 1;
        func_002A8578(s1, p1, p2, 3, 0.0f, 0, 0);
        func_0012B928(s1);
        CallWithAndClearField698_12AC28(s1);
        s1->step += 1;
    }
    case 1:
        if (moveMotion(s1) != 0) {
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    if (s1->seqFlags & 1) {
        char *hs = (char *)D_005CB000;
        if (*(unsigned char *)(hs + 0x10) == 0) {
            cHeatSys_SetHeatMode(hs, 1);
            *(int *)((char *)s1 + 0x15F4) = (*(int *)((char *)s1 + 0x15F4) | 0x10) & ~0x20;
            CallWithAndClearField698_12AC28(s1);
            func_0012B928(s1);
        }
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) == 0) {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}

__attribute__((section(".text.func_00111010")))
void func_00111010(void *a0)
{
    cGameObj *s0 = a0;
    float one;
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0: {
        int p1, p2;
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s0);
        if (s0->stepArg != 0) {
            char *v = s0->pack;
            p1 = *(int *)(v + 0x4BC) + (int)v;
            p2 = *(int *)(v + 0x4C0) + (int)v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x32, 0x26, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x32, 0x26, 0x1D, 0, 0x123);
        } else {
            char *v = s0->pack;
            p1 = *(int *)(v + 0x494) + (int)v;
            p2 = *(int *)(v + 0x498) + (int)v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x32, 0x25, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x32, 0x25, 0x1D, 0, 0x123);
        }
        *(char *)((char *)s0 + 0x1684) = 0;
        func_002A8578(s0, p1, p2, 0, 0.0f, 0, 0);
        cCoreSave_addGameLevelPoint(&D_00569B70, 100);
        s0->hitFlash = 15.0f;
        s0->step += 1;
    }
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            pl00_clearMotionCam(s0, 1, 0);
            *(char *)((char *)s0 + 0x2F4) = 0;
            *(char *)((char *)s0 + 0x2F5) = 0;
            *(char *)((char *)s0 + 0x2F6) = 0;
            *(char *)((char *)s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    func_0010A438(s0);
    if (s0->seqFlags & 0x100) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if (func_00123938(s0, 1) != 0) {
        pl00_clearMotionCam(s0, 1, 0);
    }
}
