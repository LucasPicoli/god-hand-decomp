/* sn-2.95.3-136: enemy setup with a damage-take volume, then the enemy work defaults (0x19DD30);
 * volume build as SpawnDamageTakeVolumeE. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_0018EAF8")))
int func_0018EAF8(cOmHitVolume *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    void *slot;

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 0.4f;
    v[0].y = 1.2218f;
    v[0].z = 4.672f;
    v[1].x = 0.4f;
    v[1].y = 1.2218f;
    v[1].z = 4.672f;
    v[0].w = 1.0f;
    size->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, (const struct cMatrix *)((char *)em + 0x80), ofs, rot, size);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->table = em->tableData;
    em->count = 6;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    em->unk5F4 = -1;
    func_001C28A0(em);
    return 1;
}
