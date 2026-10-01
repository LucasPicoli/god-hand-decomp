/* include/godhand/cDataManager.h - the loaded-data cache.
 *
 * cDataManager keeps an array of 0x5C-byte slots. Each slot holds one loaded
 * data file, found by a numeric kind. Callers ask for a kind, get the load
 * address back and the slot counts the use. A negative use count means the
 * slot is pinned and never counted down.
 *
 * Method names come from the retail symbol table. Field names are ours, taken
 * from the methods that read and write them. Offsets are exact. A field we
 * can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CDATAMANAGER_H
#define GODHAND_CDATAMANAGER_H

#define CDATA_SLOT_SIZE     0x5C
#define CDATA_USE_PINNED    (-100)      /* useCount value that pins a slot */
#define CDATA_FLAG_BUSY     0x4         /* bit 2 of flags: slot is reserved */

typedef struct cDataSlot {
    int state;                          /* 0x00 3 = in use, 4 = free for reuse */
    int useCount;                       /* 0x04 */
    int flags;                          /* 0x08 */
    char unk0C[4];
    int data;                           /* 0x10 load address of the data */
    char unk14[0xC];
    int kind;                           /* 0x20 numeric id of the data */
    char unk24[0x38];
} cDataSlot;                            /* 0x5C */

typedef struct cDataManager {
    int unk00;
    int slotNum;                        /* 0x04 */
    cDataSlot *slot;                    /* 0x08 */
} cDataManager;

extern int func_001FF0D8(cDataSlot *slot);               /* 1 when the slot holds data */
extern void func_001FF090(cDataSlot *slot);              /* count one more use */
extern int func_001FF180(cDataSlot *slot, int kind, void *buf);  /* start the load */
extern int UpdateStateReady_1FF238(cDataSlot *slot);     /* 0 while loading */
extern int ResetSlotState_1FF2E0(cDataSlot *slot, int arg);
extern void func_002D5250(int frames);                   /* wait */

extern int func_001FEE00(cDataManager *self, int kind);  /* slot index of kind, or -1 */
extern int func_001FEEA0(cDataManager *self);            /* index of a free slot, or -1 */

#endif
