/* sn-2.95.3-136 matched TU. */

/* Enter the scripted sequence: set its state, start a soft event, run the sequence task for this object and flag the task's work record as a soft-event task. */
#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"

typedef struct cOmScripted {
    cOmBase base;
    char unk5E0[0x24];
    unsigned char seqState;             /* 0x604 */
} cOmScripted;

#define OMSCRIPTED_SEQ_RUN  5

extern void func_001A6AF8(cOmScripted *self);

__attribute__((section(".text.cOmScripted_startSeq")))
void cOmScripted_startSeq(cOmScripted *self)
{
    int no;
    char *works;
    self->seqState = OMSCRIPTED_SEQ_RUN;
    cScenario_startSoftEvent(D_003C2F84, 0);
    no = cScenario_taskExec(D_003C2F84, (void *)func_001A6AF8, self, 1);
    works = D_003C2F84->task.works;     /* dead store: the unused read changes retail's register choice */
    if (no >= 0) {
        cTaskWork *e = (cTaskWork *)(no * TASKMGR_WORK_SIZE + (int)D_003C2F84->task.works);
        e->attr = e->attr | SCENARIO_TASK_SOFT_EVENT;
    }
}
