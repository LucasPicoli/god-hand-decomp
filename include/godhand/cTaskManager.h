/* include/godhand/cTaskManager.h - cTaskManager, the pool of task threads.
 *
 * works points at an array of 0x58-byte task records (cTaskWork). The
 * manager asks its virtual allocator (entry 2 of the table at 0x30, a g++
 * 2.x delta/index/pfn entry) for a free record index, starts the task in
 * it, then calls func_002D5440 to finish the bookkeeping. -1 means the pool
 * is full. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CTASKMANAGER_H
#define GODHAND_CTASKMANAGER_H

#define TASKMGR_WORK_SIZE   0x58
#define TASKMGR_NONE        (-1)

typedef struct cTaskManagerVt {
    char unk00[0x10];
    short allocDelta;           /* 0x10 this adjustment for allocSlot */
    short allocIndex;           /* 0x12 */
    int (*allocSlot)(void *self, int arg);  /* 0x14 returns a free index or -1 */
} cTaskManagerVt;

typedef struct cTaskManager {
    char *works;                /* 0x00 array of TASKMGR_WORK_SIZE records */
    struct cTaskWork *cur;      /* 0x04 the record of the running task */
    int curNo;                  /* 0x08 its index, TASKMGR_NONE when idle */
    char unk0C[0x20];
    int flags;                  /* 0x2C set at init; the owner keeps its own bits here */
    cTaskManagerVt *vt;         /* 0x30 */
} cTaskManager;                 /* 0x34 */

#endif
