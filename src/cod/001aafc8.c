/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern void KillEffect(void *a0, int a1, int a2);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f);
extern unsigned int Rnd(void);
extern int func_002DDAB0(void *a0, int a1, float f);
extern void func_0026EE40(void *a0, int a1, int a2);

__attribute__((section(".text.func_00279750")))
void func_00279750(void *a0){ char *s0=(char*)a0; int v0;
 Forward_001346C8_00134608_1351D8(&D_00462FC0,s0,0);
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xC)+v0,*(int*)(v0+0x10)+v0,0.0f,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=2; *(unsigned char*)(s0+0x2F5)=1;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  else {
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f); } break; } }

__attribute__((section(".text.func_00247218")))
void func_00247218(void *a0){ char *s0=(char*)a0;
 *(unsigned char*)(s0+0x617)=1;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF; int a, bb;
  if(*(int*)(s0+0x564)==0x24F){ int b=*(int*)(s0+0x304); a=*(int*)(b+0x1F70)+b; bb=*(int*)(b+0x1F74)+b; }
  else { int b=*(int*)(s0+0x304); a=*(int*)(b+0x1F78)+b; bb=*(int*)(b+0x1F7C)+b; }
  func_002A8578(s0,a,bb,0.0f,0xA,t0,0); }
  *(short*)(s0+0x568)=0xA;
  *(unsigned char*)(s0+0x623)=1;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ func_002705D8(s0); }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  if(*(short*)(s0+0x568)>0) *(short*)(s0+0x568)=*(unsigned short*)(s0+0x568)-1;
  else *(unsigned char*)(s0+0x623)=0;
  break; } }

#define ARM { int b=*(int*)(s0+0x304); a=*(int*)(b+0xC4C)+b; bb=*(int*)(b+0xC50)+b; }
__attribute__((section(".text.func_0023D410")))
void func_0023D410(void *a0){ char *s0=(char*)a0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0; int a, bb;
  *(char*)(s0+0x1864)=0;
  switch(*(int*)(s0+0x564)){
  case 0x20A ... 0x20E: ARM break;
  case 0x218: ARM break;
  case 0x245 ... 0x247: ARM break;
  case 0x24F ... 0x251: ARM break;
  case 0x278 ... 0x279: ARM break;
  default: ARM break; }
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  func_002A8578(s0,a,bb,0.0f,0xA,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6E;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  break; }
 if(*(unsigned short*)(s0+0x3AC)&8) *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x4000; }

__attribute__((section(".text.func_001AAFC8")))
void func_001AAFC8(void *a0){ char *s0=(char*)a0; int v0;
 if(*(int*)(s0+0x9D4)!=0) *(int*)(s0+0x9D4)=*(int*)(s0+0x9D4)-1;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(int*)(s0+0x9D0)=*(int*)(s0+0x9D0)&0xBFFFFFFF;
  { int b=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(b+0xC)+b,*(int*)(b+0x6C)+b,0.0f,0xA,0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){
   if(*(int*)(s0+0x9D0)<0){ *(unsigned char*)(s0+0x2F7)=0; *(int*)(s0+0x9E4)=0;
    *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1; } }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  break;
 case 2:
  v0=*(int*)(s0+0x304);
  setMotionInfo(s0,*(int*)(v0+0xC)+v0,0,0,0.0f,0.0f,0);
  moveMotion(s0);
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  if((*(int*)(s0+0x9E4))++<0x12C && *(unsigned char*)(s0+0x2F7)==0){
   KillEffect(s0,0xA,2);
   *(unsigned char*)(s0+0x2F7)=*(unsigned char*)(s0+0x2F7)+1; }
  break; } }

__attribute__((section(".text.func_00277858")))
void func_00277858(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x64)+v0,*(int*)(v0+0x68)+v0,0.0f,3,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  AddScaledDeltaToField_104_2A7498(s0,*(int*)((char*)Obj0000_Get_D_00747A94_2DB6B0()+0xF0),*(float*)(s0+0x5A8)*0.09817477f);
  if(moveMotion(s0)!=0 && (Rnd()&1)!=0) *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  break;
 case 2:
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xC)+v0,*(int*)(v0+0x10)+v0,0.0f,3,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  AddScaledDeltaToField_104_2A7498(s0,*(int*)((char*)Obj0000_Get_D_00747A94_2DB6B0()+0xF0),*(float*)(s0+0x5A8)*0.09817477f);
  if(moveMotion(s0)!=0 && (Rnd()&1)!=0) *(unsigned char*)(s0+0x2F6)=0;
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  break; }
 if(func_002DDAB0(*(void**)(s0+0xF0),0,10.0f)!=0){
  *(unsigned char*)(s0+0x2F7)=0;
  *(unsigned char*)(s0+0x2F4)=0;
  *(unsigned char*)(s0+0x2F6)=0;
  *(unsigned char*)(s0+0x2F5)=2;
 } }

#define ARM(o1,o2) { int b=*(int*)(s0+0x304); a=*(int*)(b+o1)+b; bb=*(int*)(b+o2)+b; }
#define IDSW(o1,o2) switch(*(int*)(s0+0x564)){ \
  case 0x20A ... 0x20E: ARM(o1,o2) break; \
  case 0x218: ARM(o1,o2) break; \
  case 0x245 ... 0x247: ARM(o1,o2) break; \
  case 0x24F ... 0x251: ARM(o1,o2) break; \
  case 0x278 ... 0x279: ARM(o1,o2) break; \
  default: ARM(o1,o2) break; }
__attribute__((section(".text.func_0023D568")))
void func_0023D568(void *a0){ char *s0=(char*)a0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0; int a, bb;
  *(char*)(s0+0x1864)=0;
  IDSW(0xC2C,0xC30)
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  func_002A8578(s0,a,bb,0.0f,0xA,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F6)=2; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  if(*(int*)(s0+0x16EC)>0) *(unsigned char*)(s0+0x2F6)=2;
  break;
 case 2: { int t0; int a, bb;
  IDSW(0xC34,0xC38)
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  func_002A8578(s0,a,bb,0.0f,0xA,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  if(moveMotion(s0)!=0){ func_0026EE40(s0,0,0); func_002705D8(s0); break; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
  break; }
 if(*(unsigned short*)(s0+0x3AC)&8) *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x4000; }
