/* sn-2.95.3-136: func_00192D20, enemy setup with two crossed 2.3 x 1.2 x 0.4 damage-take boxes (one offset 1 along z,
 * one offset -1 along x) and the enemy work defaults. */
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00192D20")))
int func_00192D20(cOmHitVolume *em)
{
    cVec v[7];             /* two box shapes, their sizes, their offsets, rotation */
    cVec *dimB;
    cVec *sizeA;
    cVec *sizeB;
    cVec *ofsA;
    cVec *ofsB;
    cVec *rot;
    float *mtx;
    void *slot;

    func_001B6FB8(em);
    dimB = &v[1];
    sizeA = &v[2];
    sizeB = &v[3];
    ofsA = &v[4];
    ofsB = &v[5];
    v[0].x = 0.4f;
    v[0].y = 1.2f;
    v[0].z = 2.3f;
    v[0].w = 1.0f;
    v[1].x = 2.3f;
    dimB->y = 1.2f;
    dimB->z = 0.4f;
    dimB->w = 1.0f;
    v[2].x = v[0].x;
    v[2].y = v[0].y;
    v[2].z = v[0].z;
    sizeA->w = 1.0f;
    v[3].x = v[1].x;
    v[3].y = v[1].y;
    v[3].z = v[1].z;
    sizeB->w = 1.0f;
    v[4].x = 0.0f;
    v[4].y = 0.0f;
    ofsA->z = 1.0f;
    ofsA->w = 1.0f;
    v[5].x = -1.0f;
    v[5].y = 0.0f;
    v[5].z = 0.0f;
    ofsB->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        rot = &v[6];
        mtx = em->base.mtx;
        v[6].x = 0.0f;
        v[6].y = 0.0f;
        v[6].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, mtx, ofsA, rot, sizeA);
        v[6].x = 0.0f;
        v[6].y = 0.0f;
        v[6].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(em->damageTake, mtx, ofsB, rot, sizeB);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->table = em->tableData;
    em->count = 6;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->unk5F4 = -1;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    func_001C28A0(em);
    return 1;
}
