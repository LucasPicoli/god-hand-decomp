#include "godhand/vu0.h"

/* func_001835A0 - object constructor: base init, vtable@0x214, loop zeroing a
 * 5-quadword sub-block per slot (Obj0000_Set_Byte_54). while(i != -1) loop
 * form for retail bne-to-(-1). sn-2.95.3-136. */

extern void InitVtable214_429C80_1C27E8(void *);
#include "godhand/objField.h"
extern int D_00422C18;
__attribute__((section(".text.func_001835A0")))
void *func_001835A0(void *a0){
  char *s0; int i;
  InitVtable214_429C80_1C27E8(a0);
  s0 = (char*)a0 + 0x620;
  *(int**)((char*)a0+0x214) = &D_00422C18;
  i = 0;
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
