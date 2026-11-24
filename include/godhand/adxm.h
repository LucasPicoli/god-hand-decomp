/* include/godhand/adxm.h - the ADX manager threads (cygnus code at 0x324C90..).
 *
 * Prototypes match their definitions.
 */
#ifndef GODHAND_ADXM_H
#define GODHAND_ADXM_H

#include "godhand/adxmCfg.h"
#include "godhand/criCbTbl.h"

extern int adxm_ResumeThread(int thid);
extern int adxm_SuspendThread(int thid);     /* server suspend */
extern void func_00325290(int thid);
/* Set up the manager threads at arg's priorities, or the defaults when arg is 0. */
extern void func_00325638(AdxmInitArg *arg);
/* The SVM lock and unlock callbacks; arg is the callback argument, unused. */
extern void func_00324C90(int arg);
extern void adxm_unlock(int arg);
/* Run the server thread thid at the lock priority until it is idle, then back at prio. */
extern void adxm_goto_svr_border(int thid, int prio);
/* The SVM server step: adxm_goto_svr_border on server thread D_003C814C; arg is unused. */
extern void Forward324D88_324E70(int arg);

extern AdxmCfg D_003C80B0;              /* thread priorities; `a` is the lock's */
extern int D_003C80E0;                  /* lock nesting count */
extern volatile int D_003C80E4;         /* server busy */
extern volatile int D_003C814C, D_003C8140, D_003C8138;    /* server thread ids */
extern int D_003CF9D0;                  /* caller's priority before the lock */
extern int D_003CF9D4;                  /* caller's thread id */

/* One ADX decoder slot (four of them at D_003D1E70). */
typedef struct AdxDecSlot {
    signed char used;           /* 0x00 */
    signed char unk01;          /* 0x01 */
    signed char n;              /* 0x02 */
    signed char unk03;          /* 0x03 */
    signed char unk04;          /* 0x04 */
    char unk05[0x17];
    int arg;                    /* 0x1C */
    int h[(0x1964 - 0x20) / 4]; /* 0x20 */
} AdxDecSlot;

extern AdxDecSlot D_003D1E70[4];

/* The two user callbacks. */
extern CriCbPair D_00755C20;    /* run by func_00325FA8 */
extern CriCbPair D_00755C28;    /* run by func_00325FD8 */

#endif
