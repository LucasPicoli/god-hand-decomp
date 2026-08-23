/* ee-2.9-991111 matched TU. */

extern float scalbnf(float, int);

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

#define SET_FLOAT_WORD(d,i)					\
do {								\
  ieee_float_shape_type sf_u;					\
  sf_u.word = (i);						\
  (d) = sf_u.value;						\
} while (0)

extern float func_003A19D8(float);		/* fabsf           */
extern float func_003A3B48(float);		/* __ieee754_sqrtf */


extern const float D_0045EB48[2];		/* bp   */
extern const float D_0045EB50[2];		/* dp_h */
extern const float D_0045EB58[2];		/* dp_l */
extern const float D_0045EBCC;			/* huge*huge, folded to +inf */
#define bp   D_0045EB48
#define dp_h D_0045EB50
#define dp_l D_0045EB58

#define zero      ((float)0.000000000e+00)
#define one       ((float)1.000000000e+00)
#define two       ((float)2.000000000e+00)
#define two24     ((float)1.677721600e+07)
#define huge      ((float)1.000000015e+30)
#define tiny      ((float)1.000000003e-30)
#define L1        ((float)6.000000238e-01)
#define L2        ((float)4.285714328e-01)
#define L3        ((float)3.333333433e-01)
#define L4        ((float)2.727281153e-01)
#define L5        ((float)2.306607515e-01)
#define L6        ((float)2.069750130e-01)
#define P1        ((float)1.666666716e-01)
#define P2        ((float)-2.777777845e-03)
#define P3        ((float)6.613755977e-05)
#define P4        ((float)-1.653390200e-06)
#define P5        ((float)4.138136944e-08)
#define lg2       ((float)6.931471825e-01)
#define lg2_h     ((float)6.931457520e-01)
#define lg2_l     ((float)1.428606538e-06)
#define ovt       ((float)4.299566569e-08)
#define cp        ((float)9.617967010e-01)
#define cp_h      ((float)9.617919922e-01)
#define cp_l      ((float)4.701738362e-06)
#define ivln2     ((float)1.442695022e+00)
#define ivln2_h   ((float)1.442687988e+00)
#define ivln2_l   ((float)7.052607543e-06)

