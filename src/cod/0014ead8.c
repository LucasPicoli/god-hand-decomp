/* sn-2.95.3-136 matched TU. */

#include "godhand/cObjBase.h"

extern unsigned int func_0031ED08(float seconds);
extern int moveMotion(cObjBase *self);
extern void Quaternion_GetEulerXYZ(float *quat, cVec *euler);
extern void func_001506F0(cVec *pos, cVec *v);

extern int setMotionInfo(cObjBase *self, char *motion, char *motionEnd, unsigned int start,
                         float rate, float blend, int flags);


/* Phase 1: start the stored motion, then play it until it ends. */
__attribute__((section(".text.cObjBase_runPhase1")))
void cObjBase_runPhase1(cObjBase *self) {
    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->motionEnd, func_0031ED08(self->motionStart),
                      self->motionRate, self->motionBlend, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        break;
    case 2:
        moveMotion(self);
        break;
    }
}

extern int setMotionInfo(cObjBase *self, char *motion, char *motionEnd, unsigned int start,
                         float rate, float blend, int flags);




/* Phase 5: play the stored motion, and each step turn the model to the
 * quaternion the motion leaves behind. */
__attribute__((section(".text.cObjBase_runPhase5")))
void cObjBase_runPhase5(cObjBase *self) {
    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->motionEnd, func_0031ED08(self->motionStart),
                      self->motionRate, self->motionBlend, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        Quaternion_GetEulerXYZ(self->quat, &self->rot);
        func_001506F0(self->pos, &self->unk310);
        break;
    case 2:
        moveMotion(self);
        Quaternion_GetEulerXYZ(self->quat, &self->rot);
        func_001506F0(self->pos, &self->unk310);
        break;
    }
}
