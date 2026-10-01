/* TU: cTaskWork [system] - recovered C++ class. */
#include "godhand/cTaskWork.h"
struct s_002D5A48 {
    int *field_0;
    int field_4;
    int pad_8;
    short field_C;
};
extern int ChangeThreadPriority(int tid, int prio);
extern int SignalSema(int sema);
extern void ExitDeleteThread(void);

/* Called by the task itself: mark it stopped, wake the manager and leave the thread. */
__attribute__((section(".text.cTaskWork_exit")))
void cTaskWork_exit(cTaskWork *self)
{
    self->running = 0;
    if (self->tid != TASKWORK_NO_THREAD) {
        ChangeThreadPriority(self->tid, 1);
        SignalSema(self->owner[TASKWORK_SEMA_WORD]);
        self->tid = TASKWORK_NO_THREAD;
        ExitDeleteThread();
    }
}
