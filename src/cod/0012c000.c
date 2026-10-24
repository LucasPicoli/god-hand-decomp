/* sn-2.95.3-136: func_0012C000, whether a combo set is used up. */
#include "godhand/cCoreSave.h"
#include "godhand/comboObj.h"

extern unsigned char D_005CB010;

/* Whether combo set `set` is used up: it is the holder's current set and the slot has reached the set's size. Set 0 (and any unknown set) also needs D_005CB010 clear. */
__attribute__((section(".text.func_0012C000")))
int func_0012C000(ComboObj *self, unsigned int set)
{
    switch (set) {
    case 0:
    default:
        if (D_005CB010 != 0)
            return 0;
        if (self->set == 0 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 1:
        if (self->set == 1 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 2:
        if (self->set == 2 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 3:
        if (self->set == 3 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 4:
        if (self->set == 4 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 5:
        if (self->set == 5 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    }
}
