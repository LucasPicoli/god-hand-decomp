/* CreateEventObj — build an event object (func_00312AB0) and register it
 * (func_0030FB20), returning it.  sn-2.95.3-136. */
#include "godhand/objFactory.h"

__attribute__((section(".text.CreateEventObj")))
void *CreateEventObj(int id, int dataId) {
    return func_0030FB20(id, func_00312AB0(id, dataId));
}
