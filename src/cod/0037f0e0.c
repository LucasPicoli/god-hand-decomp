/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045C210[];
extern const char D_0045C220[];
extern void func_00384C60(void *);
extern void func_003A6A20(const char *);
extern void func_003229D0(int, const char *, int, void *);

/* sn-2.95.3-136 matched TU. */



extern const char D_0045C208[];                                               /* "" */



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

extern char *func_003BB058(void *);                                            /* Rep::clone */
extern void *func_003BB178(void *, unsigned int, unsigned int, const char *, unsigned int); /* replace */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                          /* free */

extern char D_003BB168[];                                                     /* nilRep */







__attribute__((section(".text.func_0037F0E0")))
void func_0037F0E0(char *self)
{
    String tmp;
    String cur;
    String *ths;
    String *dst;
    char *sub;
    void *h;

    /* tmp = ((String *)self->m10->m14)[self->mC] */
    {
        String *src = &((String *)(*(char **)(*(char **)(self + 0x10) + 0x14)))[*(int *)(self + 0xC)];
        char *sdat = src->dat;
        Rep *srep = (Rep *)(sdat - 16);
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        tmp.dat = sdat;
        tmp.flag = src->flag;
    }

    /* cur = *(String *)self->m10 */
    {
        String *src = (String *)*(char **)(self + 0x10);
        char *sdat = src->dat;
        Rep *srep = (Rep *)(sdat - 16);
        sub = self + 0x370;
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        dst = (String *)(self + 0x40);
        cur.dat = sdat;
    }

    /* self->m40 = cur */
    ths = dst;
    if (&cur != dst) {
        char *odat = *(char **)(self + 0x40);
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
        sdat = cur.dat;
        srep = (Rep *)(sdat - 16);
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        dst->dat = sdat;
    }

    /* ~cur */
    {
        char *odat = cur.dat;
        Rep *orep = (Rep *)(odat - 16);
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
    }

    /* self->m40 += tmp.c_str() */
    {
        const char *cs;
        char *d = tmp.dat;
        size_t n;
        if (((Rep *)(d - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            d[((Rep *)(d - 16))->len] = 0;
            cs = tmp.dat;
        }
        n = strlen(cs);
        func_003BB178(ths, ((Rep *)(*(char **)(self + 0x40) - 16))->len, 0, cs, n);
    }

    func_00384C60(self);
    h = func_0031C890(0x31C);
    *(void **)(sub + 0xFC) = h;
    if (h == 0) {
        char *odat;
        Rep *orep;
        func_003A6A20(D_0045C220);
        *(char *)(sub + 1) = 1;
        *(char *)(self + 2) = 10;
        /* ~tmp */
        odat = tmp.dat;
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
        return;
    }

    /* cur = D_0045C210 */
    {
        Rep *nr = (Rep *)D_003BB168;
        const char *lit = D_0045C210;
        char *d;
        size_t n;
        if (nr->selfish) {
            d = func_003BB058(nr);
        } else {
            nr->ref = nr->ref + 1;
            d = (char *)(nr + 1);
        }
        cur.dat = d;
        n = strlen(lit);
        func_003BB178(&cur, 0, 0xFFFFFFFFU, lit, n);
    }

    /* cur += self->m40.c_str() */
    {
        const char *cs;
        char *d = *(char **)(self + 0x40);
        size_t n;
        if (((Rep *)(d - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            d[((Rep *)(d - 16))->len] = 0;
            cs = *(char **)(self + 0x40);
        }
        n = strlen(cs);
        func_003BB178(&cur, ((Rep *)(cur.dat - 16))->len, 0, cs, n);
    }

    /* func_003229D0(0xFF, cur.c_str(), 0, self->m46C) */
    {
        const char *cs;
        char *d = cur.dat;
        if (((Rep *)(d - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            d[((Rep *)(d - 16))->len] = 0;
            cs = cur.dat;
        }
        func_003229D0(0xFF, cs, 0, *(void **)(sub + 0xFC));
    }
    *(char *)(self + 2) = 4;
    *(char *)(self + 6) = 0;

    /* ~cur */
    {
        char *odat = cur.dat;
        Rep *orep = (Rep *)(odat - 16);
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
    }

    /* ~tmp */
    {
        char *odat = tmp.dat;
        Rep *orep = (Rep *)(odat - 16);
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
    }
}
