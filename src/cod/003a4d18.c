/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU.  fp_hazard_rules: "cmpfull"  (NOT "libm").
 * fdlibm sf_floor.c -- floorf.  Donor: sce_crt_libm/sf_floor.o :: floorf.
 * MATCH (exact), 228 B, verified by score_candidate.py from disk.
 */

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

#define huge ((float)(1.0e30))

__attribute__((section(".text.func_003A4D18")))
float func_003A4D18(float x)
{
	int i0,j0;
	unsigned i;
	GET_FLOAT_WORD(i0,x);
	j0 = ((i0>>23)&0xff)-127;
	if(j0<23) {
	    if(j0<0) { 	/* raise inexact if x != 0 */
		if(huge+x>(float)0.0) {/* return 0*sign(x) if |x|<1 */
		    if(i0>=0) {i0=0;}
		    else if((i0&0x7fffffff)!=0)
			{ i0=0xbf800000;}
		}
	    } else {
		i = (0x007fffff)>>j0;
		if((i0&i)==0) return x; /* x is integral */
		if(huge+x>(float)0.0) {	/* raise inexact flag */
		    if(i0<0) i0 += (0x00800000)>>j0;
		    i0 &= (~i);
		}
	    }
	} else {
	    if(j0==0x80) return x+x;	/* inf or NaN */
	    else return x;		/* x is integral */
	}
	SET_FLOAT_WORD(x,i0);
	return x;
}
