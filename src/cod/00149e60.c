#include "godhand/cModel.h"

/* sn-2.95.3-136 matched TU. */

extern void func_00150100(cParts *part);

/* sn-2.95.3-136 matched TU. */



/* Free every part of the model's part list and empty the list. The next
 * pointer is read before the free, as the free would clobber it. */
__attribute__((section(".text.func_00149E60")))
void func_00149E60(cModel *self) {
    cParts *part = self->next;
    while (part != 0) {
        cParts *cur = part;
        part = part->next;
        func_00150100(cur);
    }
    self->next = 0;
}
