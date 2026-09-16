/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void func_001646C0(void *a0, void *a1, float f12);
extern char D_003BD880[];
extern float D_003BD9D0;
extern float D_003BD9D4;
extern char D_00567D70[];
typedef struct { float f[4]; } F4;
extern F4 D_0041F630[];
extern int D_007474A0;

__attribute__((section(".text.func_00163840")))
void func_00163840(void *a0)
{
    char *s1 = (char *)a0;
    unsigned char frame[0x20] __attribute__((aligned(16)));

    VU0_LQC2(4, D_003BD880, 0);
    VU0_SQC2(4, frame, 0);

    switch (*(char *)(s1 + 0x5C)) {
    case 0:
        D_003BD9D0 = 0.0f;
        (*(unsigned char *)(s1 + 0x5C))++;
        /* fallthrough */
    case 1:
        if (*(char *)(s1 + 0xF0) == -1) {
            (*(unsigned char *)(s1 + 0x5C))++;
            break;
        }
        {
            float *o = (float *)(frame + 0x10);

            func_001646C0(o, D_00567D70,
                          *(float *)(s1 + 0x120)
                              + (*(float *)(s1 + 0x124) - *(float *)(s1 + 0x120))
                                    * D_003BD9D0);
            if ((float *)frame != o) {
                *(float *)(frame + 0x0) = *(float *)(frame + 0x10);
                *(float *)(frame + 0x4) = *(float *)(frame + 0x14);
                *(float *)(frame + 0x8) = *(float *)(frame + 0x18);
            }
        }
        *(float *)(*(char **)(s1 + 0x80) + 0x38) = *(float *)(frame + 0x0);
        *(float *)(*(char **)(s1 + 0x80) + 0x3C) = *(float *)(frame + 0x4) - 16.0f;
        D_003BD9D0 = D_003BD9D0 + 0.01f;
        {
            char *p = *(char **)(s1 + 0xDC);

            *(float *)(p + 0x38) =
                D_003BD9D0 * 623.0f + *(float *)(*(char **)(p + 0x1C) + 8);
        }
        if (1.0f < D_003BD9D0) {
            char *p;

            D_003BD9D4 = *(float *)(s1 + 0x124);
            p = *(char **)(s1 + 0x80);
            *(float *)(s1 + 0x128) = *(float *)(p + 0x38);
            *(float *)(s1 + 0x12C) = *(float *)(p + 0x3C);
            (*(unsigned char *)(s1 + 0x5C))++;
        }
        break;
    case 2:
    {
        char *q;

        *(unsigned int *)(*(char **)(s1 + 0xE0) + 0x2C) &= 0xF7FFFFFFU;
        *(unsigned int *)(*(char **)(s1 + 0xC4) + 0x2C) &= 0xF7FFFFFFU;
        *(int *)(*(char **)(s1 + 0xCC) + 0x2C) |= 0x8000000;
        *(int *)(*(char **)(s1 + 0xD8) + 0x2C) |= 0x8000000;
        *(int *)(*(char **)(s1 + 0xD4) + 0x2C) |= 0x8000000;
        *(int *)(*(char **)(s1 + 0xD0) + 0x2C) |= 0x8000000;
        switch (*(short *)(s1 + 0x130)) {
        case 0:
        {
            char *g = (char *)&D_007474A0;
            *(float *)(*(char **)(s1 + 0xC8) + 0x3C) =
                D_0041F630[*(int *)(g + 0x56C)].f[0];
            q = *(char **)(s1 + 0xCC);
            *(unsigned int *)(q + 0x2C) &= 0xF7FFFFFFU;
            *(unsigned char *)(s1 + 0x132) = 0;
            break;
        }
        case 1:
        {
            char *g = (char *)&D_007474A0;
            *(float *)(*(char **)(s1 + 0xC8) + 0x3C) =
                D_0041F630[*(int *)(g + 0x56C)].f[1];
            q = *(char **)(s1 + 0xD0);
            *(unsigned int *)(q + 0x2C) &= 0xF7FFFFFFU;
            *(unsigned char *)(s1 + 0x132) = 0;
            break;
        }
        case 2:
        {
            char *g = (char *)&D_007474A0;
            *(float *)(*(char **)(s1 + 0xC8) + 0x3C) =
                D_0041F630[*(int *)(g + 0x56C)].f[2];
            q = *(char **)(s1 + 0xD4);
            *(unsigned int *)(q + 0x2C) &= 0xF7FFFFFFU;
            *(unsigned char *)(s1 + 0x132) = 1;
            break;
        }
        case 3:
        {
            char *g = (char *)&D_007474A0;
            *(float *)(*(char **)(s1 + 0xC8) + 0x3C) =
                D_0041F630[*(int *)(g + 0x56C)].f[3];
            q = *(char **)(s1 + 0xD8);
            *(unsigned int *)(q + 0x2C) &= 0xF7FFFFFFU;
            *(unsigned char *)(s1 + 0x132) = 1;
            break;
        }
        }
        if (*(unsigned char *)(s1 + 0x132) == 0) {
            *(float *)(*(char **)(s1 + 0x80) + 0x38) = *(float *)(s1 + 0x128);
            *(float *)(*(char **)(s1 + 0x80) + 0x3C) = *(float *)(s1 + 0x12C);
        }
        if (*(unsigned char *)(s1 + 0x132) == 1) {
            *(float *)(*(char **)(s1 + 0x80) + 0x38) = 255.0f;
            *(float *)(*(char **)(s1 + 0x80) + 0x3C) = 283.0f;
        }
        {
            char *g = (char *)&D_007474A0;

            if (*(long *)(g + 0x1A0) & 0x10000000)
                (*(unsigned char *)(s1 + 0x5C))++;
        }
        break;
    }
    case 3:
        (*(unsigned char *)(s1 + 0x5C))++;
        break;
    case 4:
        *(unsigned char *)(s1 + 0x5C) = 0;
        (*(unsigned char *)(s1 + 0x5B))++;
        break;
    }

    if (*(char *)(s1 + 0x5C) != 1)
        D_003BD9D0 = D_003BD9D0 + 0.01f;
    {
        char *p = *(char **)(s1 + 0xDC);

        *(float *)(p + 0x38) =
            D_003BD9D0 * 623.0f + *(float *)(*(char **)(p + 0x1C) + 8);
    }
    if (2.0f < D_003BD9D0)
        D_003BD9D0 = 0.0f;
}
