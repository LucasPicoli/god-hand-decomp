/* cygnus-2.96 matched TU. */
#include "godhand/adxm.h"
#include "godhand/adxmThread.h"
#include "godhand/criCbTbl.h"
#include "godhand/eeKernel.h"
#include "godhand/globals.h"

#define SVM_CB_ADXM 6           /* the SVM callback slot the ADX server step takes */

extern const char *volatile D_003C80A0;    /* "ADXPS2 Ver.2.63 Build:..." banner pointer */

/* Set up the ADX manager threads, the first time in: the lock callbacks,
 * the priorities (the caller's or the defaults), the four server threads,
 * and the server step on SVM. */
__attribute__((section(".text.func_00325638")))
void func_00325638(AdxmInitArg *arg)
{
    struct ThreadParam info;

    D_003C80A0;
    D_003C80FC = 0;
    if (D_003C80A4 == 0) {
        func_0033BE80();
        Obj0000_Set_D_007588A0_Pair_33BC18(func_00324C90, 0);
        Obj0000_Set_D_007588A8_XY_33BC30(adxm_unlock, 0);
        D_00755C20.fn = 0;
        D_00755C20.arg = 0;
        D_00755C28.fn = 0;
        D_00755C28.arg = 0;
        if (arg == 0) {
            D_003C80B0.prio = ADXM_DEF_PRIO;
            D_003C80B0.a = ADXM_DEF_A;
            D_003C80B0.b = ADXM_DEF_B;
            D_003C80B0.d = ADXM_DEF_D;
            D_003C80B0.e = ADXM_DEF_E;
            D_003C80B0.g = ADXM_DEF_G;
        } else {
            D_003C80B0.prio = arg->prio;
            D_003C80B0.a = arg->a;
            D_003C80B0.b = arg->b;
            D_003C80B0.d = arg->d;
            D_003C80B0.e = arg->e;
            D_003C80B0.g = arg->g;
        }
        D_003C8148 = GetThreadId();
        ReferThreadStatus(D_003C8148, &info);
        D_003CF9D8 = info.currentPriority;
        func_003253C0();
        func_00325468();
        func_003254F0();
        func_00325578();
        ChangeThreadPriority(D_003C8148, D_003C80B0.prio);
        SVM_SetCbBdr(SVM_CB_ADXM, Forward324D88_324E70, 0);
    }
    D_003C80A4++;
}
