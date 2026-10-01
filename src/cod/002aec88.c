#include "godhand/cMessage.h"
extern cMessageWin *func_002AEF10(cMessage *self, cMessageWin *win);
/* Delete every window; func_002AEF10 returns the next one. */
__attribute__((section(".text.cMessage_deleteAll")))
void cMessage_deleteAll(cMessage *self) {
    cMessageWin *win = self->head;
    while (win) {
        win = func_002AEF10(self, win);
    }
}
