/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"

/* ee-2.9-991111 — SCE libmpeg 3.0.2, error.o :: _sceMpegErrorBdec */

typedef unsigned int u_int;

extern char D_0045E610[];                     /* the error message */
extern void _sceMpegError(void *m, const char *msg);
struct cbp { int reason; int pad[7]; };
extern int  func_0039AB20(void *p, struct cbp *q);       /* _sceMpegDispatchMpegCallback */

__attribute__((section(".text._sceMpegErrorBdec")))
void _sceMpegErrorBdec(void *m)
{
    struct cbp cb;
    int oldstat;

    _sceMpegError(m, D_0045E610);
    cb.reason = 2;
    func_0039AB20(*(void **)((char *)m + 0x868), &cb);
    *(volatile u_int *)0x10002010 = 0x40000000;
    cb.reason = 3;
    func_0039AB20(*(void **)((char *)m + 0x868), &cb);
    oldstat = DIntr();
    *(volatile u_int *)0x1000F590 = *(volatile u_int *)0x1000F520 | 0x10000;
    *(volatile u_int *)0x1000B000 = 0;
    *(volatile u_int *)0x1000F590 = *(volatile u_int *)0x1000F520 & 0xFFFEFFFF;
    if (oldstat)
        EIntr();
    *(volatile u_int *)0x1000B020 = 0;
}
