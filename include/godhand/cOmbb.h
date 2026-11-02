/* include/godhand/cOmbb.h - cOmbb, a bomb object.
 *
 * cOmbb builds on the cOmBase record (0x5E0 bytes). The fuse state is the
 * base's mode and step bytes (0x2F4, 0x2F6). Past the base it has a "fire
 * lit" flag at 0x600, a bomb-kind byte at 0x601, a countdown at 0x604 and
 * the sound handle of the hiss at 0x608. The enemy manager keeps up to two
 * bombs (cEmManage.unk5AC). Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COMBB_H
#define GODHAND_COMBB_H

#include "godhand/cOmBase.h"

#define COMBB_FUSE_LIT   2      /* base.step once the fire is set */
#define COMBB_SE_HISS    0x15   /* sound effect id of the burning fuse */

typedef struct cOmbb {
    cOmBase base;               /* 0x000 */
    char unk5E0[0x20];
    unsigned char fireLit;      /* 0x600 */
    unsigned char bombKind;     /* 0x601 */
    char unk602[2];
    float countdown;            /* 0x604 */
    int hissSe;                 /* 0x608 sound handle, 0 when none */
} cOmbb;

void cOmbb_setFire(cOmbb *self);
unsigned char cOmbb_ckFire(cOmbb *self);
cVec *func_001B8720(cOmbb *self);

#endif
