/* sn-2.95.3-136: func_001A3E10, enemy setup with a 1.6 x 2.2 damage-take cylinder, a radius 1.5 damage-give sphere,
 * 50 hit points and flags2 bits 7 and 8. */
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cDamageGive.h"

extern int cDamageUnit_AddDamageCollCylinder(void *unit, void *mtx, float *ofs, float *rot, float r, float h);

__attribute__((section(".text.func_001A3E10")))
int func_001A3E10(cOmHitVolume *em)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    void *give;
    cVec *ov;

    func_001B6FB8(em);
    m = &v[2];
    v[0].x = 1.6f;
    v[0].y = 2.2f;
    v[0].z = 1.6f;
    v[0].w = 1.0f;
    v[1].x = 1.6f;
    v[1].y = 2.2f;
    v[1].z = 1.6f;
    v[1].w = 1.0f;
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
        cDamageUnit_AddDamageCollCylinder(slot, em->base.mtx, m, nv, v[1].y, v[1].x * 0.5f);
        *(int *)em->damageTake |= 1;
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->damageGive = give;
    if (give != 0) {
        ov = &v[3];
        v[3].x = 0.0f;
        ov->y = 3.0f;
        v[3].z = 0.0f;
        ov->w = 1.0f;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 1.5f);
        ((cDamageGive *)em->damageGive)->unk46 = 0x52;
        ((cDamageGive *)em->damageGive)->activeTime = 0x14;
        cDamageUnit_SetDamageCollActive(em->damageGive, 0);
    }
    em->base.hp = em->base.hpMax = 50;
    em->table = em->tableData;
    em->count = 9;
    em->unk5E4 = 1;
    em->unk5EC = 2;
    em->unk5E8 = 0;
    em->unk5F0 = 0;
    em->unk5F4 = 0x2D;
    em->unk5F6 = 0x2E;
    func_001C28A0(em);
    em->base.flags2 |= 0x180;
    return 1;
}
