/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"

static inline cOmBase *getPart(cEm00 *self, int i)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)self, frame, i);
}

/* Copies unk16FC to child parts 1 and 2 (their extraYaw, with CPARTS_EXTRA_YAW
 * set while it is nonzero), then scales it by 0.6 (by -0.6 for enemies 0x223,
 * 0x275 and 0x276) and clears it once it is within one degree of 0. */
__attribute__((section(".text.func_0026A3D8")))
void func_0026A3D8(cEm00 *self)
{
    cOmBase *child;
    float d;

    child = getPart(self, 1);
    if (child != 0) {
        if (self->unk16FC != 0.0f) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->unk16FC;
        } else {
            child->extraYaw = 0.0f;
            child->partFlags &= ~CPARTS_EXTRA_YAW;
        }
    }
    child = getPart(self, 2);
    if (child != 0) {
        if (self->unk16FC != 0.0f) {
            child->partFlags |= CPARTS_EXTRA_YAW;
            child->extraYaw = self->unk16FC;
        } else {
            child->extraYaw = 0.0f;
            child->partFlags &= ~CPARTS_EXTRA_YAW;
        }
    }
    switch (self->emNo) {
    default:
        self->unk16FC *= 0.6f;
        break;
    case 0x223:
    case 0x275:
    case 0x276:
        self->unk16FC *= -0.6f;
        break;
    }
    d = self->unk16FC;
    if (d < 0.0f) {
        d = -d;
    }
    if (d <= 0.017453292f) {
        self->unk16FC = 0.0f;
    }
}
