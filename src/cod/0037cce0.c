/* sn-2.95.3-136: dispatch the pending update flags at +6, then clear them. */
#include "godhand/seqNode.h"

extern void SndMix_calcVoiceLevel(SeqNode *self);
extern void func_0037D680(SeqNode *self);
extern void func_0037D728(SeqNode *self);
extern void func_0037D558(SeqNode *self);
extern void func_0037C720(SeqNode *self);
extern void func_003738A0(void *node, int a1, float w);
extern void UpdateSequenceNodeWeighted_373560(void *node, int a1, float w);

__attribute__((section(".text.func_0037CCE0")))
void func_0037CCE0(SeqNode *self)
{
    if (self->kind & 8) {
        if (self->sub & 1) {
            SndMix_calcVoiceLevel(self);
            func_003738A0(&D_0076A600[self->id], -1,
                          (short)self->weight >> 8);
            UpdateSequenceNodeWeighted_373560(&D_0076A600[self->id], -1,
                                              (short)self->weight >> 8);
        }
        if (self->sub & 2) {
            func_0037D680(self);
            func_0037C720(self);
        }
    } else {
        if (self->sub & 1) {
            SndMix_calcVoiceLevel(self);
        }
        if (self->sub & 2) {
            func_0037D680(self);
        }
        if (self->sub & 4) {
            func_0037D728(self);
        }
        if (self->sub & 8) {
            func_0037D558(self);
        }
    }
    self->sub = 0;
}
