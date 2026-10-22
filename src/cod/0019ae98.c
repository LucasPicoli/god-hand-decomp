#include "godhand/vu0.h"

/* func_0019AE98 - object constructor: base init, vtable@0x214, loop zeroing a
 * sub-block per slot (Obj0000_Set_Byte_54), then a few trailing field clears.
 * while(i != -1) loop form for retail bne-to-(-1). sn-2.95.3-136. */

extern void InitFields_1B6E90(void *);
#include "godhand/objField.h"
extern int D_00425820;
__attribute__((section(".text.func_0019AE98")))
void *func_0019AE98(void *a0){
  char *s0; int i;
  InitFields_1B6E90(a0);
  s0 = (char*)a0 + 0x610;
  *(int**)((char*)a0+0x214) = &D_00425820;
  i = 11;
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
  *(signed char*)((char*)a0+0xA92) = 0;
  return a0;
}
