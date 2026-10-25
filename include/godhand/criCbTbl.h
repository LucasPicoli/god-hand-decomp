/* include/godhand/criCbTbl.h - the CRI callback table D_00758620 (8 groups of 6 slots,
 * cygnus code at 0x33B978..0x33BC48). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CRICBTBL_H
#define GODHAND_CRICBTBL_H

#define CRICB_GROUPS   8
#define CRICB_SLOTS    6

typedef struct CriCbEnt {
    void *func;                 /* 0x00 handler, 0 when the slot is free */
    void *obj;                  /* 0x04 handler argument */
    void *name;                 /* 0x08 label for the error report */
} CriCbEnt;                     /* 0x0C */

extern CriCbEnt D_00758620[CRICB_GROUPS][CRICB_SLOTS];

extern void func_0033B790(const char *msg);

#endif
