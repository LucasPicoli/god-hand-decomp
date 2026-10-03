/* include/godhand/cCollisionSolid.h - cCollisionSolid, one solid collision body.
 *
 * The base constructor (cCollisionSolid) clears the state words, zeroes two
 * vectors, points the vtable word at the base table and sets flag bit 0. The
 * sphere constructor runs it, swaps in the sphere table, stores the owner and
 * fills the centre and the radius. The record is at least 0x74 bytes; its real
 * size is not known.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CCOLLISIONSOLID_H
#define GODHAND_CCOLLISIONSOLID_H

#include "godhand/cOmBase.h"

#define CSOLID_STATE_SPHERE  1          /* state: the sphere constructor ran */

/* The C function cCollisionSolid is the constructor, so the record type has
 * its own name. */
typedef struct cCollisionSolidObj {
    int unk00;                          /* 0x00 cleared by the base constructor */
    int state;                          /* 0x04 */
    unsigned int flags;                 /* 0x08 bit 0 set by the constructor */
    char unk0C[4];
    cVec unk10;                         /* 0x10 zeroed */
    cVec unk20;                         /* 0x20 zeroed */
    const void *vt;                     /* 0x30 table of the body kind */
    char unk34[0xC];
    void *owner;                        /* 0x40 the object that owns the body */
    char unk44[0xC];
    cVec center;                        /* 0x50 sphere centre, w zeroed */
    cVec unk60;                         /* 0x60 zeroed */
    float radius;                       /* 0x70 sphere radius */
} cCollisionSolidObj;

typedef char cCollisionSolid_radius_check[((int)&((cCollisionSolidObj *)0)->radius == 0x70) ? 1 : -1];

#endif
