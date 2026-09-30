/* cCoreSave_addCasinoTicket - add casino tickets, clamped to [0, 9]. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_addCasinoTicket")))
void cCoreSave_addCasinoTicket(cCoreSave *self, int num) {
    if (!self->data)
        return;
    self->data->casinoTicketNum += num;
    if (self->data->casinoTicketNum > CORESAVE_KEY_MAX)
        self->data->casinoTicketNum = CORESAVE_KEY_MAX;
    if (self->data->casinoTicketNum < 0)
        self->data->casinoTicketNum = 0;
}
