/* sn-2.95.3-136: func_0019AA80, enemy setup with a damage-take volume and the enemy work defaults. */
#include "godhand/cOmHitVolumeSetup.h"

static inline void cVec_setW(cVec *v, float w)
{
    v->w = w;
}

__attribute__((section(".text.func_0019AA80")))
int func_0019AA80(cOmHitVolume *em)
{
    cVec hit;              /* filled but never passed on */
    cVec size;
    cVec ofs;
    cVec rot;

    func_001B6FB8(em);
    hit.x = 2.8f; hit.y = 0.6f; hit.z = 1.6f;
    cVec_setW(&hit, 1.0f);
    size.x = 2.8f; size.y = 1.0f; size.z = 1.6f;
    cVec_setW(&size, 1.0f);
    ofs.x = 0.0f; ofs.y = 0.0f; ofs.z = 0.0f;
    cVec_setW(&ofs, 1.0f);
    em->damageTake = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    if (em->damageTake != 0) {
        rot.x = 0.0f; rot.y = 0.0f; rot.z = 0.0f;
        cVec_setW(&rot, 1.0f);
        func_001FD9D8(em->damageTake, em->base.mtx, &ofs, &rot, &size);
    }
    cOmHitVolume_initWork(em, 1, em->tableData, 7, 7, 0);
    func_001C28A0(em);
    return 1;
}
