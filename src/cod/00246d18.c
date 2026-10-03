#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002744E0(void *a0);

/* sn-2.95.3-136 matched TU. */






/* Phase machine on the step byte, 8 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, moveMotion, func_002744E0. */
__attribute__((section(".text.func_00246D18"))) void func_00246D18(cEm00 *self)
{
    int res;
    int n;

    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            n = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x98), EM_RES_REC(res, 0x9C), 0.0f, 0xA, n & 0xFFFF,
                          0);
            self->emFlags = self->emFlags & 0xDFFFFFFF;
            self->step++;
        case 1:
            moveMotion(self);
            if ((self->emFlags & 0x20000000) != 0) {
                self->step++;
            }
            break;
        case 2:
            self->unk1864 = 0;
            n = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x3CC), EM_RES_REC(res, 0x3D0), 0.0f, 0x6,
                          n & 0xFFFF, 0);
            self->step++;
        case 3:
            if (moveMotion(self) != 0) {
                self->step++;
            }
            break;
        case 4:
            self->unk1864 = 0;
            n = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x98), EM_RES_REC(res, 0x9C), 0.0f, 0xA, n & 0xFFFF,
                          0);
            self->emFlags = self->emFlags & 0xDFFFFFFF;
            self->step++;
        case 5:
            moveMotion(self);
            if ((self->emFlags & 0x20000000) != 0) {
                self->step++;
            }
            break;
        case 6:
            self->unk1864 = 0;
            n = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x3E4), EM_RES_REC(res, 0x3E8), 0.0f, 0x6,
                          n & 0xFFFF, 0);
            self->step++;
        case 7:
            if (moveMotion(self) != 0) {
                self->step = 4;
            }
            break;
    }

    if ((self->moveFlags & 3) != 0) {
        if (self->timerA != 0) {
            self->timerA = 0;
            func_002744E0(self);
        }
    }
}
