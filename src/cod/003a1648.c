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
