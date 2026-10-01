#include "godhand/cMessage.h"
extern cMessageWin *cMessage_searchWorkId(cMessage *self, unsigned short workId);
extern cMessageWin *func_002AEF10(cMessage *self, cMessageWin *win);
/* Delete the window with this work id. 1 if it existed. */
__attribute__((section(".text.cMessage_deleteWorkId")))
int cMessage_deleteWorkId(cMessage *self, unsigned short workId)
{
    cMessageWin *win;
    win = cMessage_searchWorkId(self, workId);
    if (win == 0) {
        return 0;
    }
    func_002AEF10(self, win);
    return 1;
}

extern cMessageWin *func_002AED40(cMessage *self, unsigned short messNo);
/* Delete the window showing message messNo. 1 if it existed. */
__attribute__((section(".text.cMessage_deleteMessNo")))
int cMessage_deleteMessNo(cMessage *self, unsigned short messNo)
{
    cMessageWin *win;
    win = func_002AED40(self, messNo);
    if (win == 0) {
        return 0;
    }
    func_002AEF10(self, win);
    return 1;
}
#include "include_asm.h"


extern void func_002B2400(cMessageWin *win);
/* Close every open window. */
__attribute__((section(".text.cMessage_closeAll")))
void cMessage_closeAll(cMessage *self) {
    cMessageWin *win = self->head;
    while (win) {
        func_002B2400(win);
        win = win->next;
    }
}
