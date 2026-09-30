/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern char D_00462FC0[];
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);

#include "godhand/vu0.h"
__attribute__((section(".text.func_00239698")))
void func_00239698(void *a0){ char *s0=(char*)a0; char *s1=(char*)Obj0000_Get_D_00747A94_2DB6B0(); char *p; char *q; int b;
 Forward_001346C8_00134608_1351D8(D_00462FC0,s0,0);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(char*)(s0+0x1864)=0;
  b=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(b+0x1484)+b,*(int*)(b+0x1488)+b,0.0f,0,0,0);
  *(short*)(s0+0x56E)=0xF;
  (*(unsigned char*)(s0+0x2F6))++;
 case 1:
  if(*(short*)(s0+0x56E)!=0){
   (*(short*)(s0+0x56E))--;
   p=*(char**)(s0+0xF0); q=s1+0x550;
   VU0_VADD_XYZ_IP(p,0,q); }
  *(float*)(s0+0x54C)=3.0f;
  if(moveMotion(s0)!=0){ *(char*)(s0+0x2F4)=0; *(char*)(s0+0x2F5)=0x6C; *(char*)(s0+0x2F6)=0; *(char*)(s0+0x2F7)=0; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f); break; } }

#include "godhand/vu0.h"
__attribute__((section(".text.func_00236C60")))
void func_00236C60(void *a0){ char *s0=(char*)a0; char *s1=(char*)Obj0000_Get_D_00747A94_2DB6B0(); char *p; char *q; int b;
 Forward_001346C8_00134608_1351D8(D_00462FC0,s0,0);
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(char*)(s0+0x1864)=0;
  b=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(b+0x1D98)+b,*(int*)(b+0x1D9C)+b,0.0f,0,0,0);
  *(short*)(s0+0x56E)=0xF;
  (*(unsigned char*)(s0+0x2F6))++;
 case 1:
  *(int*)(s0+0x250)=*(int*)(s0+0x250)|0x40000;
  if(*(short*)(s0+0x56E)!=0){
   (*(short*)(s0+0x56E))--;
   p=*(char**)(s0+0xF0); q=s1+0x550;
   VU0_VADD_XYZ_IP(p,0,q); }
  if(moveMotion(s0)!=0){ *(char*)(s0+0x2F4)=0; *(char*)(s0+0x2F5)=0x6C; *(char*)(s0+0x2F6)=0; *(char*)(s0+0x2F7)=0; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f); break; } }
