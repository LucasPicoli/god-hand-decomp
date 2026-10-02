#include "godhand/vu0.h"

/* cPlCamera — extends cCamera: run the base constructor, then set
 * (and re-set) the vtable at 0x35C while zeroing two further blocks of
 * quadwords and a tail word block.  The inline-asm memory clobbers keep the
 * first (overwritten) 0x35C store live.  sn-2.95.3-136. */

extern void *cCamera(void *);
extern int D_0041D8F8;
extern int D_0041DBB0;

__attribute__((section(".text.cPlCamera")))
void *cPlCamera(void *a0) {
    cCamera(a0);
    *(int **)((char *)a0 + 0x35C) = &D_0041D8F8;
    VU0_SQC2_VF0(a0, 0x370);
    VU0_SQC2_VF0(a0, 0x380);
    VU0_SQC2_VF0(a0, 0x390);
    VU0_SQC2_VF0(a0, 0x3B0);
    VU0_SQC2_VF0(a0, 0x3C0);
    VU0_SQC2_VF0(a0, 0x3D0);
    *(int **)((char *)a0 + 0x35C) = &D_0041DBB0;
    VU0_SQC2_VF0(a0, 0x400);
    VU0_SQC2_VF0(a0, 0x410);
    VU0_SQC2_VF0(a0, 0x440);
    VU0_SQC2_VF0(a0, 0x450);
    VU0_SQC2_VF0(a0, 0x480);
    VU0_SQC2_VF0(a0, 0x490);
    VU0_SQC2_VF0(a0, 0x4C0);
    VU0_SQC2_VF0(a0, 0x4D0);
    VU0_SQC2_VF0(a0, 0x500);
    *(int *)((char *)a0 + 0x528) = 0;
    *(int *)((char *)a0 + 0x520) = 0;
    *(int *)((char *)a0 + 0x524) = 0;
    *(int *)((char *)a0 + 0x510) = 0;
    *(int *)((char *)a0 + 0x514) = 0;
    return a0;
}
