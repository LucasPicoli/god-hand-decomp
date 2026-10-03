#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern int Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0026B600(void *a0);
extern void func_0026BAD8(void *a0, int a1, int a2);
extern float capVu0Sin(float f12);
extern float Adjust_theta(float f12);
extern char D_00462FC0[];

/* Phase machine on the step byte, 12 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, cGameObj_SetTgtTurn, Getplayer, moveMotion and
 * 6 more. */
__attribute__((section(".text.func_002439A0"))) void func_002439A0(cEm00 *self)
{
    float t20;
    float th;
    int p;

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    self->emFlags |= 0x10000;
    switch (self->step) {
        case 0: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2474), EM_RES_REC(w, 0x2478), 3, 0.0f, t, 0);
            self->timerA = 1;
            *(float *)((char *)self + 0x60C) = 0.0f;
            self->step++;
        }
        /* fallthrough */
        case 1:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->moveFlags & 1) && self->timerA != 0) {
                self->timerA = 0;
                func_0026B600(self);
            }
            break;
        case 2: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x247C), EM_RES_REC(w, 0x2480), 3, 0.0f, t, 0);
            self->timer = 90.0f;
            self->step++;
        }
        /* fallthrough */
        case 3: {
            float d;
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f)
                self->step++;
            break;
        }
        case 4: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x249C), EM_RES_REC(w, 0x24A0), 3, 0.0f, t, 0);
            self->timer = 0.0f;
            self->unk568 = 0;
            self->step++;
        }
        /* fallthrough */
        case 5:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 3) {
                if (self->unk568 > 0)
                    goto chk;
                self->unk568 = 8;
                self->timer = 2.0f;
            }
            if (self->unk568 == 0)
                break;
        chk:
            if (0.0f < self->timer) {
                self->timer = self->timer - self->speedRate;
            } else {
                self->unk568 = self->unk568 - 1;
                func_0026BAD8(self, 1, 1);
                self->timer = 20.0f;
            }
            break;
        case 6: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x247C), EM_RES_REC(w, 0x2480), 3, 0.0f, t, 0);
            self->step++;
        }
        /* fallthrough */
        case 7:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk568 != 0) {
                if (0.0f < self->timer) {
                    self->timer = self->timer - self->speedRate;
                } else {
                    self->unk568 = self->unk568 - 1;
                    func_0026BAD8(self, 1, 1);
                    self->timer = 20.0f;
                }
            } else {
                self->step++;
            }
            break;
        case 8: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x24A4), EM_RES_REC(w, 0x24A8), 3, 0.0f, t, 0);
            self->step++;
        }
        /* fallthrough */
        case 9:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 10: {
            int t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2464), EM_RES_REC(w, 0x2468), 3, 0.0f, t, 0);
            self->timer = 90.0f;
            self->step++;
        }
        /* fallthrough */
        case 11: {
            float d;
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                self->mode = 0;
                self->phase = 0x7F;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        }
        default:
            break;
    }
    t20 = capVu0Sin(*(float *)((char *)self + 0x60C)) * 0.02f;
    th = *(float *)((char *)self + 0x60C) + self->speedRate * 0.17453292f;
    *(float *)((char *)self + 0x60C) = th;
    *(float *)((char *)self + 0x60C) = Adjust_theta(th);
    p = (int)self->pos;
    *(float *)(p + 4) = *(float *)(p + 4) + t20 * self->speedRate;
}