__attribute__((section(".text.func_003A2ED8")))
float func_003A2ED8(float x, float y)		/* __ieee754_powf */
{
	float z,ax,z_h,z_l,p_h,p_l;
	float y1,t1,t2,r,s,t,u,v,w;
	int i,j,k,yisint,n;
	int hx,hy,ix,iy,is;

	GET_FLOAT_WORD(hx,x);
	GET_FLOAT_WORD(hy,y);
	ix = hx&0x7fffffff;  iy = hy&0x7fffffff;

    /* y==zero: x**0 = 1 */
	if(iy==0) return one;

    /* +-NaN return x+y */
	if(ix > 0x7f800000 ||
	   iy > 0x7f800000)
		return x+y;

    /* determine if y is an odd int when x < 0
     * yisint = 0	... y is not an integer
     * yisint = 1	... y is an odd int
     * yisint = 2	... y is an even int
     */
	yisint  = 0;
	if(hx<0) {
	    if(iy>=0x4b800000) yisint = 2; /* even integer y */
	    else if(iy>=0x3f800000) {
		k = (iy>>23)-0x7f;	   /* exponent */
		j = iy>>(23-k);
		if((j<<(23-k))==iy) yisint = 2-(j&1);
	    }
	}

    /* special value of y */
	if (iy==0x7f800000) {	/* y is +-inf */
	    if(ix==0x3f800000)
	        return  y - y;	/* inf**+-1 is NaN */
	    else if (ix > 0x3f800000)/* (|x|>1)**+-inf = inf,0 */
	        return (hy>=0)? y: zero;
	    else			/* (|x|<1)**-,+inf = inf,0 */
	        return (hy<0)?-y: zero;
	}
	if(iy==0x3f800000) {	/* y is  +-1 */
	    if(hy<0) return one/x; else return x;
	}
	if(hy==0x40000000) return x*x; /* y is  2 */
	if(hy==0x3f000000) {	/* y is  0.5 */
	    if(hx>=0)	/* x >= +0 */
	    return func_003A3B48(x);
	}

	ax   = func_003A19D8(x);
    /* special value of x */
	if(ix==0x7f800000||ix==0||ix==0x3f800000){
	    z = ax;			/*x is +-0,+-inf,+-1*/
	    if(hy<0) z = one/z;	/* z = (1/|x|) */
	    if(hx<0) {
		if(((ix-0x3f800000)|yisint)==0) {
		    z = (z-z)/(z-z); /* (-1)**non-int is NaN */
		} else if(yisint==1)
		    z = -z;		/* (x<0)**odd = -(|x|**odd) */
	    }
	    return z;
	}

    /* (x<0)**(non-int) is NaN */
	if(((((unsigned)hx>>31)-1)|yisint)==0) return (x-x)/(x-x);

    /* |y| is huge */
	if(iy>0x4d000000) { /* if |y| > 2**27 */
	/* over/underflow if x is not close to one */
	    if(ix<0x3f7ffff8) return (hy<0)? D_0045EBCC:tiny*tiny;
	    if(ix>0x3f800007) return (hy>0)? D_0045EBCC:tiny*tiny;
	/* now |1-x| is tiny <= 2**-20, suffice to compute
	   log(x) by x-x^2/2+x^3/3-x^4/4 */
	    t = x-1;		/* t has 20 trailing zeros */
	    w = (t*t)*((float)0.5-t*((float)0.333333333333-t*(float)0.25));
	    u = ivln2_h*t;	/* ivln2_h has 16 sig. bits */
	    v = t*ivln2_l-w*ivln2;
	    t1 = u+v;
	    GET_FLOAT_WORD(is,t1);
	    SET_FLOAT_WORD(t1,is&0xfffff000);
	    t2 = v-(t1-u);
	} else {
	    float s2,s_h,s_l,t_h,t_l;
	    n = 0;
	/* take care subnormal number */
	    if(ix<0x00800000)
		{ax *= two24; n -= 24; GET_FLOAT_WORD(ix,ax); }
	    n  += ((ix)>>23)-0x7f;
	    j  = ix&0x007fffff;
	/* determine interval */
	    ix = j|0x3f800000;		/* normalize ix */
	    if(j<=0x1cc471) k=0;	/* |x|<sqrt(3/2) */
	    else if(j<0x5db3d7) k=1;	/* |x|<sqrt(3)   */
	    else {k=0;n+=1;ix -= 0x00800000;}
	    SET_FLOAT_WORD(ax,ix);

	/* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
	    u = ax-bp[k];		/* bp[0]=1.0, bp[1]=1.5 */
	    v = one/(ax+bp[k]);
	    s = u*v;
	    s_h = s;
	    GET_FLOAT_WORD(is,s_h);
	    SET_FLOAT_WORD(s_h,is&0xfffff000);
	/* t_h=ax+bp[k] High */
	    is = ((ix>>1)|0x20000000)+0x0040000+(k<<21);
	    SET_FLOAT_WORD(t_h,is);
	    t_l = ax - (t_h-bp[k]);
	    s_l = v*((u-s_h*t_h)-s_h*t_l);
	/* compute log(ax) */
	    s2 = s*s;
	    r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
	    r += s_l*(s_h+s);
	    s2  = s_h*s_h;
	    t_h = (float)3.0+s2+r;
	    GET_FLOAT_WORD(is,t_h);
	    SET_FLOAT_WORD(t_h,is&0xfffff000);
	    t_l = r-((t_h-(float)3.0)-s2);
	/* u+v = s*(1+...) */
	    u = s_h*t_h;
	    v = s_l*t_h+t_l*s;
	/* 2/(3log2)*(s+...) */
	    p_h = u+v;
	    GET_FLOAT_WORD(is,p_h);
	    SET_FLOAT_WORD(p_h,is&0xfffff000);
	    p_l = v-(p_h-u);
	    z_h = cp_h*p_h;		/* cp_h+cp_l = 2/(3*log2) */
	    z_l = cp_l*p_h+p_l*cp+dp_l[k];
	/* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
	    t = (float)n;
	    t1 = (((z_h+z_l)+dp_h[k])+t);
	    GET_FLOAT_WORD(is,t1);
	    SET_FLOAT_WORD(t1,is&0xfffff000);
	    t2 = z_l-(((t1-t)-dp_h[k])-z_h);
	}

	s = one; /* s (sign of result -ve**odd) = -1 else = 1 */
	if(((((unsigned)hx>>31)-1)|(yisint-1))==0)
	    s = -one;	/* (-ve)**(odd int) */

    /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
	GET_FLOAT_WORD(is,y);
	SET_FLOAT_WORD(y1,is&0xfffff000);
	p_l = (y-y1)*t1+y*t2;
	p_h = y1*t1;
	z = p_l+p_h;
	GET_FLOAT_WORD(j,z);
	if (j>0x43000000)				/* if z > 128 */
	    return s*huge*huge;			/* overflow */
	else if(j==0x43000000) {			/* if z == 128 */
	    if(p_l+ovt>z-p_h) return s*huge*huge;	/* overflow */
	} else if((j&0x7fffffff)>0x43160000)		/* z <= -150 */
	    return s*tiny*tiny;				/* underflow */
	else if((unsigned)j==0xc3160000){		/* z == -150 */
	    if(p_l<=z-p_h) return s*tiny*tiny;		/* underflow */
	}
    /*
     * compute 2**(p_h+p_l)
     */
	i = j&0x7fffffff;
	k = (i>>23)-0x7f;
	n = 0;
	if(i>0x3f000000) {		/* if |z| > 0.5, set n = [z+0.5] */
	    n = j+(0x00800000>>(k+1));
	    k = ((n&0x7fffffff)>>23)-0x7f;	/* new k for n */
	    SET_FLOAT_WORD(t,n&~(0x007fffff>>k));
	    n = ((n&0x007fffff)|0x00800000)>>(23-k);
	    if(j<0) n = -n;
	    p_h -= t;
	}
	t = p_l+p_h;
	GET_FLOAT_WORD(is,t);
	SET_FLOAT_WORD(t,is&0xfffff000);
	u = t*lg2_h;
	v = (p_l-(t-p_h))*lg2+t*lg2_l;
	z = u+v;
	w = v-(z-u);
	t  = z*z;
	t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	r  = (z*t1)/(t1-two)-(w+z*w);
	z  = one-(r-z);
	GET_FLOAT_WORD(j,z);
	j += (n<<23);
	if((j>>23)<=0) z = scalbnf(z,n);	/* subnormal output */
	else SET_FLOAT_WORD(z,j);
	return s*z;
}
