/* sn-2.95.3-136: func_00275DA8, rebuild collision unit/spheres and the three damage-take spheres for enemy type 0x265. */
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"

#define EM_NO_265  0x265

/* The enemy this rebuilds: its damage-take unit and the sphere ids the unit returned. */
typedef struct cEm265 {
    cGameObj base;                      /* 0x000 */
    char unk5AC[0x698 - 0x5AC];
    void *take;                         /* 0x698 damage-take unit, 0 when none */
    int sphere[5];                      /* 0x69C sphere ids, -1 when unused */
} cEm265;

/* A sphere offset whose first word also takes cOmBase_childAt's child count; it is
 * written back to 0 before each use, the same bits as 0.0f. */
typedef struct SphOfs {
    int frame;                          /* 0x0 x, and the childAt frame */
    float y;
    float z;
    float w;
} SphOfs;

extern int ClearAndResetFields_1FE278(void *mgr, void *unit);
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern int D_00462FC0;
extern char D_00574380[];

__attribute__((section(".text.func_00275DA8")))
void func_00275DA8(cEm265 *self)
{
    SphOfs q;
    unsigned int i;
    cOmBase *child;

    if ((self->base.emNo ^ EM_NO_265) != 0)
        return;
    if (ClearAndResetFields_1FE278(D_00574380, self->take)) {
        self->take = 0;
        for (i = 0; i < 5; i++)
            self->sphere[i] = -1;
    }
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, self);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, self, 0, 0.2f);
    q.frame = 0;
    q.y = 0.5f;
    q.z = 0.0f;
    q.w = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->base.mtx, &q, 1.8f);
    q.frame = 0;
    q.y = 0.5f;
    q.z = -0.8f;
    q.w = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->base.mtx, &q, 1.0f);
    q.frame = 0;
    q.y = 0.5f;
    q.z = -1.4f;
    q.w = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->base.mtx, &q, 1.0f);
    self->take = cDamageManage_CreateDamageTake(D_00574380, self, 1);

    child = cOmBase_childAt((cOmBase *)self, &q.frame, 2);
    q.frame = 0;
    q.y = -0.3f;
    q.z = 0.0f;
    q.w = 1.0f;
    self->sphere[0] = cDamageUnit_AddDamageCollSphere(self->take, child->mtx, (float *)&q,
                                                      self->base.scale[2] * 0.7f);

    child = cOmBase_childAt((cOmBase *)self, &q.frame, 0x13);
    q.frame = 0;
    q.y = -0.3f;
    q.z = 0.4f;
    q.w = 1.0f;
    self->sphere[1] = cDamageUnit_AddDamageCollSphere(self->take, child->mtx, (float *)&q,
                                                      self->base.scale[2] * 0.8f);

    child = cOmBase_childAt((cOmBase *)self, &q.frame, 0x20);
    q.frame = 0;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 1.0f;
    self->sphere[2] = cDamageUnit_AddDamageCollSphere(self->take, child->mtx, (float *)&q,
                                                      self->base.scale[2] * 0.7f);
    self->sphere[3] = -1;
    self->sphere[4] = -1;
}
