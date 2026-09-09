/* ee-2.9-991111 matched TU. */

typedef struct Pic {
    char pad_00[0x28];
    int  f028;
} Pic;

typedef struct Ctx {
    char pad_000[0x130];
    int  f130;
    char pad_134[0x184 - 0x134];
    int  f184;
    char pad_188[0x1D0 - 0x188];
    Pic *f1D0;
    char pad_1D4[0x1E0 - 0x1D4];
    Pic *f1E0;
    char pad_1E4[0x1F0 - 0x1E4];
    Pic *f1F0;
} Ctx;

extern char D_0045E548[];
extern char D_0045E568[];
extern void func_0039C390(Ctx *c, char *msg);


__attribute__((section(".text.func_0039ACD8")))
int func_0039ACD8(Ctx *c)
{
    Pic *p;
    int r;

    if (c->f184 == 3 && c->f130 != 0) {
        func_0039C390(c, D_0045E548);
        c->f130 = 0;
    }
    switch (c->f184) {
    case 3:
        p = c->f1D0;
        break;
    case 1:
        p = c->f1E0;
        break;
    case 2:
        p = c->f1F0;
        break;
    default:
        p = c->f1D0;
        func_0039C390(c, D_0045E568);
        break;
    }
    r = func_0039D5B8(c);
    if (r != 0)
        p->f028 = 1;
    return r;
}
