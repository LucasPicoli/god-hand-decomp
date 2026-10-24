/* sn-2.95.3-136: func_0027F1B0, enemy per-frame update: the same shape as 00281968.c, with unk1560's low
 * two bits cleared before the phase dispatch and the wobble angle kept at 0x15B0. */
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

#define SYS_FLAG_FREEZE   0x40000000    /* D_00747A78: enemies skip their update */
#define DEG_TO_RAD        0.017453292f

/* This enemy keeps its wobble angle at 0x15B0, where cEm00.h has cEma2's gotoFlags. */
#define EM_WOBBLE(self)   (*(float *)((char *)(self) + 0x15B0))

extern unsigned int D_00747A78;         /* system flags */
extern char D_00462FC0[];
extern void SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_0027F3A0(char *self);
extern void cObjBase_SetSeqEffect(cObjBase *a0);
extern void func_00280DB8(char *self);
extern void cModel_calcParts(cModel *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern float capVu0Sin(float f12);
extern float Adjust_theta(float angle);
extern void cModel_ScrollTexture(cModel *a0, float f);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFE98;

__attribute__((section(".text.func_0027F1B0")))
void func_0027F1B0(cEm00 *self)
{
    float rate;
    float scroll;

    if (D_00747A78 & SYS_FLAG_FREEZE)
        return;
    rate = cEmManage_GetSpeedRate(&D_005864F0);
    self->speedRate = rate;
    SetMotionStep(self, rate);
    self->playerDist = capVu0MagnitudeSqXZ(Getplayer()->pos, self->pos);
    func_0027F3A0((char *)self);
    self->unk1560 &= 0xFFFFFFFC;
    EM_PHASE_RUN(&D_003BFE98, self, self->mode);

    cObjBase_SetSeqEffect(self);
    func_00280DB8((char *)self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);

    scroll = capVu0Sin(EM_WOBBLE(self)) * 0.5f;
    scroll += 1.0f;
    scroll += scroll;
    scroll *= self->speedRate;
    EM_WOBBLE(self) += self->speedRate * 10.0f * DEG_TO_RAD;
    EM_WOBBLE(self) = Adjust_theta(EM_WOBBLE(self));
    cModel_ScrollTexture(self, scroll);
    vec3_copy(&self->posA.x, &self->pos->x);
}
