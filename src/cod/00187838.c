/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmHitVolume.h"
#include "godhand/cDamageManage.h"

extern void func_001B6FB8(void *a0);


#define BOX_HALF_XY 2.0f                /* half extent along x and y */
#define BOX_HALF_Z  1.6f                /* half extent along z */

/* Spawn setup of an object with a box hit area: build the box, register it with the damage manager, and set the fields the step code starts from. */
__attribute__((section(".text.cOmHitVolume_setupBox_20_16")))
int cOmHitVolume_setupBox_20_16(cOmHitVolume *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, c, w;

    func_001B6FB8(self);
    c = BOX_HALF_XY;
    one = 1.0f;
    w = BOX_HALF_Z;
    f[0] = c;
    f[1] = c;
    t = &f[4];
    f[2] = w;
    f[3] = one;
    f[4] = c;
    f[5] = c;
    f[6] = w;
    t[3] = one;
    m = &f[8];
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
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
    self->base.hpMax = 1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->base.hp = 1;
    self->unk5F4 = -1;
    self->table = self->tableData;
    self->count = 8;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x89;
    func_001C28A0(self);
    return 1;
}
