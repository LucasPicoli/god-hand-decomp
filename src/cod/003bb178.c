/* sn-2.95.3-136 matched TU. */

extern const char D_0045C430[];
extern const char D_0045C440[];

typedef unsigned int size_t;

typedef struct Rep {
    size_t len;
    size_t res;
    size_t ref;
    int selfish;
} Rep;

typedef struct String {
    char *dat;
} String;

extern void func_003A7B58(const char *, int, const char *);   /* __assert */
extern void *func_003A7C70(size_t);                           /* malloc */
extern void *func_0031D6E8(size_t);                           /* _S_oom_malloc */
extern void *func_0031D928(size_t);                           /* _S_refill */
extern void func_003A5148(char *, const char *, size_t);      /* memcpy */
extern void func_003A51F4(char *, const char *, size_t);      /* memmove */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);          /* free */
extern void *D_003C4030[16];                                  /* _S_free_list */
extern const char D_0045C3F8[];                               /* "bastring.cc" */



__attribute__((section(".text.func_003BB178")))
String *func_003BB178(String *self, size_t pos, size_t n1, const char *s, size_t n2)
{
    size_t len;
    size_t newlen;
    size_t sz;
    Rep *rp;
    int need;

    len = ((Rep *)(self->dat - 16))->len;
    if (pos > len)
        func_003A7B58(D_0045C3F8, 156, D_0045C430);
    if (n1 > len - pos)
        n1 = len - pos;
    if (len - n1 > 0xFFFFFFFEU - n2)
        func_003A7B58(D_0045C3F8, 159, D_0045C440);
    newlen = len - n1 + n2;

    sz = newlen + 1;
    ((Rep *)(self->dat - 16))->selfish = 0;
    rp = (Rep *)(self->dat - 16);
    need = (rp->ref > 1 || sz > rp->res || 2 * (sz <= 16 ? 16 : sz) < rp->res);

    if (need) {
        size_t ss;
        size_t i;
        size_t nb;
        size_t cpos;
        size_t cend;
        Rep *p;
        char *d;
        const char *src;
        size_t cn;
        char *odat;
        Rep *orep;

        ss = newlen + 1;
        i = 16;
        while (i < ss)
            i *= 2;
        cend = pos + n1;
        cpos = pos + n2;
        nb = i + 16;
        if (nb > 128) {
            void *r = func_003A7C70(nb);
            if (r == 0)
                r = func_0031D6E8(nb);
            p = (Rep *)r;
        } else {
            size_t idx;
            void **fl;
            void *q;
            idx = (nb + 7) / 8;
            idx = idx - 1;
            fl = D_003C4030 + idx;
            q = *fl;
            if (q == 0) {
                p = (Rep *)func_0031D928((nb + 7) & ~7);
            } else {
                *fl = *(void **)q;
                p = (Rep *)q;
            }
        }
        p->res = i;
        p->ref = 1;
        p->selfish = 0;
        d = (char *)(p + 1);

        src = self->dat;
        if (pos)
            func_003A5148(d, src, pos);

        src = self->dat + pos;
        src += n1;
        cn = len - cend;
        if (cn)
            func_003A5148(d + cpos, src, cn);

        src = s;
        if (n2)
            func_003A5148(d + pos, src, n2);

        odat = self->dat;
        orep = (Rep *)(odat - 16);
        if (--orep->ref == 0) {
            size_t dn = orep->res + 16;
            if (dn > 128) {
                UpdateGlobalPtrWithParam_3A7CC0(orep);
            } else {
                size_t di;
                void **dfl;
                di = (dn + 7) / 8;
                di = di - 1;
                dfl = D_003C4030 + di;
                *(char **)(odat - 16) = (char *)*dfl;
                *dfl = orep;
            }
        }
        self->dat = d;
    } else {
        size_t mpos;
        const char *msrc;
        size_t mn;
        char *mdat;

        mdat = self->dat;
        mpos = pos + n2;
        msrc = mdat + pos;
        msrc += n1;
        mn = len - (pos + n1);
        if (mn)
            func_003A51F4(mdat + mpos, msrc, mn);
        mdat = self->dat;
        if (n2)
            func_003A5148(mdat + pos, s, n2);
    }
    ((Rep *)(self->dat - 16))->len = newlen;
    return self;
}
