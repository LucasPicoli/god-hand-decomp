/* sn-2.95.3-136 matched TU. */

/* Once a frame: when an end was requested and the cutscene allows it, fade out, start the end task and kill the script task. 1 when the scenario ends. */
#include "godhand/cScenario.h"

#define SCEN_LOCK_END      0x20000000   /* D_00747A84 bit: scenario end blocked */
#define SCEN_FADING        0x10         /* D_00747A84 bit: a fade is running (also set here) */
#define SCEN_END_ALLOWED   0x800000     /* D_00747640 bit: the room may be left */
/* D_00747640 is read as an offset from D_00747A84, as retail does (one address register for both). */
#define SCEN_ROOM_WORD(flagsp)  (*(long *)((char *)(flagsp) - 0x444))
#define SCEN_FADE_BLACK    0xFF000000U

extern unsigned int D_00747A84;
extern char D_00747470[];
extern void classFADE_start(void *fade, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void cTaskWork_kill(cTaskWork *work);

__attribute__((section(".text.cScenario_checkEnd")))
int cScenario_checkEnd(cScenario *self) {
    unsigned int flags = D_00747A84;
    unsigned int *flagsp = &D_00747A84;
    long v;
    long fading;
    if (flags & SCEN_LOCK_END) {
        return 0;
    }
    v = flags;
    fading = (v >> 4) & 1;
    if (fading != 0) {
        return 1;
    }
    if (self->endReq == 0) {
        return 0;
    }
    if ((SCEN_ROOM_WORD(flagsp) & SCEN_END_ALLOWED) == 0) {
        return 0;
    }
    D_00747A84 = flags | SCEN_FADING;
    classFADE_start(D_00747470, 0, 8, 0, 0, SCEN_FADE_BLACK, 0xF);
    cScenario_taskExec_2C3890(self, cScenario_endTask, 0);
    cTaskWork_kill((cTaskWork *)(D_003C2F84->task.works + D_003C2F84->scriptTaskNo * TASKMGR_WORK_SIZE));
    self->endReq = 0;
    return 1;
}
