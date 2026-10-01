/* sn-2.95.3-136 matched TU. */

#include "godhand/cTaskWork.h"
#include "godhand/cTaskManager.h"

extern int TerminateThread(int tid);
extern int DeleteThread(int tid);
extern void func_002D58B8(void *work, void *entry, int arg);
extern void func_002D5440(cTaskManager *self, int index);

/* Stop the task: clear running, then terminate and delete its thread. */
__attribute__((section(".text.cTaskWork_kill")))
void cTaskWork_kill(cTaskWork *self)
{
    if (self->running != 0) {
        int tid = self->tid;
        self->running = 0;
        if (tid != TASKWORK_NO_THREAD) {
            TerminateThread(tid);
            DeleteThread(self->tid);
            self->tid = TASKWORK_NO_THREAD;
        }
    }
}

/* Take a free task record, start entry(arg) in it, and return its index (-1 if full). */
__attribute__((section(".text.cTaskManager_execute_2D54F0")))
int cTaskManager_execute_2D54F0(cTaskManager *self, void *entry, int arg, int allocArg)
{
    int index = self->vt->allocSlot((char *)self + self->vt->allocDelta, allocArg);
    if (index != TASKMGR_NONE) {
        func_002D58B8(self->works + index * TASKMGR_WORK_SIZE, entry, arg);
    }
    func_002D5440(self, index);
    return index;
}
