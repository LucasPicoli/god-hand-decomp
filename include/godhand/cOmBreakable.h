/* include/godhand/cOmBreakable.h - cOmBreakable, a cOmBase object that breaks apart.
 *
 * A breakable map object owns a damage-take unit (what the player hits)
 * and a damage-give unit (what hurts the player while it breaks), and holds
 * its pieces as children from index 1 up. The setup routines of this family
 * (sn code at 0x187D88..) register both units and hide or fix the pieces.
 *
 * Offsets are exact; unknown spans stay unkNNN padding.
 */
#ifndef GODHAND_COMBREAKABLE_H
#define GODHAND_COMBREAKABLE_H

#include "godhand/cOmBase.h"

#define COMBREAK_PIECE_FIRST    1       /* first piece in the child list */
#define COMBREAK_PIECE_END      6       /* children past this index are not pieces */
#define COMBREAK_PART_NO_LOCAL  0x08    /* piece partFlags: skip the local matrix build */
#define COMBREAK_PART_NO_PARENT 0x10    /* piece partFlags: skip the multiply by the parent */
#define COMBREAK_MESH_HIDE      0x01    /* mesh node dispFlags: not drawn */

/* A piece, seen through the one word the setup sets. */
typedef struct cOmBreakPiece {
    char unk000[0x154];
    int partFlags;                      /* 0x154 COMBREAK_PART_* */
} cOmBreakPiece;

typedef struct cOmBreakable {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x22];
    short wait;                         /* 0x602 */
    void *dmgTake;                      /* 0x604 damage-take unit, 0 when none */
    void *dmgGive;                      /* 0x608 damage-give unit, 0 when none */
} cOmBreakable;

typedef char cOmBreakable_chk_take[((int)&((cOmBreakable *)0)->dmgTake == 0x604) ? 1 : -1];

#endif
