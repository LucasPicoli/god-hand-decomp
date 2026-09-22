/* sn-2.95.3-136 matched TU. */

extern void func_0032A6D0(void *x, int mode, short v);
extern void *cModel_getMeshPtr(void *m, int i);
extern void *D_00754C58;
extern int D_0041D5A8;
extern int D_0041D580;
extern int D_003C2388;
extern int D_003C11B0;
extern void *cIDManager_getTexAddr(int a, int b, int c);
extern void cIDBase_trans(void *p);

/* sn-2.95.3-136 candidate. */





__attribute__((section(".text.func_00383C70")))
void func_00383C70(void *a0, char *p, unsigned char flag)
{
    unsigned short *q;
    unsigned short *r;
    char *c;
    void *h;
    void *t;
    int mode;
    int i;
    int j;

    if (flag != 0) {
        q = (unsigned short *)(p + 0x26);
        mode = 1;
    } else {
        q = (unsigned short *)(p + 0x1C);
        mode = 0;
    }
    if (*(unsigned char *)(p + 4) == 0) {
        r = q + 1;
        for (j = 3; j >= 0; j--) {
            *r = *q;
            r++;
        }
    } else {
        if (func_00383DD0(a0, p) != 0) {
            *q = q[*(unsigned char *)(p + 4)];
        }
    }
    if ((*(unsigned char *)(p + 3) & 1) != 0) {
        c = p + 0xA4;
        h = *(void **)(c + 0x20);
        if (h != 0) {
            if (*(unsigned char *)(p + 4) != 0) {
                t = func_0032DCD0(h, *(unsigned char *)(p + 4) - 1);
                func_0032A6D0(t, mode, q[*(unsigned char *)(p + 4)]);
            } else {
                if (*(int *)(c + 8) > 0) {
                    i = 0;
                    do {
                        t = func_0032DCD0(*(void **)(c + 0x20), i);
                        i++;
                        func_0032A6D0(t, mode, q[1]);
                        q++;
                    } while (i < *(int *)(c + 8));
                }
            }
        }
    } else {
        h = *(void **)(p + 0x64);
        if (h != 0) {
            func_0032A6D0(h, mode, *q);
        }
    }
}

/* sn-2.95.3-136 candidate. */




