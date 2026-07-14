/* sn-2.95.3-136 matched TU. */

extern void InitFields_1B6E90(void *obj);
extern int D_00422560;

#include "godhand/vu0.h"




__attribute__((section(".text.func_0017FB48")))
void *func_0017FB48(void *obj) {
    char *p;
    int i;
    unsigned int j;

    InitFields_1B6E90(obj);
    *(int **)((char *)obj + 0x214) = &D_00422560;
    p = (char *)obj + 0x600;
    i = 2;
    do {
        VU0_SQC2_VF0(p, 0x50);
        VU0_SQC2_VF0(p, 0x60);
        VU0_SQC2_VF0(p, 0x70);
        VU0_SQC2_VF0(p, 0x80);
        VU0_SQC2_VF0(p, 0x90);
        VU0_SQC2_VF0(p, 0xA0);
        VU0_SQC2_VF0(p, 0xB0);
        VU0_SQC2_VF0(p, 0xC0);
        VU0_SQC2_VF0(p, 0xD0);
        VU0_SQC2_VF0(p, 0xE0);
        VU0_SQC2_VF0(p, 0xF0);
        VU0_SQC2_VF0(p, 0x100);
        VU0_SQC2_VF0(p, 0x110);
        VU0_SQC2_VF0(p, 0x120);
        *(char *)(p + 0x0) = 0;
        *(char *)(p + 0x1) = 0;
        *(char *)(p + 0x2) = 0;
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
        for (j = 0; j < 8; j++) {
            *(int *)(p + 0xC + j * 4) = 0;
        }
        p += 0x160;
        i--;
    } while (i != -1);
    return obj;
}
