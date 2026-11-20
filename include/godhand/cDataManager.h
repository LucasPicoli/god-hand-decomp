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
#define SLOT_STATE_IDLE     8           /* state of an empty slot */

typedef struct cDataSlot {
    int state;                          /* 0x00 0 after cDataHolder_systemInit, 1 loading, 2 loaded,
                                         *      3 a use counted, 4 last use released, 5 released,
                                         *      8 idle (SLOT_STATE_IDLE); func_001FF110 sets 6 and 7 */
    int useCount;                       /* 0x04 */
    int flags;                          /* 0x08 */
    char unk0C[4];
    void *data;                         /* 0x10 load address of the data */
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
extern void *FileLoadRec_start(cDataSlot *slot, int kind, void *buf);  /* start the load */
extern int UpdateStateReady_1FF238(cDataSlot *slot);     /* 0 while loading */
extern int ResetSlotState_1FF2E0(cDataSlot *slot, int arg);
extern void cScenario_sleepFrames(int frames);                   /* wait */

extern int func_001FEE00(cDataManager *self, int kind);  /* slot index of kind, or -1 */
extern int func_001FEEA0(cDataManager *self);            /* index of a free slot, or -1 */
extern int cDataManager_isLoaded(cDataManager *self, int kind);
extern int cDataManager_isUnload(cDataManager *self, int kind); /* 1 unless a slot of kind is in a state other than SLOT_STATE_IDLE */
extern void cDataManager_resetKind(cDataManager *self, int kind, int arg);
extern void *cDataManager_useDataAddress(cDataManager *self, int kind); /* load address of kind, one more use counted */
extern void *cDataManager_loadWait(cDataManager *self, int kind, void *buf, int keep); /* load address of kind, loaded first if needed */

extern cDataManager D_005864E0;
extern cDataManager D_00580D20;

#endif
