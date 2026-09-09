/* cygnus-2.96 matched TU. */

typedef struct Adxt { void *hn; char pad4[0x20]; int f24; int f28; } Adxt;
typedef struct Sfd { char pad0[0x48]; int f48; char pad4c[0x1020-0x4C]; char tst[0x2004-0x1020]; Adxt *adxt; } Sfd;

extern void sfadxt_GetTimeTst(void *tst, void *hn, int *tim, int *tunit);
__attribute__((section(".text.func_0034B030")))
int func_0034B030(Sfd *sfd, int *tmr, int *tunit)
{
    int tim, tu;
    Adxt *ax;
    void *hn;
    void *tst;

    ax = sfd->adxt;
    hn = ax->hn;
    tst = sfd->tst;
    if (func_0035AE18(sfd) == 0) return 0;
    if (sfd->f48 == 4) {
        sfadxt_GetTimeTst(tst, hn, &tim, &tu);
        if (ax->f24 < tim) { ax->f24 = tim; ax->f28 = tu; }
    }
    *tmr = ax->f24;
    *tunit = ax->f28;
    return 0;
}
