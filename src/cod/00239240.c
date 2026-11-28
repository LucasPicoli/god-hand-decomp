/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */














#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

__attribute__((section(".text.func_00239240")))
void func_00239240(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();

    switch (s0->step) {
    case 0:
    {
        int p;

        s0->unk1864 = 0;
        p = EM_RES(s0);
        func_002A8578(s0, *(int *)(p + 0x3BD8) + p, *(int *)(p + 0x3BDC) + p,
                      0, 0.0f, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: s0->unk568 = 0xF; break;
        case 2: s0->unk568 = 0x14; break;
        case 3: case 4: s0->unk568 = 0x19; break;
        case 5: s0->unk568 = 0x1E; break;
        }
        s0->unk56A = 0x1E;
        s0->unk56E = 0xF;
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
        cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
        if (s0->unk56E != 0) {
            cVec *q;
            cVec *p0;

            (s0->unk56E)--;
            p0 = s0->pos;

            q = &s1->vel;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        s0->hitFlash = 3.0f;
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->unk56A > 0) {
            s0->unk56A = s0->unk56A - 1;
            func_002DB770();
            {
                char *g = D_007474A0;
                if ((*(int *)(g + 8) & 0xF0) != 0)
                    s0->unk568 = s0->unk568 - 1;
                if ((*(int *)(g + 8) & 0xF00000) != 0)
                    s0->unk568 = s0->unk568 - 4;
            }
        } else if (s0->unk568 <= 0) {
            int k = 2;

            do {
                s0->step = k;
                s1->step = k;
            } while (0);
        }
        break;
    case 2:
    {
        int p;
        int one = 1;

        p = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(p + 0x3BE0) + p, *(int *)(p + 0x3BE4) + p,
                      3, 0.0f, 0, 0);
        s0->timerA = one;
        s0->hitFlash = 15.0f;
        s0->unk568 = 0x28;
        (s0->step)++;
    }
        /* fallthrough */
    case 3:
        if (s0->unk568 != 0) {
            s0->unk568 = s0->unk568 - 1;
            cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            break;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((s0->seqFlags & 0x1) != 0) {
            if (s0->timerA != 0) {
                CEM00_VCALL(s0, hit, 0xA, s1, 1, 0);
                if (s0->hp <= 0)
                    s0->hp = 1;
            }
        }
        break;
    default:
        break;
    }
}
