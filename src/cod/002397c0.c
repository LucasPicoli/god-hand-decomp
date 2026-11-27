/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void func_002DB770(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"














__attribute__((section(".text.func_002397C0")))
void func_002397C0(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0: {
        int w = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(w + 0x3C44) + w, *(int *)(w + 0x3C48) + w,
                      0, 0.0f, 0, 0);
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
        s0->unk56A = 4;
        s0->unk56E = 0xF;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
        if (s0->unk56E != 0) {
            cVec *q = &s1->vel;
            cVec *p;
            s0->unk56E = s0->unk56E - 1;
            p = s0->pos;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        s0->hitFlash = 3.0f;
        if (moveMotion(s0))
            s0->step = s0->step + 1;
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 2: {
        int w = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(w + 0x3C4C) + w, *(int *)(w + 0x3C50) + w,
                      0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
    {
        char *g;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0)
            s0->unk568 = s0->unk568 - 1;
        if (*(int *)(g + 8) & 0xF00000)
            s0->unk568 = s0->unk568 - 4;
    }
        s0->hitFlash = 3.0f;
        if (moveMotion(s0)) {
            if (s0->unk568 <= 0) {
                s0->step = 6;
                s1->step = 6;
            }
            if (--s0->unk56A <= 0) {
                s0->step = 4;
                s1->step = 4;
            }
            if (s1->hp <= 0) {
                s0->step = 4;
                s1->step = 4;
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 4: {
        int w = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(w + 0x3C54) + w, *(int *)(w + 0x3C58) + w,
                      3, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 5:
        s0->hitFlash = 3.0f;
        if (moveMotion(s0)) {
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 6: {
        int w = EM_RES(s0);
        func_002A8578(s0, *(int *)(w + 0x3C5C) + w, *(int *)(w + 0x3C60) + w,
                      3, 0.0f, 0, 0);
        s0->timerA = 1;
        s0->hitFlash = 5.0f;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 7:
        if (moveMotion(s0))
            func_002705D8(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->seqFlags & 1) {
            if (s0->timerA != 0) {
                s0->timerA = 0;
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
