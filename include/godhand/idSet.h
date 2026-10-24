#ifndef GODHAND_IDSET_H
#define GODHAND_IDSET_H

#include "godhand/cIDBase.h"

#define IDSET_WORK_NUM  13

/* An id display (kind 4) that keeps pointers to its 13 element entries; the first one's position is mirrored at 0xA0. */
typedef struct IdSet {
    cIDBaseObj base;
    char unk48[0x48];
    int unk90;                          /* 0x90 */
    unsigned char active;               /* 0x94 bit 0: the display runs */
    unsigned char step;                 /* 0x95 which element group is shown, 0..6 */
    char unk96[0xA];
    float x;                            /* 0xA0 */
    float y;                            /* 0xA4 */
    char unkA8[8];
    cIDBaseEnt *work[IDSET_WORK_NUM];   /* 0xB0 */
    int msg;                            /* 0xE4 message id for elements 7 and 8, -1 = none */
} IdSet;

typedef char IdSet_msg_check[(int)&((IdSet *)0)->msg == 0xE4 ? 1 : -1];

#endif
