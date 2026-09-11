/* cygnus-2.96 matched TU. */

struct SJUNI { void *f0; signed char f4; signed char f5; char pad6[2]; void *f8;
               int fC; int f10; char pad14[0x14]; void *f28; void *f2C; };
extern struct SJUNI D_003E7FF0[0x40];
extern int D_003E7FB8[];
extern int D_00455BA8[];
extern void Forward340AE8_33A028(void);
extern void func_0033A4F8(struct SJUNI *e);

__attribute__((section(".text.func_0033A1E8")))
struct SJUNI *func_0033A1E8(int a, int b, int c)
{
    int i;
    struct SJUNI *e;
    for (i = 0; i < 0x40; i++) if (D_003E7FF0[i].f4 == 0) break;
    if (i == 0x40) return 0;
    e = &D_003E7FF0[i];
    e->f4 = 1;
    e->f0 = D_003E7FB8;
    e->f5 = a;
    e->f8 = D_00455BA8;
    e->fC = b;
    e->f10 = c / 16;
    e->f28 = (void *)Forward340AE8_33A028;
    e->f2C = e;
    func_0033A4F8(e);
    return e;
}
