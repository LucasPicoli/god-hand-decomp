/* sn-2.95.3-136 */
#include "godhand/cModel.h"

extern void MtxInitCoord(void *a0, int a1, int a2, int a3, int t0);
extern void Adjust_theta_vec(cVec *v);
extern void cParts_calcLocal(cParts *part);
extern void func_00156D70(cParts *dst, cParts *src, float *mtx, float blend);
extern void func_001501D0(cParts *part, int objFlags);

/* Builds the model's world matrix (unless its owner does), marks whether it blends, then
 * updates each part: wraps its angles, builds its local matrix, blends it and joins the parent. */
__attribute__((section(".text.cModel_calcParts")))
void cModel_calcParts(cModel *self)
{
    cParts *part;
    int i;

    if ((self->objFlags & CMODEL_F_NO_CALC) == 0) {
        MtxInitCoord(self->mtx, (int)self->pos, (int)&self->rot, (int)&self->scale, self->rotOrder);
        cVec_copy3(&self->scaleCalc, &self->scale);
    }
    if (self->blend > 0.0f)
        self->objFlags |= 4;
    else
        self->objFlags &= 0xFFFFFFFB;
    part = self->next;
    for (i = 0; i < self->partNum; i++) {
        unsigned long f;

        Adjust_theta_vec(&part->rot);
        f = part->partFlags;
        if (((f >> 3) & 1) == 0)
            cParts_calcLocal(part);
        if (self->blend > 0.0f) {
            f = part->partFlags;
            if ((f & CPARTS_NO_BLEND) == 0 && (self->objFlags & CMODEL_F_NEAR) == 0)
                func_00156D70(part, part, part->mtxBind, self->blend);
        }
        f = part->partFlags;
        if (((f >> 4) & 1) == 0)
            func_001501D0(part, self->objFlags);
        part = part->next;
    }
}
