/* include/godhand/cCollisionScroll.h - the scrolling collision set.
 *
 * One cCollisionScroll (D_005CAE50) holds the collision data of the
 * current stage: a header, a table of named layers, a table of 16-byte
 * polygon groups and a table of collision entries. A layer is a run of
 * entries (first, count) under an 8-character name; turning a layer off
 * sets COLLSCROLL_ENTRY_OFF in each of its entries.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCOLLISIONSCROLL_H
#define GODHAND_CCOLLISIONSCROLL_H

#define COLLSCROLL_NAME_LEN    8        /* layer names are packed into one 64-bit word */
#define COLLSCROLL_ENTRY_OFF   2        /* bit of ScrollEntry.flags: entry is disabled */

typedef struct ScrollData {
    char unk00[0x20];
    unsigned short numLayers;           /* 0x20 entries in cCollisionScroll.layers */
} ScrollData;

typedef struct ScrollLayer {
    char unk00[8];
    unsigned short first;               /* 0x08 first entry of the layer */
    unsigned short count;               /* 0x0A entries in the layer */
    signed char name[COLLSCROLL_NAME_LEN]; /* 0x0C zero-padded, not terminated at 8 */
} ScrollLayer;                          /* 0x14 */

typedef struct ScrollEntry {
    char unk00[0xC];
    unsigned short group;               /* 0x0C index into cCollisionScroll.groups */
    char unk0E[2];
    unsigned int flags;                 /* 0x10 COLLSCROLL_ENTRY_* */
} ScrollEntry;                          /* 0x14 */

typedef struct cCollisionScroll {
    ScrollData *data;                   /* 0x00 0 until a stage is loaded */
    ScrollLayer *layers;                /* 0x04 */
    char *groups;                       /* 0x08 16-byte records, kind byte at +0xD */
    char unk0C[8];
    ScrollEntry *entries;               /* 0x14 */
} cCollisionScroll;

/* Layer i as an integer sum, index first. &layers[i] gives the same address with
 * the addu operands the other way round (func_001331B8). */
#define COLLSCROLL_LAYER_AT(base, i)     ((ScrollLayer *)((i) * sizeof(ScrollLayer) + (unsigned int)(base)))

typedef char cCollisionScroll_chk_layer[sizeof(ScrollLayer) == 0x14 ? 1 : -1];
typedef char cCollisionScroll_chk_entry[sizeof(ScrollEntry) == 0x14 ? 1 : -1];

#endif
