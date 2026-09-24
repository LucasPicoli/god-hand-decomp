/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"

extern void ForwardVec3At30_147C60(void *d, void *s);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float Tramp_001F7DF8_00101E28(void *v);
extern void func_002BC950(void *a, void *b, float f12, float f13, void *c);

static __inline__ void CopyVec3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_002BC6C8")))
void func_002BC6C8(void *obj, void *mtx, char *src, float f12, float f13)
{
    unsigned char f[0x50];
    float v[8][4];
    float *pB;
    float *pC;
    float *pD;
    float *d;
    float *pT;
    char *s;
    char *z;
    float len;
    float t;
    unsigned int i;
    int n;

    VU0_SQC2_VF0(f, 0x0);
    VU0_SQC2_VF0(f, 0x10);
    pC = (float *)(f + 0x20);
    pB = (float *)(f + 0x10);
    VU0_SQC2_VF0(f, 0x20);
    ForwardVec3At30_147C60(f, obj);
    pD = (float *)(f + 0x40);
    *(float *)(f + 0x14) = f13;
    VU0_LQC2(4, pB, 0x0);
    VU0_SQC2(4, pC, 0x20);
    sceVu0ApplyMatrix(pD, obj, pD);
    VU0_LQC2(4, pD, 0x0);
    VU0_SQC2(4, f, 0x30);
    *(float *)(f + 0x10) = *(float *)(f + 0x30);
    *(float *)(f + 0x14) = *(float *)(f + 0x34);
    *(float *)(f + 0x18) = *(float *)(f + 0x38);
    VU0_SQC2_VF0(f, 0x40);
    VU0_LQC2(4, pB, 0x0);
    VU0_LQC2(5, f, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, pC, 0x20);
    VU0_LQC2(4, pD, 0x0);
    VU0_SQC2(4, f, 0x30);
    *(float *)(f + 0x20) = *(float *)(f + 0x30);
    *(float *)(f + 0x24) = *(float *)(f + 0x34);
    *(float *)(f + 0x28) = *(float *)(f + 0x38);
    VU0_SQC2_VF0(f, 0x40);
    len = Tramp_001F7DF8_00101E28(pC);
    if (0.0f < len) {
        t = 1.0f / len;
        *(float *)(f + 0x4C) = pC[3];
        *(float *)(f + 0x40) = *(float *)(f + 0x20) * t;
        *(float *)(f + 0x44) = pC[1] * t;
        *(float *)(f + 0x48) = pC[2] * t;
    }
    VU0_LQC2(4, pD, 0x0);
    VU0_SQC2(4, f, 0x30);
    *(float *)(f + 0x20) = *(float *)(f + 0x30);
    *(float *)(f + 0x24) = *(float *)(f + 0x34);
    *(float *)(f + 0x28) = *(float *)(f + 0x38);
    VU0_LQC2(4, f, 0x20);
    VU0_LOAD_SCALAR(5, f12);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x20);
    VU0_LQC2(4, f, 0x0);
    VU0_LQC2(5, f + 0x20, 0x0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x0);
    VU0_LQC2(4, f, 0x10);
    VU0_LQC2(5, f + 0x20, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x10);
    f13 = f13 - (f12 + f12);
    z = (char *)v;
    n = 7;
    do {
        VU0_SQC2_VF0(z, 0x0);
        z += 0x10;
    } while (--n != -1);
    do {
        for (i = 0; i < 8; i++) {
            pT = (float *)(f + 0x30);
            VU0_LQC2(4, src + i * 0x10, 0x0);
            VU0_SQC2(4, f, 0x30);
            sceVu0ApplyMatrix(pT, mtx, pT);
            VU0_LQC2(4, pT, 0x0);
            VU0_SQC2(4, f, 0x20);
            CopyVec3(v[i], (float *)(f + 0x20));
        }
        func_002BC950(f, f + 0x10, f12, f13, v);
    } while (0);
}
