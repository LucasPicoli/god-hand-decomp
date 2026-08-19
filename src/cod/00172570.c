/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0LengthSq(void *a0);
extern float sqrtf(float x);

/* sn-2.95.3-136 matched TU. */





#include "godhand/vu0.h"

typedef void *(*vfn)(void *);

__attribute__((section(".text.func_00172570")))
void func_00172570(void *a0) {
    char *s = (char *)a0;
    char buf[32] __attribute__((aligned(16)));
    float t = 1.0f;
    float dist;
    int n;

    {
        void *o = Obj0000_Get_D_00747A94_2DB6B0();
        char *vt = *(char **)((char *)o + 0x214);
        void *p1 = (*(vfn *)(vt + 0x84))((char *)o + *(short *)(vt + 0x80));
        char *vt2 = *(char **)(s + 0x214);
        void *p2 = (*(vfn *)(vt2 + 0x84))(s + *(short *)(vt2 + 0x80));

        VU0_SQC2_VF0(buf, 0x10);
        VU0_LQC2(4, p1, 0x0);
        VU0_LQC2(5, p2, 0x0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0x0);
        VU0_SQC2(4, buf, 0x0);
    }

    dist = __builtin_sqrtf(capVu0LengthSq(buf));

    if (!(15.0f < dist)) {
        if (5.0f < dist) {
            t = (dist - 5.0f) / 10.0f;
        } else {
            t = 0.0f;
        }
    }

    n = (int)((1.0f - t) * 60.0f) + 1;
    if (*(short *)(s + 0xD94) < n) {
        *(short *)(s + 0xD94) = n;
    }

    switch (*(unsigned char *)(s + 0x2F5)) {
    case 0:
        *(char *)(s + 0x2F6) = 0;
        *(char *)(s + 0x2F5) = 1;
        *(char *)(s + 0x2F7) = 0;
        /* fall through */
    case 1:
        if (dist < 15.0f) {
            *(char *)(s + 0x2F6) = 0;
            *(char *)(s + 0x2F5) = 2;
            *(char *)(s + 0x2F7) = 0;
            *(short *)(s + 0xD94) = 0;
        }
        break;
    case 2:
        {
            int m = *(unsigned short *)(s + 0xD94) + 1;
            short c;
            float v;

            *(short *)(s + 0xD94) = m;
            c = m;
            v = (float)c / 60.0f;
            v = 1.0f - v;
            if (t < v) {
                v = t;
            }
            *(float *)(s + 0x24C) = v;
            if (!(c < 0x3D)) {
                *(int *)(s + 0x24C) = 0;
                *(char *)(s + 0x2F5) = 3;
                *(char *)(s + 0x2F6) = 0;
                *(char *)(s + 0x2F7) = 0;
            }
        }
        break;
    case 3:
        *(int *)(s + 0x24C) = 0;
        if (18.0f < dist) {
            *(char *)(s + 0x2F6) = 0;
            *(char *)(s + 0x2F5) = 4;
            *(char *)(s + 0x2F7) = 0;
            *(short *)(s + 0xD94) = 0;
        }
        break;
    case 4:
        {
            int m = *(unsigned short *)(s + 0xD94) + 1;
            short c;
            float v;

            *(short *)(s + 0xD94) = m;
            c = m;
            v = (float)c / 60.0f;
            if (t < v) {
                v = t;
            }
            *(float *)(s + 0x24C) = v;
            if (!(c < 0x3D)) {
                *(char *)(s + 0x2F5) = 1;
                *(float *)(s + 0x24C) = 1.0f;
                *(char *)(s + 0x2F6) = 0;
                *(char *)(s + 0x2F7) = 0;
            }
            if (dist < 15.0f) {
                *(short *)(s + 0xD94) = 0x3C - *(unsigned short *)(s + 0xD94);
                *(char *)(s + 0x2F5) = 2;
                *(char *)(s + 0x2F7) = 0;
                *(char *)(s + 0x2F6) = 0;
            }
        }
        break;
    }
}
