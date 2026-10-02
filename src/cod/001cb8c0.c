/* func_001CB8C0 — refresh +0x5A8 speed-rate field, then a +0x2F6 phase machine
 * (record field 0xC, mode 0); phase 0 also spawns effect 0x7B/0xB8 via SetEffect,
 * and the moveMotion-done reset re-arms 0x2F5=1.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern float SetMotionStep(void *a0, float f);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int D_005864F0;
__attribute__((section(".text.func_001CB8C0")))
void func_001CB8C0(void *a0){ char *s0=(char*)a0; int v0;
 float r=cEmManage_GetSpeedRate(&D_005864F0);
 *(float*)(s0+0x5A8)=r;
 SetMotionStep(s0,r);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xC)+v0,0,0.0f,0,0,0);
  SetEffect(0x7B,0xB8,s0,0,-1,0xFFFFFFFFU);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=1;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; } break; } }
