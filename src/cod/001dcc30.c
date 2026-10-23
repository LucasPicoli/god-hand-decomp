/* sn-2.95.3-136: func_001DCC30, when exactly one slot shows kind 2, mark the first pair of cards
 * with one rank and report it. */
#include "godhand/Poker.h"

extern void func_001DBFB8(PokerHandView *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DCC30")))
int func_001DCC30(PokerHandView *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short pair[2];
    unsigned short n;
    int i;
    int j;
    int k;
    int l;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    n = 0;
    for (j = 0; j < POKER_HAND_NUM; j++) {
        if (y[j] == 2)
            n++;
    }
    if (n != 1)
        return 0;
    for (i = 0; i < POKER_HAND_NUM - 1; i++) {
        k = i + 1;
        if (k < POKER_HAND_NUM) {
            do {
                if (self->slot[i]->card->rank == self->slot[k]->card->rank) {
                    pair[0] = i;
                    pair[1] = k;
                    break;
                }
            } while (++k < POKER_HAND_NUM);
        }
    }
    for (l = 0; l < POKER_HAND_NUM; l++)
        self->slot[l]->flags &= ~POKER_HAND_F_MARK;
    self->slot[pair[0]]->flags |= POKER_HAND_F_MARK;
    self->slot[pair[1]]->flags |= POKER_HAND_F_MARK;
    return 1;
}
