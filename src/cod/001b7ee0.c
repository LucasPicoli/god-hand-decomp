/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0LengthSq(void *a0);
extern int Dest_ck(void *a0, void *a1, float f12, float f13);
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern char D_00568288;

#include "godhand/vu0.h"







typedef void *(*vfn)(void *);

__attribute__((section(".text.func_001B7EE0")))
void func_001B7EE0(void *a0, float fp12) {
    char *s2 = (char *)a0;
    float saved = fp12;
    char buf[32] __attribute__((aligned(16)));
    long flag = *(unsigned int *)(s2 + 0x5B0);

    if (((flag >> 1) & 1) == 0) {
        void *o = Obj0000_Get_D_00747A94_2DB6B0();
        char *vt = *(char **)((char *)o + 0x214);
        void *p1 = (*(vfn *)(vt + 0x84))((char *)o + *(short *)(vt + 0x80));
        char *vt2 = *(char **)(s2 + 0x214);
        void *p2 = (*(vfn *)(vt2 + 0x6C))(s2 + *(short *)(vt2 + 0x68));

        VU0_SQC2_VF0(buf, 0x10);
        VU0_LQC2(4, p1, 0x0);
        VU0_LQC2(5, p2, 0x0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0x0);
        VU0_SQC2(4, buf, 0x0);

        if (capVu0LengthSq(buf) < saved * saved) {
            void *o1 = Obj0000_Get_D_00747A94_2DB6B0();
            char *vta = *(char **)((char *)o1 + 0x214);
            void *r1 = (*(vfn *)(vta + 0x84))((char *)o1 + *(short *)(vta + 0x80));
            void *o2 = Obj0000_Get_D_00747A94_2DB6B0();
            char *vtb = *(char **)((char *)o2 + 0x214);
            void *r2 = (*(vfn *)(vtb + 0x8C))((char *)o2 + *(short *)(vtb + 0x88));
            char *vtc = *(char **)(s2 + 0x214);
            void *r3 = (*(vfn *)(vtc + 0x6C))(s2 + *(short *)(vtc + 0x68));
            if (Dest_ck(r1, r3, *(float *)((char *)r2 + 0x4), 1.3089969f) != 0) {
                LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 3, 0x1B, 0x12, 0, 0, 0);
            }
        }
    }
}
