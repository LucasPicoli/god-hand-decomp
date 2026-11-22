#include "godhand/criSj.h"
#include "godhand/globals.h"
extern char D_00455BD8[];
extern char D_00455C08[];
extern void func_0033A048(char *a, char *b);

__attribute__((section(".text.func_0033A4F8")))
void func_0033A4F8(SjUni *e)
{
    SjUniChunk *buf;
    SjUniChunk *c;
    int i;

    if (e == 0) {
        func_0033A048(D_00455C68, D_00455BD8);
        return;
    }
    if (e->f4 == 0) {
        func_0033A048(D_00455C78, D_00455C08);
        return;
    }
    buf = e->buf;
    e->free = buf;
    for (i = 0; i < e->nchunk - 1; i++) {
        buf[i].unkC = 0;
        buf[i].unk8 = 0;
        buf[i].next = &buf[i + 1];
    }
    buf[i].next = 0;
    buf[i].unk8 = 0;
    buf[i].unkC = 0;
    for (i = 3; i >= 0; i--) {
        e->list[i] = 0;
    }
}
