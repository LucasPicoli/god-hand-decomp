/* sn-2.95.3-136 matched TU. */

/* newlib mprec __pow5mult (0x003AEEC0). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

extern void func_003AE8C0(void *ptr, _Bigint *v);                    /* _Bfree     */
extern _Bigint *func_003AE8F8(void *ptr, _Bigint *b, int m, int a);  /* __multadd  */
extern _Bigint *func_003AEC80(void *ptr, int i);                     /* __i2b      */
extern _Bigint *func_003AECB8(void *ptr, _Bigint *a, _Bigint *b);    /* __multiply */
extern const int D_0045FCD8[];                                       /* p05[3]     */

#define P5S(p) (*(_Bigint **)((char *)(p) + 0x48))

__attribute__((section(".text.func_003AEEC0")))
_Bigint *func_003AEEC0(void *ptr, _Bigint *b, int k)
{
    _Bigint *b1, *p5, *p51;
    int i;

    if ((i = k & 3) != 0) {
        b = func_003AE8F8(ptr, b, D_0045FCD8[i - 1], 0);
    }
    if (!(k >>= 2)) {
        return b;
    }
    if (!(p5 = P5S(ptr))) {
        p5 = P5S(ptr) = func_003AEC80(ptr, 625);
        p5->_next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = func_003AECB8(ptr, b, p5);
            func_003AE8C0(ptr, b);
            b = b1;
        }
        if (!(k >>= 1)) {
            break;
        }
        if (!(p51 = p5->_next)) {
            p51 = p5->_next = func_003AECB8(ptr, p5, p5);
            p51->_next = 0;
        }
        p5 = p51;
    }
    return b;
}
