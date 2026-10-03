#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005850B0[];
extern unsigned char D_005CB010;
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int t0, int t1);
extern void func_00281260(void *a0);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_002495E0(void *a0, float f12);
extern void func_00249770(void *a0, float f12);
extern float fRand0_1(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* Phase machine on the step byte, 6 case labels. Calls capVu0MagnitudeSqXZ, Getplayer,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, func_00281260, ClearBytes2F4To2F7_283170 and 6
 * more. */
__attribute__((section(".text.func_00249AB0"))) void func_00249AB0(cEm00 *self)
{
    capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), &D_005850B0);
    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0: {
            int gb;
            int b;
            void *q;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0x3D34), EM_RES_REC(b, 0x3D38), 0xA, 0.0f, gb, 0);
            self->timer = 30.0f;
            q = (void *)self->sub0;
            if (q != 0) {
                func_00281260(q);
            }
            q = (void *)self->sub1;
            if (q != 0) {
                ClearBytes2F4To2F7_283170(q);
            }
            q = (void *)self->sub2;
            if (q != 0) {
                ClearBytes2F4To2F7_283170(q);
            }
            self->emFlags = self->emFlags & 0xFCFFFFFFU;
            self->step++;
        }
        case 1: {
            float d;

            func_002495E0(self, 0.0f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (D_005CB010 != 0) {
                self->phase = 0x6B;
                self->mode = 0;
                self->step = 0;
                self->stepArg = 0;
                break;
            }
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                self->step++;
            }
            break;
        }
        case 2: {
            int gb;
            int b;
            void *q;
            float rv;
            float z = 0.0f;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0x3D34), EM_RES_REC(b, 0x3D38), 0xA, z, gb, 0);
            self->timer = 60.0f;
            q = (void *)self->sub0;
            if (q != 0) {
                func_00281260(q);
            }
            q = (void *)self->sub1;
            if (q != 0) {
                ClearBytes2F4To2F7_283170(q);
            }
            q = (void *)self->sub2;
            if (q != 0) {
                ClearBytes2F4To2F7_283170(q);
            }
            self->unk1864 = 0;
            self->emFlags = self->emFlags & 0xFCFFFFFFU;
            Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            if (z < *(float *)((char *)self + 0x75C)) {
                self->unk568 = 0;
            } else {
                self->unk568 = 1;
            }
            *(int *)((char *)self + 0x604) = 0;
            rv = fRand0_1() * 60.0f;
            self->step++;
            self->timer = rv + 60.0f;
        }
        case 3: {
            float d;

            if ((self->unk568 & 1) != 0) {
                float v = self->timer2 + self->speedRate * 0.0008726646f;

                self->timer2 = v;
                if (0.017453292f < v) {
                    self->timer2 = 0.017453292f;
                }
            } else {
                float v = self->timer2 - self->speedRate * 0.0008726646f;

                self->timer2 = v;
                if (v < -0.017453292f) {
                    self->timer2 = -0.017453292f;
                }
            }
            func_00249770(self, self->timer2 * self->speedRate);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (D_005CB010 != 0) {
                self->step = 4;
            }
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                self->step = 4;
            }
            break;
        }
        case 4:
            self->unk1864 = 0;
            Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            self->step++;
        case 5: {
            if ((self->unk568 & 1) != 0) {
                float v = self->timer2 - self->speedRate * 0.0008726646f;

                self->timer2 = v;
                if (v < 0.0f) {
                    self->timer2 = 0.0f;
                    self->phase = 0xA1;
                    self->mode = 0;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                float v = self->timer2 + self->speedRate * 0.0008726646f;

                self->timer2 = v;
                if (0.0f < v) {
                    self->timer2 = 0.0f;
                    self->phase = 0xA1;
                    self->mode = 0;
                    self->step = 0;
                    self->stepArg = 0;
                }
            }
            func_00249770(self, self->timer2 * self->speedRate);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
}
