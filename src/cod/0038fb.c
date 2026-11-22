/* newlib mprec pow5mult (TU 0038fb, ee-gcc 2.9-991111-01).  Multiplies the
 * bignum b by 5^k using multadd: 5^6 (15625) per loop step, then the residual
 * 5^(k mod) from the powers-of-five table D_003F5160 = {5,25,125,625,3125,15625}. */
#include "godhand/globals.h"

typedef struct _Bigint {
    struct _Bigint *_next; int _k; int _maxwds; int _sign; int _wds;
    unsigned int _x[1];
} _Bigint;

extern _Bigint *multadd(_Bigint *b, int m, int a);

__attribute__((section(".text.pow5mult")))
_Bigint *pow5mult(_Bigint *b, int k) {
    while (k >= 7) {
        b = multadd(b, 15625, 0);
        k -= 6;
    }
    if (!k)
        return b;
    b = multadd(b, D_003F5160[k - 1], 0);
    return b;
}
