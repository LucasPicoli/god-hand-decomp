/* cygnus-2.96: SJ ring buffer GetChunk: take up to nbyte contiguous bytes from lane 0 (free) or lane 1
 * (data) and advance that lane; other lanes report -3 through the error callback. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern char D_00455A80[];
extern char D_00455AB0[];
extern void func_00339458(const char *msg, const char *fn);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

__attribute__((section(".text.func_003398F8")))
void func_003398F8(SjRbf *sj, int id, int nbyte, SjChunk *ck)
{
    if (sj == 0) {
        func_00339458(D_00455AF0, D_00455A80);
        return;
    }
    if (sj->used == 0) {
        func_00339458(D_00455B00, D_00455AB0);
        return;
    }
    if (sj->size == 0) {
        func_00339458(D_00455B10, D_00455B20);
        return;
    }
    if (id == 0) {
        ck->len = MIN(MIN(sj->free, sj->size - sj->freePos + sj->extra), nbyte);
        ck->data = sj->buf + sj->freePos;
        sj->freePos = (sj->freePos + ck->len) % sj->size;
        sj->free -= ck->len;
        sj->freeTaken += ck->len;
    } else if (id == 1) {
        ck->len = MIN(MIN(sj->data, sj->size - sj->dataPos + sj->extra), nbyte);
        ck->data = sj->buf + sj->dataPos;
        sj->dataPos = (sj->dataPos + ck->len) % sj->size;
        sj->data -= ck->len;
        sj->dataTaken += ck->len;
    } else {
        ck->len = 0;
        ck->data = 0;
        if (sj->err != 0)
            sj->err(sj->errObj, -3);
    }
}
