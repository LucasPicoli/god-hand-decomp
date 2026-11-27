/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/cObj.h"

extern int setMotionInfo(cObjBase *self, char *motion, SEQ_DATA_HEADER_1 *seqData, unsigned int blendLen,

float step, float start, int flags);

extern unsigned int func_0031ED08(float f);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern char *func_002DDAB0(void *a0, int a1, float f);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int D_00747A78;
extern void *Getplayer(void);
extern void func_001034E0(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);

/* Phase 4: start the stored motion, play it until it ends and keep moving and
 * turning the model by its null-part speeds. */
__attribute__((section(".text.func_0014ED60")))
void func_0014ED60(cObjBase *self)
{
    float one;

    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->seqData, func_0031ED08(self->blendLeft),
                      self->motionRate, self->motionFrame, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    case 2:
        moveMotion(self);
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}

__attribute__((section(".text.func_00288B78")))
void func_00288B78(void *a0)
{
    cGameObj *s0 = a0;
    int v0;
    float one;

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0:
        func_0028FB08(a0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x130) + v0, *(int *)(v0 + 0x134) + v0, 5, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5F, a0, 0, 0, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            s0->stepArg = 0;
            s0->mode = 2;
            s0->step = 0;
            s0->phase = 2;
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s0, one);
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
}

__attribute__((section(".text.func_00277B18")))
void func_00277B18(void *a0)
{
    cGameObj *s0 = a0;
    char *s1;
    int v0;
    float one;

    s1 = func_002DDAB0(*(void **)((char *)s0 + 0xF0), 0, 15.0f);
    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x14) + v0, *(int *)(v0 + 0x18) + v0, 3, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        if (s1 != 0) {
            cGameObj_SetTgtTurn((cGameObj *)s0, *(cVec **)(s1 + 0xF0),
                                             s0->speedRate * 0.39269909f);
            if (capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), *(void **)((char *)s0 + 0xF0)) < 0.25f) {
                s0->mode = 0;
                s0->phase = 3;
                goto fin;
            }
        } else {
            s0->mode = 0;
            s0->phase = 0;
        fin:
            s0->step = 0;
            s0->stepArg = 0;
        }
        moveMotion(s0);
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_001027D8")))
void func_001027D8(void *a0)
{
    cObj *s0 = a0;
    char *s1;
    char *v0;
    float one;
    float f;

    s1 = (char *)Getplayer();
    switch (s0->step) {
    case 0:
        v0 = s0->pack;
        func_002A8578(s0, *(int *)(v0 + 0xC) + (int)v0, *(int *)(v0 + 0x10) + (int)v0, 10, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        if (!(D_00747A78 & 0x2000000) && *(unsigned char *)(s1 + 0x61F) != 0) {
            f = *(float *)(s1 + 0x608) - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.2f;
            if (0.06544985f < f) {
                f = 0.06544985f;
            }
            if (*(float *)(s1 + 0x604) < 0.0f) {
                f = -f;
            }
            s0->rot.y = s0->rot.y + f;
            s0->rot.y = Adjust_theta(s0->rot.y);
        }
        one = 1.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_00246370")))
void func_00246370(void *a0)
{
    cGameObj *s0 = a0;
    int s1, s2;
    int t0;
    float f, one;

    switch (s0->step) {
    case 0:
        *(char *)((char *)s0 + 0x1864) = 0;
        if (s0->emNo == 0x256) {
            int b = *(int *)((char *)s0 + 0x304);
            s2 = *(int *)(b + 0x2B84) + b;
            s1 = *(int *)(b + 0x2B88) + b;
        } else {
            int b = *(int *)((char *)s0 + 0x304);
            s2 = *(int *)(b + 0x2C38) + b;
            s1 = *(int *)(b + 0x2C3C) + b;
        }
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 10, 0.0f, t0, 0);
        *(float *)((char *)s0 + 0x600) = 30.0f;
        s0->step = s0->step + 1;
    case 1:
        f = *(float *)((char *)s0 + 0x600);
        if (0.0f < f) {
            *(int *)((char *)s0 + 0x16D0) = *(int *)((char *)s0 + 0x16D0) | 0x800000;
            *(float *)((char *)s0 + 0x600) = f - s0->speedRate;
        }
        cGameObj_SetTgtTurn((cGameObj *)s0, *(cVec **)((char *)Getplayer() + 0xF0),
                                         s0->speedRate * 0.19634955f);
        if (moveMotion(s0) != 0 || (s0->seqFlags & 0x10) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_002461F0")))
void func_002461F0(void *a0)
{
    cGameObj *s0 = a0;
    int s1, s2;
    int t0;
    float f, one;

    switch (s0->step) {
    case 0:
        *(char *)((char *)s0 + 0x1864) = 0;
        if (s0->emNo == 0x256) {
            int b = *(int *)((char *)s0 + 0x304);
            s2 = *(int *)(b + 0x2B7C) + b;
            s1 = *(int *)(b + 0x2B80) + b;
            *(float *)((char *)s0 + 0x600) = 45.0f;
        } else {
            int b = *(int *)((char *)s0 + 0x304);
            s2 = *(int *)(b + 0x2C30) + b;
            s1 = *(int *)(b + 0x2C34) + b;
            *(float *)((char *)s0 + 0x600) = 60.0f;
        }
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 10, 0.0f, t0, 0);
        s0->step = s0->step + 1;
    case 1:
        f = *(float *)((char *)s0 + 0x600);
        if (0.0f < f) {
            *(int *)((char *)s0 + 0x16D0) = *(int *)((char *)s0 + 0x16D0) | 0x800000;
            *(float *)((char *)s0 + 0x600) = f - s0->speedRate;
        }
        cGameObj_SetTgtTurn((cGameObj *)s0, *(cVec **)((char *)Getplayer() + 0xF0),
                                         s0->speedRate * 0.19634955f);
        if (moveMotion(s0) != 0 || (s0->seqFlags & 0x10) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
