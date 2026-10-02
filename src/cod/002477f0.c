/* func_002477F0 — sets +0x54C=3.0f, ORs 0x20000 into +0x16D0, then a +0x2F6 phase
 * machine (record fields 0x23F8/0x23FC, mode 0; t0 = low 16 bits of the 0x17C3
 * getter) stepping moveMotion and adding the 1.0f-scaled vectors.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
__attribute__((section(".text.func_002477F0")))
void func_002477F0(void *a0){ char *s0=(char*)a0; int v0;
 *(float*)(s0+0x54C)=3.0f;
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x20000;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x23F8)+v0,*(int*)(v0+0x23FC)+v0,0.0f,0,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1: moveMotion(s0); cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f); break; } }
