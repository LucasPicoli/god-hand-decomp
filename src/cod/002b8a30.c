/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageUnit.h"

/* The kind of group: 1 for 0 and the odd groups 1-7, 0 for the even ones
 * 2-8 and anything else. self isn't read. */
__attribute__((section(".text.func_002B8A30")))
int func_002B8A30(cCollisionManager *self, unsigned int group) {
    switch (group) {
    case 0:
    case 1:
    case 3:
    case 5:
    case 7:
        return 1;
    case 2:
    case 4:
    case 6:
    case 8:
        return 0;
    default:
        return 0;
    }
}
