/* sn-2.95.3-136 */
#include "godhand/cOmWeapon.h"
#include "godhand/cEmManage.h"
#include "godhand/vu0.h"

#define DROP_GRAVITY     0.065f
#define DROP_LIFE        300.0f
#define DROP_HIT_MASK    7
#define DROP_HIT_KIND    0x534
#define EFF_WEAPON_BREAK 0x69

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void cOmWeapon_SetBreak(cOmWeapon *self);

/* Drops the weapon straight down; it breaks when it hits the ground or its time runs out. */
__attribute__((section(".text.func_001CD800")))
void func_001CD800(cOmWeapon *self)
{
    cVec to;
    cVec from;
    cVec hit;
    float rate;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    VU0_SQC2_VF0_MEM(&to, 0);
    VU0_LQC2(4, self->base.pos, 0);
    VU0_SQC2_MEM(4, &from, 0);
    VU0_SQC2_VF0_MEM(&hit, 0);
    switch (self->base.step) {
    case 0:
        self->fallSpeed = DROP_GRAVITY;
        self->life = DROP_LIFE;
        self->fallVel = -self->fallSpeed;
        self->base.step++;
    case 1:
        break;
    default:
        return;
    }
    self->base.pos->y += self->fallVel * rate;
    self->fallVel -= self->fallSpeed * rate;
    cVec_copy3(&to, self->base.pos);
    if (ChkLine(&from, &to, &hit, 0, DROP_HIT_MASK, DROP_HIT_KIND, 0, 0, 0, 0, 0, 0, 1)) {
        cVec_copy3(self->base.pos, &hit);
        SetEffectPos(EFF_WEAPON_BREAK, 0xC, 0, self->base.pos, -1, 1.0f);
        cOmWeapon_SetBreak(self);
    }
    self->life -= rate;
    if (self->life <= 0.0f) {
        cOmWeapon_SetBreak(self);
        SetEffectPos(EFF_WEAPON_BREAK, 0xC, 0, self->base.pos, -1, 1.0f);
    }
}
