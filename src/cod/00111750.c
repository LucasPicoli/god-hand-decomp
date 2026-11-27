/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void cEm00_armAttackVolume(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int SetCustomIDDispOneOrAll_1EE1C0();
extern int CustomIDWork_SetColorAnimSin();
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0010A438(void *a0);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005864F0[];
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_00227FE8")))
void func_00227FE8(void *a0)
{
    cEm00 *s1 = a0;

    s1->unk186A = 2;
    s1->emFlags2 |= 0x400;
    switch (s1->step) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        s1->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        s1->stepArg = (unsigned int)irand() % 3;
        v0 = s1->pack;
        a1v = *(int *)(v0 + 0x2FEC) + (int)v0;
        a2v = *(int *)(v0 + 0x2FF0) + (int)v0;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = s1->pack;
            a2v = *(int *)(v1 + 0x2FF4) + (int)v1;
        }
        StoreMotionParamsBoth_2609A8(a0, 0x28, 0, 0x3E, -1, 0);
        func_002A8578(s1, a1v, a2v, 3, 0.0f, gb, 0);
        s1->timerA = 0x1E;
        s1->timer = 20.0f;
        s1->step += 1;
        s1->timerB = 0;
        s1->timerC = 0;
    }
        /* fallthrough */
    case 1: {
        float f1;
        if (s1->timerA != 0) {
            cGameObj *v0;
            s1->timerA -= 1;
            v0 = Getplayer();
            cGameObj_SetTgtTurn((cGameObj *)s1, v0->pos, s1->speedRate * 0.19634955f);
        }
        f1 = s1->timer;
        if (f1 > 0.0f) {
            s1->emFlags |= 0x2000;
            s1->timer = f1 - s1->speedRate;
            s1->emFlags2 |= 0x2000;
        }
        if (s1->emFlags2 & 0x4000) {
            s1->timerC = 1;
            cEm00_armAttackVolume(s1);
        }
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if ((s1->seqFlags & 0x10) && s1->timerC == 0) {
            s1->step += 1;
        }
        break;
    }
    case 2: {
        int gb;
        char *v1;
        s1->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v1 = s1->pack;
        func_002A8578(s1, *(int *)(v1 + 0x2FF8) + (int)v1, *(int *)(v1 + 0x2FFC) + (int)v1, 3, 0.0f, gb, 0);
        s1->step += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_00260B30(a0);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001EE2E8")))
void func_001EE2E8(void *a0, int a1, int a2)
{
    char *s1 = (char *)a0;

    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x2, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x3, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x4, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x5, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x6, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x7, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x8, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x9, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xA, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xB, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xC, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xD, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xE, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xF, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x10, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x17, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x18, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x19, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1A, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1B, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x11, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x12, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x13, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x14, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1C, a1);
    if (a2) {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(s1 + 0xA8C, x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(s1, 0x15, a1);
    } else {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(s1 + 0xB08, x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(s1, 0x16, a1);
    }
}

/* sn-2.95.3-136 matched TU. */




























__attribute__((section(".text.func_00111750")))
void func_00111750(void *a0)
{
    pl00 *s1 = a0;

    s1->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    s1->unk15F4 |= 0x200;
    if (s1->base.step != 0 &&
        s1->unk649 == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        s1->unk649 = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (s1->base.step) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        s1->comboSlot = 0;
        s1->comboSet = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x82, 0x11, 0x1F, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x82, 0x11, 0x1F, 0, 0x123);
        t = (int)s1->base.pack;
        s1->unk1684 = 1;
        func_002A8578(s1, *(int *)(t + 0x1C0) + t, *(int *)(t + 0x1C4) + t,
                      3, 0.0f, 0, 0);
        func_00129578(s1);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        InvokeVirtualAtField214AndForward_124E68(s1, 3.14159274f);
        s1->unk15B0 = 1;
        (s1->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if ((s1->base.seqFlags & 0x100) != 0) {
            cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 0, 0);
            s1->base.mode = 0;
            s1->base.phase = 0;
            s1->base.step = 0;
            s1->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((s1->base.seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if ((s1->base.seqFlags & 1) != 0) {
        cSnd *g = &D_005FEE00;
        cSnd_SeStop(g, s1->unk161C);
        s1->unk161C = 0;
        g->flagsB0 &= 0xFFBFFFFF;
        g->flagsAC &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 0, 0);
    } else {
        s1->base.seqFlags |= 0x800;
        s1->unk674 = 0.05f;
    }
}

/* sn-2.95.3-136 matched TU. */















#include "godhand/vu0.h"

__attribute__((section(".text.func_0025C5D8")))
void func_0025C5D8(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x3BFC) + p, *(int *)(p + 0x3C00) + p,
                      0, 0.0f, 0, 0);
        s0->timerA = 0x2A;
        s0->timerB = 1;
        s0->unk56E = 0x1E;
        (s0->step)++;
        s0->unk16EC = 0;
    }
        /* fallthrough */
    case 1:
        if ((s0->seqFlags & 8) == 0) {
            s0->emFlags |= 0x10000;
            s0->pos->y =
                s1->pos->y
                - (s0->scale.y - 1.0f) * 0.1f;
        }
        if (s0->unk56E != 0) {
            cVec *p;
            cVec *q;

            (s0->unk56E)--;
            p = s0->pos;

            q = &s1->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if ((s0->seqFlags & 2) != 0
            && s0->timerB != 0) {

            s0->timerB = 0;
            CEM00_VCALL(s0, hit, 0x64, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 10.0f);
        }
        if (moveMotion(s0) != 0) {
            if (s0->hp <= 0) {
                if ((s0->flags1644 & 0x800000) != 0) {
                    s0->mode = 2;
                    s0->phase = 3;
                    s0->step = 0;
                    s0->stepArg = 0;
                    return;
                } else {
                    func_0025FE30(a0, 0x1000000, 0);
                    s0->mode = 2;
                    s0->phase = 2;
                    s0->step = 0;
                    s0->stepArg = 0;
                }
            } else {
                func_00274FE8(s0);
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
    if ((s0->seqFlags & 1) != 0)
        func_00262750(s0, 0);
}
