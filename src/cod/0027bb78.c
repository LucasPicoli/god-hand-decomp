/* sn-2.95.3-136: func_0027BB78, per-frame update of an enemy that follows a parent enemy: take the parent's
 * speed, run the phase handler, turn child part 0 toward the player while unk1560 bit 1 is set, then
 * update the model and IK. */
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

#define SYS_FLAG_FREEZE   0x40000000    /* D_00747A78: enemies skip their update */
#define TURN_SPEED        0.049087387f  /* pi/64 a frame, scaled by speedRate */

extern unsigned int D_00747A78;         /* system flags */
extern char D_00462FC0[];
extern void SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_0027BDD8(char *self);
extern void cObjBase_SetSeqEffect(cObjBase *a0);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float angle);
extern void func_0027D300(char *self);
extern void func_0027D400(char *self);
extern void cModel_calcParts(cModel *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFE00;

static inline cOmBase *getPart0(cEm00 *self)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)self, frame, 0);
}

__attribute__((section(".text.func_0027BB78")))
void func_0027BB78(cEm00 *self)
{
    cEm00 *parent = self->target;
    cOmBase *part;
    float t;
    float ang;

    if (D_00747A78 & SYS_FLAG_FREEZE)
        return;
    if (parent != 0)
        self->speedRate = parent->speedRate;
    else
        self->speedRate = cEmManage_GetSpeedRate(&D_005864F0);
    SetMotionStep(self, self->speedRate);
    self->playerDist = capVu0MagnitudeSqXZ(Getplayer()->pos, self->pos);
    func_0027BDD8((char *)self);
    t = self->stepVar.time;
    self->unk1560 &= 0xFFFFFFFC;
    if (t > 0.0f)
        self->stepVar.time = t - self->speedRate;
    EM_PHASE_RUN(&D_003BFE00, self, self->mode);

    cObjBase_SetSeqEffect(self);
    part = getPart0(self);
    if (part != 0 && parent != 0) {
        if (self->unk1560 & 2u) {
            void *pos = parent->pos;

            ang = Turn_dest(pos, parent->rot.y, 3.1415927f, Getplayer()->pos);
        } else {
            ang = 0.0f;
        }
        self->partYaw += Turn_dest_dir(self->partYaw, ang, self->speedRate * TURN_SPEED);
        self->partYaw = Adjust_theta(self->partYaw);
        part->rot.y = self->partYaw;    /* 0x104: the part's heading */
    }
    func_0027D300((char *)self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    func_0027D400((char *)self);
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    vec3_copy(&self->posA.x, &self->pos->x);
}
