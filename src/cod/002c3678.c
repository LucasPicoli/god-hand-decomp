/* sn-2.95.3-136 matched TU. */
#include "godhand/cScenario.h"

extern int D_007474A0;
extern int D_00747A2C;
extern int D_005FEA60;
extern char *Getplayer(void);
extern void func_002C14F8(int *a0);
extern void func_002D5358(cTaskManager *task);

__attribute__((section(".text.cScenario_move")))
/* Every frame: track the player's death, then run the room script and
 * the script tasks unless the game is paused. */
void cScenario_move(cScenario *self)
{
    char *g = (char *)&D_007474A0;

    if (*(unsigned short *)(g + 0x5B0) != 0x20) {
        if (Getplayer() != 0) {
            long t = (unsigned int)self->task.flags;
            if (((t >> 1) & 1) == 0) {
                if (*(short *)(Getplayer() + 0x54A) <= 0) {
                    /* Stored through an int: as a struct store, the
                     * D_003C2F84 load below is scheduled above it. */
                    *(int *)&self->task.flags = self->task.flags | SCENARIO_F_PL_DEAD;
                    cScenario_endMess(D_003C2F84);
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) | 0x100000;
                }
            } else {
                if (*(short *)(Getplayer() + 0x54A) > 0) {
                    self->task.flags = self->task.flags & ~SCENARIO_F_PL_DEAD;
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) & 0xFFEFFFFF;
                }
            }
        }
    }

    if (*(int *)&D_00747A2C >= 0) {
        char *o = (char *)&D_00747A2C;
        unsigned long w8;
        if ((*(int *)(o + 0x58) & 0x8000000) == 0 &&
            (w8 = *(int *)(o - 0x8), ((w8 >> 3) & 1) == 0) &&
            (*(int *)(o + 0x4C) & 0x10000) == 0 &&
            (*(int *)(o + 0x4) & 1) == 0) {
            cTaskManager *p = &self->task;
            long t2 = (unsigned int)self->task.flags;
            if (((t2 >> 1) & 1) == 0) {
                void (*fp)(void);
                func_002C14F8(&D_005FEA60);
                fp = self->script->move;
                if (fp)
                    (*fp)();
                func_002D5358(p);
                cScenario_checkEnd(self);
            } else {
                void (*fp)(void);
                fp = self->script->move;
                if (fp)
                    (*fp)();
                func_002D5358(p);
            }
        }
    }
}
