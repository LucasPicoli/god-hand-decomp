/* ee-2.9-991111 matched TU. */

typedef struct _Bigint {
    struct _Bigint *_next; int _k; int _maxwds; int _sign; int _wds;
    unsigned int _x[1];
} _Bigint;

__attribute__((section(".text.func_003AF118")))
int func_003AF118(_Bigint *a, _Bigint *b)
{
    unsigned int *xa;
    unsigned int *xa0;
    unsigned int *xb;
    unsigned int *xb0;
    int i;
    int j;

    i = a->_wds;
    j = b->_wds;
    if (i -= j) {
        return i;
    }
    xa0 = a->_x;
    xa = xa0 + j;
    xb0 = b->_x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb) {
            return *xa < *xb ? -1 : 1;
        }
        if (xa <= xa0) {
            break;
        }
    }
    return 0;
}
