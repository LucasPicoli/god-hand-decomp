/* sn-2.95.3-136 matched TU. */

extern void func_00305A18(void *);
extern char D_007419A0[];
extern char D_00743250[];
extern void sceVu0MulVector(float *v0, float *m0, float *v1);

#include "godhand/vu0.h"

__attribute__((section(".text.func_002AD238")))
void *func_002AD238(void *this, int a1, int a2, int a3, int a4, int a5) {
    char *p;
    int i;

    *(int *)((char *)this + 0xC) = 0;
    *(int *)((char *)this + 0x10) = 0;
    *(int *)((char *)this + 0x14) = 0;

    p = (char *)this + 0x20;
    for (i = 0x7F; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x10);
        p += 0x20;
    }

    *(int *)((char *)this + 0x0) = a1;
    *(int *)((char *)this + 0x4) = a2;
    *(int *)((char *)this + 0x8) = a5;
    *(int *)((char *)this + 0x10) = a3;
    *(int *)((char *)this + 0x14) = a4;
    return this;
}

#include "godhand/vu0.h"





__attribute__((section(".text.func_00307140")))
void func_00307140(int a0, int a1) {
    char *base;
    char *p;
    int i;

    if (a1 == 0xFFFF) {
        if (a0 != 0) {
            func_00305A18(D_007419A0);
            base = D_00743250;
            p = base + 0x380;
            for (i = 0x3E7; i != -1; i--) {
                VU0_SQC2_VF0(p, 0x0);
                p += 0x10;
            }
        }
    }
}

__attribute__((section(".text.func_002D8008")))
void func_002D8008(void *a0, float *a1, float *a2, int a3, float *a4) {
    float tmp[4];
    float *dst;
    float *src;
    int i;

    a1[15] = 1.0f;
    sceVu0MulVector(tmp, (float *)((char *)a0 + 0x30), a4);

    dst = (float *)((char *)a2 + 0x30);
    for (i = 3, src = tmp; i != -1; i--) {
        *dst++ = *src++;
    }
}

__attribute__((section(".text.F16toF32")))
float F16toF32(unsigned short half) {
    unsigned int h;
    unsigned int mant;
    unsigned int sign;
    unsigned int exp;
    unsigned int bits;
    float ret;

    h = half;
    mant = h & 0x3FF;
    if ((h & 0x7C00) != 0) {
        exp = (h >> 10) & 0x1F;
        sign = h & 0x8000;
    } else if (mant != 0) {
        exp = 1;
        sign = h & 0x8000;
        do {
            mant <<= 1;
            exp--;
        } while ((mant & 0x400) == 0);
        mant &= 0x3FF;
    } else {
        exp = -0x70;
        sign = h & 0x8000;
    }

    bits = (sign << 16) | ((exp + 0x70) << 23) | (mant << 13);
    *(unsigned int *)&ret = bits;
    return ret;
}

__attribute__((section(".text.classPAD_WORK_Pad_act_all_stop")))
void classPAD_WORK_Pad_act_all_stop(void *this) {
    unsigned char *p;
    int i;

    p = (unsigned char *)this + 0x160;
    for (i = 31; i != -1; i--) {
        *p = 0;
        p += 0x10;
    }
}

__attribute__((section(".text.func_002A6C78")))
void func_002A6C78(void *this) {
    char *p;
    int i;

    p = (char *)this + 0x14;
    for (i = 0; i < 32; i++) {
        *(int *)(p - 8) = 0xFFFF;
        *(int *)(p - 4) = -1;
        *(int *)(p - 0) = 0;
        p += 0xC;
    }
}
