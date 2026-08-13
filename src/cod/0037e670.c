/* sn-2.95.3-136 matched TU. */

extern void *D_003C4030[16];
extern char D_0045C110[];
extern char D_0045C118[];
extern char D_0045C120[];
extern void func_003863B8(void *);
extern void func_00386520(void *, char *);
extern void func_0037EDA8(void *);
extern void func_0037E908(void *);
extern void func_0037F0E0(void *);
extern void func_0037F4F8(void *);

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





extern char D_0045C208[];   /* "" */

extern char *func_003BB058(void *);                    /* Rep::clone */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);   /* free */










__attribute__((section(".text.func_0037E670")))
void func_0037E670(char *self)
{
    String tmp;
    String *e;
    char *cs;

    if (func_00386640(*(void **)(self + 0x10)) != 0 && *(int *)(self + 0xC) == 0) {
        func_003863B8(*(void **)(self + 0x10));
        if (func_0037E8D8(self)) {
            *(char *)(self + 2) = 12;
        }
        return;
    }

    e = &((String *)*(char **)(*(char **)(self + 0x10) + 0x14))[*(int *)(self + 0xC)];
    {
        char *dat = e->dat;
        Rep *rp = (Rep *)(dat - 16);
        char *held;
        if (rp->selfish) {
            held = func_003BB058(rp);
        } else {
            held = dat;
            rp->ref = rp->ref + 1;
        }
        tmp.dat = held;
    }
    tmp.flag = e->flag;

    if (tmp.flag) {
        if (((Rep *)(tmp.dat - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            tmp.dat[((Rep *)(tmp.dat - 16))->len] = 0;
            cs = tmp.dat;
        }
        func_00386520(*(void **)(self + 0x10), cs);
        if (func_0037E8D8(self)) {
            *(char *)(self + 2) = 12;
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
    } else {
        if (((Rep *)(tmp.dat - 16))->len == 0) {
            cs = D_0045C208;
        } else {
            tmp.dat[((Rep *)(tmp.dat - 16))->len] = 0;
            cs = tmp.dat;
        }
        if (func_003866B8(*(void **)(self + 0x10), cs, D_0045C118)) {
            func_0037EDA8(self);
        } else {
            if (((Rep *)(tmp.dat - 16))->len == 0) {
                cs = D_0045C208;
            } else {
                tmp.dat[((Rep *)(tmp.dat - 16))->len] = 0;
                cs = tmp.dat;
            }
            if (func_003866B8(*(void **)(self + 0x10), cs, D_0045C110)) {
                func_0037E908(self);
            } else {
                if (((Rep *)(tmp.dat - 16))->len == 0) {
                    cs = D_0045C208;
                } else {
                    tmp.dat[((Rep *)(tmp.dat - 16))->len] = 0;
                    cs = tmp.dat;
                }
                if (func_003866B8(*(void **)(self + 0x10), cs, D_0045C120)) {
                    func_0037F0E0(self);
                } else {
                    func_0037F4F8(self);
                }
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
    }
}
