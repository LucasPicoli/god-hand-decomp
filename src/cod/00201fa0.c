/* sn-2.95.3-136 matched TU. */

extern unsigned char D_004479C8[];
extern unsigned char D_0042C7F0[];

#include "godhand/vu0.h"





__attribute__((section(".text.func_00201FA0")))
void *func_00201FA0(unsigned char *this) {
    unsigned char *q;
    unsigned char *r;
    unsigned char *s;
    int i;
    int j;

    func_0028EB00(this);

    *(unsigned char **)(this + 0x214) = D_004479C8;

    VU0_SQC2_VF0(this, 0x6C0);
    VU0_SQC2_VF0(this, 0x6D0);
    s = this + 0x1620;
    VU0_SQC2_VF0(this, 0x1630);
    s[0x31] = 0xFF;
    VU0_SQC2_VF0(this, 0x1660);
    VU0_SQC2_VF0(this, 0x1680);
    VU0_SQC2_VF0(this, 0x1690);
    VU0_SQC2_VF0(this, 0x16A0);
    VU0_SQC2_VF0(this, 0x16B0);
    VU0_SQC2_VF0(this, 0x1840);

    q = this + 0x18A0;
    j = 4;
    while (j--) {
        r = q;
        i = 2;
        while (i--) {
            VU0_SQC2_VF0(r, 0x0);
            r += 0x10;
        }
        q += 0x20;
    }

    VU0_SQC2_VF0(this, 0x1950);

    *(unsigned char **)(this + 0x4AC) = D_0042C7F0;
    return this;
}
