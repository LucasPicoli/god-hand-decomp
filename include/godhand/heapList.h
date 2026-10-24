/* include/godhand/heapList.h - a list whose entries live in one heap block.
 *
 * func_002A96D8 stores the block and its geometry in the first four words.
 * 00149378.c and 00150418.c destroy and refill two such lists.
 */
#ifndef GODHAND_HEAPLIST_H
#define GODHAND_HEAPLIST_H

typedef struct HeapList {
    int *block;                         /* 0x00 heap block that holds the entries, 0 when none */
    int entrySize;                      /* 0x04 */
    int num;                            /* 0x08 */
    int align;                          /* 0x0C */
    char unk10[0x8];
    int unk18;                          /* 0x18 entry count */
    int unk1C;                          /* 0x1C entry count */
    int size;                           /* 0x20 bytes in block */
    int capacity;                       /* 0x24 entries block holds */
} HeapList;

extern void func_002A9790(void *list);              /* empties the list */
extern int func_002A9860(int list, int cur);        /* the entry after cur (0 = the first), 0 at the end */
extern int func_002A96C0(int size, int num, int align);  /* bytes a block of num entries needs */
extern void func_002A96D8(int *list, int block, int entrySize, int num, int align);

#endif
