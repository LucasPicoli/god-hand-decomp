/* sn-2.95.3-136 matched TU. */

#include "godhand/cFxBurst.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"


extern void func_002B62F8(void *a0, char *a1);
extern void func_002B60D0(void *dst, void *src);
extern void MtxCopy(void *dst, void *src);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern float *CallThenReturnPlusB0_002B6420_2B61B0(void *node);
extern void func_002B6230(char *a0, float *a1);
extern void func_002B5D58(void *arg, void *parent);

/* When the countdown has run out, moves the node's position and velocity
 * through the parent's world matrix, then detaches it from the parent. */
__attribute__((section(".text.func_002FCB88")))
void func_002FCB88(cFxBurst *self)
{
    cVec p;
    cVec v;
    float m[4][4];
    cVec t;
    /* Address locals bound at the first use: retail keeps the three stack
     * addresses in saved registers, and a binding at the top changes which. */
    cVec *pv;
    float (*pm)[4];
    cVec *pt;

    if (func_002B5E50(self) == 0)
        return;
    if (self->count < 0)
        return;
    if (self->count - self->limit > 0)
        return;
    self->count = 0;
    func_002B62F8(&p, (char *)self);
    if (!(self->flags & FXBURST_F_SKIP)) {
        if (self->flags & FXBURST_F_WORLD)
            return;
        pv = &v;
        pm = m;
        v.x = self->pos[0];
        v.y = self->pos[1];
        v.z = self->pos[2];
        self->flags |= FXBURST_F_WORLD;
        pv->w = 1.0f;
        MtxCopy(pm, CallThenReturnPlusB0_002B6420_2B61B0((void *)func_002B5E50(self)));
        VU0_SQC2_VF0_MEM(&t, 0);
        pt = &t;
        CopyVec3ToField30_147C40((float *)pm, (float *)pt);
        sceVu0ApplyMatrix(pv, pm, pv);
        self->pos[0] = v.x;
        self->pos[1] = v.y;
        self->pos[2] = v.z;
        if (self->velFlag == FXBURST_VEL_ON) {
            t.x = self->vel[0];
            t.y = self->vel[1];
            t.z = self->vel[2];
            pt->w = 1.0f;
            sceVu0ApplyMatrix(pt, pm, pt);
            self->vel[0] = t.x;
            self->vel[1] = t.y;
            self->vel[2] = t.z;
        }
    }
    if (func_002B5E50(self) != 0) {
        if (!(self->flags & FXBURST_F_FROZEN)) {
            func_002B60D0(&v, self);
            if (&p != &v) {
                p.x = v.x;
                p.y = v.y;
                p.z = v.z;
            }
        }
    }
    func_002B5D58(self, 0);
    func_002B6230((char *)self, (float *)&p);
}
