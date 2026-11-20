/* sn-2.95.3-136 matched TU. */
#include "godhand/EspDataBank.h"

/* Unregister effect data block id: clear the res[] word of each resource it
 * resolves, then its block slot. 1 if the slot held a block, else 0. */
__attribute__((section(".text.func_00306BB0")))
int func_00306BB0(EspDataBank *bank, int id)
{
    EspDataBlock *blk;
    unsigned int i;
    void *res;

    if (id < ESP_BANK_NUM) {
        blk = bank->block[id];
        if (blk == 0) {
            return 0;
        }
        for (i = 0; i < blk->count; i++) {
            if (func_00306A48(blk, i, &res) != 0 && res != 0) {
                bank->res[i] = 0;
            }
        }
        bank->block[id] = 0;
    } else {
        return 0;
    }
    return 1;
}
