/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/globals.h"

extern int ClearField5B4IfFlagUnset_1B76B0(void *a0);
extern void func_001B76D8(void *a0);
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

struct Pmf { short delta; short index; union { void *fn; short vo; } u; };
typedef struct { char b[0x20]; } Tbl32;

__attribute__((section(".text.func_001A2AA8")))
void func_001A2AA8(void *a0)
{
    char frame[0x80] __attribute__((aligned(16)));
    cObj *s2 = a0;
    struct Pmf *pm;
    cVtEnt *vt;
    void *fn;
    long ve;
    int ix, off8;
    char *q4;
    char *th;
    int dl;
    int *new_var;
    struct Pmf *pm3;
    unsigned short n2;
    int i;
    int one1;
    float lim;
    char *e, *e10, *e20, *e30, *e40;
    char *m1, *m2, *m3, *m4;
    char *q20v, *q10v;
    float rate;

    if (ClearField5B4IfFlagUnset_1B76B0(s2) == 0) {
        return;
    }
    *(Tbl32 *)frame = *(Tbl32 *)D_00426F50;
    pm = (struct Pmf *)frame + s2->mode;
    ix = pm->index;
    if (ix >= 0) {
        vt = *(cVtEnt **)((char *)s2 + pm->u.vo);
        ve = *(long *)((char *)vt + (ix - 1) * 8);
        fn = (void *)(int)(ve >> 32);
    } else {
        q4 = frame + 4;
        off8 = s2->mode * 8;
        fn = *(void **)(q4 + off8);
    }
    dl = (pm3 = (struct Pmf *)frame + s2->mode)->delta;
    new_var = &dl;
    dl = (ix >= 0) ? (short)ve + (*new_var) : dl;
    th = (char *)s2 + dl;
    i = 0;
    ((void (*)(void *))fn)(th);
    if (s2->partNum != i) {
        q20v = frame + 0x30;
        q10v = frame + 0x20;
        e40 = (char *)s2 + 0x650;
        e10 = (char *)s2 + 0x620;
        e30 = (char *)s2 + 0x640;
        e20 = (char *)s2 + 0x630;
        e = (char *)s2 + 0x610;
        for (; i < 0x14 && s2->partNum != i; i++, e40 += 0x60, e10 += 0x60, e30 += 0x60, e20 += 0x60, e += 0x60) {
        one1 = 1;
        lim = -1000.0f;
        if (GetField_54_173900(e) == one1) {
            rate = cEmManage_GetSpeedRate(D_005864F0);
            VU0_LQC2(4, e20, 0);
            VU0_SQC2(4, frame, 0x30);
            VU0_LQC2(4, frame, 0x30);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, frame, 0x30);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, frame, 0x20);
            VU0_VADD_XYZ_IP(e10, -0x10, q10v);
            VU0_LQC2(4, e30, 0);
            VU0_SQC2(4, frame, 0x30);
            VU0_LQC2(4, frame, 0x30);
            VU0_LOAD_SCALAR(5, rate);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, frame, 0x30);
            VU0_LQC2(4, q20v, 0);
            VU0_SQC2(4, frame, 0x20);
            VU0_VADD_XYZ_IP(e10, 0, q10v);
            Adjust_theta_vec((float *)e10);
            m1 = frame + 0x40;
            MtxInitRotVec(m1, e10, 0);
            m1 = 0;
            m2 = frame + 0x40;
            CopyVec3ToField30_147C40(m2, e);
            m2 = 0;
            m3 = frame + 0x40;
            MtxMulScaleVec(m3, m3, e40);
            m3 = 0;
            m4 = frame + 0x40;
            MtxCopy(*(int *)(e10 + 0x40), m4);
            m4 = 0;
            *(float *)(e10 + 0x14) = *(float *)(e10 + 0x14) + *(float *)(e10 + 0x48) * rate;
            if (*(float *)(e10 + 0x14) < lim) {
                do { do { Obj0000_Set_Byte_54(e, 0); } while (0); } while (0);
            }
        }
        }
    }
    func_001B76D8(s2);
}
