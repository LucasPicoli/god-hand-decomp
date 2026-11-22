/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

/* Runs every queued sound request (a stop or a start) and frees its slot. */
__attribute__((section(".text.SdeVoiceExecute")))
void SdeVoiceExecute(void)
{
    SeqCmd *c;
    int i;

    for (i = 0; i < SEQCMD_NUM; i++) {
        c = &D_0076B9C0[i];
        if (c->used != 0) {
            if (c->flags & SEQCMD_F_STOP) {
                vexeCmdExec(c);
            } else {
                func_0037BF10(c);
            }
            c->used = 0;
        }
    }
}
