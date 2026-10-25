/* include/godhand/cSlotObj.h - a game object that carries a bank of slots.
 *
 * The object is a cGameObj with SLOTOBJ_SLOT_NUM slot records of
 * SLOTOBJ_SLOT_SIZE bytes from 0x5B0 and a 16-byte block at 0x2190. The
 * factory for ids 0x257 and 0x628 builds one. Names are ours. Offsets are
 * exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSLOTOBJ_H
#define GODHAND_CSLOTOBJ_H

#include "godhand/cGameObj.h"

#define SLOTOBJ_SIZE        0x21C0
#define SLOTOBJ_SLOT_NUM    0x2C
#define SLOTOBJ_SLOT_SIZE   0xA0

typedef struct cSlotObjSlot {
    char unk00[SLOTOBJ_SLOT_SIZE];
} cSlotObjSlot;                 /* 0xA0 */

typedef struct cSlotObj {
    cGameObj base;              /* 0x000 */
    char unk5AC[0x5B0 - 0x5AC];
    cSlotObjSlot slot[SLOTOBJ_SLOT_NUM]; /* 0x5B0 */
    char unk2090[0x2190 - (0x5B0 + SLOTOBJ_SLOT_NUM * SLOTOBJ_SLOT_SIZE)];
    char block[0x10];           /* 0x2190 */
    char unk21A0[SLOTOBJ_SIZE - 0x21A0];
} cSlotObj;                     /* 0x21C0 */

typedef char cSlotObj_size_check[sizeof(cSlotObj) == SLOTOBJ_SIZE ? 1 : -1];

#endif /* GODHAND_CSLOTOBJ_H */
