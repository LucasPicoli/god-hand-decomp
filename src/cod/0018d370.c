/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
extern void func_00188798(void *a0);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];
extern void SetField5B0Bit2ClearBit8_1B7908(void *a0);
extern void cDamageUnit_SetDamageCollFlashActive(void *a0, int a1, int a2);
extern int GetField_54_173900(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern void Adjust_theta_vec(float *p);
extern void MtxInitRotVec(void *a0, void *a1, int a2);
extern void CopyVec3ToField30_147C40(void *a0, void *a1);
extern void MtxMulScaleVec(void *a0, void *a1, void *a2);
extern int MtxCopy();
extern void Obj0000_Set_Byte_54(void *a0, int a1);
extern char D_005864F0[];
extern void func_0018D8F8(void *a0);

struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.func_0018D370")))
void func_0018D370(void *a0)
{
    char buf[0x70] __attribute__((aligned(16)));
    char *s1 = (char *)a0;
    struct VtEnt *vt;
    int i;
    int off;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    char *m1, *m2, *m3, *m4;
    char *q20v, *q10v;
    float rate;

    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0: {
        float *r;
        VU0_SQC2_VF0(buf, 0x0);
        vt = *(struct VtEnt **)(s1 + 0x214);
        r = ((float *(*)(void *))vt[0x10].pfn)(s1 + vt[0x10].delta);
        if ((float *)buf != r) {
            ((float *)buf)[0] = r[0];
            ((float *)buf)[1] = r[1];
            ((float *)buf)[2] = r[2];
        }
        SetEffectPos(0, 0xCB, 0, buf, -1, 1.0f);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xF, s1, 0, 0, 0, 0);
        func_0018D8F8(s1);
        SetField5B0Bit2ClearBit8_1B7908(s1);
        *(unsigned char *)(s1 + 0x2F5) = 1;
        *(short *)(s1 + 0x654) = 0x1E;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
    }
        /* fallthrough */
    case 1:
        *(short *)(s1 + 0x654) = *(unsigned short *)(s1 + 0x654) - 1;
        if (*(short *)(s1 + 0x654) <= 0) {
            *(short *)(s1 + 0x654) = 0xF;
            *(unsigned char *)(s1 + 0x2F5) = 2;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    case 2: {
        int n = *(unsigned short *)(s1 + 0x654) - 1;

        *(short *)(s1 + 0x654) = n;
        *(float *)(s1 + 0x24C) = (float)(short)n / 15.0f;
        if ((short)n <= 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 3;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    }
    case 3:
        *(unsigned char *)(s1 + 0x2F4) = 3;
        *(unsigned char *)(s1 + 0x2F5) = 0;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    default:
        break;
    }
    i = 1;
    if (i < 6 && *(unsigned char *)(s1 + 0x2B4) != i) {
        q20v = buf + 0x20;
        q10v = buf + 0x10;
        e40 = s1 + 0x700;
        e10 = s1 + 0x6D0;
        e30 = s1 + 0x6F0;
        e20 = s1 + 0x6E0;
        e = s1 + 0x6C0;
        for (; i < 6 && *(unsigned char *)(s1 + 0x2B4) != i; i++, e40 += 0x60, e10 += 0x60, e30 += 0x60, e20 += 0x60, e += 0x60) {
        one1 = 1;
        lim = -1000.0f;
        if (GetField_54_173900(e) == one1) {
            rate = cEmManage_GetSpeedRate(D_005864F0);
            VU0_LQC2(4, e20, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, buf, 0x20);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, buf, 0x10);
            VU0_VADD_XYZ_IP(e10, -0x10, q10v);
            VU0_LQC2(4, e30, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, buf, 0x20);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, buf, 0x10);
            VU0_VADD_XYZ_IP(e10, 0, q10v);
            Adjust_theta_vec((float *)e10);
            m1 = buf + 0x30;
            MtxInitRotVec(m1, e10, 0);
            m1 = 0;
            m2 = buf + 0x30;
            CopyVec3ToField30_147C40(m2, e);
            m2 = 0;
            m3 = buf + 0x30;
            MtxMulScaleVec(m3, m3, e40);
            m3 = 0;
            m4 = buf + 0x30;
            MtxCopy(*(int *)(e10 + 0x40), m4);
            m4 = 0;
            *(float *)(e10 + 0x14) = *(float *)(e10 + 0x14) + *(float *)(e10 + 0x48) * rate;
            if (*(float *)(e10 + 0x14) < lim) {
                Obj0000_Set_Byte_54(e, 0);
            }
        }
        }
    }
}
