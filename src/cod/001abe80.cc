/* sn-2.95.3-136 matched TU. */
extern "C" {

#include "godhand/cOm5a.h"
#include "godhand/cDamageManage.h"
#include "godhand/vu0.h"
#include "godhand/cScrSpriteDraw.h"
#include "godhand/cGrid.h"

/* The six face records func_0012EAD8 copies into the box (u.box.face[0..5]). */
typedef struct cOm5aBoxFaces {
    cVec v[6];
} cOm5aBoxFaces;

/* As its definition takes it (src/cod/001b6fb8.c). cOmHitVolumeSetup.h
 * declares it for cOmHitVolume. */
extern int func_001B6FB8(void *self);
/* Read here as bytes ([1] picks the hit-point factor); other files declare
 * it as unsigned short. */
extern unsigned char D_00747A50[];
extern char D_005CAE50[];
extern cOm5aBoxFaces D_00427DC0;

/* Sets all four components of v. */
static __inline__ void om5a_vec(cVec *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Sets the object up: a sphere take on the first child, a box give, 80 hit
 * points times a factor picked by D_00747A50[1], the collision box, and the
 * open type from unk5E0's type. */
__attribute__((section(".text.func_001ABE80")))
int func_001ABE80(cOm5a *self)
{
    cVec size;
    cVec center;
    float *mtx;
    float scale;
    int n;

    func_001B6FB8(&self->base);
    om5a_vec(&size, 5.0f, 3.0f, 0.6f, 1.0f);
    om5a_vec(&center, 0.0f, 0.5f, 0.0f, 1.0f);
    self->take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 1);
    if (self->take != 0) {
        int frame[3];
        cOmBase *child = cOmBase_childAt(&self->base, frame, 0);

        cDamageUnit_AddDamageCollSphere((cDamageUnit *)self->take,
                                        (const struct cMatrix *)child->mtx, &center, 0.7f);
        self->take->flags |= 1;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)self->take, 0);
    }
    switch (D_00747A50[1]) {
    default:
    case 1: scale = 1.0f; break;
    case 2: scale = 1.4f; break;
    case 3: scale = 1.8000001f; break;
    case 4: scale = 2.3f; break;
    case 5: scale = 2.7f; break;
    case 6: scale = 3.1f; break;
    case 7: scale = 3.6f; break;
    case 8: scale = 4.0f; break;
    }
    n = func_0031ED08(scale * 80.0f);
    self->base.hpMax = n;
    if (n < self->base.hpMax) {
        self->base.hp = n;
    } else {
        self->base.hp = self->base.hpMax;
    }
    {
        cVec bsize;
        cVec bofs;
        cVec brot;

        om5a_vec(&bsize, 2.3f, 0.4f, 1.4f, 1.0f);
        om5a_vec(&bofs, 0.0f, 0.4f, 0.7f, 1.0f);
        self->give = cDamageManage_CreateDamageGive(&D_00574380, 2, (cGameObj *)self);
        if (self->give != 0) {
            int frame[3];
            cOmBase *child = cOmBase_childAt(&self->base, frame, 0);

            om5a_vec(&brot, 0.0f, 0.0f, 0.0f, 1.0f);
            func_001FD9D8((cDamageUnit *)self->give, (const struct cMatrix *)child->mtx,
                          &bofs, &brot, &bsize);
            self->give->kind = 0x37;
            self->give->power = 20;
            cDamageUnit_SetDamageCollActive((cDamageUnit *)self->give, 0);
        }
    }
    {
        cVec half;
        cVec zero;
        cOm5aBoxFaces faces;

        om5a_vec(&center, size.x, size.y, size.z, 1.0f);
        VU0_VADDX_XYZ_MEM(&center, 0, 0.1f);
        om5a_vec(&half, 0.0f, size.y * 0.5f, 0.0f, 1.0f);
        om5a_vec(&zero, 0.0f, 0.0f, 0.0f, 1.0f);
        faces = D_00427DC0;
        mtx = self->base.mtx;
        func_0012EAD8(D_005CAE50, self, mtx, &half, &zero, &center,
                      &faces.v[0], &faces.v[1], &faces.v[2], &faces.v[3], &faces.v[4], &faces.v[5]);
    }
    self->base.flags2 |= 0x188;
    func_001ADA70(self, 3.1f);
    cOm5a_setFaceOpen(self);
    if (self->unk5E0 != 0) {
        switch (self->unk5E0->type) {
        case 0:
            cOm5a_setOpenType(self, 0);
            break;
        default:
            cOm5a_setOpenType(self, 0);
            break;
        case 1:
            cOm5a_setOpenType(self, 1);
            break;
        }
    } else {
        cOm5a_setOpenType(self, 0);
    }
    self->active = 0;
    self->shakeTimer = 0;
    self->base.scrFlags |= 0x10;
    return 1;
}

}
