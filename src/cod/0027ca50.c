/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* func_0027CA50 — +0x2F6 phase machine, twin of func_0027C620. sn-2.95.3-136. */


__attribute__((section(".text.func_0027CA50")))
void func_0027CA50(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x90)+v0,*(int*)(v0+0x94)+v0,0.0f,5,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); break;
 case 2: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x98)+v0,*(int*)(v0+0x9C)+v0,0.0f,5,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3: moveMotion(s0); break;
 case 4: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xA0)+v0,*(int*)(v0+0xA4)+v0,0.0f,5,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 5: if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; } break; } }
