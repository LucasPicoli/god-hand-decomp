/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/cCamera.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void *Getplayer(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00262750(void *a0, int a1);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0010A438(void *a0);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005864F0[];

__attribute__((section(".text.func_002256C8")))
void func_002256C8(void *a0)
{
    cGameObj *s1 = a0;

    *(char *)((char *)s1 + 0x186A) = 2;
    *(int *)((char *)s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(a0);
    switch (s1->step) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        *(char *)((char *)s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(a0, 0x28, 0xB, 0x42, 0, 0xF5);
        v0 = s1->pack;
        a1v = *(int *)(v0 + 0xCE4) + (int)v0;
        a2v = *(int *)(v0 + 0xCE8) + (int)v0;
        *(int *)((char *)s1 + 0x5F0) = 10;
        if (s1->emNo == 0x250 || s1->emNo == 0x251) {
            a2v = *(int *)(v0 + 0xCEC) + (int)v0;
            *(int *)((char *)s1 + 0x5F0) = 8;
        }
        func_002A8578(s1, a1v, a2v, 3, 0.0f, gb, 0);
        *(int *)((char *)s1 + 0x5FC) = 0;
        *(float *)((char *)s1 + 0x600) = s1->rot.y;
        s1->step += 1;
    }
        /* fallthrough */
    case 1: {
        if (*(int *)((char *)s1 + 0x5F0) != 0) {
            void *s0;
            char *v0;
            float th;
            *(int *)((char *)s1 + 0x5F0) -= 1;
            s0 = *(void **)((char *)s1 + 0xF0);
            v0 = (char *)Getplayer();
            th = Turn_dest(s0, *(float *)((char *)s1 + 0x600), *(void **)(v0 + 0xF0), s1->speedRate * 0.19634955f);
            *(float *)((char *)s1 + 0x600) += th;
            *(float *)((char *)s1 + 0x600) = Adjust_theta(*(float *)((char *)s1 + 0x600));
            s1->rot.y += th;
            s1->rot.y = Adjust_theta(s1->rot.y);
        }
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    }
    func_00260B30(a0);
    if (s1->seqFlags & 1) {
        func_00262750(s1, 0);
    }
    if (s1->seqFlags & 3) {
        *(int *)((char *)s1 + 0x5FC) = 1;
    }
    if (*(int *)((char *)s1 + 0x5FC) != 0) {
        *(int *)((char *)s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}

__attribute__((section(".text.func_001114B0")))
void func_001114B0(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    if (s1->step != 0 &&
        *(unsigned char *)((char *)s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)((char *)s1 + 0x649) = 1;
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (s1->step) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x2BC, 0x10, 0x1E, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x2BC, 0x10, 0x1E, 0, 0x123);
        t = *(int *)((char *)s1 + 0x304);
        *(char *)((char *)s1 + 0x1684) = 1;
        func_002A8578(s1, *(int *)(t + 0x614) + t, *(int *)(t + 0x618) + t,
                      3, 0.0f, 0, 0);
        func_00129578(s1);
        cEmManage_SetSpeedRate(D_005864F0, 0.2f);
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 0, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if ((s1->seqFlags & 1) != 0) {
        cSnd *g = &D_005FEE00;
        cSnd_SeStop(g, *(int *)((char *)s1 + 0x161C));
        *(int *)((char *)s1 + 0x161C) = 0;
        g->flagsB0 &= 0xFFBFFFFF;
        g->flagsAC &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 0, 0);
    } else {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}

__attribute__((section(".text.func_001125A0")))
void func_001125A0(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    if (s1->step != 0 &&
        *(unsigned char *)((char *)s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)((char *)s1 + 0x649) = 1;
        cCoreSave_useGodItem(&D_00569B70);
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (s1->step) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x14, 0x1D, 0x23, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x50, 0xF, 0x1E, 0, 0x123);
        *(char *)((char *)s1 + 0x1684) = 1;
        func_00129578(s1);
        t = *(int *)((char *)s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x2C0) + t, *(int *)(t + 0x2C4) + t,
                      3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}
