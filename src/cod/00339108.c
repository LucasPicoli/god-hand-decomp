/* cygnus-2.96: func_00339108, releases a non-empty chunk back to the stream and notifies its callback with -3. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern int func_00338A48(void *a0, void *a1);
extern char D_00455920[];
extern char D_00455950[];

__attribute__((section(".text.func_00339108")))
void func_00339108(SjMem *sj, int id, SjChunk *ck)
{
    void (*cb)(void *obj, int ev);

    if (sj == 0) {
        func_00338A48(D_004559F0, D_00455920);
        return;
    }
    if (sj->used == 0) {
        func_00338A48(D_00455A00, D_00455950);
        return;
    }
    if (ck->len > 0 && ck->data != 0 && id != 0 && id != 1) {
        cb = sj->cb;
        ck->len = 0;
        ck->data = 0;
        if (cb != 0)
            cb(sj->cbobj, -3);
    }
}
