#include "godhand/cMessage.h"
extern cMessageWin *func_002AED40(cMessage *self, int messNo);
/* Whether a window is showing message messNo. */
__attribute__((section(".text.cMessage_ckMessage")))
int cMessage_ckMessage(cMessage *self, int messNo) {
    return func_002AED40(self, messNo & 0xFFFF) != 0;
}
