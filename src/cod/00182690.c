/* sn-2.95.3-136: func_00182690, enemy setup with a 3.24 x 1 x 1 damage-take volume, a radius 2 damage-give
 * sphere and the enemy work defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00182690")))
int func_00182690(cOmHitVolume *em)
{
    cVec v[4];
    cVec *m;
    cVec *t;
    void *take;
    void *give;

    func_001B6FB8(em);
    t = &v[1];
    m = &v[2];
    v[0].x = 3.24f;
    v[0].y = 1.0f;
    v[0].z = 1.0f;
    v[1].x = 3.24f;
    v[0].w = 1.0f;
    v[1].y = 1.0f;
    v[1].z = 1.0f;
    t->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    m->w = 1.0f;
    take = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->damageTake = take;
    if (take != 0) {
        cVec *nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = 1.0f;
        func_001FD9D8(take, em->base.mtx, m, nv, t);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->damageGive = give;
    if (give != 0) {
        cVec *nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = 1.0f;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, nv, 2.0f);
        *(short *)(((char *)em->damageGive) + 0x46) = 46;
        *(int *)(((char *)em->damageGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->damageGive, 0);
    }
    cOmHitVolume_initWork(em, 1, em->tableData, 8, 7, 0);
    func_001C28A0(em);
    return 1;
}
