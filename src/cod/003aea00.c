/* sn-2.95.3-136 matched TU. */

/* newlib mprec __s2b (0x003AEA00). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

extern _Bigint *func_003AE818(void *ptr, int k);                        /* _Balloc  */
extern _Bigint *func_003AE8F8(void *ptr, _Bigint *b, int m, int a);     /* __multadd */

__attribute__((section(".text.func_003AEA00")))
_Bigint *func_003AEA00(void *ptr, const char *s, int nd0, int nd, unsigned int y9)
{
    _Bigint *b;
    int i, k;
    int x, y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++);
    b = func_003AE818(ptr, k);
    b->_x[0] = y9;
    b->_wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do {
            b = func_003AE8F8(ptr, b, 10, *s++ - '0');
        } while (++i < nd0);
        s++;
    } else {
        s += 10;
    }
    for (; i < nd; i++) {
        b = func_003AE8F8(ptr, b, 10, *s++ - '0');
    }
    return b;
}
