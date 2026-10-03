#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/vu0.h"







extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0,
                         float f12, float f13, float f14);

/* Phase machine on the step byte, 4 case labels. Calls aligned, func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed, VU0_LQC2 and 2 more. */
__attribute__((section(".text.func_002412A8"))) void func_002412A8(cEm00 *self)
{
    float buf[4] __attribute__((aligned(16)));

    switch (self->step) {
        case 0: {
            int b = (int)*(char **)((char *)self + 0x304);
            func_002A8578(self, EM_RES_REC(b, 0x1A50), EM_RES_REC(b, 0x1A54), 0.0f, 3, 0, 0);
            self->unk568 = 0xA;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            int m = self->emFlags;
            m |= 0x10000;
            self->hitFlash = 3.0f;
            m |= 0x20000;
            self->emFlags = m;
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f / *(float *)((char *)self + 0x118));
            break;
        }
        case 2: {
            int b = (int)*(char **)((char *)self + 0x304);
            func_002A8578(self, EM_RES_REC(b, 0x18F0), EM_RES_REC(b, 0x18F4), 10.0f, 0, 0, 0);
            self->unk568 = 0xA;
            self->step++;
        }
        /* fallthrough */
        case 3: {
            float *dst;
            float *src;
            int m = self->emFlags;
            m |= 0x10000;
            self->hitFlash = 3.0f;
            m |= 0x20000;
            self->emFlags = m;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->emFlags & 0x20000000) == 0) {
                int n;
                float *q = *(float **)((char *)self + 0xF0);
                VU0_LQC2(4, q, 0);
                VU0_SQC2(4, buf, 0);
                if (func_00291010(&D_005864F0, buf, self, 2, 0, self->rot.y, 100.0f, 3.14159274f) !=
                    0)
                    break;
                n = *(unsigned short *)((char *)self + 0x568) - 1;
                self->unk568 = n;
                if ((short)n > 0)
                    break;
            }
            dst = (float *)(&self->unk6D0);
            src = *(float **)((char *)self + 0xF0);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            self->phase = 0x75;
            self->unk6E0 = self->rot.y;
            self->mode = 0;
            self->step = 0;
            self->stepArg = 0;
            break;
        }
    }
}
