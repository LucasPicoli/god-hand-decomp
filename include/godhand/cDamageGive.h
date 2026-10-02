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

typedef struct cDamageGive {
    char unk00[0x10];
    cVec hitVec;                        /* 0x10 push direction of the hit */
} cDamageGive;

#endif
