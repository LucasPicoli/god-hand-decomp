/* func_00244610 — runs the 0x1346C8 handler and ORs 0x10000 into +0x16D0, then a
 * +0x2F6 phase machine (record fields 0x2494/0x2498, mode 3, t0 = low 16 bits of
 * the 0x17C3 getter); phase 0 also fires two func_002606E8 events (0x200, 0x203).
 * Shared tail steps moveMotion (func_002705D8 on completion) + 1.0f vectors. sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002606E8(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

__attribute__((section(".text.func_00244610")))
void func_00244610(void *a0){ char *s0=(char*)a0; int v0;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x10000;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x2494)+v0,*(int*)(v0+0x2498)+v0,0.0f,3,t0,0);
  func_002606E8(s0,0x200); func_002606E8(s0,0x203); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ func_002705D8(s0); }
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }
