/* sn-2.95.3-136: func_00374210, size and allocate a sound stream's buffer, then create its handle. */
#include "godhand/heapArena.h"

#include "godhand/sndStream.h"

extern void *func_0031C8E0(int size, int align, void *heap);
extern void func_0031C928(void *block, void *heap);
extern int func_0032D340(int a0, int a1, int a2, int a3);

/* Size the buffer for sec + 1 seconds of nch channels at rate plus n per-channel headers,
 * allocate it from the sound arena and create the stream handle on it. Returns 1 on
 * success; on failure frees the buffer and returns 0. */
__attribute__((section(".text.func_00374210")))
int func_00374210(SndStream *s, int rate, int sec, int n)
{
    int sz;
    int hdr;
    int bps;

    bps = rate / 1000 * 25000;
    hdr = s->nch * 0x40C0 + 0x24;
    sz = s->nch * bps / 44 * (sec + 1);
    sz = (sz + 0x800) / 0x800 * 0x800;
    s->size = (sz + hdr) * n + 0x40;
    s->buf = func_0031C8E0(s->size, 0x40, &D_00754210);
    if (s->buf != 0) {
        s->handle = (void *)func_0032D340(n, s->nch, (int)s->buf, s->size);
        if (s->handle != 0) {
            return 1;
        }
        func_0031C928(s->buf, &D_00754210);
        s->buf = 0;
    }
    return 0;
}
