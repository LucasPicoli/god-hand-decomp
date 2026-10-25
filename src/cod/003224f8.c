/* ee-2.9-991111 matched TU. */

#include "godhand/ehFrameObj.h"

extern void func_003A7B48(void);
extern void UpdateGlobalPtrWithParam_3A7CC0(void *);

/* gcc frame.c: unlink the object registered with `begin`, free its sorted FDE array, return it. */
__attribute__((section(".text.__deregister_frame_info")))
void *__deregister_frame_info(void *begin)
{
    struct object **p = &D_00755C18;

    while (*p) {
        if ((*p)->fde_begin == begin) {
            struct object *ob = *p;
            *p = (*p)->next;
            if (ob->pc_begin)
                UpdateGlobalPtrWithParam_3A7CC0(ob->fde_array);
            return (void *)ob;
        }
        p = &((*p)->next);
    }
    func_003A7B48();
}
