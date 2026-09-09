/* ee-2.9-991111 matched TU. */

typedef struct Ctx {
    char pad_00[0x004];
    int  f004;
    int  f008;
    char pad_00C[0x0C0 - 0x00C];
    int  f0C0;
    char pad_0C4[0x128 - 0x0C4];
    int  f128;
    char pad_12C[0x130 - 0x12C];
    int  f130;
    char pad_134[0x184 - 0x134];
    int  f184;
    char pad_188[0x1CC - 0x188];
    int  f1CC;
    char pad_1D0[0x1DC - 0x1D0];
    int  f1DC;
    char pad_1E0[0x1EC - 0x1E0];
    int  f1EC;
} Ctx;

typedef struct Mpeg {
    char pad_00[0x08];
    int  f008;
    char pad_0C[0x40 - 0x0C];
    Ctx *ctx;
} Mpeg;

extern char D_0045E5D8[];
extern void func_0039C390(Ctx *c, char *msg);
extern void _dispRefImage(Ctx *c, int a, int b);
extern void _dispRefImageField(Ctx *c, int a, int b, int d);

__attribute__((section(".text.func_0039B810")))
int func_0039B810(Mpeg *m)
{
    Ctx *c = m->ctx;
    int ret = 0;

    if (c->f004 != 0 && c->f008 != 0) {
        int n = c->f128;
        if (c->f130 != 0) {
            func_0039C390(c, D_0045E5D8);
        } else if (c->f184 == 3) {
            _dispRefImage(c, c->f1CC, n - 1);
        } else {
            _dispRefImageField(c, c->f1DC, c->f1EC, n - 1);
        }
        c->f130 = 0;
        m->f008 = c->f128 - c->f0C0;
        c->f004 = 0;
        ret = 1;
    }
    return ret;
}
