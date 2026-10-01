#include "godhand/cMessage.h"
extern cMessageWin *func_002AED40(cMessage *self, int messNo);
extern void func_002B2400(cMessageWin *win);
/* Close the window showing message messNo. 1 if it existed. */
__attribute__((section(".text.cMessage_closeMessNo")))
int cMessage_closeMessNo(cMessage *self, int messNo) {
    cMessageWin *win = func_002AED40(self, messNo & 0xFFFF);
    if (!win)
        return 0;
    func_002B2400(win);
    return 1;
}
