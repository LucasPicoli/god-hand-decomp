/* include/godhand/cCockScroll.h - cCockScroll, the cockpit's message banner:
 * two cIDBase parts and a short message queue.
 *
 * The class name is retail's: the vtable D_0041E8C0 holds func_001467E8,
 * func_00146878 and func_00146A18, and its type-info function
 * (func_00146EA0) registers "11cCockScroll" with base "9cCockBase". Like
 * every cCockBase, the constructor stores the vtable pointer at 0x80
 * (0x1419EC). OnScroll (cCockScroll_OnScroll, 0x146978) is the only method
 * name the symbol table gives; the other names and the field names are
 * ours. The record goes on past `timer`; its total size is not known.
 */
#ifndef GODHAND_CCOCKSCROLL_H
#define GODHAND_CCOCKSCROLL_H

#include "godhand/cIDBase.h"

#define COCKSCROLL_WORK_NUM  4
#define COCKSCROLL_TOP       (-50.0f)   /* entry 0's start y in each part */
#define COCKSCROLL_SHOW_TIME 0x5A       /* frames the queued message stays up */

typedef struct cCockScroll {
    cIDBaseObj base;                        /* 0x00 */
    char unk48[0x79 - 0x48];
    unsigned char state[4];                 /* 0x79 cCockScroll_reset clears all four */
    char unk7D[0x80 - 0x7D];
    void *vtable;                           /* 0x80 */
    char unk84[0x90 - 0x84];
    cIDBaseEnt *work[COCKSCROLL_WORK_NUM];  /* 0x90 the first part's entries */
    cIDBaseObj part2;                       /* 0xA0 */
    char unkE8[0x100 - 0xE8];
    short count;                            /* 0x100 queued messages */
    short timer;                            /* 0x102 */
} cCockScroll;

typedef char cCockScroll_vtable_check[((int)&((cCockScroll *)0)->vtable == 0x80) ? 1 : -1];
typedef char cCockScroll_part2_check[((int)&((cCockScroll *)0)->part2 == 0xA0) ? 1 : -1];
typedef char cCockScroll_timer_check[((int)&((cCockScroll *)0)->timer == 0x102) ? 1 : -1];

/* Clear the state bytes, initialise both parts' entries and restart the timer. */
void cCockScroll_reset(cCockScroll *self);

#endif /* GODHAND_CCOCKSCROLL_H */
