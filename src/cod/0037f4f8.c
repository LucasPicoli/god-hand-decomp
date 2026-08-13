/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045C220[];
extern const char D_0045C250[];
extern const char D_0045C258[];
extern unsigned short D_003F215E;
extern void func_00385A20(void *);
extern void func_0032A9F0(void *, short);
extern void func_0032A6D0(void *, int, short);
extern void func_0032BDC0(void *, void *, int);

/* sn-2.95.3-136 matched TU, c_flags_add: -f=-fno-gcse. */



extern char D_003BB168[];                     /* basic_string<char>::nilRep */
extern const char D_0045C208[];               /* "" */





typedef unsigned int size_t;

typedef struct Rep {
    size_t len;
    size_t res;
    size_t ref;
    int selfish;
} Rep;

typedef struct String {
    char *dat;
    unsigned char flag;
} String;

extern char *func_003BB058(void *);                                                         /* Rep::clone */
extern void *func_003BB178(void *, unsigned int, unsigned int, const char *, unsigned int); /* replace */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                                        /* free */













#define RELEASE(DAT)                                     \
    {                                                    \
        char *odat = (DAT);                              \
        Rep *orep = (Rep *)(odat - 16);                  \
        if (--orep->ref == 0) {                          \
            size_t dn = orep->res + 16;                  \
            if (dn > 128) {                              \
                UpdateGlobalPtrWithParam_3A7CC0(orep);   \
            } else {                                     \
                size_t di;                               \
                void **dfl;                              \
                di = (dn + 7) / 8;                       \
                di = di - 1;                             \
                dfl = D_003C4030 + di;                   \
                *(char **)(odat - 16) = (char *)*dfl;    \
                *dfl = orep;                             \
            }                                            \
        }                                                \
    }

__attribute__((section(".text.func_0037F4F8")))
void func_0037F4F8(char *self)
{
    String A;
    String T;
    String *el;
    String *dst;
    String *ths;
    Rep *r;
    char *dat;
    char *s3;
    char *s4;
    int fd;
    int sz;
    void *buf;
    int rc;
    unsigned short hw;

    el = (String *)(*(char **)(*(char **)(self + 0x10) + 0x14)
                    + *(int *)(self + 0xC) * 8);
    dat = el->dat;
    r = (Rep *)(dat - 16);
    if (r->selfish) {
        dat = func_003BB058(r);
    } else {
        r->ref = r->ref + 1;
    }
    A.dat = dat;
    s3 = self + 0x470;
    A.flag = el->flag;

    dat = ((String *)*(char **)(self + 0x10))->dat;
    r = (Rep *)(dat - 16);
    s4 = self + 0x4BC;
    if (r->selfish) {
        dat = func_003BB058(r);
    } else {
        r->ref = r->ref + 1;
    }
    dst = (String *)(self + 0x44);
    T.dat = dat;
    ths = dst;

    if (&T != ths) {
        char *odat = *(char **)(self + 0x44);
        Rep *orep = (Rep *)(odat - 16);
        char *sdat;
        Rep *srep;
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
        sdat = T.dat;
        srep = (Rep *)(sdat - 16);
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        dst->dat = sdat;
    }
    RELEASE(T.dat);

    {
        char *ed = A.dat;
        const char *cs;
        size_t n;
        if (((Rep *)(ed - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            ed[((Rep *)(ed - 16))->len] = 0;
            cs = A.dat;
        }
        n = strlen(cs);
        func_003BB178(ths, ((Rep *)(*(char **)(self + 0x44) - 16))->len, 0, cs, n);
    }
    func_00385A20(self);

    {
        Rep *nr = (Rep *)D_003BB168;
        const char *lit = D_0045C250;
        char *d;
        size_t n;
        if (nr->selfish) {
            d = func_003BB058(nr);
        } else {
            nr->ref = nr->ref + 1;
            d = (char *)(nr + 1);
        }
        T.dat = d;
        n = strlen(lit);
        func_003BB178(&T, 0, 0xFFFFFFFFU, lit, n);
    }

    {
        char *ed = *(char **)(self + 0x44);
        const char *cs;
        size_t n;
        if (((Rep *)(ed - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            ed[((Rep *)(ed - 16))->len] = 0;
            cs = *(char **)(self + 0x44);
        }
        n = strlen(cs);
        func_003BB178(&T, ((Rep *)(T.dat - 16))->len, 0, cs, n);
    }

    {
        char *ed = T.dat;
        const char *cs;
        if (((Rep *)(ed - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            ed[((Rep *)(ed - 16))->len] = 0;
            cs = T.dat;
        }
        fd = func_003B4220(cs, 1);
    }
    if (fd < 0) {
        const char *fmt = D_0045C258;
        char *ed = T.dat;
        const char *cs;
        if (((Rep *)(ed - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            ed[((Rep *)(ed - 16))->len] = 0;
            cs = T.dat;
        }
        func_003A6A20(fmt, cs);
        *(char *)(s3 + 1) = 3;
        *(char *)(self + 2) = 11;
        RELEASE(T.dat);
        RELEASE(A.dat);
        return;
    }

    sz = func_003B4628(fd, 0, 2);
    func_003B4628(fd, 0, 0);
    buf = func_0031C890(sz);
    *(void **)(s3 + 0x84) = buf;
    if (buf == 0) {
        func_003B44B0(fd);
        func_003A6A20(D_0045C220);
        *(char *)(s3 + 1) = 1;
        *(char *)(self + 2) = 11;
        RELEASE(T.dat);
        RELEASE(A.dat);
        return;
    }

    func_003B4868(fd, buf, sz);
    func_003B44B0(fd);
    rc = func_00380AE8(self, s4, s3);
    if (rc != 0) {
        *(char *)(s3 + 1) = rc;
        *(char *)(self + 2) = 11;
        RELEASE(T.dat);
        RELEASE(A.dat);
        return;
    }

    *(short *)(s3 + 6) = 0x7F;
    hw = D_003F215E;
    *(short *)(s3 + 4) = hw;
    func_0032A9F0(*(void **)(s4 + 0x30), hw);
    *(short *)(s3 + 8) = -0x80;
    *(short *)(s3 + 0xA) = -0x80;
    func_0032A6D0(*(void **)(s4 + 0x30), 0, *(short *)(s3 + 8));
    func_0032A6D0(*(void **)(s4 + 0x30), 1, *(short *)(s3 + 0xA));
    *(int *)(s4 + 0x20) = func_0032A988(*(void **)(s4 + 0x30));
    *(char *)(self + 7) = 0;
    func_0032BDC0(*(void **)(s4 + 0x30), *(void **)(s3 + 0x84), 0);
    *(char *)(self + 2) = 7;
    RELEASE(T.dat);
    RELEASE(A.dat);
}
