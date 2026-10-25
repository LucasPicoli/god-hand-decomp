/* include/godhand/NameTable.h - the loaded table of named entries at D_007588FC.
 *
 * D_007588FC points at an array of D_00758900 entries of 0x10 bytes. Each
 * entry is a 0xC-byte name followed by one word the lookups return. Field
 * names are ours; offsets are exact.
 */
#ifndef GODHAND_NAMETABLE_H
#define GODHAND_NAMETABLE_H

#define NAMETABLE_NAME_LEN  0xC     /* bytes compared per lookup */

typedef struct NameEntry {
    char name[NAMETABLE_NAME_LEN];      /* 0x00 */
    int value;                          /* 0x0C */
} NameEntry;                            /* 0x10 */

typedef char NameEntry_chk_size[sizeof(NameEntry) == 0x10 ? 1 : -1];

extern NameEntry *D_007588FC;           /* the entry array, NULL until loaded */
extern int D_00758900;                  /* number of entries */

#endif
