/* sn-2.95.3-136 matched TU. */
#include "godhand/PanelObj.h"
#include "godhand/gameWork.h"

/* Set element 8's local x to its left (left != 0) or right x for the
 * language: languages 1-6 use the second pair, language 0 and anything out
 * of range the first. */
__attribute__((section(".text.func_001DF7D0")))
void func_001DF7D0(PanelObj *self, int left)
{
    int x;

    switch (D_007474A0.language) {
    case 0:
    default:
        x = left ? -0x61 : 0x12;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        x = left ? -0x4F : 0x19;
        break;
    }
    CustomIDWork_SetLocalPosX(&self->elem[8], x);
}
