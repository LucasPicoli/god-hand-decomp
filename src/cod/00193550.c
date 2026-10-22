/* sn-2.95.3-136: func_00193550, hit volume 1.18 x 1.61 x 0.67 with the origin at half the depth, the damage-take
 * marked active, and a five entry table at 0x620. */
extern char D_00574380[];               /* the damage manager */

#include "godhand/cOmHitVolume.h"
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00193550")))
int func_00193550(cOmHitVolume *self) {
    cVec v[1];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *t;
    float *m;
    float *nv;
    void *slot;

    func_001B6FB8(self);
    t = &sizeVec[0];
    m = &originVec[0];
    v[0].x = 1.18f;
    v[0].y = 1.61f;
    v[0].z = 0.67f;
    v[0].w = 1.0f;
    sizeVec[0] = 1.18f;
    sizeVec[1] = 1.61f;
    sizeVec[2] = 0.67f;
    t[3] = 1.0f;
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = v[0].z * 0.5f;
    m[3] = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        nv[3] = 1.0f;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
        if (self->damageTake != 0)
            *(int *)self->damageTake |= 1;
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
