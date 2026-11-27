/* sn-2.95.3-136 matched TU. */

/* func_002373B0, 784 B, sn-2.95.3-136. Wave 2026-08-30 VU0P parked + nested Duff do{}while(0) before case 1 (label 0x002374E0, 0 mod 8; dispatch beq slot filled from before so no beql), case 3 store order 2F4 2F5 2F6 2F7. */
/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

__attribute__((section(".text.func_002373B0")))
void func_002373B0(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();
    cVec *p;
    cVec *q;
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0:
        s0->unk1864 = 0;
        b = EM_RES(s0);
        func_002A8578(s0, *(int *)(b + 0x20D8) + b, *(int *)(b + 0x20DC) + b,
                      0, 0.0f, 0, 0);
        s0->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: s0->unk568 = 0xF; break;
        case 2: s0->unk568 = 0x14; break;
        case 3: case 4: s0->unk568 = 0x19; break;
        case 5: s0->unk568 = 0x1E; break;
        }
        if (s1->hp < 2)
            s0->unk568 = 0x19;
        s0->unk56A = 0x5A;
        (s0->step)++;
        /* fallthrough */
    
    
    case 1:
        if (s0->unk56E == 0)
            goto join;
        (s0->unk56E)--;
        p = s0->pos;

        q = &s1->vel;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s1->hp > 0) {
            if (s0->unk56A != 0) {
                s0->unk56A = s0->unk56A - 1;
            } else {
                func_002DB770();
                {
                    char *g = D_007474A0;
                    if ((*(int *)(g + 8) & 0xF0) != 0)
                        s0->unk568 = s0->unk568 - 1;
                    if ((*(int *)(g + 8) & 0xF00000) != 0)
                        s0->unk568 = s0->unk568 - 4;
                }
            }
            if ((s0->seqFlags & 0x10) != 0) {
                if (s1->hp > 0 && s0->unk568 <= 0) {
                    (s1->step)++;
                    (s0->step)++;
                }
                s0->unk56A = 0x3E7;
            }
        }
        break;
    case 2:
    {
        int k = 3;
        s0->step = k;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((s0->seqFlags & 0x1) != 0) {
            CEM00_VCALL(s0, hit, 0x32, 0, 0, 0);
            if (s0->hp <= 0)
                s0->hp = 1;
            s0->mode = 1;
            s0->phase = 0x15;
            s0->step = 0;
            s0->stepArg = 0;
        }
        break;
    default:
        break;
    }
}
