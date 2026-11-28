/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void SetMotionStep(void *a0, float f12);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"

__attribute__((section(".text.func_0025CCC0")))
void func_0025CCC0(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1;
    float v;
    float t;

    s1 = Getplayer();
    v = s1->speedRate;
    s0->speedRate = v;
    SetMotionStep(s0, v);
    s0->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);

    t = s0->unk770;
    if (t > 0.0f) {
        if (t < 10.0f) {
            s0->unk770 = 10.0f;
        }
    }

    switch (s0->step) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x14C0) + p, *(int *)(p + 0x14C4) + p,
                      0, 0.0f, 0, 0);
        s0->unk16EC = 0;
        s0->timerA = 1;
        (s0->step)++;
        s0->timerB = 1;
    }
        /* fallthrough */
    case 1:
    {
        cVec *q;
        cVec *pa;
        cVec *pb;
        cVec *p0;

        s0->emFlags |= 0x10000;
        q = &s1->vel;
        pa = s1->pos;
        pb = s0->pos;
        pb->y = pa->y - (s0->scale.y - 1.0f) * 0.1f;
        p0 = s0->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
        if (moveMotion(s0) != 0) {
            (s0->step)++;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    case 2:
    {
        int p;

        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x14C8) + p, *(int *)(p + 0x14CC) + p,
                      0, 0.0f, 0, 0);
        (s0->step)++;
    }
        /* fallthrough */
    case 3:
    {
        cVec *q;
        cVec *pa;
        cVec *pb;
        cVec *p0;

        s0->emFlags |= 0x10000;
        q = &s1->vel;
        pa = s1->pos;
        pb = s0->pos;
        pb->y = pa->y - (s0->scale.y - 1.0f) * 0.1f;
        p0 = s0->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        s0->step = s1->step;
        break;
    }
    case 4:
    {
        int p;

        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x14D0) + p, *(int *)(p + 0x14D4) + p,
                      0, 0.0f, 0, 0);
        (s0->step)++;
    }
        /* fallthrough */
    case 5:
    {
        cVec *pa;
        cVec *pb;

        s0->emFlags |= 0x10000;
        pa = s1->pos;
        pb = s0->pos;
        pb->y = pa->y - (s0->scale.y - 1.0f) * 0.1f;
        if (moveMotion(s0) != 0) {
            s0->mode = 1;
            s0->phase = 0x23;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    default:
        break;
    }

    if (s0->seqFlags & 1) {
        if (s0->timerA != 0) {
            s0->timerA = 0;
            CEM00_VCALL(s0, hit, 6, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
        }
    } else {
        s0->timerA = 1;
    }

    if ((s0->seqFlags & 2) && s0->timerB != 0) {
        s0->timerB = 0;
        CEM00_VCALL(s0, hit, 0x14, s1, 1, 0);
        cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
    } else {
        s0->timerB = 1;
    }
}
