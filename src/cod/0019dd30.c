/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmHitVolume.h"
#include "godhand/cDamageManage.h"

extern void func_001B6FB8(void *self);


/* Set the object up: a damage-take unit with a 0.8 x 4.6 x 0.8 volume whose origin sits at half the box depth, one hit point, a six entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox08x46x08")))
int cOmHitVolume_setupBox08x46x08(cOmHitVolume *self) {
    float box[4];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *t;                           /* sizeVec, addressed through a register as retail does */
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 0.8f;
    cb = 4.6f;
    cc = 0.8f;
    t = &sizeVec[0];
    m = &originVec[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = cc;
    box[3] = one;
    sizeVec[0] = ca;
    sizeVec[1] = cb;
    sizeVec[2] = cc;
    t[3] = one;
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = box[2] * 0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 6;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
