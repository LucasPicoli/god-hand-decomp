/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111; libgcc fp-bit.c :: divide (double variant, gofast dpdiv), _fpdiv_parts inlined as upstream. */

typedef unsigned long fractype;
typedef long long FLO_type;

typedef enum
{
  CLASS_SNAN,
  CLASS_QNAN,
  CLASS_ZERO,
  CLASS_NUMBER,
  CLASS_INFINITY
} fp_class_type;

typedef struct
{
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union
    {
      fractype ll;
      unsigned int l[2];
    } fraction;
} fp_number_type;

#define isnan(x)  ((x)->class == CLASS_SNAN || (x)->class == CLASS_QNAN)
#define isinf(x)  (((x)->class ^ CLASS_INFINITY) == 0)
#define iszero(x) (((x)->class ^ CLASS_ZERO) == 0)
#define NGARDS 8L
#define GARDROUND 0x7f
#define GARDMASK  0xff
#define GARDMSB   0x80
#define FRACBITS 52
#define IMPLICIT_1 (1LL<<(FRACBITS+NGARDS))

extern unsigned char D_00755BD0[];
#define nan() ((fp_number_type *)D_00755BD0)

extern void func_0031DFA8 (FLO_type *, fp_number_type *);   /* unpack_d */
extern FLO_type func_0031DE78 (fp_number_type *);           /* pack_d */

static __inline__ fp_number_type *
_fpdiv_parts (fp_number_type * a,
	      fp_number_type * b)
{
  fractype bit;
  fractype numerator;
  fractype denominator;
  fractype quotient;

  if (isnan (a))
    {
      return a;
    }
  if (isnan (b))
    {
      return b;
    }

  a->sign = a->sign ^ b->sign;

  if (isinf (a) || iszero (a))
    {
      if (a->class == b->class)
	return nan ();
      return a;
    }

  if (isinf (b))
    {
      a->fraction.ll = 0;
      a->normal_exp = 0;
      return a;
    }
  if (iszero (b))
    {
      a->class = CLASS_INFINITY;
      return a;
    }

  {
    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator)
      {
	/* Fraction will be less than 1.0 */
	numerator *= 2;
	a->normal_exp--;
      }
    bit = IMPLICIT_1;
    quotient = 0;
    /* ??? Does divide one bit at a time.  Optimize.  */
    while (bit)
      {
	if (numerator >= denominator)
	  {
	    quotient |= bit;
	    numerator -= denominator;
	  }
	bit >>= 1;
	numerator *= 2;
      }

    if ((quotient & GARDMASK) == GARDMSB)
      {
	if (quotient & (1 << NGARDS))
	  {
	    /* half way, so round to even */
	    quotient += GARDROUND + 1;
	  }
	else if (numerator)
	  {
	    /* but we really weren't half way, more bits exist */
	    quotient += GARDROUND + 1;
	  }
      }

    a->fraction.ll = quotient;
    return (a);
  }
}

__attribute__((section(".text.func_0031E5F0")))
FLO_type
func_0031E5F0 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type *res;

  func_0031DFA8 (&arg_a, &a);
  func_0031DFA8 (&arg_b, &b);

  res = _fpdiv_parts (&a, &b);

  return func_0031DE78 (res);
}
