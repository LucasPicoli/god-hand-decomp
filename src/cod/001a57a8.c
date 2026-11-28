/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/vu0.h"
extern void func_00188798(void *a0);
extern void cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void func_001A5D68(void *a0);
extern void SetField5B0Bit2ClearBit8_1B7908(void *a0);
extern void cDamageUnit_SetDamageCollFlashActive(void *a0, int a1, int a2);
extern int GetField_54_173900(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern void Adjust_theta_vec(float *p);
extern void MtxInitRotVec(void *a0, void *a1, int a2);
extern void CopyVec3ToField30_147C40(void *a0, void *a1);
extern void MtxMulScaleVec(void *a0, void *a1, void *a2);
extern int MtxCopy();
#include "godhand/objField.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmBase.h"
extern char D_005864F0[];

__attribute__((section(".text.func_001A57A8")))
void func_001A57A8(void *a0)
{
    char buf[0x80] __attribute__((aligned(16)));
    cOmBase *s1 = a0;
    cVtEnt *vt;
    int i;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    char *m1, *m2, *m3, *m4;
    char *q20v, *q10v;
    float rate;

    switch (s1->phase) {
    case 0: {
        float *r;
        int cnt, idx;
        cOmBase *tt;
        unsigned char ok;
        VU0_SQC2_VF0(buf, 0x0);
        vt = s1->vtable;
        r = ((float *(*)(void *))vt[0x10].pfn)((char *)s1 + vt[0x10].delta);
        if ((float *)buf != r) {
            ((float *)buf)[0] = r[0];
            ((float *)buf)[1] = r[1];
            ((float *)buf)[2] = r[2];
        }
        SetEffect(1, 3, a0, 0, -1, EFFECT_FOLLOW_OWNER);
        cnt = s1->partNum;
        idx = 1;
        do { } while (0);
        ok = ((*(int *)(buf + 0x10) = cnt), (idx >= 0 && idx < cnt));
        if (ok) tt = s1->children[idx]; else tt = 0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x95, a0, 0, (cParts *)tt, 0, 0);
        if (*(int *)((char *)s1 + 0x620) != 0) {
            cDamageUnit_SetDamageCollActive(*(void **)((char *)s1 + 0x620), 0);
        }
        func_001A5D68(s1);
        SetField5B0Bit2ClearBit8_1B7908(s1);
        *(short *)((char *)s1 + 0x628) = 0x1E;
        s1->phase = 1;
        s1->step = 0;
        s1->stepArg = 0;
    }
        /* fallthrough */
    case 1:
        *(short *)((char *)s1 + 0x628) = *(unsigned short *)((char *)s1 + 0x628) - 1;
        if (*(short *)((char *)s1 + 0x628) <= 0) {
            *(short *)((char *)s1 + 0x628) = 0xF;
            s1->phase = 2;
            s1->step = 0;
            s1->stepArg = 0;
        }
        break;
    case 2: {
        int n = *(unsigned short *)((char *)s1 + 0x628) - 1;

        *(short *)((char *)s1 + 0x628) = n;
        s1->tint.w = (float)(short)n / 15.0f;
        if ((short)n <= 0) {
            s1->step = 0;
            s1->phase = 3;
            s1->stepArg = 0;
        }
        break;
    }
    case 3:
        s1->mode = 2;
        s1->phase = 0;
        s1->step = 0;
        s1->stepArg = 0;
        break;
    default:
        break;
    }
    i = 1;
    if (i < 7 && s1->partNum != i) {
        q20v = buf + 0x30;
        q10v = buf + 0x20;
        e40 = (char *)s1 + 0x6D0;
        e10 = (char *)s1 + 0x6A0;
        e30 = (char *)s1 + 0x6C0;
        e20 = (char *)s1 + 0x6B0;
        e = (char *)s1 + 0x690;
        for (; i < 7 && s1->partNum != i; i++, e40 += 0x60, e10 += 0x60, e30 += 0x60, e20 += 0x60, e += 0x60) {
        one1 = 1;
        lim = -1000.0f;
        if (GetField_54_173900(e) == one1) {
            rate = cEmManage_GetSpeedRate(D_005864F0);
            VU0_LQC2(4, e20, 0);
            VU0_SQC2(4, buf, 0x30);
            VU0_LQC2(4, buf, 0x30);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x30);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_VADD_XYZ_IP(e10, -0x10, q10v);
            VU0_LQC2(4, e30, 0);
            VU0_SQC2(4, buf, 0x30);
            VU0_LQC2(4, buf, 0x30);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x30);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_VADD_XYZ_IP(e10, 0, q10v);
            Adjust_theta_vec((float *)e10);
            m1 = buf + 0x40;
            MtxInitRotVec(m1, e10, 0);
            m1 = 0;
            m2 = buf + 0x40;
            CopyVec3ToField30_147C40(m2, e);
            m2 = 0;
            m3 = buf + 0x40;
            MtxMulScaleVec(m3, m3, e40);
            m3 = 0;
            m4 = buf + 0x40;
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
