/* sn-2.95.3-136: func_0028E858, event handler: reset this object and the player, play the event sound and cut,
 * then fade out and end the soft event (moving the scenario on with heading 0x43 when the flag at 0xBEC is
 * clear). */
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/classFADE.h"
#include "godhand/cScenario.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"

#define EVENT_FADE_TIME  15

extern unsigned char D_005FEE00[];
extern char *D_003C23A4;

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int cSnd_SeFadeOut(void *a0, int a1, short a2);
extern void cTaskWork_exit(cTaskWork *task);
extern void func_002C45A8(cScenario *self, int no, cVec *pos, float arg);

__attribute__((section(".text.func_0028E858")))
void func_0028E858(cGameObj *self)
{
    cGameObj *pl;
    int se;
    cVec v;

    self->vt->reset((char *)self + self->vt->resetDelta, 0);
    pl = Getplayer();
    pl->vt->reset((char *)pl + pl->vt->resetDelta, 0);
    se = cSnd_SeCall_2CBA48(D_005FEE00, 1, 0, self, 0, 0, 0, 0);
    cScenario_execUpCut(D_003C2F84, 0x3004, 0, 0, 0, 1);
    cSnd_SeFadeOut(D_005FEE00, se, EVENT_FADE_TIME);
    if (*(short *)(D_003C23A4 + 0xBEC) == 0) {
        classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, EVENT_FADE_TIME);
        cTaskWork_sleep(D_003C2F84->task.cur, EVENT_FADE_TIME);
        cScenario__endSoftEvent(D_003C2F84);
        v.x = 2.0f;
        v.y = 1.61f;
        v.z = 0.0f;
        v.w = 1.0f;
        /* the heading is passed as an int */
        func_002C45A8(D_003C2F84, 0x43, &v, (int)v.z);
    } else {
        cScenario__endSoftEvent(D_003C2F84);
    }
    cTaskWork_exit(D_003C2F84->task.cur);
}
