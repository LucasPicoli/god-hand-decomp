/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"

extern void func_002FBED0(void *self);
extern char *cWorldLight_Get_LightData2(void *a0, int a1, int a2);
extern void cWorldLight_Del_LightData(void *a0, int a1, int a2);
extern void cWorldLight_Set_LightData(void *a0, void *a1);
extern float Adjust_theta(float f12);
extern void MtxInitRotVec(void *a0, void *a1, int a2);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void cNode_setLocalTranslation(void *self, void *v);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern char D_00604700[];

__attribute__((section(".text.func_002E7E10")))
void func_002E7E10(char *p)
{
    float buf[16] __attribute__((aligned(16)));
    char *l;
    char *m;
    char *q;
    float *x;
    float *d;
    float *y;
    float *e;
    float fa, fb, fc;

    func_002FBED0(p);
    if (*(unsigned char *)(p + 0x2CA) != 0) {
        VU0_LQC2(4, p + 0x2F0, 0x0);
        VU0_SQC2(4, buf, 0x0);
        l = cWorldLight_Get_LightData2(D_00604700, *(unsigned short *)(p + 0x2B2), *(int *)(p + 0x2B4));
        if (l == 0) return;
        m = p + 0x310;
        *(float *)(p + 0x304) = Adjust_theta(*(float *)(p + 0x304) + (float)*(unsigned char *)(p + 0x2CC) * 0.0174532924f);
        MtxInitRotVec(m, p + 0x300, 0);
        sceVu0ApplyMatrix(buf, m, buf);
        q = *(char **)(p + 0x350);
        x = &buf[8];
        y = &buf[12];
        fa = *(float *)(q + 0xB0);
        fb = *(float *)(q + 0xB4);
        fc = *(float *)(q + 0xB8);
        buf[8] = fa;
        buf[9] = fb;
        buf[10] = fc;
        x[3] = 1.0f;
        VU0_LQC2(4, x, 0x0);
        VU0_SQC2(4, buf, 0x30);
        VU0_LQC2(4, buf, 0x30);
        VU0_LQC2(5, buf, 0x0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x30);
        VU0_LQC2(4, y, 0x0);
        VU0_SQC2(4, buf, 0x10);
        d = (float *)(l + 0x10);
        e = &buf[4];
        if (d != e) {
            d[0] = buf[4];
            d[1] = buf[5];
            d[2] = buf[6];
        }
        cNode_setLocalTranslation(p, buf);
    } else if (*(unsigned char *)(p + 0x2CD) != 0) {
        StoreVecFromFieldB0_2B6160(buf, p);
        e = (float *)(p + 0x370);
        if (e != buf) {
            e[0] = buf[0];
            e[1] = buf[1];
            e[2] = buf[2];
        }
        cWorldLight_Del_LightData(D_00604700, *(unsigned short *)(p + 0x2B2), *(int *)(p + 0x2B4));
        cWorldLight_Set_LightData(D_00604700, p + 0x360);
    }
}
