/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmHitVolume.h"
#include "godhand/cDamageManage.h"

extern void func_001B6FB8(cOmHitVolume *self);

/* Set the object up: a damage-take unit with a 1.0 x 2.0 x 1.0 volume at its position, one hit point, a five entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox10x20x10")))
int cOmHitVolume_setupBox10x20x10(cOmHitVolume *self)
{
    float box[4];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *size;                        /* sizeVec, addressed through a register as retail does */
    float *origin;
    float *origin2;
    void *take;
    float one, cb;

    func_001B6FB8(self);
    one = 1.0f;
    cb = 2.0f;
    size = &sizeVec[0];
    box[0] = one;
    box[1] = cb;
    box[2] = one;
    box[3] = one;
    sizeVec[0] = one;
    sizeVec[1] = cb;
    sizeVec[2] = one;
    size[3] = one;
    origin = &originVec[0];
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = 0.0f;
    origin[3] = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        origin2[3] = one;
        func_001FD9D8(take, (const struct cMatrix *)self->base.mtx, (const cVec *)origin, (const cVec *)origin2, (const cVec *)size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x2E;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    func_001C28A0(self);
    return 1;
}

/* Set the object up: a damage-take unit with a 1.2 x 1.5 x 1.2 volume at its position, one hit point, a six entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox12x15x12")))
int cOmHitVolume_setupBox12x15x12(cOmHitVolume *self)
{
    float box[4];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *size;                        /* sizeVec, addressed through a register as retail does */
    float *origin;
    float *origin2;
    void *take;
    float one, ca, cb;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.2f;
    cb = 1.5f;
    size = &sizeVec[0];
    origin = &originVec[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = ca;
    box[3] = one;
    sizeVec[0] = ca;
    sizeVec[1] = cb;
    sizeVec[2] = ca;
    size[3] = one;
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = 0.0f;
    origin[3] = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        origin2[3] = one;
        func_001FD9D8(take, (const struct cMatrix *)self->base.mtx, (const cVec *)origin, (const cVec *)origin2, (const cVec *)size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 6;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x2E;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    func_001C28A0(self);
    return 1;
}

/* Set the object up: a damage-take unit with a 2.4306 x 1.1591 x 0.2 volume at its position, one hit point, a four entry table at 0x620 and the state words cleared; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox24x12x02")))
int cOmHitVolume_setupBox24x12x02(cOmHitVolume *self)
{
    float box[4];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *size;                        /* sizeVec, addressed through a register as retail does */
    float *origin;
    float *origin2;
    void *take;
    float one, cx, cy, cz;

    func_001B6FB8(self);
    one = 1.0f;
    cx = 2.4306f;
    cy = 1.1591f;
    cz = 0.2f;
    size = &sizeVec[0];
    origin = &originVec[0];
    box[0] = cx;
    box[1] = cy;
    box[2] = cz;
    box[3] = one;
    sizeVec[0] = cx;
    sizeVec[1] = cy;
    sizeVec[2] = cz;
    size[3] = one;
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = 0.0f;
    origin[3] = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        origin2[3] = one;
        func_001FD9D8(take, (const struct cMatrix *)self->base.mtx, (const cVec *)origin, (const cVec *)origin2, (const cVec *)size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 4;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
