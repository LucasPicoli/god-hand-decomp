#include "godhand/vu0.h"
#include "godhand/cPlCamera.h"

/* cPlCamera — extends cCamera: run the base constructor, then set
 * (and re-set) the vtable at 0x35C while zeroing two further blocks of
 * quadwords and a tail word block.  The inline-asm memory clobbers keep the
 * first (overwritten) 0x35C store live.  sn-2.95.3-136. */

extern struct cCamera *cCamera(struct cCamera *self);
extern int D_0041D8F8;
extern int D_0041DBB0;

/* Constructor: run the cCamera one, set the vtable (twice, as retail does:
 * the memory clobbers of the asm keep the first store), zero the vectors
 * and the counters of the player camera. */
__attribute__((section(".text.cPlCamera")))
struct cPlCamera *cPlCamera(struct cPlCamera *self) {
    cCamera(&self->base);
    self->base.vt = (cCamVt *)&D_0041D8F8;
    VU0_SQC2_VF0(self, 0x370);
    VU0_SQC2_VF0(self, 0x380);
    VU0_SQC2_VF0(self, 0x390);
    VU0_SQC2_VF0(self, 0x3B0);
    VU0_SQC2_VF0(self, 0x3C0);
    VU0_SQC2_VF0(self, 0x3D0);
    self->base.vt = (cCamVt *)&D_0041DBB0;
    VU0_SQC2_VF0(self, 0x400);
    VU0_SQC2_VF0(self, 0x410);
    VU0_SQC2_VF0(self, 0x440);
    VU0_SQC2_VF0(self, 0x450);
    VU0_SQC2_VF0(self, 0x480);
    VU0_SQC2_VF0(self, 0x490);
    VU0_SQC2_VF0(self, 0x4C0);
    VU0_SQC2_VF0(self, 0x4D0);
    VU0_SQC2_VF0(self, 0x500);
    self->flags528 = 0;
    self->unk520 = 0;
    self->unk524 = 0;
    self->unk510 = 0;
    self->unk514 = 0;
    return self;
}
