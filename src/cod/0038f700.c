/* ee-2.9-991111 matched TU. */

typedef unsigned int unsigned32;

struct Bigint {
    struct Bigint *next;   /* 0x00 */
    int k;                 /* 0x04 */
    int maxwds;            /* 0x08 */
    short on_stack;        /* 0x0C */
    short sign;            /* 0x0E */
    int wds;               /* 0x10 */
    unsigned32 x[8];       /* 0x14 */
};

typedef struct Bigint Bigint;

extern Bigint *Brealloc(Bigint *b, int k);
#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
#define Sign_Extend(a,b) /*no-op*/
typedef int _G_int32_t;

extern Bigint *multadd(Bigint *b, int m, int a);

/* libio floatconv.c :: s2b */
__attribute__((section(".text.func_0038F700")))
Bigint *func_0038F700(Bigint *result, const char *s, int nd0, int nd, unsigned32 y9) {
  int i, k;
  _G_int32_t x, y;

  x = (nd + 8) / 9;
  for(k = 0, y = 1; x > y; y <<= 1, k++) ;
  result = Brealloc(result, k);
  result->x[0] = y9;
  result->wds = 1;

  i = 9;
  if (9 < nd0)
    {
      s += 9;
      do
        result = multadd(result, 10, *s++ - '0');
      while (++i < nd0);
      s++;
    }
  else
    s += 10;
  for(; i < nd; i++)
    result = multadd(result, 10, *s++ - '0');
  return result;
}
