/* TU: cOl21 [object] - recovered C++ class. */
extern float fRand0_1(void);
extern unsigned int Rnd(void);

#include "godhand/vu0.h"

static __inline__ void cpy3(float *d, float *s) {
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.cOl21_initMove")))
void cOl21_initMove(char *s0, float *s1, float *a2, float ang) {
    unsigned char frame[0x20];
    float r, k, dx, dz;

    cpy3((float *)(s0 + 0x610), *(float **)(s0 + 0xF0));
    cpy3((float *)(s0 + 0x620), s1);
    cpy3((float *)(s0 + 0x630), a2);

    VU0_SQC2_VF0(frame, 0x10);
    VU0_LQC2(4, a2, 0);
    VU0_LQC2(5, s1, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, frame + 0x10, 0);
    VU0_SQC2(4, frame, 0);

    r = fRand0_1();
    k = ang * r;
    dx = *(float *)(frame + 0) / ang;
    *(int *)(s0 + 0x644) = 0;
    dz = *(float *)(frame + 8) / ang;
    *(float *)(s0 + 0x640) = dx;
    *(float *)(s0 + 0x648) = dz;
    (*(float **)(s0 + 0xF0))[0] = s1[0] + *(float *)(s0 + 0x640) * k;
    (*(float **)(s0 + 0xF0))[2] = s1[2] + *(float *)(s0 + 0x648) * k;
    if (((Rnd() ^ 1) & 1) != 0) {
        *(float *)(s0 + 0x640) = -*(float *)(s0 + 0x640);
        *(float *)(s0 + 0x648) = -*(float *)(s0 + 0x648);
    }
}
