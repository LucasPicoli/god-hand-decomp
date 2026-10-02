/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_0023ADB8")))
void func_0023ADB8(void *a0){ char *s0=(char*)a0; int v0;
 *(float*)(s0+0x54C)=5.0f;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x20000;
 *(char*)(s0+0x617)=1;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(char*)(s0+0x1864)=0;
  { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
    v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xBE8)+v0,*(int*)(v0+0xBEC)+v0,0.0f,0xA,t0,0); }
  { int t=*(int*)(s0+0x16D0); t=t&0xFFFF7FFF; t=t&0xFFFFFFFD; *(int*)(s0+0x16D0)=t; }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
  *(short*)(s0+0x54A)=0;
 case 1:
  *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x400000;
  moveMotion(s0);
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  if(*(int*)(s0+0x16D0)&0x20000000){ *(unsigned char*)(s0+0x2F6)=2; }
  break;
 case 2:
  { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
    v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xBF0)+v0,*(int*)(v0+0xBF4)+v0,0.0f,3,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  moveMotion(s0);
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  break;
 case 4:
  { int t0=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
    v0=*(int*)(s0+0x304);
    func_002A8578(s0,*(int*)(v0+0xBF0)+v0,*(int*)(v0+0xBF4)+v0,64.0f,0,t0,0); }
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 5:
  moveMotion(s0);
  cObjBase_addNullSpeed_Rotation(s0,1.0f);
  cObjBase_addNullSpeed(s0,1.0f);
  break; } }
