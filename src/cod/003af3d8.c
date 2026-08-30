/* sn-2.95.3-136 matched TU. */

/* newlib mprec _b2d (0x003AF3D8).  Bignum -> double. */

typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

typedef union { double d; unsigned int i[2]; } U;

extern int func_003AEB38(unsigned int);   /* __hi0bits */

#define Ebits 11
#define Exp_1 0x3ff00000

__attribute__((section(".text.func_003AF3D8")))
double func_003AF3D8(_Bigint *a, int *e)
{
    unsigned int *xa, *xa0, w, y, z;
    int k;
    U d;

    xa0 = a->_x;
    xa = xa0 + a->_wds;
    y = *--xa;
    k = func_003AEB38(y);
    *e = 32 - k;
    if (k < Ebits) {
        d.i[1] = Exp_1 | (y >> (Ebits - k));
        w = xa > xa0 ? *--xa : 0;
        d.i[0] = (y << (32 - Ebits + k)) | (w >> (Ebits - k));
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= Ebits) {
        d.i[1] = Exp_1 | (y << k) | (z >> (32 - k));
        y = xa > xa0 ? *--xa : 0;
        d.i[0] = (z << k) | (y >> (32 - k));
    } else {
        d.i[1] = Exp_1 | y;
        d.i[0] = z;
    }
ret_d:
    return d.d;
}
