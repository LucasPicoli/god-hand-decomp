/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void func_0010A438(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern int D_005864F0;

__attribute__((section(".text.func_00113A20")))
void func_00113A20(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    switch (s1->step) {
    case 0: {
        int p1, p2;
        int s2;
        int t;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        func_00129578(s1);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 5, 0x17, 0x2A, 0, 0xA);
        *(char *)((char *)s1 + 0x1684) = 1;
        s1->seqFlags |= 1;
        func_0010A438(s1);
        if (s1->stepArg) {
            char *q = s1->pack;
            p1 = *(int *)(q + 0x294) + (int)q;
            p2 = *(int *)(q + 0x29C) + (int)q;
        } else {
            char *r = s1->pack;
            p1 = *(int *)(r + 0x294) + (int)r;
            p2 = *(int *)(r + 0x298) + (int)r;
        }
        func_002A8578(s1, p1, p2, 3, 0.0f, 0, 0);
        if (s1->stepArg) {
            s2 = s1->hpMax;
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
        } else {
            s2 = (int)(s1->hpMax * 0.3f);
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
        }
        t = *(unsigned short *)((char *)s1 + 0x54A) + s2;
        s1->hp = t;
        if (s1->hpMax < (short)t) {
            s1->hp = *(unsigned short *)((char *)s1 + 0x548);
        }
        s1->step += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_00124EC0(s1);
        if (s1->seqFlags & 0x100) {
            cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 0, 0);
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
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 0, 0);
    } else {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}
