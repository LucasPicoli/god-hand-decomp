/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"
#include "godhand/vu0.h"

#define ACTOR_PLAYER     0x100      /* actorId of the player */
#define ACTOR_PARTNER    0x101      /* actorId of the object this function moves */
#define PARTNER_F_HOVER  0x400      /* flags: the hover offset below is valid */
#define SEQ_F_HOVER      0x800      /* player seqFlags bit that asks for the hover */

/* The actor with id 0x101 as this function sees it. */
typedef struct cPartner {
    cGameObj base;
    char unk5B0[0x2050 - 0x5B0];
    char work[0x20AC - 0x2050];     /* 0x2050 handed to func_00104010 */
    unsigned int flags;             /* 0x20AC PARTNER_F_* */
    cVec hover;                     /* 0x20B0 offset from the player, bobbing */
    char unk20C0[0x20D0 - 0x20C0];
    cGameObj *target;               /* 0x20D0 the actor it follows */
} cPartner;

#include "godhand/mtx.h"
extern float capVu0Sin(float a);
extern float Adjust_theta(float a);
extern void func_00104010(void *self, void *work, void *model);
extern float D_003BC730;            /* hover offset in the player's frame: x */
extern float D_003BC734;            /*                                     y */
extern float D_003BC738;            /*                                     z */
extern float D_003BC73C;            /* bob amplitude */
extern float D_003BC740;            /* bob phase */
extern float D_003BC744;            /* bob phase step per frame */

/* While following the player with the hover bit set, place the hover offset
 * along the player's heading, scaled by a sine bob, then run the move. */
__attribute__((section(".text.func_00100CE0")))
void func_00100CE0(cPartner *self)
{
    float mtx[16] __attribute__((aligned(16)));
    cVec v;
    CVEC_TEMPS;
    float s;

    if (self->base.actorId == ACTOR_PARTNER) {
        cGameObj *pl;

        self->flags &= ~PARTNER_F_HOVER;
        if (self->target != 0 && self->target->actorId == ACTOR_PLAYER) {
            pl = Getplayer();
            if (pl->seqFlags & SEQ_F_HOVER) {
                CVEC_ZERO(v);
                MtxInitRotY(mtx, pl->rot.y);
                v.x = D_003BC730;
                v.y = D_003BC734;
                v.z = D_003BC738;
                cVec_applyMatrix(&v, mtx);
                do { } while (0);   /* keeps &v out of a callee-saved register */
                cVec_unitOf(&tmp_, &v);
                VU0_LQC2(4, &tmp_, 0);
                VU0_SQC2_MEM(4, &ret_, 0);
                v.x = ret_.x;   /* operator=, its self-check folded away: v is not ret_ */
                v.y = ret_.y;
                v.z = ret_.z;
                s = (capVu0Sin(D_003BC740) + 1.0f) * 0.5f * D_003BC73C;
                D_003BC740 += D_003BC744;
                D_003BC740 = Adjust_theta(D_003BC740);
                CVEC_MUL_SCALAR(v, s);
                cVec_copy3(&self->hover, &v);
                self->flags |= PARTNER_F_HOVER;
            }
        }
    }
    func_00104010(self, self->work, (char *)self + sizeof(cObjBase));
}
