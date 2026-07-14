/* sn-2.95.3-136 matched TU. */

extern void *InitFields_1B6E90(void *this);
extern void Obj0000_Set_Byte_54(void *obj, int v);
extern unsigned char D_00428090[];

#include "godhand/vu0.h"





__attribute__((section(".text.func_001AE798")))
void *func_001AE798(unsigned char *this) {
    unsigned char *p;
    unsigned char *q;
    int *r;
    int i;
    unsigned int j;

    p = this + 0x620;
    InitFields_1B6E90(this);

    *(unsigned char **)(this + 0x214) = D_00428090;

    i = 9;
    while (i--) {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }

    q = this + 0x990;

    VU0_SQC2_VF0(this, 0x9E0);
    VU0_SQC2_VF0(this, 0x9F0);
    VU0_SQC2_VF0(this, 0xA00);
    VU0_SQC2_VF0(this, 0xA10);
    VU0_SQC2_VF0(this, 0xA20);
    VU0_SQC2_VF0(this, 0xA30);
    VU0_SQC2_VF0(this, 0xA40);
    VU0_SQC2_VF0(this, 0xA50);
    VU0_SQC2_VF0(this, 0xA60);
    VU0_SQC2_VF0(this, 0xA70);
    VU0_SQC2_VF0(this, 0xA80);
    VU0_SQC2_VF0(this, 0xA90);
    VU0_SQC2_VF0(this, 0xAA0);
    VU0_SQC2_VF0(this, 0xAB0);

    *(unsigned char *)(this + 0x990) = 0;
    q[0x1] = 0;
    q[0x2] = 0;
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

    j = 0;
    r = (int *)(this + 0x99C);
    for (; j < 8; j++) {
        *r = 0;
        r++;
    }

    return this;
}
