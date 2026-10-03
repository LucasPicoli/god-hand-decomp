#include "godhand/cEm00.h"

/* func_00277A48 — +0x2F6 phase machine (record fields 0x54/0x58, mode 3): phase 0
 * fires func_002A8578 and advances, phases 0/1 step moveMotion and add the
 * 1.0f-scaled vectors. Every phase then runs func_002DDAB0 on the +0xF0 object
 * (scale 10.0f) and re-arms 0x2F5=2 when it reports done.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int func_002DDAB0(void *a0, int a1, float f);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed, func_002DDAB0. */
__attribute__((section(".text.func_00277A48"))) void func_00277A48(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x54), EM_RES_REC(res, 0x58), 0.0f, 3, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (func_002DDAB0((void *)self->pos, 0, 10.0f) != 0) {
        self->mode = 0;
        self->phase = 2;
        self->step = 0;
        self->stepArg = 0;
    }
}
