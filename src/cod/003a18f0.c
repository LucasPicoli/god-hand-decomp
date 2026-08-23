/* ee-2.9-991111 matched TU. */

extern int __ieee754_rem_pio2f(float x, float *y);

/* newlib fdlibm sf_cos.c -- cosf */

extern float func_003A3C80(float x, float y);			/* __kernel_cosf */
extern float func_003A4728(float x, float y, int iy);		/* __kernel_sinf */


typedef union {
	float value;
	int word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i,d)					\
do {								\
	ieee_float_shape_type gf_u;				\
	gf_u.value = (d);					\
	(i) = gf_u.word;					\
} while (0)

__attribute__((section(".text.func_003A18F0")))
float func_003A18F0(float x)
{
	float y[2], z = 0.0;
	int n, ix;

	GET_FLOAT_WORD(ix, x);

	ix &= 0x7fffffff;
	if (ix <= 0x3f490fd8)
		return func_003A3C80(x, z);
	else if (ix >= 0x7f800000)
		return x - x;
	else {
		n = __ieee754_rem_pio2f(x, y);
		switch (n & 3) {
		case 0:
			return func_003A3C80(y[0], y[1]);
		case 1:
			return -func_003A4728(y[0], y[1], 1);
		case 2:
			return -func_003A3C80(y[0], y[1]);
		default:
			return func_003A4728(y[0], y[1], 1);
		}
	}
}
