/* func_002880C8 — ORs 0x10020 into the +0x15B0 flags, sets +0x54C=3.0f and runs
 * the 0x1346C8/0x134608 handler, then a +0x2F6 phase machine (record fields
 * 0x168/0x16C, mode 3) stepping moveMotion.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;

__attribute__((section(".text.func_002880C8")))
void func_002880C8(void *a0){ char *s0=(char*)a0; int v0;
 *(int*)(s0+0x15B0)=*(int*)(s0+0x15B0)|0x10020;
 *(float*)(s0+0x54C)=3.0f;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x168)+v0,*(int*)(v0+0x16C)+v0,0.0f,3,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); break; } }
