/* sn-2.95.3-136: func_0030DA08, play boot movie 0 and wait it out, then queue the two boot tasks. */
#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"
#include "godhand/cMovie.h"

extern void cTaskWork_exit(cTaskWork *self);
extern char D_005E79D0[];               /* the movie manager */
extern cTaskManager D_00752C00;

extern void cTaskWork_sleep(char *w, int n);
extern int cTaskManager_execute(cTaskManager *mgr, void (*fn)(void), int pri);
extern void func_002A5998(void);
extern void func_0030D5C8(int a0, int a1);

__attribute__((section(".text.func_0030DA08")))
void func_0030DA08(void)
{
    int id = cMovie_Start(D_005E79D0, 0, 1);

    while (cMovie_GetStatus(D_005E79D0, id) != 0)
        cTaskWork_sleep(D_00752C00.cur, 1);
    cMovie_Stop(D_005E79D0, id);
    cTaskManager_execute(&D_00752C00, func_002A5998, 0);
    cTaskManager_execute(&D_00752C00, func_0030D5C8, 3);
    cTaskWork_exit(D_00752C00.cur);
}
