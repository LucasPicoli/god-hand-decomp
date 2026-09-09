/* ee-2.9-991111 matched TU. */

typedef struct Ctx {
    char pad_000[0x878];
    int  f878;
} Ctx;

typedef struct ExtTbl {
    void (*f[11])(Ctx *s);
} ExtTbl;

extern const ExtTbl D_0045E968;
extern void func_003A0E20(Ctx *s, int n);
extern void func_003A0F80(Ctx *s);
extern void flushByteBoundary(Ctx *s);



__attribute__((section(".text.func_003A0C18")))
void func_003A0C18(Ctx *s)
{
    ExtTbl tbl = D_0045E968;
    int code;
    int id;

    flushByteBoundary(s);
    while (func_0039EB90(s, 24) != 1) {
        if (s->f878 != 0)
            break;
        func_003A0E20(s, 8);
    }
    while ((code = func_0039EB90(s, 32)) == 0x1B5 || code == 0x1B2) {
        if (code == 0x1B5) {
            func_003A0F80(s);
            id = func_0039EAA8(s, 4);
            id = ((unsigned int)id > 10U) ? 0 : id;
            tbl.f[id](s);
            flushByteBoundary(s);
            while (func_0039EB90(s, 24) != 1) {
                if (s->f878 != 0)
                    break;
                func_003A0E20(s, 8);
            }
        } else {
            func_003A0F80(s);
            flushByteBoundary(s);
            while (func_0039EB90(s, 24) != 1) {
                if (s->f878 != 0)
                    break;
                func_003A0E20(s, 8);
            }
        }
    }
}
