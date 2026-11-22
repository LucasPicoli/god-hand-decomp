#include "godhand/seqNode.h"
typedef struct {
    unsigned short flags;
    unsigned char b2;
    unsigned char b3;
    int w4;
    unsigned short h8;
    unsigned short hA;
    unsigned short hC;
    unsigned short hE;
    int w10[6];
    char pad28[0x18];
} SndChOut;

extern SndChOut D_0076AFC0[];

__attribute__((section(".text.SdeStrOrderMake")))
void SdeStrOrderMake(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        SndCh *s = &D_0076E910[i];
        SndChOut *d = &D_0076AFC0[i];
        if (s->flags == 0) {
            d->flags = 0;
            d->w4 = 0;
        } else {
            d->flags = s->flags;
            d->b2 = s->unk0E;
            d->b3 = s->unk0F;
            d->w4 = s->unk04;
            d->h8 = s->unk08;
            d->hA = s->unk0A;
            d->hC = s->unk0C;
            d->hE = s->unk12;
            d->w10[0] = s->unk78[0];
            d->w10[1] = s->unk78[1];
            d->w10[2] = s->unk78[2];
            d->w10[3] = s->unk78[3];
            d->w10[4] = s->unk78[4];
            d->w10[5] = s->unk78[5];
        }
    }
}
