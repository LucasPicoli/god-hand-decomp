/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

#include "godhand/sync.h"

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern char D_0045FE40[];

extern int CreateSema(struct SemaParam *param);
extern int DeleteSema(int semid);
extern int WaitSema(int semid);
extern unsigned int TimerUSec2BusClock(unsigned int sec, unsigned int usec);

extern int func_003B0D20(int a0, int a1, int a2, int semid);

__attribute__((section(".text.func_003B0AE0")))
int func_003B0AE0(unsigned int usec)
{
    struct SemaParam sp;
    int semid;
    int alid;
    unsigned int stat;

    GH_MFC0_STATUS(stat);
    if ((stat & 0x10000) == 0) {
        return 0x80008008;
    }
    sp.maxCount = 1;
    sp.option = (unsigned int)D_0045FE40;
    sp.initCount = 0;
    semid = CreateSema(&sp);
    if (semid < 0) {
        return 0x80008003;
    }
    alid = func_003B7768(TimerUSec2BusClock(0, usec), (void *)func_003B0D20,
                         (void *)semid);
    if (alid < 0) {
        DeleteSema(semid);
        return alid;
    }
    WaitSema(semid);
    DeleteSema(semid);
    return 0;
}
