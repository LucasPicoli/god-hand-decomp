/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

/* Count the filled god-item slots among the unlocked ones. */
__attribute__((section(".text.cCoreSave_getGodItemNum")))
unsigned int cCoreSave_getGodItemNum(cCoreSave *self) {
    unsigned int i;
    unsigned int n;

    n = 0;
    for (i = 0; (i < CORESAVE_GOD_ITEM_NUM) && (i < self->data->reelItemNum); i++) {
        if (self->data->godItem[i] != 0) {
            n++;
        }
    }
    return n;
}
