/* sn-2.95.3-136 matched TU. */

extern void *D_003C4030[16];
extern void InitObjectFull_3806D8(void *);

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

typedef struct Pair {
    char *dat;
    int x;
} Pair;

typedef struct Vec {
    String *start;
    String *finish;
    String *eos;
} Vec;

typedef struct PVec {
    Pair *start;
    Pair *finish;
    Pair *eos;
} PVec;

typedef struct Sub {
    String m0;
    String m4;
    Vec v8;
    PVec v14;
} Sub;


extern void UpdateGlobalPtrWithParam_3A7CC0(void *);                /* free */
extern void ForwardFieldNeg20_002A9680_30F5A0(void *);              /* operator delete */


__attribute__((section(".text.func_0037DC88")))
void func_0037DC88(char *self, int in_chrg)
{
    Sub *p;

    InitObjectFull_3806D8(self);
    p = *(Sub **)(self + 0x10);
    if (p != 0) {
        PVec *pv = &p->v14;
        Vec *sv = &p->v8;
        Pair *q;
        Pair *qe;
        String *r;
        String *re;

        /* destroy(v14.begin(), v14.end()) */
        q = p->v14.start;
        qe = pv->finish;
        while (q < qe) {
            char *odat = q->dat;
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
            q = q + 1;
        }

        /* v14.deallocate() */
        {
            Pair *en = pv->eos;
            Pair *st = pv->start;
            int cap = en - st;
            if (cap != 0) {
                size_t db = cap * 8;
                if (db > 128) {
                    UpdateGlobalPtrWithParam_3A7CC0(st);
                } else {
                    size_t di;
                    void **dfl;
                    di = (db + 7) / 8;
                    di = di - 1;
                    dfl = D_003C4030 + di;
                    *(char **)st = (char *)*dfl;
                    *dfl = st;
                }
            }
        }

        /* destroy(v8.begin(), v8.end()) */
        re = sv->finish;
        r = p->v8.start;
        while (r < re) {
            char *odat = r->dat;
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
            r = r + 1;
        }

        /* v8.deallocate() */
        {
            String *en = sv->eos;
            String *st = sv->start;
            int cap = en - st;
            if (cap != 0) {
                size_t db = cap * 4;
                if (db > 128) {
                    UpdateGlobalPtrWithParam_3A7CC0(st);
                } else {
                    size_t di;
                    void **dfl;
                    di = (db + 7) / 8;
                    di = di - 1;
                    dfl = D_003C4030 + di;
                    *(char **)st = (char *)*dfl;
                    *dfl = st;
                }
            }
        }

        /* ~m4 */
        {
            char *odat = p->m4.dat;
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

        /* ~m0 */
        {
            char *odat = p->m0.dat;
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

        ForwardFieldNeg20_002A9680_30F5A0(p);
    }

    /* ~m44 */
    {
        char *odat = *(char **)(self + 0x44);
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

    /* ~m40 */
    {
        char *odat = *(char **)(self + 0x40);
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

    /* ~m3C */
    {
        char *odat = *(char **)(self + 0x3C);
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

    /* ~m14[10], in reverse */
    {
        String *b = (String *)(self + 0x14);
        String *e = (String *)(self + 0x3C);
        if (b != 0) {
            if (b != e) {
                do {
                    char *odat;
                    Rep *orep;
                    e = e - 1;
                    odat = e->dat;
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
                } while (b != e);
            }
        }
    }

    if (in_chrg & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(self);
    }
}
