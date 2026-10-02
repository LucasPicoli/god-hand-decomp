/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern char *func_002DDAB0(int a0, float f, int a1);
extern void func_0026AB20(void *a0, char *a1, int a2);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00123938(void *a0, int a1);
extern float D_003BD488;

__attribute__((section(".text.func_00102DE8")))
void func_00102DE8(void *a0){ char *s0=(char*)a0; int p1,p2;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  switch(*(unsigned char*)(s0+0x2F7)){
  case 0: default: { char *v0=*(char**)(s0+0x304);
   p1=*(int*)(v0+0x34)+(int)v0; p2=*(int*)(v0+0x38)+(int)v0; } break;
  case 1: { char *v1=*(char**)(s0+0x304);
   p1=*(int*)(v1+0x3C)+(int)v1; p2=*(int*)(v1+0x40)+(int)v1; } break;
  case 2: { char *v2=*(char**)(s0+0x304);
   p1=*(int*)(v2+0x44)+(int)v2; p2=*(int*)(v2+0x48)+(int)v2; } break; }
  func_002A8578(s0,p1,p2,0.0f,5,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_0023F970")))
void func_0023F970(void *a0){ char *s2=(char*)a0; int v0,p1,p2,t0;
 switch(*(unsigned char*)(s2+0x2F6)){
 case 0:
  v0=*(int*)(s2+0x304);
  p1=*(int*)(v0+0x488)+v0; p2=*(int*)(v0+0x48C)+v0;
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s2)&0xFFFF;
  func_002A8578(s2,p1,p2,0.0f,3,t0,0);
  *(unsigned char*)(s2+0x2F6)=*(unsigned char*)(s2+0x2F6)+1;
 case 1:
  if(moveMotion(s2)!=0){ func_002705D8(s2); }
  cObjBase_addNullSpeed_Rotation(s2,1.0f);
  cObjBase_addNullSpeed(s2,1.0f); break; }
 if(*(int*)(s2+0x6EC)==0){
  if(*(unsigned short*)(s2+0x3AC)&1){
   char *a=func_002DDAB0(*(int*)(s2+0xF0),1.5f,1);
   if(a!=0) func_0026AB20(s2,a,*(unsigned short*)(a+0x2FE)); } } }

typedef struct { int w[3]; } T3;
__attribute__((section(".text.func_001AB8F8")))
void func_001AB8F8(void *a0){ char *s0=(char*)a0; char *g; T3 c; T3 t;
 g=*(char**)(s0+0x304);
 t.w[0]=*(int*)(g+0x18)+(int)g;
 t.w[1]=*(int*)(g+0x24)+(int)g;
 t.w[2]=*(int*)(g+0x30)+(int)g;
 c=t;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if((*(int*)(s0+0x9D0)&0x40000000)==0){
   *(unsigned char*)(s0+0x2F7)=0;
   *(unsigned char*)(s0+0x2F4)=0;
   *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0;
   *(int*)(s0+0x9D4)=0x3C;
   break; }
  func_002A8578(s0,c.w[*(unsigned char*)(s0+0x2F7)],0,0.0f,10,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_00237F98")))
void func_00237F98(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x146C)+v0,*(int*)(v0+0x1470)+v0,0.0f,0,0,0);
  *(float*)(*(char**)(s0+0xF0)+4)-=(*(float*)(s0+0x114)-1.0f)*1.6f;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  *(int*)(s0+0x16D0)|=0x10000;
  if(moveMotion(s0)!=0){ *(int*)(s0+0x16D0)&=0xFFFEFFFF; *(unsigned char*)(s0+0x2F5)=0x6C; *(unsigned char*)(s0+0x2F4)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }

__attribute__((section(".text.func_0010CB10")))
void func_0010CB10(void *a0){ char *s0=(char*)a0; char *t0; int p1,p2; void *fl;
 if(*(short*)(s0+0x54A)<=0) *(short*)(s0+0x54A)=1;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(short*)(s0+0x5E0)=0; *(short*)(s0+0x5E2)=0;
  Obj0000_Clear_Fields_640_648_124E58(s0);
  t0=*(char**)(s0+0x304); fl=*(void**)(s0+0x6A0);
  p1=*(int*)(t0+0x7C)+(int)t0; p2=*(int*)(t0+0x80)+(int)t0;
  if(fl!=0){
   func_002A8578(fl,*(int*)(t0+0x39C)+(int)t0,*(int*)(t0+0x3A0)+(int)t0,0.0f,5,0,0);
   { char *v0=*(char**)(s0+0x304);
   p1=*(int*)(v0+0x3A4)+(int)v0; p2=*(int*)(v0+0x3A8)+(int)v0; } }
  func_002A8578(s0,p1,p2,0.0f,5,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  *(float*)(s0+0x15F0)=D_003BD488;
  if(moveMotion(s0)!=0){ pl00_clearMotionCam(s0,1,0); *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  func_00123938(s0,1); break; } }

__attribute__((section(".text.func_00236ED0")))
void func_00236ED0(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x20000;
 *(float*)(s0+0x54C)=3.0f;
 *(int*)(s0+0x250)=*(int*)(s0+0x250)|0x10000;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x1BA0)+v0,*(int*)(v0+0x1BA4)+v0,0.0f,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break;
 case 2: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x1BA8)+v0,*(int*)(v0+0x1BAC)+v0,0.0f,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }
