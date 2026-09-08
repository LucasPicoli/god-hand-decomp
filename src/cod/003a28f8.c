/* ee-2.9-991111 matched TU. */

/* MATCH (exact), 692 B.  Wave 23 lane G, 2026-09-07.
 * newlib libm ef_exp.c -- __ieee754_expf.  Donor: sce_crt_libm/ef_exp.o.
 *
 *   compiler:         ee-2.9-991111
 *   assembler:        ee (default)
 *   fp_hazard_rules:  "libm-mtc1,fpfence"
 *
 *   python3 .private/scripts/score_candidate.py func_003A28F8 <this file> \
 *           --compiler ee-2.9-991111 --fp-hazard-rules libm-mtc1,fpfence
 *   -> MATCH (exact)
 *
 * The BODY is worker D3's, unchanged.  Only the wrapper moved.
 *   `libm-mtc1` drops the FTOI->mfc1 pad this object does not carry.
 *   `fpfence` closes D3's second residual, which D3 called the scheduler wall.
 *   IT IS NOT ONE.  Retail ends `mtc1 $v1,$f1 / mul.s $f0,$f1,$f0 / jr ra /
 *   nop` at 0x003A2B9C; ee-as hoists the `mul.s` into the `jr` delay slot and
 *   the body comes out ONE WORD SHORT.  A `.set noreorder` fence around the
 *   `mul.s` -- the same fence the `fdiv` pad already uses -- stops the hoist.
 *   Measured directly on the tracked ee-as 2.10 before any rule was written.
 *   ee-as does NOT hoist an `mtc1` the same way (retail 0x003A2B84 reproduces
 *   with no fence), which is why the rule names the FP arithmetic class only.
 */
/* newlib libm ef_exp.c -- __ieee754_expf */

extern const float D_0045EAD0[2];	/* halF  */
extern const float D_0045EAE8[2];	/* ln2HI */
extern const float D_0045EAF0[2];	/* ln2LO */
extern const float D_0045EB10;		/* huge*huge, folded to +inf */
#define halF  D_0045EAD0
#define ln2HI D_0045EAE8
#define ln2LO D_0045EAF0

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
#define twom100	((float)7.888609052210118e-31)	/* 0x0D800000 */
#define o_threshold	((float)88.7216796875)	/* 0x42B17180 */
#define u_threshold	((float)-103.97208404541016)	/* 0xC2CFF1B5 */
#define invln2	((float)1.4426950216293335)	/* 0x3FB8AA3B */
#define P1	((float)0.1666666716337204)	/* 0x3E2AAAAB */
#define P2	((float)-0.0027777778450399637)	/* 0xBB360B61 */
#define P3	((float)6.61375597701408e-05)	/* 0x388AB355 */
#define P4	((float)-1.6533901998627698e-06)	/* 0xB5DDEA0E */
#define P5	((float)4.138136944220605e-08)	/* 0x3331BB4C */

__attribute__((section(".text.func_003A28F8")))
float func_003A28F8(float x)	/* __ieee754_expf */
{
	float y,hi,lo,c,t;
	int k,xsb;
	unsigned hx;

	GET_FLOAT_WORD(hx,x);
	xsb = (hx>>31)&1;		/* sign bit of x */
	hx &= 0x7fffffff;		/* high word of |x| */

    /* filter out non-finite argument */
	if(hx >= 0x42b17218) {			/* if |x|>=88.721... */
            if(hx>0x7f800000)
		 return x+x;	 		/* NaN */
            if(hx==0x7f800000)
		return (xsb==0)? x:(float)0.0;	/* exp(+-inf)={inf,0} */
	    if(x > o_threshold) return D_0045EB10;	/* overflow */
	    if(x < u_threshold) return twom100*twom100;	/* underflow */
	}

    /* argument reduction */
	if(hx > 0x3eb17218) {		/* if  |x| > 0.5 ln2 */
	    if(hx < 0x3F851592) {	/* and |x| < 1.5 ln2 */
		hi = x-ln2HI[xsb]; lo=ln2LO[xsb]; k = 1-xsb-xsb;
	    } else {
		k  = invln2*x+halF[xsb];
		t  = k;
		hi = x - t*ln2HI[0];	/* t*ln2HI is exact here */
		lo = t*ln2LO[0];
	    }
	    x  = hi - lo;
	}
	else if(hx < 0x31800000)  {	/* when |x|<2**-28 */
	    if(huge+x>one) return one+x;/* trigger inexact */
	}
	else k = 0;

    /* x is now in primary range */
	t  = x*x;
	c  = x - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	if(k==0) 	return one-((x*c)/(c-(float)2.0)-x);
	else 		y = one-((lo-(x*c)/((float)2.0-c))-hi);
	if(k >= -125) {
	    unsigned hy;
	    GET_FLOAT_WORD(hy,y);
	    SET_FLOAT_WORD(y,hy+(k<<23));	/* add k to y's exponent */
	    return y;
	} else {
	    unsigned hy;
	    GET_FLOAT_WORD(hy,y);
	    SET_FLOAT_WORD(y,hy+((k+100)<<23));	/* add k to y's exponent */
	    return y*twom100;
	}
}
