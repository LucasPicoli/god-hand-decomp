/* sn-2.95.3-136 matched TU. */

extern int D_003C1180;
extern int D_003C118C;
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"





__attribute__((section(".text.cCamera_getScreenPos")))
void *cCamera_getScreenPos(void *out, void *m0, void *v0)
{
    float buf[4];

    VU0_SQC2_VF0(buf, 0);
    sceVu0ApplyMatrix(buf, m0, v0);
    buf[0] = buf[0] / buf[3] + (float)(D_003C1180 / 2 - 0x800);
    buf[1] = buf[1] / buf[3] + (float)(D_003C118C / 2 - 0x800);
    buf[2] = buf[3];
    VU0_LQC2(4, buf, 0);
    VU0_SQC2(4, out, 0);
    return out;
}
