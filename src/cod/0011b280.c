/* sn-2.95.3-136 matched TU. */

extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

extern void func_0010A438(void *a0);
extern int D_007474A0;
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
__attribute__((section(".text.func_0011B280")))
void func_0011B280(void *a0){ char *s0=(char*)a0; int s2,s1;
 *(float*)(s0+0x54C)=15.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(*(unsigned char*)(s0+0x2F7)!=0 || (D_007474A0&0xF0)!=0){
   { char *v0=*(char**)(s0+0x304);
   s2=*(int*)(v0+0x51C)+(int)v0; s1=*(int*)(v0+0x520)+(int)v0; }
   Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0,10,0x17,0x2A,0,10);
   Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0,10,0x17,0x2A,0,10);
   *(char*)(s0+0x1684)=0;
  } else {
   { char *v1=*(char**)(s0+0x304);
   s2=*(int*)(v1+0x174)+(int)v1; s1=*(int*)(v1+0x178)+(int)v1; } }
  func_002A8578(s0,s2,s1,0.0f,10,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  if(func_00123938(s0,1)==0) func_0010A438(s0); break; } }
