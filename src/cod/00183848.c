/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"

extern void InitFields_1B6E90(void *);
extern void Obj0000_Set_Byte_54(void *, int);
extern int D_00422EB8;
__attribute__((section(".text.func_00183848")))
void *func_00183848(void *a0){
  char *s0; int i;
  InitFields_1B6E90(a0);
  s0 = (char*)a0 + 0x670;
  *(int**)((char*)a0+0x214) = &D_00422EB8;
  i = 0x13;
  do {
    VU0_SQC2_VF0(s0, 0x0);
    VU0_SQC2_VF0(s0, 0x10);
    VU0_SQC2_VF0(s0, 0x20);
    VU0_SQC2_VF0(s0, 0x30);
    VU0_SQC2_VF0(s0, 0x40);
    Obj0000_Set_Byte_54(s0, 0);
    s0 += 0x60;
    i--;
  } while(i != -1);
  VU0_SQC2_VF0(a0, 0xDF0);
  VU0_SQC2_VF0(a0, 0xE00);
  return a0;
}
