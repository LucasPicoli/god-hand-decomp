/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int D_005FEE00[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Forward30F348_31CFE0(void);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern char D_00462FC0[];
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void Forward30A2B0_2DA9B8(void *a0);

__attribute__((section(".text.func_002803F0")))
void func_002803F0(void *a0){ char *s0=(char*)a0; int v0; unsigned long t0=0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x100)+v0,*(int*)(v0+0x104)+v0,0.0f,2,t0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x100)+v0,*(int*)(v0+0x104)+v0,0.0f,2,t0,0); }
  cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)Obj0000_Get_Field_424_1595F0(s0), s0, 0, 0, 0, 0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }

__attribute__((section(".text.func_002887D0")))
void func_002887D0(void *a0){ char *s0=(char*)a0; int v0;
 Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
 *(int*)(s0+0x15B0)=*(int*)(s0+0x15B0)|2;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(Forward30F348_31CFE0()&1){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0xA8)+v0,*(int*)(v0+0xAC)+v0,0.0f,10,0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0xB0)+v0,*(int*)(v0+0xB4)+v0,0.0f,10,0,0); }
  if(*(unsigned char*)(s0+0x2F7)==0)
   cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, s0, 0, 0, 0, 0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){
   if(*(int*)(s0+0x15B0)&0x80){
    *(unsigned char*)(s0+0x2F5)=7; *(unsigned char*)(s0+0x2F6)=0x12;
    *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F7)=0;
    break; }
   *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=2;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  CopyVec3From110To120_14A2B0(s0);
  break; } }

__attribute__((section(".text.func_00288660")))
void func_00288660(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int s2, s1;
  if(Forward30F348_31CFE0()&1){ int b=*(int*)(s0+0x304); s2=*(int*)(b+0x50)+b; s1=*(int*)(b+0x54)+b; }
  else { int b=*(int*)(s0+0x304); s2=*(int*)(b+0x58)+b; s1=*(int*)(b+0x5C)+b; }
  cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, s0, 0, 0, 0, 0);
  func_002A8578(s0,s2,s1,0.0f,5,0,0);
  *(int*)(s0+0x5F0)=10;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1; }
 case 1: {
  int t=*(int*)(s0+0x5F0);
  if(t!=0){ int q=*(int*)(s0+0x670);
   *(int*)(s0+0x5F0)=t-1;
   v0=*(int*)(q+0x34);
   if(v0!=0) AddScaledDeltaToField_104_2A7498(s0,*(int*)(v0+0xF0),*(float*)(s0+0x5A8)*0.39269909f); }
  if(moveMotion(s0)!=0){
   if(*(int*)(s0+0x15B0)&0x80){
    *(unsigned char*)(s0+0x2F5)=7; *(unsigned char*)(s0+0x2F6)=0x10;
    *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F7)=0;
    break; }
   *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=4;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  CopyVec3From110To120_14A2B0(s0);
  Forward30A2B0_2DA9B8(s0);
  break; } } }

__attribute__((section(".text.func_00280000")))
void func_00280000(void *a0){ char *s0=(char*)a0; int v0; void *s2=*(void**)(s0+0x1580);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(func_0026F1D8(s2)!=0){
   switch(Forward30F348_31CFE0()&1){
   case 0: default: v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0x110)+v0,*(int*)(v0+0x114)+v0,0.0f,2,0,0); break;
   case 1: v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0x110)+v0,*(int*)(v0+0x114)+v0,0.0f,2,0,0); break; } }
  else {
   switch((unsigned)Forward30F348_31CFE0()%3){
   case 0: default: v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xD0)+v0,*(int*)(v0+0xD4)+v0,0.0f,2,0,0); break;
   case 1: v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xD8)+v0,*(int*)(v0+0xDC)+v0,0.0f,2,0,0); break;
   case 2: v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xE0)+v0,*(int*)(v0+0xE4)+v0,0.0f,2,0,0); break; } }
  cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)Obj0000_Get_Field_424_1595F0(s0), s0, 0, 0, 0, 0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){
   if(func_0026F1D8(s2)!=0){
    *(unsigned char*)(s0+0x2F5)=0x10; *(unsigned char*)(s0+0x2F6)=2;
    *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F7)=0; }
   else {
    *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
    *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; } }
  break; } }
