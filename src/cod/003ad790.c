/* sn-2.95.3-136 matched TU. */

/* newlib e_log.c -- __ieee754_log (0x003AD790). */

typedef union { double value; unsigned int i[2]; } U;

#define EXTRACT_WORDS(ix0, ix1, d)                                      \
    do { U ew_u; ew_u.value = (d); (ix0) = ew_u.i[1]; (ix1) = ew_u.i[0]; } while (0)

#define GET_HIGH_WORD(ihi, dv)                                          \
    do { U gh_u; gh_u.value = (dv); (ihi) = gh_u.i[1]; } while (0)

#define SET_HIGH_WORD(d, v)                                             \
    do { U sh_u; sh_u.value = (d); sh_u.i[1] = (v); (d) = sh_u.value; } while (0)

extern const double D_0045FC60;         /* -two54/zero, folded to -inf */

#define ln2_hi  6.93147180369123816490e-01      /* 3fe62e42 fee00000 */
#define ln2_lo  1.90821492927058770002e-10      /* 3dea39ef 35793c76 */
#define two54   1.80143985094819840000e+16      /* 43500000 00000000 */
#define Lg1     6.666666666666735130e-01        /* 3FE55555 55555593 */
#define Lg2     3.999999999940941908e-01        /* 3FD99999 9997FA04 */
#define Lg3     2.857142874366239149e-01        /* 3FD24924 94229359 */
#define Lg4     2.222219843214978396e-01        /* 3FCC71C5 1D8E78AF */
#define Lg5     1.818357216161805012e-01        /* 3FC74664 96CB03DE */
#define Lg6     1.531383769920937332e-01        /* 3FC39A09 D078C69F */
#define Lg7     1.479819860511658591e-01        /* 3FC2F112 DF3E5244 */
#define zero    0.0

__attribute__((section(".text.func_003AD790")))
double func_003AD790(double x)
{
    double hfsq, f, s, z, R, w, t1, t2, dk;
    int k, hx, i, j;
    unsigned int lx;

    EXTRACT_WORDS(hx, lx, x);

    k = 0;
    if (hx < 0x00100000) {              /* x < 2**-1022 */
        if (((hx & 0x7fffffff) | lx) == 0)
            return D_0045FC60;          /* log(+-0) = -inf */
        /* Upstream fdlibm returns (x-x)/zero (a NaN) here.  Retail returns a
         * literal 0.0 -- `daddu $v0,$zero,$zero` at 0x003AD8EC -- and its
         * sibling __ieee754_log10 at 0x003ADDA8 does the same.  This vendor
         * copy of fdlibm returns zero for a negative argument. */
        if (hx < 0) return zero;        /* log(-#) */
        k -= 54; x *= two54;            /* subnormal number, scale up x */
        GET_HIGH_WORD(hx, x);
    }
    if (hx >= 0x7ff00000) return x + x;
    k += (hx >> 20) - 1023;
    hx &= 0x000fffff;
    i = (hx + 0x95f64) & 0x100000;
    SET_HIGH_WORD(x, hx | (i ^ 0x3ff00000));    /* normalize x or x/2 */
    k += (i >> 20);
    f = x - 1.0;
    if ((0x000fffff & (2 + hx)) < 3) {  /* |f| < 2**-20 */
        if (f == zero) {
            if (k == 0) return zero;
            else { dk = (double)k; return dk * ln2_hi + dk * ln2_lo; }
        }
        R = f * f * (0.5 - 0.33333333333333333 * f);
        if (k == 0) return f - R;
        else { dk = (double)k; return dk * ln2_hi - ((R - dk * ln2_lo) - f); }
    }
    s = f / (2.0 + f);
    dk = (double)k;
    z = s * s;
    i = hx - 0x6147a;
    w = z * z;
    j = 0x6b851 - hx;
    t1 = w * (Lg2 + w * (Lg4 + w * Lg6));
    t2 = z * (Lg1 + w * (Lg3 + w * (Lg5 + w * Lg7)));
    i |= j;
    R = t2 + t1;
    if (i > 0) {
        hfsq = f * (0.5 * f);   /* == 0.5*f*f; retail multiplies f by (0.5*f) */
        if (k == 0) return f - (hfsq - s * (hfsq + R));
        else return dk * ln2_hi - ((hfsq - (s * (hfsq + R) + dk * ln2_lo)) - f);
    } else {
        if (k == 0) return f - s * (f - R);
        else return dk * ln2_hi - ((s * (f - R) - dk * ln2_lo) - f);
    }
}

/* sn-2.95.3-136 matched TU. */

/* newlib libm/math/e_log10.c -- __ieee754_log10.
 * The EE ABI carries a double in a GPR, so GET_HIGH_WORD/GET_LOW_WORD/
 * SET_HIGH_WORD are register shifts through a union, not memory accesses.
 * `long` is the 64-bit type here; `long long` is 128-bit and cc1 rejects it. */

extern double func_0031E348(double a, double b);	/* dpmul */
extern double func_0031E288(double a, double b);	/* dpadd */
extern double func_0031E8C0(int i);			/* litodp */
extern double func_003AD790(double x);			/* __ieee754_log */

extern const double D_0045FC80;				/* -two54/zero == -inf */

typedef union {
	double	value;
	long	bits;
} ieee_double_shape_type;

#define GET_HIGH_WORD(i,d)					\
  do {								\
    ieee_double_shape_type gh_u;				\
    gh_u.value = (d);						\
    (i) = (int) (gh_u.bits >> 32);				\
  } while (0)

#define EXTRACT_WORDS(ix,lx,d)					\
  do {								\
    ieee_double_shape_type ew_u;				\
    ew_u.value = (d);						\
    (ix) = (int) (ew_u.bits >> 32);				\
    (lx) = (int) ew_u.bits;					\
  } while (0)

#define SET_HIGH_WORD(d,v)					\
  do {								\
    ieee_double_shape_type sh_u;				\
    sh_u.value = (d);						\
    sh_u.bits = (sh_u.bits & 0xffffffffL) | ((long) (v) << 32);	\
    (d) = sh_u.value;						\
  } while (0)

#define two54     1.80143985094819840000e+16	/* 0x43500000, 0x00000000 */
#define ivln10    4.34294481903251816668e-01	/* 0x3FDBCB7B, 0x1526E50E */
#define log10_2hi 3.01029995663611771306e-01	/* 0x3FD34413, 0x509F6000 */
#define log10_2lo 3.69423907715893089906e-13	/* 0x3D59FEF3, 0x11F12B36 */

__attribute__((section(".text.func_003ADDA8")))
double func_003ADDA8(double x)
{
	double y, z;
	int i, k, hx;
	int lx;

	EXTRACT_WORDS (hx, lx, x);	/* high and low word of x */

	k = 0;
	if (hx < 0x00100000) {			/* x < 2**-1022  */
		if (((hx & 0x7fffffff) | lx) == 0)
			return D_0045FC80;	/* log(+-0) = -inf */
		if (hx < 0)
			return 0.0;		/* log(-#) */
		k -= 54;
		x *= two54;			/* subnormal number, scale up x */
		GET_HIGH_WORD (hx, x);		/* high word of x */
	}

	if (hx >= 0x7ff00000)
		return x + x;

	k += (hx >> 20) - 1023;
	i = ((unsigned int) k & 0x80000000) >> 31;
	hx = (hx & 0x000fffff) | ((0x3ff - i) << 20);
	y = (double) (k + i);
	SET_HIGH_WORD (x, hx);
	z = y * log10_2lo + ivln10 * func_003AD790 (x);
	return z + y * log10_2hi;
}
