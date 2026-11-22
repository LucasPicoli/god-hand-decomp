/* cygnus-2.96: func_003391F8, puts a data chunk back into the memory stream (lane 1 only); a chunk
 * that is not the one just taken, or any other lane, notifies the callback with -3. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern int func_00338A48(void *a0, void *a1);
extern char D_00455920[];
extern char D_00455950[];

__attribute__((section(".text.func_003391F8")))
void func_003391F8(SjMem *sj, int id, SjChunk *ck)
{
    void (*cb)(void *obj, int ev);
    int n;

    if (sj == 0) {
        func_00338A48(D_00455A10, D_00455920);
        return;
    }
    if (sj->used == 0) {
        func_00338A48(D_00455A20, D_00455950);
        return;
    }
    if (ck->len > 0 && ck->data != 0) {
        if (id == 0)
            goto err;
        if (id == 1) {
            n = sj->readPos - ck->len;
            sj->readPos = n < 0 ? 0 : n;
            n = sj->dataLen + ck->len;
            sj->dataLen = sj->size < n ? sj->size : n;
            if (sj->readPos != ck->data - sj->base) {
            err:
                if (sj->cb != 0)
                    sj->cb(sj->cbobj, -3);
            }
        } else {
            cb = sj->cb;
            ck->len = 0;
            ck->data = 0;
            if (cb != 0)
                cb(sj->cbobj, -3);
        }
    }
}
