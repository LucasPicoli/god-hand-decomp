/* sn-2.95.3-136 */
#include "godhand/BlackJack.h"

#define BLACKJACK_BUST          22

extern int func_001D4720(BlackJack *self);
extern int func_001D47E8(BlackJack *self);

/* Hand A holds five cards without going bust. */
__attribute__((section(".text.func_001D4980")))
int func_001D4980(BlackJack *self)
{
    if (self->dealSlot != BLACKJACK_HAND_NUM) {
        return 0;
    }
    return func_001D4720(self) < BLACKJACK_BUST;
}

/* Hand B holds five cards without going bust. */
__attribute__((section(".text.func_001D49B0")))
int func_001D49B0(BlackJack *self)
{
    if (self->dealSlotB != BLACKJACK_HAND_NUM) {
        return 0;
    }
    return func_001D47E8(self) < BLACKJACK_BUST;
}
