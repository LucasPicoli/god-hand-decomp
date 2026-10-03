#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */






/* Phase machine on the step byte, 8 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed. */
__attribute__((section(".text.func_0023A138"))) void func_0023A138(cEm00 *self)
{
    int res;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0:
            res = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(res, 0x2C8C), EM_RES_REC(res, 0x2C90), 0.0f, 0, 0, 0);
            self->step = self->step + 1;
            goto L_mm;
        case 2:
            res = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(res, 0x2C94), EM_RES_REC(res, 0x2C98), 0.0f, 0, 0, 0);
            self->step = self->step + 1;
            goto L_mm;
        case 4:
            res = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(res, 0x2C9C), EM_RES_REC(res, 0x2CA0), 0.0f, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
        case 3:
        case 5:
        L_mm:
            if (moveMotion(self) != 0) {
                self->step = self->step + 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6:
            res = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(res, 0x2CA4), EM_RES_REC(res, 0x2CA8), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step = self->step + 1;
        case 7:
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
