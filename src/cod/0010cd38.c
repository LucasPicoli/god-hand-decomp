/* sn-2.95.3-136: func_0010CD38, the player's thrown-down step. */

#include "godhand/cEm00.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern void cSnd_SeStop(cSnd *self, int handle);
extern int func_00124540(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(char *a0, float f12);
extern void Obj0000_Clear_Fields_640_648_124E58(char *a0);
extern void func_001268F0(int *p);
extern int func_00123938(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);

/* Thrown-down step of the player (a state of the pl00 table D_003BD0F0): on entry award the level points for a 0x200 actor held at
 * 0x640, stop the sound and start the knockdown motion and effect picked by stepArg;
 * then run the motion at the stepScale speed until it ends. */
__attribute__((section(".text.func_0010CD38")))
void func_0010CD38(pl00 *self)
{
    int p1;
    int p2;

    switch (self->base.step) {
    case 0:
        if (self->base.stepArg != 0 && self->held != 0) {
            if (cGameObj_idInRange(self->held, 0x200, 0x300) & 0xFF) {
                cCoreSave_addGameLevelPoint(&D_00569B70, 8);
            }
        }
        self->comboSlot = 0;
        self->comboSet = 0;
        func_001268F0((int *)self);
        self->stepScale = 1.0f;
        cSnd_SeStop(&D_005FEE00, self->unk1620);
        self->unk1620 = 0;
        self->base.unk568 = 0;
        switch (self->base.stepArg) {
        case 0:
        default:
            Obj0000_Clear_Fields_640_648_124E58((char *)self);
            p1 = EM_RES_REC(EM_RES(&self->base), 0x48);
            p2 = EM_RES_REC(EM_RES(&self->base), 0x4C);
            SetEffect(0, 0x17, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2A, (cObj *)self, 0, 0, 0, 0);
            self->base.unk568 = 0xC;
            break;
        case 1:
            self->base.hitFlash = 12.0f;
            Obj0000_Clear_Fields_640_648_124E58((char *)self);
            p1 = EM_RES_REC(EM_RES(&self->base), 0x50);
            p2 = EM_RES_REC(EM_RES(&self->base), 0x54);
            SetEffect(0, 0x18, self, 0, -1, 0xFFFFFFFF);
            break;
        case 2:
            self->base.hitFlash = 5.0f;
            func_00124540(self, 5);
            p1 = EM_RES_REC(EM_RES(&self->base), 0x40);
            p2 = EM_RES_REC(EM_RES(&self->base), 0x44);
            SetEffect(0, 0x16, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2A, (cObj *)self, 0, 0, 0, 0);
            self->stepScale = 1.2f;
            break;
        case 3:
            self->base.hitFlash = 5.0f;
            func_00124540(self, 5);
            p1 = EM_RES_REC(EM_RES(&self->base), 0x38);
            p2 = EM_RES_REC(EM_RES(&self->base), 0x3C);
            SetEffect(0, 0x15, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2A, (cObj *)self, 0, 0, 0, 0);
            self->stepScale = 1.2f;
            break;
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.step += 1;
    case 1:
        if (self->held != 0) {
            self->unk648 = 0x14;
        }
        if (self->base.stepArg == 0) {
            self->unk15F4 |= 0x4000;
        }
        switch (self->base.stepArg) {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            if (self->held == 0) {
                func_00124540(self, 5);
            }
            break;
        }
        if (self->base.unk568 > 0) {
            self->base.unk568 -= 1;
            if (self->unk61F != 0) {
                self->unk15F4 |= 0x8000;
            }
        }
        InvokeVirtualAtField214AndForward_124E68((char *)self, 0.19634954f);
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        self->base.nullSpeed.x *= self->stepScale;
        self->base.nullSpeed.z *= self->stepScale;
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    func_00123938(self, 1);
}
