/* sn-2.95.3-136 */
#include "godhand/cModel.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"

/* An object that spins its first child body: speeds up to a top speed, then
 * slows to a stop. */
typedef struct cOmSpinner {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x3C];
    float speedMax;                     /* 0x61C */
    float speed;                        /* 0x620 turn per frame */
    float accel;                        /* 0x624 */
    float decel;                        /* 0x628 */
} cOmSpinner;

#define SPIN_START  0
#define SPIN_IDLE   1
#define SPIN_UP     2
#define SPIN_DOWN   3

/* Step the spin speed for the current step and turn the first child by it. */
__attribute__((section(".text.func_001B48E0")))
void func_001B48E0(cOmSpinner *self)
{
    int frame[3];
    cParts *child;

    switch (self->base.step) {
    case SPIN_START:
        self->base.step = SPIN_IDLE;
        self->speed = 0.0f;
        break;
    case SPIN_IDLE:
        break;
    case SPIN_UP:
        self->speed += self->accel * cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
        if (self->speedMax <= self->speed) {
            self->speed = self->speedMax;
        }
        break;
    case SPIN_DOWN:
        self->speed -= self->decel * cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
        if (self->speed <= 0.0f) {
            self->speed = 0.0f;
        }
        break;
    }
    child = (cParts *)cOmBase_childAt(&self->base, frame, 0);
    child->rot.y += self->speed * cEmManage_GetSpeedRate(&D_005864F0) * D_007474A0.timeScale;
}
