/* cygnus-2.96 matched TU. */

typedef struct W {
    char pad0[0x28];
    void *alloc;
    void *freep;
    void *obj;
} W;

extern W *GetD003EC7E0_3452B0(void);

__attribute__((section(".text.mwPlySetMallocFn")))
void mwPlySetMallocFn(void *fn1, void *fn2, void *obj)
{
    W *w;

    w = GetD003EC7E0_3452B0();
    w->alloc = fn1;
    w->freep = fn2;
    w->obj = obj;
}
