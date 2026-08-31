/* sn-2.95.3-136 matched TU. */

extern float Adjust_theta(float);

/* sn-2.95.3-136 matched TU. */



#include "godhand/vu0.h"

__attribute__((section(".text.func_001AADE0")))
void func_001AADE0(void *a0)
{
    char *s0 = (char *)a0;
    float b0[4];
    float b1[4];
    char *o;
    char *o3;
    int idx;
    int nf;

    o = *(char **)(s0 + 0x9A0);
    if (o == 0) return;
    idx = *(int *)(s0 + 0x9A4);
    if (idx >= 0) {
        unsigned char ok;
        int cnt;
        char *obj;

        ok = ((*(int *)b0 = cnt = *(unsigned char *)(o + 0x2B4)), (idx < cnt));
        if (ok) obj = *(char **)(*(int *)(o + 0x278) + idx * 4);
        else obj = 0;
        if (obj != 0) {
            char *d;
            char *dd;
            char *ss;
            float *v = b1;

            {
                float x = *(float *)(obj + 0xB0);
                float y = *(float *)(obj + 0xB4);
                float z = *(float *)(obj + 0xB8);
                b1[0] = x;
                b1[1] = y;
                b1[2] = z;
            }
            v[3] = 1.0f;
            d = *(char **)(s0 + 0xF0);
            if (d != (char *)v) {
                *(float *)(d + 0) = b1[0];
                *(float *)(d + 4) = b1[1];
                *(float *)(d + 8) = b1[2];
            }
            dd = s0 + 0x100;
            ss = obj + 0x100;
            if (dd != ss) {
                *(float *)(s0 + 0x100) = *(float *)(obj + 0x100);
                *(float *)(dd + 4) = *(float *)(ss + 4);
                *(float *)(dd + 8) = *(float *)(ss + 8);
            }
        }
        {
            char *p0;
            char *q0;

            p0 = *(char **)(s0 + 0xF0);
            do { } while (0);
            q0 = s0 + 0x9B0;
            VU0_LQC2(4, p0, 0);
            VU0_LQC2(5, q0, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p0, 0);
        }
        *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + *(float *)(s0 + 0x9C4);
    } else {
        do {
        char *d;
        float *w = b0;
        char *o2;
        char *dd;
        char *ss;

        {
            float x = *(float *)(o + 0xB0);
            float y = *(float *)(o + 0xB4);
            float z = *(float *)(o + 0xB8);
            b0[0] = x;
            b0[1] = y;
            b0[2] = z;
        }
        w[3] = 1.0f;
        d = *(char **)(s0 + 0xF0);
        if (d != (char *)w) {
            *(float *)(d + 0) = b0[0];
            *(float *)(d + 4) = b0[1];
            *(float *)(d + 8) = b0[2];
        }
        {
            char *p1;
            char *q1;

            p1 = *(char **)(s0 + 0xF0);
            do { } while (0);
            q1 = s0 + 0x9B0;
            VU0_LQC2(4, p1, 0);
            VU0_LQC2(5, q1, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p1, 0);
        }
        o2 = *(char **)(s0 + 0x9A0);
        dd = s0 + 0x100;
        ss = o2 + 0x100;
        if (dd != ss) {
            *(float *)(s0 + 0x100) = *(float *)(o2 + 0x100);
            *(float *)(dd + 4) = *(float *)(ss + 4);
            *(float *)(dd + 8) = *(float *)(ss + 8);
        }
        *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + *(float *)(s0 + 0x9C4);
        } while (0);
    }
    *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
    o3 = *(char **)(s0 + 0x9A0);
    if ((*(int *)(o3 + 0x250) & 2) != 0) {
        nf = *(int *)(s0 + 0x250) | 2;
    } else {
        int f = *(int *)(s0 + 0x250) & 0xFFFFFFFDU;

        *(int *)(s0 + 0x250) = f;
        *(float *)(s0 + 0x24C) = *(float *)(o3 + 0x24C);
        if ((*(int *)(o3 + 0x250) & 0x10) != 0) {
            nf = f | 0x10;
        } else {
            nf = f & 0xFFFFFFEFU;
        }
    }
    *(int *)(s0 + 0x250) = nf;
}
