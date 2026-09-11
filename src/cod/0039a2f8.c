/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: _updateRefImage */

typedef struct Pic {
    char      pad_00[0x18];
    long long f018;
    long long f020;
    int       f028;
    int       f02C;
    int       f030;
    int       f034;
    int       f038;
    int       f03C;
    int       f040;
    int       f044;
    int       f048;
    int       f04C;
    int       f050;
    int       f054;
    int       f058;
    int       f05C;
    int       f060;
} Pic;

typedef struct Ctx {
    char pad_000[0x0B4];
    int  f0B4;
    int  f0B8;
    char pad_0BC[0x0FC - 0x0BC];
    int  f0FC;
    char pad_100[0x14C - 0x100];
    int  f14C;
    char pad_150[0x158 - 0x150];
    int  f158;
    int  f15C;
    int  f160;
    char pad_164[0x184 - 0x164];
    int  f184;
    int  f188;
    char pad_18C[0x194 - 0x18C];
    int  f194;
    int  f198;
    int  f19C;
    int  f1A0;
    int  f1A4;
    int  f1A8;
    int  f1AC;
    int  f1B0;
    int  f1B4;
    int  f1B8;
    char pad_1BC[0x1C8 - 0x1BC];
    Pic *f1C8;
    Pic *f1CC;
    Pic *f1D0;
    Pic *f1D4;
    Pic *f1D8;
    Pic *f1DC;
    Pic *f1E0;
    Pic *f1E4;
    Pic *f1E8;
    Pic *f1EC;
    Pic *f1F0;
    Pic *f1F4;
    char pad_1F8[0x838 - 0x1F8];
    long long f838;
    long long f840;
} Ctx;

__attribute__((section(".text.func_0039A2F8")))
int func_0039A2F8(Ctx *c, int p2)
{
    Pic *p;
    Pic *t;
    Pic *sel;
    int n;
    int ret;

    p = 0;
    ret = 0;
    n = (c->f184 == 3) ? 2 : 4;
    if (c->f160 == 3) {
        c->f1D0 = c->f1D4;
        c->f1E0 = c->f1E4;
        c->f1F0 = c->f1F4;
        if (c->f0B4 + c->f0B8 >= n) {
            c->f0FC = 0;
            c->f1B8 = 0;
            c->f1B4 = 0;
        }
        if ((c->f0FC != 0 || c->f1B8 != 0) && c->f1B4 == 0) {
            c->f1C8->f028 = 0;
            c->f1D8->f028 = 0;
            c->f1E8->f028 = 0;
        }
        c->f0FC = 0;
        c->f1B8 = 0;
        if (c->f184 == 3) {
            if (c->f1C8->f028 == 1 || c->f1B4 != 0) {
                if (c->f1CC->f028 == 1)
                    ret = 1;
            }
        } else {
            if (((c->f1D8->f028 == 1 && c->f1E8->f028 == 1) || c->f1B4 != 0)
                && c->f1DC->f028 == 1) {
                if (c->f1EC->f028 == 1)
                    ret = 1;
            }
        }
    } else {
        if (p2 == 0) {
            t = c->f1C8; c->f1C8 = c->f1CC; c->f1CC = t;
            t = c->f1D8; c->f1D8 = c->f1DC; c->f1DC = t;
            t = c->f1E8; c->f1E8 = c->f1EC; c->f1EC = t;
        }
        c->f1D0 = c->f1CC;
        c->f1E0 = c->f1DC;
        c->f1F0 = c->f1EC;
        if (c->f184 == 3) {
            if (c->f160 != 2 || c->f1C8->f028 == 1)
                ret = 1;
        } else {
            sel = (c->f184 == 1) ? c->f1EC : c->f1DC;
            if (c->f160 != 2
                || (p2 != 0 && sel->f028 == 1)
                || (c->f1D8->f028 == 1 && c->f1E8->f028 == 1))
                ret = 1;
        }
    }
    switch (c->f184) {
    case 3: p = c->f1D0; break;
    case 1: p = c->f1E0; break;
    case 2: p = c->f1F0; break;
    }
    p->f028 = 0;
    p->f018 = c->f838;
    p->f02C = c->f160;
    p->f020 = c->f840;
    p->f030 = c->f184;
    p->f034 = c->f14C;
    p->f038 = c->f198;
    p->f03C = c->f188;
    p->f040 = c->f194;
    p->f044 = c->f19C;
    p->f048 = c->f1A0;
    p->f04C = c->f1A4;
    p->f050 = c->f1A8;
    p->f054 = c->f1AC;
    p->f058 = c->f1B0;
    p->f05C = c->f158;
    p->f060 = c->f15C;
    return ret;
}
