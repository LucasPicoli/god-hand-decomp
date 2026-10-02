/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

/* Raises the unk510 wait to at least wait. */
__attribute__((section(".text.func_00292018")))
void func_00292018(cEmManage *self, int wait) {
    if (self->unk510 < wait) self->unk510 = wait;
}
