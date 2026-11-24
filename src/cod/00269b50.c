/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"

static inline cOmBase *getPart(cEm00 *self, int i)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)self, frame, i);
}

/* The neck move: turns neckYaw toward the player (when emFlags 0x400 is set),
 * holds it at 0 while CEM00_FLAG2_NECK_OFF is set, then copies it into the
 * parts' extraYaw with CPARTS_EXTRA_YAW:
 * half of it to parts 3 and 4 (5 and 6 for enemy 0x223), all of it to part 16
 * for enemy 0x26A, and zero to the parts that must stay straight. */
__attribute__((section(".text.func_00269B50")))
void func_00269B50(cEm00 *self)
{
    cVec target;
    float rate;
    float d;
    cOmBase *child;

    VU0_SQC2_VF0_MEM(&target, 0);
    switch (self->emNo) {
    case 0x264:
    case 0x265:
        return;
    }
    CVEC_ASSIGN(target, self->pos);
    rate = 0.19634955f;
    if (self->emNo == 0x26A) {
        child = getPart(self, 16);
        if (child != 0) {
            CVEC_ASSIGN(target, child->pos);
        }
        rate = 0.012271847f;
    }
    if (self->emFlags & 0x400) {
        d = Turn_dest(&target.x, self->rot.y, &Getplayer()->pos->x, 1.0471976f);
    } else {
        d = 0.0f;
    }
    self->neckYaw += Turn_dest_dir(self->neckYaw, d, rate * self->speedRate);
    self->neckYaw = Adjust_theta(self->neckYaw);
    if (self->emFlags2 & CEM00_FLAG2_NECK_OFF) {
        self->neckYaw = 0.0f;
    }

    switch (self->emNo) {
    default:
        child = getPart(self, 3);
        if (child != 0) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->neckYaw * 0.5f;
        }
        child = getPart(self, 4);
        if (child != 0) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->neckYaw * 0.5f;
        }
        child = getPart(self, 26);
        if (child != 0) {
            child->extraYaw = 0.0f;
            child->partFlags |= CPARTS_EXTRA_YAW;
        }
        if (self->emNo == 0x256 || self->emNo == 0x27E) {
            child = getPart(self, 29);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
            child = getPart(self, 30);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
            child = getPart(self, 31);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
            child = getPart(self, 32);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
            child = getPart(self, 33);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
            child = getPart(self, 34);
            if (child != 0) {
                child->extraYaw = 0.0f;
                child->partFlags |= CPARTS_EXTRA_YAW;
            }
        }
        break;
    case 0x223:
        child = getPart(self, 5);
        if (child != 0) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->neckYaw * 0.5f;
        }
        child = getPart(self, 6);
        if (child != 0) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->neckYaw * 0.5f;
        }
        break;
    case 0x26A:
        child = getPart(self, 16);
        if (child != 0) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->neckYaw;
        }
        break;
    }
}
