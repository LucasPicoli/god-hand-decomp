/* sn-2.95.3-136 */
#include "godhand/Poker.h"

extern void func_001DBFB8(PokerHandView *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

/* Four of a kind: when the first or second rank group has four cards, mark
 * the four cards of that rank and return 1; otherwise return 0. */
__attribute__((section(".text.func_001DC4C0")))
int func_001DC4C0(PokerHandView *self)
{
    unsigned short x[POKER_HAND_NUM];
    unsigned short y[POKER_HAND_NUM];
    unsigned short n;
    int i;
    int k;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    if (y[0] == 4 || y[1] == 4) {
        for (i = 0; i < POKER_HAND_NUM - 1; i++) {
            int l;

            for (l = 0; l < POKER_HAND_NUM; l++)
                self->slot[l]->flags &= ~POKER_HAND_F_MARK;
            n = 0;
            for (k = i + 1; k < POKER_HAND_NUM; k++) {
                if (self->slot[i]->card->rank == self->slot[k]->card->rank) {
                    n++;
                    self->slot[i]->flags |= POKER_HAND_F_MARK;
                    self->slot[k]->flags |= POKER_HAND_F_MARK;
                }
            }
            if (n == 3)
                break;
        }
        return 1;
    }
    return 0;
}
