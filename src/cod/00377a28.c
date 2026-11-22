/* sn-2.95.3-136: SdeStrCtlFadeOutEnd, stops every active kind-2 sequence node owned by the given track. */
#include "godhand/seqNode.h"

typedef struct {
    unsigned short flags; /* 0x00 */
    short pad02;
    int id;               /* 0x04 */
    char pad08[0x14 - 0x08];
    short state;          /* 0x14 */
} SeqTrack;

__attribute__((section(".text.SdeStrCtlFadeOutEnd")))
void SdeStrCtlFadeOutEnd(SeqTrack *t)
{
    SeqNode *n = D_0076CF20;

    do {
        if (n->flags != 0 && (n->kind & 2) && n->unk14 == t->id)
            func_0037D8B8(n, -1);
        n++;
    } while ((int)n < (int)(D_0076CF20 + 48));
    t->state = 3;
    t->flags |= 0x28;
}
