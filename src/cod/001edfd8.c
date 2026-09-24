/* sn-2.95.3-136 matched TU. */

extern int D_003C2388;
extern int D_003C11B0;
extern void *cIDManager_getTexAddr(int a, int b, int c);
extern void cIDBase_trans(void *p);
extern void func_002BB760(void *a0, void *a1, void *pts);
extern void func_002BD4B0(void *a0, void *a1, void *a2, void *pts);

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

__attribute__((section(".text.func_001EDFD8")))
void func_001EDFD8(char *self)
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

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_002BBBA0")))
void func_002BBBA0(void *a0, void *a1, float *ext)
{
    char buf[0x90];
    char *p;
    float *v1;
    float *v2;
    float *v3;
    float *v4;
    float *v5;
    float *v6;
    float *v7;
    float w;
    float t;
    int i;

    p = buf;
    i = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--i != -1);

    VU0_LQC2(4, ext, 0x0);
    VU0_SQC2(4, buf, 0x80);
    t = 0.5f;
    VU0_LQC2(4, buf, 0x80);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x80);

    v1 = (float *)(buf + 0x10);
    v2 = (float *)(buf + 0x20);
    v3 = (float *)(buf + 0x30);
    v4 = (float *)(buf + 0x40);
    v5 = (float *)(buf + 0x50);
    v6 = (float *)(buf + 0x60);
    v7 = (float *)(buf + 0x70);
    w = ext[1];

    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        *(float *)(buf + 0x0) = -xx;
        *(float *)(buf + 0x4) = 0.0f;
        *(float *)(buf + 0x8) = -zz;
        v1[0] = xx;
        v1[1] = 0.0f;
        v1[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v2[0] = -xx;
        v2[1] = 0.0f;
        v2[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v3[0] = xx;
        v3[1] = 0.0f;
        v3[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v4[0] = -xx;
        v4[1] = w;
        v4[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v5[0] = xx;
        v5[1] = w;
        v5[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v6[0] = -xx;
        v6[1] = w;
        v6[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v7[0] = xx;
        v7[1] = w;
        v7[2] = zz;
    }

    func_002BB760(a0, a1, buf);
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_002BD6A8")))
void func_002BD6A8(void *a0, void *a1, void *a2, float *ext)
{
    char buf[0x90];
    char *p;
    float *v1;
    float *v2;
    float *v3;
    float *v4;
    float *v5;
    float *v6;
    float *v7;
    float w;
    float t;
    int i;

    p = buf;
    i = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--i != -1);

    VU0_LQC2(4, ext, 0x0);
    VU0_SQC2(4, buf, 0x80);
    t = 0.5f;
    VU0_LQC2(4, buf, 0x80);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x80);

    v1 = (float *)(buf + 0x10);
    v2 = (float *)(buf + 0x20);
    v3 = (float *)(buf + 0x30);
    v4 = (float *)(buf + 0x40);
    v5 = (float *)(buf + 0x50);
    v6 = (float *)(buf + 0x60);
    v7 = (float *)(buf + 0x70);
    w = ext[1];

    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        *(float *)(buf + 0x0) = -xx;
        *(float *)(buf + 0x4) = 0.0f;
        *(float *)(buf + 0x8) = -zz;
        v1[0] = xx;
        v1[1] = 0.0f;
        v1[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v2[0] = -xx;
        v2[1] = 0.0f;
        v2[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v3[0] = xx;
        v3[1] = 0.0f;
        v3[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v4[0] = -xx;
        v4[1] = w;
        v4[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v5[0] = xx;
        v5[1] = w;
        v5[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v6[0] = -xx;
        v6[1] = w;
        v6[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v7[0] = xx;
        v7[1] = w;
        v7[2] = zz;
    }

    func_002BD4B0(a0, a1, a2, buf);
}
