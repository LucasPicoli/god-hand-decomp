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
    struct cGameObj *parent;                /* 0x600 the fighter holding it, 0 when free */
    int parentIdx;                          /* 0x604 index of the held slot on the parent */
    char unk608[0x8];
    cVec heldPos;                           /* 0x610 */
    cVec heldRot;                           /* 0x620 */
    float fallSpeed;                        /* 0x630 */
    char unk634[0xC];
    cVec vel;                               /* 0x640 launch velocity */
    char unk650[0x10];
    float life;                             /* 0x660 frames left before a dropped weapon breaks */
    unsigned char unk664;                   /* 0x664 */
    unsigned char unk665;                   /* 0x665 */
    char unk666[0x2];
    int timer;                              /* 0x668 frame countdown, see cOmWeapon_SetDamage */
    float unk66C;                           /* 0x66C */
    struct cGameObj *thrower;               /* 0x670 the fighter that threw it (setThrow's cGameObj argument) */
    float fallVel;                          /* 0x674 vertical speed while dropping */
    char unk678[0x10];
    unsigned char waterHit;                 /* 0x688 set once LineObj_checkWaterHit finds water */
    char unk689[0x7];
    int target;                             /* 0x690 object the weapon was thrown at */
    float spin;                             /* 0x694 */
    char unk698[0x8];
    int unk6A0;                             /* 0x6A0 */
    float unk6A4;                           /* 0x6A4 */
    float unk6A8;                           /* 0x6A8 */
    char unk6AC[0x4];
    cOmWeaponPiece piece[COMWEAPON_PIECE_NUM];/* 0x6B0 debris pieces spawned when it breaks */
} cOmWeapon;

/* cOmWeapon::setParent: attach the weapon to body part idx of par with the hold offsets heldPos and heldRot, and start the held state. */
void cOmWeapon_setParent(cOmWeapon *self, struct cGameObj *par, unsigned int idx, const cVec *heldPos, const cVec *heldRot);
/* Set the four state bytes to mode 0, phase 6 (7, 8 or 9), step 0, stepArg 0. */
void Obj1D00_ClearState_6(cOmBase *self);
void Obj1D00_ClearState_7(cOmBase *self);
void Obj1D00_ClearState_8(cOmBase *self);
void Obj1D00_ClearState_9(cOmBase *self);
/* setThrow's siblings: let go of the holder, launch with velocity vel, keep thrower and enter a throw state.
 * func_001CFB28 also zeroes the body's anchor (state 4); func_001D0140 enters 0x11, func_001D0240 0x12. */
void func_001CFB28(cOmWeapon *self, const cVec *vel, struct cGameObj *thrower);
void func_001D0140(cOmWeapon *self, const cVec *vel, struct cGameObj *thrower);
void func_001D0240(cOmWeapon *self, const cVec *vel, struct cGameObj *thrower);

typedef char cOmWeapon_size_check[(sizeof(cOmWeapon) == 0x790) ? 1 : -1];

/* Once per weapon: cast a line from posA to pos and, on a water surface,
 * splash and play the splash sound. */
void LineObj_checkWaterHit(cOmWeapon *self);

#endif
