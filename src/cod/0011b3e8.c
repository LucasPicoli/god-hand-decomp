/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"

extern unsigned char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern float capVu0Atan2(float y, float x);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
#include "godhand/vu0.h"
/* Phase machine of the enemy that turns toward the target of its link record: step 0 starts the
 * motion and sets the facing angle from the vector to the target, step 1 waits for the motion to
 * end. */
__attribute__((section(".text.func_0011B3E8"))) void func_0011B3E8(cEm00 *self)
{
    char buf[0x30] __attribute__((aligned(16)));
    int s2v, s1v;
    char *g;

    switch (self->step) {
        case 0: {
            int v0 = self->resource;
            char *p;
            g = (char *)&D_005FEE00;
            s2v = EM_RES_REC(v0, 0x270);
            s1v = EM_RES_REC(v0, 0x274);
            cSnd_SeCall_2CBA48(g, 0, 0xCF, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(g, 0, 0x2D, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(g, 0, 0x32, self, 0, 0, 0, 0);
            self->hitFlash = 5.0f;
            func_0012C348(self, 2);
            CallWithAndClearField698_12AC28(self);
            func_0012B928(self);
            func_002A8578(self, s2v, s1v, 15.0f, 2, 0, 0);
            p = self->unk678;
            if (p != 0) {
                p = *(char **)(p + 0x34);
                if (p != 0) {
                    char *a;
                    char *b;
                    char *q;
                    VU0_SQC2_VF0(buf, 0x0);
                    a = *(char **)(p + 0xF0);
                    q = buf + 0x10;
                    b = (char *)self->pos;
                    VU0_SQC2_VF0(buf, 0x20);
                    CEM00_REGALLOC_NUDGE(self);
                    VU0_LQC2(4, a, 0);
                    VU0_LQC2(5, b, 0);
                    VU0_VSUB_XYZ(4, 4, 5);
                    VU0_SQC2(4, buf, 0x20);
                    VU0_LQC2(4, buf + 0x20, 0);
                    VU0_SQC2(4, buf, 0x10);
                    if ((float *)buf != (float *)q) {
                        ((float *)buf)[0] = ((float *)(buf + 0x10))[0];
                        ((float *)buf)[1] = ((float *)(buf + 0x10))[1];
                        ((float *)buf)[2] = ((float *)(buf + 0x10))[2];
                    }
                    self->rot.y = capVu0Atan2(((float *)buf)[0], ((float *)buf)[2]);
                }
            }
            self->step = self->step + 1;
            self->gotoFlags = 0x1E;
        }
        case 1:
            func_00124EC0(self);
            if (moveMotion(self) != 0) {
                pl00_clearMotionCam(self, 0, 0);
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
