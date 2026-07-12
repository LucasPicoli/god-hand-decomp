/* sn-2.95.3-136 matched TU. */

extern void func_0030A700(void *, void *, float);
extern void func_0030A7B8(void *, void *, float);
extern void func_0030A650(void *, void *, float);
extern void sceVu0RotMatrix(void *, void *, void *);

#include "godhand/vu0.h"






__attribute__((section(".text.MtxInitRotVec")))
void MtxInitRotVec(void *a0, float *a1, unsigned char order) {
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, a0, 0x30);
    VU0_SQC2(5, a0, 0x20);
    VU0_SQC2(6, a0, 0x10);
    VU0_SQC2(7, a0, 0x0);
    switch (order) {
    case 0:
        func_0030A700(a0, a0, a1[0]);
        func_0030A7B8(a0, a0, a1[1]);
        func_0030A650(a0, a0, a1[2]);
        break;
    case 1:
        func_0030A700(a0, a0, a1[0]);
        func_0030A650(a0, a0, a1[2]);
        func_0030A7B8(a0, a0, a1[1]);
        break;
    case 2:
        func_0030A7B8(a0, a0, a1[1]);
        func_0030A700(a0, a0, a1[0]);
        func_0030A650(a0, a0, a1[2]);
        break;
    case 3:
        func_0030A7B8(a0, a0, a1[1]);
        func_0030A650(a0, a0, a1[2]);
        func_0030A700(a0, a0, a1[0]);
        break;
    case 4:
        func_0030A650(a0, a0, a1[2]);
        func_0030A700(a0, a0, a1[0]);
        func_0030A7B8(a0, a0, a1[1]);
        break;
    case 5:
        sceVu0RotMatrix(a0, a0, a1);
        break;
    }
}
