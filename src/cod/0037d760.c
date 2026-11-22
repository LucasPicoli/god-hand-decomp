/* sn-2.95.3-136: sequence node random range / state (0x37D760..). */

#include "godhand/seqNode.h"

extern int func_00377FA0(void);
extern void UpdateSequenceNode_373430(void *node);
extern void ResetNodeData_3733C8(void *node);

__attribute__((section(".text.SdeVregRndPchGet")))
short SdeVregRndPchGet(SeqRange *r)
{
    short lo = r->min;
    short hi = r->max;
    short d, v;

    if (lo == hi) {
        return lo;
    }
    d = hi - lo;
    if (d <= 16) {
        v = func_00377FA0() % (d + 1);
    } else {
        v = (func_00377FA0() % 17U) * (d / 16);
    }
    return v + lo;
}

__attribute__((section(".text.func_0037D820")))
void func_0037D820(SeqNode *n)
{
    if (n->kind & 8) {
        UpdateSequenceNode_373430(&D_0076A600[n->id]);
        ResetNodeData_3733C8(&D_0076A600[n->id]);
        SdeVmngClose(n);
        SdeVregClose(n);
    } else {
        SdeVmngClose(n);
        n->parent = 0;
        n->flags |= 0x10;
    }
}

__attribute__((section(".text.func_0037D8B8")))
void func_0037D8B8(SeqNode *n, short arg)
{
    if (n->busy == 0) {
        if (n->kind & 8) {
            func_0037D820(n);
            return;
        }
        if (n->flags & 2) {
            if (n->parent != 0 && n->parent->busy == 0) {
                SdeVmngClose(n);
                SdeVregClose(n);
                return;
            }
        } else {
            func_0037D820(n);
        }
    }
    if (arg == 0) {
        n->flags |= 0x20;
        func_0037D820(n);
    } else if (arg == -1) {
        func_0037D820(n);
    } else if (n->timer.f30 != 0) {
        n->timer.f36 = arg;
        n->timer.f32 = 0;
        SdeFadeSpdSet(&n->timer);
        n->flags |= 0x40;
    }
}

/* For every live node whose kind bits meet mask, set sub bits 9 (mode 1) or 10 (mode 2). */
__attribute__((section(".text.SeqNode_setSubByKind")))
void SeqNode_setSubByKind(unsigned char mask, unsigned short mode)
{
    int i;
    SeqNode *n;

    for (i = 0; i < 51; i++) {
        n = &D_0076CF20[i];
        if (n->flags != 0 && (n->kind & mask)) {
            switch (mode) {
            case 1:
                n->sub |= 9;
                break;
            case 2:
                n->sub |= 10;
                break;
            }
        }
    }
}
