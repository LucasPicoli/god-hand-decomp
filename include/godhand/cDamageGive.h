/* include/godhand/cDamageGive.h - cDamageGive, the damage an attack hands out.
 *
 * One record per attack volume. The part that matters to the hit code is
 * the hit vector at 0x10: the direction the target is pushed. SetDmgGiveHitVec
 * copies a vector in; SetDmgGiveHitVecDir turns a facing direction into a
 * push direction by rotating the unit Z axis with it.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CDAMAGEGIVE_H
#define GODHAND_CDAMAGEGIVE_H

#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"

typedef struct cDamageGive {
    CDAMAGE_UNIT_FIELDS;                /* 0x00..0x53, as cDamageUnit */
    char unk54[0x60 - 0x54];
} cDamageGive;                          /* 0x60: the manager's give array has a 0x60 stride */

typedef char cDamageGive_size_check[(sizeof(cDamageGive) == 0x60) ? 1 : -1];

/* Hand give to owner and set it up for kind; nothing on the spare. Returns 1. */
int SetObjTargetAndActivate_1FD2C0(cDamageGive *self, int kind, struct cGameObj *owner);

/* Resets a give: the head, attacker and type 1. */
void func_001FCDB8(cDamageGive *self);

/* Copies x, y and z of vec into hitVec (SetDmgGiveHitVec__11cDamageGiveRC4cVec). */
void cDamageGive_SetDmgGiveHitVec(cDamageGive *self, const cVec *vec);

#endif
