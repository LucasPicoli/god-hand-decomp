#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern void SetMotionStep(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

/* func_001CB030 — refresh the +0x5A8 speed-rate field from the +0x600 owner, then a
 * 16-phase +0x2F6 machine over record +0x304.  sn-2.95.3-136. */







/* Phase machine on the step byte, 16 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, moveMotion, InitRenderStruct_2A8608. */
__attribute__((section(".text.func_001CB030"))) void func_001CB030(cEm00 *self)
{
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    char *p = *(char **)((char *)self + 0x600);
    if (p != 0) {
        r = *(float *)(p + 0x5A8);
    }
    self->speedRate = r;
    SetMotionStep(self, r);
    switch (self->step) {
        case 0: {
            int v = self->resource;
            self->objFlags |= 0x40000;
            func_002A8578(self, EM_RES_REC(v, 0xC), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
        case 1:
            moveMotion(self);
            break;
        case 2:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x14), EM_RES_REC(v, 0x18), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x65, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x14), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x64, 0, 2, 0);
            }
            self->step++;
            goto L_mm;
        case 4:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x1C), EM_RES_REC(v, 0x20), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x63, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x1C), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x62, 0, 2, 0);
            }
            self->step++;
            goto L_mm;
        case 6:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x24), EM_RES_REC(v, 0x28), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x78, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x24), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x77, 0, 2, 0);
            }
            self->step++;
            goto L_mm;
        case 8:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x34), EM_RES_REC(v, 0x38), 0.0f, 0, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x34), 0, 0.0f, 0, 0, 0);
            }
            self->step++;
            goto L_mm;
        case 10: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x3C), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_mm;
        case 12:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x2C), EM_RES_REC(v, 0x30), 0.0f, 0, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x2C), 0, 0.0f, 0, 0, 0);
            }
            self->step++;
            goto L_mm;
        case 14:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x40), EM_RES_REC(v, 0x44), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x94, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x40), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x58, 0x93, 0, 2, 0);
            }
            self->step++;
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
        case 13:
        case 15:
        L_mm:
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            break;
    }
}
