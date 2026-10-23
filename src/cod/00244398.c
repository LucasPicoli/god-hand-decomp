/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/sceVu0.h"

extern void cCollisionSolidManage_SetActive(int a0, int a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12);
extern void KillEffect(int a0, int a1, int a2);
extern void func_00262750(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void func_001D0108(cOmWeapon *self);
extern char D_00462FC0;

/* Down step: start the down motion, kill the effects, then settle onto the
 * ground below; on landing take a 50 hit and move to phase 8. */
__attribute__((section(".text.func_00244398")))
void func_00244398(cEm00 *self)
{
    cVec from;
    cVec to;
    cVec hit;
    int landed;
    int motion;

    cCollisionSolidManage_SetActive((int)&D_00462FC0, (int)self, 0);
    self->emFlags |= 0x10000;
    switch (self->step) {
    case 0:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x246C),
                      EM_RES_REC(self->resource, 0x2470), 3, motion, 0, 0.0f);
        self->unk1730 = 600.0f;
        KillEffect((int)self, 1, 2);
        self->emFlags2 &= 0xFFFFFFDF;
        self->step++;
    case 1:
        self->emFlags |= 0x1000;
        func_00262750(self, 2);
        self->emFlags |= 0x10000;
        if (moveMotion(self) != 0) {
            self->vital = 0;
            self->mode = 2;
            self->phase = 2;
            self->step = 0;
            self->stepArg = 1;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        cVec_zero(&from);
        cVec_zero(&to);
        cVec_zero(&hit);
        cVec_copy3(&from, &self->posA);
        cVec_copy3(&to, self->pos);
        from.y += 0.5f;
        landed = ChkLine(&from, &to, &hit, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1);
        if (landed == 1) {
            self->pos->y = hit.y;
            CEM00_VCALL(self, hit, 0x32, 0, 0, 0);
            self->mode = 1;
            self->phase = 8;
            self->step = 2;
            self->stepArg = 0;
        }
        if (self->moveFlags & 1) {
            if (self->unk730 != 0) {
                func_001D0108((cOmWeapon *)self->unk730);
                self->unk730 = 0;
            }
        }
        break;
    }
}
