/* include/godhand/SubSlotTable.h - a nine-entry table of registered sub-objects.
 *
 * func_0015FD98 clears the 0x48-byte table and registers nine sub-objects of
 * its owner, each with a kind id. An entry is free while its obj is 0
 * (func_0015FD68 returns the first free index, -1 when all nine are used).
 * Names are ours.
 */
#ifndef GODHAND_SUBSLOTTABLE_H
#define GODHAND_SUBSLOTTABLE_H

#define SUBSLOT_NUM  9                  /* entries in a SubSlotTable */

typedef struct SubSlot {
    int kind;                           /* 0x00 id the owner gave the sub-object */
    void *obj;                          /* 0x04 the sub-object; 0 when the entry is free */
} SubSlot;                              /* 0x08 */

typedef struct SubSlotTable {
    SubSlot slot[SUBSLOT_NUM];          /* 0x00 */
} SubSlotTable;                         /* 0x48 */

typedef char SubSlot_size_check[sizeof(SubSlot) == 0x8 ? 1 : -1];
typedef char SubSlotTable_size_check[sizeof(SubSlotTable) == 0x48 ? 1 : -1];

#endif
