/* func_002387B8 — runs the 0x1346C8 handler and sets +0x54C=3.0f, then a +0x2F6
 * phase machine (record fields 0x36D0/0x36D4, mode 0); phase 0 also clears +0x1864.
 * moveMotion-done reset re-arms 0x2F5=0x6C; 1.0f vector tail.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
__attribute__((section(".text.func_002387B8")))
void func_002387B8(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x36D0)+v0,*(int*)(v0+0x36D4)+v0,0.0f,0,0,0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }
