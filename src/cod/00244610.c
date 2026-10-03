#include "godhand/cEm00.h"

/* func_00244610 — runs the 0x1346C8 handler and ORs 0x10000 into +0x16D0, then a
 * +0x2F6 phase machine (record fields 0x2494/0x2498, mode 3, t0 = low 16 bits of
 * the 0x17C3 getter); phase 0 also fires two func_002606E8 events (0x200, 0x203).
 * Shared tail steps moveMotion (func_002705D8 on completion) + 1.0f vectors. sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002606E8(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* Phase machine on the step byte, 2 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, func_002606E8, moveMotion, func_002705D8 and 2
 * more. */
__attribute__((section(".text.func_00244610"))) void func_00244610(cEm00 *self)
{
    int res;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->emFlags = self->emFlags | 0x10000;
    switch (self->step) {
        case 0: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x2494), EM_RES_REC(res, 0x2498), 0.0f, 3, t0, 0);
            func_002606E8(self, 0x200);
            func_002606E8(self, 0x203);
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
