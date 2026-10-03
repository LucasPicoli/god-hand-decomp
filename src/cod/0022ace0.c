/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

/* func_0022ACE0 — 0x0022ACE0, 688 B — sn-2.95.3-136.
 * Template src/cod/00225e30.c (func_00225E30, jaccard 0.67). */

extern int  Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int irand(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int  Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int  moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0026A638(void *a0, int a1);
extern void EmThrower_throwHeld(void *a0, int a1, int a2);
extern void func_0026A838(void *a0, int a1);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, irand,
 * cCoreSave_getGameLevel, func_002A8578, Getplayer, cGameObj_SetTgtTurn and 7 more. */
__attribute__((section(".text.func_0022ACE0"))) void func_0022ACE0(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int r;
            int c;
            int p1;
            int p2;

            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            c = irand() & 1;
            if (64.0f < self->playerDist)
                c = 0;
            if (self->playerDist < 16.0f)
                c = 1;
            if (c != 0) {
                int w = self->resource;
                p1 = EM_RES_REC(w, 0xDD0);
                p2 = EM_RES_REC(w, 0xDD4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    int w2 = self->resource;
                    p2 = EM_RES_REC(w2, 0xDD4);
                }
                self->stepArg = 1;
            } else {
                int w = self->resource;
                p1 = EM_RES_REC(w, 0xDC4);
                p2 = EM_RES_REC(w, 0xDC8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    int w2 = self->resource;
                    p2 = EM_RES_REC(w2, 0xDCC);
                }
                self->stepArg = 0;
            }
            func_002A8578(self, p1, p2, 0.0f, 3, r, 0);
            self->timerA = 0x64;
            self->timerC = 0;
            self->step++;
        }
        /* fallthrough */
        case 1:
            *(int *)((char *)self + 0x16DC) = 0x64;
            *(int *)((char *)self + 0x16E0) = 0x96;
            if (self->timerA != 0) {
                int q;
                self->timerA = self->timerA - 1;
                q = Getplayer();
                cGameObj_SetTgtTurn(self, *(int *)(q + 0xF0), self->speedRate * 0.19634954f);
            }
            if (moveMotion(self))
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 1) {
                if (self->unk17C3 != 0) {
                    func_0026A638(self, 1);
                } else {
                    func_0026A638(self, 0);
                }
            }
            if (self->moveFlags & 2) {
                if (self->stepArg != 0) {
                    EmThrower_throwHeld(self, 0, 0);
                    EmThrower_throwHeld(self, 1, 0);
                } else {
                    func_0026A838(self, 0);
                    func_0026A838(self, 1);
                }
            }
            break;
        default:
            break;
    }
    if (self->moveFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFFU;
}
