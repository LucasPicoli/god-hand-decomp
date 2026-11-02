/* sn-2.95.3-136 */
#include "godhand/cIDManager.h"

/* Cut the job queue back to its leading tag-1 jobs and count the pool
 * buffers they hold. Returns 0 (nothing changed) when the pool is empty or a
 * tag-1 job comes after a job of another tag. */
__attribute__((section(".text.func_002AD108")))
int func_002AD108(cIDManager *self)
{
    unsigned int i;
    int last;
    unsigned char flags;
    int used;

    if (self->poolUsed == 0)
        return 0;
    last = 0;
    flags = 0;
    used = 0;
    for (i = 0; i < self->jobNum; i++) {
        if (self->job[i].tag == 1) {
            last = i;
            used += self->job[i].bufNum;
            if (flags & 1)
                flags |= 2;
        } else {
            flags |= 1;
        }
    }
    if ((flags & 3) == 3)
        return 0;
    self->jobNum = last + 1;
    self->poolUsed = used;
    return 1;
}
