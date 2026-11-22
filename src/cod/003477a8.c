/* cygnus-2.96: func_003477A8, queues a read request of size bytes on an open stream handle,
 * counting successful requests and flagging the handle on failure. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"
extern int GetField0OrZero_346828(MwsfdHn *hn);
extern int func_003355C8(void *sj, int size);

__attribute__((section(".text.func_003477A8")))
void func_003477A8(MwsfdHn *hn, int size)
{
    if (GetField0OrZero_346828(hn) != 1) {
        MWSFSVM_Error(D_00458E80);
        return;
    }
    if (size == 0) {
        MWSFSVM_Error(D_00458EB0);
        return;
    }
    if (func_003355C8(hn->stm, size) < 0) {
        hn->stat = 4;
        MWSFSVM_Error(D_00458EE0, size);
        return;
    }
    hn->nreq++;
}
