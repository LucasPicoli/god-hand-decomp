#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* Phase machine on the step byte, 6 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, func_002705D8,
 * cObjBase_addNullSpeed_Rotation and 1 more. */
__attribute__((section(".text.func_00247320"))) void func_00247320(cEm00 *self)
{
    int res;

    self->emFlags = self->emFlags | 0x20000;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int a;
            int bb;

            {
                int id = self->emNo;
                if (id != 0x22C) {
                    if (id >= 0x22D)
                        goto dflt;
                    if (id != 0x21C) {
                    dflt:
                        {
                            int b = self->resource;
                            a = EM_RES_REC(b, 0x36F0);
                            bb = EM_RES_REC(b, 0x36F4);
                        }
                    } else {
                        {
                            int b = self->resource;
                            a = EM_RES_REC(b, 0x3708);
                            bb = EM_RES_REC(b, 0x370C);
                        }
                    }
                } else {
                    {
                        int b = self->resource;
                        a = EM_RES_REC(b, 0x3710);
                        bb = EM_RES_REC(b, 0x3714);
                    }
                }
            }
            func_002A8578(self, a, bb, 0.0f, 0, t0, 0);
        }
            self->step++;
        case 1:
            if (moveMotion(self) != 0) {
                if (self->emNo == 0x244) {
                    self->step++;
                } else {
                    func_002705D8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;

            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x36F8), EM_RES_REC(res, 0x36FC), 0.0f, 3, t0, 0);
        }
            self->step++;
        case 3:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->emFlags & 0x20000000) != 0) {
                self->step = 4;
            }
            if (0.0f < *(float *)((char *)self + 0x16C0)) {
                self->step = 4;
            }
            break;
        case 4: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;

            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x3700), EM_RES_REC(res, 0x3704), 0.0f, 3, t0, 0);
        }
            self->step++;
        case 5:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
