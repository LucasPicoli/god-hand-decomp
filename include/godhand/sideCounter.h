/* include/godhand/sideCounter.h - D_00754C38: the list of objects with actor id 0, followed by
 * the side state the side check at 0x319848 reads and cEmManage_reset clears. */
#ifndef GODHAND_SIDECOUNTER_H
#define GODHAND_SIDECOUNTER_H

#include "godhand/ptrVec.h"

typedef struct SideCounter {
    PtrVecRef list;             /* 0x00 objects with actor id 0 (func_0030FCC0) */
    unsigned char on;           /* 0x04 */
    unsigned char side;         /* 0x05 */
    char pad6[2];
    int cnt;                    /* 0x08 */
    int unkC;                   /* 0x0C */
    float unk10;                /* 0x10 1.0 after func_002C53A8 */
} SideCounter;

extern SideCounter D_00754C38;

/* Constructor: empty list, side state cleared. Returns self. */
SideCounter *func_002C53A8(SideCounter *self);

#endif /* GODHAND_SIDECOUNTER_H */
