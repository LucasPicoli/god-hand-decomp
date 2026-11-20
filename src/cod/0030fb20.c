#include "godhand/vu0.h"
#include "godhand/sideCounter.h"
#include "godhand/objFactory.h"

/* Register the new object (func_0030FCC0) and return it; when a list is full,
 * delete it through its vtable (entry 1, mode 3). id is not read. */
__attribute__((section(".text.func_0030FB20")))
void *func_0030FB20(int id, cObj *obj)
{
    if (obj != 0) {
        if (func_0030FCC0(obj) != 0)
            return obj;
        CVCALL_FN(obj, 1, void (*)(void *, int))(CVCALL_THIS(obj, 1), 3);
    }
    return 0;
}
