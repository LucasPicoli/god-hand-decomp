/* newlib mprec — Bfree / Bcopy / Brealloc (TU 0038f5, ee-gcc 2.9-991111-01).
 * Shares one _Bigint fiction with field widths chosen to reproduce retail's
 * exact load/store widths (Bfree guards on a signed short @0xC; Bcopy short-
 * copies @0xE and word-copies on the int count @0x10). */

typedef struct _Bigint {
    struct _Bigint *_next;   /* 0x00 */
    int _k;                  /* 0x04 */
    int _maxwds;             /* 0x08 */
    short _sign;             /* 0x0C */
    unsigned short _hi;      /* 0x0E */
    int _wds;                /* 0x10 */
    unsigned int _x[1];      /* 0x14 */
} _Bigint;

extern void *func_003A7C70(unsigned int);             /* malloc */
extern void  UpdateGlobalPtrWithParam_3A7CC0(void *); /* free   */
extern _Bigint *Balloc(int k);

__attribute__((section(".text.Bfree_38F548")))
void Bfree_38F548(_Bigint *v) {
    if (v && !v->_sign)
        UpdateGlobalPtrWithParam_3A7CC0(v);
}

__attribute__((section(".text.Bcopy")))
void Bcopy(_Bigint *c, _Bigint *b) {
    unsigned int *dst = c->_x;
    unsigned int *src = b->_x;
    int i = b->_wds;
    c->_wds = i;
    c->_hi = b->_hi;
    for (--i; i >= 0; --i)
        *dst++ = *src++;
}

__attribute__((section(".text.Brealloc")))
_Bigint *Brealloc(_Bigint *b, int k) {
    _Bigint *rv;
    if (!b)
        return Balloc(k);
    if (b->_k >= k)
        return b;
    rv = Balloc(k);
    Bcopy(rv, b);
    Bfree_38F548(b);
    return rv;
}
