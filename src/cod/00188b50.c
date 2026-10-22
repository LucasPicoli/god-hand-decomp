/* sn-2.95.3-136: func_00188B50, enemy setup with a 4.4 x 1.6 x 0.3 damage-take volume and the enemy work
 * defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00188B50")))
int func_00188B50(cOmHitVolume *em)
{
    float base[4];
    float size[4];
    float ofs[4];
    float rot[4];
    float *sz;
    float *of;
    float *rt;
    void *slot;

    func_001B6FB8(em);
    base[0] = 4.4f;
    base[1] = 1.234f;
    base[2] = 0.3f;
    base[3] = 1.0f;
    sz = size;
    size[0] = 4.4f;
    sz[1] = 1.6f;
    size[2] = 0.3f;
    sz[3] = 1.0f;
    of = ofs;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = 0.0f;
    of[3] = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        rt = rot;
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        rt[3] = 1.0f;
        func_001FD9D8(slot, em->base.mtx, of, rt, sz);
    }
    cOmHitVolume_initWork(em, 1, em->tableData, 6, 0xC9, 0);
    func_001C28A0(em);
    return 1;
}
