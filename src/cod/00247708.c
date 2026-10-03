#include "godhand/cEm00.h"

/* func_00247708 — ORs 0x30000 into +0x16D0 and 0x10000 into +0x250, sets
 * +0x54C=3.0f, then a +0x2F6 phase machine (record fields 0x2148/0x214C, mode 0,
 * t0 = low 16 bits of the 0x17C3 getter). The shared tail steps moveMotion (and
 * on completion runs func_002705D8) then adds the 1.0f-scaled vectors. sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, moveMotion, func_002705D8, cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed.
 */
__attribute__((section(".text.func_00247708"))) void func_00247708(cEm00 *self)
{
    int res;
    self->emFlags = self->emFlags | 0x30000;
    self->hitFlash = 3.0f;
    self->objFlags = self->objFlags | 0x10000;
    switch (self->step) {
        case 0: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x2148), EM_RES_REC(res, 0x214C), 0.0f, 0, t0, 0);
        }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
