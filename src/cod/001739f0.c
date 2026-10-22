#include "godhand/vu0.h"

/* func_001739F0 - object constructor: base init, set vtable at 0x214, then loop zeroing
 * a 5-quadword sub-block per slot and tagging it (Obj0000_Set_Byte_54). Loop
 * uses the while(i != -1) form to match retail bne-to-(-1). sn-2.95.3-136. */

extern void func_001C7D98(void *);
#include "godhand/objField.h"
extern int D_00420FE0;
__attribute__((section(".text.func_001739F0")))
void *func_001739F0(void *a0){
  char *s0; int i;
  func_001C7D98(a0);
  s0 = (char*)a0 + 0x660;
  *(int**)((char*)a0+0x214) = &D_00420FE0;
  i = 5;
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
  return a0;
}
