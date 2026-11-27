#include "include_asm.h"
#include "godhand/sfdSys.h"

extern void *volatile D_00762054;
extern char D_004595C0[];
extern int D_003EE2E4;                  /* transport work size */
extern void Thunk_func_003394A0(void);  /* j-thunk to SJRBF_Init */
extern long SfdSys_init(SfdSysInit *init);
extern void Call_3571D0_Then_4D048(void);
extern void NoOp_DF58(void);

#define SFTRN_WORK_SIZE 0x37B0

/* Set up the transport work area and the Sofdec system block; when the system
 * init fails, run the teardown hooks and return 0. */
__attribute__((section(".text.SfdSys_initWithWork")))
long SfdSys_initWithWork(SfdSysInit *init)
{
    long ok;

    D_00762054 = D_004595C0;
    D_003EE2E4 = SFTRN_WORK_SIZE;
    Thunk_func_003394A0();
    ok = SfdSys_init(init);
    if (ok != 0)
        return ok;
    Call_3571D0_Then_4D048();
    NoOp_DF58();
    return 0;
}
