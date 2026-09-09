/* ee-2.9-991111 matched TU. */

typedef struct Blk {
    int f00, f04, f08, f0C, f10, f14, f18, f1C;
} Blk;

typedef struct Ctx {
    char pad_000[0x12C];
    int  f12C;
    char pad_130[0x13C - 0x130];
    int  f13C;
    char pad_140[0x1C0 - 0x140];
    int  f1C0;
    int  f1C4;
    char pad_1C8[0x878 - 0x1C8];
    int  f878;
} Ctx;

extern char D_0045E7A8[];
extern char D_0045E7D0[];
extern void func_003A0E20(Ctx *s, int n);
extern void flushByteBoundary(Ctx *s);
extern void func_003A0F80(Ctx *s);



extern void func_0039C3E8(Ctx *s, char *msg, int a);
extern void func_0039C390(Ctx *s, char *msg);

__attribute__((section(".text.func_0039FE78")))
int func_0039FE78(Ctx *s, int unused, int *p3, int *p4, Blk *b)
{
    int code;
    int mb;

    s->f12C = 0;
    flushByteBoundary(s);
    while (func_0039EB90(s, 24) != 1) {
        if (s->f878 != 0)
            break;
        func_003A0E20(s, 8);
    }
    code = func_0039EB90(s, 32);
    if (code < 0x101 || code > 0x1AF) {
        func_0039C3E8(s, D_0045E7A8, code);
        return 2;
    }
    func_003A0F80(s);
    s->f1C4 = func_0039EAA8(s, 5);
    if (func_0039EAA8(s, 1) != 0) {
        func_0039EAA8(s, 1);
        func_003A0E20(s, 7);
        while (func_0039EAA8(s, 1) != 0)
            func_003A0E20(s, 8);
    }
    mb = func_0039E648(s);
    *p4 = mb;
    if (s->f12C != 0) {
        func_0039C390(s, D_0045E7D0);
        return 1;
    }
    *p3 = ((code & 0xFF) - 1) * s->f13C + mb - 1;
    *p4 = 1;
    s->f1C0 = 1;
    b->f14 = 0;
    b->f10 = 0;
    b->f04 = 0;
    b->f00 = 0;
    b->f1C = 0;
    b->f18 = 0;
    b->f0C = 0;
    b->f08 = 0;
    return 0;
}
