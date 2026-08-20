/* ee-2.9-991111 matched TU. */

extern int __ieee754_rem_pio2f(float, float *);
extern float func_003A3C80(float, float);
extern float func_003A4728(float, float, int);

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





__attribute__((section(".text.func_003A19F8")))
float func_003A19F8(float x)
{
	float y[2];
	int ix;

    /* High word of x. */
	GET_FLOAT_WORD(ix,x);

    /* |x| ~< pi/4 */
	ix &= 0x7fffffff;
	if(ix <= 0x3f490fd8) return func_003A4728(x,(float)0.0,0);

    /* sin(Inf or NaN) is NaN */
	else if (ix>=0x7f800000) return x-x;

    /* argument reduction needed */
	else {
	    switch(__ieee754_rem_pio2f(x,y)&3) {
		case 0: return  func_003A4728(y[0],y[1],1);
		case 1: return  func_003A3C80(y[0],y[1]);
		case 2: return -func_003A4728(y[0],y[1],1);
		default:
			return -func_003A3C80(y[0],y[1]);
	    }
	}
}
