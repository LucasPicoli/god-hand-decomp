/* TU: CustomIDWork [id] - recovered C++ class. */
#include "godhand/CustomIDWork.h"

/* Shows the element when `show` is 1, hides it otherwise. */
__attribute__((section(".text.CustomIDWork_SetDisp")))
void CustomIDWork_SetDisp(CustomIDWork *self, int show) {
    CustomIDObj *obj = self->obj;
    if (obj != 0) {
        if ((show ^ 1) != 0) {
            obj->flags |= CIDW_OBJ_HIDE;
        } else {
            obj->flags &= ~CIDW_OBJ_HIDE;
        }
    }
}

/* Sets the number the element displays. */
__attribute__((section(".text.CustomIDWork_SetNumber")))
void CustomIDWork_SetNumber(CustomIDWork *self, int number) {
    CustomIDObj *obj = self->obj;
    if (obj != 0) {
        obj->number = number;
    }
}
