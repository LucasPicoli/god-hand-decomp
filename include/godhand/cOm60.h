/* include/godhand/cOm60.h - cOm60, a map object that can be thrown.
 *
 * cOm60 builds on the cGameObj record (0x5AC bytes). A thrown object keeps
 * its parent in `parent` (0 once it flies free), the throw direction in
 * `throwDir`, and a speed. setThrow detaches it, turns it to face the
 * direction and starts the throw effect and sound once.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_COM60_H
#define GODHAND_COM60_H

#include "godhand/cGameObj.h"

#define COM60_THROW_EFFECT  0x58
#define COM60_THROW_SE      0x117
#define COM60_THROW_PITCH   0.5235988f      /* 30 degrees */

typedef struct cOm60 {
    cGameObj base;                      /* 0x000 */
    char unk5AC[0x600 - 0x5AC];
    int parent;                         /* 0x600 nonzero while held; setThrow clears it */
    char unk604[0x2C];
    float speed;                        /* 0x630 */
    char unk634[0xC];
    cVec throwDir;                      /* 0x640 */
    float pitch;                        /* 0x650 */
    char unk654[0x12];
    unsigned char hitFlag;              /* 0x666 */
    unsigned char started;              /* 0x667 1 once the throw effect has run */
    int seHandle;                       /* 0x668 */
} cOm60;

typedef char cOm60_size_check[(sizeof(cOm60) == 0x66C) ? 1 : -1];

#endif
