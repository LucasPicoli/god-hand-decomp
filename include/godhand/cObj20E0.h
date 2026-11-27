/* include/godhand/cObj20E0.h - the 0x20E0-byte object built at 0x312F70 (sn code).
 * Derives from cObjBase (0x000..0x4CF, method table at 0x214); holds an array
 * of 44 0xA0-byte records at 0x4D0 whose vectors the constructor zeroes, and
 * one more vector at 0x20B0. Factory id 0x101. Field names are ours; offsets
 * are exact.
 */
#ifndef GODHAND_COBJ20E0_H
#define GODHAND_COBJ20E0_H

#define COBJ20E0_SIZE       0x20E0
#define COBJ20E0_ALIGN      0x10
#define COBJ20E0_ENT_NUM    44          /* records at 0x4D0 */
#define COBJ20E0_ENT_SIZE   0xA0
#define COBJ20E0_NO_NEW     0x10000     /* D_00747A34 bit: this allocator is locked */

typedef struct cObj20E0Ent {
    char unk00[COBJ20E0_ENT_SIZE];      /* vectors at 0x00 0x10 0x30 0x40 0x50 0x80 */
} cObj20E0Ent;

typedef struct cObj20E0 {
    char base[0x214];                   /* cObjBase */
    void *vt;                           /* 0x214 */
    char unk218[0x4D0 - 0x218];
    cObj20E0Ent ent[COBJ20E0_ENT_NUM];  /* 0x4D0 */
    char unk2050[0x20B0 - 0x4D0 - sizeof(cObj20E0Ent) * COBJ20E0_ENT_NUM];
    char tail[0x20E0 - 0x20B0];         /* 0x20B0 */
} cObj20E0;

typedef char cObj20E0_size_check[sizeof(cObj20E0) == COBJ20E0_SIZE ? 1 : -1];

#endif
