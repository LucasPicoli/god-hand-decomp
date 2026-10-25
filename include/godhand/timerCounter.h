/* include/godhand/timerCounter.h - EE kernel timer counter records (ee-2.9 code at 0x3B7270..).
 * Field names are ours; offsets are exact. Counter n sits at (n >> 10) << 6.
 */
#ifndef GODHAND_TIMERCOUNTER_H
#define GODHAND_TIMERCOUNTER_H

#define TC_ERR_BAD_ID       0x80008002
#define TC_ERR_BUSY         0x80000010
#define TC_ID_MASK          0x3FF
#define TC_RUN              1       /* flags bit: counter is running */
#define TC_HANDLER          2       /* flags bit: a handler is set */

typedef struct TimerCounter {
    int pad00[2];
    int id;                     /* 0x08 low 10 bits of the counter id */
    int flags;                  /* 0x0C TC_RUN | TC_HANDLER */
    long time;                  /* 0x10 */
    char unk18[0x20 - 0x18];
    long handler;               /* 0x20 handler function */
    int common;                 /* 0x28 handler common argument */
    void *gp;                   /* 0x2C handler $gp */
    int arg;                    /* 0x30 */
} TimerCounter;

typedef struct TimerCtl {
    unsigned char pad00[0x1C];
    int f1C;                    /* 0x1C counter in use by the handler */
    TimerCounter *f20;          /* 0x20 */
} TimerCtl;

extern volatile TimerCtl D_003FBE90;
extern long iGetTimerSystemTime(void);
extern void func_003B6DB8(TimerCounter *t);
extern TimerCounter *func_003B6E40(TimerCounter *t);
extern void SetNextComp(long tm);

#endif
