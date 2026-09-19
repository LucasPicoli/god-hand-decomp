/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111; libgcc fp-bit.c :: float_to_usi (double variant, gofast dptoul). Style of src/cod/0031e978.c. */

typedef unsigned long fractype;

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
#define FRACBITS 52
#define NGARDS 8L
#define MAX_USI_INT  ((unsigned int) ~0)

extern void func_0031DFA8 (long long *, fp_number_type *);   /* unpack_d */

__attribute__((section(".text.func_0031EA10")))
unsigned int
func_0031EA10 (long long arg_a)
{
  fp_number_type a;

  func_0031DFA8 (&arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* it is a negative number */
  if (a.sign)
    return 0;
  /* get reasonable MAX_USI_INT... */
  if (isinf (&a))
    return MAX_USI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 31)
    return MAX_USI_INT;
  else if (a.normal_exp > (FRACBITS + NGARDS))
    return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
  else
    return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}
