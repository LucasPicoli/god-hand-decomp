/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern void *Getplayer(void);
extern int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void Obj2810_SetState_9_a1(char *a0, int a1);
extern void SetBytes2F4Mode8_283288(char *a0, char a1);
extern void func_0026DB00(void *a0, int a1, int a2);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, Obj2810_SetState_9_a1, SetBytes2F4Mode8_283288, func_002A8578,
 * cGameObj_SetTgtTurn and 6 more. */
__attribute__((section(".text.func_0024B3D0"))) void func_0024B3D0(cEm00 *self)
{
    float one;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0: {
            int t0, b, b2, a1v, a2v;
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            a1v = EM_RES_REC(b, 0x3DB0);
            a2v = EM_RES_REC(b, 0x3DB4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                b2 = self->resource;
                a2v = EM_RES_REC(b2, 0x3DB8);
                if (self->sub0 != 0)
                    Obj2810_SetState_9_a1((char *)self->sub0, 1);
                if (self->sub1 != 0)
                    SetBytes2F4Mode8_283288((char *)self->sub1, 1);
                if (self->sub2 != 0)
                    SetBytes2F4Mode8_283288((char *)self->sub2, 1);
            } else {
                if (self->sub0 != 0)
                    Obj2810_SetState_9_a1((char *)self->sub0, 0);
                if (self->sub1 != 0)
                    SetBytes2F4Mode8_283288((char *)self->sub1, 0);
                if (self->sub2 != 0)
                    SetBytes2F4Mode8_283288((char *)self->sub2, 0);
            }
            func_002A8578(self, a1v, a2v, 0.0f, 0xA, t0, 0);
        }
            self->timer = 30.0f;
            self->step++;
        case 1:
            if (0.0f < self->timer) {
                self->timer = self->timer - self->speedRate;
                cGameObj_SetTgtTurn(self, *(int *)((char *)Getplayer() + 0xF0),
                                    self->speedRate * 0.0122718466f);
            }
            if (moveMotion(self) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) < 3 && (irand() & 1) != 0 &&
                    64.0f < self->playerDist) {
                    self->mode = 0;
                    self->phase = 0x6C;
                    self->step = 0;
                    self->stepArg = 0;
                    break;
                }
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
    if (self->moveFlags & 1) {
        func_0026DB00(self, 3, 0);
    }
    if (self->moveFlags & 2) {
        func_0026DB00(self, 3, 1);
    }
}
