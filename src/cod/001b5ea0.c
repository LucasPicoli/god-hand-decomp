/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"
extern void func_00188798(void *a0);
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
#include "godhand/cOmTwin.h"
extern char D_005864F0[];
extern void func_001B6458(void *a0);

__attribute__((section(".text.func_001B5EA0")))
void func_001B5EA0(void *a0)
{
    struct {
        cVec pos;       /* 0x00 the effect position */
        cVec q10;       /* 0x10 */
        cVec q20;       /* 0x20 */
        float mtx[16];  /* 0x30 */
    } buf __attribute__((aligned(16)));
    cOmTwin *s1 = a0;
    cVtEnt *vt;
    int i;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    float *m1, *m2, *m3, *m4;
    cVec *q20v, *q10v;
    float rate;

    switch (s1->base.phase) {
    case 0: {
        float *r;
        if (s1->partA != 0) {
            ((cOmTwinPart *)s1->partA)->state |= COMTWIN_PART_LIVE;
            s1->partA->flags2 &= ~1;
        }
        if (s1->partB != 0) {
            ((cOmTwinPart *)s1->partB)->state |= COMTWIN_PART_LIVE;
            s1->partB->flags2 &= ~1;
        }
        VU0_SQC2_VF0(&buf.pos, 0x0);
        vt = s1->base.vtable;
        r = ((float *(*)(void *))vt[0x10].pfn)((char *)s1 + vt[0x10].delta);
        if (&buf.pos.x != r) {
            buf.pos.x = r[0];
            buf.pos.y = r[1];
            buf.pos.z = r[2];
        }
        SetEffectPos(0, 0x11, 0, &buf.pos, 1.0f, -1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x87, a0, 0, 0, 0, 0);
        func_001B6458(s1);
        SetField5B0Bit2ClearBit8_1B7908(s1);
        s1->base.phase = 1;
        *(int *)((char *)s1 + 0x850) = 0x1E;
        s1->base.step = 0;
        s1->base.stepArg = 0;
    }
        /* fallthrough */
    case 1:
        *(int *)((char *)s1 + 0x850) = *(int *)((char *)s1 + 0x850) - 1;
        if (*(int *)((char *)s1 + 0x850) <= 0) {
            *(int *)((char *)s1 + 0x850) = 0xF;
            s1->base.phase = 2;
            s1->base.step = 0;
            s1->base.stepArg = 0;
        }
        break;
    case 2: {
        int n = *(int *)((char *)s1 + 0x850) - 1;

        *(int *)((char *)s1 + 0x850) = n;
        s1->base.tint.w = (float)n / 15.0f;
        if (n <= 0) {
            s1->base.step = 0;
            s1->base.phase = 3;
            s1->base.stepArg = 0;
        }
        break;
    }
    case 3:
        s1->base.mode = 2;
        s1->base.phase = 0;
        s1->base.step = 0;
        s1->base.stepArg = 0;
        break;
    default:
        break;
    }
    i = 1;
    if (i < 6 && s1->base.partNum != i) {
        q20v = &buf.q20;
        q10v = &buf.q10;
        e40 = (char *)s1 + 0x6B0;
        e10 = (char *)s1 + 0x680;
        e30 = (char *)s1 + 0x6A0;
        e20 = (char *)s1 + 0x690;
        e = (char *)s1 + 0x670;
        for (; i < 6 && s1->base.partNum != i;) {
        one1 = 1;
        lim = -1000.0f;
        if (GetField_54_173900(e) == one1) {
            rate = cEmManage_GetSpeedRate(D_005864F0);
            VU0_LQC2(4, e20, 0);
            VU0_SQC2(4, &buf, 0x20);
            VU0_LQC2(4, &buf, 0x20);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, &buf, 0x20);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, &buf, 0x10);
            VU0_VADD_XYZ_IP(e10, -0x10, q10v);
            VU0_LQC2(4, e30, 0);
            VU0_SQC2(4, &buf, 0x20);
            VU0_LQC2(4, &buf, 0x20);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, &buf, 0x20);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, &buf, 0x10);
            VU0_VADD_XYZ_IP(e10, 0, q10v);
            Adjust_theta_vec((float *)e10);
            m1 = buf.mtx;
            MtxInitRotVec(m1, e10, 0);
            m1 = 0;
            m2 = buf.mtx;
            CopyVec3ToField30_147C40(m2, e);
            m2 = 0;
            m3 = buf.mtx;
            MtxMulScaleVec(m3, m3, e40);
            m3 = 0;
            m4 = buf.mtx;
            MtxCopy(*(int *)(e10 + 0x40), m4);
            m4 = 0;
            *(float *)(e10 + 0x14) = *(float *)(e10 + 0x14) + *(float *)(e10 + 0x48) * rate;
            if (*(float *)(e10 + 0x14) < lim) {
                Obj0000_Set_Byte_54(e, 0);
            }
        }
        i++;
        e40 += 0x60;
        e10 += 0x60;
        e30 += 0x60;
        e20 += 0x60;
        e += 0x60;
        }
    }
}
