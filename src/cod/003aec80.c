/* sn-2.95.3-136 matched TU. */

/* newlib mprec __i2b (0x003AEC80). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

extern _Bigint *func_003AE818(void *ptr, int k);   /* _Balloc */

__attribute__((section(".text.func_003AEC80")))
_Bigint *func_003AEC80(void *ptr, int i)
{
    _Bigint *b;

    b = func_003AE818(ptr, 1);
    b->_x[0] = i;
    b->_wds = 1;
    return b;
}
