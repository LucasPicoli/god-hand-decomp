/* cCoreSave_subGold - take gold away, clamped to [0, CORESAVE_GOLD_MAX]. The
 * infinite-money cheat (D_00747A34 & 0x2000000) pins it at the cap. */
#include "godhand/cCoreSave.h"

extern int D_00747A34;

__attribute__((section(".text.cCoreSave_subGold")))
void cCoreSave_subGold(cCoreSave *self, int amount) {
    if (!self->data)
        return;
    self->data->gold -= amount;
    if (self->data->gold > CORESAVE_GOLD_MAX)
        self->data->gold = CORESAVE_GOLD_MAX;
    if (self->data->gold < 0)
        self->data->gold = 0;
    if (D_00747A34 & 0x2000000)
        self->data->gold = CORESAVE_GOLD_MAX;
}
