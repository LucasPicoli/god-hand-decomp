/* sn-2.95.3-136: func_0037BF10, start a voice pair for a sound request: take a channel node and a voice node,
 * link them, and when the request is sequenced find the channel's slot in D_0076CEC0 and start the sequence there. */
#include "godhand/seqNode.h"

extern SeqLink D_0076CEC0[3];
extern int D_00773250[];
extern char *func_0037CF00(void *a0);
extern char *func_0037CEE0(void *a0);
extern char *func_0037D298(int a0);
extern void func_0037C160(SeqLink *a0, SeqCmd *a1);
extern void func_0037C1B8(SeqNode *a0, SeqCmd *a1);
extern void func_0037C228(SeqNode *a0, SeqCmd *a1);
extern void func_0037C2A8(SeqNode *a0, SeqCmd *a1);
extern void func_0037C2E0(SeqNode *a0, SeqCmd *a1);
extern int func_0037C630(SeqCmd *a0);
extern int func_00373118(void *a0, int a1, int a2, int a3);
extern int UpdateSequenceEntry_373298(void *a0, int a1);
extern void func_003738A0(void *a0, int a1, float f12);
extern void UpdateSequenceNodeWeighted_373560(void *a0, int a1, float f12);
extern void func_003735E0(void *a0, int a1, float f12, float f13);

__attribute__((section(".text.func_0037BF10")))
int func_0037BF10(SeqCmd *h)
{
    SeqLink *a;
    SeqNode *b;
    int i;
    int j;
    int idx;
    int *ent;
    SndVoiceNode *seq;

    i = 0;
    if (h->mask & SEQCMD_M_ALT)
        a = (SeqLink *)func_0037CF00(&h->req);
    else
        a = (SeqLink *)func_0037CEE0(&h->req);
    if (a == 0)
        return -1;
    b = (SeqNode *)func_0037D298(h->voice);
    if (b == 0)
        return -1;
    func_0037C160(a, h);
    func_0037C1B8(b, h);
    a->node = b;
    b->parent = (SeqNode *)a;
    func_0037C228(b, h);
    func_0037C2A8(b, h);
    func_0037C2E0(b, h);
    if (h->mask & SEQCMD_M_SEQUENCE) {
        for (j = 0; j < 3 && &D_0076CEC0[j] != a; j++)
            i++;
        if (i >= 3) {
            func_0037D148(b);
            func_0037D3B0(b);
            return -1;
        }
        a->id = i;
        b->id = i;
        idx = h->req;
        ent = &D_00773250[idx];
        if (*ent == 0)
            return 0;
        seq = &D_0076A600[(short)i];
        if (func_00373118(seq, idx + 0x82, *ent, func_0037C630(h)) == 0 ||
            UpdateSequenceEntry_373298(&D_0076A600[b->id], h->seqArg) == 0) {
            func_0037D148(b);
            func_0037D3B0(b);
            return -1;
        }
        func_003738A0(&D_0076A600[b->id], -1, (short)b->weight >> 8);
        UpdateSequenceNodeWeighted_373560(&D_0076A600[b->id], -1, (short)b->weight >> 8);
        func_003735E0(&D_0076A600[b->id], -1, 1.0f, 0.0f);
        func_0037C720(b);
        return 0;
    }
    func_0037D558(b);
    return 0;
}
