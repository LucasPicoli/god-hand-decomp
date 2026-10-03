/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int irand(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);

extern void func_0026BDD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, irand,
 * cCoreSave_getGameLevel, func_002A8578, Getplayer, cGameObj_SetTgtTurn and 6 more. */
__attribute__((section(".text.func_0022C1A8"))) void func_0022C1A8(cEm00 *self)
{
    int r;

    self->unk186A = 2;
    self->emFlags = self->emFlags | 0x400;
    self->emFlags2 = self->emFlags2 | 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            char *v1;
            int s2v, s1v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            self->stepArg = irand() & 1;
            v1 = (char *)self->resource;
            s2v = EM_RES_REC((int)v1, 0x22E0);
            s1v = EM_RES_REC((int)v1, 0x22E4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *w = (char *)self->resource;
                s1v = EM_RES_REC((int)w, 0x22E8);
            }
            func_002A8578(self, s2v, s1v, 0.0f, 3, gb, 0);
            self->timerA = 1;
            self->timer2 = 35.0f;
            self->step += 1;
            self->timerC = 0;
        }
            /* fallthrough */
        case 1: {
            char *p;
            if (self->timer2 > 0.0f) {
                self->timer2 = self->timer2 - self->speedRate;
                self->emFlags = self->emFlags | 0x800000;
            }
            p = (char *)Getplayer();
            cGameObj_SetTgtTurn(self, *(void **)(p + 0xF0), self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
    if (self->moveFlags & 1) {
        if (self->timerA != 0) {
            self->timerA = 0;
            if (self->emNo == 0x276) {
                r = func_0026AA30(self, 0x373);
            } else {
                r = func_0026AA30(self, 0x36B);
            }
            if (r != 0) {
                func_0026BDD0(self, r);
                self->emFlags2 = self->emFlags2 | 0x10000;
            }
        }
    } else {
        self->timerA = 1;
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 = self->emFlags2 & 0xFFFFFBFF;
    }
}
