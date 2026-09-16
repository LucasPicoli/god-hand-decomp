/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"

extern void func_001645E0(void *a0);
extern int IsSet_Field_A4_1FBFD0(void *a0, int a1);
extern void Set_Field_0_4_8_1646B0(void *a0, void *a1, void *a2, int a3);
extern void func_001646C0(void *a0, void *a1, float f);
extern unsigned char *D_00586B28;
extern unsigned short D_00583EEC;
extern char *D_003C23A4;
extern char D_00569B70[];
extern char D_00567D70[];
extern char D_00567D80[];
extern char D_00567E80[];
extern float D_003BD9A8[];

static __inline__ int MakeId(unsigned short h)
{
    if ((h >> 8) != 0) {
        return ((h >> 8) << 4) + ((h & 0xFF) + 0x2013);
    }
    return 0x20A3;
}

__attribute__((section(".text.func_00162C98")))
void func_00162C98(void *a0)
{
    char *s0 = (char *)a0;
    int id;
    unsigned int i;
    char *base;
    float v[4] __attribute__((aligned(16)));
    float t[4] __attribute__((aligned(16)));

    func_001645E0(s0);
    if (*(int *)D_00586B28 & 1) {
        id = MakeId(*(unsigned short *)(D_00586B28 + 8));
    } else {
        id = MakeId(D_00583EEC);
    }
    if ((unsigned int)id >= 0x20A4) {
        id = 0x20A3;
    }
    *(unsigned short *)(D_003C23A4 + 0xBEE) = id;
    *(unsigned short *)(*(char **)(s0 + 0xE4) + 0x90) = 0x2022;
    *(unsigned short *)(*(char **)(s0 + 0xE8) + 0x90) = 0x2022;
    *(char *)(s0 + 0xF0) = 1;
    while (*(char *)(s0 + 0xF0) < 8
           && IsSet_Field_A4_1FBFD0(D_00569B70,
                                    (unsigned short)*(char *)(s0 + 0xF0)) != 0) {
        *(char *)(s0 + 0xF0) = *(unsigned char *)(s0 + 0xF0) + 1;
    }
    *(char *)(s0 + 0xF0) = *(unsigned char *)(s0 + 0xF0) - 1;

    base = s0 + 0x80;
    for (i = 1; i < 9; i++) {
        int k = (i + 8) * 4;
        char *w = *(char **)(base + k);

        *(int *)(w + 0x2C) = *(int *)(w + 0x2C) | 0x08000000;
        if (i >= (unsigned int)*(char *)(s0 + 0xF0)) {
            continue;
        }
        switch (i - 1) {
        case 0:
            *(int *)(*(char **)(s0 + 0x84) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xA4) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 1:
            *(int *)(*(char **)(s0 + 0x88) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xA8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 2:
            *(int *)(*(char **)(s0 + 0x8C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xAC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 3:
            *(int *)(*(char **)(s0 + 0x90) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xB0) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 4:
            *(int *)(*(char **)(s0 + 0x94) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xB4) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0x98) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 5:
            *(int *)(*(char **)(s0 + 0x9C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xB8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 6:
            *(int *)(*(char **)(s0 + 0xA0) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(char **)(s0 + 0xBC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 7:
            *(int *)(*(char **)(s0 + 0xC0) + 0x2C) &= 0xF7FFFFFF;
            break;
        }
    }

    Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
    switch (*(char *)(s0 + 0xF0)) {
    case 0:
        Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
        *(float *)(s0 + 0x120) = D_003BD9A8[1];
        *(float *)(s0 + 0x124) = D_003BD9A8[1];
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
        *(float *)(s0 + 0x120) = D_003BD9A8[*(char *)(s0 + 0xF0)];
        *(float *)(s0 + 0x124) = D_003BD9A8[*(char *)(s0 + 0xF0) + 1];
        break;
    case 5:
        Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
        *(float *)(s0 + 0x120) = D_003BD9A8[*(char *)(s0 + 0xF0)];
        *(float *)(s0 + 0x124) = D_003BD9A8[*(char *)(s0 + 0xF0) + 2];
        break;
    case 6:
    case 7:
        Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
        *(float *)(s0 + 0x120) = D_003BD9A8[*(char *)(s0 + 0xF0) + 1];
        *(float *)(s0 + 0x124) = D_003BD9A8[*(char *)(s0 + 0xF0) + 2];
        break;
    case 8:
        Set_Field_0_4_8_1646B0(D_00567D70, D_00567D80, D_00567E80, 0x10);
        *(float *)(s0 + 0x120) = D_003BD9A8[*(char *)(s0 + 0xF0) + 1];
        *(float *)(s0 + 0x124) = D_003BD9A8[*(char *)(s0 + 0xF0) + 1];
        break;
    }

    VU0_SQC2_VF0(v, 0);
    func_001646C0(t, D_00567D70, *(float *)(s0 + 0x120));
    if (v != t) {
        v[0] = t[0];
        v[1] = t[1];
        v[2] = t[2];
    }
    *(float *)(*(char **)(s0 + 0x80) + 0x38) = v[0];
    *(float *)(*(char **)(s0 + 0x80) + 0x3C) = v[1] - 16.0f;
}
