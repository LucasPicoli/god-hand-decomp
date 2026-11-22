/* cygnus-2.96: sjrbf_IsGetChunk, how many of want bytes are available in lane 0 (free) or lane 1 (data)
 * of the ring buffer; any other lane goes to the error callback. Returns 1 when all are. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern int D_00455A80;
extern int D_00455AB0;
extern int func_00339458(void *a0, void *a1);

__attribute__((section(".text.sjrbf_IsGetChunk")))
int sjrbf_IsGetChunk(SjRbf *r, int lane, int want, int *got)
{
    int n, len;

    if (r == 0) {
        func_00339458(&D_00455B88, &D_00455A80);
        return 0;
    }
    if (r->used == 0) {
        func_00339458(&D_00455B98, &D_00455AB0);
        return 0;
    }
    if (lane == 0) {
        n = r->size - r->freePos + r->extra;
        if (r->free < n)
            n = r->free;
        n = n < want ? n : want;
    } else if (lane == 1) {
        n = r->size - r->dataPos + r->extra;
        if (r->data < n)
            n = r->data;
        n = n < want ? n : want;
    } else {
        n = 0;
        if (r->err != 0)
            r->err(r->errObj, -3);
    }
    *got = n;
    return n == want;
}
