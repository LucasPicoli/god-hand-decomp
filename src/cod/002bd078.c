/* sn-2.95.3-136 matched TU. */

extern void func_0032A6D0(void *x, int mode, short v);
extern void ForwardVec3At30_147C60(void *d, void *s);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void func_002BC950(void *a, void *b, float f12, float f13, void *c);

/* sn-2.95.3-136 candidate. */





__attribute__((section(".text.func_003823E0")))
void func_003823E0(void *a0, char *p, unsigned char flag)
{
    unsigned short *q;
    unsigned short *r;
    unsigned short *e;
    char *c;
    void *h;
    void *t;
    int mode;
    int i;
    int j;

    c = p + 0x30;
    if (flag != 0) {
        q = (unsigned short *)(p + 0x22);
        mode = 1;
        e = (unsigned short *)(p + (*(unsigned char *)(p + 2) * 2 + 0x22));
    } else {
        q = (unsigned short *)(p + 0x18);
        mode = 0;
        e = (unsigned short *)(p + (*(unsigned char *)(p + 2) * 2 + 0x18));
    }
    if (*(unsigned char *)(p + 2) == 0) {
        r = q + 1;
        for (j = 3; j >= 0; j--) {
            *r = *q;
            r++;
        }
    } else {
        if (func_00382520(a0, p) != 0) {
            *q = *e;
        }
    }
    h = *(void **)(c + 0x20);
    if (h != 0) {
        if (*(unsigned char *)(p + 2) != 0) {
            t = func_0032DCD0(h, *(unsigned char *)(p + 2) - 1);
            func_0032A6D0(t, mode, *e);
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
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"





static __inline__ void CopyVec3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_002BD078")))
void func_002BD078(void *obj, void *mtx, char *src, float f12, float f13)
{
    unsigned char f[0x40];
    float v[8][4];
    float *pB;
    float *pT;
    float *pL;
    char *z;
    unsigned int i;
    int n;

    VU0_SQC2_VF0(f, 0x0);
    VU0_SQC2_VF0(f, 0x10);
    ForwardVec3At30_147C60(f, obj);
    *(float *)(f + 0x14) = f13;
    pB = (float *)(f + 0x10);
    pT = (float *)(f + 0x30);
    VU0_LQC2(4, pB, 0x0);
    VU0_SQC2(4, f, 0x30);
    sceVu0ApplyMatrix(pT, obj, pT);
    VU0_LQC2(4, pT, 0x0);
    VU0_SQC2(4, f, 0x20);
    {
        float x = *(float *)(f + 0x20);
        float y = *(float *)(f + 0x24);
        float zz = *(float *)(f + 0x28);

        *(float *)(f + 0x10) = x;
        *(float *)(f + 0x14) = y;
        *(float *)(f + 0x18) = zz;
    }
    z = (char *)v;
    n = 7;
    do {
        VU0_SQC2_VF0(z, 0x0);
        z += 0x10;
    } while (--n != -1);
    for (i = 0; i < 8; i++) {
        pL = (float *)(f + 0x30);
        VU0_LQC2(4, src + i * 0x10, 0x0);
        VU0_SQC2(4, f, 0x30);
        sceVu0ApplyMatrix(pL, mtx, pL);
        VU0_LQC2(4, pL, 0x0);
        VU0_SQC2(4, f, 0x20);
        CopyVec3(v[i], (float *)(f + 0x20));
    }
    func_002BC950(f, f + 0x10, f12, f13, v);
}
