/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_0028FB08(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Forward30A2B0_2DA9B8(void *a0);
extern float fRand0_1(void);
extern char D_00462FC0[];
extern char D_005FEE00[];
__attribute__((section(".text.func_00287090")))
void func_00287090(void *a0){ char *s0=(char*)a0; int v0; float f;
 Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(int*)(s0+0x15B0)=*(int*)(s0+0x15B0)|1;
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x110)+v0,*(int*)(v0+0x114)+v0,0.0f,0,0,0);
  *(float*)(s0+0x600)=10.0f;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  moveMotion(s0);
  CopyVec3From110To120_14A2B0(s0);
  Forward30A2B0_2DA9B8(s0);
  f=*(float*)(s0+0x600)-*(float*)(s0+0x5A8);
  *(float*)(s0+0x600)=f;
  if(f<=0.0f){
   cSnd_SeCall_2CBA48(D_005FEE00,2,0x60,s0,0,0,0,0);
   *(float*)(s0+0x600)=fRand0_1()*60.0f+90.0f; }
  break;
 case 2:
  { int b=*(int*)(s0+0x304);
  *(short*)(s0+0x54A)=0;
  func_002A8578(s0,*(int*)(b+0x118)+b,*(int*)(b+0x11C)+b,0.0f,0,0,0); }
  func_0028FB08(s0);
  cCoreSave_addKillNpcNum(&D_00569B70);
  cSnd_SeCall_2CBA48(D_005FEE00,1,0x5F,s0,0,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  moveMotion(s0);
  CopyVec3From110To120_14A2B0(s0);
  Forward30A2B0_2DA9B8(s0);
  break; } }
