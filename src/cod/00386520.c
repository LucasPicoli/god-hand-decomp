/* sn-2.95.3-136 matched TU. */

extern unsigned int strlen(const char *);
extern void *D_003C4030[16];
extern const char D_0045D018[];

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




__attribute__((section(".text.func_00386520")))
void func_00386520(String *self, const char *s)
{
    String *dst = self + 1;
    size_t n;

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
    n = strlen(s);
    func_003BB178(self, ((Rep *)(self->dat - 16))->len, 0, s, n);
    n = strlen(D_0045D018);
    func_003BB178(self, ((Rep *)(self->dat - 16))->len, 0, D_0045D018, n);
}
