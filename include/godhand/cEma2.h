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
#define EMA2_F_GOTO      0x80           /* gotoSwitch: it is heading for the goal */
#define EMA2_F_KISS      0x100          /* ckKiss reads this bit */

typedef struct cEma2 {
    cGameObj base;                      /* 0x0000 */
    char unk5AC[0x616 - 0x5AC];
    unsigned char unk616;               /* 0x616 set to 1 by the constructor */
    char unk617[0x670 - 0x617];
    int damageTake;                     /* 0x670 handle from cDamageManage_CreateDamageTake */
    int hitSphere[4];                   /* 0x674 damage spheres on four joints */
    char unk684[0x690 - 0x684];
    char shadow[0x10];                  /* 0x690 shadow record handed to KageInit, size not known */
    char unk6A0[0x1530 - 0x6A0];
    SET_EM_DATA setData;                /* 0x1530 the room record it was entered with */
    char unk1564[0x1590 - 0x1564];
    cVec escPos;                        /* 0x1590 (x, y, z only) where it runs to */
    cVec goal;                          /* 0x15A0 where gotoSwitch sends it; the constructor also stores a flag
                                         * (|= 0x40) in its first word, 0.02 in y and a random wait in w */
    unsigned int flags;                 /* 0x15B0 EMA2_F_* */
    cMeshNode *mesh[EMA2_MESH_NUM];     /* 0x15B4 mesh nodes it hides and shows */
    char unk15D4[0x15F0 - 0x15D4];
    cVec aim;                           /* 0x15F0 where the head turns to; byte 0x15F4 is also stored alone by func_002897F0 */
    float pitchRate;                    /* 0x1600 head pitch rate, damped every frame */
} cEma2;

#define EMA2_OFFSET(field) ((int)&((cEma2 *)0)->field)
typedef char cEma2_chk_dmg[EMA2_OFFSET(damageTake) == 0x670 ? 1 : -1];
typedef char cEma2_chk_shadow[EMA2_OFFSET(shadow) == 0x690 ? 1 : -1];
typedef char cEma2_chk_set[EMA2_OFFSET(setData) == 0x1530 ? 1 : -1];
typedef char cEma2_chk_goal[EMA2_OFFSET(goal) == 0x15A0 ? 1 : -1];
typedef char cEma2_chk_esc[EMA2_OFFSET(escPos) == 0x1590 ? 1 : -1];
typedef char cEma2_chk_flags[EMA2_OFFSET(flags) == 0x15B0 ? 1 : -1];
typedef char cEma2_chk_aim[EMA2_OFFSET(aim) == 0x15F0 ? 1 : -1];
typedef char cEma2_chk_pitch[EMA2_OFFSET(pitchRate) == 0x1600 ? 1 : -1];
typedef char cEma2_chk_mesh[EMA2_OFFSET(mesh) == 0x15B4 ? 1 : -1];

/* The name every cEma2 carries in cGameObj.kindName; cEmManage compares it. */
extern char D_0044A7A8[];

#endif /* GODHAND_CEMA2_H */
