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

/* libio floatconv.c :: i2b */
__attribute__((section(".text.func_0038F980")))
Bigint *func_0038F980(Bigint* result, int i) {
  result = Brealloc(result, 1);
  result->x[0] = i;
  result->wds = 1;
  return result;
}
