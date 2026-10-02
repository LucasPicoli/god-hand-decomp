/* func_002884E0 — +0x2F6 phase machine: phase 0 fires func_002A8578 (record
 * fields 0xD8/0xDC, mode 0xA) and advances; both phases step moveMotion then
 * refresh the vec3 copy and forward the 0x30A2B0 handler.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
__attribute__((section(".text.func_002884E0")))
void func_002884E0(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0xD8)+v0,*(int*)(v0+0xDC)+v0,0.0f,0xA,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); cModel_calcNullPart(s0); Add_nullspeed(s0); break; } }
