/* ee-2.9-991111 matched TU. */

extern float D_0045EB40;

/* newlib fdlibm ef_log.c -- __ieee754_logf
 *
 * LANE X1 repair, wave 18.
 * CAUSE 1: `typedef union {...} ieee_float_shape_type;` collides with the same
 *          typedef in func_003A1648 when _rehome merges both into one TU
 *          ("conflicting types for `ieee_float_shape_type'", cc1 exit 33).
 * REPAIR 1: the typedef and both macros carry a per-function suffix.
 * CAUSE 2: the `static const float` objects emitted a 0x2C B TU-local .rodata
 *          that NOTHING references -- retail folds every one of them into a
 *          `lui`+`mtc1` immediate. A carved TU must emit an EMPTY .rodata;
 *          the dead pool shifts every later section and the ELF sha256 gate
 *          fails. score_candidate compares .text.<name> ONLY, so the pool was
 *          INVISIBLE to it.
 * REPAIR 2: every constant becomes a macro, so cc1 emits no object at all.
 *          The TU now emits NO .rodata. */



#define ln2_hi 6.9313812256e-01f
#define ln2_lo 9.0580006145e-06f
#define two25 3.355443200e+07f
#define Lg1 6.6666668653e-01f
#define Lg2 4.0000000596e-01f
#define Lg3 2.8571429849e-01f
#define Lg4 2.2222198546e-01f
#define Lg5 1.8183572590e-01f
#define Lg6 1.5313838422e-01f
#define Lg7 1.4798198640e-01f
#define zero 0.0f

typedef union {
    float value;
    unsigned int word;
} ieee_float_shape_type_3A2BB0;

#define GET_FLOAT_WORD_3A2BB0(i, d)        \
    do {                            \
        ieee_float_shape_type_3A2BB0 gf_u; \
        gf_u.value = (d);           \
        (i) = gf_u.word;            \
    } while (0)

#define SET_FLOAT_WORD_3A2BB0(d, i)        \
    do {                            \
        ieee_float_shape_type_3A2BB0 sf_u; \
        sf_u.word = (i);            \
        (d) = sf_u.value;           \
    } while (0)

__attribute__((section(".text.func_003A2BB0")))
float func_003A2BB0(float x) {
    float hfsq, f, s, z, R, w, t1, t2, dk;
    int k, ix, i, j;

    GET_FLOAT_WORD_3A2BB0(ix, x);

    k = 0;
    if (ix < 0x00800000) {
        if ((ix & 0x7FFFFFFF) == 0) return D_0045EB40;
        if (ix < 0) return (x - x) / zero;
        k -= 25;
        x *= two25;
        GET_FLOAT_WORD_3A2BB0(ix, x);
    }
    if (ix >= 0x7F800000) return x + x;
    k += (ix >> 23) - 127;
    ix &= 0x007FFFFF;
    i = (ix + (0x95F64 << 3)) & 0x800000;
    SET_FLOAT_WORD_3A2BB0(x, ix | (i ^ 0x3F800000));
    k += (i >> 23);
    f = x - (float)1.0;
    if ((0x007FFFFF & (15 + ix)) < 16) {
        if (f == zero) {
            if (k == 0) return zero;
            dk = (float)k;
            return dk * ln2_hi + dk * ln2_lo;
        }
        R = f * f * ((float)0.5 - (float)0.33333333333333333 * f);
        if (k == 0) return f - R;
        dk = (float)k;
        return dk * ln2_hi - ((R - dk * ln2_lo) - f);
    }
    s = f / ((float)2.0 + f);
    dk = (float)k;
    z = s * s;
    i = ix - (0x6147A << 3);
    w = z * z;
    j = (0x6B851 << 3) - ix;
    t1 = w * (Lg2 + w * (Lg4 + w * Lg6));
    t2 = z * (Lg1 + w * (Lg3 + w * (Lg5 + w * Lg7)));
    i |= j;
    R = t2 + t1;
    if (i > 0) {
        hfsq = (float)0.5 * f * f;
        if (k == 0) return f - (hfsq - s * (hfsq + R));
        return dk * ln2_hi - ((hfsq - (s * (hfsq + R) + dk * ln2_lo)) - f);
    } else {
        if (k == 0) return f - (s * (f - R));
        return dk * ln2_hi - ((s * (f - R) - dk * ln2_lo) - f);
    }
}
