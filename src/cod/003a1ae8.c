/* ee-2.9-991111 matched TU. */

extern int __ieee754_rem_pio2f(float, float *);
extern float func_003A4830(float, float, int);

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




__attribute__((section(".text.func_003A1AE8")))
float func_003A1AE8(float x)
{
	float y[2];
	int ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3f490fda) return func_003A4830(x,(float)0.0,1);
	else if (ix>0x7f7fffff) return x-x;
	else {
	    return func_003A4830(y[0],y[1],
			1-((__ieee754_rem_pio2f(x,y)&1)<<1));
	}
}
