/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef int (*TrFn)(int, int, int, int);
typedef struct TrTbl { int w[15]; } TrTbl;

extern int sftrn_CallTrEntry(TrTbl *tbl, int idx);

__attribute__((section(".text.SFTRN_Init")))
int SFTRN_Init(TrTbl *dst, TrTbl *src)
{
    *dst = *src;
    return sftrn_CallTrEntry(src, 0);
}
