/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern float capVu0LengthSq(void *a0);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, void *t0, void *t1, int t2);
extern int D_00568288;
extern void func_001BEB28();

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"









typedef void *(*GetVecFn)(void *);

__attribute__((section(".text.cOmea_ChkTreasureBox")))
void cOmea_ChkTreasureBox(void *a0) {
    char *obj = (char *)a0;
    long flags = *(unsigned int *)(obj + 0x600);
    if ((flags & 1) == 0) {
        char buf[32] __attribute__((aligned(16)));
        void *o = Getplayer();
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
            if (cCoreSave_getCasinoTicketNum(&D_00569B70) != 0) {
                cActionButton_set(&D_00568288, 4, 0, 0, (void *)&func_001BEB28, obj, 0);
            }
        }
    }
}
