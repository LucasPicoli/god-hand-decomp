/* cygnus-2.96 matched TU. */

typedef struct R { char pad0[0x10]; int f10; int f14; int f18; int f1C; } R;

extern int D_0035DC10();
extern int func_0035DC60();
extern int func_0035DCB0();
extern int func_0035DD00();
extern int sfhds_CallN(void *h, int (*f)());

__attribute__((section(".text.sfhds_AnlyHead")))
void sfhds_AnlyHead(void *h, R *r)
{
    int v;

    r->f10 = sfhds_CallN(h, D_0035DC10);
    r->f14 = sfhds_CallN(h, func_0035DC60);
    v = sfhds_CallN(h, func_0035DCB0);
    r->f18 = v;
    if (v == -1) r->f18 = 2;
    r->f1C = sfhds_CallN(h, func_0035DD00);
}
