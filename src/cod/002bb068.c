/* ee-2.9-991111 matched TU. */

#include "godhand/cDamageUnit.h"

/* The slot holding key, or 0. */
__attribute__((section(".text.func_002BB068")))
KeySlot *func_002BB068(KeySlot *tbl, int key) {
    unsigned int i = 0;
    do {
        if (tbl->key == key) return tbl;
        tbl++;
    } while (++i < 4);
    return 0;
}

/* The first free slot, or 0. */
__attribute__((section(".text.func_002BB098")))
KeySlot *func_002BB098(KeySlot *tbl) {
    unsigned int i = 0;
    do {
        if (tbl->key == 0) return tbl;
        tbl++;
    } while (++i < 4);
    return 0;
}
