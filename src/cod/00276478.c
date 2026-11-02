/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/cSaveLoad.h"
#include "godhand/vu0.h"
#include "godhand/gameWork.h"
#include "godhand/capVu0.h"

#define EM_NO_SCREEN_GHOST   0x26A
#define SYSFLAG_SCENE_HIDE   0x20000000
#define EMFLAG_SECOND_PART   0x1000000
#define OBJFLAG_SEE_THROUGH  0x10u
#define GHOST_RATE           0.3f
#define GHOST_HEAD_NEAR_SQ   64.0f
#define GHOST_PART_NEAR_SQ   36.0f

/* Whether the enemy is the screen ghost. */
static __inline__ int Em_isScreenGhost(cEm00 *self)
{
    return self->emNo == EM_NO_SCREEN_GHOST;
}

/* Makes the enemy see-through and slow while the camera eye is close to its head
 * child (or, when flagged, its ninth child); otherwise restores it. */
__attribute__((section(".text.func_00276478")))
void func_00276478(cEm00 *self)
{
    cVec eye;
    int frame[3];
    cOmBase *child;
    int flags;
    unsigned long word;
    unsigned long bit;
    int near;

    if (!Em_isScreenGhost(self)) {
        return;
    }
    flags = D_007474A0.flags5E4;
    if (!(flags & SYSFLAG_SCENE_HIDE)) {
        if (!(flags & SAVELOAD_FLAG_BUSY)) {
            word = flags;
            bit = (word >> 6) & 1;
            if (bit == 0) {
                if (D_005CAFF0 == 0) {
                    return;
                }
                VU0_SQC2_VF0_MEM(&eye, 0);
                cVec_copy3(&eye, &D_005CAFF0->eye);
                near = 0;
                child = cOmBase_childAt((cOmBase *)self, frame, 16);
                if (child != 0 && capVu0MagnitudeSqXZ(child->pos, &eye) < GHOST_HEAD_NEAR_SQ) {
                    near = 1;
                }
                if (self->emFlags & EMFLAG_SECOND_PART) {
                    child = cOmBase_childAt((cOmBase *)self, frame, 9);
                    if (child != 0 && capVu0MagnitudeSqXZ(child->pos, &eye) < GHOST_PART_NEAR_SQ) {
                        near = 1;
                    }
                }
                if (near) {
                    self->animRate = GHOST_RATE;
                    self->objFlags |= OBJFLAG_SEE_THROUGH;
                    return;
                }
            }
        }
    }
    self->animRate = 1.0f;
    self->objFlags &= ~OBJFLAG_SEE_THROUGH;
}
