#include "godhand/cEm00.h"

/* func_0027E438 — +0x2F6 phase machine (record fields 0x190/0x194, mode 0): phase
 * 0 fires func_002A8578 and advances; both phases step moveMotion then add a unit
 * (1.0f) scaled vector into the +0x100 and +0xF0 fields.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed. */
__attribute__((section(".text.func_0027E438"))) void func_0027E438(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x190), EM_RES_REC(res, 0x194), 0.0f, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
