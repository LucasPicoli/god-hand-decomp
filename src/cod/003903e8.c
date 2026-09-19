/* ee-2.9-991111 matched TU. */

/* libio floatconv.c -- transcribed verbatim from gcc-2.95.2 libio.
 * Config block resolved for MIPSEL / IEEE_8087 exactly as the vendor build did. */

typedef unsigned int unsigned32;
typedef int _G_int32_t;
#define CONST const
#define NULL 0

union doubleword {
  double d;
  unsigned32 u[2];
};

#define IEEE_8087
#define HIWORD 1
#define LOWORD 0
#define TEST_ENDIANNESS  /* nothing */

#define word0(x) ({ union doubleword _du; _du.d = (x); _du.u[HIWORD]; })
#define word1(x) ({ union doubleword _du; _du.d = (x); _du.u[LOWORD]; })
#define setword0(D,W) \
  ({ union doubleword _du; _du.d = (D); _du.u[HIWORD]=(W); (D)=_du.d; })
#define setword1(D,W) \
  ({ union doubleword _du; _du.d = (D); _du.u[LOWORD]=(W); (D)=_du.d; })
#define setwords(D,HW,LW) ({ union doubleword _du; \
  _du.u[HIWORD]=(HW); _du.u[LOWORD]=(LW); (D)=_du.d; })
#define addword0(D,W) \
  ({ union doubleword _du; _du.d = (D); _du.u[HIWORD]+=(W); (D)=_du.d; })

#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, \
((unsigned short *)a)[0] = (unsigned short)c, a++)

#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1    0x100000
#define Exp_msk11   0x100000
#define Exp_mask  0x7ff00000
#define P 53
#define Bias 1023
#define IEEE_Arith
#define Emin (-1022)
#define Exp_1  0x3ff00000
#define Exp_11 0x3ff00000
#define Ebits 11
#define Frac_mask  0xfffff
#define Frac_mask1 0xfffff
#define Ten_pmax 22
#define Bletch 0x10
#define Bndry_mask  0xfffff
#define Bndry_mask1 0xfffff
#define LSB 1
#define Sign_bit 0x80000000
#define Log2P 1
#define Tiny0 0
#define Tiny1 1
#define Quick_max 14
#define Int_max 14
#define Infinite(x) (word0(x) == 0x7ff00000)

#define rounded_product(a,b) a *= b
#define rounded_quotient(a,b) a /= b

#define Big0 (Frac_mask1 | Exp_msk1*(1024+Bias-1))
#define Big1 0xffffffff
#define Kmax 15
#define BIGINT_MINIMUM_K 3

struct Bigint {
  struct Bigint *next;
  int k;
  int maxwds;
  short on_stack;
  short sign;
  int wds;
  unsigned32 x[1<<BIGINT_MINIMUM_K];
};

#define BIGINT_HEADER_SIZE \
  (sizeof(Bigint) - (1<<BIGINT_MINIMUM_K) * sizeof(unsigned32))

typedef struct Bigint Bigint;

/* The floatconv rodata tables, already in retail. */
extern CONST double D_0045D890[];      /* tens[]     */
extern CONST double D_0045D948[];      /* bigtens[]  */
extern CONST double D_0045D970[];      /* tinytens[] */
#define tens D_0045D890
#define bigtens D_0045D948
#define tinytens D_0045D970
#define n_bigtens 5

/* The floatconv helpers, already carved in this repository. */
extern Bigint *Binit(Bigint *b);
extern Bigint *Balloc(int k);
extern void func_0038F548(Bigint *v);
extern void Bcopy(Bigint *x, Bigint *y);
extern Bigint *Brealloc(Bigint *b, int k);
extern Bigint *multadd(Bigint *b, int m, int a);
extern Bigint *func_0038F700(Bigint *result, CONST char *s, int nd0, int nd, unsigned32 y9);
extern int hi0bits(register unsigned32 x);
extern int lo0bits(unsigned32 *y);
extern Bigint *func_0038F980(Bigint *result, int i);
extern Bigint *func_0038F9B8(Bigint *c, Bigint *a, Bigint *b);
extern Bigint *pow5mult(Bigint *b, int k);
extern Bigint *func_0038FC68(Bigint *b, int k);
extern int cmp(Bigint *a, Bigint *b);
extern Bigint *func_0038FE50(Bigint *c, Bigint *a, Bigint *b);
extern double ulp(double x);
extern double b2d(Bigint *a, int *e);
extern Bigint *d2b(Bigint *result, double d, _G_int32_t *e, _G_int32_t *bits);
extern double ratio(Bigint *a, Bigint *b);
extern int func_00391340(Bigint *b, Bigint *S);

