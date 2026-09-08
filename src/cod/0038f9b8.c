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

/* libio floatconv.c :: mult -- c = a * b */
__attribute__((section(".text.func_0038F9B8")))
Bigint *func_0038F9B8(Bigint *c, Bigint *a, Bigint *b) {
        int k, wa, wb, wc;
        unsigned32 carry, y, z;
        unsigned32 *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
        unsigned32 z2;
        if (a->wds < b->wds) {
                Bigint *tmp = a;
                a = b;
                b = tmp;
                }
        k = a->k;
        wa = a->wds;
        wb = b->wds;
        wc = wa + wb;
        if (wc > a->maxwds)
                k++;
        c = Brealloc(c, k);
        for(x = c->x, xa = x + wc; x < xa; x++)
                *x = 0;
        xa = a->x;
        xae = xa + wa;
        xb = b->x;
        xbe = xb + wb;
        xc0 = c->x;
        for(; xb < xbe; xb++, xc0++) {
                if ((y = *xb & 0xffff)) {
                        x = xa;
                        xc = xc0;
                        carry = 0;
                        do {
                                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                                carry = z >> 16;
                                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                                carry = z2 >> 16;
                                Storeinc(xc, z2, z);
                                }
                                while(x < xae);
                        *xc = carry;
                        }
                if ((y = *xb >> 16)) {
                        x = xa;
                        xc = xc0;
                        carry = 0;
                        z2 = *xc;
                        do {
                                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                                carry = z >> 16;
                                Storeinc(xc, z, z2);
                                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                                carry = z2 >> 16;
                                }
                                while(x < xae);
                        *xc = z2;
                        }
                }
        for(xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc) ;
        c->wds = wc;
        return c;
        }
