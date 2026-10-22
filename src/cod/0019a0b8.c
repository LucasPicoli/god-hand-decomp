/* sn-2.95.3-136: func_0019A0B8, enemy setup with a 3.6 x 3.5 x 3.6 damage-take volume and the enemy work
 * defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_0019A0B8")))
int func_0019A0B8(cOmHitVolume *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    void *slot;

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 3.6f;
    v[0].y = 3.5f;
    v[0].z = 3.6f;
    v[1].y = 3.5f;
    v[0].w = 1.0f;
    v[1].x = 3.6f;
    v[1].z = 3.6f;
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
    cOmHitVolume_initWork(em, 1, em->tableData, 7, 7, 0);
    func_001C28A0(em);
    return 1;
}
