/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cMc.h"
#include "godhand/cEvent.h"

extern cGameObj *InitFields_1B6E90(cGameObj *self);
extern void Obj0000_Set_Byte_54(void *p, int v);
extern int D_00427400;
extern int D_005864F0;
extern int cEmManage_CkPlCatched(void *p);
extern void func_0();
extern cMc D_005E6900;
extern cMcTaskRef D_00752C00;
extern void cMc_DllLoad(cMc *self, int pump);
extern void cMc_DllRelease(cMc *self);
extern void cTaskWork_exit(void *task);

/* Constructor of a game object subclass: base init, method table, seven cleared quadwords at 0x610, tag the block at 0x630. */
__attribute__((section(".text.cGameObj_constructSubclassA")))
cGameObj *cGameObj_constructSubclassA(cGameObj *self) {
    char *blk;
    InitFields_1B6E90(self);
    self->vt = (cGameObjVt *)&D_00427400;
    VU0_SQC2_VF0(self, 0x610);
    VU0_SQC2_VF0(self, 0x620);
    blk = (char *)self + 0x630;
    VU0_SQC2_VF0(self, 0x630);
    VU0_SQC2_VF0(self, 0x640);
    VU0_SQC2_VF0(self, 0x650);
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    Obj0000_Set_Byte_54(blk, 0);
    return self;
}

/* Motion blend record: a table of up to 0x23 words copied in from a source table. */
typedef struct BlendWork {
    char unk00[0x90];
    unsigned int flags;                 /* 0x90 */
    char unk94[0x2A8 - 0x94];
    int table[0x23];                    /* 0x2A8 copied from the source table */
    short tableNum;                     /* 0x334 words in use, at most 0x23 */
} BlendWork;

#define BLENDWORK_TABLE_READY 0x40000000        /* flags: the table holds fresh data */
#define BLENDWORK_TABLE_MAX   0x23



/* Copy num words from src into the table (clamped to the table size) and mark the table ready. */
__attribute__((section(".text.BlendWork_copyTable")))
void BlendWork_copyTable(BlendWork *self, void *src, short num) {
    if (num >= BLENDWORK_TABLE_MAX + 1) {
        self->tableNum = BLENDWORK_TABLE_MAX;
    } else {
        self->tableNum = num;
    }
    func_003A5148(self->table, src, self->tableNum << 2);
    self->flags |= BLENDWORK_TABLE_READY;
}

/* The player object (pl00): the fields the attack-button check reads. */
typedef struct Pl00 {
    char unk000[0x54A];
    short hp;                           /* 0x54A */
    char unk54C[0x6A0 - 0x54C];
    int actionLock;                     /* 0x6A0 nonzero while an action blocks the attack button */
    char unk6A4[0x15F4 - 0x6A4];
    char unk15F4;                       /* 0x15F4 low byte of the flag word */
    unsigned char btnFlags;             /* 0x15F5 bit 0: the attack button is enabled (bit 8 of the 0x15F4 word) */
} Pl00;


extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(Pl00 *p);


/* Nonzero if the player may start an attack action: alive, free, not caught, and the button flag is on. */
__attribute__((section(".text.pl00_ckAtkActBtnEnable")))
int pl00_ckAtkActBtnEnable(Pl00 *self) {
    if (self->actionLock != 0) {
        return 0;
    }
    if (self->hp <= 0) {
        return 0;
    }
    if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(self) != 0) {
        return 0;
    }
    if (cEmManage_CkPlCatched(&D_005864F0) != 0) {
        return 0;
    }
    return self->btnFlags & 1;
}

/* Load the memory card module, run its two stripped log hooks, release it and end the calling task. */
__attribute__((section(".text.cMc_loadRunRelease")))
void cMc_loadRunRelease(void) {
    cMc_DllLoad(&D_005E6900, 0);
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr00);
    cMc_DllRelease(&D_005E6900);
    cTaskWork_exit(D_00752C00.task);
}

/* A four-slot table of {key, value} pairs. */
typedef struct KeySlot {
    int key;                            /* 0x0 key, 0 when the slot is free */
    int value;                          /* 0x4 */
} KeySlot;




/* Store value under key: replace the value of an existing key, else take a free slot. 1 on success, 0 if full. */
__attribute__((section(".text.KeySlotTable_set")))
int KeySlotTable_set(KeySlot *tbl, int key, int value) {
    KeySlot *found = func_002BB068(tbl, key);
    KeySlot *fresh;
    if (found != 0) {
        found->value = value;
    } else {
        fresh = func_002BB098(tbl);
        if (fresh == 0) {
            return 0;
        }
        fresh->key = key;
        fresh->value = value;
    }
    return 1;
}
