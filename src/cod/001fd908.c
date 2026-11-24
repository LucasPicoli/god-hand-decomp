/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

/* The collision group of a damage unit: 1 to 8 by unit kind (0-3), the odd one for a give, the even one otherwise; 0 for any other kind. */
__attribute__((section(".text.func_001FD908")))
int func_001FD908(cDamageUnit *self)
{
    int a, b, c;

    switch (self->unitKind) {
    case 0:
        c = self->type;
        a = 1;
        b = 2;
    tail: /* retail tests the type once, here, for every arm; break and one test after the switch is 2 words short and 19 off */
        return (c == CDAMAGE_TYPE_GIVE) ? a : b;
    case 1:
        c = self->type;
        a = 3;
        b = 4;
        goto tail;
    case 2:
        c = self->type;
        a = 5;
        b = 6;
        goto tail;
    case 3:
        c = self->type;
        a = 7;
        b = 8;
        goto tail;
    case 4:
    default:
        return 0;
    }
}
