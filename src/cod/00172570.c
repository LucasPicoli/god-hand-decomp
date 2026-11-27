/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float sqrtf(float x);

/* sn-2.95.3-136 matched TU. */





#include "godhand/vu0.h"
#include "godhand/cObj.h"
#include "godhand/player.h"

typedef void *(*vfn)(void *);

__attribute__((section(".text.func_00172570")))
void func_00172570(void *a0) {
    cObj *s = a0;
    char buf[32] __attribute__((aligned(16)));
    float t = 1.0f;
    float dist;
    int n;

    {
        cGameObj *o = Getplayer();
        cVtEnt *vt = o->vtable;
        void *p1 = ((vfn)vt[16].pfn)((char *)o + vt[16].delta);
        cVtEnt *vt2 = s->vtable;
        void *p2 = ((vfn)vt2[16].pfn)((char *)s + vt2[16].delta);

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
    if (*(short *)((char *)s + 0xD94) < n) {
        *(short *)((char *)s + 0xD94) = n;
    }

    switch (s->phase) {
    case 0:
        s->step = 0;
        s->phase = 1;
        s->stepArg = 0;
        /* fall through */
    case 1:
        if (dist < 15.0f) {
            s->step = 0;
            s->phase = 2;
            s->stepArg = 0;
            *(short *)((char *)s + 0xD94) = 0;
        }
        break;
    case 2:
        {
            int m = *(unsigned short *)((char *)s + 0xD94) + 1;
            short c;
            float v;

            *(short *)((char *)s + 0xD94) = m;
            c = m;
            v = (float)c / 60.0f;
            v = 1.0f - v;
            if (t < v) {
                v = t;
            }
            s->tint.w = v;
            if (!(c < 0x3D)) {
                s->tint.w = 0.0f;
                s->phase = 3;
                s->step = 0;
                s->stepArg = 0;
            }
        }
        break;
    case 3:
        s->tint.w = 0.0f;
        if (18.0f < dist) {
            s->step = 0;
            s->phase = 4;
            s->stepArg = 0;
            *(short *)((char *)s + 0xD94) = 0;
        }
        break;
    case 4:
        {
            int m = *(unsigned short *)((char *)s + 0xD94) + 1;
            short c;
            float v;

            *(short *)((char *)s + 0xD94) = m;
            c = m;
            v = (float)c / 60.0f;
            if (t < v) {
                v = t;
            }
            s->tint.w = v;
            if (!(c < 0x3D)) {
                s->phase = 1;
                s->tint.w = 1.0f;
                s->step = 0;
                s->stepArg = 0;
            }
            if (dist < 15.0f) {
                *(short *)((char *)s + 0xD94) = 0x3C - *(unsigned short *)((char *)s + 0xD94);
                s->phase = 2;
                s->stepArg = 0;
                s->step = 0;
            }
        }
        break;
    }
}
