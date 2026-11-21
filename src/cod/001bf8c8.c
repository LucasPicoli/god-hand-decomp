/* sn-2.95.3-136: func_001BF8C8, tutorial gimmick task: show the tutorial page for this object, wait for the confirm buttons and the page close, clear the scenario hold flags and advance the object phase. */
#include "godhand/cOmBase.h"
#include "godhand/gameWork.h"
#include "godhand/cScenario.h"
#include "godhand/criStm.h"
#include "godhand/DispMgr.h"
extern void cTaskWork_exit(cTaskWork *self);
extern unsigned int D_00747A78;         /* system flags */

/* A gimmick that shows a tutorial page. */
typedef struct cOmTutorial {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    signed char page;                   /* 0x600 tutorial page, shown as 0x2000 + page */
    char unk601;
    short timer;                        /* 0x602 set to 10 when the page closes */
} cOmTutorial;

__attribute__((section(".text.func_001BF8C8")))
void func_001BF8C8(cOmTutorial *self)
{
    cCockTutorial *tut;
    cScenario *sc;
    int idx;
    signed char state;

    cCockTutorial_TutorialON(&Cockpit->tutorial, self->page + 0x2000);
    cTaskWork_sleep(D_003C2F84->task.cur, 10);
    while ((D_007474A0.trg & 0x30000000) == 0)
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    tut = &Cockpit->tutorial;
    if (tut->unkB8 == 2 || tut->unkB8 == 3)
        tut->unkB8 = 4;
    do {
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
        state = Cockpit->tutorial.unkB8;
    } while (state != 0);
    func_003A52F0(&D_00747A78, 0, 8);
    func_003A52F0((char *)&D_00747A78 + 8, 0, 4);
    sc = D_003C2F84;
    idx = sc->task.curNo;
    if (idx >= 0)
        ((cTaskWork *)(sc->task.works + idx * TASKMGR_WORK_SIZE))->attr &= ~1;
    D_003C2F84->task.flags &= ~1;
    self->timer = 10;
    self->base.phase += 1;
    cTaskWork_exit(D_003C2F84->task.cur);
}
