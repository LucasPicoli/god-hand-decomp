/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct SfMpv SfMpv;

__attribute__((section(".text.sfmpv_IsTerm")))
int sfmpv_IsTerm(SfMpv *p, int n, int code)
{
    if (code == 0x80) return 1;
    if (n < 5) {
        if (func_00351C00(p) == 1) return 1;
    }
    return 0;
}
