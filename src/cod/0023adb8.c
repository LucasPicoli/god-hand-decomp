#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */









/* Phase machine on the step byte, 6 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation,
 * cObjBase_addNullSpeed. */
__attribute__((section(".text.func_0023ADB8"))) void func_0023ADB8(cEm00 *self)
{
    int res;
    self->hitFlash = 5.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->emFlags = self->emFlags | 0x20000;
    *(char *)((char *)self + 0x617) = 1;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            {
                int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0xBE8), EM_RES_REC(res, 0xBEC), 0.0f, 0xA, t0,
                              0);
            }
            {
                int t = self->emFlags;
                t = t & 0xFFFF7FFF;
                t = t & 0xFFFFFFFD;
                self->emFlags = t;
            }
            self->step = self->step + 1;
            self->vital = 0;
        case 1:
            self->emFlags = self->emFlags | 0x400000;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->emFlags & 0x20000000) {
                self->step = 2;
            }
            break;
        case 2: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xBF0), EM_RES_REC(res, 0xBF4), 0.0f, 3, t0, 0);
        }
            self->step = self->step + 1;
        case 3:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xBF0), EM_RES_REC(res, 0xBF4), 64.0f, 0, t0, 0);
        }
            self->step = self->step + 1;
        case 5:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
