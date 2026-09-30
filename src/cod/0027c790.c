/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern unsigned char D_005FEE00[];

/* func_00281D98 */


__attribute__((section(".text.func_00281D98")))
void func_00281D98(void *a0){ char *s0=(char*)a0; int v0;
 int t0=0; unsigned long two=2;
 if(*(unsigned char*)(s0+0x15B0)) t0=two;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  switch(*(unsigned char*)(s0+0x2F7)){
  case 0: default: v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x2C)+v0,*(int*)(v0+0x30)+v0,0.0f,5,t0,0); break;
  case 1: v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x34)+v0,*(int*)(v0+0x38)+v0,0.0f,5,t0,0); break; }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); break; } }

__attribute__((section(".text.func_0027F6B0")))
void func_0027F6B0(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x3C)+v0,*(int*)(v0+0x44)+v0,0.0f,5,0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x3C)+v0,*(int*)(v0+0x40)+v0,0.0f,5,0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }

__attribute__((section(".text.func_00281E60")))
void func_00281E60(void *a0){ char *s0=(char*)a0; int v0;
 int t0=0; unsigned long two=2;
 if(*(unsigned char*)(s0+0x15B0)) t0=two;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x54)+v0,*(int*)(v0+0x5C)+v0,0.0f,5,t0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x54)+v0,*(int*)(v0+0x58)+v0,0.0f,5,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }

__attribute__((section(".text.func_0027FD00")))
void func_0027FD00(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x80)+v0,*(int*)(v0+0x88)+v0,0.0f,5,0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x80)+v0,*(int*)(v0+0x84)+v0,0.0f,5,0,0); }
  *(int*)(s0+0x5F0)=1;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }

__attribute__((section(".text.func_00280688")))
void func_00280688(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x158)+v0,*(int*)(v0+0x15C)+v0,0.0f,2,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); break;
 case 2: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x160)+v0,*(int*)(v0+0x164)+v0,0.0f,2,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3: moveMotion(s0); break; } }

__attribute__((section(".text.func_0027C790")))
void func_0027C790(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  cSnd_SeCall_2CBA48(D_005FEE00, 1, 12, s0, 0, 0, 0, 0);
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x40)+v0,*(int*)(v0+0x44)+v0,0.0f,0,0,0); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x38)+v0,*(int*)(v0+0x3C)+v0,0.0f,0,0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }
