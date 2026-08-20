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

__attribute__((section(".text.func_003A19D8")))
float func_003A19D8(float x)
{
	unsigned int ix;
	GET_FLOAT_WORD(ix,x);
	SET_FLOAT_WORD(x,ix&0x7fffffff);
	return x;
}
