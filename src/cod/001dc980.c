/* sn-2.95.3-136: func_001DC980, when a slot shows kind 3, mark the first card pair group (two matches of one rank) and report it. */
#include "godhand/Poker.h"

extern void func_001DBFB8(PokerHandView *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DC980")))
int func_001DC980(PokerHandView *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short n;
    int i;
    int j;
    int k;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    for (j = 0; j < POKER_HAND_NUM; j++) {
        if (y[j] == 3) {
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
                if (n == 2)
                    break;
            }
            return 1;
        }
    }
    return 0;
}
