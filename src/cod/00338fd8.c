#include "godhand/criSj.h"
#include "godhand/globals.h"

extern char D_00455920[];
extern char D_00455950[];
extern int func_00338A48(char *, char *);

__attribute__((section(".text.func_00338FD8")))
void func_00338FD8(SjMem *s, int mode, int size, SjChunk *res)
{
    int n;
    int pos;

    if (s == 0) {
        func_00338A48(D_004559D0, D_00455920);
        return;
    }
    if (s->used == 0) {
        func_00338A48(D_004559E0, D_00455950);
        return;
    }
    if (mode == 0) {
        res->len = 0;
        res->data = 0;
        return;
    }
    if (mode == 1) {
        n = s->dataLen;
        if (n >= size) {
            n = size;
        }
        res->len = n;
        pos = s->readPos;
        s->readPos = pos + n;
        res->data = s->base + pos;
        s->dataLen -= res->len;
        return;
    }
    res->len = 0;
    res->data = 0;
    if (s->cb != 0) {
        s->cb(s->cbobj, -3);
    }
}
