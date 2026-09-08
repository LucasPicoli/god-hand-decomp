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

/* libio floatconv.c :: lshift */
__attribute__((section(".text.func_0038FC68")))
Bigint *func_0038FC68(Bigint *b, int k) {
    int i;
    unsigned32 *x, *x1, *xe;
    int old_wds = b->wds;
    int n = k >> 5;
    int k1 = b->k;
    int n1 = n + old_wds + 1;

    if (k == 0)
        return b;

    for (i = b->maxwds; n1 > i; i <<= 1)
        k1++;
    b = Brealloc(b, k1);

    xe = b->x;          /* Source limit */
    x = xe + old_wds;   /* Source pointer */
    x1 = x + n;         /* Destination pointer */
    if (k &= 0x1f) {
        int k1 = 32 - k;
        unsigned32 z = *--x;
        if ((*x1 = (z >> k1)) != 0) {
            ++n1;
        }
        while (x > xe) {
            unsigned32 w = *--x;
            *--x1 = (z << k) | (w >> k1);
            z = w;
        }
        *--x1 = z << k;
    } else
        do {
            *--x1 = *--x;
        } while (x > xe);
    while (x1 > xe)
        *--x1 = 0;
    b->wds = n1 - 1;
    return b;
}
