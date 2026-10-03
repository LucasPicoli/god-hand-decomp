#include "godhand/cEm00.h"

/* func_002387B8 — runs the 0x1346C8 handler and sets +0x54C=3.0f, then a +0x2F6
 * phase machine (record fields 0x36D0/0x36D4, mode 0); phase 0 also clears +0x1864.
 * moveMotion-done reset re-arms 0x2F5=0x6C; 1.0f vector tail.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
/* Phase machine on the step byte, 2 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed. */
__attribute__((section(".text.func_002387B8"))) void func_002387B8(cEm00 *self)
{
    int res;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0:
            res = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(res, 0x36D0), EM_RES_REC(res, 0x36D4), 0.0f, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
