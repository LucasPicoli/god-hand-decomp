/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"
#include "godhand/cCamera.h"

/* The second rocking object class: the same swing as cOmRocker (0x18F618) with its fields 0x50 lower. */
typedef struct cOmRockerLow {
    cGameObj base;                      /* 0x000 */
    char unk5AC[0x5C0 - 0x5AC];
    cVec knock;                         /* 0x5C0 direction of the last hit */
    char unk5D0[0x600 - 0x5D0];
    short swingTimer;                   /* 0x600 frames left in this swing */
    short swingCount;                   /* 0x602 swings done */
    char unk604[0xC];
    cVec swingDir;                      /* 0x610 */
    float swingVel;                     /* 0x620 angular speed */
} cOmRockerLow;

typedef struct cOmRockerLowFrame {
    cVec dir;                           /* 0x00 */
    cVec unit;                          /* 0x10 */
} cOmRockerLowFrame;

#define ROCKER_FRAME_OFFSET(field) ((int)&((cOmRockerLowFrame *)0)->field)

extern cSnd D_005FEE00;
extern int cSnd_SeCall_2CBA48(cSnd *self, int slot, int id, void *obj, int a4, int a5, int a6, int a7);
extern float fRand1_1(void);

/* Rocks the object: on the hit, aim along the knock direction; then three damped swings back and forth. */
__attribute__((section(".text.func_001A6310")))
void func_001A6310(cOmRockerLow *self)
{
    cOmRockerLowFrame f;

    switch (self->base.phase) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x96, self, 0, 0, 0, 0);
        cVec_copy3(&self->swingDir, &self->knock);
        cVec_unitOf(&f.unit, &self->swingDir);
        VU0_LQC2(4, &f.unit, 0);
        VU0_SQC2(4, &f, ROCKER_FRAME_OFFSET(dir));
        cVec_copy3(&self->swingDir, &f.dir);
        VU0_VSCALE_XYZ_MEM(&self->swingDir, 0, 0.04f);
        self->swingDir.x += fRand1_1() * 0.01f;
        self->swingDir.z += fRand1_1() * 0.01f;
        self->swingTimer = 2;
        self->swingVel = 0.02617994f;
        self->base.phase = 1;
        self->swingCount = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    case 1:
        self->base.rot.x = Adjust_theta(self->base.rot.x + self->swingVel);
        self->swingVel *= 0.9f;
        if (--self->swingTimer <= 0) {
            if (self->swingCount < 2) {
                self->swingCount++;
                self->swingVel = -self->swingVel;
                self->swingTimer = 2;
                self->base.phase = 1;
                self->base.step = 0;
                self->base.stepArg = 0;
            } else {
                self->base.rot.x = 0.0f;
                self->base.rot.z = 0.0f;
                self->base.mode = 0;
                self->base.phase = 0;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
        }
        break;
    }
}
