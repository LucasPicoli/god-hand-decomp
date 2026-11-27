/* sn-2.95.3-136 matched TU. */

extern void func_0012C348(void *a0, int a1);
extern float capVu0Atan2(float y, float x);
extern float Adjust_theta(float f12);
extern void *Getplayer(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
#include "godhand/cSnd.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cSnd_DieDemoStart(void *a0);
extern void func_00124EC0(void *a0);
extern int D_00747A24;

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
__attribute__((section(".text.func_00103170")))
void func_00103170(void *a0)
{
    float buf[4];
    cGameObj *s0 = a0;
    void *s1;
    float one;
    s1 = Getplayer();
    s0->hitFlash = 5.0f;
    switch (s0->step) {
    case 0:
    {
        int v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x2C) + v0, *(int *)(v0 + 0x30) + v0, 1, 0.0f, 0, 0);
    }
        SetEffect(0, 0x52, a0, 0, -1, EFFECT_FOLLOW_OWNER);
        func_0012C348(s1, 0);
        pl00_clearMotionCam(s1, 0, 0);
        {
            char *p = *(char **)((char *)s0 + 0x5B0);
            if (p != 0) {
                float th;
                VU0_LQC2(4, p + 0x10, 0);
                VU0_SQC2(4, buf, 0);
                th = capVu0Atan2(buf[0], buf[2]) + 3.14159274f;
                s0->rot.y = th;
                s0->rot.y = Adjust_theta(th);
            }
        }
        s0->step = s0->step + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00122D18")))
void func_00122D18(void *a0)
{
    cGameObj *s1 = a0;
    int s2;
    int s0;
    float one;

    s1->hitFlash = 30.0f;
    switch (s1->step) {
    case 0:
        {
            int b = *(int *)((char *)s1 + 0x304);
            s2 = *(int *)(b + 0x16C) + b;
            s0 = *(int *)(b + 0x170) + b;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, a0, 0, 0, 0, 0);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -1000);
        func_0012C348(s1, 3);
        func_002A8578(s1, s2, s0, 2, 0.0f, 0, 0);
        *(int *)((char *)s1 + 0x15B0) = 0x82;
        s1->step = s1->step + 1;
    case 1:
        func_00124EC0(s1);
        if (*(int *)((char *)s1 + 0x15B0) != 0) {
            *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) - 1;
        } else {
            D_00747A24 = D_00747A24 | 8;
        }
        if (moveMotion(s1) != 0) {
            D_00747A24 = D_00747A24 | 8;
            s1->step = s1->step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    case 2:
        break;
    }
}
