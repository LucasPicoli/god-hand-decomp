/* ee-2.9-991111 matched TU. */

extern void *__frame_state_for(void *pc_target, void *state_in);
extern long long *func_00320948(int col, void *a1, int a2);
extern void _dispRefImage(void *, int, int);
extern void _dispRefImageField(void *, int, int, int);
extern int SignalSema(int);
extern int D_003F86C0;
extern int D_003F9810;
extern int D_003F8668;
extern void *GetD003F8560_395388(void);
extern void func_003B06D8(int a);
extern int RemoveIntcHandler(int a, int b);
extern int AddIntcHandler(int a, void *b, int c);
extern void func_003B0740(int a);
extern double func_0031DE78(void *);

typedef struct {
    int cfa;
    int eh_ptr;
    long long cfa_offset;
    long long args_size;
    long long reg_or_offset[80];
    unsigned short cfa_reg;
    unsigned short retaddr_column;
    char saved[80];
} frame_state;




__attribute__((section(".text.func_00320A50")))
frame_state *func_00320A50(void *a0, frame_state *a1, frame_state *a2)
{
    frame_state *s0;
    frame_state *s1;
    unsigned short col;

    s1 = a1;
    s0 = __frame_state_for(a0, a2);
    if (!s0) return 0;

    col = s0->cfa_reg;
    if (s1->saved[col]) {
        long long *p;
        long long val;
        p = func_00320948(col, s1, 0);
        val = *p;
        *(int *)s0 = (int)val;
    } else {
        *(int *)s0 = *(int *)s1;
    }
    *(int *)s0 += *((int *)s0 + 2);
    return s0;
}

__attribute__((section(".text.func_0039B8D0")))
void func_0039B8D0(void *a0, int a1, int a2, int a3)
{
    void *s0;
    int v0, v1, sa1, sa2;
    s0 = a0;
    if (a2 != 0) {
        v0 = *(int *)((char *)s0 + 0x184);
        if (v0 == 3) {
            v0 = *(int *)((char *)s0 + 0x160);
            if (v0 == 3) {
                sa1 = *(int *)((char *)s0 + 0x1D4);
            } else {
                sa1 = *(int *)((char *)s0 + 0x1C8);
            }
            _dispRefImage(s0, sa1, a1 - 1);
        } else {
            v0 = *(int *)((char *)s0 + 0x160);
            if (v0 == 3) {
                sa1 = *(int *)((char *)s0 + 0x1E4);
                sa2 = *(int *)((char *)s0 + 0x1F4);
            } else {
                sa1 = *(int *)((char *)s0 + 0x1D8);
                sa2 = *(int *)((char *)s0 + 0x1E8);
            }
            _dispRefImageField(s0, sa1, sa2, a1 - 1);
        }
    }
    v1 = *(int *)((char *)s0 + 0x108);
    if (v1 == 1) {
        *(int *)((char *)s0 + 0x108) = 2;
    }
}

__attribute__((section(".text.func_00398D08")))
int func_00398D08(void) {
    int s0;
    int v0;

    v0 = func_00398BB0(2);
    if (v0 == 0) {
        return 0;
    }

    s0 = (int)&D_003F86C0;

    v0 = func_003B3128((int)&D_003F9810, 0xE, 0, 0, 0, s0, 4, 0, 0);

    if (v0 < 0) {
        SignalSema(D_003F8668);
        return 0;
    }

    s0 = *(int *)((s0 | 0x20000000) + 0);
    SignalSema(D_003F8668);
    return s0;
}

__attribute__((section(".text.func_00395F68")))
int func_00395F68(void *handler) {
    void *s0;
    void *s1;
    int s2;

    s1 = handler;
    s0 = GetD003F8560_395388();
    s2 = *(int *)((char *)s0 + 8);

    if (s1 == 0) {
        func_003B06D8(2);
        RemoveIntcHandler(2, *(int *)((char *)s0 + 0xC));
        *(int *)((char *)s0 + 0xC) = 0;
        *(int *)((char *)s0 + 8) = 0;
    } else {
        if (s2 != 0) {
            func_003B06D8(2);
            RemoveIntcHandler(2, *(int *)((char *)s0 + 0xC));
        }
        *(int *)((char *)s0 + 8) = (int)s1;
        *(int *)((char *)s0 + 0xC) = AddIntcHandler(2, s1, -1);
        func_003B0740(2);
    }
    return s2;
}

typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef long long DItype;
typedef unsigned long long UDItype;
typedef int SItype;
typedef struct {
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union { UDItype ll; SItype l[2]; } fraction;
} fp_number_type;



__attribute__((section(".text.func_0031E8C0")))
double func_0031E8C0(SItype arg_a)
{
  fp_number_type in;

  in.class = CLASS_NUMBER;
  in.sign = arg_a < 0;
  if (!arg_a)
    {
      in.class = CLASS_ZERO;
    }
  else
    {
      in.normal_exp = 52 + 8;
      if (in.sign)
        {
          if (arg_a == (SItype) 0x80000000)
            {
              return -2147483648.0;
            }
          in.fraction.ll = (-arg_a);
        }
      else
        in.fraction.ll = arg_a;

      while (in.fraction.ll < (1ULL << (52 + 8)))
        {
          in.fraction.ll <<= 1;
          in.normal_exp -= 1;
        }
    }
  return func_0031DE78(&in);
}
