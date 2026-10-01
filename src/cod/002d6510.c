/* Hides (`hide` nonzero) or shows the element's children. */
#include "godhand/CustomIDWork.h"
__attribute__((section(".text.CustomIDWork_SetChildNoDisp")))
void CustomIDWork_SetChildNoDisp(CustomIDWork *self, int hide)
{
    CustomIDObj *obj = self->obj;

    if (obj == 0) {
        return;
    }
    if (hide) {
        obj->flags |= CIDW_OBJ_HIDE_CHILD;
    } else {
        obj->flags &= ~CIDW_OBJ_HIDE_CHILD;
    }
}
