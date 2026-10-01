/* sn-2.95.3-136 matched TU. */
#include "godhand/Poker.h"

extern void Obj0000_Init_Fields_00_04_1D6DB0(void *a0);

/* sn-2.95.3-136 matched TU. One call-loop → --call-loop-pad. */




extern void func_001DF858(Poker *a0);
/* Constructor: set up the 52 deck nodes and the display node, then clear flags, bet and the hand. */
__attribute__((section(".text.Poker__ctor")))
Poker *Poker__ctor(Poker *this) {
    BlackJackCard *card;
    int i;
    int j;

    func_001DF858(this);

    card = this->deck;
    /* `i != -1`: retail closes with `bne $s2,$s3` where $s3 = -1. */
    for (i = POKER_DECK_NUM - 1; i != -1; i--) {
        Obj0000_Init_Fields_00_04_1D6DB0(card);
        card += 1;
    }

    Obj0000_Init_Fields_00_04_1D6DB0(this->node);

    this->flags = 0;
    this->unk3048 = 9;
    this->state = 0;
    this->phase = 0;
    this->unk304C = 0;
    this->bet = 0;
    this->payout = 0;

    for (j = 4; j >= 0; j--) {
        this->hand[j] = 0;
    }
    for (j = 4; j >= 0; j--) {
        this->cardId[j] = POKER_CARD_NONE;
    }

    this->unk3050 = 0;
    return this;
}