static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_00308BC0")))
void func_00308BC0(char *a0)
{
    char *m;
    char *n;
    char **p;
    unsigned short k;
    long found;
    int i;
    int off;

    for (i = 0; i < 0x20; i++) {
        off = i * 4;
        m = *(char **)(a0 + off);
        if (m != 0) {
            n = (char *)cModel_getMeshPtr(m, 0);
            while (n != 0) {
                *(unsigned int *)(n + 0x380) =
                    *(unsigned int *)(n + 0x380) & 0xFFFFFFFE;
                n = *(char **)(n + 0x404);
            }
        }
    }
    p = *(char ***)((char *)D_00754C58 + 4);
    while ((unsigned int)p < *(unsigned int *)((char *)D_00754C58 + 8)) {
        found = 0;
        k = *(unsigned short *)(*p + 0x2FE);
        if ((inrange(k, 0x100, 0x1FF) & 0xFF) || (inrange(k, 0x200, 0x300) & 0xFF) ||
            (inrange(k, 0x300, 0x500) & 0xFF) || (inrange(k, 0x500, 0x600) & 0xFF))
            found = 1;
        if (found & 0xFF) {
            *(int *)(*p + 0x5A0) = *(int *)(*p + 0x5A0) & ~2;
        }
        p++;
    }
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"

typedef struct { char b[0x10]; } Blob16;





__attribute__((section(".text.func_0012CF70")))
void *func_0012CF70(char *self, char *obj, int flags, float *v1, float *v2,
                    char *blob, float f12, float f13)
{
    char *p;
    float x;
    float y;
    int i;

    *(int *)(self + 0x5C) = (int)&D_0041D5A8;
    *(int *)(self + 0x8) = 0;
    VU0_SQC2_VF0(self, 0x10);
    VU0_SQC2_VF0(self, 0x20);
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x30) = 0;
    *(int *)(self + 0x0) = 0;
    *(int *)(self + 0x54) = 0;
    func_003A52F0(self + 0x34, 0, 0x20);
    *(int *)(self + 0x5C) = (int)&D_0041D580;
    VU0_SQC2_VF0(self, 0x60);
    VU0_SQC2_VF0(self, 0x70);
    VU0_SQC2_VF0(self, 0x80);
    VU0_SQC2_VF0(self, 0x90);
    p = self + 0xC0;
    i = 3;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--i != -1);
    *(int *)(self + 0x58) = flags;
    *(int *)(self + 0x4) = 1;
    *(int *)(self + 0x30) = (int)obj;

    {
        float *d1 = (float *)(self + 0x60);
        float *s1 = *(float **)(obj + 0xF0);
        if (d1 != s1) { d1[0] = s1[0]; d1[1] = s1[1]; d1[2] = s1[2]; }
    }
    {
        float *d2 = (float *)(self + 0x70);
        if (d2 != v1) { d2[0] = v1[0]; d2[1] = v1[1]; d2[2] = v1[2]; }
    }
    {
        float *d3 = (float *)(self + 0x80);
        float *s3 = (float *)(obj + 0x100);
        if (d3 != s3) { d3[0] = s3[0]; d3[1] = s3[1]; d3[2] = s3[2]; }
    }
    {
        float *d4 = (float *)(self + 0x90);
        if (d4 != v2) { d4[0] = v2[0]; d4[1] = v2[1]; d4[2] = v2[2]; }
    }

    x = f12;
    if (x < 0.0f) x = -x;
    *(float *)(self + 0xA0) = x;
    y = f13;
    if (y < 0.0f) y = -y;
    *(float *)(self + 0xA4) = y;

    *(Blob16 *)(self + 0xA8) = *(Blob16 *)blob;
    *(unsigned short *)(self + 0xB0) = 0xFFFF;
    *(char *)(self + 0xB3) = 0;
    *(char *)(self + 0xB2) = 0;
    *(int *)(self + 0x8) = *(int *)(self + 0x8) | 5;
    return self;
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"




extern void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                             int t0, int t1, void *cfg, int t3, int extra);


static __inline__ void SetVec4(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

static __inline__ void CopyVec3(float *d, float *s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

__attribute__((section(".text.func_001ECC48")))
void func_001ECC48(char *self)
{
    char cfg[0x50];
    float v[4][4];
    float ta[4];
    float tb[4];
    float tmp[4];
    void *tex;
    void *r;
    char *z;
    int i;

    *(int *)(cfg + 0x0) = 1;
    z = (char *)v;
    i = 3;
    do {
        VU0_SQC2_VF0(z, 0x0);
        z += 0x10;
    } while (--i != -1);
    VU0_SQC2_VF0((char *)ta - 0xA0, 0xA0);
    VU0_SQC2_VF0((char *)ta - 0xA0, 0xB0);

    SetVec4(tmp, -1.0f, -1.0f, 0.0f);
    CopyVec3(ta, tmp);
    SetVec4(tmp, 513.0f, 448.0f, 0.0f);
    CopyVec3(tb, tmp);

    tex = cIDManager_getTexAddr(D_003C2388, 0x14, 1);

    SetVec4(v[0], ta[0], ta[1], 0.0f);
    SetVec4(v[1], tb[0], ta[1], 0.0f);
    SetVec4(v[2], ta[0], tb[1], 0.0f);
    SetVec4(v[3], tb[0], tb[1], 0.0f);

    *(int *)(cfg + 0x4) = 0;
    *(int *)(cfg + 0x8) = 0;
    *(float *)(cfg + 0xC) = 1.0f;
    *(float *)(cfg + 0x10) = 0.875f;

    r = Gp_draw_polyFT4(v, 0x80808080, 1, tex, D_003C11B0, 0x1CF0, cfg, 0, 5);
    if (r != 0) {
        *(long *)((char *)r + 0x1A0) = 0x3001D;
    }
    cIDBase_trans(self + 0x10);
}
