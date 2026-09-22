/* sn-2.95.3-136 matched TU. */

extern void *SearchData(void *a, void *b, int c);
extern void ClearLinkedNodeList_12ECF0(void *p);
extern void *D_00747A4C;
extern char D_0041D418[];
extern char D_0041D420[];
extern unsigned char D_007474A0[];
extern void cMessDrawFont_setBodyData(void *a0, void *a1, void *a2, void *a3);
extern void cMessDrawFont_setRubyData(void *a0, int a1, int a2);
extern void cMessDrawFont_setDrawCounter(void *a0, int a1, int a2);
extern void cMessDrawFont_setDrawPos(void *a0, int a1, float x, float y);
extern void func_002AF668(void *a0, float x, float y);
extern void func_002AF678(void *a0, float x, float y);
extern void func_002AF688(void *a0, float x, float y);
extern void func_002AF698(void *a0, float x, float y);
extern void func_002AF6A8(void *a0, int a1, int a2);
extern void func_002AF6B8(void *a0, int a1);
extern void func_002AF708(void *a0, int a1);
extern void func_002AF710(void *a0, int a1, unsigned int a2);
extern void func_002AF720(void *a0, float x);
extern void cEmManage_EntryEm(void *, void *, int, void *);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern unsigned char D_005864F0[];
extern char D_00569B70[];
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern float DoubleFloatMinusHalf_31D020(void);
extern void Obj1D00_SetState_6_E_a1(void *a0, int a1);

/* SN ProDG ee-gcc 2.95.3 matched TU. */








typedef struct Hdr {
    char *p00;
    char *p04;
    char *p08;
    char *p0C;
    char *p10;
    char *p14;
    char *p18;
    char *p1C;
    char pad20[0x10];
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
    float f50;
    char pad54[0x0C];
    unsigned short h60;
    unsigned short h62;
    unsigned short h64;
} Hdr;

typedef struct Obj {
    Hdr *hdr;
    char *w04;
    char *w08;
    char *w0C;
    char *w10;
    char *w14;
    char *w18;
    char *w1C;
    char *w20;
    char pad24[0x0C];
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
    float f50;
    float f54;
    float f58;
    char pad5C[0x04];
    int n60;
    int n64;
    int n68;
} Obj;

__attribute__((section(".text.func_0012E670")))
void func_0012E670(Obj *p)
{
    Hdr *t;
    Hdr *h;

    if (p->hdr != 0) {
        return;
    }
    t = (Hdr *)SearchData(D_00747A4C, D_0041D418, 0);
    if (t == 0) {
        return;
    }
    h = (Hdr *)SearchData(t, D_0041D420, 0);
    p->hdr = h;
    if (h == 0) {
        return;
    }
    p->hdr->p00 = (char *)p->hdr + (int)p->hdr->p00;
    p->hdr->p04 = (char *)p->hdr + (int)p->hdr->p04;
    p->hdr->p08 = (char *)p->hdr + (int)p->hdr->p08;
    p->hdr->p0C = (char *)p->hdr + (int)p->hdr->p0C;
    p->hdr->p10 = (char *)p->hdr + (int)p->hdr->p10;
    p->hdr->p14 = (char *)p->hdr + (int)p->hdr->p14;
    p->hdr->p18 = (char *)p->hdr + (int)p->hdr->p18;
    p->hdr->p1C = (char *)p->hdr + (int)p->hdr->p1C;

    p->w04 = p->hdr->p00;
    p->w08 = p->hdr->p04;
    p->w0C = p->hdr->p08;
    p->w10 = p->hdr->p0C;
    p->w14 = p->hdr->p10;
    p->w18 = p->hdr->p14;
    p->w1C = p->hdr->p18;
    p->w20 = p->hdr->p1C;

    p->n60 = p->hdr->h60;
    p->n64 = p->hdr->h62;
    p->n68 = p->hdr->h64;

    p->f50 = p->hdr->f48;
    p->f54 = p->hdr->f4C;
    p->f58 = p->hdr->f50;

    p->f30 = p->hdr->f30;
    p->f34 = p->hdr->f34;
    p->f38 = p->hdr->f38;

    p->f40 = p->hdr->f3C;
    p->f44 = p->hdr->f40;
    p->f48 = p->hdr->f44;

    ClearLinkedNodeList_12ECF0(p);
}

/* SN ProDG ee-gcc 2.95.3 matched TU. */

















