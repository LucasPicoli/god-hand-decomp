/* sn-2.95.3-136: sequence stop commands (0x37C330..). */

#include "godhand/seqNode.h"

extern void func_0037C4C0(SeqCmd *c);

void func_0037C388(SeqCmd *c);
void func_0037C420(SeqCmd *c);

__attribute__((section(".text.vexeCmdExec")))
int vexeCmdExec(SeqCmd *c)
{
    if (c->all == 0) {
        if (c->arg == 0) {
            func_0037C388(c);
        } else {
            func_0037C420(c);
        }
    } else {
        func_0037C4C0(c);
    }
    return 0;
}

__attribute__((section(".text.func_0037C388")))
void func_0037C388(SeqCmd *c)
{
    SeqNode *n;
    int i = 0;

    do {
        n = &D_0076CF20[i];
        if (n->flags != 0 && (n->kind & c->mask) &&
            (c->owner == 0 || n->owner == c->owner)) {
            func_0037D8B8(n, c->arg);
            if (c->owner != 0) {
                break;
            }
        }
    } while (++i < 51);
}

__attribute__((section(".text.func_0037C420")))
void func_0037C420(SeqCmd *c)
{
    SeqLink *l = D_0076C8C0;
    int i = 0;

    do {
        if (l->flags != 0 && (l->kind & c->mask) &&
            (c->owner == 0 || l->owner == c->owner)) {
            func_0037D8B8(l->node, c->arg);
            if (c->owner != 0) {
                break;
            }
        }
        i++;
        l++;
    } while (i < 51);
}
