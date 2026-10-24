/* sn-2.95.3-136: func_0037CAE0, per-frame voice scan: step every live voice (sequenced voices poll their sequence and retire when it ends), then store the per-kind live counts. */
#include "godhand/seqNode.h"
#include "godhand/sndTiming.h"

#define SEQNODE_K_SEQUENCED  8          /* kind: the voice plays a sequence */

extern int GetSequenceResult_373770(void *seq);
extern void UpdateSequenceNode_373430(void *seq);
extern void ResetNodeData_3733C8(void *seq);
extern void func_0037CC78(unsigned short *v);
extern void func_0037CCE0(SeqNode *v);

__attribute__((section(".text.func_0037CAE0")))
void func_0037CAE0(void)
{
    SndTiming *st;
    SeqNode *v;
    unsigned char n1;
    unsigned char n2;
    unsigned char n4;
    int i;

    st = &D_0076A790;
    n1 = 0;
    n2 = 0;
    n4 = 0;
    for (i = 0; i < SEQ_NUM; i++) {
        v = &D_0076CF20[i];
        if (v->flags == 0)
            continue;
        if (v->kind & SEQNODE_K_SEQUENCED) {
            switch (GetSequenceResult_373770(&D_0076A600[v->id])) {
            case 6:
                UpdateSequenceNode_373430(&D_0076A600[v->id]);
                ResetNodeData_3733C8(&D_0076A600[v->id]);
                /* fall through */
            case 0:
                func_0037D148(v);
                func_0037D3B0(v);
                break;
            default:
                func_0037CC78(&v->flags);
                func_0037CCE0(v);
                n1++;
                break;
            }
        } else {
            func_0037CC78(&v->flags);
            func_0037CCE0(v);
            if (v->kind & 1)
                n1++;
            if (v->kind & 2)
                n2++;
            if (v->kind & 4)
                n4++;
        }
    }
    st->nKind1 = n1;
    st->nKind2 = n2;
    st->nKind4 = n4;
    st->nTotal = n1 + n2 + n4;
}
