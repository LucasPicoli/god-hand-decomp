/* sn-2.95.3-136. The do-while(0) block boundary pins the s0/s1 allocation
 * to retail (found via decomp-permuter). */
#include "godhand/cScenario.h"

extern int cTaskManager_execute(cTaskManager *task, void *entry, int slot);

__attribute__((section(".text.cScenario_taskExec_2C3890")))
/* Start entry as a script task in `slot`; returns its index or -1. */
int cScenario_taskExec_2C3890(cScenario *self, void *entry, int slot) {
    int no = cTaskManager_execute(&self->task, entry, slot);
    do {
        cScenario_clearTaskData(self, no);
        return no;
    } while (0);
}
