/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern float cEmManage_GetSpeedRate(void *a0);
extern void KillEffect(void *a0, int a1, int a2);
extern float Adjust_theta(float f12);
extern int D_005864E0[];
extern void sceVu0ApplyMatrix(void *dst, void *m, void *src);
extern unsigned int Forward30F348_31CFE0(void);
extern void cEmManage_EntryEm(void *, void *, int, void *);
extern char D_003BF958[];
extern char D_003BF970[];
extern char D_003BF988[];
extern char D_003BF9A0[];
extern char D_003BF9B8[];
extern char D_003BFA10[];
extern char D_003BFA68[];
extern char D_005850C0[];
extern void func_001038E0(char *a0, char *a1, char *a2, float f12, float f13);
extern char D_003BFFD0[];
extern char D_003BFFE8[];
extern char D_003C0000[];
extern char D_003C0018[];
extern char D_003C0030[];
extern char D_003C0088[];
extern char D_003C00E0[];
extern char D_00585660[];

/* sn-2.95.3-136 matched TU. */






static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_001CA040")))
void func_001CA040(char *this)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    float rate;
    int kind;
    int lim, b, obj;
    unsigned char ok;
    int b2;
    unsigned char ok2;
    char *o2;
    float w;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    kind = *(unsigned short *)(this + 0x2FE);
    if (kind == 0x3AA) goto have;
    if (kind != 0x3AB) goto nohave;
have:
    {
        lim = 5;
        ok = ((*(int *)frame = b = *(unsigned char *)(this + 0x2B4)), (lim < b));
        if (ok) obj = *(int *)(*(int *)(this + 0x278) + 0x14); else obj = 0;
        if (obj != 0) {
            float c = *(float *)(obj + 0x110);
            float k = 0.0500000007f;
            float x = c - k;
            float y;
            *(float *)(obj + 0x110) = x;
            if (x < k) *(float *)(obj + 0x110) = k;
            y = *(float *)(obj + 0x110);
            *(float *)(obj + 0x118) = y;
            *(float *)(obj + 0x114) = y;
        }
    }
nohave:
    if (*(unsigned char *)(this + 0x2F6) == 0) {
        int t = *(unsigned short *)(this + 0x2FE);
        *(char *)(this + 0x531) = -1;
        if (t != 0x3AE && t != 0x3B7) {
            KillEffect(this, 8, 2);
        }
        *(unsigned char *)(this + 0x2F6) = *(unsigned char *)(this + 0x2F6) + 1;
    }
    w = *(float *)(this + 0x684);
    if (0.0f < w) {
        *(float *)(this + 0x684) = w - rate;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(this + 0x2B4)), (b2 != 0));
        if (ok2) o2 = *(char **)(*(int *)(this + 0x278) + 0); else o2 = 0;
        if (o2 != 0) {
            if (0.0f < *(float *)(this + 0x684)) {
                float r = *(float *)(o2 + 0x104) + rate * 0.523598790f;
                *(float *)(o2 + 0x104) = r;
                *(float *)(o2 + 0x104) = Adjust_theta(r);
            } else {
                float *ss = (float *)(this + 0x620);
                float *dd = (float *)(o2 + 0x100);
                cpy3(dd, ss);
            }
        }
    }
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

__attribute__((section(".text.func_00260278")))
void func_00260278(char *this)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    float pos[4];
    EmParam ep;
    EmParam *e;
    char *o;
    int lim, b, obj;
    unsigned char ok;
    unsigned int i;
    int id;
    float tmp;

    if ((*(int *)(this + 0x564) ^ 0x26A) != 0) return;
    o = *(char **)(this + 0x748);
    if (o == 0) return;
    lim = 0xA;
    ok = ((*(int *)frame = b = *(unsigned char *)(o + 0x2B4)), (lim < b));
    if (ok) obj = *(int *)(*(int *)(o + 0x278) + 0x28); else obj = 0;
    if (obj == 0) return;

    VU0_SQC2_VF0(frame, 0x10);
    pos[1] = 0.100000001f;
    pos[2] = 0.0500000007f;
    id = 0xFFFF;
    *(int *)pos = 0;
    sceVu0ApplyMatrix(pos, (void *)(obj + 0x80), pos);
    pos[1] = pos[1] - 1.0f;
    for (i = 0; i < func_0028FE58(D_005864E0); i++) {
        id = func_0028FED8(D_005864E0, i);
        if (id == 0x220) break;
    }
    VU0_SQC2_VF0(frame, 0x30);
    e = &ep;
    e->f31 = 0xFF;
    if (id == 0x220) {
        unsigned int r;
        ep.f31 = 0xFF;
        ep.pos[0] = pos[0];
        ep.pos[1] = pos[1];
        ep.pos[2] = pos[2];
        tmp = *(float *)(this + 0x104);
        ep.f20 = tmp;
        ep.f30 = 0x21;
        ep.f00 = id;
        ep.f24 = 0;
        ep.f2C = 0;
        r = Forward30F348_31CFE0();
        {
            unsigned int three = 3;
            r = r % three;
        }
        switch (r) {
        case 0:
        default:
            ep.f28 = id;
            break;
        case 1:
            ep.f28 = 0x221;
            break;
        case 2:
            ep.f28 = 0x222;
            break;
        }
        cEmManage_EntryEm(D_005864F0, e, 0, this);
    }
}

