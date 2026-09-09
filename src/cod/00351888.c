/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct SfMpv SfMpv;

extern int func_003518D8(SfMpv *p, int n);   /* sfmpv_ConcatSub */
extern void sfmpv_DiscardSec(SfMpv *p, int n);

__attribute__((section(".text.sfmpv_Concat")))
int sfmpv_Concat(SfMpv *p, int n)
{
    if (func_003518D8(p, n) == -1)
        return -1;
    sfmpv_DiscardSec(p, n);
    return 0;
}
