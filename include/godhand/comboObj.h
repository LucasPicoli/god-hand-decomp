/* include/godhand/comboObj.h - the combo state of an object that runs combos (sn code at 0x126918, 0x12C000).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_COMBOOBJ_H
#define GODHAND_COMBOOBJ_H

typedef struct ComboObj {
    char unk000[0x5E0];
    unsigned short slot;                /* 0x5E0 combo slot being run */
    unsigned short set;                 /* 0x5E2 combo set */
    unsigned short ticks;               /* 0x5E4 */
    unsigned short stage;               /* 0x5E6 */
    char unk5E8[0x1080];
    int moveA;                          /* 0x1668 */
    int moveB;                          /* 0x166C */
} ComboObj;

#endif /* GODHAND_COMBOOBJ_H */
