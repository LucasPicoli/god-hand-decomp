/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageUnit.h"

extern void func_002BA250(void *a0);
extern void func_002B8F48(void *a0);

/* func_002BA250, then func_002B8AA8 on every live unit, then func_002B8F48. */
__attribute__((section(".text.func_002B9D58")))
void func_002B9D58(cCollisionManager *self) {
    cCollisionUnit *p;
    func_002BA250(self);
    p = self->head;
    if (p != 0) {
        do {
            func_002B8AA8(p);
            p = p->next;
        } while (p != 0);
    }
    func_002B8F48(self);
}
