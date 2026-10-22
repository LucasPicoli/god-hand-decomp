/* sn-2.95.3-136: func_0016FA80, enemy setup with a 2.6 x 1.8 x 1.2 damage-take volume, the enemy work defaults,
 * and effect data 0x25A registered from the resource at 0x304. */
#include "godhand/cOmHitVolumeSetup.h"

extern void espSys_effDataRegist(void *self, int id, void *data);
extern char D_007419A0[];

static inline void setState(cOmHitVolume *em, int v)
{
    em->base.hpMax = v;
    em->base.hp = v;
    em->unk5EC = v;
}

__attribute__((section(".text.func_0016FA80")))
int func_0016FA80(cOmHitVolume *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    void *slot;
    char *res;

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 2.6f;
    v[0].y = 1.8f;
    v[0].z = 1.2f;
    v[1].x = 2.6f;
    v[1].y = 1.8f;
    v[1].z = 1.2f;
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
    em->unk5E4 = 0;
    em->unk5F6 = 0;
    em->unk5E8 = 0x25A;
    em->unk5F0 = 0x25A;
    em->table = em->tableData;
    em->count = 9;
    em->unk5F4 = -1;
    setState(em, 1);
    func_001C28A0(em);
    res = (char *)em->base.texKey;
    espSys_effDataRegist(D_007419A0, 0x25A, (char *)(*(int *)(res + 0xC) + (int)res));
    em->base.flags5A0 |= 0x10;
    return 1;
}
