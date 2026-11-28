/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern void SetMotionStep(void *a0, float f12);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);

#include "godhand/cCollisionSolid.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"

/* Held-by-player phase of an enemy, stepped on its 0x2F6 sub-phase (0 to 5).
 * The enemy copies the player's motion step, plays three motion pairs from
 * its motion table (0x39A0, 0x39A8, 0x39B0) and rides the player's position
 * delta at 0x550; the last phase spawns effect 0x4F on a part, fires the
 * vtable hit at 0xA8 with damage 20 * the charge at 0x600, adds heat and
 * hands control back with phase 1/4/2. */
__attribute__((section(".text.cEm_heldByPlayerPhase")))
void cEm_heldByPlayerPhase(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s2;
    unsigned char frame[0x10];
    cVec buf;
    void *m1;
    cVec *m2;

    s2 = Getplayer();
    {
        float v = s2->speedRate;

        s0->speedRate = v;
        SetMotionStep(s0, v);
    }
    s0->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x39A0) + p, *(int *)(p + 0x39A4) + p,
                      0, 0.0f, 0, 0);
        if (s0->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(s0->unk744, 0x19);
        }
        s0->unk16EC = 0;
        s0->unk56A = 0;
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
    {
        cVec *q;
        cVec *p;

        q = &s2->vel;
        p = s0->pos;
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, q, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
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
        float z = 0.0f;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x39A8) + p, *(int *)(p + 0x39AC) + p,
                      0, z, 0, 0);
        if (s0->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(s0->unk744, 0x1A);
        }
        s0->timerA = 1;
        s0->timer = z;
        (s0->step)++;
    }
        /* fallthrough */
    case 3:
    {
        cVec *p;
        cVec *q;

        p = s0->pos;
        q = &s2->vel;
        VU0_VADD_XYZ_IP(p, 0, q);
    }
        if (moveMotion(s0) != 0) {
            s0->timer = s0->timer + 1.0f;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        s0->step = s2->step;
        break;
    case 4:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x39B0) + p, *(int *)(p + 0x39B4) + p,
                      0, 0.0f, 0, 0);
        if (s0->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(s0->unk744, 0x1B);
        }
        s0->timerA = 1;
        s0->unk56E = 0xF;
        (s0->step)++;
    }
        /* fallthrough */
    case 5:
        if (s0->unk56E != 0) {
            cVec *p;
            cVec *q;

            (s0->unk56E)--;
            p = s0->pos;
            q = &s2->vel;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0) != 0) {
            unsigned char ok;
            int cnt;
            int idx = 4;
            cGameObj *s1;

            ok = ((*(int *)frame = cnt = s0->partNum),
                  (idx < cnt));
            if (ok) s1 = (cGameObj *)s0->children[idx];
            else s1 = 0;
            if (s1 != 0) {
                VU0_SQC2_VF0(frame, 0x10);
                buf.x = fRand1_1() * 0.1f;
                buf.y = fRand1_1() * 0.1f + 0.1f;
                buf.z = fRand0_1() * 0.1f + 0.2f;
                /* One pointer local per call, cleared after it: retail recomputes
                 * $sp+0x10 at each call instead of holding it in a saved register. */
                m1 = &buf;
                sceVu0ApplyMatrix(m1, s1->mtx, m1);
                m1 = 0;
                m2 = &buf;
                SetEffectPos(0, 0x4F, 0, m2, 1.0f, -1);
                m2 = 0;
            }
            CEM00_VCALL(s0, hit, (int)(s0->timer * 20.0f), s2, 0, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, s0->timer);
            s0->mode = 1;
            s0->phase = 4;
            s0->stepArg = 2;
            s0->step = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
