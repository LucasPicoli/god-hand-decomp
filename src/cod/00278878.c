#include "godhand/cEm00.h"

/* func_00278878 — sets +0x54C=3.0f, then a +0x2F6 phase machine (record fields
 * 0x1C/0x20, mode 2); on moveMotion completion it re-arms the phase block to
 * 0x2F5=2, then adds the 1.0f-scaled vectors.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed. */
__attribute__((section(".text.func_00278878"))) void func_00278878(cEm00 *self)
{
    int res;
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x1C), EM_RES_REC(res, 0x20), 0.0f, 2, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
