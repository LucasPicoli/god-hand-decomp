/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern char D_007474A0[];

__attribute__((section(".text.func_00237078")))
void func_00237078(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();
    cVec *p;
    cVec *q;

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0: {
        int p = EM_RES(s0);
        int t;

        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(p + 0x240C) + p, *(int *)(p + 0x2410) + p,
                      0, 0.0f, 0, 0);
        s0->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            t = 0xF;
            break;
        case 2:
            t = 0x14;
            break;
        case 3:
        case 4:
            t = 0x19;
            break;
        case 5:
            t = 0x1E;
            break;
        }
        s0->unk568 = t;
        if (s1->hp < 2)
            s0->unk568 = 0x3C;
        s0->unk56A = 0x14;
        s0->step = s0->step + 1;
    }
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
        if (s0->unk56A != 0) {
            (s0->unk56A)--;
        } else {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if (*(int *)(g + 8) & 0xF0)
                (s0->unk568)--;
            if (*(int *)(g + 8) & 0xF00000)
                s0->unk568 -= 4;
        }
        if (s0->seqFlags & 0x10) {
            if (s0->unk568 <= 0) {
                s1->step = 2;
                s0->step = 2;
            }
            s0->unk56A = 0x3E7;
        }
        break;
    case 2: {
        int p = EM_RES(s0);

        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(p + 0x2420) + p, *(int *)(p + 0x2424) + p,
                      0, 0.0f, 0, 0);
        s0->unk56E = 0xF;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
        if (s0->unk56E != 0) {
            cVec *q;
            cVec *p0;

            (s0->unk56E)--;
            q = &s1->vel;
            p0 = s0->pos;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (moveMotion(s0) != 0)
            func_002705D8(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->seqFlags & 1) {
            CEM00_VCALL(s0, hit, 0x14, 0, 0, 0);
            if (s0->hp <= 0)
                s0->hp = 1;
        }
        break;
    default:
        break;
    }
}
