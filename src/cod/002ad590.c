/* sn-2.95.3-136 matched TU. */

extern void func_002AD748(void *a0);
extern int D_003C238C;

/* sn-2.95.3-136 candidate. */




#include "godhand/vu0.h"

__attribute__((section(".text.func_002AD590")))
void func_002AD590(void *arg, float f12) {
    char buf[0x30] __attribute__((aligned(16)));
    char *self = (char *)arg;
    int n;
    int i;
    int y;
    int x;
    float t;
    float s;
    char *elem;
    char *r10;
    char *e10;
    float *d;

    n = D_003C238C;
    t = f12 / (float)n;
    for (i = 0; i < D_003C238C; i++) {
        func_002AD748(self);
        for (y = 0; y <= *(int *)(self + 4); y++) {
            for (x = 0; x <= *(int *)(self + 0); x++) {
                elem = *(char **)(self + 0x10) +
                       (*(int *)(self + 0) * y + y + x) * 0x50;
                if (*(unsigned char *)(elem + 0x48) == 1) {
                    continue;
                }
                r10 = buf + 0x10;
                s = *(float *)(elem + 0x44);
                VU0_LQC2(4, elem + 0x30, 0x0);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, buf, 0x10);
                VU0_LOAD_SCALAR(5, s);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, r10, 0x0);
                VU0_SQC2(4, buf, 0x0);
                d = (float *)(elem + 0x20);
                if (d != (float *)buf) {
                    *(float *)(elem + 0x20) = *(float *)(buf + 0x0);
                    d[1] = *(float *)(buf + 0x4);
                    d[2] = *(float *)(buf + 0x8);
                }
                VU0_LQC2(4, buf, 0x0);
                VU0_SQC2(4, buf, 0x20);
                VU0_LQC2(4, buf, 0x20);
                VU0_LOAD_SCALAR(5, t);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x20);
                VU0_LQC2(4, buf + 0x20, 0x0);
                VU0_SQC2(4, buf, 0x10);
                e10 = elem + 0x10;
                VU0_LQC2(4, elem, 0x10);
                VU0_LQC2(5, r10, 0x0);
                VU0_VADD_XYZ(4, 4, 5);
                VU0_SQC2(4, elem, 0x10);
                VU0_LQC2(4, e10, 0x0);
                VU0_SQC2(4, buf, 0x20);
                VU0_LQC2(4, buf, 0x20);
                VU0_LOAD_SCALAR(5, t);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x20);
                VU0_LQC2(4, buf + 0x20, 0x0);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, elem, 0x0);
                VU0_LQC2(5, r10, 0x0);
                VU0_VADD_XYZ(4, 4, 5);
                VU0_SQC2(4, elem, 0x0);
            }
        }
    }
}
