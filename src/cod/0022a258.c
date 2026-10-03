#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void func_0026B240(void *a0, int a1, int a2, int a3);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_0028FB08(void *a0);
extern void cEmManage_ReleaseEm(void *a0, void *a1);
extern char D_005864F0[];

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Getplayer, cGameObj_SetTgtTurn, moveMotion, func_002705D8 and 4 more. */
__attribute__((section(".text.func_0022A258"))) void func_0022A258(cEm00 *self)
{
    char *v;
    float one;
    int r, t;

    self->unk186A = 2;
    switch (self->step) {
        case 0:
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v, 0x3914), EM_RES_REC((int)v, 0x3918), 0.0f, 3, t,
                          0);
            self->timerA = 1;
            self->timerB = 1;
            self->step++;
        case 1:
            v = (char *)Getplayer();
            cGameObj_SetTgtTurn(self, *(int *)(v + 0xF0), self->speedRate * 0.09817477f);
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (self->moveFlags & 1) {
                if (self->timerA != 0) {
                    self->timerA = 0;
                    r = func_0026AA30(self, 0x37E);
                    if (r != 0) {
                        func_0026B240(self, r, 0x37E, 0xE);
                    }
                }
            } else {
                self->timerA = 1;
            }
            if (self->moveFlags & 1) {
                if (self->timerB != 0) {
                    self->timerB = 0;
                    r = func_0026AA30(self, 0x37E);
                    if (r != 0) {
                        func_0026B240(self, r, 0x37E, 0x12);
                    }
                }
            } else {
                self->timerB = 1;
            }
            break;
    }
}

/* Phase machine on the step byte, 4 case labels. Calls func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed, func_0028FB08, cEmManage_ReleaseEm. */
__attribute__((section(".text.func_00277D38"))) void func_00277D38(cEm00 *self)
{
    char *v;
    float one;

    self->unk1560 |= 1;
    switch (self->step) {
        case 0:
            self->rot.y = 2.5918138f;
            *(float *)((char *)self->pos + 0) = -80.327904f;
            *(float *)((char *)self->pos + 4) = -26.400499f;
            *(float *)((char *)self->pos + 8) = -22.3136f;
            v = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v, 0xC), EM_RES_REC((int)v, 0x10), 0.0f, 0, 0, 0);
            self->unk568 = 0x3C;
            self->step++;
        case 1:
            one = 1.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (--self->unk568 <= 0) {
                self->step++;
            }
            break;
        case 2:
            func_002A8578(self, *(int *)((char *)self->resource + 0x6C) + self->resource,
                          *(int *)((char *)self->resource + 0x70) + self->resource, 0.0f, 3, 0, 0);
            self->step++;
        case 3:
            if (moveMotion(self) != 0) {
                func_0028FB08(self);
                cEmManage_ReleaseEm(D_005864F0, self);
                break;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}
