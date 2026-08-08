/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8(int, int, int, void *);
extern void *D_003C4030[16];
extern void *D_003F28C0[];
extern char D_0045C328[];

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

extern char *func_003BB058(Rep *);                    /* Rep::clone */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);  /* free */






__attribute__((section(".text.func_00380138")))
void func_00380138(char *self, char *other)
{
    if (*(int *)(other + 0x34) & 0x40) {
        String *dst = *(String **)(self + 0x10);
        String *src = dst + 1;

        if (src != dst) {
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
            sdat = src->dat;
            srep = (Rep *)(sdat - 16);
            if (srep->selfish) {
                sdat = func_003BB058(srep);
            } else {
                srep->ref = srep->ref + 1;
            }
            dst->dat = sdat;
        }
        if (func_0037E8D8(self))
            *(char *)(self + 2) = 12;
        else
            *(char *)(self + 2) = 1;
    } else {
        char *p = *(char **)(self + 0x10);
        size_t idx;
        idx = *(unsigned char *)(p + 0x20);
        idx = idx - 1;
        func_002E0DE8(3, 0x14, 10, D_003F28C0[idx]);
        func_002E0DE8(3, 0x15, 10, D_0045C328);
    }
}