__attribute__((section(".text.cMessDrawFont_setEnvInit")))
void cMessDrawFont_setEnvInit(void *p)
{
    unsigned char *d;
    unsigned char *e;

    *(int *)p = 0;
    cMessDrawFont_setBodyData(p, 0, 0, 0);
    cMessDrawFont_setRubyData(p, 0, 0);
    cMessDrawFont_setDrawCounter(p, 0, 0);
    cMessDrawFont_setDrawPos(p, 2, 0.0f, 0.0f);
    d = D_007474A0;
    if (*(int *)(d + 0x56C) == 0) {
        func_002AF668(p, 2.0f, -10.0f);
    } else {
        func_002AF668(p, 2.0f, -10.0f);
    }
    func_002AF678(p, 1.0f, 0.0f);
    e = D_007474A0;
    if (*(int *)(e + 0x56C) == 0) {
        func_002AF688(p, 1.0f, 1.0f);
        func_002AF698(p, 1.0f, 1.0f);
    } else {
        func_002AF688(p, 0.9f, 1.0f);
        func_002AF698(p, 0.9f, 1.0f);
    }
    func_002AF6A8(p, 3, 0);
    func_002AF6B8(p, 1);
    func_002AF708(p, -1);
    func_002AF710(p, 6, 0xFFFFFFFF);
    func_002AF720(p, 65535.0f);
}

/* sn-2.95.3-136 matched TU. */








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

__attribute__((section(".text.func_002606E8")))
void func_002606E8(unsigned char *p, int kind)
{
    float pos[4];
    EmParam ep;
    EmParam *e;
    float tmp;
    int h;

    if ((*(int *)(p + 0x564) ^ 0x211) != 0) {
        return;
    }

    VU0_SQC2_VF0(pos, 0);
    if (func_00260650(p) >= 2) {
        return;
    }

    switch (kind) {
    default:
    case 0x200:
        pos[0] = -12.0200005f;
        pos[1] = 5.86199999f;
        pos[2] = -24.7800007f;
        tmp = 1.30899692f;
        break;
    case 0x203:
        pos[0] = 10.1000004f;
        pos[1] = 6.46000004f;
        pos[2] = -20.9400005f;
        tmp = -1.2566371f;
        break;
    }

    e = &ep;
    VU0_SQC2_VF0(pos, 0x20);
    h = *(unsigned short *)(p + 0x2FE);
    e->f31 = 0xFF;
    ep.f00 = h;
    cpy3(ep.pos, pos);
    ep.f20 = tmp;
    ep.f24 = 0x04080000;
    ep.f28 = kind;
    ep.f31 = 0xFF;
    ep.f30 = 0;
    ep.f2C = 0;
    if (cCoreSave_getGameLevel(D_00569B70) >= 2) {
        if ((Forward30F348_31CFE0() & 3) == 0) {
            ep.f2C = 1;
        }
        if (cCoreSave_getGameLevel(D_00569B70) >= 5) {
            ep.f2C = 1;
        }
    }
    cEmManage_EntryEm(D_005864F0, &ep, 0, p);
}

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_002464E0")))
void func_002464E0(void *a0)
{
    char *s2 = (char *)a0;
    int v0;
    int v1;
    int p1;
    int p2;
    int t0;

    *(float *)(s2 + 0x54C) = 3.0f;
    *(char *)(s2 + 0x617) = 1;
    switch (*(unsigned char *)(s2 + 0x2F6)) {
    case 0:
        *(char *)(s2 + 0x1864) = 0;
        v0 = *(int *)(s2 + 0x304);
        p1 = *(int *)(v0 + 0x2504) + v0;
        p2 = *(int *)(v0 + 0x2508) + v0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        *(int *)(s2 + 0x16D0) = *(int *)(s2 + 0x16D0) & 0xDFFFFFFF;
        func_002A8578(s2, p1, p2, 0.0f, 0xA, t0, 0);
        *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s2) != 0) {
            *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        break;
    case 2:
        *(char *)(s2 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        v1 = *(int *)(s2 + 0x304);
        func_002A8578(s2, *(int *)(v1 + 0x24EC) + v1, *(int *)(v1 + 0x24F0) + v1,
                      0.0f, 0xA, t0, 0);
        *(unsigned char *)(s2 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6) + 1;
    case 3:
        moveMotion(s2);
        AddScaledVecToField_100_14F9F0(s2, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s2, 1.0f);
        if (*(int *)(s2 + 0x16D0) & 0x20000000) {
            func_002705D8(s2);
        }
        break;
    }
}

/* sn-2.95.3-136 matched TU. */










__attribute__((section(".text.func_00247050")))
void func_00247050(void *a0)
{
    char *s0 = (char *)a0;
    int v1;
    int t0;

    *(char *)(s0 + 0x617) = 1;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x10A8) + v1, *(int *)(v1 + 0x10AC) + v1,
                      0.0f, 0xA, t0, 0);
        *(float *)(s0 + 0x600) = DoubleFloatMinusHalf_31D020() * 150.0f + 150.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        if (*(float *)(s0 + 0x600) <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        if (0.0f < *(float *)(s0 + 0x16C0)) {
            func_002705D8(s0);
        }
        break;
    case 2:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x11A8) + v1, *(int *)(v1 + 0x11B4) + v1,
                      0.0f, 0xA, t0, 0);
        if (*(void **)(s0 + 0x6F0) != 0) {
            Obj1D00_SetState_6_E_a1(*(void **)(s0 + 0x6F0), 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
}
