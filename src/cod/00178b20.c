/* sn-2.95.3-136: func_00178B20, enemy setup with a 3.7 x 1.5 x 1.352 damage-take volume, a radius 2 damage-give
 * sphere and the enemy work defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00178B20")))
int func_00178B20(cOmHitVolume *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    float *ov;
    void *slot;
    void *give;

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 3.7f;
    v[0].y = 1.5f;
    v[0].z = 1.352f;
    v[1].x = 3.7f;
    v[1].y = 1.5f;
    v[1].z = 1.352f;
    v[0].w = 1.0f;
    size->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, em->base.mtx, ofs, rot, size);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->damageGive = give;
    if (give != 0) {
        ov = &v[3].x;
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        ov[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 2.0f);
        *(short *)(((char *)em->damageGive) + 0x46) = 0x2E;
        *(int *)(((char *)em->damageGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->damageGive, 0);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->table = em->tableData;
    em->count = 8;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->unk5F4 = -1;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    func_001C28A0(em);
    return 1;
}
