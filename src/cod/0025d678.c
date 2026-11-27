/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void SetMotionStep(void *a0, float f);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/effectPos.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"












__attribute__((section(".text.func_0025D678")))
void func_0025D678(void *a0)
{
    struct {
        int childCount;     /* 0x00 the child count, stored on the way */
        char unk04[0xC];
        cVec pos;           /* 0x10 the effect position */
    } f __attribute__((aligned(16)));
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();
    float t;

    t = s1->speedRate;
    s0->speedRate = t;
    SetMotionStep(s0, t);
    s0->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);

    switch (s0->step) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x31E4) + p, *(int *)(p + 0x31E8) + p,
                      0, 0.0f, 0, 0);
        s0->unk16EC = 0;
        s0->unk56A = 0;
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
    {
        cVec *q;
        cVec *p0;

        q = &s1->vel;
        p0 = s0->pos;
        VU0_VADD_XYZ_IP(p0, 0, q);
    }
        if (moveMotion(s0) != 0) {
            (s0->step)++;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 2:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x31EC) + p, *(int *)(p + 0x31F0) + p,
                      0, 0.0f, 0, 0);
        s0->timerA = 1;
        (s0->step)++;
    }
        /* fallthrough */
    case 3:
    {
        cVec *q;
        cVec *p0;

        p0 = s0->pos;
        q = &s1->vel;
        VU0_VADD_XYZ_IP(p0, 0, q);
    }
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->seqFlags & 1) {
            if (s0->timerA != 0) {

                s0->timerA = 0;
                CEM00_VCALL(s0, hit, 0xA, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
        } else {
            s0->timerA = 1;
        }
        s0->step = s1->step;
        break;
    case 4:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x31F4) + p, *(int *)(p + 0x31F8) + p,
                      0, 0.0f, 0, 0);
        s0->timerA = 1;
        s0->unk56E = 0xF;
        (s0->step)++;
    }
        /* fallthrough */
    case 5:
        if (s0->unk56E != 0) {
            cVec *q;
            cVec *p0;

            (s0->unk56E)--;
            p0 = s0->pos;
            q = &s1->vel;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (s0->seqFlags & 2) {
            if (s0->timerA != 0) {

                s0->timerA = 0;
                CEM00_VCALL(s0, hit, 0x1E, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
                if (s0->hp < 2) {
                    s0->hp = 1;
                }
            }
        }
        if (moveMotion(s0) != 0) {
            if (s0->hp < 2) {
                s0->hp = 1;
            }
            func_002705D8(s0);
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 6:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x31FC) + p, *(int *)(p + 0x3200) + p,
                      0, 0.0f, 0, 0);
        s0->timerA = 1;
        s0->unk56E = 0xF;
        (s0->step)++;
    }
        /* fallthrough */
    case 7:
        if (s0->unk56E != 0) {
            cVec *q;
            cVec *p0;

            (s0->unk56E)--;
            q = &s1->vel;
            p0 = s0->pos;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (s0->seqFlags & 2) {
            if (s0->timerA != 0) {
                s0->timerA = 0;
                s0->hp = 0;
            }
        }
        if (moveMotion(s0) != 0) {
            s0->hp = 0;
            s0->mode = 2;
            s0->phase = 2;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }

    if (s0->seqFlags & 3) {
        if (s0->unk56A != 0) {
            int n;
            int ok;
            int idx = 4;

            ok = ((f.childCount = n = s0->partNum), (idx < n));
            if (ok) {
                s1 = (cGameObj *)s0->children[4];
            } else {
                s1 = 0;
            }
            if (s1 != 0) {
                VU0_SQC2_VF0(&f, 0x10);
                f.pos.x = fRand1_1() * 0.1f;
                f.pos.y = fRand1_1() * 0.1f + 0.1f;
                f.pos.z = fRand0_1() * 0.1f + 0.2f;
                { float *e = &f.pos.x; sceVu0ApplyMatrix(e, s1->mtx, e); e = 0; }
                SetEffectPos(0, 0x4F, 0, &f.pos, 1.0f, -1);
            }
        }
        s0->unk56A = 0;
    } else {
        s0->unk56A = 1;
    }
}
