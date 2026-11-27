/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/globals.h"

extern unsigned int Rnd(void);
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_00279C20(void *a0);
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
#include "godhand/cObj.h"
extern char D_005864F0[];

__attribute__((section(".text.func_00278C30")))
void func_00278C30(void *a0)
{
    cObj *s0 = a0;
    cObj *g = (cObj *)D_00586A7C;
    float one;

    switch (s0->step) {
    case 0: {
        float f = 0.0f;
        char *v0;
        if (s0->stepArg == 0) {
            f = (float)(int)(Rnd() % 0xF0);
        }
        v0 = s0->pack;
        s0->stepArg = 1;
        func_002A8578(s0, *(int *)(v0 + 0xC) + (int)v0, *(int *)(v0 + 0x10) + (int)v0, 5, f, 0, 0);
        s0->step += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s0) != 0) {
            if ((Rnd() & 1) != 0) {
                s0->step = 2;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    case 2: {
        char *v0 = s0->pack;
        func_002A8578(s0, *(int *)(v0 + 0x14) + (int)v0, *(int *)(v0 + 0x18) + (int)v0, 5, 0.0f, 0, 0);
        s0->step += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0) {
            if ((Rnd() & 1) != 0) {
                s0->step = 0;
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    if (g != 0) {
        if (g->mode == 1) {
            func_00279C20(s0);
            s0->stepArg = 0;
            s0->mode = 0;
            s0->step = 0;
            s0->phase = 5;
        }
    }
}

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

__attribute__((section(".text.func_001881F0")))
void func_001881F0(void *a0)
{
    struct {
        cVec pos;       /* 0x00 the effect position */
        cVec q10;       /* 0x10 */
        cVec q20;       /* 0x20 */
        float mtx[16];  /* 0x30 */
    } buf __attribute__((aligned(16)));
    cOmBase *s1 = a0;
    cVtEnt *vt;
    int i;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    float *m1, *m2, *m3, *m4;
    cVec *q20v, *q10v;
    float rate;

    switch (s1->phase) {
    case 0: {
        float *r;
        VU0_SQC2_VF0(&buf.pos, 0x0);
        vt = s1->vtable;
        r = ((float *(*)(void *))vt[0x10].pfn)((char *)s1 + vt[0x10].delta);
        if (&buf.pos.x != r) {
            buf.pos.x = r[0];
            buf.pos.y = r[1];
            buf.pos.z = r[2];
        }
        SetEffectPos(0, 7, 0, &buf.pos, 1.0f, -1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, a0, 0, 0, 0, 0);
        func_00188798(s1);
        SetField5B0Bit2ClearBit8_1B7908(s1);
        if (*(int *)((char *)s1 + 0x608) != 0) {
            cDamageUnit_SetDamageCollFlashActive(*(void **)((char *)s1 + 0x608), 1, 1);
        }
        s1->phase = 1;
        *(short *)((char *)s1 + 0x600) = 0x1E;
        s1->step = 0;
        s1->stepArg = 0;
    }
        /* fallthrough */
    case 1:
        *(short *)((char *)s1 + 0x600) = *(unsigned short *)((char *)s1 + 0x600) - 1;
        if (*(short *)((char *)s1 + 0x600) <= 0) {
            *(short *)((char *)s1 + 0x600) = 0xF;
            s1->phase = 2;
            s1->step = 0;
            s1->stepArg = 0;
        }
        break;
    case 2: {
        int n = *(unsigned short *)((char *)s1 + 0x600) - 1;

        *(short *)((char *)s1 + 0x600) = n;
        s1->tint.w = (float)(short)n / 15.0f;
        if ((short)n <= 0) {
            s1->step = 0;
            s1->phase = 3;
            s1->stepArg = 0;
        }
        break;
    }
    case 3:
        s1->mode = 3;
        s1->phase = 0;
        s1->step = 0;
        s1->stepArg = 0;
        break;
    default:
        break;
    }
    i = 0;
    if (i < 6 && s1->partNum != i) {
        q20v = &buf.q20;
        q10v = &buf.q10;
        e40 = (char *)s1 + 0x650;
        e10 = (char *)s1 + 0x620;
        e30 = (char *)s1 + 0x640;
        e20 = (char *)s1 + 0x630;
        e = (char *)s1 + 0x610;
        for (; i < 6 && s1->partNum != i; i++, e40 += 0x60, e10 += 0x60, e30 += 0x60, e20 += 0x60, e += 0x60) {
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
        }
    }
}
