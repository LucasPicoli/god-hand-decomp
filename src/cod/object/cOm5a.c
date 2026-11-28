/* TU: cOm5a [object] - recovered C++ class. */
#include "godhand/vu0.h"
#include "include_asm.h"
#include "godhand/cOm5a.h"

__attribute__((section(".text.cOm5a_isOpen")))
unsigned char cOm5a_isOpen(cOm5a *a0) {
    return a0->open;
}

__attribute__((section(".text.cOm5a_setOpenFix")))
void cOm5a_setOpenFix(cOm5a *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 0) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
        if (a0->openType == 0) {
            buf[1] = buf[1] + a0->unk790;
        } else {
            buf[1] = buf[1] - a0->unk790;
        }
        {
            cVtEnt *vt2 = a0->base.vtable;
            short off2 = vt2[14].delta;
            void (*fp2)(void *, float *) = (void (*)(void *, float *))vt2[14].pfn;
            fp2((char *)a0 + off2, buf);
        }
        a0->base.flags2 = a0->base.flags2 & ~0x100;
        a0->open = 1;
        a0->base.mode = 3;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}
__attribute__((section(".text.cOm5a_setCloseFix")))
void cOm5a_setCloseFix(cOm5a *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 1) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
        if (a0->openType == 0) {
            buf[1] = buf[1] - a0->unk790;
        } else {
            buf[1] = buf[1] + a0->unk790;
        }
        {
            cVtEnt *vt2 = a0->base.vtable;
            short off2 = vt2[14].delta;
            void (*fp2)(void *, float *) = (void (*)(void *, float *))vt2[14].pfn;
            fp2((char *)a0 + off2, buf);
        }
        a0->base.flags2 = a0->base.flags2 | 0x100;
        a0->open = 0;
        a0->base.mode = 0;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}
__attribute__((section(".text.cOm5a_setFaceClose")))
void cOm5a_setFaceClose(cOm5a *a0) {
    cDamageTake *p;
    a0->faceState = 2;
    a0->unk604 = 0.0f;
    p = a0->take;
    if (p != 0) {
        cDamageUnit_SetDamageCollActive((cDamageUnit *)p, 0);
    }
}

