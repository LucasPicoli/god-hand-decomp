/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* Phase machine on the step byte, 14 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, StoreMotionParamsBoth_2609A8, cCoreSave_getGameLevel,
 * func_002A8578, Getplayer and 6 more. */
__attribute__((section(".text.func_00228E18"))) void func_00228E18(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            cCoreSave *sv;
            int r;
            int w;
            int p1;
            int p2;
            self->unk1864 = 0;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x37, -1, 0);
            w = self->resource;
            sv = &D_00569B70;
            p1 = EM_RES_REC(w, 0x254C);
            p2 = EM_RES_REC(w, 0x2550);
            if (cCoreSave_getGameLevel(sv) == 5) {
                int w2 = self->resource;
                p2 = EM_RES_REC(w2, 0x2554);
            }
            func_002A8578(self, p1, p2, 0.0f, 3, r, 0);
            self->timerA = 0x1E;
            switch (cCoreSave_getGameLevel(sv) - 1) {
                default:
                case 0:
                    self->timerA = (int)((float)self->timerA * 0.75f);
                    break;
                case 1:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 2:
                case 3:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 4:
                    break;
            }
            self->timerC = 0;
            self->step++;
        }
        /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                char *p;
                self->timerA = self->timerA - 1;
                p = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(p + 0xF0), self->speedRate * 0.19634954f);
            }
            if (moveMotion(self))
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->moveFlags & 0x10) && self->playerDist < 5.29f)
                self->step++;
            break;
        case 2: {
            cCoreSave *sv;
            int r;
            int w;
            int p1;
            int p2;
            self->unk1864 = 0;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 3, 0x37, -1, 0);
            w = self->resource;
            sv = &D_00569B70;
            p1 = EM_RES_REC(w, 0x2558);
            p2 = EM_RES_REC(w, 0x255C);
            if (cCoreSave_getGameLevel(sv) == 5) {
                int w2 = self->resource;
                p2 = EM_RES_REC(w2, 0x2560);
            }
            func_002A8578(self, p1, p2, 0.0f, 1, r, 0);
            self->timerA = 0x14;
            switch (cCoreSave_getGameLevel(sv) - 1) {
                default:
                case 0:
                    self->timerA = (int)((float)self->timerA * 0.75f);
                    break;
                case 1:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 2:
                case 3:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 4:
                    break;
            }
            self->step++;
        }
        /* fallthrough */
        case 3:
            if (self->timerA != 0) {
                char *p;
                self->timerA = self->timerA - 1;
                p = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(p + 0xF0), self->speedRate * 0.19634954f);
            }
            if (moveMotion(self))
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
    if (self->unk1864 == 0)
        func_00260B30(self);
    if (self->moveFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFFU;
}
