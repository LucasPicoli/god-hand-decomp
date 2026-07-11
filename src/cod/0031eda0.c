/* sn-2.95.3-136 matched TU. */

extern void *(*D_003C490C)(void);
extern int type_info___eq(void *self, void *arg);
extern float func_0031EB38(void *);

__attribute__((section(".text.func_00320338")))
void *func_00320338(void)
{
  return (*D_003C490C)();
}

__attribute__((section(".text.func_0031F460")))
int func_0031F460(void *self, void *arg)
{
  return type_info___eq(self, arg) ^ 1;
}

typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef int SItype;
typedef unsigned int USItype;
typedef short HItype;
typedef struct {
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union { SItype ll; HItype l[2]; } fraction;
} fp_number_type;

__attribute__((section(".text.func_0031EDA0")))
float func_0031EDA0(fp_class_type class, unsigned int sign, int exp, USItype frac)
{
  fp_number_type in;
  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return func_0031EB38(&in);
}
