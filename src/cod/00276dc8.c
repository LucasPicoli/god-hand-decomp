/* sn-2.95.3-136 */
/* func_00276DC8: take the push direction from the link's heading (sn-2.95.3-136) */
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

/* An enemy that can be pushed along by a linked object. */
typedef struct cEmLinked {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x2130 - 0x1870];
    char work[0x5C];                    /* 0x2130 step work */
    int mode;                           /* 0x218C EMLINK_MODE_* */
    cVec push;                          /* 0x2190 */
    char unk21A0[0x10];
    cGameObj *link;                     /* 0x21B0 */
} cEmLinked;

extern int func_002744B8(unsigned char *obj);
extern void MtxInitRotY(void *mtx, float angle);
extern void func_00104010(void *self, void *work, void *model);

/* Take the push direction from the link's heading when it can push, then run the step. */
__attribute__((section(".text.func_00276DC8")))
void func_00276DC8(cEmLinked *self)
{
    cGameObj *link;

    self->mode = EMLINK_MODE_FREE;
    link = self->link;
    if (link != 0 && func_002744B8(link) != 0) {
        struct {
            float mtx[4][4];            /* 0x00 */
            cVec v;                     /* 0x40 */
        } f;

        VU0_SQC2_VF0(&f, 0x40);
        MtxInitRotY(&f.mtx[0][0], link->rot.y);
        f.v.x = 0.0f;
        f.v.y = 0.01f;
        f.v.z = -0.01f;
        cVec_applyMatrix(&f.v, f.mtx);
        cVec_copy3(&self->push, &f.v);
        self->mode = EMLINK_MODE_HELD;
    }
    func_00104010(self, self->work, &self->base.unk5B0);
}
