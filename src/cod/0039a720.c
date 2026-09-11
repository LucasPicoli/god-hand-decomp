/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpeg.o :: _decodeOrSkipField */
#include <godhand/gp.h>

typedef struct Ctx {
    int  f000;
    int  f004;
    int  f008;
    char pad_00C[0x0C0 - 0x00C];
    int  f0C0;
    char pad_0C4[0x0E8 - 0x0C4];
    int  f0E8;
    char pad_0EC[0x128 - 0x0EC];
    int  f128;
    char pad_12C[0x130 - 0x12C];
    int  f130;
    char pad_134[0x184 - 0x134];
    int  f184;
    char pad_188[0x878 - 0x188];
    int  f878;
} Ctx;

typedef struct Mpeg {
    char pad_00[0x08];
    int  f008;
    char pad_0C[0x40 - 0x0C];
    Ctx *ctx;
} Mpeg;

struct cbp { int reason; int pad[7]; };
typedef int (*cbfn)();



extern void func_0039B810(Mpeg *m);
extern void func_0039B8D0(Ctx *c, int a, int b);


__attribute__((section(".text.func_0039A720")))
int func_0039A720(Mpeg *m, int p2, int p3)
{
    Ctx *c;
    int first;
    int ret;
    int r;
    int want;
    struct cbp cb;

    first = 0;
    c = m->ctx;
    c->f130 = 0;
    if (p3 == -1 || p2 < p3)
        first = 1;
    if (c->f008 == 0) {
        m->f008 = 0;
        c->f008 = 1;
    }
    if (func_0039A2F8(c, 0) != 0 && first != 0)
        func_0039ACD8(c);
    if (c->f878 != 0) return 0;
    c->f130 = 1;
    if (func_003A0E28(c) == 0) {
        func_0039B810(m);
        c->f000 = 1;
        return 0;
    }
    want = (c->f0E8 == 1) ? 2 : 1;
    if (c->f184 != want) return -1;
    r = 0;
    if (func_0039A2F8(c, 1) != 0)
        r = 1;
    ret = 0;
    if (r != 0 && first != 0) {
        if (func_0039ACD8(c) != 0)
            ret = 1;
    }
    if (c->f878 != 0) return 0;
    func_0039B8D0(c, c->f128, c->f004);
    c->f130 = 0;
    m->f008 = c->f128 - c->f0C0;
    c->f128 = c->f128 + 1;
    c->f004 = c->f004 + 1;
    if (first == 0) {
        cb.reason = 1;
        if (m != 0) {
            char *base = *(char **)((char *)m + 0x40);
            if (base != 0) {
                cbfn fn = *(cbfn *)(base + cb.reason * 12 + 12);
                if (fn != 0) {
                    void *oldgp = SetGp(*(void **)(base + cb.reason * 12 + 20));
                    fn(m, &cb, *(void **)(base + cb.reason * 12 + 16));
                    SetGp(oldgp);
                }
            }
        }
    }
    return ret;
}
