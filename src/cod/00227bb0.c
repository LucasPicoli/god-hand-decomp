/* func_00227BB0 — sets +0x186A=2, ORs 0x400 into +0x16D4, then a +0x2F6 phase
 * machine (record fields 0x1EAC/0x1EB0, mode 0, t0 = low 16 bits of the 0x17C3
 * getter); phase 0 clears +0x1864. Shared tail steps moveMotion, adds the
 * 1.0f-scaled vectors, and re-arms 0x2F5=0x25 when +0x618 < 484.0f.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

__attribute__((section(".text.func_00227BB0")))
void func_00227BB0(void *a0){ char *s0=(char*)a0; int v0;
 *(unsigned char*)(s0+0x186A)=2;
 *(int*)(s0+0x16D4)=*(int*)(s0+0x16D4)|0x400;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: { int t0;
  *(char*)(s0+0x1864)=0;
  t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  v0=*(int*)(s0+0x304);
  func_002A8578(s0,*(int*)(v0+0x1EAC)+v0,*(int*)(v0+0x1EB0)+v0,0.0f,0,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  moveMotion(s0);
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  if(*(float*)(s0+0x618)<484.0f){
   *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x25;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  break; } }
