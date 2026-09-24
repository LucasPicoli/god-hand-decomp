/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045C210[] __attribute__((aligned(8)));
extern char D_0077BE80[] __attribute__((aligned(8)));
extern const char D_0045C208[];
extern void func_003A53A8(char *, const char *);
extern void func_0032D9B8(void *, char *, int);
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);
extern void func_002E0DE8(int, int, int, const char *, ...);
extern char D_0076E910[];
extern char D_0076B340[];
extern char D_0045B868[];
extern char D_0045B888[];
extern char D_0045B8A8[];
extern char D_0045B8C0[];
extern char D_0045B8D8[];
extern char D_0045B8F0[];
extern char D_0045B908[];
extern char D_0045B920[];
extern char D_0045B938[];
extern char D_0045B950[];
extern char D_0045B968[];
extern char D_0045B988[];
extern char D_0045B9A8[];
extern char D_0045B9C8[];
extern char D_0045B9E8[];
extern char D_0045BA08[];
extern char D_0045BA28[];
extern char D_0045BA40[];
extern char D_0045BA58[];
extern char D_0045BA70[];
extern char D_0045BA88[];
extern char D_0045BAA0[];
extern char D_0045BAB8[];
extern char D_0045BAD0[];
extern void func_00379838(char *);
extern void func_00379910(char *);
extern char D_0045B350[];
extern char D_0045B360[];
extern char D_0045B6C8[];
extern char D_0045B6E0[];
extern char D_0045B6F8[];
extern char D_0045B710[];
extern char D_0045B3E8[];
extern char D_0045B418[];
extern char D_0045B728[];
extern char D_0045B738[];
extern char D_0045B4F0[];
extern char D_0045B508[];
extern char D_0045B520[];
extern char D_0045B740[];
extern char D_0045B448[];
extern char D_0045B460[];
extern char D_0045B478[];
extern char D_0045B388[];
extern char D_0045B3A0[];
extern char D_0045B560[];
extern char D_0045B578[];
extern char D_0045B590[];
extern char D_0045B5A8[];
extern void func_00151990(char *w, unsigned int name, char *pa, char *pb, int type);
extern void func_00151CC0(char *w, unsigned int name, char *pa, char *pb, int type);
extern void func_00151688(char *w, unsigned int name, char *pa, char *pb, int type);
extern void func_00151FA0(char *w, unsigned int name, char *pa, char *pb, int type);

typedef unsigned int size_t;
typedef char achar __attribute__((aligned(8)));

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





