/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(char *a0);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void MtxInitRotY(void *a0, float angle);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void cOmWeapon_resetHold(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void func_00124EC0(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012A8D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int func_00123938(void *a0, int a1);
extern char D_005864F0[];

/* SN ProDG ee-gcc 2.95.3 matched TU — func_00115030.
 *
 * Per-frame update for the "state 0x2F6" actor phase.  Same family as the
 * already-matched UpdateAttackState2F6_1161E0 (src/cod/001161e0.c) and
 * UpdateStatePhase2F6_10CC58 (src/cod/0010cc58.c): a 5.0f cooldown store,
 * a two-case switch on the phase byte at +0x2F6, then the common
 * moveMotion/AddScaled.../func_00123938 tail.
 *
 * Phase 0 additionally binds the "carried object" slot (+0x69C -> +0x698),
 * pushes it one unit along the actor's -Z axis rotated by the actor's Y
 * heading (+0x104), and copies the actor's world position (+0xF0 vector)
 * and heading (+0x100) onto it.
 */

#include "godhand/vu0.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"





















__attribute__((section(".text.func_00115030")))
void func_00115030(void *a0) {
    pl00 *s1 = a0;
    float mv[20]; /* mv[0..15]: rotation matrix; mv[16..19]: direction vector */
    cVec *d;
    cVec *s;
    cVec *d2;
    cVec *s2;
    cGameObj *o;
    int t;
    int tt;
    int p1;
    int p2;

    s1->base.hitFlash = 5.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    switch (s1->base.step) {
    case 0:
        s1->comboSlot = 0;
        s1->comboSet = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        t = (int)s1->base.pack;
        p1 = *(int *)(t + 0x8C8) + t;
        p2 = *(int *)(t + 0x8CC) + t;
        o = s1->unk69C;
        s1->sub698 = o;
        if (o != 0) {
            VU0_SQC2_VF0(mv, 0x40);
            MtxInitRotY(mv, s1->base.rot.y);
            mv[16] = 0.0f;
            mv[17] = 0.0f;
            mv[18] = -1.0f;
            sceVu0ApplyMatrix(&mv[16], mv, &mv[16]);
            s1->base.pos->x = s1->sub698->pos->x + mv[16];
            s1->base.pos->z = s1->sub698->pos->z + mv[18];
            cOmWeapon_resetHold(s1->sub698);
            d = s1->sub698->pos;
            s = s1->base.pos;
            if (d != s) {
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
            d = &s1->sub698->rot;
            s = &s1->base.rot;
            if (d != s) {
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
            tt = (int)s1->base.pack;
            func_002A8578(s1->sub698, *(int *)(tt + 0x900) + tt, 0, 0, 0.0f, 0, 0);
        }
        func_002A8578(s1, p1, p2, 0, 0.0f, 0, 0);
        s1->base.step = s1->base.step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (s1->sub698 != 0) {
            d2 = s1->sub698->pos;
            s2 = s1->base.pos;
            if (d2 != s2) {
                d2->x = s2->x;
                d2->y = s2->y;
                d2->z = s2->z;
            }
            d = &s1->sub698->rot;
            s = &s1->base.rot;
            if (d != s) {
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
        }
        InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 0, 0);
            func_0012A8D8(s1);
            s1->base.mode = 0;
            s1->base.phase = 0;
            s1->base.step = 0;
            s1->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    if (func_00123938(s1, 1) != 0) {
        pl00_clearMotionCam(s1, 0, 0);
        func_0012A8D8(s1);
    }
}
