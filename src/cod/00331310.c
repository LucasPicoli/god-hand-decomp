/* cygnus-2.96: srd_wait_hst, polls an IOP request until it completes, with an error state and a spin timeout. */
#include "godhand/iopReq.h"
#include "godhand/globals.h"
extern void PushGlobalD8478History_331C78(int tag);
extern int func_00331E70(int handle, int mode, int *busy);
extern void func_003312B8(void);
extern void func_003B1F28(char *msg);

__attribute__((section(".text.srd_wait_hst")))
void srd_wait_hst(IopReq *req)
{
    int busy = 1;
    int n = 0;
    int r;

    for (;;) {
        if (busy != 1)
            return;
        PushGlobalD8478History_331C78(0x1100);
        r = func_00331E70(req->handle, 1, &busy);
        PushGlobalD8478History_331C78(0x1101);
        if (r < 0) {
            req->state = 9;
            req->err = r;
            return;
        }
        func_003312B8();
        n++;
        if (n > 0x9000) {
            func_003B1F28(D_00453E90);
            return;
        }
    }
}
