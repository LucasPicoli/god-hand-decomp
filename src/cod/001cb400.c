#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern void SetMotionStep(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

/* Phase machine on the step byte, 30 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, InitRenderStruct_2A8608, moveMotion. */
__attribute__((section(".text.func_001CB400"))) void func_001CB400(cEm00 *self)
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
            func_002A8578(self, EM_RES_REC(v, 0xC), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_mm;
        case 2: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x10), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_mm;
        case 4: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x14), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_rs;
        case 6: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x18), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_mm;
        case 8: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x44), 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(self, 0x6F, 0xC, 0, 2, 0);
        }
            self->step++;
            goto L_mm;
        case 10:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x1C), EM_RES_REC(v, 0x20), 0.0f, 0, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x1C), 0, 0.0f, 0, 0, 0);
            }
            self->step++;
            goto L_mm;
        case 12:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x24), EM_RES_REC(v, 0x28), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x6F, 0xB, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x24), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x6F, 0xA, 0, 2, 0);
            }
            self->step++;
            goto L_rs;
        case 14:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x30), 0, 0.0f, 0, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x34), 0, 0.0f, 0, 0, 0);
            }
            self->step++;
            goto L_mm;
        case 16: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x38), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
        case 1:
        case 3:
        case 7:
        case 9:
        case 11:
        case 15:
        case 17:
        L_mm:
            moveMotion(self);
            break;
        case 18: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x3C), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
        case 19:
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            break;
        case 20: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x40), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_rs;
        case 22: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x2C), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_rs;
        case 24: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x50), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
            goto L_rs;
        case 26:
            if (self->stepArg != 0) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x48), EM_RES_REC(v, 0x4C), 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x6F, 0xF, 0, 2, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x48), 0, 0.0f, 0, 0, 0);
                InitRenderStruct_2A8608(self, 0x6F, 0xE, 0, 2, 0);
            }
            self->step++;
            goto L_rs;
        case 28: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x58), 0, 0.0f, 0, 0, 0);
        }
            self->step++;
        case 5:
        case 13:
        case 21:
        case 23:
        case 25:
        case 27:
        case 29:
        L_rs:
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            break;
    }
}
