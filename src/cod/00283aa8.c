/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/cEmLinked.h"

#define EMLINK_HOLDER     2             /* child of the link that holds this enemy */
#define EMLINK_LIFT       0.01f

/* Point the push along the heading of the link's holder (or of the link), then run the step. */
__attribute__((section(".text.func_00283AA8")))
void func_00283AA8(cEmLinked *self)
{
    struct {
        float m[4][4];
        cVec v;
        int childNum;
    } f;
    cGameObj *link;
    cOmBase *holder;
    float angle;

    self->mode = EMLINK_MODE_FREE;
    link = self->link;
    if (link != 0 && link->hp > 0) {
        VU0_SQC2_VF0(&f, 0x40);
        holder = cOmBase_childAt((cOmBase *)link, &f.childNum, EMLINK_HOLDER);
        if (holder != 0) {
            f.v.x = 0.0f;
            f.v.y = 0.0f;
            f.v.z = 1.0f;
            cVec_applyMatrix(&f.v, holder->mtx);
            VU0_VSUB_XYZ_IP(&f.v, 0, holder->pos);
            angle = capVu0Atan2(f.v.x, f.v.z);
        } else {
            angle = link->rot.y;
        }
        MtxInitRotY(f.m[0], angle);
        f.v.x = 0.0f;
        f.v.y = EMLINK_LIFT;
        f.v.z = -EMLINK_LIFT;
        cVec_applyMatrix(&f.v, f.m);
        cVec_copy3(&self->push, &f.v);
        self->mode = EMLINK_MODE_HELD;
    }
    func_00104010(self, self->work, &self->base.unk5B0);
}
