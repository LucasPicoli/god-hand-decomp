/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU.  NO fp_hazard_rules (none needed).
 * newlib libm ef_rem_pio2.c -- __ieee754_rem_pio2f.  Donor: sce_crt_libm/ef_rem_pio2.o.
 * MATCH (exact), 992 B.  Emitted symbol: __ieee754_rem_pio2f.
 * Callees: func_003A19D8 (fabsf, landed), __kernel_rem_pio2f (__kernel_rem_pio2f, OPEN).
 * Data: D_0045EEE8 (npio2_hw[32]), D_0045EBD0 (two_over_pi).
 */
/* newlib libm ef_rem_pio2.c -- __ieee754_rem_pio2f */

extern float func_003A19D8(float);	/* fabsf */
extern int __kernel_rem_pio2f(float *, float *, int, int, int, const int *);	/* __kernel_rem_pio2f */
extern const int D_0045EEE8[32];	/* npio2_hw   */
extern const int D_0045EBD0[];		/* two_over_pi */
#define npio2_hw    D_0045EEE8
#define two_over_pi D_0045EBD0

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

#define zero	((float)0.0)			/* 0x00000000 */
#define half	((float)0.5)			/* 0x3F000000 */
#define two8	((float)256.0)			/* 0x43800000 */
#define invpio2	((float)0.6366198062896729)	/* 0x3F22F984 */
#define pio2_1	((float)1.5707855224609375)	/* 0x3FC90F80 */
#define pio2_1t	((float)1.0804334124259185e-05)	/* 0x37354443 */
#define pio2_2	((float)1.0804273188114166e-05)	/* 0x37354400 */
#define pio2_2t	((float)6.07709993438732e-11)	/* 0x2E85A308 */
#define pio2_3	((float)6.077094383272197e-11)	/* 0x2E85A300 */
#define pio2_3t	((float)6.123234262925839e-17)	/* 0x248D3132 */

__attribute__((section(".text.__ieee754_rem_pio2f")))
int __ieee754_rem_pio2f(float x, float *y)
{
	float z,w,t,r,fn;
	float tx[3];
	int e0,i,j,nx,n,ix,hx;

	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix<=0x3f490fd8)   /* |x| ~<= pi/4 , no need for reduction */
	    {y[0] = x; y[1] = 0; return 0;}
	if(ix<0x4016cbe4) {  /* |x| < 3pi/4, special case with n=+-1 */
	    if(hx>0) {
		z = x - pio2_1;
		if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
		    y[0] = z - pio2_1t;
		    y[1] = (z-y[0])-pio2_1t;
		} else {		/* near pi/2, use 24+24+24 bit pi */
		    z -= pio2_2;
		    y[0] = z - pio2_2t;
		    y[1] = (z-y[0])-pio2_2t;
		}
		return 1;
	    } else {	/* negative x */
		z = x + pio2_1;
		if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
		    y[0] = z + pio2_1t;
		    y[1] = (z-y[0])+pio2_1t;
		} else {		/* near pi/2, use 24+24+24 bit pi */
		    z += pio2_2;
		    y[0] = z + pio2_2t;
		    y[1] = (z-y[0])+pio2_2t;
		}
		return -1;
	    }
	}
	if(ix<=0x43490f80) { /* |x| ~<= 2^7*(pi/2), medium size */
	    t  = func_003A19D8(x);
	    n  = (int) (t*invpio2+half);
	    fn = (float)n;
	    r  = t-fn*pio2_1;
	    w  = fn*pio2_1t;	/* 1st round good to 40 bit */
	    if(n<32&&(ix&0xffffff00)!=npio2_hw[n-1]) {
		y[0] = r-w;	/* quick check no cancellation */
	    } else {
	        unsigned high;
	        j  = ix>>23;
	        y[0] = r-w;
		GET_FLOAT_WORD(high,y[0]);
	        i = j-((high>>23)&0xff);
	        if(i>8) {  /* 2nd iteration needed, good to 57 */
		    t  = r;
		    w  = fn*pio2_2;
		    r  = t-w;
		    w  = fn*pio2_2t-((t-r)-w);
		    y[0] = r-w;
		    GET_FLOAT_WORD(high,y[0]);
		    i = j-((high>>23)&0xff);
		    if(i>25)  {	/* 3rd iteration need, 74 bits acc */
		    	t  = r;	/* will cover all possible cases */
		    	w  = fn*pio2_3;
		    	r  = t-w;
		    	w  = fn*pio2_3t-((t-r)-w);
		    	y[0] = r-w;
		    }
		}
	    }
	    y[1] = (r-y[0])-w;
	    if(hx<0) 	{y[0] = -y[0]; y[1] = -y[1]; return -n;}
	    else	 return n;
	}
    /*
     * all other (large) arguments
     */
	if(ix>=0x7f800000) {		/* x is inf or NaN */
	    y[0]=y[1]=x-x; return 0;
	}
    /* set z = scalbn(|x|,ilogb(x)-7) */
	e0 	= (ix>>23)-134;		/* e0 = ilogb(z)-7; */
	SET_FLOAT_WORD(z, ix - ((int)(e0<<23)));
	for(i=0;i<2;i++) {
		tx[i] = (float)((int)(z));
		z     = (z-tx[i])*two8;
	}
	tx[2] = z;
	nx = 3;
	while(tx[nx-1]==zero) nx--;	/* skip zero term */
	n  =  __kernel_rem_pio2f(tx,y,e0,nx,2,two_over_pi);
	if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
	return n;
}
