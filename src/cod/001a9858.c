/* sn-2.95.3-136 matched TU. */

extern void *InitFields_1B6E90(void *this);
extern void Obj0000_Set_Byte_54(void *obj, int v);
extern unsigned char D_00427CF0[];

#include "godhand/vu0.h"





__attribute__((section(".text.func_001A9858")))
void *func_001A9858(unsigned char *this) {
    unsigned char *p;
    int *q;
    int i;
    int j;

    InitFields_1B6E90(this);

    *(unsigned char **)(this + 0x214) = D_00427CF0;

    VU0_SQC2_VF0(this, 0x630);

    p = this + 0x640;
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

    VU0_SQC2_VF0(this, 0x9B0);
    VU0_SQC2_VF0(this, 0x9C0);

    *(int *)(this + 0x9D0) = 0;
    *(int *)(this + 0x9D4) = 0;
    *(int *)(this + 0x9EC) = 0x4E2;
    *(int *)(this + 0x9F0) = 0x101;
    *(int *)(this + 0x9F4) = 0x4E2;
    *(int *)(this + 0x9F8) = 0x101;
    *(int *)(this + 0x604) = 0;
    *(int *)(this + 0x608) = 0;

    j = 2;
    q = (int *)(this + 0x614);
    for (; j >= 0; j--) {
        *q = 0;
        q--;
    }

    return this;
}
