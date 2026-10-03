/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void func_00262AA8(void *a0);

/* sn-2.95.3-136 matched TU. */














/* Phase machine on the step byte, 15 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Getplayer, cGameObj_SetTgtTurn, moveMotion, cObjBase_addNullSpeed_Rotation and 5
 * more. */
__attribute__((section(".text.func_002276B0"))) void func_002276B0(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    if (self->step == 0) {
        if (self->playerDist < 36.0f) {
            self->step = 8;
        }
    }
    switch (self->step) {
        case 0: {
            int gb;
            char *v1;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x1F10), EM_RES_REC((int)v1, 0x1F14), 0xA, 0.0f,
                          gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            char *v0;
            self->emFlags2 |= 0x20000;
            v0 = Getplayer();
            cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x1F18), EM_RES_REC((int)v1, 0x1F1C), 3, 0.0f,
                          gb, 0);
            self->timerA = 1;
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            char *v0;
            self->emFlags2 |= 0x20000;
            v0 = Getplayer();
            cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self) != 0) {
                self->step = 4;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 1) {
                if (self->timerA != 0) {
                    self->timerA = 0;
                    func_0026BEF0(self, 9, 0);
                }
            }
            break;
        }
        case 4: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x1F2C), EM_RES_REC((int)v1, 0x1F30), 0xA, 0.0f,
                          gb, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
                default:
                case 0:
                    self->timer = 20.0f;
                    break;
                case 1:
                    self->timer = 10.0f;
                    break;
                case 2:
                case 3:
                    self->timer = 5.0f;
                    break;
                case 4:
                    self->timer = 0.0f;
                    break;
            }
            self->step += 1;
        }
            /* fallthrough */
        case 5: {
            float d;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                self->step = 2;
                if (self->playerDist > 225.0f) {
                    self->step = 6;
                }
                if (self->playerDist < 9.0f) {
                    self->step = 6;
                }
            }
            break;
        }
        case 6: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x1F24), EM_RES_REC((int)v1, 0x1F28), 0xA, 0.0f,
                          gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 7:
            if (moveMotion(self) != 0) {
                if (self->playerDist > 25.0f) {
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
            break;
        case 8: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x1F34), EM_RES_REC((int)v1, 0x1F38), 3, 0.0f,
                          gb, 0);
            self->timerA = 1;
            self->step += 1;
        }
            /* fallthrough */
        case 9: {
            char *v0;
            self->emFlags2 |= 0x20000;
            v0 = Getplayer();
            cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 1) {
                if (self->timerA != 0) {
                    self->timerA = 0;
                    func_0026BEF0(self, 9, 0);
                }
            }
            if (self->moveFlags & 0x10) {
                func_00262AA8(self);
            }
            break;
        }
        default:
            break;
    }
}
