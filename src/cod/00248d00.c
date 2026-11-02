/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"

extern void MtxInitRotY(void *a0, float angle);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern int Rnd(void);
extern int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12);
extern void cGameObj_SetTgtTurn(char *self, void *target, float rate);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);

/* Attack step: on entry a wall within 8 ahead, or one roll in four, picks the
 * second motion; then turn toward the player until the motion ends. */
__attribute__((section(".text.func_00248D00")))
void func_00248D00(cEm00 *self)
{
    float mtx[16];
    cVec from;
    cVec to;
    int motion;
    int p1;
    int p2;

    self->objFlags |= 0x40000;
    if (self->step == 0) {
        cVec_zero(&from);
        cVec_zero(&to);
        MtxInitRotY(mtx, self->rot.y);
        CopyVec3ToField30_147C40(mtx, (float *)self->pos);
        from.x = 0.0f;
        from.y = 0.5f;
        from.z = 0.0f;
        to.x = 0.0f;
        to.y = 0.5f;
        to.z = -8.0f;
        cVec_applyMatrix(&from, mtx);
        cVec_applyMatrix(&to, mtx);
        if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1)
            self->stepArg = 1;
        if ((Rnd() & 3) == 0)
            self->stepArg = 1;
    }
    switch (self->step) {
    case 0:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        if (self->stepArg != 0) {
            p1 = EM_RES_REC(self->resource, 0x38E0);
            p2 = EM_RES_REC(self->resource, 0x38E4);
        } else {
            p1 = EM_RES_REC(self->resource, 0x38C8);
            p2 = EM_RES_REC(self->resource, 0x38CC);
        }
        func_002A8578((int)self, p1, p2, 10, motion, 0, 0.0f);
        self->step++;
    case 1:
        self->emFlags |= 0x800000;
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        if (moveMotion(self) != 0) {
            if (16.0f < self->playerDist && self->playerDist < 144.0f) {
                if (irand() & 1) {
                    self->mode = 0;
                    self->phase = 0x17;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    self->mode = 0;
                    self->phase = 0x31;
                    self->step = 0;
                    self->stepArg = 0;
                }
                cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
                cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
                break;
            }
            if (func_00262AA8(self) != 0)
                break;
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->moveFlags & 1) {
            self->unk617 = 1;
            self->hitFlash = 3.0f;
        }
        if (self->moveFlags & 0x10) {
            if (cCoreSave_getGameLevel(&D_00569B70) >= 3)
                func_00262AA8(self);
        }
        break;
    }
}
