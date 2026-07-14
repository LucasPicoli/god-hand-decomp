/* sn-2.95.3-136 matched TU. */

extern char *InitFields_1B6E90(void *);
extern int D_00429420;

#include "godhand/vu0.h"




__attribute__((section(".text.func_001BD580")))
void *func_001BD580(char *a0) {
    char *p;
    char *q;
    unsigned int i;

    InitFields_1B6E90(a0);
    *(int **)(a0 + 0x214) = &D_00429420;
    VU0_SQC2_VF0(a0, 0x600);
    p = a0 + 0x610;
    VU0_SQC2_VF0(a0, 0x660);
    VU0_SQC2_VF0(a0, 0x670);
    VU0_SQC2_VF0(a0, 0x680);
    VU0_SQC2_VF0(a0, 0x690);
    VU0_SQC2_VF0(a0, 0x6A0);
    VU0_SQC2_VF0(a0, 0x6B0);
    VU0_SQC2_VF0(a0, 0x6C0);
    VU0_SQC2_VF0(a0, 0x6D0);
    VU0_SQC2_VF0(a0, 0x6E0);
    VU0_SQC2_VF0(a0, 0x6F0);
    VU0_SQC2_VF0(a0, 0x700);
    VU0_SQC2_VF0(a0, 0x710);
    VU0_SQC2_VF0(a0, 0x720);
    VU0_SQC2_VF0(a0, 0x730);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x130) = 0;
    *(int *)(p + 0x134) = 0;
    *(int *)(p + 0x138) = 0;
    *(int *)(p + 0x13C) = 0;
    i = 0;
    q = p + 0xC;
    for (; i < 8; i++) {
        *(int *)q = 0;
        q += 4;
    }
    return a0;
}
