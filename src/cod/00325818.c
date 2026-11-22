#include "godhand/adxmThread.h"
#include "godhand/globals.h"
extern void func_003257C8(void);
extern void func_003258B8(void);
extern void func_00325A58(void);
extern void func_00325988(void);
extern void func_00325B90(void);
extern int ChangeThreadPriority(int tid, int prio);
extern void Obj0000_Set_D_007588A0_Pair_33BC18(int a, int b);
extern void Obj0000_Set_D_007588A8_XY_33BC30(int x, int y);
extern void SVM_Finish(void);

__attribute__((section(".text.ADXM_ShutdownThrd")))
void ADXM_ShutdownThrd(void)
{
    if (--D_003C80A4 == 0) {
        func_003257C8();
        func_003258B8();
        func_00325A58();
        func_00325988();
        func_00325B90();
        ChangeThreadPriority(D_003C8148, D_003CF9D8);
        Obj0000_Set_D_007588A0_Pair_33BC18(0, 0);
        Obj0000_Set_D_007588A8_XY_33BC30(0, 0);
        SVM_Finish();
    }
}
