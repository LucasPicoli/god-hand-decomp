/* include/godhand/cOm71Slots.h - the five tracked-object slots of a record
 * that watches cOm71 objects. Slots start at 0x5C and are 0x40 bytes apart.
 * Each slot holds the watched object and a 0x24-byte target record that the
 * step copies out before it tests it. Offsets are exact; fields nobody has
 * named stay as unkNN padding.
 */
#ifndef GODHAND_COM71SLOTS_H
#define GODHAND_COM71SLOTS_H

#include "godhand/cGameObj.h"

#define COM71SLOTS_BASE     0x5C        /* offset of slot 0 in the record */
#define COM71SLOTS_NUM      5
#define COM71SLOT_F_DONE    0x08        /* cOm71Slot.flags: the object has fallen */

/* The target record: only the limit height is named. */
typedef struct cOm71Target {
    int unk00[5];
    float limit;                        /* 0x14 object height below which it falls */
    int unk18[3];
} cOm71Target;                          /* 0x24 */

typedef struct cOm71Slot {
    cGameObj *obj;                      /* 0x00 watched object, 0 when the slot is free */
    int unk04;
    cOm71Target target;                 /* 0x08 */
    int unk2C;
    int flags;                          /* 0x30 COM71SLOT_F_* */
    char unk34[0x40 - 0x34];
} cOm71Slot;                            /* 0x40 */

typedef struct cOm71Slots {
    char unk00[COM71SLOTS_BASE];
    cOm71Slot slot[COM71SLOTS_NUM];     /* 0x5C */
} cOm71Slots;

typedef char cOm71Slot_size_check[(sizeof(cOm71Slot) == 0x40) ? 1 : -1];
typedef char cOm71Slots_chk_slot[((int)&((cOm71Slots *)0)->slot == 0x5C) ? 1 : -1];

extern void cOm71_SetMotionKokeru(void *obj);

#endif
