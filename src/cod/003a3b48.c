/* ee-2.9-991111 matched TU. */

/* newlib libm ../../../../../src/newlib/libm/math/ef_sqrt.c */

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i, d)                                                   \
    do {                                                                       \
        ieee_float_shape_type gf_u;                                            \
        gf_u.value = (d);                                                      \
        (i) = gf_u.word;                                                       \
    } while (0)

#define SET_FLOAT_WORD(d, i)                                                   \
    do {                                                                       \
        ieee_float_shape_type sf_u;                                            \
        sf_u.word = (i);                                                       \
        (d) = sf_u.value;                                                      \
    } while (0)

__attribute__((section(".text.func_003A3B48")))
float func_003A3B48(float x)
{
    float z;
    __uint32_t r;
    __int32_t ix, s, q, m, t, i;

    GET_FLOAT_WORD(ix, x);

    /* take care of Inf and NaN */
    if ((ix & 0x7f800000) == 0x7f800000) {
        return x * x + x;
    }
    /* take care of zero */
    if (ix <= 0) {
        if ((ix & 0x7fffffff) == 0)
            return x;
        else if (ix < 0)
            return (x - x) / (x - x);
    }
    /* normalize x */
    m = (ix >> 23);
    if (m == 0) {
        for (i = 0; (ix & 0x00800000) == 0; i++)
            ix <<= 1;
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffff) | 0x00800000;
    if (m & 1)
        ix += ix;
    m >>= 1;

    /* generate sqrt(x) bit by bit */
    ix += ix;
    q = s = 0;
    r = 0x01000000;

    while (r != 0) {
        t = s + r;
        if (t <= ix) {
            s = t + r;
            ix -= t;
            q += r;
        }
        ix += ix;
        r >>= 1;
    }

    /* use floating add to find out rounding direction */
    /* one - tiny == 1.0f and one + tiny == 1.0f both fold at compile time,
       so fdlibm's rounding-direction probe reduces to this. */
    if (ix != 0)
        q += (q & 1);
    ix = (q >> 1) + 0x3f000000;
    ix += (m << 23);
    SET_FLOAT_WORD(z, ix);
    return z;
}
