/* include/godhand/cTaskWork.h - cTaskWork, one task thread owned by cTaskManager.
 *
 * A cTaskWork wraps an EE kernel thread. tid is -1 while no thread exists.
 * owner points at the manager record; word 10 of it is the semaphore that
 * cTaskWork_exit signals. Offsets are exact; every body that uses this
 * header builds byte-identical to retail.
 */
#ifndef GODHAND_CTASKWORK_H
#define GODHAND_CTASKWORK_H

#define TASKWORK_NO_THREAD  (-1)
#define TASKWORK_SEMA_WORD  10      /* index of the semaphore in *owner */

typedef struct cTaskWork {
    int *owner;                 /* 0x00 manager record */
    int tid;                    /* 0x04 kernel thread id, -1 when none */
    int unk08;
    unsigned short running;     /* 0x0C nonzero while the task is alive */
} cTaskWork;

#endif