__attribute__((section(".text.func_00276C88")))
void func_00276C88(char *p)
{
    float v[4];
    volatile float *dst;

    *(int *)(p + 0x2130) = 0x15;
    *(char **)(p + 0x2134) = D_003BF958;
    *(char **)(p + 0x2138) = D_003BF9A0;
    *(int *)(p + 0x213C) = 0;
    *(int *)(p + 0x2140) = 0;
    *(int *)(p + 0x2144) = 0;
    *(char **)(p + 0x2148) = D_003BF970;
    *(char **)(p + 0x214C) = D_003BF988;
    *(int *)(p + 0x2150) = 0;
    *(int *)(p + 0x2154) = 0;
    *(char **)(p + 0x2158) = D_003BF9B8;
    *(char **)(p + 0x215C) = D_003BFA10;
    *(char **)(p + 0x2160) = D_003BFA68;
    *(char **)(p + 0x2164) = D_005850C0;
    *(int *)(p + 0x2168) = 0;
    *(int *)(p + 0x2188) = 0;
    *(float *)(p + 0x216C) = 0.015f;
    *(float *)(p + 0x2170) = 0.8f;
    *(int *)(p + 0x2174) = 1;
    *(float *)(p + 0x2178) = 0.0f;
    *(float *)(p + 0x217C) = 0.8f;
    *(float *)(p + 0x2180) = 0.5f;
    *(int *)(p + 0x2184) = 0;
    *(int *)(p + 0x218C) = 0x100;
    v[0] = 0.0f;
    v[1] = 0.0f;
    *(int *)&v[2] = 0;
    v[3] = 1.0f;
    dst = (volatile float *)(p + 0x2190);
    if (dst != (volatile float *)v) {
        dst[0] = v[0];
        dst[1] = v[1];
        dst[2] = *(volatile float *)&v[2];
    }
    *(int *)(p + 0x21A0) = 0;
    func_001038E0(p, p + 0x2130, p + 0x5B0, 0.1f, *(float *)(p + 0x21A0));
}

__attribute__((section(".text.func_00283968")))
void func_00283968(char *p)
{
    float v[4];
    volatile float *dst;

    *(int *)(p + 0x2130) = 0x15;
    *(char **)(p + 0x2134) = D_003BFFD0;
    *(char **)(p + 0x2138) = D_003C0018;
    *(int *)(p + 0x213C) = 0;
    *(int *)(p + 0x2140) = 0;
    *(int *)(p + 0x2144) = 0;
    *(char **)(p + 0x2148) = D_003BFFE8;
    *(char **)(p + 0x214C) = D_003C0000;
    *(int *)(p + 0x2150) = 0;
    *(int *)(p + 0x2154) = 0;
    *(char **)(p + 0x2158) = D_003C0030;
    *(char **)(p + 0x215C) = D_003C0088;
    *(char **)(p + 0x2160) = D_003C00E0;
    *(char **)(p + 0x2164) = D_00585660;
    *(int *)(p + 0x2168) = 0;
    *(int *)(p + 0x2188) = 0;
    *(float *)(p + 0x216C) = 0.015f;
    *(float *)(p + 0x2170) = 0.8f;
    *(int *)(p + 0x2174) = 1;
    *(float *)(p + 0x2178) = 0.0f;
    *(float *)(p + 0x217C) = 0.8f;
    *(float *)(p + 0x2180) = 0.5f;
    *(int *)(p + 0x2184) = 0;
    *(int *)(p + 0x218C) = 0x100;
    v[0] = 0.0f;
    v[1] = 0.0f;
    *(int *)&v[2] = 0;
    v[3] = 1.0f;
    dst = (volatile float *)(p + 0x2190);
    if (dst != (volatile float *)v) {
        dst[0] = v[0];
        dst[1] = v[1];
        dst[2] = *(volatile float *)&v[2];
    }
    *(int *)(p + 0x21A0) = 0;
    func_001038E0(p, p + 0x2130, p + 0x5B0, 0.1f, *(float *)(p + 0x21A0));
}
