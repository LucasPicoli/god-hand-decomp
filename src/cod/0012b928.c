/* sn-2.95.3-136 matched TU. */

extern void cOmThrow_SetFall(void *p);

#include "godhand/vu0.h"



__attribute__((section(".text.func_0012B928")))
void func_0012B928(char *a0) {
    char *s0 = a0;
    char *p = *(char **)(s0 + 0x6A0);
    if (p != 0) {
        float v[4];
        VU0_SQC2_VF0(v, 0);
        v[0] = 0.0f;
        v[1] = 0.1f;
        v[2] = 0.0f;
        cOmThrow_SetFall(p);

        {
            float *dst = *(float **)(*(char **)(s0 + 0x6A0) + 0xF0);
            float *src = *(float **)(s0 + 0xF0);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
        }
        *((float *)(*(char **)(*(char **)(s0 + 0x6A0) + 0xF0)) + 1) += 1.6f;
        {
            char *q = *(char **)(s0 + 0x6A0);
            float *d = (float *)(q + 0x490);
            float *pf = *(float **)(q + 0xF0);
            if (d != pf) {
                d[0] = pf[0];
                d[1] = pf[1];
                d[2] = pf[2];
            }
            *(int *)(s0 + 0x6A0) = 0;
        }
    }
}
