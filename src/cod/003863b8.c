/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045D010[];

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
extern unsigned int func_003BBEC0(void *, char, unsigned int);                          /* rfind(c,pos) */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                          /* free */




__attribute__((section(".text.func_003863B8")))
void func_003863B8(String *self)
{
    String *dst = self + 1;
    const char *lit;
    size_t pos;
    size_t n;

    pos = func_003BBEC0(self, 0x2F, 0xFFFFFFFFU);
    if (pos != 0xFFFFFFFFU) {
        if (self != dst) {
            char *odat = dst->dat;
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
            sdat = self->dat;
            srep = (Rep *)(sdat - 16);
            if (srep->selfish) {
                sdat = func_003BB058(srep);
            } else {
                srep->ref = srep->ref + 1;
            }
            dst->dat = sdat;
        }
        lit = D_0045D010;
        n = strlen(lit);
        func_003BB178(self, pos, 0xFFFFFFFFU, lit, n);
        pos = func_003BBEC0(self, 0x2F, 0xFFFFFFFFU);
        if (pos != 0xFFFFFFFFU) {
            pos = pos + 1;
            n = strlen(lit);
            func_003BB178(self, pos, 0xFFFFFFFFU, lit, n);
        }
    }
}
