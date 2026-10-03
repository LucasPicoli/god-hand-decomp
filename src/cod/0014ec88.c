#include "godhand/cObjBase.h"

/* sn-2.95.3-136 matched TU. */

extern int setMotionInfo(cObjBase *self, char *motion, char *motionEnd, unsigned int start,

float rate, float blend, int flags);

extern unsigned int func_0031ED08(float seconds);
extern int moveMotion(cObjBase *self);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern void Obj1D00_SetState_6_A(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);

/* Phase 3: start the stored motion, play it until it ends and keep moving the
 * model by its null-part speed. */
__attribute__((section(".text.func_0014EC88")))
void func_0014EC88(cObjBase *self) {
    float one;
    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->motionEnd, func_0031ED08(self->motionStart),
                      self->motionRate, self->motionBlend, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed(self, one);
        break;
    case 2:
        moveMotion(self);
        one = 1.0f;
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00237E90")))
void func_00237E90(void *a0){ char *s0=(char*)a0; int v0; float one;
 cCollisionSolidManage_SetActive(&D_00462FC0,s0,0);
 *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)|0x20000;
 *(float*)(s0+0x54C)=3.0f;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1864)=0;
  func_002A8578(s0,*(int*)(v0+0x1550)+v0,*(int*)(v0+0x1554)+v0,0.0f,0,0,0);
  if(*(int*)(s0+0x6F0)!=0) Obj1D00_SetState_6_A((void*)*(int*)(s0+0x6F0));
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0x6C;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(s0,one);
  cObjBase_addNullSpeed(s0,one); break; } }

__attribute__((section(".text.func_001ABA20")))
void func_001ABA20(void *a0){ char *s0=(char*)a0; int v0; float one;
 if(*(int*)(s0+0x9D4)!=0) (*(int*)(s0+0x9D4))--;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: v0=*(int*)(s0+0x304);
  *(int*)(s0+0x9D0)=*(int*)(s0+0x9D0)&0xBFFFFFFF;
  setMotionInfo((int)s0,*(int*)(v0+0x40)+v0,*(int*)(v0+0x68)+v0,0,0.0f,0.0f,0);
  moveMotion(s0);
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(s0,one);
  cObjBase_addNullSpeed(s0,one); break;
 case 2: *(unsigned char*)(s0+0x2F6)=(unsigned char)*(unsigned char*)(s0+0x2F6)+1;
 case 3:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  one=1.0f;
  cObjBase_addNullSpeed_Rotation(s0,one);
  cObjBase_addNullSpeed(s0,one); break; } }
