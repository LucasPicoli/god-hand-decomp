/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — donor sce302_libsdr/sdr_main.o :: sceSdRemote */
#include "godhand/gp.h"

typedef unsigned int   u_int;
typedef unsigned short u_short;



extern u_int D_0077C8C0[];   /* transData            */
extern char  D_0077C900[];   /* sbuff (client data)  */
extern void *D_003FA300;     /* sceSdEndFunc         */
extern void *D_003FA304;     /* sceSdEndGp           */
extern char  D_003FA308[];   /* +0x10 = _sce_sdr_transIntr0Hdr */
extern void *D_003FA31C;     /* _sce_sdr_transIntr1Hdr */
extern void *D_003FA320;     /* _sce_sdr_spu2IntrHdr   */
extern void *D_003FA324;     /* _sce_sdr_transIntr0Arg */
extern void *D_003FA328;     /* _sce_sdr_transIntr1Arg */
extern void *D_003FA32C;     /* _sce_sdr_spu2IntrArg   */
extern void *D_003FA330;     /* _sce_sdr_transIntr0Gp  */
extern void *D_003FA334;     /* _sce_sdr_transIntr1Gp  */
extern void *D_003FA338;     /* _sce_sdr_spu2IntrGp    */

__attribute__((section(".text.sceSdRemote")))
int sceSdRemote(int arg, ...)
{
    char *ap;
    u_int *p;
    u_int cmd;
    u_int mode;
    int i;
    int ret;
    void *endfunc;
    void *oldgp;
    void *old;
    char *batch;
    void *rbuf;
    int rsize;

    endfunc = 0;
    oldgp = 0;
    D_0077C8C0[0] = (u_int)D_0077C8C0;
    ap = (char *)__builtin_next_arg(arg) - 0x38;
    ap += 8;
    cmd = *(u_int *)(ap - 8);
    p = &D_0077C8C0[1];
    for (i = 5; i >= 0; i--) {
        ap += 8;
        *p++ = *(u_int *)(ap - 8);
    }
    mode = 0;
    if (arg == 0) {
        mode = 1;
        endfunc = D_003FA300;
    }
    old = 0;
    if (cmd == 0x8160) {
        if (D_0077C8C0[1] == 0) {
            old = *(void **)(D_003FA308 + 0x10);
            *(void **)(D_003FA308 + 0x10) = (void *)D_0077C8C0[2];
            D_003FA324 = (void *)D_0077C8C0[3];
            D_003FA330 = GetGp();
        } else {
            old = D_003FA31C;
            D_003FA31C = (void *)D_0077C8C0[2];
            D_003FA328 = (void *)D_0077C8C0[3];
            D_003FA334 = GetGp();
        }
    } else if (cmd == 0x8170) {
        old = D_003FA320;
        D_003FA320 = (void *)D_0077C8C0[1];
        D_003FA32C = (void *)D_0077C8C0[2];
        D_003FA338 = GetGp();
    }
    ret = 0;
    if (cmd == 0x8130 || cmd == 0x81A0 || cmd == 0x81B0) {
        if (endfunc != 0) {
            oldgp = SetGp(D_003FA304);
        }
        func_003B3128(D_0077C900, cmd | D_0077C8C0[1], mode,
                      (void *)D_0077C8C0[2], 0x40, D_0077C8C0, 0x40,
                      endfunc, (void *)D_0077C8C0[0]);
        if (endfunc != 0) {
            SetGp(oldgp);
        }
        ret = (int)D_0077C8C0[0];
    } else if (cmd == 0x8140) {
        if (endfunc != 0) {
            oldgp = SetGp(D_003FA304);
        }
        func_003B3128(D_0077C900, 0x8140 | D_0077C8C0[1], mode,
                      D_0077C8C0, 0x40, (void *)D_0077C8C0[2], 0x40,
                      endfunc, (void *)D_0077C8C0[2]);
        if (endfunc != 0) {
            SetGp(oldgp);
        }
    } else if (cmd == 0x81C0 || cmd == 0x81D0) {
        batch = (char *)D_0077C8C0[1];
        *(u_short *)(batch + 2) = (u_short)D_0077C8C0[2];
        if (cmd == 0x81D0) {
            *(int *)(batch + 4) = (int)D_0077C8C0[5];
        }
        rbuf = (void *)D_0077C8C0[3];
        rsize = (int)D_0077C8C0[4];
        if (rbuf == 0) {
            rbuf = &ret;
            rsize = 4;
        }
        if (endfunc != 0) {
            oldgp = SetGp(D_003FA304);
        }
        func_003B3128(D_0077C900, cmd, mode,
                      (void *)D_0077C8C0[1], (D_0077C8C0[2] + 1) * 8,
                      rbuf, rsize, endfunc, D_0077C8C0);
        if (endfunc != 0) {
            SetGp(oldgp);
        }
        if (D_0077C8C0[3] != 0) {
            ret = *(int *)D_0077C8C0[3];
        }
    } else if (cmd - 0x9000 <= 0xF0) {
        if (endfunc != 0) {
            oldgp = SetGp(D_003FA304);
        }
        func_003B3128(D_0077C900, cmd, mode,
                      (void *)D_0077C8C0[1], (int)D_0077C8C0[2],
                      D_0077C8C0, 0x10, endfunc, D_0077C8C0);
        if (endfunc != 0) {
            SetGp(oldgp);
        }
        ret = (int)D_0077C8C0[0];
    } else {
        if (endfunc != 0) {
            oldgp = SetGp(D_003FA304);
        }
        func_003B3128(D_0077C900, cmd, mode,
                      D_0077C8C0, 0x40, D_0077C8C0, 0x10,
                      endfunc, D_0077C8C0);
        if (endfunc != 0) {
            SetGp(oldgp);
        }
        ret = (int)D_0077C8C0[0];
    }
    if (cmd == 0x8160 || cmd == 0x8170) {
        ret = (int)old;
    }
    return ret;
}
