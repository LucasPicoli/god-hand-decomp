/* sn-2.95.3-136 matched TU. */
#define CGAMEOBJ_NO_TYPEDEF
#define COBJBASE_NO_TYPEDEF
#include "godhand/cGameObj.h"
#include "godhand/cVec.h"
#include "godhand/vu0.h"

extern char D_0044ADF0[];               /* "cGameObj" */

/* Construct the object: the cObjBase base, this class's method table and
 * class name, the stored position (0, 0, 0, 1), the velocity and the vectors
 * at 0x580 and 0x590 set to (0, 0, 0, 1) from $vf0, the speed rate 1.0. */
__attribute__((section(".text.cGameObj")))
struct cGameObj *cGameObj(struct cGameObj *self)
{
    cObjBase((struct cObjBase *)self);
    self->vtable = D_0044AE28;
    CVEC_INIT_XYZ(self->stored, 0.0f, 0.0f, 0.0f);
    VU0_SQC2_VF0_AT(self->vel);
    VU0_SQC2_VF0_AT(self->unk580);
    VU0_SQC2_VF0_AT(self->unk590);
    self->kindName = D_0044ADF0;
    self->speedRate = 1.0f;
    self->unk4D0 = 0xFFFF;
    self->unk531 = -1;
    self->unk510 = 0;
    self->name = 0;
    self->modelHandle = 0;
    self->scrFlags = 0;
    return self;
}
