#include "godhand/cEm00.h"

/* func_002880C8 — ORs 0x10020 into the +0x15B0 flags, sets +0x54C=3.0f and runs
 * the 0x1346C8/0x134608 handler, then a +0x2F6 phase machine (record fields
 * 0x168/0x16C, mode 3) stepping moveMotion.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;

/* Phase machine on the step byte, 2 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, moveMotion. */
__attribute__((section(".text.func_002880C8"))) void func_002880C8(cEm00 *self)
{
    int res;
    self->gotoFlags = self->gotoFlags | 0x10020;
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x168), EM_RES_REC(res, 0x16C), 0.0f, 3, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
    }
}
