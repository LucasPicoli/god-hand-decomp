/* include/godhand/cIDDirIcons.h - a cIDBase display of four direction icons.
 *
 * The object keeps one word of direction bits at 0x94 and one display entry
 * per icon at 0x98..0xA4. Each frame an icon is shown when its bit is clear
 * and hidden when it is set, then the four bits are cleared for the next
 * frame. Offsets are exact; fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_CIDDIRICONS_H
#define GODHAND_CIDDIRICONS_H

#include "godhand/cIDBase.h"

#define IDDIR_NUM       4
#define IDDIR_BIT_0     0x80000000      /* dirBits: icon 0 */
#define IDDIR_BIT_1     0x40000000
#define IDDIR_BIT_2     0x20000000
#define IDDIR_BIT_3     0x10000000
#define IDDIR_ALL       (IDDIR_BIT_0 | IDDIR_BIT_1 | IDDIR_BIT_2 | IDDIR_BIT_3)

typedef struct cIDDirIcons {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x94 - 0x48];
    unsigned int dirBits;               /* 0x94 */
    cIDBaseEnt *icon[IDDIR_NUM];        /* 0x98 */
} cIDDirIcons;

#endif
