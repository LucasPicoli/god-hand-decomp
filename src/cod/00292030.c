/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEmManage.h"

__attribute__((section(".text.NoOp_33E6A8")))
void NoOp_33E6A8(void) {}

__attribute__((section(".text.NoOp_33E6B0")))
void NoOp_33E6B0(void) {}

/* Raises the slot wait to at least wait. */
__attribute__((section(".text.cEmManage_SetSlotWait")))
void cEmManage_SetSlotWait(cEmManage *self, int wait)
{
    if (self->slotWait < wait)
        self->slotWait = wait;
}
