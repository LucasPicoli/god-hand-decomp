/* include/godhand/ColiseumEmSelect.h - ColiseumEmSelect, the coliseum enemy pick screen.
 *
 * The screen is a large object (more than 0x37E0 bytes). The fields below
 * are the ones the recovered methods touch; the rest stays unkNNN.
 * func_001F46E0 releases the sub-object at 0x60 (a cIDBase). cardNode at
 * 0x37D8 is a heap node owned by the screen; the node's word at -0x20 is its
 * heap. Offsets are exact.
 */
#ifndef GODHAND_COLISEUMEMSELECT_H
#define GODHAND_COLISEUMEMSELECT_H

/* The global record at **D_003C2384; only the two words cleared at close are named. */
typedef struct ColiseumHost {
    char unk00[0xA8];
    int pickA;                  /* 0xA8 */
    int pickB;                  /* 0xAC */
} ColiseumHost;

typedef struct ColiseumEmSelect {
    char unk000[0x04];
    int vtIndex;                /* 0x04 index into the D_003BF0A8 dispatch table */
    char unk008[0x60 - 8];
    char idBase[0x10];          /* 0x60 sub-object released at close */
    char unk70[0x37D8 - 0x70];
    int *cardNode;              /* 0x37D8 heap node, 0 when none */
} ColiseumEmSelect;

#endif
