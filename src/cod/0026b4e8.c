/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define THROW_TURN_LIMIT  1.0471976f
#define THROW_SPEED       0.3f
#define HELD_LIFT         1.5f

/* An enemy that carries a weapon. */
typedef struct cEmCarrier {
    cGameObj base;
    char unk5AC[0x700 - 0x5AC];
    cOmWeapon *held;            /* 0x700 the weapon it carries, or 0 */
} cEmCarrier;

extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void MtxInitRotY(void *a0, float angle);
extern void func_001CFB28(cOmWeapon *self, cVec *pos, int arg);

/* Throws the carried weapon toward the player, turned at most 60 degrees from the enemy's heading. */
__attribute__((section(".text.func_0026B4E8")))
void func_0026B4E8(cEmCarrier *self)
{
    float mtx[16] __attribute__((aligned(16)));
    cVec vel;
    cOmWeapon *held = self->held;

    if (held == 0) {
        return;
    }
    VU0_SQC2_VF0_MEM(&vel, 0);
    {
        cVec *from = self->base.pos;
        cVec *to = Getplayer()->pos;
        float turn = Turn_dest(from, to, self->base.rot[1], THROW_TURN_LIMIT);

        MtxInitRotY(mtx, Adjust_theta(turn + self->base.rot[1]));
    }
    vel.x = 0;
    vel.y = 0;
    vel.z = THROW_SPEED;
    cVec_applyMatrix(&vel, mtx);
    cVec_copy3(held->base.pos, self->base.pos);
    held->base.pos->y += HELD_LIFT;
    cVec_copy3(&held->base.posA, self->base.pos);
    func_001CFB28(held, &vel, (int)self);
}
