/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"

extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float *cGameObj_findBurningPos(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012A3C0(void *a0);
extern void func_00123938(void *a0, int a1);

__attribute__((section(".text.func_0010FF80")))
void func_0010FF80(void *a0)
{
    float b[12] __attribute__((aligned(16)));
    cGameObj *s0 = a0;
    char *s1;
    float *src;
    float *dp;
    float *dd;
    float *d;
    char *obj;
    char *q;
    char *q2;
    char *obj2;
    float k;
    float one;
    int t;

    VU0_SQC2_VF0(b, 0);
    switch (s0->step) {
    case 0:
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s0);
        s1 = (char *)s0 + 0x580;
        func_00126770(s0);
        pl00_clearMotionCam(s0, 0, 0);
        src = cGameObj_findBurningPos(s0);
        if ((float *)s1 != src) {
            s0->unk580.x = src[0];
            *(float *)(s1 + 4) = src[1];
            *(float *)(s1 + 8) = src[2];
        }
        t = *(int *)((char *)s0 + 0x304);
        /* Called as int-returning: the $v0 def steers obj and d into v1 and a0. */
        ((int (*)(void *, int, int, int, float, int, int))func_002A8578)(
            s0, *(int *)(t + 0x20C) + t, *(int *)(t + 0x6DC) + t, 3, 15.0f, 0, 0);
        obj = *(char **)((char *)s0 + 0xF0);
        d = &b[4];
        VU0_SQC2_VF0(b, 0x20);
        VU0_LQC2(4, s1, 0);
        VU0_LQC2(5, obj, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        q = (char *)b + 0x20;
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, b, 0x10);
        dp = (float *)((char *)s0 + 0x590);
        if (dp != d) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            dp[0] = t0;
            *(volatile float *)&dp[1] = t1;
            t2 = *(volatile float *)&b[6];
            dp[2] = t2;
        }
        s0->step = s0->step + 1;
    case 1:
        k = 0.1f;
        q2 = (char *)b + 0x20;
        VU0_LQC2(4, (char *)s0 + 0x590, 0);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, b, 0x20);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, q2, 0);
        VU0_SQC2(4, b, 0x10);
        dd = b;
        src = &b[4];
        if (dd != src) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            t2 = b[6];
            dd[0] = t0;
            dd[1] = t1;
            dd[2] = t2;
        }
        obj2 = *(char **)((char *)s0 + 0xF0);
        VU0_LQC2(4, obj2, 0);
        VU0_LQC2(5, b, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, obj2, 0);
        VU0_LQC2(4, s0, 0x590);
        VU0_LQC2(5, b, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, s0, 0x590);
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        if (!(s0->seqFlags & 4)) {
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
    if (s0->seqFlags & 1) {
        func_0012A3C0(s0);
    }
    s0->seqFlags = s0->seqFlags | 0x200;
    func_00123938(s0, 1);
}
