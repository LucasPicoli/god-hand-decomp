/* include/godhand/cOmWeapon.h - a weapon lying on the map or carried by a fighter.
 *
 * cOmWeapon extends cOmBase: the first 0x5E0 bytes are the cOmBase record, and
 * the weapon adds its own state from 0x600. A weapon can be held (parent set),
 * thrown, falling or broken. Its child list entry 0 is the collision body, a
 * second cOmBase that the weapon repositions every time it changes hands.
 *
 * Field offsets are exact: every body that uses this header builds
 * byte-identical to retail. A field nobody has named yet is unkNNN padding.
 */
#ifndef GODHAND_COMWEAPON_H
#define GODHAND_COMWEAPON_H

#include "godhand/cOmBase.h"

#define COMWEAPON_PIECE_NUM 7

/* One piece of debris. rot is the spin per frame, vel the launch velocity. */
typedef struct cOmWeaponPiece {
    float rot[3];                       /* 0x00 */
    float unk0C;
    float vel[3];                       /* 0x10 */
    float unk1C;
} cOmWeaponPiece;

typedef struct cOmWeapon {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cOmBase *parent;                        /* 0x600 the fighter holding it, 0 when free */
    int parentIdx;                          /* 0x604 index of the held slot on the parent */
    char unk608[0x8];
    cVec heldPos;                           /* 0x610 */
    cVec heldOfs;                           /* 0x620 */
    float fallSpeed;                        /* 0x630 */
    char unk634[0xC];
    cVec vel;                               /* 0x640 launch velocity */
    char unk650[0x14];
    unsigned char unk664;                   /* 0x664 */
    unsigned char unk665;                   /* 0x665 */
    char unk666[0x2];
    int timer;                              /* 0x668 frame countdown, see Obj1D00_TickTimer_668 */
    float unk66C;                           /* 0x66C */
    int throwArg;                           /* 0x670 second argument of setThrow */
    char unk674[0x1C];
    int target;                             /* 0x690 object the weapon was thrown at */
    float spin;                             /* 0x694 */
    char unk698[0x8];
    int unk6A0;                             /* 0x6A0 */
    float unk6A4;                           /* 0x6A4 */
    float unk6A8;                           /* 0x6A8 */
    char unk6AC[0x4];
    cOmWeaponPiece piece[COMWEAPON_PIECE_NUM];/* 0x6B0 debris pieces spawned when it breaks */
} cOmWeapon;

typedef char cOmWeapon_size_check[(sizeof(cOmWeapon) == 0x790) ? 1 : -1];

#endif
