/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00260B30(void *a0);

/* sn-2.95.3-136 matched TU. */















/* Phase machine on the step byte, 7 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, StoreMotionParamsBoth_2609A8, cCoreSave_getGameLevel,
 * func_002A8578, Getplayer and 6 more. */
__attribute__((section(".text.func_0022B790"))) void func_0022B790(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (self->step) {
        case 0: {
            int gb;
            char *v1;
            int a1v, a2v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
            v1 = (char *)self->resource;
            a1v = EM_RES_REC((int)v1, 0x21F4);
            a2v = EM_RES_REC((int)v1, 0x21F8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *w = (char *)self->resource;
                a2v = EM_RES_REC((int)w, 0x21FC);
            }
            func_002A8578(self, a1v, a2v, 0.0f, 5, gb, 0);
            self->timerA = 0xA;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
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
            self->timerC = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                char *v0;
                self->timerA -= 1;
                v0 = (char *)Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    func_00260B30(self);
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
