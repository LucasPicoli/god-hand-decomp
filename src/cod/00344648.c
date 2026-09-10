/* cygnus-2.96 matched TU. */

typedef struct W {
    char pad0[0x28];
    void *(*alloc)(void *obj, int n);
    void *(*freep)(void *obj, void *p);
    void *obj;
} W;

extern W *GetD003EC7E0_3452B0(void);

__attribute__((section(".text.mwsfcre_UsrMalloc")))
void *mwsfcre_UsrMalloc(int n)
{
    W *w;

    w = GetD003EC7E0_3452B0();
    return w->alloc(w->obj, n);
}
