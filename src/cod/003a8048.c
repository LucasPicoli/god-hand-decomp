/* sn-2.95.3-136 matched TU. */

extern int GetThreadId(void);
extern int WaitSema(int sema);
extern int SignalSema(int sema);

/* SCE newlib __malloc_lock (0x003A8048). */



extern int D_003FA990;   /* owner thread id */
extern int D_003FA994;   /* recursion count */
extern int D_003FAF18;   /* semaphore id    */

__attribute__((section(".text.__malloc_lock")))
void __malloc_lock(void *r)
{
    int tid;

    tid = GetThreadId();
    if (D_003FA990 == tid) {
        D_003FA994++;
        return;
    }
    WaitSema(D_003FAF18);
    D_003FA990 = tid;
    D_003FA994++;
}

/* SCE newlib __malloc_unlock (0x003A80A8). */


extern int D_003FA990;   /* owner thread id */
extern int D_003FA994;   /* recursion count */
extern int D_003FAF18;   /* semaphore id    */

__attribute__((section(".text.__malloc_unlock")))
void __malloc_unlock(void *r)
{
    if (--D_003FA994 == 0) {
        D_003FA990 = -1;
        SignalSema(D_003FAF18);
    }
}

/* newlib mprec __mdiff (0x003AF180). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

extern _Bigint *func_003AE818(void *ptr, int k);           /* _Balloc */
extern int func_003AF118(_Bigint *a, _Bigint *b);          /* __mcmp  */

#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)(b), \
                         ((unsigned short *)a)[0] = (unsigned short)(c), a++)

__attribute__((section(".text.__mdiff")))
_Bigint *__mdiff(void *ptr, _Bigint *a, _Bigint *b)
{
    int i, wa, wb;
    _Bigint *c;
    unsigned int *xa, *xae, *xb, *xbe, *xc;
    int borrow, y;
    int z;

    i = func_003AF118(a, b);
    if (!i) {
        c = func_003AE818(ptr, 0);
        c->_wds = 1;
        c->_x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else {
        i = 0;
    }
    c = func_003AE818(ptr, a->_k);
    c->_sign = i;
    wa = a->_wds;
    xa = a->_x;
    xae = xa + wa;
    wb = b->_wds;
    xb = b->_x;
    xbe = xb + wb;
    xc = c->_x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        Storeinc(xc, z, y);
    }
    while (!*--xc) {
        wa--;
    }
    c->_wds = wa;
    return c;
}
