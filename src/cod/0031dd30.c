/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — gcc-2.95.2 libgcc2.c L_floatdisf, verbatim with the macros resolved
   (DI_SIZE 64, DF_SIZE 53, SF_SIZE 24, WORD_SIZE 32). */
typedef long long          DItype;
typedef unsigned long long UDItype;
typedef int                SItype;
typedef unsigned int       USItype;
typedef double             DFtype;
typedef float              SFtype;

#define WORD_SIZE 32
#define HIGH_HALFWORD_COEFF (((UDItype) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((UDItype) 1) << WORD_SIZE)
#define DF_SIZE 53
#define REP_BIT ((USItype) 1 << 11)

__attribute__((section(".text.__floatdisf")))
SFtype __floatdisf (DItype u)
{
  DFtype f;

  if (! (- ((DItype) 1 << DF_SIZE) < u
         && u < ((DItype) 1 << DF_SIZE)))
    {
      if ((USItype) u & (REP_BIT - 1))
        u |= REP_BIT;
    }
  f = (SItype) (u >> WORD_SIZE);
  f *= HIGH_HALFWORD_COEFF;
  f *= HIGH_HALFWORD_COEFF;
  f += (USItype) (u & (HIGH_WORD_COEFF - 1));

  return (SFtype) f;
}
