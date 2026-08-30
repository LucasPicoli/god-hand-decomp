/* sn-2.95.3-136 matched TU. */

extern void cParts_setRotationOrder(void *a0, int a1);
extern void cModel_calcParts(void *a0);
extern void VecRotVec(void *a0, void *a1, void *a2, int a3);
extern float sqrtf(float x);
extern char *D_005CAFF0;
extern char D_003BD8C0[];

/* sn-2.95.3-136 matched TU. */








#include "godhand/vu0.h"

__attribute__((section(".text.func_00319520")))
void func_00319520(char *self)
{
    char buf[0x90] __attribute__((aligned(16)));
    unsigned long fl;
    unsigned char on;

    *(int *)(self + 0x250) = *(int *)(self + 0x250) & 0xFFDFFFFF;
    {
        char *m = *(char **)(self + 0x214);
        int (*fn)(void *);

        fn = *(int (**)(void *))(m + 0x34);
        if (fn(self + *(short *)(m + 0x30)) != 0) {
            *(int *)(self + 0x250) = *(int *)(self + 0x250) | 0x200000;
        }
    }
    if ((*(int *)(*(char **)(self + 0x320) + 0x34) & 0x4000000) != 0) {
        float *d = (float *)(self + 0x100);
        float *s = (float *)(D_005CAFF0 + 0x220);

        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        cParts_setRotationOrder(self, 4);
        if ((*(int *)(self + 0x250) & 0x200000) == 0) {
            cModel_calcParts(self);
        }
    }
    if ((*(int *)(*(char **)(self + 0x320) + 0x34) & 0x2000000) != 0) {
        *(float *)(self + 0x104) = *(float *)(D_005CAFF0 + 0x224);
        cParts_setRotationOrder(self, 4);
        if ((*(int *)(self + 0x250) & 0x200000) == 0) {
            cModel_calcParts(self);
        }
    }
    fl = *(int *)(*(char **)(self + 0x320) + 0x34);
    on = (fl >> 5) & 1;
    if (on != 0) {
        float *w;
        float *p70;
        float *p40;
        float kk;
        char *b1;

        VU0_SQC2_VF0(buf, 0x0);
        VU0_SQC2_VF0(buf, 0x10);
        w = (float *)(buf + 0x20);
        VU0_LQC2(4, D_003BD8C0, 0x0);
        VU0_SQC2(4, buf, 0x20);
        VecRotVec(buf, w, self + 0x100, 0);
        b1 = buf + 0x10;
        VU0_LQC2(4, D_003BD8C0, 0x0);
        VU0_SQC2(4, buf, 0x20);
        VecRotVec(b1, w, D_005CAFF0 + 0x220, 0);
        {
            char *m = *(char **)(self + 0x320);
            float x;
            float y;
            float z;

            p70 = (float *)(buf + 0x70);
            x = *(float *)(m + 0x28);
            y = *(float *)(m + 0x2C);
            z = *(float *)(m + 0x30);
            *(float *)(buf + 0x20) = x;
            *(float *)(buf + 0x24) = y;
            *(float *)(buf + 0x28) = z;
            kk = 0.01f;
            w[3] = 1.0f;
        }
        VU0_LQC2(4, buf, 0x0);
        VU0_SQC2(4, buf, 0x70);
        VU0_LQC2(4, buf, 0x70);
        VU0_LOAD_SCALAR(5, kk);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x70);
        VU0_LQC2(4, p70, 0x0);
        VU0_SQC2(4, buf, 0x60);
        {
            float d0 = *(float *)(buf + 0x0) * *(float *)(buf + 0x10)
                     + *(float *)(buf + 0x4) * *(float *)(buf + 0x14)
                     + *(float *)(buf + 0x8) * *(float *)(buf + 0x18);
            float dot = (d0 < 0.0f) ? 0.0f : d0;
            VU0_LQC2(4, buf + 0x60, 0x0);
            VU0_SQC2(4, buf, 0x70);
            VU0_LQC2(4, buf, 0x70);
            VU0_LOAD_SCALAR(5, dot);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x70);
        }
        VU0_LQC2(4, p70, 0x0);
        VU0_SQC2(4, buf, 0x50);
        {
            char *pf0 = *(char **)(self + 0xF0);
            char *cam = D_005CAFF0 + 0x210;

            VU0_SQC2_VF0(buf, 0x80);
            VU0_LQC2(4, pf0, 0x0);
            VU0_LQC2(5, cam, 0x0);
        }
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x80);
        VU0_LQC2(4, buf + 0x80, 0x0);
        VU0_SQC2(4, buf, 0x70);
        {
            float len = __builtin_sqrtf(
                *(float *)(buf + 0x70) * *(float *)(buf + 0x70)
                + *(float *)(buf + 0x78) * *(float *)(buf + 0x78));

            VU0_LQC2(4, buf + 0x50, 0x0);
            VU0_SQC2(4, buf, 0x80);
            VU0_LQC2(4, buf, 0x80);
            VU0_LOAD_SCALAR(5, len);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x80);
        }
        VU0_LQC2(4, buf + 0x80, 0x0);
        VU0_SQC2(4, buf, 0x40);
        p40 = (float *)(buf + 0x40);
        VU0_LQC2(4, w, 0x0);
        VU0_SQC2(4, buf, 0x80);
        VU0_LQC2(4, buf, 0x80);
        VU0_LQC2(5, p40, 0x0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x80);
        VU0_LQC2(4, buf + 0x80, 0x0);
        VU0_SQC2(4, buf, 0x30);
        {
            float *d = *(float **)(self + 0xF0);
            float *s = (float *)(buf + 0x30);

            if (d != s) {
                d[0] = *(float *)(buf + 0x30);
                d[1] = *(float *)(buf + 0x34);
                d[2] = *(float *)(buf + 0x38);
            }
        }
    }
}
