/* sn-2.95.3-136 matched TU. */

/* newlib mprec __d2b (0x003AF570).  Double -> bignum. */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

typedef union { double d; unsigned int i[2]; } U;

extern _Bigint *func_003AE818(void *ptr, int k);  /* _Balloc   */
extern int func_003AEBC0(unsigned int *y);        /* __lo0bits */
extern int func_003AEB38(unsigned int x);         /* __hi0bits */

#define Frac_mask 0xfffff
#define Exp_msk1  0x100000
#define Exp_shift 20
#define Bias      0x3ff
#define P         53

__attribute__((section(".text.func_003AF570")))
_Bigint *func_003AF570(void *ptr, double _d, int *e, int *bits)
{
    _Bigint *b;
    int de, k, i;
    unsigned int *x, y, z;
    U d;

    d.d = _d;
    b = func_003AE818(ptr, 1);
    x = b->_x;
    z = d.i[1] & Frac_mask;
    d.i[1] &= 0x7fffffff;
    if ((de = (int)(d.i[1] >> Exp_shift)) != 0) {
        z |= Exp_msk1;
    }
    if ((y = d.i[0]) != 0) {
        if ((k = func_003AEBC0(&y)) != 0) {
            x[0] = y | (z << (32 - k));
            z >>= k;
        } else {
            x[0] = y;
        }
        i = b->_wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_003AEBC0(&z);
        x[0] = z;
        i = b->_wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - Bias - (P - 1) + k;
        *bits = P - k;
    } else {
        *e = de - Bias - (P - 1) + 1 + k;
        *bits = 32 * i - func_003AEB38(x[i - 1]);
    }
    return b;
}
