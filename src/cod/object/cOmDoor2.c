/* TU: cOmDoor2 [object] - recovered C++ class. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

/* The cOmDoor2 record as far as its methods reach. The base is cOmBase, the
 * base of the cOm* map objects (cOmBase.h). */
typedef struct cOmDoor2 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x770 - 0x5E0];
    float openHeight;                   /* 0x770 setOpenFix and setCloseFix move the door by this much in y */
    unsigned char open;                 /* 0x774 1 after setOpenFix, 0 after setCloseFix */
    char unk775[3];
    int openType;                       /* 0x778 setOpenType: 0 opens upward, otherwise downward */
} cOmDoor2;

__attribute__((section(".text.cOmDoor2_setOpen")))
void cOmDoor2_setOpen(cOmDoor2 *a0) {
    if (a0->open == 0) {
        a0->base.mode = 1;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}

__attribute__((section(".text.cOmDoor2_setClose")))
void cOmDoor2_setClose(cOmDoor2 *a0) {
    if (a0->open == 1) {
        a0->base.mode = 2;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}
#include "include_asm.h"

__attribute__((section(".text.cOmDoor2_setOpenFix")))
void cOmDoor2_setOpenFix(cOmDoor2 *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 0) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
        if (a0->openType == 0) {
            buf[1] = buf[1] + a0->openHeight;
        } else {
            buf[1] = buf[1] - a0->openHeight;
        }
        {
            cVtEnt *vt2 = a0->base.vtable;
            short off2 = vt2[14].delta;
            void (*fp2)(void *, float *) = (void (*)(void *, float *))vt2[14].pfn;
            fp2((char *)a0 + off2, buf);
        }
        a0->open = 1;
        a0->base.mode = 0;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}


__attribute__((section(".text.cOmDoor2_setCloseFix")))
void cOmDoor2_setCloseFix(cOmDoor2 *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 1) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
        if (a0->openType == 0) {
            buf[1] = buf[1] - a0->openHeight;
        } else {
            buf[1] = buf[1] + a0->openHeight;
        }
        {
            cVtEnt *vt2 = a0->base.vtable;
            short off2 = vt2[14].delta;
            void (*fp2)(void *, float *) = (void (*)(void *, float *))vt2[14].pfn;
            fp2((char *)a0 + off2, buf);
        }
        a0->open = 0;
        a0->base.mode = 0;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.stepArg = 0;
    }
}


__attribute__((section(".text.cOmDoor2_setOpenType")))
void cOmDoor2_setOpenType(cOmDoor2 *a0, int a1) {
    if (a0->openType == a1) {
        return;
    }
    if (a0->open == 1) {
        cOmDoor2_setCloseFix(a0);
        a0->openType = a1;
        cOmDoor2_setOpenFix(a0);
    } else {
        a0->openType = a1;
    }
}

