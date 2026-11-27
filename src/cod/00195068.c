/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/vu0.h"
extern void func_00188798(void *a0);
extern void cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void func_00195620(void *a0);
extern void cSnd_SeStop(void *a0, int a1);
extern void KillEffect(int a0, int a1, int a2);
extern void cEmManage_CreateItem(void *a0, int a1, int a2, int a3);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
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
#include "godhand/cOmBreakable.h"
extern char D_005864F0[];

struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.cOmBreakable_stepBreak")))
void cOmBreakable_stepBreak(void *a0)
{
    char buf[0x80] __attribute__((aligned(16)));
    cOmBreakable *s1 = a0;
    struct VtEnt *vt;
    int i;
    int off;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    char *m1, *m2, *m3, *m4;
    char *q20v, *q10v;
    float rate;

    switch (s1->base.phase) {
    case 0: {
        int cnt, part;
        cOmBase *tt;
        unsigned char ok;
        if (*(int *)((char *)s1 + 0xB20) != 0) {
            cSnd_SeStop(&D_005FEE00, *(int *)((char *)s1 + 0xB20));
            *(int *)((char *)s1 + 0xB20) = 0;
        }
        VU0_SQC2_VF0(buf, 0x0);
        {
            int two = 2;
            cnt = s1->base.partNum;
            ok = ((*(int *)(buf + 0x10) = cnt), (two < cnt));
            if (ok) part = *(int *)(*(int *)((char *)s1 + 0x278) + 8); else part = 0;
        }
        ForwardVec3At30_147C60(buf, (float *)(part + 0x80));
        SetEffect(0x177, 2, a0, 0, -1, EFFECT_FOLLOW_OWNER);
        {
            int two = 2;
            cnt = s1->base.partNum;
            ok = ((*(int *)(buf + 0x10) = cnt), (two < cnt));
            if (ok) tt = (*(cOmBase ***)((char *)s1 + 0x278))[2]; else tt = 0;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x87, a0, 0, (cParts *)tt, 0, 0);
        KillEffect((int)s1, 1, 2);
        cEmManage_CreateItem(D_005864F0, (int)buf, 0xFFFF, 0);
        func_00195620(s1);
        SetField5B0Bit2ClearBit8_1B7908(s1);
        *(short *)((char *)s1 + 0xAF0) = 0x96;
        s1->base.phase = 1;
        s1->base.step = 0;
        s1->base.stepArg = 0;
    }
        /* fallthrough */
    case 1:
        *(short *)((char *)s1 + 0xAF0) = *(unsigned short *)((char *)s1 + 0xAF0) - 1;
        if (*(short *)((char *)s1 + 0xAF0) <= 0) {
            *(short *)((char *)s1 + 0xAF0) = 0xF;
            s1->base.phase = 2;
            s1->base.step = 0;
            s1->base.stepArg = 0;
        }
        break;
    case 2: {
        int n = *(unsigned short *)((char *)s1 + 0xAF0) - 1;

        *(short *)((char *)s1 + 0xAF0) = n;
        if ((short)n <= 0) {
            s1->base.step = 0;
            s1->base.phase = 3;
            s1->base.stepArg = 0;
        }
        break;
    }
    case 3:
        s1->base.mode = 0;
        s1->base.phase = 0;
        s1->base.step = 0;
        s1->base.stepArg = 0;
        break;
    default:
        break;
    }
    i = 3;
    if (i < 9 && s1->base.partNum != i) {
        q20v = buf + 0x30;
        q10v = buf + 0x20;
        e40 = (char *)s1 + 0x790;
        e10 = (char *)s1 + 0x760;
        e30 = (char *)s1 + 0x780;
        e20 = (char *)s1 + 0x770;
        e = (char *)s1 + 0x750;
        for (; i < 9 && s1->base.partNum != i; i++, e40 += 0x60, e10 += 0x60, e30 += 0x60, e20 += 0x60, e += 0x60) {
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
