/* cygnus-2.96 matched TU. */

struct SJMEM { void *f0; int f4; void *f8; char padC[8]; int f14; int f18;
               void *f1C; void *f20; };
extern struct SJMEM D_003E3AD0[0x20];
extern int D_003E3A98[];
extern int D_004558F0[];
extern void Forward340AE8_338A28(void);
extern void func_00338EC8(struct SJMEM *e);

__attribute__((section(".text.SJMEM_Create")))
struct SJMEM *SJMEM_Create(int a, int b)
{
    int i;
    struct SJMEM *e;
    for (i = 0; i < 0x20; i++) if (D_003E3AD0[i].f4 == 0) break;
    if (i == 0x20) return 0;
    e = &D_003E3AD0[i];
    e->f4 = 1;
    e->f0 = D_003E3A98;
    e->f14 = a;
    e->f18 = b;
    e->f8 = D_004558F0;
    e->f1C = (void *)Forward340AE8_338A28;
    e->f20 = e;
    func_00338EC8(e);
    return e;
}
