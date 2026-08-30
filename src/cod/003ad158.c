/* sn-2.95.3-136 matched TU. */

/* newlib s_floor.c -- floor (0x003AD158). */

typedef union { double value; unsigned int i[2]; } U;

#define EXTRACT_WORDS(ix0, ix1, d)                                      \
    do { U ew_u; ew_u.value = (d); (ix0) = ew_u.i[1]; (ix1) = ew_u.i[0]; } while (0)

#define INSERT_WORDS(d, ix0, ix1)                                       \
    do { U iw_u; iw_u.i[1] = (ix0); iw_u.i[0] = (ix1); (d) = iw_u.value; } while (0)

extern const double D_0045FBE8;         /* huge = 1.0e300 */

__attribute__((section(".text.func_003AD158")))
double func_003AD158(double x)
{
    int i0, i1, j0;
    unsigned int i, j;

    EXTRACT_WORDS(i0, i1, x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {                   /* raise inexact if x != 0 */
            if (x + D_0045FBE8 > 0.0) { /* return 0*sign(x) if |x|<1 */
                if (i0 >= 0) { i0 = i1 = 0; }
                else if (((i0 & 0x7fffffff) | i1) != 0) { i0 = 0xbff00000; i1 = 0; }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) return x;  /* x is integral */
            if (x + D_0045FBE8 > 0.0) { /* raise inexact flag */
                if (i0 < 0) i0 += (0x00100000) >> j0;
                i0 &= (~i); i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) return x + x;  /* inf or NaN */
        else return x;                  /* x is integral */
    } else {
        i = ((unsigned int)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) return x;    /* x is integral */
        if (x + D_0045FBE8 > 0.0) {     /* raise inexact flag */
            if (i0 < 0) {
                if (j0 == 20) i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < (unsigned int)i1) i0 += 1;  /* got a carry */
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    INSERT_WORDS(x, i0, i1);
    return x;
}
