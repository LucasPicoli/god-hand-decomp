/* ee-2.9-991111 matched TU. */

extern int D_00452B48;
extern int D_00454D38;
extern void func_0031EC48(float *, void *);
extern double func_0031EAB0(int, unsigned int, int, unsigned long long);
extern void func_0031EEC8(void *a, void *b);
extern int D_00460DB0;
extern int D_0045D388;
extern void func_003B1EE0(void *buf, int size, int a, int b);
extern void func_0039C390(int a0, void *buf);

__attribute__((section(".text.func_0032DC90")))
int func_0032DC90(char *a0) {
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(&D_00452B48);
        return -1;
    }
    return *(char *)(a0 + 1);
}

__attribute__((section(".text.func_00335AD8")))
int func_00335AD8(char *a0) {
    if (a0 == 0) {
        func_00335D40(&D_00454D38);
        return -1;
    }
    return *(char *)(a0 + 1);
}

typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef int SItype;
typedef short HItype;

typedef struct {
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union { SItype ll; HItype l[2]; } fraction;
} fp_number_type_sf;




__attribute__((section(".text.func_0031EDD0")))
double func_0031EDD0(float arg_a)
{
  fp_number_type_sf in;
  func_0031EC48(&arg_a, &in);
  return func_0031EAB0(in.class, in.sign, in.normal_exp, (unsigned long long)(unsigned int)in.fraction.ll << 30);
}

__attribute__((section(".text.func_0038C168")))
void *func_0038C168(void)
{
    if (D_00460DB0 == 0) {
        func_0031EEC8(&D_00460DB0, &D_0045D388);
    }
    return &D_00460DB0;
}

__attribute__((section(".text.func_0039C3E8")))
void func_0039C3E8(int a0, int a1, int a2)
{
    char buf[0x100];
    func_003B1EE0(buf, 0x100, a1, a2);
    func_0039C390(a0, buf);
}
