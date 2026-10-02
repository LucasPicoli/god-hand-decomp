/* include/godhand/cOm1f.h - cOm1f, a cOmBase object that patrols a home point.
 *
 * cOm1f builds on the cOmBase record (0x5E0 bytes) and adds a set type at
 * 0x600, a move range at 0xAF8 and a home position at 0xB10. The set type
 * is 0 or 1: changeSetType flips the mesh layers and the model flag bits to
 * match it, setStart restarts the state bytes from it.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COM1F_H
#define GODHAND_COM1F_H

#include "godhand/cOmBase.h"

typedef struct cOm1f {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    int setType;                        /* 0x600 */
    char unk604[0xAF8 - 0x604];
    float moveRange[4];                 /* 0xAF8 */
    char unkB08[0xB10 - 0xB08];
    float homePos[3];                   /* 0xB10 */
} cOm1f;

typedef char cOm1f_size_check[(sizeof(cOm1f) == 0xB20) ? 1 : -1];

#endif
