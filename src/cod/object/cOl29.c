/* TU: cOl29 [object] - recovered C++ class. */
#include "godhand/vu0.h"
#include "include_asm.h"
#include "godhand/cOmBase.h"

/* The cOl29 record as far as its methods reach. The base is cOmBase, as for
 * the other cOl* objects (cOl0e.h). */
typedef struct cOl29 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x764 - 0x5E0];
    unsigned char open;                 /* 0x764 what cOl29::isOpen returns: 1 after setOpenFix, 0 after setCloseFix */
} cOl29;

__attribute__((section(".text.cOl29_setOpen")))
void cOl29_setOpen(cOl29 *a0)
{
    if (a0->open == 0) {
        a0->base.stepArg = 0;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.mode = 1;
    }
}

__attribute__((section(".text.cOl29_setClose")))
void cOl29_setClose(cOl29 *a0)
{
    if (a0->open == 1) {
        a0->base.stepArg = 0;
        a0->base.phase = 0;
        a0->base.step = 0;
        a0->base.mode = 2;
    }
}

__attribute__((section(".text.cOl29_isOpen")))
unsigned char cOl29_isOpen(cOl29 *a0) {
    return a0->open;
}

__attribute__((section(".text.cOl29_setOpenFix")))
void cOl29_setOpenFix(cOl29 *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 0) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
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
__attribute__((section(".text.cOl29_setCloseFix")))
void cOl29_setCloseFix(cOl29 *a0) {
    float buf[4] __attribute__((aligned(16)));
    if (a0->open == 1) {
        cVtEnt *vt = a0->base.vtable;
        short off = vt[16].delta;
        void *(*fp)(void *) = (void *(*)(void *))vt[16].pfn;
        void *src = fp((char *)a0 + off);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, buf, 0);
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
