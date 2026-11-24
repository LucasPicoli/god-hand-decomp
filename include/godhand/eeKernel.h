/* include/godhand/eeKernel.h - EE kernel calls: interrupt enable and disable (0x3B63A0, 0x3B63F0),
 * DMA controller handlers and the thread calls. */
#ifndef GODHAND_EEKERNEL_H
#define GODHAND_EEKERNEL_H

/* DIntr: disable interrupts; nonzero when they were enabled. */
int DIntr(void);
/* Enable interrupts. */
int EIntr(void);

/* DMA controller interrupt handlers and channel interrupt masks. */
int AddDmacHandler2(int chan, int (*handler)(int, void *), int next, void *arg);
int RemoveDmacHandler(int chan, int hid);
int func_003B0810(int cause);   /* EnableDmac */
int func_003B07A8(int cause);   /* DisableDmac */

/* A thread's parameters, as ReferThreadStatus fills them in. */
struct ThreadParam {
    int status;                 /* 0x00 */
    void *entry;                /* 0x04 */
    void *stack;                /* 0x08 */
    int stackSize;              /* 0x0C */
    void *gpReg;                /* 0x10 */
    int initPriority;           /* 0x14 */
    int currentPriority;        /* 0x18 */
    unsigned int attr;          /* 0x1C */
    unsigned int option;        /* 0x20 */
    int waitType;               /* 0x24 */
    int waitId;                 /* 0x28 */
    int wakeupCount;            /* 0x2C */
};                              /* 0x30 */

int GetThreadId(void);
int ReferThreadStatus(int tid, struct ThreadParam *info);
/* Returns the thread's previous priority. */
int ChangeThreadPriority(int tid, int prio);

#endif
