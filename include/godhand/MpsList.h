/* include/godhand/MpsList.h - the MPS sort lists (sn code at 0x322748).
 *
 * An MpsList is a counted array of pointers to records that carry a signed
 * sort key. func_00322748 takes the records of one list that sort below a
 * later neighbour and moves them to the end of a second list, keeping the
 * rest in order.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MPSLIST_H
#define GODHAND_MPSLIST_H

#define MPSLIST_NONE  0xFFFFFFFFu   /* "no index" in the stack links */

typedef struct MpsKeyed {
    int unk00, unk04;
    int key;                            /* 0x08 sort key */
} MpsKeyed;

typedef struct MpsList {
    int *item;                          /* 0x00 */
    unsigned int count;                 /* 0x04 */
} MpsList;

#endif
