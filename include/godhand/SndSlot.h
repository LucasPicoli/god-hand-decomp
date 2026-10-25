/* include/godhand/SndSlot.h - the sound slot table.
 *
 * D_00770850 holds SND_SLOT_NUM slots of 0xE0 bytes. A slot is live while
 * `state` is nonzero. Each frame the update pass walks the table: a slot
 * with SND_SLOT_CHECK set is validated first, then its state is advanced.
 * Names are ours. Offsets are exact. A field we can't name stays as unkNNN.
 */
#ifndef GODHAND_SNDSLOT_H
#define GODHAND_SNDSLOT_H

#define SND_SLOT_NUM     0x30
#define SND_SLOT_SIZE    0xE0
#define SND_SLOT_CHECK   0x1000   /* SndSlot.state: id must be revalidated */

typedef struct SndSlot {
    unsigned short state;       /* 0x00 0 means free */
    short unk02;
    int id;                     /* 0x04 0 means no voice yet */
    char unk08[0xD8];
} SndSlot;                      /* 0xE0 */

extern SndSlot D_00770850[SND_SLOT_NUM];

#endif
