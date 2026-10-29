/* sn-2.95.3-136 */
#include "godhand/BlackJack.h"

#define BJ_ACE_EXTRA  10
#define BJ_BUST       21

/* Total of hand A: number cards count their value, faces 10 and aces 1, and
 * the last ace counts 11 when that doesn't go over 21. */
__attribute__((section(".text.func_001D4720")))
int func_001D4720(BlackJack *self)
{
    int total = 0;
    unsigned short aces;
    int i;
    int j;

    for (i = 0; i < self->dealSlot; i++) {
        int rank = self->handA[i]->obj->rank;

        if (rank != 0) {
            if (rank >= 1 && rank <= 9) {
                total += rank + 1;
            } else {
                total += 10;
            }
        }
    }
    aces = 0;
    for (j = 0; j < self->dealSlot; j++) {
        if (self->handA[j]->obj->rank == 0) {
            aces++;
        }
    }
    while (aces != 0) {
        aces--;
        if (aces == 0) {
            if (total + 1 + BJ_ACE_EXTRA <= BJ_BUST) {
                total += 1 + BJ_ACE_EXTRA;
            } else {
                total++;
            }
        } else {
            total++;
        }
    }
    return total;
}
