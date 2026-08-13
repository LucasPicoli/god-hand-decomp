/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045C210[];
extern unsigned short D_003F215E;
extern void func_0032A9F0(void *, short);
extern void func_0032A6D0(void *, int, short);
extern void func_0032BD50(void *, const char *);

/* sn-2.95.3-136 matched TU. */

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

typedef struct Item {
    char *dat;
    unsigned char flag;
} Item;

/* gcc gives every BLKmode local a 16-byte slot, so the two objects sit at
   sp+0x0 and sp+0x10.  One frame object with explicit padding reproduces that
   layout and lets the sub-object address reach the compare through a pointer
   variable, which is what fixes the operand order of the `beq`. */
typedef struct Frame {
    Item a;
    char pad[8];
    String t;
} Frame;



extern char D_003BB168[];                                                     /* nilRep */
extern const char D_0045C208[];                                               /* "" */



extern char *func_003BB058(void *);                                            /* Rep::clone */
extern void *func_003BB178(void *, unsigned int, unsigned int, const char *, unsigned int); /* replace */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                           /* free */






__attribute__((section(".text.func_0037E908")))
void func_0037E908(char *self)
{
    Frame fr;
    Frame *fp;
    String *tp;
    char *b;
    char *sub;
    Item *elem;
    char *dat;
    char *d;
    Rep *r;
    size_t i2;
    char *sd;
    Rep *sr;
    char *ep;
    int rc;
    const char *lit;
    Rep *nr;
    char *nd;
    size_t n;

    b = self + (*(unsigned char *)(self + 5) * 0x48 + 0x48);
    sub = b + 0x10;

    elem = (Item *)(*(char **)(*(char **)(self + 0x10) + 0x14)
                    + *(int *)(self + 0xC) * 8);
    dat = elem->dat;
    r = (Rep *)(dat - 16);
    if (r->selfish) {
        d = func_003BB058(r);
    } else {
        r->ref = r->ref + 1;
        d = dat;
    }
    fr.a.dat = d;
    fr.a.flag = elem->flag;

    i2 = *(unsigned char *)(self + 5);
    sd = *(char **)(*(char **)(self + 0x10));
    sr = (Rep *)(sd - 16);
    if (sr->selfish) {
        sd = func_003BB058(sr);
    } else {
        sr->ref = sr->ref + 1;
    }
    fr.t.dat = sd;

    fp = &fr;
    tp = &fp->t;
    ep = (char *)(i2 * 4 + (size_t)self);
    ep = ep + 0x14;
    if (tp != (String *)ep) {
        char *odat = ((String *)ep)->dat;
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
        {
            char *sdat = fr.t.dat;
            Rep *srep = (Rep *)(sdat - 16);
            if (srep->selfish) {
                sdat = func_003BB058(srep);
            } else {
                srep->ref = srep->ref + 1;
            }
            ((String *)ep)->dat = sdat;
        }
    }
    {
        char *odat = fr.t.dat;
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

    {
        const char *cs;
        char *ad = fr.a.dat;
        size_t i3 = *(unsigned char *)(self + 5);
        char *ep2;
        size_t nn;
        if (((Rep *)(ad - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            ad[((Rep *)(ad - 16))->len] = 0;
            cs = fr.a.dat;
        }
        ep2 = (char *)(i3 * 4 + (size_t)self);
        nn = strlen(cs);
        ep2 = ep2 + 0x14;
        func_003BB178(ep2, ((Rep *)(((String *)ep2)->dat - 16))->len, 0, cs, nn);
    }

    rc = func_00380AE8(self, sub, b);
    if (rc != 0) {
        char *odat;
        Rep *orep;
        *(char *)(b + 1) = rc;
        *(char *)(self + 2) = 8;
        odat = fr.a.dat;
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

    *(short *)(b + 6) = 0x7F;
    *(short *)(b + 4) = D_003F215E;
    func_0032A9F0(*(void **)(sub + 0x30), *(short *)(b + 4));
    *(short *)(b + 8) = -0x80;
    *(short *)(b + 0xA) = -0x80;
    func_0032A6D0(*(void **)(sub + 0x30), 0, -0x80);
    func_0032A6D0(*(void **)(sub + 0x30), 1, *(short *)(b + 0xA));
    *(int *)(sub + 0x20) = func_0032A988(*(void **)(sub + 0x30));

    nr = (Rep *)D_003BB168;
    lit = D_0045C210;
    if (nr->selfish) {
        nd = func_003BB058(nr);
    } else {
        nr->ref = nr->ref + 1;
        nd = (char *)(nr + 1);
    }
    fr.t.dat = nd;
    n = strlen(lit);
    func_003BB178(&fr.t, 0, 0xFFFFFFFFU, lit, n);

    {
        const char *cs2;
        char *ep3;
        char *ed;
        size_t nn;
        ep3 = (char *)(*(unsigned char *)(self + 5) * 4 + (size_t)self);
        ep3 = ep3 + 0x14;
        ed = ((String *)ep3)->dat;
        if (((Rep *)(ed - 16))->len == 0) {
            cs2 = D_0045C208;
        } else {
            ed[((Rep *)(ed - 16))->len] = 0;
            cs2 = ((String *)ep3)->dat;
        }
        nn = strlen(cs2);
        func_003BB178(&fr.t, ((Rep *)(fr.t.dat - 16))->len, 0, cs2, nn);
    }

    {
        const char *cs3;
        if (((Rep *)(fr.t.dat - 16))->len == 0) {
            cs3 = D_0045C208;
        } else {
            fr.t.dat[((Rep *)(fr.t.dat - 16))->len] = 0;
            cs3 = fr.t.dat;
        }
        func_0032BD50(*(void **)(sub + 0x30), cs3);
    }
    *(char *)(self + 2) = 2;
    {
        char *odat = fr.t.dat;
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
    {
        char *odat = fr.a.dat;
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
