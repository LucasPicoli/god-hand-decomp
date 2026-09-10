/* cygnus-2.96 matched TU. */

struct PD { int f0; int f4; int f8; int fC; char pad10[0x18]; char f28[8];
            short f30; short f32; char pad34[8]; };
extern struct PD D_003EB858[0x10];

extern void func_0033E6B8(int a, int b, short *c, short *d);

__attribute__((section(".text.func_0033F8B8")))
struct PD *func_0033F8B8(void)
{
    int i;
    struct PD *e;
    for (i = 0; i < 0x10; i++) if (D_003EB858[i].f0 == 0) break;
    if (i == 0x10) return 0;
    e = &D_003EB858[i];
    func_003A52F0(e, 0, 0x3C);
    e->f0 = 1;
    e->f4 = i;
    e->f8 = 0;
    e->fC = 0;
    func_0033E6B8(500, 0xAC44, &e->f30, &e->f32);
    func_003A52F0(e->f28, 0, 8);
    return e;
}
