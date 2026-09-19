/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: _sceMpegDispatchMpegCallback */
#include <godhand/gp.h>

typedef int (*cbfn)();
typedef struct { cbfn func; void *data; void *gp; } Cb;
typedef struct { int pad[3]; Cb cb[1]; } Ctx;

__attribute__((section(".text.func_0039AB20")))
int func_0039AB20(void *m, int *cb)
{
    int ret = 0;

    if (m != 0) {
        Ctx *c = *(Ctx **)((char *)m + 0x40);
        if (c != 0) {
            cbfn fn = c->cb[cb[0]].func;
            if (fn != 0) {
                void *oldgp = SetGp(c->cb[cb[0]].gp);
                ret = fn(m, cb, c->cb[cb[0]].data);
                SetGp(oldgp);
            }
        }
    }
    return ret;
}
