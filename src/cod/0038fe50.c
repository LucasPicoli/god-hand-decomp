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

extern int cmp(Bigint *a, Bigint *b);

/* libio floatconv.c :: diff -- c = a - b */
__attribute__((section(".text.func_0038FE50")))
Bigint *func_0038FE50(Bigint *c, Bigint *a, Bigint *b) {
        int i, wa, wb;
        _G_int32_t borrow, y;
        unsigned32 *xa, *xae, *xb, *xbe, *xc;
        _G_int32_t z;

        i = cmp(a,b);
        if (!i) {
                c = Brealloc(c, 0);
                c->wds = 1;
                c->x[0] = 0;
                return c;
                }
        if (i < 0) {
                Bigint *tmp = a;
                a = b;
                b = tmp;
                i = 1;
                }
        else
                i = 0;
        c = Brealloc(c, a->k);
        c->sign = i;
        wa = a->wds;
        xa = a->x;
        xae = xa + wa;
        wb = b->wds;
        xb = b->x;
        xbe = xb + wb;
        xc = c->x;
        borrow = 0;
        do {
                y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
                borrow = y >> 16;
                Sign_Extend(borrow, y);
                z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
                borrow = z >> 16;
                Sign_Extend(borrow, z);
                Storeinc(xc, z, y);
                }
                while(xb < xbe);
        while(xa < xae) {
                y = (*xa & 0xffff) + borrow;
                borrow = y >> 16;
                Sign_Extend(borrow, y);
                z = (*xa++ >> 16) + borrow;
                borrow = z >> 16;
                Sign_Extend(borrow, z);
                Storeinc(xc, z, y);
                }
        while(!*--xc)
                wa--;
        c->wds = wa;
        return c;
        }
