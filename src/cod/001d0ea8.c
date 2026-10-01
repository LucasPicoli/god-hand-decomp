/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

/* sn-2.95.3-136 candidate. */

extern void InitNode_1D0C78(void *o);

extern void func_001D4D80(BlackJack *o);
/* Constructor: set up the 52 deck nodes, then clear state, bet and both hands. */
__attribute__((section(".text.BlackJack__ctor")))
BlackJack *BlackJack__ctor(BlackJack *self)
{
    BlackJackCard *card;
    BlackJackCard **q;
    BlackJackCard **r;
    short *u;
    short *w;
    int i;
    int j;
    int k;
    int m;
    int n;
    int val;

    func_001D4D80(self);
    card = self->deck;
    i = BLACKJACK_DECK_NUM - 1;
    do {
        InitNode_1D0C78(card);
        card += 1;
    } while (--i != -1);
    self->flags = 0;
    self->state = 0;
    self->phase = 0;
    self->camera = 0;
    self->bet = 0;
    self->payout = 0;
    q = self->handA;
    r = self->handB;
    u = self->cardIdA;
    w = self->cardIdB;
    for (j = 4; j >= 0; j--) q[j] = 0;
    for (k = 4; k >= 0; k--) r[k] = 0;
    val = BLACKJACK_CARD_NONE;
    for (m = 4; m >= 0; m--) u[m] = val;
    val = BLACKJACK_CARD_NONE;
    for (n = 4; n >= 0; n--) w[n] = val;
    self->unk1820[0] = 0;
    return self;
}
