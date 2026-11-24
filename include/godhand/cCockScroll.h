/* include/godhand/cCockScroll.h - cCockScroll, the cockpit's message banner:
 * two cIDBase parts and two short queues (message and kind).
 *
 * The class name is retail's: the vtable D_0041E8C0 holds func_001467E8,
 * func_00146878 and func_00146A18, and its type-info function
 * (func_00146EA0) registers "11cCockScroll" with base "9cCockBase". Like
 * every cCockBase, the constructor stores the vtable pointer at 0x80
 * (0x1419EC). OnScroll (cCockScroll_OnScroll, 0x146978) is the only method
 * name the symbol table gives; the other names and the field names are
 * ours. The record is 0x110 bytes: the cockpit's constructor builds it at
 * +0x1CB0 and the next cCockBase at +0x1DC0, and cIDBase's two cVecs (0x20,
 * 0x30) make it 16-byte aligned.
 */
#ifndef GODHAND_CCOCKSCROLL_H
#define GODHAND_CCOCKSCROLL_H

#include "godhand/cIDBase.h"

#define COCKSCROLL_WORK_NUM  4
#define COCKSCROLL_QUEUE_NUM 4          /* entries in each queue */
#define COCKSCROLL_TOP       (-50.0f)   /* entry 0's start y in each part, and the x it leaves by (step 5) */
#define COCKSCROLL_SHOW_TIME 0x5A       /* frames the queued message stays up */

typedef struct cCockScroll {
    cIDBaseObj base;                        /* 0x00 */
    char unk48[0x79 - 0x48];
    signed char state[4];                   /* 0x79 state[0] is the banner step; cCockScroll_reset clears all four */
    char unk7D[0x80 - 0x7D];
    void *vtable;                           /* 0x80 */
    char unk84[0x90 - 0x84];
    cIDBaseEnt *work[COCKSCROLL_WORK_NUM];  /* 0x90 the entries of the part on show */
    cIDBaseObj part2;                       /* 0xA0 */
    char unkE8[0xF0 - 0xE8];
    unsigned short msgQueue[COCKSCROLL_QUEUE_NUM];  /* 0xF0 queued message numbers */
    unsigned short kindQueue[COCKSCROLL_QUEUE_NUM]; /* 0xF8 their kinds: nonzero shows the second part */
    short count;                            /* 0x100 queued messages */
    short timer;                            /* 0x102 */
    unsigned char flags;                    /* 0x104 COCKSCROLL_FLAG_* */
    char unk105[0x110 - 0x105];
} cCockScroll;                              /* 0x110 */

/* cCockScroll.state[0]: the banner step */
enum {
    COCKSCROLL_STEP_WAIT,   /* wait for a queued message */
    COCKSCROLL_STEP_DROP,   /* slide entry 0 down to its rest y */
    COCKSCROLL_STEP_GROW,   /* grow entry 1 */
    COCKSCROLL_STEP_SHOW,   /* show the message until the timer runs out */
    COCKSCROLL_STEP_SHRINK, /* shrink entry 1 */
    COCKSCROLL_STEP_LEAVE,  /* move entry 0 out to the left */
    COCKSCROLL_STEP_POP     /* pop the queues and reset */
};

/* cCockScroll.flags */
#define COCKSCROLL_FLAG_LOW   0x01  /* entry 0 rests 50 lower; the step clears it every frame */
#define COCKSCROLL_FLAG_SHIFT 0x02  /* OnScroll moves entry 0 50 right, then clears it */

typedef char cCockScroll_vtable_check[((int)&((cCockScroll *)0)->vtable == 0x80) ? 1 : -1];
typedef char cCockScroll_part2_check[((int)&((cCockScroll *)0)->part2 == 0xA0) ? 1 : -1];
typedef char cCockScroll_timer_check[((int)&((cCockScroll *)0)->timer == 0x102) ? 1 : -1];
typedef char cCockScroll_flags_check[((int)&((cCockScroll *)0)->flags == 0x104) ? 1 : -1];
typedef char cCockScroll_size_check[sizeof(cCockScroll) == 0x110 ? 1 : -1];

/* Clear the state bytes, initialise both parts' entries and restart the timer. */
void cCockScroll_reset(cCockScroll *self);

/* Queue message `msg` of kind `kind` (0 or 1) if fewer than four are queued. */
void cCockScroll_OnScroll(cCockScroll *self, unsigned short msg, unsigned short kind);

#endif /* GODHAND_CCOCKSCROLL_H */
