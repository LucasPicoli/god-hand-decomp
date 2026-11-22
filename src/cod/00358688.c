/* cygnus-2.96: sfply_InitTmrInf, clear the header, init the five channel blocks and the master
 * block, and zero the trailing counters. */
typedef struct {
    char body[0x20];
} ChBlock;

typedef struct {
    ChBlock ch[5];
    ChBlock master;
    long c0;
    long c8;
    long d0;
    int d8;
    int dc;
} ChSet;

extern void UTY_MemsetDword(void *dst, int c, int n);
extern void func_0035BB40(ChBlock *b);

__attribute__((section(".text.sfply_InitTmrInf")))
void sfply_InitTmrInf(ChSet *s)
{
    ChBlock *b;
    int i;

    UTY_MemsetDword(s, 0, 0x38);
    b = s->ch;
    for (i = 4; i >= 0; i--)
        func_0035BB40(b++);
    func_0035BB40(&s->master);
    s->c0 = 0;
    s->c8 = 0;
    s->d0 = 0;
    s->d8 = 0;
    s->dc = 0;
}
