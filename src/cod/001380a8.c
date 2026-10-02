#include "godhand/vu0.h"

/* cCamera — large object constructor: set the vtable at 0x35C, zero a
 * block of quadwords, lay down seven identity matrices at 0x0/0x40/0x80/0xC0/
 * 0x100/0x140/0x180 (each via vmove/vmr32 in its own scope so the base pointer
 * alternates v0/v1 as retail does), reset the camera, return the object.
 * sn-2.95.3-136. */

extern int D_0041D8B8;
extern void cCamera_reset(void *);

__attribute__((section(".text.cCamera")))
void *cCamera(void *a0) {
    *(int **)((char *)a0 + 0x35C) = &D_0041D8B8;
    VU0_SQC2_VF0(a0, 0x1D0);
    VU0_SQC2_VF0(a0, 0x1E0);
    VU0_SQC2_VF0(a0, 0x200);
    VU0_SQC2_VF0(a0, 0x210);
    VU0_SQC2_VF0(a0, 0x220);
    VU0_SQC2_VF0(a0, 0x230);
    VU0_SQC2_VF0(a0, 0x240);
    VU0_SQC2_VF0(a0, 0x280);
    VU0_SQC2_VF0(a0, 0x290);
    VU0_SQC2_VF0(a0, 0x2A0);
    VU0_SQC2_VF0(a0, 0x300);
    VU0_SQC2_VF0(a0, 0x320);
    VU0_SQC2_VF0(a0, 0x330);
    VU0_SQC2_VF0(a0, 0x340);
    {
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, a0, 0x30); VU0_SQC2(5, a0, 0x20); VU0_SQC2(6, a0, 0x10); VU0_SQC2(7, a0, 0x0);
    }
    {
        char *p = (char *)a0 + 0x40;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        char *p = (char *)a0 + 0x80;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        char *p = (char *)a0 + 0xC0;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        char *p = (char *)a0 + 0x100;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        char *p = (char *)a0 + 0x140;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    {
        char *p = (char *)a0 + 0x180;
        VU0_VMOVE_XYZW(4, 0); VU0_VMR32_XYZW(5, 4); VU0_VMR32_XYZW(6, 5); VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, p, 0x30); VU0_SQC2(5, p, 0x20); VU0_SQC2(6, p, 0x10); VU0_SQC2(7, p, 0x0);
    }
    cCamera_reset(a0);
    return a0;
}
