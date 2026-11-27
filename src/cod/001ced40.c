#include "godhand/cGameObj.h"
/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */




static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

__attribute__((section(".text.func_001CED40")))
void func_001CED40(void *a0) {
    cGameObj *s0 = a0;
    unsigned char frame[0x10];
    float r;
    char *e;

    r = cEmManage_GetSpeedRate(&D_005864F0);
    e = (char *)GetLayerObj(s0, (int *)frame, 1);
    switch (s0->step) {
    case 0:
        s0->unk56A = 0;
        *(int *)((char *)s0 + 0x24C) = 0;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 1:
        {
            float t;
            int fl;

            t = s0->tint.w;
            t += r * 0.1f;
            fl = s0->objFlags | 0x10;
            s0->objFlags = fl;
            s0->tint.w = t;
            if (t > 1.0f) {
                s0->tint.w = 1.0f;
                s0->objFlags = fl & 0xFFFFFFEF;
                s0->step = s0->step + 1;
            }
        }
        break;
    case 2:
        *(float *)((char *)s0 + 0x674) = 30.0f;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 3:
        {
            if (e != 0) {
                float *p;
                float t;

                p = *(float **)(e + 0xD0);
                *p = *p + r * 0.05f;
                t = *(float *)((char *)s0 + 0x674);
                t -= r;
                *(float *)((char *)s0 + 0x674) = t;
                if (!(t <= 0.0f)) {
                    break;
                }
            }
            s0->step = s0->step + 1;
        }
        break;
    case 4:
        *(float *)((char *)s0 + 0x674) = 60.0f;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 5:
        {
            float t;

            t = *(float *)((char *)s0 + 0x674);
            t -= r;
            *(float *)((char *)s0 + 0x674) = t;
            if (t <= 0.0f) {
                s0->step = s0->step + 1;
            }
        }
        break;
    case 6:
        s0->step = s0->step + 1;
        /* fallthrough */
    case 7:
        {
            float t;

            t = s0->tint.w;
            t -= r * 0.1f;
            s0->objFlags = s0->objFlags | 0x10;
            s0->tint.w = t;
            if (t < 0.0f) {
                s0->tint.w = 0.0f;
                s0->mode = 1;
                s0->phase = 0;
                s0->step = 0;
                s0->stepArg = 0;
            }
        }
        break;
    }
}
