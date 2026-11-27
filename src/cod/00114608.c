/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"

extern unsigned char D_005864F0[];
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00124EC0(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern void func_0012CC70(void *a0);
extern void cEmManage_SetSpeedRate(void *a0, float f12);
extern void SetMotionStep(void *a0, float f12);
extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void FreeFieldObject_1267F8(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_00114608")))
void func_00114608(void *a0)
{
    cGameObj *s1 = a0;

    switch (s1->step) {
    case 0: {
        int s2;
        char *e;
        int p1;
        int p2;
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        func_00124540(s1, 3);
        if (*(int *)((char *)s1 + 0x640) != 0)
            func_00124EC0(s1);
        e = *(char **)((char *)s1 + 0x640);
        s2 = 0;
        if (e != 0) {
            char *vt = *(char **)(e + 0x214);
            char *p = *(char **)((char *)s1 + 0xF0);
            int off = *(short *)(vt + 0x68);
            int (*fp)() = *(int (**)())(vt + 0x6C);
            int r = fp(e + off);
            if (64.0f < capVu0MagnitudeSqXZ(p, (void *)r))
                s2 = 1;
        }
        if (s2 != 0) {
            int w1 = *(int *)((char *)s1 + 0x304);
            p1 = *(int *)(w1 + 0x228) + w1;
            p2 = *(int *)(w1 + 0x22C) + w1;
        } else {
            int w2 = *(int *)((char *)s1 + 0x304);
            p1 = *(int *)(w2 + 0x220) + w2;
            p2 = *(int *)(w2 + 0x224) + w2;
        }
        func_002A8578(s1, p1, p2, 3, 0.0f, 0, 0);
        *(int *)((char *)s1 + 0x15B0) = 0x66;
        *(int *)((char *)s1 + 0x15BC) = *(int *)((char *)s1 + 0x15B4) = 1;
        s1->unk568 = 5;
        *(int *)((char *)s1 + 0x15B8) = 0;
        *(int *)((char *)s1 + 0x165C) = 0;
        *(int *)((char *)s1 + 0x161C) = 0;
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 1:
        InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        if (*(int *)((char *)s1 + 0x640) != 0) {
            *(unsigned char *)((char *)s1 + 0x648) = 0x14;
            func_0012CC70(s1);
            *(int *)((char *)s1 + 0x15F4) = *(int *)((char *)s1 + 0x15F4) | 0x800000;
        }
        if (s1->seqFlags & 0x100) {
            if (*(int *)((char *)s1 + 0x15B4) != 0) {
                if (*(int *)((char *)s1 + 0x165C) == 0)
                    *(int *)((char *)s1 + 0x165C) = func_00125048(s1);
                if (*(int *)((char *)s1 + 0x15B0) != 0) {
                    *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) - 1;
                    if (*(int *)((char *)s1 + 0x161C) == 0)
                        *(int *)((char *)s1 + 0x161C) =
                            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 4, a0, 0, 0, 0, 0);
                    cEmManage_SetSpeedRate(&D_005864F0, 0.03f);
                    s1->speedRate = 0.03f;
                    SetMotionStep(s1, 0.03f);
                    {
                        cSnd *g = &D_005FEE00;
                        g->flagsB0 = g->flagsB0 | 0x400000;
                        g->flagsAC = g->flagsAC | 0x400000;
                    }
                    if (*(int *)((char *)s1 + 0x15BC) != 0) {
                        *(int *)((char *)s1 + 0x15BC) = 0;
                        if (*(int *)((char *)s1 + 0x15F4) & 0x20) {
                            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
                            default:
                            case 0:
                            case 2:
                            case 4:
                            case 6:
                                SetEffect(0, 0xE, a0, 0, -1, EFFECT_FOLLOW_OWNER);
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                break;
                            }
                        }
                    }
                }
            }
            if (s1->seqFlags & 0x100) {
                if (s1->unk568 != 0) {
                    s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
                } else if (*(signed char *)((char *)s1 + 0x626) != 0 &&
                           *(int *)((char *)s1 + 0x15B8) == 0) {
                    *(unsigned char *)((char *)s1 + 0x626) = 0;
                    *(unsigned char *)((char *)s1 + 0x621) = 0;
                    *(unsigned char *)((char *)s1 + 0x622) = 0;
                    *(unsigned char *)((char *)s1 + 0x623) = 0;
                    *(int *)((char *)s1 + 0x15B8) = 1;
                    func_00126770(s1);
                    pl00_clearMotionCam(s1, 1, 0);
                    s1->step = 2;
                }
            }
        }
        if (*(int *)((char *)s1 + 0x15B0) == 0 && *(int *)((char *)s1 + 0x15B8) == 0)
            FreeFieldObject_1267F8(s1);
        if (moveMotion(s1)) {
            pl00_clearMotionCam(s1, 1, 0);
            func_00126770(s1);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if (s1->seqFlags & 0x100) {
            *(short *)((char *)s1 + 0x3AC) = s1->seqFlags | 0x800;
            *(float *)((char *)s1 + 0x674) = 0.05f;
        }
        break;
    case 2: {
        int w = *(int *)((char *)s1 + 0x304);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        func_002A8578(s1, *(int *)(w + 0x220) + w, *(int *)(w + 0x224) + w,
                      0xA, 21.0f, 0, 0);
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s1)) {
            func_00126770(s1);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    default:
        break;
    }
    if (s1->seqFlags & 0x10)
        *(int *)((char *)s1 + 0x15F4) = *(int *)((char *)s1 + 0x15F4) | 0x400000;
    if (func_00123938(s1, 1)) {
        func_00126770(s1);
        pl00_clearMotionCam(s1, 1, 0);
    }
}