#define Bfree   func_0038F548
#define s2b     func_0038F700
#define i2b     func_0038F980
#define mult    func_0038F9B8
#define lshift  func_0038FC68
#define diff    func_0038FE50
#define quorem  func_00391340

/* dtoa's two function-scope statics live in retail's own .data/.bss. */
extern Bigint *D_003F5178;      /* result   */
extern int D_0077C080;          /* result_k */
#define result   D_003F5178
#define result_k D_0077C080

/* strtod's errno and its limits. */
extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define ERANGE 34
#define DBL_DIG 15
#define DBL_MAX_10_EXP 308
#define Sign_Extend(a,b) /*no-op*/
#define FLT_ROUNDS 1
#define FLT_RADIX 2
#define DBL_MAX_EXP 1024

extern CONST double D_0045EA00;  /* +Infinity, retail's HUGE_VAL */

 double
__attribute__((section(".text.func_003903E8")))
func_003903E8 (CONST char *s00, char **se)
{
        _G_int32_t bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign,
                 e, e1, esign, i, j, k, nd, nd0, nf, nz, nz0, sign;
        CONST char *s, *s0, *s1;
        double aadj, aadj1, adj, rv, rv0;
        _G_int32_t L;
        unsigned32 y, z;
	Bigint _bb, _b_avail, _bd, _bd0, _bs, _delta;
	Bigint *bb = Binit(&_bb);
	Bigint *bd = Binit(&_bd);
	Bigint *bd0 = Binit(&_bd0);
	Bigint *bs = Binit(&_bs);
	Bigint *b_avail = Binit(&_b_avail);
	Bigint *delta = Binit(&_delta);

	TEST_ENDIANNESS;
        sign = nz0 = nz = 0;
        rv = 0.;
	(void)&rv;		/* Force rv into the stack */
        for(s = s00;;s++) switch(*s) {
                case '-':
                        sign = 1;
                        /* no break */
                case '+':
                        if (*++s)
                                goto break2;
                        /* no break */
                case 0:
			/* "+" and "-" should be reported as an error? */
			sign = 0;
			s = s00;
                        goto ret;
                case '\t':
                case '\n':
                case '\v':
                case '\f':
                case '\r':
                case ' ':
                        continue;
                default:
                        goto break2;
                }
 break2:
        if (*s == '0') {
                nz0 = 1;
                while(*++s == '0') ;
                if (!*s)
                        goto ret;
                }
        s0 = s;
        y = z = 0;
        for(nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
                if (nd < 9)
                        y = 10*y + c - '0';
                else if (nd < 16)
                        z = 10*z + c - '0';
        nd0 = nd;
        if (c == '.') {
                c = *++s;
                if (!nd) {
                        for(; c == '0'; c = *++s)
                                nz++;
                        if (c > '0' && c <= '9') {
                                s0 = s;
                                nf += nz;
                                nz = 0;
                                goto have_dig;
                                }
                        goto dig_done;
                        }
                for(; c >= '0' && c <= '9'; c = *++s) {
 have_dig:
                        nz++;
                        if (c -= '0') {
                                nf += nz;
                                for(i = 1; i < nz; i++)
                                        if (nd++ < 9)
                                                y *= 10;
                                        else if (nd <= DBL_DIG + 1)
                                                z *= 10;
                                if (nd++ < 9)
                                        y = 10*y + c;
                                else if (nd <= DBL_DIG + 1)
                                        z = 10*z + c;
                                nz = 0;
                                }
                        }
                }
 dig_done:
        e = 0;
        if (c == 'e' || c == 'E') {
                if (!nd && !nz && !nz0) {
                        s = s00;
                        goto ret;
                        }
                s00 = s;
                esign = 0;
                switch(c = *++s) {
                        case '-':
                                esign = 1;
                        case '+':
                                c = *++s;
                        }
                if (c >= '0' && c <= '9') {
                        while(c == '0')
                                c = *++s;
                        if (c > '0' && c <= '9') {
                                e = c - '0';
                                s1 = s;
                                while((c = *++s) >= '0' && c <= '9')
                                        e = 10*e + c - '0';
                                if (s - s1 > 8)
                                        /* Avoid confusion from exponents
                                         * so large that e might overflow.
                                         */
                                        e = 9999999;
                                if (esign)
                                        e = -e;
                                }
                        else
                                e = 0;
                        }
                else
                        s = s00;
                }
        if (!nd) {
                if (!nz && !nz0)
                        s = s00;
                goto ret;
                }
        e1 = e -= nf;

        /* Now we have nd0 digits, starting at s0, followed by a
         * decimal point, followed by nd-nd0 digits.  The number we're
         * after is the integer represented by those digits times
         * 10**e */

        if (!nd0)
                nd0 = nd;
        k = nd < DBL_DIG + 1 ? nd : DBL_DIG + 1;
        rv = y;
        if (k > 9)
                rv = tens[k - 9] * rv + z;
        if (nd <= DBL_DIG
#ifndef RND_PRODQUOT
                && FLT_ROUNDS == 1
#endif
                        ) {
                if (!e)
                        goto ret;
                if (e > 0) {
                        if (e <= Ten_pmax) {
#ifdef VAX
                                goto vax_ovfl_check;
#else
                                /* rv = */ rounded_product(rv, tens[e]);
                                goto ret;
#endif
                                }
                        i = DBL_DIG - nd;
                        if (e <= Ten_pmax + i) {
                                /* A fancier test would sometimes let us do
                                 * this for larger i values.
                                 */
                                e -= i;
                                rv *= tens[i];
#ifdef VAX
                                /* VAX exponent range is so narrow we must
                                 * worry about overflow here...
                                 */
 vax_ovfl_check:
                                addword0(rv, - P*Exp_msk1);
                                /* rv = */ rounded_product(rv, tens[e]);
                                if ((word0(rv) & Exp_mask)
                                 > Exp_msk1*(DBL_MAX_EXP+Bias-1-P))
                                        goto ovfl;
                                addword0(rv, P*Exp_msk1);
#else
                                /* rv = */ rounded_product(rv, tens[e]);
#endif
                                goto ret;
                                }
                        }
#ifndef Inaccurate_Divide
                else if (e >= -Ten_pmax) {
                        /* rv = */ rounded_quotient(rv, tens[-e]);
                        goto ret;
                        }
#endif
                }
        e1 += nd - k;

        /* Get starting approximation = rv * 10**e1 */

        if (e1 > 0) {
                if ((i = e1 & 15))
                        rv *= tens[i];
                if (e1 &= ~15) {
                        if (e1 > DBL_MAX_10_EXP) {
 ovfl:
                                errno = ERANGE;
#if defined(sun) && !defined(__svr4__)
/* SunOS defines HUGE_VAL as __infinity(), which is in libm. */
#undef HUGE_VAL
#endif
#ifndef HUGE_VAL
/* RETAIL loads 0x7FF0000000000000 -- +Infinity -- from the split rodata blob
   at 0x0045EA00, which is what <math.h> HUGE_VAL expands to. The DBL_MAX
   fallback 1.7976931348623157E+308 is a DIFFERENT value and it also makes the
   TU emit its own .rodata copy. Read off --link-check's relocation join. */
#define HUGE_VAL        D_0045EA00
#endif
                                rv = HUGE_VAL;
                                goto ret;
                                }
                        if (e1 >>= 4) {
                                for(j = 0; e1 > 1; j++, e1 >>= 1)
                                        if (e1 & 1)
                                                rv *= bigtens[j];
                        /* The last multiplication could overflow. */
                                addword0(rv, -P*Exp_msk1);
                                rv *= bigtens[j];
                                if ((z = word0(rv) & Exp_mask)
                                 > Exp_msk1*(DBL_MAX_EXP+Bias-P))
                                        goto ovfl;
                                if (z > Exp_msk1*(DBL_MAX_EXP+Bias-1-P)) {
                                        /* set to largest number */
                                        /* (Can't trust DBL_MAX) */
                                        setwords(rv, Big0, Big1);
                                        }
                                else
                                        addword0(rv, P*Exp_msk1);
                                }

                        }
                }
        else if (e1 < 0) {
                e1 = -e1;
                if ((i = e1 & 15))
                        rv /= tens[i];
                if (e1 &= ~15) {
                        e1 >>= 4;
                        for(j = 0; e1 > 1; j++, e1 >>= 1)
                                if (e1 & 1)
                                        rv *= tinytens[j];
                        /* The last multiplication could underflow. */
                        rv0 = rv;
                        rv *= tinytens[j];
                        if (!rv) {
                                rv = 2.*rv0;
                                rv *= tinytens[j];
                                if (!rv) {
 undfl:
                                        rv = 0.;
                                        errno = ERANGE;
                                        goto ret;
                                        }
                                setwords(rv, Tiny0, Tiny1);
                                /* The refinement below will clean
                                 * this approximation up.
                                 */
                                }
                        }
                }

        /* Now the hard part -- adjusting rv to the correct value.*/

        /* Put digits into bd: true value = bd * 10^e */

        bd0 = s2b(bd0, s0, nd0, nd, y);
	bd = Brealloc(bd, bd0->k);

        for(;;) {
                Bcopy(bd, bd0);
                bb = d2b(bb, rv, &bbe, &bbbits);    /* rv = bb * 2^bbe */
                bs = i2b(bs, 1);

                if (e >= 0) {
                        bb2 = bb5 = 0;
                        bd2 = bd5 = e;
                        }
                else {
                        bb2 = bb5 = -e;
                        bd2 = bd5 = 0;
                        }
                if (bbe >= 0)
                        bb2 += bbe;
                else
                        bd2 -= bbe;
                bs2 = bb2;
#ifdef Sudden_Underflow
#ifdef IBM
                j = 1 + 4*P - 3 - bbbits + ((bbe + bbbits - 1) & 3);
#else
                j = P + 1 - bbbits;
#endif
#else
                i = bbe + bbbits - 1;   /* logb(rv) */
                if (i < Emin)   /* denormal */
                        j = bbe + (P-Emin);
                else
                        j = P + 1 - bbbits;
#endif
                bb2 += j;
                bd2 += j;
                i = bb2 < bd2 ? bb2 : bd2;
                if (i > bs2)
                        i = bs2;
                if (i > 0) {
                        bb2 -= i;
                        bd2 -= i;
                        bs2 -= i;
                        }
                if (bb5 > 0) {
			Bigint *b_tmp;
                        bs = pow5mult(bs, bb5);
                        b_tmp = mult(b_avail, bs, bb);
                        b_avail = bb;
                        bb = b_tmp;
                        }
                if (bb2 > 0)
                        bb = lshift(bb, bb2);
                if (bd5 > 0)
                        bd = pow5mult(bd, bd5);
                if (bd2 > 0)
                        bd = lshift(bd, bd2);
                if (bs2 > 0)
                        bs = lshift(bs, bs2);
                delta = diff(delta, bb, bd);
                dsign = delta->sign;
                delta->sign = 0;
                i = cmp(delta, bs);
                if (i < 0) {
                        /* Error is less than half an ulp -- check for
                         * special case of mantissa a power of two.
                         */
                        if (dsign || word1(rv) || word0(rv) & Bndry_mask)
                                break;
                        delta = lshift(delta,Log2P);
                        if (cmp(delta, bs) > 0)
                                goto drop_down;
                        break;
                        }
                if (i == 0) {
                        /* exactly half-way between */
                        if (dsign) {
                                if ((word0(rv) & Bndry_mask1) == Bndry_mask1
                                 &&  word1(rv) == 0xffffffff) {
                                        /*boundary case -- increment exponent*/
                                        setword0(rv, (word0(rv) & Exp_mask)
						 + Exp_msk1);
#ifdef IBM
                                        setword0 (rv,
						  word0(rv) | (Exp_msk1 >> 4));
#endif
                                        setword1(rv, 0);
                                        break;
                                        }
                                }
                        else if (!(word0(rv) & Bndry_mask) && !word1(rv)) {
 drop_down:
                                /* boundary case -- decrement exponent */
#ifdef Sudden_Underflow
                                L = word0(rv) & Exp_mask;
#ifdef IBM
                                if (L <  Exp_msk1)
#else
                                if (L <= Exp_msk1)
#endif
                                        goto undfl;
                                L -= Exp_msk1;
#else
                                L = (word0(rv) & Exp_mask) - Exp_msk1;
#endif
                                setwords(rv, L | Bndry_mask1, 0xffffffff);
#ifdef IBM
                                continue;
#else
                                break;
#endif
                                }
#ifndef ROUND_BIASED
                        if (!(word1(rv) & LSB))
                                break;
#endif
                        if (dsign)
                                rv += ulp(rv);
#ifndef ROUND_BIASED
                        else {
                                rv -= ulp(rv);
#ifndef Sudden_Underflow
                                if (!rv)
                                        goto undfl;
#endif
                                }
#endif
                        break;
                        }
                if ((aadj = ratio(delta, bs)) <= 2.) {
                        if (dsign)
                                aadj = aadj1 = 1.;
                        else if (word1(rv) || word0(rv) & Bndry_mask) {
#ifndef Sudden_Underflow
                                if (word1(rv) == Tiny1 && !word0(rv))
                                        goto undfl;
#endif
                                aadj = 1.;
                                aadj1 = -1.;
                                }
                        else {
                                /* special case -- power of FLT_RADIX to be */
                                /* rounded down... */

                                if (aadj < 2./FLT_RADIX)
                                        aadj = 1./FLT_RADIX;
                                else
                                        aadj *= 0.5;
                                aadj1 = -aadj;
                                }
                        }
                else {
                        aadj *= 0.5;
                        aadj1 = dsign ? aadj : -aadj;
#ifdef Check_FLT_ROUNDS
                        switch(FLT_ROUNDS) {
                                case 2: /* towards +infinity */
                                        aadj1 -= 0.5;
                                        break;
                                case 0: /* towards 0 */
                                case 3: /* towards -infinity */
                                        aadj1 += 0.5;
                                }
#else
                        if (FLT_ROUNDS == 0)
                                aadj1 += 0.5;
#endif
                        }
                y = word0(rv) & Exp_mask;

                /* Check for overflow */

                if (y == Exp_msk1*(DBL_MAX_EXP+Bias-1)) {
                        rv0 = rv;
                        addword0(rv, - P*Exp_msk1);
                        adj = aadj1 * ulp(rv);
                        rv += adj;
                        if ((word0(rv) & Exp_mask) >=
                                        Exp_msk1*(DBL_MAX_EXP+Bias-P)) {
                                if (word0(rv0) == Big0 && word1(rv0) == Big1)
                                        goto ovfl;
                                setwords(rv, Big0, Big1);
                                continue;
                                }
                        else
                                addword0(rv, P*Exp_msk1);
                        }
                else {
#ifdef Sudden_Underflow
                        if ((word0(rv) & Exp_mask) <= P*Exp_msk1) {
                                rv0 = rv;
                                addword0(rv, P*Exp_msk1);
                                adj = aadj1 * ulp(rv);
                                rv += adj;
#ifdef IBM
                                if ((word0(rv) & Exp_mask) <  P*Exp_msk1)
#else
                                if ((word0(rv) & Exp_mask) <= P*Exp_msk1)
#endif
                                        {
                                        if (word0(rv0) == Tiny0
                                         && word1(rv0) == Tiny1)
                                                goto undfl;
                                        setwords(rv, Tiny0, Tiny1);
                                        continue;
                                        }
                                else
                                        addword0(rv, -P*Exp_msk1);
                                }
                        else {
                                adj = aadj1 * ulp(rv);
                                rv += adj;
                                }
#else
                        /* Compute adj so that the IEEE rounding rules will
                         * correctly round rv + adj in some half-way cases.
                         * If rv * ulp(rv) is denormalized (i.e.,
                         * y <= (P-1)*Exp_msk1), we must adjust aadj to avoid
                         * trouble from bits lost to denormalization;
                         * example: 1.2e-307 .
                         */
                        if (y <= (P-1)*Exp_msk1 && aadj >= 1.) {
                                aadj1 = (double)(int)(aadj + 0.5);
                                if (!dsign)
                                        aadj1 = -aadj1;
                                }
                        adj = aadj1 * ulp(rv);
                        rv += adj;
#endif
                        }
                z = word0(rv) & Exp_mask;
                if (y == z) {
                        /* Can we stop now? */
                        L = (_G_int32_t)aadj;
                        aadj -= L;
                        /* The tolerances below are conservative. */
                        if (dsign || word1(rv) || word0(rv) & Bndry_mask) {
                                if (aadj < .4999999 || aadj > .5000001)
                                        break;
                                }
                        else if (aadj < .4999999/FLT_RADIX)
                                break;
                        }
                }
        Bfree(bb);
        Bfree(bd);
        Bfree(bs);
        Bfree(bd0);
        Bfree(delta);
	Bfree(b_avail);
 ret:
        if (se)
                *se = (char *)s;
        return sign ? -rv : rv;
        }
