/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void cSnd_DieDemoStart(void *a0);
extern void func_0012C348(void *a0, int a1);
extern int D_00747A24;
extern char D_005864F0[];
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/player.h"
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);
extern int irand(void);
extern void func_00129718(void *a0, void *a1, int a2);

/* sn-2.95.3-136 matched TU. */






















#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/pl00.h"

__attribute__((section(".text.func_00121E88")))
void func_00121E88(void *a0)
{
    pl00 *s1 = a0;
    cEm00 *s0;

    s1->base.hitFlash = 5.0f;
    s0 = s1->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(D_005864F0);
    s1->base.objFlags |= 0x10000;
    switch (s1->base.step) {
    case 0:
    {
        float buf[4];

        buf[0] = -0.416f;
        buf[1] = 0.0f;
        buf[2] = -0.4255f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s0, 0x32, 0.0f, 0.0f);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        s1->unk15B0 = 1;
        s1->base.unk56E = 0xF;
        (s1->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (s1->base.unk56E != 0 && s0 != 0) {
            cVec *p;
            cVec *q;

            (s1->base.unk56E)--;
            p = s1->base.pos;

            q = &s0->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (s1->base.hp > 0) {
                pl00_clearMotionCam(s1, 0, 0);
                s1->base.mode = 1;
                s1->base.phase = 4;
                s1->base.step = 0;
                s1->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if ((s1->base.seqFlags & 1) != 0
            && s1->unk15B0 != 0) {
            cCoreSave *s2 = &D_00569B70;

            s1->unk15B0 = 0;
            cCoreSave_addGameLevelPoint(s2, -0x140);
            if (s0 != 0)
                func_0012C0F8(s1, (int)(s0->unk76C * 30.0f));
            if (s1->base.hp <= 0) {
                cSnd *g = &D_005FEE00;

                s1->base.hp = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, a0, 0, 0, 0, 0);
                cSnd_DieDemoStart(g);
                cCoreSave_addGameLevelPoint(s2, -0x3E8);
                s1->base.motionFlags |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, a0, 0, 0, 0, 0);
            }
            func_0012C348(s1, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */






















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011C348")))
void func_0011C348(void *a0)
{
    pl00 *s1 = a0;
    cEm00 *s0;

    s1->base.hitFlash = 5.0f;
    s1->base.objFlags |= 0x10000;
    s0 = s1->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (s1->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.5068f;
        buf[2] = 0.1395f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 6, z, z);
        s1->unk15B0 = 1;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        s1->base.unk56E = 0xF;
        (s1->base.step)++;
    }
        /* fallthrough */
    case 1:
        if (s1->base.unk56E != 0 && s0 != 0) {
            cVec *p;
            cVec *q;

            (s1->base.unk56E)--;
            p = s1->base.pos;

            q = &s0->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (s1->base.hp > 0) {
                pl00_clearMotionCam(s1, 0, 0);
                s1->base.mode = 1;
                s1->base.phase = 4;
                s1->base.step = 0;
                s1->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if ((s1->base.seqFlags & 1) != 0
            && s1->unk15B0 != 0) {
            s1->unk15B0 = 0;
            if (s0->emNo != 0x23B) {
                if (s0 != 0)
                    func_0012C0F8(s1, (int)(s0->unk76C * 50.0f));
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            }
            if (s1->base.hp <= 0) {
                cSnd *g = &D_005FEE00;

                s1->base.hp = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, a0, 0, 0, 0, 0);
                cSnd_DieDemoStart(g);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                s1->base.motionFlags |= 8;
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, a0, 0, 0, 0, 0);
            }
            func_0012C348(s1, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

















#include "godhand/vu0.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_0025BCC0")))
void func_0025BCC0(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0:
    {
        short saved;
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        saved = s0->hp;
        CEM00_VCALL(s0, hit, 0x32, s1, 1, 0);
        if (s0->hp <= 0) {
            p = EM_RES(s0);
            func_002A8578(s0, *(int *)(p + 0x530) + p, *(int *)(p + 0x534) + p,
                          0, 0.0f, 0, 0);
            s0->unk568 = 1;
        } else {
            p = EM_RES(s0);
            func_002A8578(s0, *(int *)(p + 0x528) + p, *(int *)(p + 0x52C) + p,
                          0, 0.0f, 0, 0);
            s0->unk568 = 0;
        }
        s0->hp = saved;
        s0->timerA = 0x2A;
        s0->timerB = 1;
        s0->unk56E = 0x1E;
        s0->unk56A = 0xF;
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
            CEM00_VCALL(s0, hit, 0x32, s1, 1, 0);
            if (s0->unk568 != 0)
                s0->hp = 0;
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
        if (s0->unk56A != 0) {
            s0->unk56A = s0->unk56A - 1;
        } else {
            s0->unk56A = 0x3E7;
            if (s0->unk186B >= 5
                && s0->stepArg == 1
                && (irand() & 1) != 0) {
                unsigned char t = s0->stepArg;

                s0->mode = 0;
                s0->step = 0;
                s0->phase = 0x4D;
                s0->stepArg = t;
                func_00129718(s1, s0, 2);
            }
        }
        break;
    default:
        break;
    }
    if ((s0->seqFlags & 1) != 0)
        func_00262750(s0, 0);
}
