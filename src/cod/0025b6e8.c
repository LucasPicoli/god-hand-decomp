/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float capVu0Atan2(float y, float x);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj2810_SetState_E_a1(void *a0, int a1);
extern void SetBytes2F4Mode11_283360(void *a0, int a1);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_0026F120(void *a0);

extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
__attribute__((section(".text.func_0025B6E8")))
void func_0025B6E8(void *a0){ char *s0=(char*)a0;
 float buf[4];
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: {
  float f20=3.1415927f;
  int s1=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  float z=0.0f;
  float turn=z;
  int v1=*(int*)(s0+0x698);
  int p1, p2;
  if(v1!=0 && *(int*)(v1+0x34)!=0){
   VU0_LQC2(4, (char*)v1 + 0x10, 0);
   VU0_SQC2(4, buf, 0);
   { float bz=buf[2]; float at=capVu0Atan2(buf[0], bz);
   turn=Turn_dest_dir(*(float*)(s0+0x104), at, f20); }
   { float ad=turn; if(turn<z) ad=-turn; f20=ad; }
  }
  if(*(unsigned char*)(s0+0x2F7)==2){
   if(turn<0.0f) *(unsigned char*)(s0+0x2F7)=2; else *(unsigned char*)(s0+0x2F7)=3;
   if(f20<0.7853982f) *(unsigned char*)(s0+0x2F7)=4;
   if(2.3561945f<f20) *(unsigned char*)(s0+0x2F7)=5;
  }
  switch(*(unsigned char*)(s0+0x2F7)){
  default: case 0: { int b=*(int*)(s0+0x304); p1=*(int*)(b+0x3DC4)+b; p2=*(int*)(b+0x3DC8)+b; } break;
  case 1: { int b=*(int*)(s0+0x304); p1=*(int*)(b+0x3DBC)+b; p2=*(int*)(b+0x3DC0)+b; } break;
  case 2: { int b=*(int*)(s0+0x304); int q1=*(int*)(b+0x3DCC); int q2=*(int*)(b+0x3DD0); { int fl=*(int*)(s0+0x16D0)&0xFEFFFFFF; p1=q1+b; *(int*)(s0+0x16D0)=fl; p2=q2+b; } } break;
  case 3: { int b=*(int*)(s0+0x304); int q1=*(int*)(b+0x3DD4); int q2=*(int*)(b+0x3DD8); { int fl=*(int*)(s0+0x16D0)&0xFEFFFFFF; p1=q1+b; *(int*)(s0+0x16D0)=fl; p2=q2+b; } } break;
  case 4: { int b=*(int*)(s0+0x304); int q1=*(int*)(b+0x3DDC); int q2=*(int*)(b+0x3DE0); { int fl=*(int*)(s0+0x16D0)&0xFEFFFFFF; p1=q1+b; *(int*)(s0+0x16D0)=fl; p2=q2+b; } } break;
  case 5: { int b=*(int*)(s0+0x304); int q1=*(int*)(b+0x3DE4); int q2=*(int*)(b+0x3DE8); { int fl=*(int*)(s0+0x16D0)&0xFEFFFFFF; p1=q1+b; *(int*)(s0+0x16D0)=fl; p2=q2+b; } } break;
  }
  func_002A8578(s0,p1,p2,0.0f,2,s1,0);
  if(*(int*)(s0+0x748)) Obj2810_SetState_E_a1(*(void**)(s0+0x748),*(unsigned char*)(s0+0x2F7));
  if(*(int*)(s0+0x74C)) SetBytes2F4Mode11_283360(*(void**)(s0+0x74C),*(unsigned char*)(s0+0x2F7));
  if(*(int*)(s0+0x750)) ClearBytes2F4To2F7_283170(*(void**)(s0+0x750));
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1; }
 case 1:
  if(moveMotion(s0)!=0){
   if(*(unsigned char*)(s0+0x2F7)>=2){
    func_0026F120(s0);
    if(func_0026F1D8(s0)!=0){ func_00270C78(s0); return; }
   }
   func_002705D8(s0);
  }
  break; }
 if(*(float*)(s0+0x176C)<=0.0f){
  *(unsigned char*)(s0+0x2F5)=0xA5; *(unsigned char*)(s0+0x2F6)=2;
  *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F7)=0; }
}
