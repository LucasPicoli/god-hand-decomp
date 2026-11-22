#include "godhand/seqNode.h"

__attribute__((section(".text.SdeVoiceOrderMake")))
void SdeVoiceOrderMake(void)
{
    int i;

    for (i = 0; i < 48; i++) {
        SeqNode *s = &D_0076CF20[i];
        SndVoiceOut *d = &D_0076A9C0[i];
        if (s->flags == 0) {
            d->flags = 0;
            d->w4 = 0;
            d->w8 = 0;
        } else {
            d->flags = s->flags;
            d->b2 = s->unk04;
            d->b3 = s->kind;
            d->w4 = s->owner;
            d->w8 = s->unk14;
            d->hC = s->unk1C;
            d->hE = s->unk1E;
            d->h10 = s->unk20;
            d->h12 = s->unk18;
            d->h14 = s->unk1A;
            d->h16 = s->unk22;
            d->h18 = s->unk4A;
            d->h1A = s->unk4C;
            d->h1C = s->unk4E;
        }
    }
}
