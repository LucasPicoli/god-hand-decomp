#ifndef GODHAND_MUL64_H
#define GODHAND_MUL64_H

/* 64-bit arithmetic primitives for the libgcc DImode family
 * (__muldi3 @ 0x0031DE10, __divdi3/__moddi3/__udivdi3/__umoddi3).
 *
 * gcc 2.9x has no C construct or __builtin that binds MULTU's paired
 * HI:LO result into two 32-bit registers; retail's libgcc 64-bit
 * arithmetic requires exactly the multu + "=l"/"=h" register contract
 * below, so the op lives here as a sanctioned intrinsic macro — same
 * policy as the COP2 ops in vu0.h and the MMI ops in mmi.h
 * (DECISIONS.md D-026/D-027; allowlisted in
 * scripts/checks/inline_asm_staged.py). The cheat rule targets pasted
 * MIPS faking a match in a .c body, not intrinsic macros; .c match
 * files stay fully scanned.
 *
 * The remaining macros are the classic pure-C double-word helpers with
 * the GNU longlong.h contract (names and semantics mirror gcc-2.95.2
 * longlong.h so libgcc-derived sources compile unmodified; only
 * builtin C types are used, so the header has no typedef
 * dependencies).
 *
 * count_leading_zeros() indexes a 256-entry clz table through the
 * token `__clz_tab`. Retail links one static copy of that table per
 * libgcc TU (D_00460418 / D_00460518 / D_00460618 / D_00460718), so a
 * TU using it must alias the token to ITS copy BEFORE including this
 * header:
 *
 *     #define __clz_tab D_00460418
 *     #include "godhand/mul64.h"
 */

#define umul_ppmm(w1, w0, u, v) \
    __asm__ ("multu %2,%3" \
             : "=l" ((unsigned int) (w0)), \
               "=h" ((unsigned int) (w1)) \
             : "d" ((unsigned int) (u)), \
               "d" ((unsigned int) (v)))

#ifndef SI_TYPE_SIZE
#define SI_TYPE_SIZE 32
#endif
#define __BITS4 (SI_TYPE_SIZE / 4)
#define __ll_B (1L << (SI_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((unsigned int) (t) % __ll_B)
#define __ll_highpart(t) ((unsigned int) (t) / __ll_B)

#define add_ssaaaa(sh, sl, ah, al, bh, bl) \
  do {									\
    unsigned int __x;							\
    __x = (al) + (bl);							\
    (sh) = (ah) + (bh) + (__x < (al));					\
    (sl) = __x;								\
  } while (0)

#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
  do {									\
    unsigned int __x;							\
    __x = (al) - (bl);							\
    (sh) = (ah) - (bh) - (__x > (al));					\
    (sl) = __x;								\
  } while (0)

#define __udiv_qrnnd_c(q, r, n1, n0, d) \
  do {									\
    unsigned int __d1, __d0, __q1, __q0;				\
    unsigned int __r1, __r0, __m;					\
    __d1 = __ll_highpart (d);						\
    __d0 = __ll_lowpart (d);						\
									\
    __r1 = (n1) % __d1;							\
    __q1 = (n1) / __d1;							\
    __m = (unsigned int) __q1 * __d0;					\
    __r1 = __r1 * __ll_B | __ll_highpart (n0);				\
    if (__r1 < __m)							\
      {									\
	__q1--, __r1 += (d);						\
	if (__r1 >= (d)) /* i.e. we didn't get carry when adding to __r1 */\
	  if (__r1 < __m)						\
	    __q1--, __r1 += (d);					\
      }									\
    __r1 -= __m;							\
									\
    __r0 = __r1 % __d1;							\
    __q0 = __r1 / __d1;							\
    __m = (unsigned int) __q0 * __d0;					\
    __r0 = __r0 * __ll_B | __ll_lowpart (n0);				\
    if (__r0 < __m)							\
      {									\
	__q0--, __r0 += (d);						\
	if (__r0 >= (d))						\
	  if (__r0 < __m)						\
	    __q0--, __r0 += (d);					\
      }									\
    __r0 -= __m;							\
									\
    (q) = (unsigned int) __q1 * __ll_B | __q0;				\
    (r) = __r0;								\
  } while (0)

#define UDIV_NEEDS_NORMALIZATION 1
#define udiv_qrnnd __udiv_qrnnd_c

extern const unsigned char __clz_tab[];
#define count_leading_zeros(count, x) \
  do {									\
    unsigned int __xr = (x);						\
    unsigned int __a;							\
									\
    if (SI_TYPE_SIZE <= 32)						\
      {									\
	__a = __xr < ((unsigned int)1<<2*__BITS4)			\
	  ? (__xr < ((unsigned int)1<<__BITS4) ? 0 : __BITS4)		\
	  : (__xr < ((unsigned int)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);\
      }									\
    else								\
      {									\
	for (__a = SI_TYPE_SIZE - 8; __a > 0; __a -= 8)			\
	  if (((__xr >> __a) & 0xff) != 0)				\
	    break;							\
      }									\
									\
    (count) = SI_TYPE_SIZE - (__clz_tab[__xr >> __a] + __a);		\
  } while (0)

#endif /* GODHAND_MUL64_H */
