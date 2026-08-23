/* ee-2.9-991111 matched TU. */

extern unsigned char D_00755BD0[];

/* libgcc fp-bit.c :: _fpadd_parts (double variant) */

typedef unsigned long fractype;
typedef long intfrac;

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
#define notinf(x)  ((x)->class ^ CLASS_INFINITY)
#define notzero(x) ((x)->class ^ CLASS_ZERO)

#define FRAC_NBITS 64
#define IMPLICIT_1 ((fractype) 1 << 60)
#define IMPLICIT_2 ((fractype) 1 << 61)

#define LSHIFT(a) ((a) = ((a) & 1) | ((a) >> 1))

#define nan() ((fp_number_type *)D_00755BD0)

__attribute__((section(".text.func_0031E048")))
fp_number_type *
func_0031E048 (fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
  intfrac tfraction;

  if (isnan (a))
    return a;
  if (isnan (b))
    return b;

  if (notinf (a) == 0)
    {
      if (notinf (b) == 0 && a->sign != b->sign)
	return nan ();
      return a;
    }
  if (notinf (b) == 0)
    return b;

  if (notzero (b) == 0)
    {
      if (notzero (a) == 0)
	{
	  *tmp = *a;
	  tmp->sign = a->sign & b->sign;
	  return tmp;
	}
      return a;
    }
  if (notzero (a) == 0)
    return b;

  {
    int diff;
    int a_normal_exp = a->normal_exp;
    int b_normal_exp = b->normal_exp;
    fractype a_fraction = a->fraction.ll;
    fractype b_fraction = b->fraction.ll;

    diff = a_normal_exp - b_normal_exp;
    if (diff < 0)
      diff = -diff;
    if (diff < FRAC_NBITS)
      {
	while (b_normal_exp < a_normal_exp)
	  {
	    b_normal_exp++;
	    LSHIFT (b_fraction);
	  }
	while (a_normal_exp < b_normal_exp)
	  {
	    a_normal_exp++;
	    LSHIFT (a_fraction);
	  }
      }
    else
      {
	if (b_normal_exp < a_normal_exp)
	  {
	    b_normal_exp = a_normal_exp;
	    b_fraction = 0;
	  }
	else
	  {
	    a_normal_exp = b_normal_exp;
	    a_fraction = 0;
	  }
      }

    if (a->sign != b->sign)
      {
	if (a->sign)
	  tfraction = -a_fraction + b_fraction;
	else
	  tfraction = a_fraction - b_fraction;

	if (tfraction >= 0)
	  {
	    tmp->sign = 0;
	    tmp->normal_exp = a_normal_exp;
	    tmp->fraction.ll = tfraction;
	  }
	else
	  {
	    tmp->sign = 1;
	    tmp->normal_exp = a_normal_exp;
	    tmp->fraction.ll = -tfraction;
	  }
	while (tmp->fraction.ll < IMPLICIT_1 && tmp->fraction.ll)
	  {
	    tmp->fraction.ll <<= 1;
	    tmp->normal_exp--;
	  }
      }
    else
      {
	tmp->sign = a->sign;
	tmp->normal_exp = a_normal_exp;
	tmp->fraction.ll = a_fraction + b_fraction;
      }

    tmp->class = CLASS_NUMBER;

    if (tmp->fraction.ll >= IMPLICIT_2)
      {
	LSHIFT (tmp->fraction.ll);
	tmp->normal_exp++;
      }
    return tmp;
  }
}
