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

#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, \
((unsigned short *)a)[0] = (unsigned short)c, a++)
#define Sign_Extend(a,b) /*no-op*/

typedef int _G_int32_t;

extern int cmp(Bigint *a, Bigint *b);

/* libio floatconv.c :: quorem */
__attribute__((section(".text.func_00391340")))
int func_00391340(Bigint *b, Bigint *S) {
        int n;
        _G_int32_t borrow, y;
        unsigned32 carry, q, ys;
        unsigned32 *bx, *bxe, *sx, *sxe;
        _G_int32_t z;
        unsigned32 si, zs;

        n = S->wds;
        if (b->wds < n)
                return 0;
        sx = S->x;
        sxe = sx + --n;
        bx = b->x;
        bxe = bx + n;
        q = *bxe / (*sxe + 1);  /* ensure q <= true quotient */
        if (q) {
                borrow = 0;
                carry = 0;
                do {
                        si = *sx++;
                        ys = (si & 0xffff) * q + carry;
                        zs = (si >> 16) * q + (ys >> 16);
                        carry = zs >> 16;
                        y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
                        borrow = y >> 16;
                        Sign_Extend(borrow, y);
                        z = (*bx >> 16) - (zs & 0xffff) + borrow;
                        borrow = z >> 16;
                        Sign_Extend(borrow, z);
                        Storeinc(bx, z, y);
                        }
                        while(sx <= sxe);
                if (!*bxe) {
                        bx = b->x;
                        while(--bxe > bx && !*bxe)
                                --n;
                        b->wds = n;
                        }
                }
        if (cmp(b, S) >= 0) {
                q++;
                borrow = 0;
                carry = 0;
                bx = b->x;
                sx = S->x;
                do {
                        si = *sx++;
                        ys = (si & 0xffff) + carry;
                        zs = (si >> 16) + (ys >> 16);
                        carry = zs >> 16;
                        y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
                        borrow = y >> 16;
                        Sign_Extend(borrow, y);
                        z = (*bx >> 16) - (zs & 0xffff) + borrow;
                        borrow = z >> 16;
                        Sign_Extend(borrow, z);
                        Storeinc(bx, z, y);
                        }
                        while(sx <= sxe);
                bx = b->x;
                bxe = bx + n;
                if (!*bxe) {
                        while(--bxe > bx && !*bxe)
                                --n;
                        b->wds = n;
                        }
                }
        return q;
        }
