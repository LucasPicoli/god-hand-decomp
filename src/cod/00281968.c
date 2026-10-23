/* sn-2.95.3-136: enemy per-frame update: sync motion speed and the player distance, run the
 * current phase handler, update the model and IK, then spin the scrolling texture on a sine wobble
 * and keep the follow position in step with the root. */
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

#define SYS_FLAG_FREEZE   0x40000000    /* D_00747A78: enemies skip their update */
#define DEG_TO_RAD        0.017453292f

extern unsigned int D_00747A78;         /* system flags */
extern char D_00462FC0[];
extern void SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00281B40(char *self);
extern void cObjBase_SetSeqEffect(cObjBase *a0);
extern void func_00283070(char *self);
extern void cModel_calcParts(cModel *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern float capVu0Sin(float f12);
extern float Adjust_theta(float angle);
extern void cModel_ScrollTexture(cModel *a0, float f);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFF40;

__attribute__((section(".text.func_00281968")))
void func_00281968(cEm00 *self)
{
    float rate;
    float scroll;

    if (D_00747A78 & SYS_FLAG_FREEZE)
        return;
    rate = cEmManage_GetSpeedRate(&D_005864F0);
    self->speedRate = rate;
    SetMotionStep(self, rate);
    self->playerDist = capVu0MagnitudeSqXZ(Getplayer()->pos, self->pos);
    func_00281B40((char *)self);
    EM_PHASE_RUN(&D_003BFF40, self, self->mode);

    cObjBase_SetSeqEffect(self);
    func_00283070((char *)self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);

    scroll = capVu0Sin(self->stepVar.angle) * 0.5f;
    scroll += 1.0f;
    scroll += scroll;
    scroll *= self->speedRate;
    self->stepVar.angle += self->speedRate * 10.0f * DEG_TO_RAD;
    self->stepVar.angle = Adjust_theta(self->stepVar.angle);
    cModel_ScrollTexture(self, scroll);
    vec3_copy(&self->posA.x, &self->pos->x);
}
