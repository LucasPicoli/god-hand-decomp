/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: _sceMpegDispatchMpegCbNodata */
#include <godhand/gp.h>

struct cbp { int reason; int pad[7]; };
typedef int (*cbfn)();

__attribute__((section(".text.func_0039AB98")))
int func_0039AB98(void *m)
{
    struct cbp cb;

    cb.reason = 1;
    if (m != 0) {
        char *base = *(char **)((char *)m + 0x40);
        if (base != 0) {
            cbfn fn = *(cbfn *)(base + cb.reason * 12 + 12);
            if (fn != 0) {
                void *oldgp = SetGp(*(void **)(base + cb.reason * 12 + 20));
                fn(m, &cb, *(void **)(base + cb.reason * 12 + 16));
                SetGp(oldgp);
            }
        }
    }
    return 1;
}