__attribute__((section(".text.func_0037EDA8")))
void func_0037EDA8(char *self)
{
    String tmp;
    String cur;
    String *ths;
    String *dst;
    char *st;
    char *sub;
    int rc;

    st = self + 0x318;
    {
        String *src = &((String *)(*(char **)(*(char **)(self + 0x10) + 0x14)))[*(int *)(self + 0xC)];
        char *sdat = src->dat;
        Rep *srep = (Rep *)(sdat - 16);
        sub = self + 0x348;
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        tmp.dat = sdat;
        tmp.flag = src->flag;
    }

    {
        String *src = (String *)*(char **)(self + 0x10);
        char *sdat = src->dat;
        Rep *srep = (Rep *)(sdat - 16);
        if (srep->selfish) {
            sdat = func_003BB058(srep);
        } else {
            srep->ref = srep->ref + 1;
        }
        dst = (String *)(self + 0x3C);
        cur.dat = sdat;
    }

    ths = dst;
    if (&cur != dst) {
        char *odat = *(char **)(self + 0x3C);
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
        func_003BB178((String *)(self + 0x3C), ((Rep *)(*(char **)(self + 0x3C) - 16))->len, 0, cs, n);
    }

    rc = func_00381B38(self, sub, st);
    if (rc != 0) {
        char *odat;
        Rep *orep;
        *(char *)(st + 1) = rc;
        *(char *)(self + 2) = 9;
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

    {
        achar *buf = (achar *)D_0077BE80;
        const char *cs;
        char *d;
        __builtin_memcpy(D_0077BE80, D_0045C210, 11);
        d = *(char **)(self + 0x3C);
        if (((Rep *)(d - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            d[((Rep *)(d - 16))->len] = 0;
            cs = *(char **)(self + 0x3C);
        }
        func_003A53A8(buf, cs);
    }
    func_0032D9B8(*(void **)(sub + 0x20), D_0077BE80, 0);
    *(char *)(self + 2) = 3;

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

__attribute__((section(".text.func_00379BC0")))
void func_00379BC0(void)
{
    char *e = D_0076E910;
    char *b = D_0076B340;

    func_002E0DE8(0x19, 0x3, 8, D_0045B868, *(unsigned short *)(e + 0x0), *(unsigned short *)(e + 0x14));
    func_002E0DE8(0x19, 0x4, 8, D_0045B888, *(unsigned short *)(b + 0x0), *(unsigned short *)(b + 0x12));
    func_002E0DE8(0x19, 0x6, 8, D_0045B8A8, *(int *)(b + 0x24));
    func_002E0DE8(0x19, 0x7, 8, D_0045B8C0, *(int *)(b + 0x2C));
    func_002E0DE8(0x19, 0x8, 8, D_0045B8D8, *(int *)(b + 0x30));
    func_002E0DE8(0x19, 0xA, 8, D_0045B8F0, *(int *)(b + 0x64));
    func_002E0DE8(0x19, 0xB, 8, D_0045B908, *(int *)(b + 0x68));
    func_002E0DE8(0x19, 0xC, 8, D_0045B920, *(int *)(b + 0x6C));
    func_002E0DE8(0x19, 0xD, 8, D_0045B938, *(int *)(b + 0x74));
    func_002E0DE8(0x19, 0xE, 8, D_0045B950, *(int *)(b + 0x70));
    func_002E0DE8(0x19, 0x10, 8, D_0045B968, *(signed char *)(b + 0x84), *(signed char *)(b + 0x85));
    func_002E0DE8(0x19, 0x11, 8, D_0045B988, *(unsigned short *)(b + 0x94), *(unsigned short *)(b + 0x96));
    func_002E0DE8(0x19, 0x12, 8, D_0045B9A8, *(unsigned short *)(b + 0xC8), *(unsigned short *)(b + 0xCA));
    func_002E0DE8(0x19, 0x14, 8, D_0045B9C8, *(signed char *)(b + 0x86), *(signed char *)(b + 0x89));
    func_002E0DE8(0x19, 0x15, 8, D_0045B9E8, *(signed char *)(b + 0x87), *(signed char *)(b + 0x8A));
    func_002E0DE8(0x19, 0x17, 8, D_0045BA08, *(signed char *)(b + 0x8B), *(signed char *)(b + 0x8C));
    func_002E0DE8(0x19, 0x18, 8, D_0045BA28, *(signed char *)(b + 0x8D));
    func_002E0DE8(0x3, 0x10, 8, D_0045BA40, *(short *)(e + 0x38));
    func_002E0DE8(0x3, 0x11, 8, D_0045BA58, *(short *)(e + 0x3A));
    func_002E0DE8(0x3, 0x12, 8, D_0045BA70, *(short *)(e + 0x3C));
    func_002E0DE8(0x3, 0x13, 8, D_0045BA88, *(int *)(e + 0x58));
    func_002E0DE8(0x3, 0x15, 8, D_0045BAA0, *(short *)(e + 0x5C));
    func_002E0DE8(0x3, 0x16, 8, D_0045BAB8, *(short *)(e + 0x60));
    func_002E0DE8(0x3, 0x18, 8, D_0045BAD0, *(unsigned short *)(b + 0x10));
}

__attribute__((section(".text.func_003794D0")))
void func_003794D0(char *self)
{
    char *p = self + 0x12C;
    int x = 0x1B;
    signed char c;

    if (*(unsigned short *)(p + 0xE) & 0x8000) {
        func_002E0DE8(0x1B, 3, 0xD, D_0045B350);
        func_002E0DE8(0x1B, 4, 0xD, D_0045B360);
        func_002E0DE8(0x1B, 5, 0xD, D_0045B350);
        return;
    }
    func_002E0DE8(0x1B, 3, 8, D_0045B6C8, *(short *)(p + 4));
    if (*(unsigned char *)(p + 6) & 1) {
        func_002E0DE8(0x1B, 4, 8, D_0045B6E0);
    } else {
        func_002E0DE8(0x1B, 4, 8, D_0045B6F8);
    }
    func_002E0DE8((short)x, 5, 8, D_0045B710, *(signed char *)(p + 9));
    func_002E0DE8((short)x, 7, 8, D_0045B3E8, *(short *)(p + 0x18));
    func_002E0DE8((short)x, 8, 8, D_0045B418, *(short *)(p + 0x1C));
    func_002E0DE8((short)x, 0xA, 8, D_0045B728);
    c = *(signed char *)(p + 7);
    if (c > 0x28) {
        func_002E0DE8(0x28, 0xA, 0xA, D_0045B738, c);
    } else {
        func_002E0DE8(0x28, 0xA, 8, D_0045B738, c);
    }
    func_002E0DE8((short)x, 0xB, 8, D_0045B4F0, *(signed char *)(p + 8));
    if (*(unsigned short *)(p + 0xE) & 0x10) {
        func_002E0DE8((short)x, 0xC, 8, D_0045B508);
    } else {
        func_002E0DE8((short)x, 0xC, 8, D_0045B520);
    }
    if (*(unsigned short *)(p + 0xE) & 2) {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xD, 8, D_0045B740);
    } else {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xD, 8, D_0045B448);
    }
    if (*(unsigned short *)(p + 0xC) & 1) {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xE, 8, D_0045B460);
    } else {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xE, 8, D_0045B478);
    }
    c = *(signed char *)(p + 0x26);
    if (c == -1) {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xF, 8, D_0045B388);
    } else {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 0xF, 8, D_0045B3A0, c);
    }
    func_002E0DE8((short)x, 0x11, 8, D_0045B560, *(signed char *)(p + 0x28));
    func_002E0DE8((short)x, 0x12, 8, D_0045B578, *(signed char *)(p + 0x29));
    func_002E0DE8((short)x, 0x13, 8, D_0045B590, *(signed char *)(p + 0x2A));
    func_002E0DE8((short)x, 0x14, 8, D_0045B5A8, *(signed char *)(p + 0x2B));
    func_00379838(self);
    func_00379910(self);
}

