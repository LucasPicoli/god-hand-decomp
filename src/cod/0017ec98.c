/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"

extern int espSys_effDataRegist(void *table, int id, void *data);
extern int SetEffect(int kind, int id, void *obj, int a3, int a4, unsigned int a5);
extern char D_007419A0[];
extern void cCollisionSolidManage_CreateUnit(void *mgr, void *owner, int kind, float radius);
extern void cCollisionSolidManage_CreateSphere(void *mgr, void *owner, void *body, void *centre, float radius);

#define EFFDATA_ID 0x27D






/* Init of an object that owns effect data 0x27D: base init, register the
 * data record, start the effect on the object. */
__attribute__((section(".text.cOmBase_initEffData27D")))
int cOmBase_initEffData27D(cOmBase *self)
{
    int res;

    func_001B6FB8(self);
    res = (int)self->pack;
    espSys_effDataRegist(D_007419A0, EFFDATA_ID, (void *)(*(int *)(res + 0xC) + res));
    SetEffect(EFFDATA_ID, 1, self, 0, -1, 0xFFFFFFFF);
    return 1;
}

#define COMBASE_F2_SOLID  0x8           /* flags2 bit 3 */




extern int D_00462FC0;                  /* collision solid manager */

/* Init of an object with one collision sphere: base init, mark it solid, register
 * the unit and a sphere centred half a unit above its origin, reset the mode byte. */
__attribute__((section(".text.cOmBase_initSphereBody")))
int cOmBase_initSphereBody(cOmBase *self)
{
    cVec centre;

    func_001B6FB8(self);
    self->flags2 |= COMBASE_F2_SOLID;
    cCollisionSolidManage_CreateUnit(&D_00462FC0, self, 6, 0.1f);
    centre.x = 0.0f;
    centre.y = 0.5f;
    centre.z = 0.0f;
    centre.w = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->mtx, &centre, 0.4f);
    self->mode = 0;
    return 1;
}

#define STEP_TYPE_SCRIPT 2

/* A script step record: the high bit of its first halfword picks the kind. */
typedef struct ScriptCmd {
    unsigned short word;                /* 0x00 bit 15 set = wait command */
} ScriptCmd;

/* A script runner: the clock at 0x68, the step type at 0xC, the next
 * command pointer at 0x8C and the next command's time at 0x90. */
typedef struct ScriptRun {
    char unk00[0xC];
    unsigned char type;                 /* 0x0C */
    char unk0D[0x5B];
    int clock;                          /* 0x68 */
    char unk6C[0x20];
    ScriptCmd *cmd;                     /* 0x8C */
    int cmdTime;                        /* 0x90 */
} ScriptRun;

extern void func_002B33D8(ScriptRun *run);

extern void func_002B4768(ScriptRun *run, int *time, ScriptCmd **cmd);

/* Run every command that is due (its time is not past the clock). A wait
 * command that accepts stops the run and moves the clock to its time. The
 * step runs as the loop's increment, so `continue` skips to the next command. */
__attribute__((section(".text.ScriptRun_runDueCommands")))
void ScriptRun_runDueCommands(ScriptRun *run)
{
    for (;; func_002B4768(run, &run->cmdTime, &run->cmd)) {
        if (run->cmdTime > run->clock)
            break;
        if (run->type != STEP_TYPE_SCRIPT)
            break;
        if ((run->cmd->word >> 15) == 0) {
            func_002B33D8(run);
            continue;
        }
        if (func_002B34D8(run) != 0) {
            run->clock = run->cmdTime;
            break;
        }
    }
}
