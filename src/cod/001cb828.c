/* func_001CB828 — refresh speed-rate field then a +0x2F6 phase machine (record field 0xC,
 * mode 0) stepping moveMotion.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern float SetMotionStep(void *a0, float f);
extern int D_005864F0;
__attribute__((section(".text.func_001CB828")))
void func_001CB828(void *a0){ char *s0=(char*)a0; int v0;
 float r=cEmManage_GetSpeedRate(&D_005864F0);
 *(float*)(s0+0x5A8)=r;
 SetMotionStep(s0,r);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xC)+v0,0,0.0f,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); break; } }
