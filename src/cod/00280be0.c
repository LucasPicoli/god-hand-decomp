/* sn-2.95.3-136 matched TU. */

extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void cNode_setLocalTranslation(void *self, void *v);
extern void func_002FEB18(void *a0);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"



typedef struct {
    float f00;          /* 0x00 */
    float f04;          /* 0x04 */
    float f08;          /* 0x08 */
    float f0C;          /* 0x0C */
    char q10[0x10];     /* 0x10 sqc2 */
    char q20[0x10];     /* 0x20 sqc2 */
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
    float f3C;          /* 0x3C */
    float f40;          /* 0x40 */
    int i44;            /* 0x44 */
    int i48;            /* 0x48 */
    signed char b4C;    /* 0x4C */
    signed char b4D;    /* 0x4D */
    signed char b4E;    /* 0x4E */
    unsigned char b4F;  /* 0x4F */
    int i50;            /* 0x50 */
    char pad54[0xC];    /* 0x54 */
    char q60[0x10];     /* 0x60 sqc2 */
    short h70;          /* 0x70 */
    short h72;          /* 0x72 */
    signed char b74;    /* 0x74 */
    char pad75[3];      /* 0x75 */
    int i78;            /* 0x78 */
} S;

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_00280BE0")))
void func_00280BE0(char *p, char *par, int idx, float *v0p, float *v1p)
{
    S s;
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b, b2;
    unsigned char ok, ok2;
    char *obj;
    char *o;
    float *sv;

    s.f00 = 1.0f;
    s.f04 = 1.0f;
    s.f08 = 1.0f;
    s.f0C = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.f30;
        s.f30 = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.f40 = 1.0f;
    s.b4C = -1;
    s.b4F = 0xFF;
    s.i44 = 0;
    s.i48 = 0;
    s.b4D = 0;
    s.b4E = 0;
    s.i50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    s.h70 = 0;
    s.h72 = 0;
    s.b74 = 0;
    s.i78 = 0;
    ok = ((*(int *)frame = b = *(unsigned char *)(par + 0x2B4)), (idx >= 0 && idx < b));
    if (ok) obj = *(char **)(*(char **)(par + 0x278) + idx * 4); else obj = 0;
    if (obj == 0) return;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (b2 != 0));
    if (ok2) o = **(char ***)(p + 0x278); else o = 0;
    if (o == 0) return;
    sv = *(float **)(o + 0xD0);
    *(int *)(o + 0x100) = 0;
    *(int *)(o + 0x104) = 0;
    *(int *)(o + 0x108) = 0;
    *(char **)(o + 0x148) = obj;
    cpy3(sv, v0p);
    cpy3((float *)(o + 0x100), v1p);
    *(int *)(p + 0x1584) = idx;
    *(char **)(p + 0x1580) = par;
    cpy3((float *)(p + 0x1590), v0p);
    cpy3((float *)(p + 0x15A0), v1p);
    cpy3((float *)(p + 0x110), (float *)(par + 0x110));
    s.f40 = *(float *)(p + 0x114);
    SetEffect(0xC2, 1, p, &s, 1, 0xFFFFFFFFu);
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);



#define FRAME ((char *)v - 0x30)

__attribute__((section(".text.func_002F9E80")))
void func_002F9E80(char *this)
{
    float v[4];
    unsigned char hold[0x10];
    float vc[4];
    float p60[4];
    float p70[4];
    char *o;
    int idx, b, obj;
    unsigned char ok;
    float one;
    float sv, d, lim, fac, h;
    float x, y, z;
    int n;

    o = *(char **)(this + 0x114);
    idx = *(int *)(this + 0x2B4);
    ok = ((*(int *)hold = b = *(unsigned char *)(o + 0x2B4)), (idx >= 0 && idx < b));
    if (ok) obj = *(int *)(*(int *)(o + 0x278) + idx * 4); else obj = 0;

    x = *(float *)(obj + 0xB0);
    y = *(float *)(obj + 0xB4);
    z = *(float *)(obj + 0xB8);
    one = 1.0f;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = one;
    VU0_SQC2_VF0(FRAME, 0x50);
    VU0_LQC2(4, v, 0);
    VU0_SQC2(4, FRAME, 0x60);
    VU0_LQC2(4, v, 0);
    VU0_SQC2(4, FRAME, 0x70);
    h = *(float *)(this + 0x2B0) + one;
    n = 1;
    p60[1] = p60[1] + one;
    p70[1] = p70[1] - h;
    if (ChkLine(p60, p70, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, n) == n) {
        char *r = *(char **)(this + 0x110);
        vc[1] = vc[1] + *(float *)(r + 0x140);
    }
    cNode_setLocalTranslation(this, vc);
    d = v[1] - vc[1];
    lim = *(float *)(this + 0x2B8);
    sv = *(float *)(this + 0x194);
    if (d < lim) {
        fac = 0.9f;
    } else {
        fac = one - (d - lim) / *(float *)(this + 0x2BC);
    }
    *(float *)(this + 0x194) = *(float *)(this + 0x194) * fac;
    func_002FEB18(this);
    *(float *)(this + 0x194) = sv;
}
