/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmHitVolume.h"
#include "godhand/cDamageManage.h"

extern void func_00383708(void *self);
extern void func_003837E8(void *self);
extern void func_00383848(void *self);
extern void func_001B6FB8(void *self);

/* Phases of the object: 0, 1 and 2 each run their own update. */
#define OBJ_PHASE_A 0
#define OBJ_PHASE_B 1
#define OBJ_PHASE_C 2

typedef struct PhaseObj {
    char unk00[2];
    unsigned char phase;                /* 0x02 */
} PhaseObj;

/* Runs the update for the object's current phase. */
__attribute__((section(".text.PhaseObj_updatePhase")))
void PhaseObj_updatePhase(PhaseObj *self)
{
    switch (self->phase) {
    case OBJ_PHASE_A:
        func_00383708(self);
        break;
    case OBJ_PHASE_B:
        func_003837E8(self);
        break;
    case OBJ_PHASE_C:
        func_00383848(self);
        break;
    }
}

/* sn-2.95.3-136 matched TU. */





#define CYL_HEIGHT  3.0f
#define CYL_RADIUS  0.8f

/* Set up a hit-volume object: a damage-take unit with a cylinder at its matrix, a hit point of 1, cleared state words and a six entry table. */
__attribute__((section(".text.cOmHitVolume_setupCylinderH3")))
int cOmHitVolume_setupCylinderH3(cOmHitVolume *self)
{
    float f[8];
    float *nv;
    void *slot;
    float one;

    func_001B6FB8(self);
    one = 1.0f;
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &f[4];
        f[4] = 0.0f;
        f[5] = 0.0f;
        f[6] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)f, (const cVec *)nv, CYL_HEIGHT, CYL_RADIUS);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->unk5F4 = -1;
    self->unk5E8 = 0;
    self->table = self->tableData;
    self->count = 6;
    self->unk5F6 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5EC = 0;
    func_001C28A0(self);
    return 1;
}

/* sn-2.95.3-136 matched TU. */





#define CYL_HEIGHT  4.0f
#define CYL_RADIUS  0.8f

/* Set up a hit-volume object: a damage-take unit with a cylinder at its matrix, a hit point of 1, cleared state words and a eight entry table. */
__attribute__((section(".text.cOmHitVolume_setupCylinderH4")))
int cOmHitVolume_setupCylinderH4(cOmHitVolume *self)
{
    float f[8];
    float *nv;
    void *slot;
    float one;

    func_001B6FB8(self);
    one = 1.0f;
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &f[4];
        f[4] = 0.0f;
        f[5] = 0.0f;
        f[6] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)f, (const cVec *)nv, CYL_HEIGHT, CYL_RADIUS);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 8;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    self->unk5EC = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}





/* Set up a hit-volume object: a damage-take box registered with the damage manager, cleared state words and a table at 0x620. */
__attribute__((section(".text.cOmHitVolume_setupBox_20")))
int cOmHitVolume_setupBox_20(cOmHitVolume *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca;

    func_001B6FB8(self);
    ca = 2.0f;
    f[1] = ca;
    f[5] = ca;
    one = 1.0f;
    f[0] = one;
    f[2] = one;
    f[3] = one;
    t = &f[4];
    f[4] = one;
    f[6] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m = &f[8];
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 17;
    self->unk5F6 = 46;
    func_001C28A0(self);
    return 1;
}
