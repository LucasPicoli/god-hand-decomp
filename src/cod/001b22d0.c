/* sn-2.95.3-136: func_001B22D0, enemy setup with a 2.8 x 1.4 damage-take box, a radius 3 damage-give sphere and
 * the enemy work defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_001B22D0")))
int func_001B22D0(cOmHitVolume *em)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    void *give;
    cVec *ov;
    cVec *t;

    func_001B6FB8(em);
    t = &v[1];
    m = &v[2];
    v[0].x = 2.8f;
    v[0].y = 1.4f;
    v[0].z = 1.4f;
    v[0].w = 1.0f;
    v[1].x = 2.8f;
    v[1].y = 1.4f;
    v[1].z = 1.4f;
    t->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    m->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = 1.0f;
        func_001FD9D8(slot, em->base.mtx, m, nv, t);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->damageGive = give;
    if (give != 0) {
        ov = &v[3];
        v[3].x = 0.0f;
        ov->y = 1.0f;
        v[3].z = 0.0f;
        ov->w = 1.0f;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 3.0f);
        *(short *)(((char *)em->damageGive) + 0x46) = 0x32;
        *(int *)(((char *)em->damageGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->damageGive, 0);
        *(int *)em->damageGive |= 1;
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->table = em->tableData;
    em->count = 9;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->unk5F4 = -1;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    func_001C28A0(em);
    return 1;
}
