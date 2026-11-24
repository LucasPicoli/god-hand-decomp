/* ee-2.9-991111 matched TU. */

#include "godhand/cDamageUnit.h"

/* The value stored under key, or 0. */
__attribute__((section(".text.func_002BB138")))
int func_002BB138(KeySlot *tbl, int key)
{
    KeySlot *h = func_002BB068(tbl, key);
    if (h == 0) return 0;
    return h->value;
}
