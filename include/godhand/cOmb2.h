/* include/godhand/cOmb2.h - cOmb2, a map object that moves along a scripted path.
 *
 * cOmb2 builds on the cOmBase record (0x5E0 bytes) and adds a move record at
 * 0x610. SetMove copies the target direction into the object, hands the
 * move record to cOmSub_initMove3_y, and sets state byte 1 (mode) so the
 * object starts to move.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding. The record's
 * real size is not known.
 */
#ifndef GODHAND_COMB2_H
#define GODHAND_COMB2_H

#include "godhand/cOmBase.h"

#define COMB2_MODE_MOVE  1      /* mode: following the move record */

typedef struct cOmb2 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x30];
    char move[0x20];                    /* 0x610 move record, built by cOmSub_initMove3_y */
} cOmb2;

typedef char cOmb2_move_check[((int)&((cOmb2 *)0)->move == 0x610) ? 1 : -1];

#endif
