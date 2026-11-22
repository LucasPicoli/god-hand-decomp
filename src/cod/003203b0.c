/* ee-2.9-991111 matched TU. */

#include "godhand/eh.h"
#include "godhand/globals.h"

__attribute__((section(".text.eh_context_static")))
struct eh_context *eh_context_static(void) {
    if (D_00755C08 == 0) {
        D_00755C08 = 1;
        func_003A52F0(&D_00755BF8, 0, sizeof(struct eh_context));
        D_00755BF8.dynamic_handler_chain = D_00755C10;
    }
    return &D_00755BF8;
}
