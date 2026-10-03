/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void Obj2810_ClearState_6(void *a0);
extern void SetBytes2F4Mode5_283258(void *a0);
extern int moveMotion(void *a0);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DC4B8(void *a0);
extern void func_0026DB00(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */














/* Phase machine on the step byte, 7 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Obj2810_ClearState_6, SetBytes2F4Mode5_283258, cCoreSave_getGameLevel, moveMotion
 * and 5 more. */
__attribute__((section(".text.func_0024ABC0"))) void func_0024ABC0(cEm00 *self)
{
    self->emFlags |= 0x30400;
    switch (self->step) {
        case 0: {
            int nb;
            char *v1;
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x3D9C), EM_RES_REC((int)v1, 0x3DA0), 0xA, 0.0f,
                          nb, 0);
            if ((void *)self->sub0 != 0)
                Obj2810_ClearState_6((void *)self->sub0);
            if ((void *)self->sub1 != 0)
                SetBytes2F4Mode5_283258((void *)self->sub1);
            if ((void *)self->sub2 != 0)
                SetBytes2F4Mode5_283258((void *)self->sub2);
            self->timer = 0.0f;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->timer = 0.0f;
                    break;
                case 2:
                    self->timer = 5.0f;
                    break;
                case 3:
                    self->timer = 10.0f;
                    break;
                case 4:
                    self->timer = 10.0f;
                    break;
                case 5:
                    self->timer = 15.0f;
                    break;
            }
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                    if ((irand() & 1) != 0) {
                        if (self->playerDist > 64.0f) {
                            self->mode = 0;
                            self->phase = 0x6C;
                            self->step = 0;
                            self->stepArg = 0;
                            break;
                        }
                    }
                }
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->moveFlags & 0x10) != 0) {
                if (self->timer > 0.0f) {
                    self->timer = self->timer - self->speedRate;
                } else {
                    func_002DC4B8(self);
                }
            }
            break;
    }
    if ((self->moveFlags & 1) != 0) {
        func_0026DB00(self, 1, 0);
    }
    if ((self->moveFlags & 2) != 0) {
        func_0026DB00(self, 1, 1);
    }
}
