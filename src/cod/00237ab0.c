/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern int moveMotion(void *a0);
extern void func_00274FE8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002376C0(void);
extern char D_00568288[];
extern int D_007474A8;

extern void cActionButton_set(void *a0, int a1, int a2,
                                                       int a3, void *t0, void *t1,
                                                       int t2);






__attribute__((section(".text.func_00237AB0")))
void func_00237AB0(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->emFlags |= 0x21000;
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0: {
        int w = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(w + 0x2118) + w, *(int *)(w + 0x211C) + w,
                      0, 0.0f, 0, 0);
        s0->unk568 = 0;
        s0->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            s0->unk56A = 0x39;
            break;
        case 2:
            s0->unk56A = 0x3E;
            break;
        case 3:
            s0->unk56A = 0x43;
            break;
        case 4:
            s0->unk56A = 0x43;
            break;
        case 5:
            s0->unk56A = 0x48;
            break;
        }
        s0->unk56C = irand() & 3;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
        if (moveMotion(s0)) {
            func_00274FE8(s0);
            return;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->unk56A != 0) {
            s0->unk56A = s0->unk56A - 1;
        } else if (s1->hp > 0 && s0->unk568 == 0) {
            switch (s0->unk56C) {
            default:
            case 0:
                if ((D_007474A8 & 0xD0) != 0)
                    s0->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           0, func_002376C0, s0, 0);
                break;
            case 1:
                if ((D_007474A8 & 0xE0) != 0)
                    s0->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           1, func_002376C0, s0, 0);
                break;
            case 2:
                if ((D_007474A8 & 0xB0) != 0)
                    s0->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           2, func_002376C0, s0, 0);
                break;
            case 3:
                if ((D_007474A8 & 0x70) != 0)
                    s0->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           3, func_002376C0, s0, 0);
                break;
            }
        }
        if (s0->seqFlags & 0x10) {
            s0->unk56A = 0x3E7;
            if (s0->unk568 == 0 || s1->hp <= 0) {
                s1->step = s1->step + 1;
                s0->step = s0->step + 1;
            }
        }
        if (s0->seqFlags & 1) {
            CEM00_VCALL(s0, hit, 0x32, 0, 0, 0);
            if (s0->hp <= 0)
                s0->hp = 1;
        }
        break;
    case 2: {
        int w = EM_RES(s0);
        s0->unk1864 = 0;
        func_002A8578(s0, *(int *)(w + 0x2120) + w, *(int *)(w + 0x2124) + w,
                      0, 0.0f, 0, 0);
        s0->unk56E = 0x3C;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0)) {
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
