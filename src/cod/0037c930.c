/* sn-2.95.3-136: sequence node owner sync (0x37C930). */

#include "godhand/seqNode.h"

typedef struct {
    unsigned short flags;
    char pad2[2];
    int owner;
} SeqOwnerCtl;

extern SeqOwnerCtl D_0076B1C0[];

__attribute__((section(".text.func_0037C930")))
void func_0037C930(void)
{
    SeqNode *n;
    SeqOwnerCtl *c;
    int i;
    unsigned short f;

    for (i = 0; i < 48; i++) {
        n = &D_0076CF20[i];
        c = &D_0076B1C0[i];
        f = n->flags;
        if (f == 0) {
            continue;
        }
        if (c->owner != n->owner) {
            continue;
        }
        if (c->flags & 0x8000) {
            if (!(f & 0x8000)) {
                n->flags = f | 0x8000;
            }
            continue;
        }
        if (f & 0x8000) {
            n->flags = f & 0x7FFF;
        }
        if (!(c->flags & 2)) {
            if (!(c->flags & 0x10)) {
                continue;
            }
            func_0037D148(n);
            func_0037D3B0(n);
            continue;
        }
        if (!(n->flags & 2)) {
            n->flags |= 2;
        }
        if (c->flags & 0x80) {
            func_0037D148(n);
            func_0037D3B0(n);
        } else {
            n->busy++;
        }
    }

    for (; i < 51; i++) {
        n = &D_0076CF20[i];
        if (n->flags != 0) {
            if (!(n->flags & 2)) {
                n->flags |= 2;
            }
            n->busy++;
        }
    }
}
