/* include/godhand/cOmHitVolumeSetup.h - the calls the cOmHitVolume setup routines share
 * (sn code at 0x188DE0..0x1A3B80).
 */
#ifndef GODHAND_COMHITVOLUMESETUP_H
#define GODHAND_COMHITVOLUMESETUP_H

#include "godhand/cOmHitVolume.h"

/* The setup steps the family shares. */
extern int func_001B6FB8(cOmHitVolume *self);    /* cOmBase constructor step */
extern int func_001C28A0(cOmHitVolume *self);    /* enemy work defaults */
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern void cDamageUnit_SetDamageCollActive(void *unit, int on);
extern int func_001FD9D8(void *unit, void *mtx, cVec *ofs, cVec *rot, cVec *size);
extern char D_00574380[];                               /* the damage manager */

/* The work defaults the effect-registering setups write: hit points, the entry table,
 * and the timer pair at 0x5E8/0x5F0. */
static __inline__ void cOmHitVolume_initWork(cOmHitVolume *em, int hp, char *table, int count, int kind, int timer)
{
    em->unk5E8 = timer;
    em->unk5E4 = 0;
    em->unk5F0 = timer;
    em->unk5F6 = 0;
    em->base.hpMax = hp;
    em->base.hp = hp;
    em->table = table;
    em->count = count;
    em->unk5EC = kind;
    em->unk5F4 = -1;
}

#endif /* GODHAND_COMHITVOLUMESETUP_H */
