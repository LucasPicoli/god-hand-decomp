#include "godhand/cEm00.h"

/* func_00227BB0 — sets +0x186A=2, ORs 0x400 into +0x16D4, then a +0x2F6 phase
 * machine (record fields 0x1EAC/0x1EB0, mode 0, t0 = low 16 bits of the 0x17C3
 * getter); phase 0 clears +0x1864. Shared tail steps moveMotion, adds the
 * 1.0f-scaled vectors, and re-arms 0x2F5=0x25 when +0x618 < 484.0f.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed. */
__attribute__((section(".text.func_00227BB0"))) void func_00227BB0(cEm00 *self)
{
    int res;
    self->unk186A = 2;
    self->emFlags2 = self->emFlags2 | 0x400;
    switch (self->step) {
        case 0: {
            int t0;
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x1EAC), EM_RES_REC(res, 0x1EB0), 0.0f, 0, t0, 0);
        }
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->playerDist < 484.0f) {
                self->mode = 0;
                self->phase = 0x25;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
