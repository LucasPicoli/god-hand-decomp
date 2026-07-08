/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0LengthSq(void *a0);
extern int Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(int a0);
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2, int a3, void *t0, void *t1, int t2);
extern int D_00569B70;
extern int D_00568288;
extern void func_001BEB28();

#include "godhand/vu0.h"









typedef void *(*GetVecFn)(void *);

__attribute__((section(".text.cOmea_ChkTreasureBox")))
void cOmea_ChkTreasureBox(void *a0) {
    char *obj = (char *)a0;
    long flags = *(unsigned int *)(obj + 0x600);
    if ((flags & 1) == 0) {
        char buf[32] __attribute__((aligned(16)));
        void *o = Obj0000_Get_D_00747A94_2DB6B0();
        char *vtA = *(char **)((char *)o + 0x214);
        GetVecFn fnA = *(GetVecFn *)(vtA + 0x84);
        void *vecA = fnA((char *)o + *(short *)(vtA + 0x80));
        char *vtB = *(char **)(obj + 0x214);
        GetVecFn fnB = *(GetVecFn *)(vtB + 0x84);
        void *vecB = fnB(obj + *(short *)(vtB + 0x80));
        float d;
        VU0_SQC2_VF0(buf, 0x10);
        VU0_LQC2(4, vecA, 0);
        VU0_LQC2(5, vecB, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0);
        VU0_SQC2(4, buf, 0);
        d = capVu0LengthSq(buf);
        if (d < 1.0f) {
            if (Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0((int)&D_00569B70) != 0) {
                LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 4, 0, 0, (void *)&func_001BEB28, obj, 0);
            }
        }
    }
}
