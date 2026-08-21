/* sn-2.95.3-136 matched TU. */

extern void cEmManage_EntryEm(void *, void *, int, void *);
extern unsigned char D_005864F0[];

#include "godhand/vu0.h"




typedef struct EmParam {
    /* 0x00 */ int f00;
    /* 0x04 */ int f04;
    /* 0x08 */ int f08;
    /* 0x0C */ int f0C;
    /* 0x10 */ float pos[4];
    /* 0x20 */ float f20;
    /* 0x24 */ unsigned int f24;
    /* 0x28 */ int f28;
    /* 0x2C */ int f2C;
    /* 0x30 */ unsigned char f30;
    /* 0x31 */ unsigned char f31;
    /* 0x32 */ unsigned char f32[14];
} EmParam;

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_00260890")))
void func_00260890(unsigned char *p, int kind)
{
    float pos[4];
    EmParam ep;
    EmParam *e;
    float tmp;
    int h;

    if ((*(int *)(p + 0x564) ^ 0x21F) != 0) {
        return;
    }

    VU0_SQC2_VF0(pos, 0);
    cpy3(pos, *(float **)(p + 0xF0));

    e = &ep;
    tmp = *(float *)(p + 0x104);
    VU0_SQC2_VF0(pos, 0x20);
    h = *(unsigned short *)(p + 0x2FE);
    e->f31 = 0xFF;
    ep.f00 = h;
    cpy3(ep.pos, pos);
    ep.f20 = tmp;
    ep.f24 = 0x040C0000;
    ep.f28 = *(int *)(p + 0x564);
    ep.f31 = 0xFF;
    ep.f2C = 0;
    switch (kind) {
    default:
    case 0:
        ep.f30 = 0x12;
        break;
    case 1:
        ep.f30 = 0x13;
        break;
    case 2:
        ep.f30 = 0x14;
        break;
    case 3:
        ep.f30 = 0x15;
        break;
    case 4:
        ep.f30 = 0x16;
        break;
    }
    cEmManage_EntryEm(D_005864F0, &ep, 0, p);
}
