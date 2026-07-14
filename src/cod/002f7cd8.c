/* sn-2.95.3-136 matched TU. */

extern void *InitObject_2FBCC8(void *this);
extern unsigned char D_0044F7D0[];

#include "godhand/vu0.h"




__attribute__((section(".text.func_002F7CD8")))
void *func_002F7CD8(unsigned char *this) {
    unsigned char *p;
    int i;

    InitObject_2FBCC8(this);

    *(int *)(this + 0x2B0) = 0;
    *(float *)(this + 0x2D4) = 1.0f;
    *(unsigned char **)(this + 0xF0) = D_0044F7D0;
    *(int *)(this + 0x2B4) = 0;
    *(int *)(this + 0x2B8) = 0;
    *(int *)(this + 0x2BC) = 0;
    *(int *)(this + 0x2C0) = 0;
    *(int *)(this + 0x2C4) = 0;
    *(int *)(this + 0x2C8) = 0;
    *(int *)(this + 0x2D8) = 0;
    *(int *)(this + 0x2DC) = 0;

    p = this + 0x320;
    i = 2;
    while (i--) {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    }

    VU0_SQC2_VF0(this, 0x340);
    VU0_SQC2_VF0(this, 0x350);

    *(int *)(this + 0x2BC) = 0;
    *(int *)(this + 0x360) = 0;
    *(int *)(this + 0x364) = 0;
    *(int *)(this + 0x368) = 0;
    *(int *)(this + 0x36C) = 0;
    *(int *)(this + 0x370) = 0;

    return this;
}
