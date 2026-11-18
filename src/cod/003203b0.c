/* ee-2.9-991111 matched TU. */

#include "godhand/eh.h"

extern int D_00755C08;                  /* set once the context is initialised */
extern struct eh_context D_00755BF8;    /* the context */
extern void *D_00755C10[2];             /* top_elt, the first dynamic handler chain entry */

__attribute__((section(".text.eh_context_static")))
struct eh_context *eh_context_static(void) {
    if (D_00755C08 == 0) {
        D_00755C08 = 1;
        func_003A52F0(&D_00755BF8, 0, sizeof(struct eh_context));
        D_00755BF8.dynamic_handler_chain = D_00755C10;
    }
    return &D_00755BF8;
}
