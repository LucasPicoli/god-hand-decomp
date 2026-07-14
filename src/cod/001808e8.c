/* sn-2.95.3-136 matched TU. */

extern int InitFields_1B6E90(void *);
extern char D_004226A8[];

#include "godhand/vu0.h"




__attribute__((section(".text.func_001808E8")))
void *func_001808E8(void *arg) {
    char *self = (char *)arg;
    char *q;
    int *r;
    unsigned int i;

    InitFields_1B6E90(self);
    *(char **)(self + 0x214) = D_004226A8;
    q = self + 0x610;
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    VU0_SQC2_VF0(self, 0x680);
    VU0_SQC2_VF0(self, 0x690);
    VU0_SQC2_VF0(self, 0x6A0);
    VU0_SQC2_VF0(self, 0x6B0);
    VU0_SQC2_VF0(self, 0x6C0);
    VU0_SQC2_VF0(self, 0x6D0);
    VU0_SQC2_VF0(self, 0x6E0);
    VU0_SQC2_VF0(self, 0x6F0);
    VU0_SQC2_VF0(self, 0x700);
    VU0_SQC2_VF0(self, 0x710);
    VU0_SQC2_VF0(self, 0x720);
    VU0_SQC2_VF0(self, 0x730);

    *(char *)(q + 0x0) = 0;
    *(char *)(q + 0x1) = 0;
    *(char *)(q + 0x2) = 0;
    *(int *)(q + 0x4) = 0;
    *(int *)(q + 0x8) = 0;
    *(int *)(q + 0x30) = 0;
    *(int *)(q + 0x34) = 0;
    *(int *)(q + 0x38) = 0;
    *(int *)(q + 0x3C) = 0;
    *(int *)(q + 0x130) = 0;
    *(int *)(q + 0x134) = 0;
    *(int *)(q + 0x138) = 0;
    *(int *)(q + 0x13C) = 0;

    i = 0;
    r = (int *)(q + 0xC);
    for (; i < 8; i++) {
        *r = 0;
        r++;
    }
    return self;
}