typedef struct {
    unsigned int name;
    int b;
    int c;
    int v;
} Ent;







__attribute__((section(".text.func_00151398")))
int func_00151398(char *w, unsigned int name, int type)
{
    Ent *e = (Ent *)(w + 0x3C990);
    char *pa;
    char *pb;
    int v;

    if (type == 2) {
        e = (Ent *)(w + 0x3D2F0);
        while (e->name != 0xFFFFFFFF) {
            if (e->name == name) return e->v;
            e--;
        }
        if (e == (Ent *)(w + 0x3C9A0)) return 0;
        pa = w + 0x3DC6C;
        pb = w + 0x3DC70;
    } else if (type == 1) {
        e = (Ent *)(w + 0x3DC50);
        while (e->name != 0xFFFFFFFF) {
            if (e->name == name) return e->v;
            e--;
        }
        if (e == (Ent *)(w + 0x3D300)) return 0;
        pa = w + 0x3DC78;
        pb = w + 0x3DC7C;
    } else {
        while (e->name != 0xFFFFFFFF) {
            if (e->name == name) return e->v;
            e--;
        }
        if (e == (Ent *)(w + 0x3C040)) return 0;
        pa = w + 0x3DC60;
        pb = w + 0x3DC64;
    }
    v = *(unsigned short *)(w + 0x3F8A8);
    e->name = name;
    e->b = *(int *)pa;
    e->c = *(int *)pb;
    e->v = *(unsigned short *)(w + 0x3F8A8);
    switch (func_00151630(name)) {
    case 0:
        func_00151990(w, name, pa, pb, type);
        break;
    case 1:
        func_00151CC0(w, name, pa, pb, type);
        break;
    case 2:
        func_00151688(w, name, pa, pb, type);
        break;
    case 3:
        func_00151FA0(w, name, pa, pb, type);
        break;
    }
    return v;
}

static __inline__ void vset(char *o, int on)
{
    if (o != 0) {
        char *vt = *(char **)(o + 0x214);
        short off = *(short *)(vt + 0x60);
        void (*fn)(char *, int) = *(void (**)(char *, int))(vt + 0x64);
        fn(o + off, on);
    }
}

__attribute__((section(".text.func_00275308")))
void func_00275308(char *self, int on)
{
    if (on == 1) {
        *(int *)(self + 0x250) |= 0x8000;
    } else {
        *(int *)(self + 0x250) &= ~0x8000;
    }
    if (on == 1) {
        *(int *)(self + 0x5A0) |= 8;
    } else {
        *(int *)(self + 0x5A0) &= ~8;
    }
    vset(*(char **)(self + 0x6EC), on);
    vset(*(char **)(self + 0x6F0), on);
    vset(*(char **)(self + 0x6F8), on);
    vset(*(char **)(self + 0x6FC), on);
    vset(*(char **)(self + 0x700), on);
    vset(*(char **)(self + 0x704), on);
    vset(*(char **)(self + 0x708), on);
    vset(*(char **)(self + 0x734), on);
    vset(*(char **)(self + 0x6F4), on);
    vset(*(char **)(self + 0x70C), on);
    vset(*(char **)(self + 0x1964), on);
    vset(*(char **)(self + 0x196C), on);
    vset(*(char **)(self + 0x1970), on);
    vset(*(char **)(self + 0x1974), on);
    vset(*(char **)(self + 0x740), on);
    vset(*(char **)(self + 0x744), on);
    vset(*(char **)(self + 0x748), on);
    vset(*(char **)(self + 0x74C), on);
    vset(*(char **)(self + 0x750), on);
}
