#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void *Getplayer(void);
extern void func_002A74E0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int D_007476B0;

/* sn-2.95.3-136 */












/* Phase machine on the step byte, 6 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed, func_002A74E0
 * and 3 more. */
__attribute__((section(".text.func_0023AAD0"))) void func_0023AAD0(cEm00 *self)
{
    float one;

    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            {
                int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
                int b = self->resource;

                func_002A8578(self, EM_RES_REC(b, 0xC08), EM_RES_REC(b, 0xC0C), 0.0f, 0xA, t0, 0);
            }
            self->emFlags = (self->emFlags | 0x8000) & 0xFFFFFFFD;
            self->step++;
        case 1:
            self->emFlags = self->emFlags | 0x400000;
            if (moveMotion(self) != 0) {
                self->step++;
                break;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 2: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int b = self->resource;

            func_002A8578(self, EM_RES_REC(b, 0xC08), EM_RES_REC(b, 0xC0C), 0.0f, 0xA, t0, 0);
        }
            self->timerA = 1;
            self->step++;
        case 3: {
            int x = self->vital;
            int lim = self->vitalMax;

            self->emFlags = self->emFlags | 0x400000;
            x = x + 1;
            if (lim < x) {
                x = lim;
            }
            if (lim <= x) {
                self->vital = self->vitalMax;
            } else {
                self->vital = x;
            }
        }
            if ((D_007476B0 & 7) == (*(int *)((char *)self + 0x17D0) & 7)) {
                self->emFlags2 = self->emFlags2 & 0xF7FFFFFF;
                func_002A74E0(self, *(int *)((char *)Getplayer() + 0xF0), 1);
                if (func_002A7CA0(self, &self->unk16A0) != 0) {
                    self->emFlags2 = self->emFlags2 | 0x8000000;
                }
                if (*(float *)((char *)self + 0x510) < 8.0f) {
                    self->timerA = 0;
                    self->emFlags = (self->emFlags & 0xFFFF7FFF) | 2;
                }
            }
            if (self->unk16EC != 0) {
                self->step = 4;
            }
            if (moveMotion(self) != 0) {
                if (self->timerA == 0) {
                    self->step = 4;
                }
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 4: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int b = self->resource;

            func_002A8578(self, EM_RES_REC(b, 0xC10), EM_RES_REC(b, 0xC14), 0.0f, 0xA, t0, 0);
        }
            self->step++;
        case 5:
            self->emFlags = self->emFlags | 0x400000;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
                break;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}
