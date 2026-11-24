/* include/godhand/criCbTbl.h - the CRI callback table D_00758620 (8 groups of 6 slots,
 * cygnus code at 0x33B978..0x33BC48), the lock and unlock callbacks next to it and
 * the init at 0x33BE80. Field names are ours; offsets are exact.
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

extern void SVM_CallErr1(const char *msg);

/* A callback and the argument it is called with. */
typedef struct CriCbPair {
    void (*fn)(int arg);        /* 0x00 0 when unset */
    int arg;                    /* 0x04 */
} CriCbPair;                    /* 0x08 */

typedef char CriCbPair_size_check[sizeof(CriCbPair) == 0x08 ? 1 : -1];

extern CriCbPair D_00758860[8]; /* set by SVM_SetCbBdr, run by SVM_GotoSvrBorder */
extern CriCbPair D_007588A0;    /* lock, called by svm_lock */
extern CriCbPair D_007588A8;    /* unlock, called by svm_unlock */

/* First call only: clear the callback tables. */
extern void func_0033BE80(void);
/* Set callback `i` of D_00758860, the ones SVM_GotoSvrBorder runs. */
extern void SVM_SetCbBdr(int i, void (*fn)(int), int arg);
extern void Obj0000_Set_D_007588A0_Pair_33BC18(void (*fn)(int), int arg);
extern void Obj0000_Set_D_007588A8_XY_33BC30(void (*fn)(int), int arg);

#endif
