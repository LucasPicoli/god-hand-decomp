/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"

extern void SetMotionStep(void *a0, float f12);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int moveMotion(void *a0);

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_0025C830")))
void func_0025C830(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1;
    float t;

    s1 = Getplayer();
    t = s1->speedRate;
    s0->speedRate = t;
    SetMotionStep(s0, t);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0: {
        int w;
        ReleaseField6ECByTag564_26B1E8(s0);
        w = EM_RES(s0);
        func_002A8578(s0, EM_RES_REC(w, 0x1820), EM_RES_REC(w, 0x1824),
                      0, 0.0f, 0, 0);
        s0->unk16EC = 0;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1: {
        cVec *q = &s1->vel;
        cVec *d = s0->pos;
        cVec *p;
        s0->hitFlash = 3.0f;
        s0->emFlags = s0->emFlags | 0x10000;
        d->y = s1->pos->y;
        p = s0->pos;
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(s0))
            s0->step = s0->step + 1;
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    case 2: {
        int w;
        ReleaseField6ECByTag564_26B1E8(s0);
        w = EM_RES(s0);
        func_002A8578(s0, EM_RES_REC(w, 0x1828), EM_RES_REC(w, 0x182C),
                      0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3: {
        cVec *q = &s1->vel;
        cVec *d = s0->pos;
        cVec *p;
        s0->hitFlash = 3.0f;
        s0->emFlags = s0->emFlags | 0x10000;
        d->y = s1->pos->y;
        p = s0->pos;
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(s0)) {
            CEM00_VCALL(s0, hit, 8, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        s0->step = s1->step;
        break;
    }
    case 4: {
        int w = EM_RES(s0);
        func_002A8578(s0, EM_RES_REC(w, 0x1838), EM_RES_REC(w, 0x183C),
                      0, 0.0f, 0, 0);
        s0->timerA = 1;
        s0->unk56E = 0xF;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 5: {
        cVec *d;
        s0->hitFlash = 3.0f;
        s0->emFlags = s0->emFlags | 0x10000;
        d = s0->pos;
        d->y = s1->pos->y;
        if (s0->unk56E != 0) {
            cVec *p;
            cVec *q;
            s0->unk56E = s0->unk56E - 1;
            p = s0->pos;
            q = &s1->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0)) {
            if (s0->hp <= 0) {
                func_0025FE30(a0, 0x1000000, 0);
                s0->mode = 2;
                s0->phase = 2;
                s0->step = 0;
                s0->stepArg = 0;
                break;
            }
            func_002705D8(s0);
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->seqFlags & 1) {
            if (s0->timerA != 0) {
                s0->timerA = 0;
                CEM00_VCALL(s0, hit, 0x14, s1, 1, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
            }
        }
        if (s0->seqFlags & 0x10) {
            if (s0->hp > 0) {
                s1->step = 6;
                s0->step = 6;
            }
        }
        break;
    }
    case 6: {
        int w = EM_RES(s0);
        func_002A8578(s0, EM_RES_REC(w, 0x1830), EM_RES_REC(w, 0x1834),
                      0, 0.0f, 0, 0);
        s0->unk56E = 0xF;
        s0->hitFlash = 15.0f;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 7:
        if (s0->unk56E != 0) {
            cVec *q = &s1->vel;
            cVec *p;
            s0->unk56E = s0->unk56E - 1;
            p = s0->pos;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0)) {
            if (s0->hp > 0) {
                func_002705D8(s0);
            } else {
                func_0025FE30(a0, 0x1000000, 0);
                s0->mode = 2;
                s0->phase = 2;
                s0->step = 0;
                s0->stepArg = 0;
                break;
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
