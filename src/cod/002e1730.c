/* sn-2.95.3-136 matched TU. */

extern void CopyVec16From20_B62E0(void *dst, void *self);
extern void cNode_setLocalScale(void *self, void *v);
extern float capVu0Sin(float f12);

#include "godhand/vu0.h"

struct VtEnt { short delta; short index; void *pfn; };
typedef struct { char b[0x10]; } C16;

#define VCALL16(o) \
    ((void (*)(void *))(*(struct VtEnt **)((o) + 0xF0))[16].pfn)((o) + (*(struct VtEnt **)((o) + 0xF0))[16].delta)

__attribute__((section(".text.func_002E1730")))
void func_002E1730(void *a0)
{
    char buf[0x30] __attribute__((aligned(16)));
    char *s0 = (char *)a0;
    int f;
    unsigned char s1;
    int s2;
    float h;
    float t;
    float r, g, b, a;

    if (*(int *)(s0 + 0x11C) & 0x800000)
        return;
    f = *(int *)(*(char **)(s0 + 0x110) + 4);
    if (f < 0) {
        if (!(f & 0x40000000))
            VCALL16(s0);
        CopyVec16From20_B62E0(buf, s0);
        s1 = *(unsigned char *)(s0 + 0x247);
        s2 = *(int *)(s0 + 0x118);
        *(C16 *)(buf + 0x10) = *(C16 *)(s0 + 0x188);
        VU0_LQC2(4, buf, 0);
        VU0_SQC2(4, buf, 0x20);
        {
            char *p = *(char **)(s0 + 0x110);

            h = *(float *)(p + 0x29C);
            if (*(unsigned char *)(p + 0x295) != 0)
                h = h + capVu0Sin(*(float *)(s0 + 0x258)) * (float)*(unsigned char *)(*(char **)(s0 + 0x110) + 0x294) * 0.0784313753f;
        }
        t = h * 0.0500000007f + 1.0f;
        *(float *)(buf + 0x20) = *(float *)(buf + 0x20) * t;
        *(float *)(buf + 0x24) = *(float *)(buf + 0x24) * t;
        cNode_setLocalScale(s0, buf + 0x20);
        {
            char *p = *(char **)(s0 + 0x110);

            *(unsigned char *)(s0 + 0x247) = *(unsigned char *)(p + 0x296);
            if (*(int *)(p + 4) & 0x8000000)
                *(int *)(s0 + 0x118) = *(int *)(s0 + 0x25C);
        }
        {
            char *p;

            if (*(int *)(*(char **)(s0 + 0x110) + 4) & 0x20000000) {
                g = 1.0f;
                r = g;
                b = g;
            } else {
                r = *(float *)(buf + 0x10);
                g = *(float *)(buf + 0x14);
                b = *(float *)(buf + 0x18);
            }
            p = *(char **)(s0 + 0x110);
            a = 1.0f;
            if (!(*(int *)(p + 4) & 0x10000000))
                a = *(float *)(buf + 0x1C);
            *(float *)(s0 + 0x188) = (float)*(unsigned char *)(p + 0x298) * 0.00392156886f * r;
            *(float *)(s0 + 0x18C) = (float)*(unsigned char *)(p + 0x299) * 0.00392156886f * g;
            *(float *)(s0 + 0x190) = (float)*(unsigned char *)(p + 0x29A) * 0.00392156886f * b;
            if (*(unsigned char *)(p + 0x29B) == 0)
                *(float *)(s0 + 0x194) = a;
            else
                *(float *)(s0 + 0x194) = a * (float)*(unsigned char *)(p + 0x29B) * 0.00392156886f;
        }
        VCALL16(s0);
        cNode_setLocalScale(s0, buf);
        *(C16 *)(s0 + 0x188) = *(C16 *)(buf + 0x10);
        *(unsigned char *)(s0 + 0x247) = s1;
        *(int *)(s0 + 0x118) = s2;
        if (*(int *)(*(char **)(s0 + 0x110) + 4) & 0x40000000)
            VCALL16(s0);
    } else {
        VCALL16(s0);
    }
}
