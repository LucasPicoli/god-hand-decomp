#include "godhand/vu0.h"
#include "godhand/globals.h"

/* func_00182888 — InitFields constructor: base-init, install vtable &D_00422A80, zero a
 * $vf0 block at +0x600 (count 0xD, 4 quadwords, stride 0x50), then a
 * func_002AD238 sub-init with the object's region pointers.  sn-2.95.3-136. */

extern void InitFields_1B6E90(void*);
extern void func_002AD238(void*, int, int, void*, void*, int);

__attribute__((section(".text.func_00182888")))
void *func_00182888(void *a0){
  char *v1; int i;
  InitFields_1B6E90(a0);
  *(int**)((char*)a0+0x214) = &D_00422A80;
  v1 = (char*)a0 + 0x600;
  i = 0xD;
  do {
    VU0_SQC2_VF0(v1,0x0); VU0_SQC2_VF0(v1,0x10); VU0_SQC2_VF0(v1,0x20); VU0_SQC2_VF0(v1,0x30);
    v1 += 0x50; i--;
  } while(i != -1);
  func_002AD238((char*)a0+0xB10, 6, 1, (char*)a0+0x600, (char*)a0+0xA60, 0x7);
  return a0;
}
