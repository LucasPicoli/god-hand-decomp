/* sn-2.95.3-136: func_00276228, move the enemy to pos: set the transform and cached positions, recalc the
 * parts, IK and world parts, then update every attached effect and sub-object the same way. */
#include "godhand/cOmWeapon.h"
#include "godhand/cModel.h"
#include "godhand/cEm00.h"
#include "godhand/vecInline.h"

extern void cModel_calcParts(cModel *self);
extern void IK_InverseKinematics(void *ik, void *self);
extern void cModel_calcWorldParts(cModel *self);
extern void func_001CF3A8(cOmWeapon *self);
extern void func_001C2378(char *self);
extern void func_0027D300(char *self);
extern void func_0027E950(char *self);
extern void func_00280DB8(char *self);
extern void func_00283070(char *self);

/* The handles at 0x6EC..0x750 hold object addresses; each one present is updated and recalculated. */
__attribute__((section(".text.func_00276228")))
void func_00276228(cEm00 *self, float *pos)
{
    vec3_copy(&self->pos->x, pos);
    vec3_copy(&self->posA.x, pos);
    self->mtx[12] = pos[0];
    self->mtx[13] = pos[1];
    self->mtx[14] = pos[2];
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    if (self->unk6EC != 0) {
        func_001CF3A8((void *)self->unk6EC);
        cModel_calcParts((void *)self->unk6EC);
    }
    if (self->fx0 != 0) {
        func_001CF3A8((void *)self->fx0);
        cModel_calcParts((void *)self->fx0);
    }
    if (self->fx2 != 0) {
        func_001CF3A8((void *)self->fx2);
        cModel_calcParts((void *)self->fx2);
    }
    if (self->fx3 != 0) {
        func_001CF3A8((void *)self->fx3);
        cModel_calcParts((void *)self->fx3);
    }
    if (self->fx4 != 0) {
        func_001CF3A8((void *)self->fx4);
        cModel_calcParts((void *)self->fx4);
    }
    if (self->fx5 != 0) {
        func_001CF3A8((void *)self->fx5);
        cModel_calcParts((void *)self->fx5);
    }
    if (self->fx6 != 0) {
        func_001CF3A8((void *)self->fx6);
        cModel_calcParts((void *)self->fx6);
    }
    if (self->unk734 != 0) {
        func_001CF3A8((void *)self->unk734);
        cModel_calcParts((void *)self->unk734);
    }
    if (self->fx1 != 0) {
        func_001CF3A8((void *)self->fx1);
        cModel_calcParts((void *)self->fx1);
    }
    if (self->unk70C != 0) {
        func_001C2378((void *)self->unk70C);
        cModel_calcParts((void *)self->unk70C);
    }
    if (self->subA != 0) {
        func_0027D300((void *)self->subA);
        cModel_calcParts((void *)self->subA);
    }
    if (self->unk744 != 0) {
        func_0027E950((void *)self->unk744);
        cModel_calcParts((void *)self->unk744);
    }
    if (self->sub0 != 0) {
        func_00280DB8((void *)self->sub0);
        cModel_calcParts((void *)self->sub0);
    }
    if (self->sub1 != 0) {
        func_00283070((void *)self->sub1);
        cModel_calcParts((void *)self->sub1);
    }
    if (self->sub2 != 0) {
        func_00283070((void *)self->sub2);
        cModel_calcParts((void *)self->sub2);
    }
}
