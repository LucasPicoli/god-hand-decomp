/* sn-2.95.3-136: gimmick per-frame update: park both damage units, sync the speed rate and the
 * timer, run the current phase handler, update the model, keep the follow positions in step and
 * die when the object falls out of the stage. */
#include "godhand/cEmManage.h"
extern int ClearField5B4IfFlagUnset_1B76B0(void *a0);
extern void cModel_ScrollTexture(void *a0, float f);
extern void func_001CF3A8(char *self);
extern void cModel_calcParts(void *a0);
extern void cOmBase_dieCommon(void *a0);

#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"
#include "godhand/cDamageGive.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/vecInline.h"

extern EmPhaseTable D_003BDE88;

/* A gimmick with two damage-give volumes that are parked every frame before its phase runs. */
typedef struct cOmFallGimmick {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    int unk600;                         /* 0x600 0 lets the object die when it falls below y -1000 */
    char unk604[0x650 - 0x604];
    cDamageGive *give0;                 /* 0x650 */
    char unk654[0x4];
    cDamageGive *give1;                 /* 0x658 */
    char unk65C[0x664 - 0x65C];
    char unk664;                        /* 0x664 cleared every frame */
    char unk665;                        /* 0x665 cleared every frame */
    char unk666[0x2];
    int unk668;                         /* 0x668 set to 0x3E7 every frame on actor 0x390 */
    float timer;                        /* 0x66C counts down by the speed rate */
} cOmFallGimmick;

__attribute__((section(".text.func_001C9860")))
void func_001C9860(cOmFallGimmick *self)
{
    float rate;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0)
        return;
    if (self->give0 != 0) {
        self->give0->unk46 = 0;
        self->give0->activeTime = 0;
        cDamageUnit_SetDamageCollActive(self->give0, 0);
    }
    if (self->give1 != 0) {
        self->give1->unk46 = 0;
        self->give1->activeTime = 0;
        cDamageUnit_SetDamageCollActive(self->give1, 0);
    }
    rate = cEmManage_GetSpeedRate(&D_005864F0);
    self->base.speedRate = rate;
    if (self->timer > 0.0f)
        self->timer -= rate;
    self->unk664 = self->unk665 = 0;
    EM_PHASE_RUN(&D_003BDE88, self, self->base.mode);

    cModel_ScrollTexture(self, self->base.speedRate);
    func_001CF3A8((char *)self);
    cModel_calcParts(self);

    vec3_copy(&self->base.posA.x, &self->base.pos->x);
    vec3_copy(&self->base.posB.x, &self->base.posPrev.x);
    if (self->unk600 == 0 && self->base.pos->y < -1000.0f)
        cOmBase_dieCommon(self);
    if (self->base.actorId == 0x390)
        self->unk668 = 0x3E7;
}
