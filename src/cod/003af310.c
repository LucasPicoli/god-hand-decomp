/* sn-2.95.3-136 matched TU. */

/* newlib mprec _ulp (0x003AF310). */
typedef union { double d; unsigned int i[2]; } U;

#define Exp_mask  0x7ff00000
#define Exp_msk1  0x100000
#define Exp_shift 20
#define P         53

__attribute__((section(".text.func_003AF310")))
double func_003AF310(double _x)
{
    int L;
    U x, a;

    x.d = _x;
    L = (x.i[1] & Exp_mask) - (P - 1) * Exp_msk1;
    if (L > 0) {
        a.i[1] = L;
        a.i[0] = 0;
    } else {
        L = -L >> Exp_shift;
        if (L < Exp_shift) {
            a.i[1] = 0x80000 >> L;
            a.i[0] = 0;
        } else {
            a.i[1] = 0;
            L -= Exp_shift;
            a.i[0] = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    return a.d;
}
