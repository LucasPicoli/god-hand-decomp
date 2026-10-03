/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002705D8(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_0026AB20(void *a0, int a1, int a2);
extern void func_00260B30(void *a0);

/* Phase machine on the step byte, 7 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, cCoreSave_getGameLevel, func_002A8578,
 * StoreMotionParamsBoth_2609A8, Getplayer and 11 more. */
__attribute__((section(".text.func_002349F8"))) void func_002349F8(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int r;
            int base;
            int p1;
            int p2;
            self->unk1864 = 0;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            base = self->resource;
            p1 = EM_RES_REC(base, 0x2030);
            p2 = EM_RES_REC(base, 0x2034);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                int b2 = self->resource;
                p2 = EM_RES_REC(b2, 0x2038);
            }
            func_002A8578(self, p1, p2, 0.0f, 0xA, r, 0);
            self->timerA = 0x1E;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0x12, 0x3A, 0, 0x112);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->timerA = (int)((float)self->timerA * 0.75f);
                    break;
                case 2:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 3:
                case 4:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 5:
                    break;
            }
            self->timerB = 1;
            self->timerC = 0;
            self->step++;
        }
        /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                int q;
                self->timerA = self->timerA - 1;
                q = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(q + 0xF0), self->speedRate * 0.19634954f);
            }
            if (moveMotion(self)) {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
                func_002705D8(self);
                return;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }

    if (self->moveFlags & 2) {
        if (self->timerB != 0) {
            self->timerB = 0;
            if (*(int *)((char *)self + 0x6EC) != 0) {
                ReleaseField6ECByTag564_26B1E8(self);
            } else {
                int h = func_0026AA30(self, 0x362);
                *(int *)((char *)self + 0x6EC) = h;
                func_0026AB20(self, h, 0x362);
            }
        }
    } else {
        self->timerB = 1;
    }
    self->moveFlags = self->moveFlags & 0xFFFD;
    func_00260B30(self);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(self) == 0 &&
        (self->moveFlags & 0x10) && self->unk1864 == 0 && func_00262AA8(self) != 0)
        return;
    if (self->moveFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFFU;
}
