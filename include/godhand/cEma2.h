/* include/godhand/cEma2.h - cEma2, an enemy type built on cGameObj.
 *
 * cEma2 is one enemy class of the roster: a cGameObj with a copy of the
 * SET_EM_DATA record it was created from, an escape position, a wait
 * counter and a few mesh pointers it hides and shows. Its methods read the
 * base class fields (hp, state bytes, motion flags) and the player.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet keeps its offset as its name
 * (unkNNN); the size of the record is not known.
 */
#ifndef GODHAND_CEMA2_H
#define GODHAND_CEMA2_H

#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"

#define EMA2_MESH_NUM  8                /* meshes it shows and hides */

/* Bits of cEma2.flags. */
#define EMA2_F_SELF_HIT  0x02           /* the last hit came from this enemy itself */
#define EMA2_F_POISON    0x08           /* set by func_00289028, SetPoison */

typedef struct cEma2 {
    cGameObj base;                      /* 0x0000 */
    char unk5AC[0x1530 - 0x5AC];
    SET_EM_DATA setData;                /* 0x1530 the room record it was entered with */
    char unk1564[0x1590 - 0x1564];
    cVec escPos;                        /* 0x1590 (x, y, z only) where it runs to */
    unsigned int state1;                /* 0x15A0 */
    float unk15A4;                      /* 0x15A4 */
    int unk15A8;                        /* 0x15A8 */
    float unk15AC;                      /* 0x15AC */
    unsigned int flags;                 /* 0x15B0 EMA2_F_* */
    char *mesh[EMA2_MESH_NUM];          /* 0x15B4 mesh nodes it hides and shows */
    char unk15D4[0x15F4 - 0x15D4];
    unsigned char unk15F4;              /* 0x15F4 */
} cEma2;

#define EMA2_OFFSET(field) ((int)&((cEma2 *)0)->field)
typedef char cEma2_chk_set[EMA2_OFFSET(setData) == 0x1530 ? 1 : -1];
typedef char cEma2_chk_esc[EMA2_OFFSET(escPos) == 0x1590 ? 1 : -1];
typedef char cEma2_chk_flags[EMA2_OFFSET(flags) == 0x15B0 ? 1 : -1];
typedef char cEma2_chk_mesh[EMA2_OFFSET(mesh) == 0x15B4 ? 1 : -1];

/* The name every cEma2 carries in cGameObj.kindName; cEmManage compares it. */
extern char D_0044A7A8[];

#endif /* GODHAND_CEMA2_H */
