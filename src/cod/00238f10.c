/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern void KillEffect(void *a0, int a1, int a2);
extern char D_007474A0[];

__attribute__((section(".text.func_00238F10")))
void func_00238F10(void *a0)
{
    int one = 1;
    cEm00 *s0 = a0;
    cGameObj *s2 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0: {
        int p = EM_RES(s0);

        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(p + 0x39DC) + p, *(int *)(p + 0x39E0) + p,
                      0, 0.0f, 0, 0);
        s0->unk56E = 0xF;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            s0->unk568 = 0xF;
            break;
        case 2:
            s0->unk568 = 0x14;
            break;
        case 3:
        case 4:
            s0->unk568 = 0x19;
            break;
        case 5:
            s0->unk568 = 0x1E;
            break;
        }
        s0->unk56A = 0;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
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
                s2->step = 2;
                s0->step = 2;
            }
            s0->unk56A = 0x3E7;
        }
        break;
    case 2: {
        int p = EM_RES(s0);

        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(p + 0x39E4) + p, *(int *)(p + 0x39E8) + p,
                      0, 0.0f, 0, 0);
        s0->emFlags2 &= 0xDFFFFFFFU;
        KillEffect(s0, 1, 2);
        s0->unk568 = one;
        s0->unk56E = 0xF;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0) {
            if (s0->hp < 2) {
                s0->mode = 2;
                s0->hp = 0;
                s0->phase = 0;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            func_002705D8(s0);
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->seqFlags & 1) {
            if (s0->unk568 != 0) {
                CEM00_VCALL(s0, hit, 0x32, 0, 0, 0);
                if (s0->hp <= 0)
                    s0->hp = 1;
                s0->unk568 = 0;
            }
        } else {
            s0->unk568 = 1;
        }
        break;
    default:
        break;
    }
}
