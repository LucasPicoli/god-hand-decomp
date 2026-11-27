/* sn-2.95.3-136 matched TU. */

extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
__attribute__((section(".text.func_00115F60")))
void func_00115F60(void *a0) {
    cGameObj *s0 = a0;
    int v0;
    float one;
    s0->hitFlash = 5.0f;
    switch (s0->step) {
    case 0:
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_001268F0(s0);
        Obj0000_Clear_Fields_640_648_124E58(s0);
        *(float *)(*(int *)((char *)s0 + 0xF0) + 0) = *(float *)((char *)s0 + 0x660);
        *(float *)(*(int *)((char *)s0 + 0xF0) + 8) = *(float *)((char *)s0 + 0x668);
        {
            char *d = (char *)s0 + 0x490;
            char *p = (char *)*(int *)((char *)s0 + 0xF0);
            if (d != p) {
                *(float *)(d + 0) = *(float *)(p + 0);
                *(float *)(d + 4) = *(float *)(p + 4);
                *(float *)(d + 8) = *(float *)(p + 8);
            }
        }
        s0->rot.y = *(float *)((char *)s0 + 0x670);
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x8B8) + v0, *(int *)(v0 + 0x8BC) + v0, 0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            pl00_clearMotionCam(s0, 1, 0);
            s0->mode = 0; s0->phase = 0;
            s0->step = 0; s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
