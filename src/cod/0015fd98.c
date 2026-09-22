/* sn-2.95.3-136 matched TU. */

extern void func_002BD078(void *a0, void *a1, void *pts);
extern void func_003A52F0(void *d, int c, int n);
extern void func_0015FCB8(void *a0, void *a1, int idx);

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_002BD200")))
void func_002BD200(void *a0, void *a1, float *ext)
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

    func_002BD078(a0, a1, buf);
}

/* sn-2.95.3-136 candidate. */

struct VtEnt { short delta; short index; void *pfn; };




__attribute__((section(".text.func_0015FD98")))
void func_0015FD98(char *self)
{
    char *q;
    char *p;
    struct VtEnt *vt;
    int *r;
    int i;
    int j;
    int m;

    func_003A52F0(self, 0, 0x48);
    func_0015FCB8(self, self + 0x60, 0);
    func_0015FCB8(self, self + 0x310, 1);
    func_0015FCB8(self, self + 0x620, 2);
    func_0015FCB8(self, self + 0x730, 3);
    func_0015FCB8(self, self + 0x880, 4);
    func_0015FCB8(self, self + 0x9C0, 5);
    func_0015FCB8(self, self + 0xBA0, 8);
    func_0015FCB8(self, self + 0xC40, 7);
    func_0015FCB8(self, self + 0xAE0, 6);
    q = self + 4;
    i = 8;
    do {
        p = *(char **)q;
        if (p != 0) {
            vt = *(struct VtEnt **)(p + 0x70);
            ((void (*)(void *))vt[1].pfn)(p + vt[1].delta);
        }
        i--;
        q += 8;
    } while (i >= 0);
    *(int *)(self + 0x48) = -1;
    *(short *)(self + 0x50) = 0;
    *(int *)(self + 0xED0) = 0;
    *(char *)(self + 0xED4) = 0;
    r = (int *)(self + 0xEE8);
    m = -1;
    for (j = 8; j >= 0; j--) r[j] = m;
    *(char *)(self + 0xF15) = 0;
}
