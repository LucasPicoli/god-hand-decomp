#include "godhand/adxmThread.h"
#include "godhand/globals.h"
extern int ChangeThreadPriority(int tid, int prio);
extern int WakeupThread(int tid);
extern int adxm_ResumeThread(int tid);

__attribute__((section(".text.func_00325A58")))
void func_00325A58(void)
{
    if (D_003C80F0 == 1) {
        while (D_003C8190 == 0)
            ;
    } else {
        D_003C81CC = 0;
        while (D_003C8190 == 0) {
            D_003C8188 = 1;
            ChangeThreadPriority(D_003C8144, 1);
            WakeupThread(D_003C8144);
            adxm_ResumeThread(D_003C8144);
            D_003C81CC++;
        }
    }
    D_003C8190 = 0;
    D_003C8188 = 0;
    D_003C8144 = 0;
}
