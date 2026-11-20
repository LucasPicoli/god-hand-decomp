/* include/godhand/EspDataBank.h - the effect data bank (D_00741DC8).
 *
 * The bank keeps up to ESP_BANK_NUM registered effect data blocks from 0x100.
 * A block starts with a magic word and a resource count; registering one
 * copies each resolved resource pointer into res[] (the first words of the
 * bank), and unregistering clears them again. Names are ours. Offsets are
 * exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_ESPDATABANK_H
#define GODHAND_ESPDATABANK_H

#define ESP_BANK_NUM     0x4E2
#define ESP_BANK_RES_NUM 0x40

typedef struct EspDataBlock {
    int magic;                  /* 0x00 */
    unsigned int count;         /* 0x04 resources in the block */
    char unk08[8];
    int ofs[ESP_BANK_RES_NUM];  /* 0x10 each resource's offset from the block, 0 when missing; count are used */
} EspDataBlock;

typedef struct EspDataBank {
    void *res[ESP_BANK_RES_NUM];        /* 0x000 */
    EspDataBlock *block[ESP_BANK_NUM];  /* 0x100 */
} EspDataBank;

typedef char EspDataBank_chk[(int)&((EspDataBank *)0)->block == 0x100 ? 1 : -1];

extern EspDataBank D_00741DC8;

/* Look up entry index of the resource table; 0 when it is missing. */
int func_00306C78(void **table, unsigned int index, void *out1, void *out2);

/* Address of resource index of a block in *out; 0 (and *out 0) when it is missing. */
int func_00306A48(EspDataBlock *blk, unsigned int index, void **out);

/* Unregister block id; 1 if its slot held a block. */
int func_00306BB0(EspDataBank *bank, int id);

#endif /* GODHAND_ESPDATABANK_H */
