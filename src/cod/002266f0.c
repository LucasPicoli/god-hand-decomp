/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void StoreMotionParams_2609E0(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Set_Fields_1884_1894_2609F8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_00260B30(void *a0);

/* Phase machine on the step byte, 11 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8, StoreMotionParams_2609E0, Set_Fields_1884_1894_2609F8,
 * func_002A8578, cCoreSave_getGameLevel and 9 more. */
__attribute__((section(".text.func_002266F0"))) void func_002266F0(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            int s2v, s0v;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default:
                case 0x250:
                case 0x251: {
                    int b;

                    StoreMotionParamsBoth_2609A8(self, 0x50, 0x1E, 0x3E, -1, 0);
                    b = self->resource;
                    s2v = EM_RES_REC(b, 0x19AC);
                    s0v = EM_RES_REC(b, 0x19B0);
                    self->timerA = 0x64;
                } break;
                case 0x260: {
                    int b;

                    StoreMotionParams_2609E0(self, 0x46, 0x1F, 0x3E, -1, 0);
                    Set_Fields_1884_1894_2609F8(self, 0x46, 0x20, 0x3E, -1, 0);
                    b = self->resource;
                    s2v = EM_RES_REC(b, 0x30BC);
                    s0v = EM_RES_REC(b, 0x30C0);
                    self->timerA = 0x64;
                } break;
                case 0x223: {
                    int b;

                    StoreMotionParamsBoth_2609A8(self, 0x32, 0x21, 0x3E, -1, 0);
                    b = self->resource;
                    s2v = EM_RES_REC(b, 0x2E0C);
                    s0v = EM_RES_REC(b, 0x2E10);
                    self->timerA = 0;
                } break;
            }
            func_002A8578(self, s2v, s0v, 0.0f, 0xA, gb, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->timerA = 0x46;
                    break;
                case 2:
                    self->timerA = 0x50;
                    break;
                case 3:
                    self->timerA = 0x5A;
                    break;
                case 4:
                    self->timerA = 0x5A;
                    break;
                case 5:
                    break;
            }
            self->timerC = 0;
            self->timerB = 0x64;
            func_0026EE40(self, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 1: {
            int n;

            if (self->timerA != 0) {
                char *o;

                self->timerA = self->timerA - 1;
                o = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(o + 0xF0), self->speedRate * 0.19634954f);
            }
            if (self->moveFlags & 1) {
                if (self->timerB >= 0xB)
                    self->timerB = 0xA;
            }
            n = self->timerB;
            if (n != 0) {
                self->emFlags |= 0x800000;
                self->timerB = n - 1;
            }
            if (moveMotion(self) != 0)
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        default:
            break;
    }
    func_00260B30(self);
    if (self->moveFlags & 0x10) {
        if (func_00262AA8(self) != 0)
            return;
    }
    if (self->moveFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFFU;
}
