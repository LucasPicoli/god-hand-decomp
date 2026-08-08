/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045C4C0[];
extern void func_0032B188(void *, int);
extern void func_0032A9F0(void *, short);
extern void func_0032A6D0(void *, int, short);
extern void func_0032BD50(void *, const char *);
extern void func_0032B300(void *, int);

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

extern char *func_003BB058(void *);                                            /* void *::clone */
extern void *func_003BB178(void *, unsigned int, unsigned int, const char *, unsigned int); /* replace */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                          /* free */


extern char D_003BB168[];                                                        /* nilRep */

extern const char D_0045C4D0[];                                               /* "" */








__attribute__((section(".text.func_00380B70")))
int func_00380B70(char *self, char *b)
{
    char *sub = b + 0x10;
    int r;
    String s;
    const char *cs;
    const char *cs2;
    const char *lit;
    char *ed;
    size_t n;
    Rep *nr;
    String *ths;
    char *d;
    char *odat;
    Rep *orep;
    char *ep;
    size_t idx;

    r = func_00380AE8(self, sub, b);
    if (r != 0) {
        *(char *)(b + 1) = r;
        return 1;
    }
    func_0032B188(*(void **)(sub + 0x30), 1);
    func_0032A9F0(*(void **)(sub + 0x30), *(short *)(b + 4));
    func_0032A6D0(*(void **)(sub + 0x30), 0, *(short *)(b + 8));
    func_0032A6D0(*(void **)(sub + 0x30), 1, *(short *)(b + 0xA));

    ths = &s;
    nr = (Rep *)D_003BB168;
    lit = D_0045C4C0;
    if (nr->selfish) {
        d = func_003BB058(nr);
    } else {
        nr->ref = nr->ref + 1;
        d = (char *)(nr + 1);
    }
    ths->dat = d;
    n = strlen(lit);
    func_003BB178(ths, 0, 0xFFFFFFFFU, lit, n);

    idx = *(unsigned char *)(self + 5);
    ep = (char *)(idx * 4 + (size_t)self);
    ep = ep + 0x14;
    ed = ((String *)ep)->dat;
    if (((Rep *)(ed - 16))->len == 0) {
        cs = D_0045C4D0;
    } else {
        ed[((Rep *)(ed - 16))->len] = 0;
        cs = ((String *)ep)->dat;
    }
    n = strlen(cs);
    func_003BB178(&s, ((Rep *)(s.dat - 16))->len, 0, cs, n);

    if (((Rep *)(s.dat - 16))->len == 0) {
        cs2 = D_0045C4D0;
    } else {
        s.dat[((Rep *)(s.dat - 16))->len] = 0;
        cs2 = s.dat;
    }
    func_0032BD50(*(void **)(sub + 0x30), cs2);
    *(char *)b = 0;
    func_0032B300(*(void **)(sub + 0x30), 0);

    odat = s.dat;
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
    return 0;
}
