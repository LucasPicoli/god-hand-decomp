#include "godhand/vu0.h"
#include "godhand/cCamera.h"

/* cCamera — large object constructor: set the vtable at 0x35C, zero a
 * block of quadwords, lay down seven identity matrices at 0x0/0x40/0x80/0xC0/
 * 0x100/0x140/0x180 (each via vmove/vmr32 in its own scope so the base pointer
 * alternates v0/v1 as retail does), reset the camera, return the object.
 * sn-2.95.3-136. */

extern int D_0041D8B8;
extern void cCamera_reset(struct cCamera *self);

/* Constructor: set the vtable, zero the vectors, lay seven identity
 * matrices (each in its own scope so the base pointer alternates as in
 * retail), reset the camera. */
__attribute__((section(".text.cCamera")))
struct cCamera *cCamera(struct cCamera *self) {
    self->vt = (cCamVt *)&D_0041D8B8;
    VU0_SQC2_VF0(self, 0x1D0);
    VU0_SQC2_VF0(self, 0x1E0);
    VU0_SQC2_VF0(self, 0x200);
    VU0_SQC2_VF0(self, 0x210);
    VU0_SQC2_VF0(self, 0x220);
    VU0_SQC2_VF0(self, 0x230);
    VU0_SQC2_VF0(self, 0x240);
    VU0_SQC2_VF0(self, 0x280);
    VU0_SQC2_VF0(self, 0x290);
    VU0_SQC2_VF0(self, 0x2A0);
    VU0_SQC2_VF0(self, 0x300);
    VU0_SQC2_VF0(self, 0x320);
    VU0_SQC2_VF0(self, 0x330);
    VU0_SQC2_VF0(self, 0x340);
    {
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, self->mtx[0], 0x30); VU0_SQC2(5, self->mtx[0], 0x20); VU0_SQC2(6, self->mtx[0], 0x10); VU0_SQC2(7, self->mtx[0], 0x0);
    }
    {
        float *p = self->mtx[1];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        float *p = self->mtx[2];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        float *p = self->mtx[3];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        float *p = self->mtx[4];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        float *p = self->mtx[5];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        float *p = self->mtx[6];
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    cCamera_reset(self);
    return self;
}
