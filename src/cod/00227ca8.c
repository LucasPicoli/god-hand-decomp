/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

/* func_00227CA8 — 0x00227CA8, 828 B — sn-2.95.3-136.
 * Template src/cod/00225e30.c (func_00225E30, jaccard 0.93). */

extern int  Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int irand(void);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int  Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int  moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_00260B30(void *a0);

/* Phase machine on the step byte, 8 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, irand,
 * cCoreSave_getGameLevel, StoreMotionParamsBoth_2609A8, func_002A8578, Getplayer and 7 more. */
__attribute__((section(".text.func_00227CA8"))) void func_00227CA8(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int r;
            int p1;
            int p2;

            self->unk1864 = 0;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            if (9.0f < self->playerDist) {
                self->stepArg = 0;
            } else {
                self->stepArg = 1;
            }
            if ((irand() & 3) == 0) {
                self->stepArg = 2;
            }
            switch (self->stepArg) {
                default:
                case 0: {
                    int w = self->resource;
                    p1 = EM_RES_REC(w, 0x300C);
                    p2 = EM_RES_REC(w, 0x3010);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        int w2 = self->resource;
                        p2 = EM_RES_REC(w2, 0x3014);
                    }
                    self->timer = 35.0f;
                    break;
                }
                case 1: {
                    int w = self->resource;
                    p1 = EM_RES_REC(w, 0x3018);
                    p2 = EM_RES_REC(w, 0x301C);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        int w2 = self->resource;
                        p2 = EM_RES_REC(w2, 0x3020);
                    }
                    self->timer = 25.0f;
                    break;
                }
                case 2: {
                    int w = self->resource;
                    p1 = EM_RES_REC(w, 0x3024);
                    p2 = EM_RES_REC(w, 0x3028);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        int w2 = self->resource;
                        p2 = EM_RES_REC(w2, 0x302C);
                    }
                    self->timer = 90.0f;
                    break;
                }
            }
            StoreMotionParamsBoth_2609A8(self, 0x14, 0x1B, 0x3E, -1, 0);
            func_002A8578(self, p1, p2, 0.0f, 3, r, 0);
            self->timerB = 0;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            float t = self->timer;

            if (0.0f < t) {
                int q;
                self->timer = t - self->speedRate;
                q = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(q + 0xF0), self->speedRate * 0.19634954f);
            }
            if (moveMotion(self)) {
                if (25.0f < self->playerDist) {
                    self->mode = 0;
                    self->phase = 0x6C;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_002705D8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 2) {
                if (self->timerB != 0) {
                    self->timerB = 0;
                    switch (self->stepArg) {
                        default:
                        case 0:
                            func_0026BEF0(self, 0xA, 0);
                            break;
                        case 1:
                            func_0026BEF0(self, 0xB, 0);
                            break;
                        case 2:
                            func_0026BEF0(self, 0xC, 0);
                            break;
                    }
                }
            } else {
                self->timerB = 1;
            }
            if (self->moveFlags & 1)
                func_00260B30(self);
            break;
        }
        default:
            break;
    }
}
