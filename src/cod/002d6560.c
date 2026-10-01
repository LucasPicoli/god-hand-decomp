/* Sets the message number the element shows. */
#include "godhand/CustomIDWork.h"
__attribute__((section(".text.CustomIDWork_SetMessNo")))
void CustomIDWork_SetMessNo(CustomIDWork *self, int messNo)
{
    CustomIDObj *obj = self->obj;

    if (obj) {
        obj->messNo = messNo;
    }
}
