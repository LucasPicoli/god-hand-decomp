/* sn-2.95.3-136 */
#include "godhand/BlackJack.h"

extern void func_001D4670(BlackJack *self);
extern void BlackJackId_SetDefaultDisp(BlackJack *self);
extern int cCoreSave_getGold(void *save);
extern void func_001D5780(BlackJack *self, int gold);
extern char D_00569B70[];

/* Start a new round: clear the bet and payout and the slots being dealt, reset the display, show
 * the player's gold, and go to the deal state if the bet changed this frame, else back to betting. */
__attribute__((section(".text.BlackJack_UpdateNewRound")))
void BlackJack_UpdateNewRound(BlackJack *self)
{
    int gold;
    unsigned int flags;
    long tmp;

    self->bet = 0;
    self->payout = 0;
    self->dealSlot = 0;
    self->dealSlotB = 0;
    func_001D4670(self);
    BlackJackId_SetDefaultDisp(self);
    CustomIDWork_SetNumber_1D5760(self, 0);
    gold = cCoreSave_getGold(D_00569B70);
    func_001D5780(self, gold);
    /* the flag is tested as a 64-bit value */
    flags = self->flags;
    tmp = flags;
    tmp = tmp >> 3;
    tmp = tmp & 1;
    if (tmp != 0) {
        self->phase = 0;
        self->state = BLACKJACK_STATE_DEAL;
    } else {
        self->phase = 0;
        self->state = BLACKJACK_STATE_BET;
    }
    self->flags = 0;
}
