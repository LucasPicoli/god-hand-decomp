/* sn-2.95.3-136 matched TU. */
#include "godhand/cOl40.h"
#include "godhand/cVec.h"
#include "godhand/vecInline.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"

/* Shake part 5: offset its height and its x/z rotation by the shake
 * amplitudes times the sine of the phase, step the phase by pi/4 and let
 * the amplitudes decay by 0.9. */
__attribute__((section(".text.func_00186398")))
void func_00186398(cOl40 *self)
{
    int frame[3];
    cVec pos;
    cVec rot;

    if (cOmBase_childAt(&self->base, frame, OL40_SHAKE_PART) == 0) {
        return;
    }
    {
        cOmBase *part = cOmBase_childAt(&self->base, frame, OL40_SHAKE_PART);

        vec4_set_point(&pos.x, part->mtxLocal[12], part->mtxLocal[13], part->mtxLocal[14]);
    }
    {
        cOmBase *part = cOmBase_childAt(&self->base, frame, OL40_SHAKE_PART);

        CVEC_COPY(rot, &part->rot);
    }
    pos.y = self->shakePos.y + self->shakeY * capVu0Sin(self->shakePhase);
    rot.x = self->shakeRot.x + self->shakeRotX * capVu0Sin(self->shakePhase);
    rot.z = self->shakeRot.z + self->shakeRotZ * capVu0Sin(self->shakePhase);
    self->shakePhase = Adjust_theta(self->shakePhase + 0.7853982f);
    self->shakeY *= 0.9f;
    self->shakeRotX *= 0.9f;
    self->shakeRotZ *= 0.9f;
    {
        cOmBase *part = cOmBase_childAt(&self->base, frame, OL40_SHAKE_PART);

        CVEC_PUT(part->anchor, pos);
    }
    {
        cOmBase *part = cOmBase_childAt(&self->base, frame, OL40_SHAKE_PART);

        CVEC_ASSIGN_ARG(part->rot, rot);
    }
}
