/* sn-2.95.3-136 matched TU. */

extern void *D_003C4030[16];
extern void func_002E0DE8(int, int, int, const char *, ...);

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
    unsigned char flag;
} String;

typedef struct SimpleString {
    char *dat;
} SimpleString;


extern char D_0045C1C8[];   /* "%s" */
extern char D_0045C208[];   /* "" */
extern char D_0045C368[];   /* "-- ADX FILE SELECT --" */
extern char D_0045C380[];   /* "DIR : %s" */
extern char D_0045C390[];   /* "[D]" */
extern char D_0045C398[];   /* "[F]" */
extern char D_0045C3A0[];   /* "ADX[%d] : %s" */
extern char D_0045C3B0[];   /* "AIX : %s" */
extern char D_0045C3C0[];   /* "AFS : %s" */
extern char D_0045C3D0[];   /* "ACX : %s" */

extern char *func_003BB058(void *);                    /* Rep::clone */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);   /* free */


__attribute__((section(".text.func_00380280")))
void func_00380280(char *self)
{
    String tmp;
    String ent;
    unsigned int i;
    unsigned int n;
    unsigned int cnt;
    int j;

    func_002E0DE8(0x11, 3, 0xD, D_0045C368);
    {
        const char *fmt = D_0045C380;
        char *dat = ((SimpleString *)*(char **)(self + 0x10))->dat;
        Rep *rp = (Rep *)(dat - 16);
        if (rp->selfish) {
            dat = func_003BB058(rp);
        } else {
            rp->ref = rp->ref + 1;
        }
        tmp.dat = dat;
        {
            char *cs;
            if (((Rep *)(tmp.dat - 16))->len == 0) {
                cs = D_0045C208;
            } else {
                tmp.dat[((Rep *)(tmp.dat - 16))->len] = 0;
                cs = tmp.dat;
            }
            func_002E0DE8(3, 5, 8, fmt, cs);
        }
    }
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

    {
        char *base = *(char **)(self + 0x10);
        String *end = *(String **)(base + 0x18);
        String *beg = *(String **)(base + 0x14);
        n = *(unsigned int *)(self + 8) + 10;
        i = *(unsigned int *)(self + 8);
        cnt = end - beg;
        if (cnt < n) {
            n = cnt;
        }
    }
    j = 7;
    for (; i < n; ++i) {
        String *e = &(*(String **)(*(char **)(self + 0x10) + 0x14))[i];
        {
            char *dat = e->dat;
            Rep *rp = (Rep *)(dat - 16);
            if (rp->selfish) {
                dat = func_003BB058(rp);
            } else {
                rp->ref = rp->ref + 1;
            }
            ent.dat = dat;
        }
        ent.flag = e->flag;
        if (ent.flag) {
            func_002E0DE8(5, (short)j, 0xC, D_0045C390);
        } else {
            func_002E0DE8(5, (short)j, 0xD, D_0045C398);
        }
        {
            const char *fmt = D_0045C1C8;
            int col = (short)j;
            char *cs;
            if (((Rep *)(ent.dat - 16))->len == 0) {
                cs = D_0045C208;
            } else {
                ent.dat[((Rep *)(ent.dat - 16))->len] = 0;
                cs = ent.dat;
            }
            func_002E0DE8(0xA, col, 8, fmt, cs);
        }
        ++j;
        {
            char *odat = ent.dat;
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

    {
        unsigned int k = *(unsigned char *)(self + 5);
        const char *fmt = D_0045C3A0;
        char **p = (char **)(k * 4 + (unsigned int)self);
        char *cs;
        p += 5;
        if (((Rep *)(*p - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            (*p)[((Rep *)(*p - 16))->len] = 0;
            cs = *p;
        }
        func_002E0DE8(3, 0x17, 8, fmt, k, cs);
    }
    {
        const char *fmt = D_0045C3B0;
        char *cs;
        if (((Rep *)(*(char **)(self + 0x3C) - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            (*(char **)(self + 0x3C))[((Rep *)(*(char **)(self + 0x3C) - 16))->len] = 0;
            cs = *(char **)(self + 0x3C);
        }
        func_002E0DE8(3, 0x18, 8, fmt, cs);
    }
    {
        const char *fmt = D_0045C3C0;
        char *cs;
        if (((Rep *)(*(char **)(self + 0x40) - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            (*(char **)(self + 0x40))[((Rep *)(*(char **)(self + 0x40) - 16))->len] = 0;
            cs = *(char **)(self + 0x40);
        }
        func_002E0DE8(3, 0x19, 8, fmt, cs);
    }
    {
        const char *fmt = D_0045C3D0;
        char *cs;
        if (((Rep *)(*(char **)(self + 0x44) - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            (*(char **)(self + 0x44))[((Rep *)(*(char **)(self + 0x44) - 16))->len] = 0;
            cs = *(char **)(self + 0x44);
        }
        func_002E0DE8(3, 0x1A, 8, fmt, cs);
    }
}
