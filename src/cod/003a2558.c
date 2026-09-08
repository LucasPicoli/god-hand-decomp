/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU.  fp_hazard_rules: "libm,cmpfull".
 * newlib libm ef_asin.c -- __ieee754_asinf.  Donor: sce_crt_libm/ef_asin.o.
 * MATCH (exact), 924 B.  Emitted symbol: __ieee754_asinf.
 * Callees: func_003A19D8 (fabsf), func_003A3B48 (__ieee754_sqrtf) -- both landed.
 */
/* newlib libm ef_asin.c -- __ieee754_asinf */

extern float func_003A19D8(float);	/* fabsf */
extern float func_003A3B48(float);	/* __ieee754_sqrtf */

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

#define SET_FLOAT_WORD(d,i)					\
do {								\
  ieee_float_shape_type sf_u;					\
  sf_u.word = (i);						\
  (d) = sf_u.value;						\
} while (0)

#define one	((float)1.0)	/* 0x3F800000 */
#define huge	((float)1.0000000150474662e+30)	/* 0x7149F2CA */
#define pio2_hi	((float)1.570796251296997)	/* 0x3FC90FDA */
#define pio2_lo	((float)7.549789415861596e-08)	/* 0x33A22168 */
#define pio4_hi	((float)0.7853981852531433)	/* 0x3F490FDB */
#define pS0	((float)0.1666666716337204)	/* 0x3E2AAAAB */
#define pS1	((float)-0.32556581497192383)	/* 0xBEA6B090 */
#define pS2	((float)0.20121252536773682)	/* 0x3E4E0AA8 */
#define pS3	((float)-0.0400555357336998)	/* 0xBD241146 */
#define pS4	((float)0.0007915350142866373)	/* 0x3A4F7F04 */
#define pS5	((float)3.479330916889012e-05)	/* 0x3811EF08 */
#define qS1	((float)-2.403394937515259)	/* 0xC019D139 */
#define qS2	((float)2.0209457874298096)	/* 0x4001572D */
#define qS3	((float)-0.6882839798927307)	/* 0xBF303361 */
#define qS4	((float)0.07703815400600433)	/* 0x3D9DC62E */

__attribute__((section(".text.__ieee754_asinf")))
float __ieee754_asinf(float x)
{
	float t,w,p,q,c,r,s;
	int hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
		/* asin(1)=+-pi/2 with inexact */
	    return x*pio2_hi+x*pio2_lo;
	} else if(ix> 0x3f800000) {	/* |x|>= 1 */
	    return (x-x)/(x-x);		/* asin(|x|>1) is NaN */
	} else if (ix<0x3f000000) {	/* |x|<0.5 */
	    if(ix<0x32000000) {		/* if |x| < 2**-27 */
		if(huge+x>one) return x;/* return x with inexact if x!=0*/
	    } else
		t = x*x;
		p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
		q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
		w = p/q;
		return x+x*w;
	}
	/* 1> |x|>= 0.5 */
	w = one-func_003A19D8(x);
	t = w*(float)0.5;
	p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
	q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
	s = func_003A3B48(t);
	if(ix>=0x3F79999A) { 	/* if |x| > 0.975 */
	    w = p/q;
	    t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
	} else {
	    int iw;
	    w  = s;
	    GET_FLOAT_WORD(iw,w);
	    SET_FLOAT_WORD(w,iw&0xfffff000);
	    c  = (t-w*w)/(s+w);
	    r  = p/q;
	    p  = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
	    q  = pio4_hi-(float)2.0*w;
	    t  = pio4_hi-(p-q);
	}
	if(hx>0) return t; else return -t;
}
