/* cygnus-2.96: ADX manager lock (raise the caller to the ADX priority) and the server wait (0x324C90..). */

#include "godhand/adxm.h"
#include "godhand/globals.h"
#include "godhand/eeKernel.h"

/* The SVM lock callback; arg is unused. */
__attribute__((section(".text.func_00324C90")))
void func_00324C90(int arg)
{
    if (D_003C80E0 == 0) {
        int thid = GetThreadId();

        D_003CF9D0 = ChangeThreadPriority(thid, D_003C80B0.a);
        D_003CF9D4 = thid;
        adxm_ResumeThread(D_003C8138);
        D_003C8138;
    }
    D_003C80E0++;
}

/* The SVM unlock callback; arg is unused. */
__attribute__((section(".text.adxm_unlock")))
void adxm_unlock(int arg)
{
    if (--D_003C80E0 == 0) {
        adxm_SuspendThread(D_003C8138);
        D_003C8138;
        ChangeThreadPriority(GetThreadId(), D_003CF9D0);
    }
    if (D_003C80E0 < 0) {
        D_003C80E0 = 0;
    }
}

__attribute__((section(".text.adxm_goto_svr_border")))
void adxm_goto_svr_border(int thid, int prio)
{
    int i;

    if (thid == 0) {
        return;
    }
    D_003C80E4 = 1;
    ChangeThreadPriority(thid, D_003C80B0.a);
    for (i = 0; ; i++) {
        func_00325290(thid);
        adxm_ResumeThread(thid);
        if (D_003C80E4 == 0) {
            break;
        }
        if (i > 0xBEBC1FF) {
            SVM_CallErr1(D_00451D78);
            break;
        }
    }
    ChangeThreadPriority(thid, prio);
}
