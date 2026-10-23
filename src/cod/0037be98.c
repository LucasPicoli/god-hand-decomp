/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

extern int func_0037BF10(char *h);

/* Runs every queued sound request (a stop or a start) and frees its slot. */
__attribute__((section(".text.func_0037BE98")))
void func_0037BE98(void)
{
    SeqCmd *c;
    int i;

    for (i = 0; i < SEQCMD_NUM; i++) {
        c = &D_0076B9C0[i];
        if (c->used != 0) {
            if (c->flags & SEQCMD_F_STOP) {
                func_0037C330(c);
            } else {
                func_0037BF10((char *)c);
            }
            c->used = 0;
        }
    }
}
