/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);


extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, func_002A8578, func_0026EE40, cGameObj_SetTgtTurn, Getplayer and 9 more.
 */
__attribute__((section(".text.func_00223470"))) void func_00223470(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            char *v0;
            int a1v, a2v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            {
                char *b = (char *)self->resource;
                a1v = EM_RES_REC((int)b, 0x6E8);
                a2v = EM_RES_REC((int)b, 0x6EC);
            }
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                v0 = (char *)self->resource;
                a2v = EM_RES_REC((int)v0, 0x6F0);
            }
            func_002A8578(self, a1v, a2v, 0.0f, 3, gb, 0);
            self->timerA = 0xF;
            self->timerB = 0;
            self->timerC = 0;
            func_0026EE40(self, 0, 0);
            self->step += 1;
        }
        case 1:
            if (self->timerA != 0) {
                self->timerA -= 1;
                cGameObj_SetTgtTurn(self, *(int *)((char *)Getplayer() + 0xF0),
                                    self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0) {
                func_0026EE40(self, 0, 0);
                if (func_00262AA8(self) != 0)
                    return;
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->timerB == 0) {
                if (self->moveFlags & 2) {
                    SetEffect(0x58, 0x29, self, 0, -1, 0xFFFFFFFF);
                    self->timerB = 1;
                }
            }
            break;
    }
    StoreMotionParamsBoth_2609A8(self, 0, 0xF, 0x4A, -1, 0);
    if (self->moveFlags & 1)
        func_00260B30(self);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
        if (func_0026F1D8(self) == 0 && (self->moveFlags & 0x10) != 0)
            if (func_00262AA8(self) != 0)
                return;
    }
    if (self->moveFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFF;
}
