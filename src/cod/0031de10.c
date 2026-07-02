/* ee-2.9-991111 matched TU. */

/* __muldi3 — gcc-2.95.2 libgcc2.c L_muldi3 shape; umul_ppmm from godhand/mul64.h. */
#include "godhand/mul64.h"
typedef long long           DItype;
typedef unsigned long long  UDItype;
typedef int                 SItype;
typedef unsigned int        USItype;

struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

#define __umulsidi3(u, v) \
  ({DIunion __w;							\
    umul_ppmm (__w.s.high, __w.s.low, u, v);				\
    __w.ll; })

__attribute__((section(".text.func_0031DE10")))
DItype func_0031DE10(DItype u, DItype v)
{
  DIunion w;
  DIunion uu, vv;

  uu.ll = u,
  vv.ll = v;

  w.ll = __umulsidi3 (uu.s.low, vv.s.low);
  w.s.high += ((USItype) uu.s.low * (USItype) vv.s.high
	       + (USItype) uu.s.high * (USItype) vv.s.low);

  return w.ll;
}
