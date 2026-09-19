/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: sceMpegAddCallback */
#include <godhand/gp.h>

typedef int (*cbfn)();
typedef struct { cbfn func; void *data; void *gp; } Cb;
typedef struct { int pad[3]; Cb cb[1]; } Ctx;

__attribute__((section(".text.func_0039AAD8")))
cbfn func_0039AAD8(void *m, int cbid, cbfn func, void *data)
{
    Ctx *c = *(Ctx **)((char *)m + 0x40);
    cbfn old;

    old = c->cb[cbid].func;
    c->cb[cbid].func = func;
    c->cb[cbid].data = data;
    c->cb[cbid].gp = GetGp();
    return old;
}

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: _decodeOrSkip */



__attribute__((section(".text.func_0039AC10")))
int func_0039AC10(void *m, int p2, int p3)
{
    char *ctx = *(char **)((char *)m + 0x40);

    if (*(int *)(ctx + 0x184) != 3)
        return func_0039A720(m, p2, p3);
    return func_0039A5B0(m, p2, p3);
}
