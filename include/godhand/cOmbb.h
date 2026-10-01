/* include/godhand/cOmbb.h - cOmbb, a bomb object.
 *
 * A bomb has a fuse state in two bytes near 0x2F4, a "fire lit" flag at
 * 0x600, a bomb-kind byte at 0x601, a countdown at 0x604 and the sound
 * handle of the hiss at 0x608. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COMBB_H
#define GODHAND_COMBB_H

#define COMBB_FUSE_LIT   2      /* value of fuseState once the fire is set */
#define COMBB_SE_HISS    0x15   /* sound effect id of the burning fuse */

typedef struct cOmbb {
    char unk000[0x2F4];
    unsigned char fuseMode;     /* 0x2F4 */
    char unk2F5;
    unsigned char fuseState;    /* 0x2F6 */
    char unk2F7[0x600 - 0x2F7];
    unsigned char fireLit;      /* 0x600 */
    unsigned char bombKind;     /* 0x601 */
    char unk602[2];
    float countdown;            /* 0x604 */
    int hissSe;                 /* 0x608 sound handle, 0 when none */
} cOmbb;

#endif
