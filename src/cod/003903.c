/* newlib mprec ratio (TU 003903, ee-gcc 2.9-991111-01).  Ratio of two
 * bignums as a double: convert each via b2d, fold the word-count and per-call
 * shift differences into the larger operand's binary exponent, then divide
 * (dpdiv is the soft-float double divide the `/` operator emits). */

typedef struct _Bigint {
    struct _Bigint *_next;   /* 0x00 */
    int _k;                  /* 0x04 */
    int _maxwds;             /* 0x08 */
    int _sign;               /* 0x0C */
    int _wds;                /* 0x10 */
    unsigned int _x[1];      /* 0x14 */
} _Bigint;

typedef union { double d; unsigned int i[2]; } U;  /* i[1]=word0 (high) */

extern double b2d(_Bigint *a, int *e);
extern double dpdiv(double a, double b);   /* __divdf3 */

__attribute__((section(".text.ratio")))
double ratio(_Bigint *a, _Bigint *b)
{
    double da, db;
    int k, ka, kb;

    da = b2d(a, &ka);
    db = b2d(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0) {
        U u;
        u.d = da;
        u.i[1] += k << 20;
        da = u.d;
    } else {
        U v;
        k = -k;
        v.d = db;
        v.i[1] += k << 20;
        db = v.d;
    }
    return da / db;
}
