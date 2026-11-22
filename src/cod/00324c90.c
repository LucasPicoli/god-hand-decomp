/* cygnus-2.96: ADX manager lock (raise the caller to the ADX priority) and the server wait (0x324C90..). */

#include "godhand/adxm.h"
#include "godhand/globals.h"

extern int GetThreadId(void);
extern int ChangeThreadPriority(int thid, int prio);

__attribute__((section(".text.func_00324C90")))
void func_00324C90(void)
{
    if (D_003C80E0 == 0) {
        int thid = GetThreadId();

        D_003CF9D0 = ChangeThreadPriority(thid, D_003C80B0);
        D_003CF9D4 = thid;
        adxm_ResumeThread(D_003C8138);
        D_003C8138;
    }
    D_003C80E0++;
}

__attribute__((section(".text.func_00324D18")))
void func_00324D18(void)
{
    if (--D_003C80E0 == 0) {
        func_00325360(D_003C8138);
        D_003C8138;
        ChangeThreadPriority(GetThreadId(), D_003CF9D0);
    }
    if (D_003C80E0 < 0) {
        D_003C80E0 = 0;
    }
}

__attribute__((section(".text.func_00324D88")))
void func_00324D88(int thid, int prio)
{
    int i;

    if (thid == 0) {
        return;
    }
    D_003C80E4 = 1;
    ChangeThreadPriority(thid, D_003C80B0);
    for (i = 0; ; i++) {
        func_00325290(thid);
        adxm_ResumeThread(thid);
        if (D_003C80E4 == 0) {
            break;
        }
        if (i > 0xBEBC1FF) {
            func_0033B790(D_00451D78);
            break;
        }
    }
    ChangeThreadPriority(thid, prio);
}
