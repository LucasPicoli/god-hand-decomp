/* ee-2.9-991111 matched TU. */

typedef union
{
  float value;
  unsigned int word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i,d)					\
do {								\
  ieee_float_shape_type gf_u;					\
  gf_u.value = (d);						\
  (i) = gf_u.word;						\
} while (0)

#define half ((float)(5.0000000000e-01))
#define S1 ((float)(-1.6666667163e-01))
#define S2 ((float)(8.3333337680e-03))
#define S3 ((float)(-1.9841270114e-04))
#define S4 ((float)(2.7557314297e-06))
#define S5 ((float)(-2.5050759689e-08))
#define S6 ((float)(1.5896910177e-10)) /* 0x2f2ec9d3 */

__attribute__((section(".text.func_003A4728")))
float func_003A4728(float x, float y, int iy)
{
	float z,r,v;
	int ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;			/* high word of x */
	if(ix<0x32000000)			/* |x| < 2**-27 */
	   {if((int)x==0) return x;}		/* generate inexact */
	z	=  x*x;
	v	=  z*x;
	r	=  S2+z*(S3+z*(S4+z*(S5+z*S6)));
	if(iy==0) return x+v*(S1+z*r);
	else      return x-((z*(half*y-v*r)-y)-v*S1);
}
