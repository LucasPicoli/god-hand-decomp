/* include/godhand/cOmBase.h - the base object of the cOm* family.
 *
 * cOmBase is the base class of the cOm* map objects (cOmWeapon derives from
 * it, and its collision bodies are cOmBase records too). One record is at
 * least 0x5E0 bytes; derived classes append their own state after it. Its
 * constructor (0x1B6E90) calls cGameObj first, so the record starts with
 * cGameObj's fields (CGAMEOBJ_FIELDS, 0x000..0x5AC) and adds three flag
 * words, a knock-back direction and a turn point. A child body's owner is
 * its cParts parent (0x148).
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_COMBASE_H
#define GODHAND_COMBASE_H

#include "godhand/cGameObj.h"

/* One node of the model's mesh list. A model owns a singly linked list of
 * nodes; each node carries the layer it belongs to. */
typedef struct cMeshNode {
    char unk000[0x380];
    unsigned int dispFlags;             /* 0x380 bit 0 hides, bit 13 is set per tag */
    char unk384[0x1C];
    float color[3];                     /* 0x3A0 r, g, b */
    float alpha;                        /* 0x3AC */
    char unk3B0[0x54];
    struct cMeshNode *next;             /* 0x404 */
    char unk408[4];
    unsigned char layer;                /* 0x40C */
} cMeshNode;

/* The hit record that cOmBase_checkDamage receives. */
typedef struct cDamageTake {
    char unk00[0x10];
    cVec dir;                           /* 0x10 hit direction */
    char unk20[0x14];
    char *attacker;                     /* 0x34 the object that dealt the hit */
    char unk38[0xE];
    short kind;                         /* 0x46 attack kind */
    char unk48[4];
    int power;                          /* 0x4C */
    char unk50[0x10];
    unsigned int flags;                 /* 0x60 bit 0 must be set for the hit to count */
} cDamageTake;

/* Bits of cOmBase.hitFlags (0x5B4), set by the hit classifier. */
#define COMBASE_HIT_STRONG    1
#define COMBASE_HIT_PLAYER    2
#define COMBASE_HIT_KNOCKBACK 4

/* Bits of flags0 (0x5B0). Names come from what the methods do with them. */
#define COMBASE_F0_ACTIVE     0x01      /* set once the object is running */
#define COMBASE_F0_GONE       0x02      /* removed: no drops, no hit checks */
#define COMBASE_F0_DROPPED    0x10      /* the item drop already happened */

/* Bits of flags2 (0x5B8). */
#define COMBASE_FLAG_HIDDEN   0x40      /* bit 6 */
#define COMBASE_FLAG_FALL     0x10      /* bit 4 */
#define COMBASE_OBJ_HELD      0x10      /* objFlags bit 4 */

typedef struct cOmBase {
    CGAMEOBJ_FIELDS                         /* 0x000..0x5AC */
    char unk5AC[0x4];
    int flags0;                             /* 0x5B0 */
    int hitFlags;                           /* 0x5B4 bits COMBASE_HIT_* */
    int flags2;                             /* 0x5B8 */
    char unk5BC[0x4];
    cVec knock;                             /* 0x5C0 */
    cVec posB;                              /* 0x5D0 */
} cOmBase;

typedef char cOmBase_size_check[(sizeof(cOmBase) == 0x5E0) ? 1 : -1];

/* Child number idx of an object, or 0 when idx is out of range. Writes the
 * child count to *frame, a dead store that retail keeps at the bottom of the
 * stack frame. */
static __inline__ cOmBase *cOmBase_childAt(cOmBase *b, int *frame, int idx)
{
    int n;

    *frame = n = b->partNum;
    if (idx >= 0 && idx < n) {
        return b->children[idx];
    }
    return 0;
}

#endif
