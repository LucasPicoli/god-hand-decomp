/* ee-2.9-991111 matched TU. */

extern float D_0045EB40;

/* LANE X1 repair, wave 18.
 * CAUSE 1: the merged TU holds three fdlibm wrappers that each define
 *          `struct exception`, which is a REDEFINITION and gives cc1 exit 33.
 * REPAIR 1: the tag carries a per-function suffix. No byte changes.
 * sqrtf emits no .rodata; the tag rename is its whole repair. */
/* ee-2.9-991111 matched TU. */

extern float func_003A3B48(float);		/* __ieee754_sqrtf */

struct exc_sqrtf {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

#define DOMAIN		1
#define SING		2
#define OVERFLOW	3
#define UNDERFLOW	4
#define TLOSS		5
#define PLOSS		6

#define _IEEE_	(-1)
#define _SVID_	0
#define _XOPEN_	1
#define _POSIX_	2

#define EDOM	33
#define ERANGE	34

extern const int D_0045F024;		/* _LIB_VERSION */
#define _LIB_VERSION D_0045F024

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);	/* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())

extern int func_003A4AC8(void *e);	/* matherr */
extern int func_003A4E00(float);		/* isnanf  */

extern char D_0045EAB8[];		/* "sqrtf" */
extern const double D_0045EAC0;		/* nan */

__attribute__((section(".text.sqrtf")))
float sqrtf(float x)			/* wrapper sqrtf */
{
	float z;
	struct exc_sqrtf exc;
	z = func_003A3B48(x);
	if(_LIB_VERSION == _IEEE_ || func_003A4E00(x)) return z;
	if(x<(float)0.0) {
	    /* sqrtf(negative) */
	    exc.type = DOMAIN;
	    exc.name = D_0045EAB8;
	    exc.err = 0;
	    exc.arg1 = exc.arg2 = (double)x;
	    if (_LIB_VERSION == _SVID_)
	        exc.retval = 0.0;
	    else
	        exc.retval = D_0045EAC0;
	    if(_LIB_VERSION == _POSIX_)
	      errno = EDOM;
	    else if (!func_003A4AC8(&exc)) {
	      errno = EDOM;
	    }
	    if (exc.err != 0)
	      errno = exc.err;
	    return (float)exc.retval;
	} else
	    return z;
}

/* newlib fdlibm sf_atan.c -- atanf
 *
 * LANE X1 repair, wave 18.
 * CAUSE 1: `typedef union {...} ieee_float_shape_type;` collides with the same
 *          typedef in func_003A2BB0 when _rehome merges both into one TU
 *          ("conflicting types for `ieee_float_shape_type'", cc1 exit 33).
 * REPAIR 1: the typedef and its macro carry a per-function suffix.
 * CAUSE 2: the `static const float` tables emitted a 0x54 B TU-local .rodata.
 *          A carved TU must emit an EMPTY .rodata; a stray pool shifts every
 *          later section and the ELF sha256 gate fails. score_candidate
 *          compares .text.<name> ONLY, so the pool was INVISIBLE to it.
 * REPAIR 2: the tables are read from the split rodata blob at the addresses
 *          retail itself uses -- D_0045EA08 (atanhi), D_0045EA18 (atanlo),
 *          D_0045EA28 (aT). `one` and `huge` are lui immediates in retail, so
 *          they become plain literals. The TU now emits NO .rodata and every
 *          relocation is comparable against retail. */

extern float func_003A19D8(float x);		/* fabsf */

extern const float D_0045EA08[4];		/* atanhi[0..3] */
extern const float D_0045EA14;			/* atanhi[3]    */
extern const float D_0045EA18[4];		/* atanlo[0..3] */
extern const float D_0045EA24;			/* atanlo[3]    */
extern const float D_0045EA28[11];		/* aT[0..10]    */

typedef union {
	float value;
	int word;
} ieee_float_shape_type_3A1648;

#define GET_FLOAT_WORD_3A1648(i,d)				\
do {								\
	ieee_float_shape_type_3A1648 gf_u;			\
	gf_u.value = (d);					\
	(i) = gf_u.word;					\
} while (0)

#define atanhi	D_0045EA08
#define atanlo	D_0045EA18
#define aT	D_0045EA28
#define one	((float)1.0)
#define huge	((float)1.0e30)

__attribute__((section(".text.func_003A1648")))
float func_003A1648(float x)
{
	float w, s1, s2, z;
	int ix, hx, id;

	GET_FLOAT_WORD_3A1648(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x50800000) {			/* if |x| >= 2^34 */
		if (ix > 0x7f800000)
			return x + x;		/* NaN */
		if (hx > 0)
			return D_0045EA14 + D_0045EA24;
		else
			return -D_0045EA14 - D_0045EA24;
	}
	if (ix < 0x3ee00000) {			/* |x| < 0.4375 */
		if (ix < 0x31000000) {		/* |x| < 2^-29 */
			if (huge + x > one)
				return x;	/* raise inexact */
		}
		id = -1;
	} else {
		x = func_003A19D8(x);
		if (ix < 0x3f980000) {		/* |x| < 1.1875 */
			if (ix < 0x3f300000) {	/* 7/16 <= |x| < 11/16 */
				id = 0;
				x = ((float)2.0 * x - one) / ((float)2.0 + x);
			} else {		/* 11/16 <= |x| < 19/16 */
				id = 1;
				x = (x - one) / (x + one);
			}
		} else {
			if (ix < 0x401c0000) {	/* |x| < 2.4375 */
				id = 2;
				x = (x - (float)1.5) / (one + (float)1.5 * x);
			} else {		/* 2.4375 <= |x| < 2^66 */
				id = 3;
				x = -(float)1.0 / x;
			}
		}
	}
	z = x * x;
	w = z * z;
	s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
	s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
	if (id < 0)
		return x - x * (s1 + s2);
	else {
		z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
		return (hx < 0) ? -z : z;
	}
}

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
