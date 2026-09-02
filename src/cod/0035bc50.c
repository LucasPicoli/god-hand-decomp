/* cygnus-2.96 matched TU. */

typedef int (*TrFn)(int, int, int, int);
__attribute__((section(".text.sftrn_CallTrEntry")))
int sftrn_CallTrEntry(TrFn **tbl, int idx)
{
    int i;
    int r = 0;

    for (i = 0; i < 15; i++) {
        TrFn *e = *tbl++;
        if (e == 0) break;
        r = e[idx](0, 0, 0, 0);
        if (r != 0) break;
    }
    return r;
}
