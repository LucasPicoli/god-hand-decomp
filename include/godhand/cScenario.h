/* include/godhand/cScenario.h - cScenario, the script runner for events.
 *
 * One cScenario (pointed at by D_003C2F84) runs the scripted side of the
 * game: soft events that freeze play around a camera move or a message,
 * room jumps, and the casino and Kurohuku battles. Script steps run as
 * tasks in the embedded task manager; a step that waits sleeps its task
 * until the camera move or the message is over.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding; the
 * record is at least 0x114 bytes and its real size is not known.
 *
 * A load through a cScenario field carries the struct's alias set, so gcc
 * may schedule it across stores to plain int globals. Where retail keeps
 * such a load below those stores, the body reads through an int view.
 */
#ifndef GODHAND_CSCENARIO_H
#define GODHAND_CSCENARIO_H

#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"

/* task.flags bits. */
#define SCENARIO_F_SOFT_EVENT  0x1   /* a soft event is running */
#define SCENARIO_F_PL_DEAD     0x2   /* the player's vitality reached 0 */

/* cTaskWork.attr bit: the task belongs to a soft event. */
#define SCENARIO_TASK_SOFT_EVENT  0x1

#define SCENARIO_NO_MESS  0xFFFF    /* messNo when no message is up */

/* softEventType (the game's eSoftEventType). The values are retail's; what
 * each does is read from cScenario_startSoftEvent:
 *   0, 1, 3  hide models, suspend the objects, camera on hold
 *   2        set the D_00747A78 lock bits only
 *   4        hold the player; endSoftEvent resets them
 *   5        only reset the hidden models */

/* Per task slot: the caller that started the task leaves a word here. */
typedef struct cScenarioTaskData {
    int unk0;
    int owner;                    /* 0x4 */
} cScenarioTaskData;

/* The room script the scenario runs. */
typedef struct cScenarioScript {
    char unk00[0xC];
    void (*move)(void);           /* 0x0C run every frame by cScenario_move */
} cScenarioScript;

typedef struct cScenario {
    char unk00[0x1C];
    cTaskManager task;            /* 0x1C script steps; flags holds SCENARIO_F_* */
    char unk50[4];
    cScenarioTaskData taskData[16]; /* 0x54 one per task slot, cleared at start */
    cScenarioScript *script;      /* 0xD4 */
    unsigned short upCutNo;       /* 0xD8 execUpCut: cut number */
    char unkDA[2];
    int upCutCam;                 /* 0xDC execUpCut: camera data, 0 for none */
    int softEventType;            /* 0xE0 */
    unsigned char upCutAsTask;    /* 0xE4 execUpCut: run the cut as its own task */
    unsigned char upCutArg;       /* 0xE5 */
    char unkE6[2];
    short softEventDepth;         /* 0xE8 startSoftEvent nesting count */
    char unkEA[2];
    void (*roomExitFunc)(void *); /* 0xEC run once when the room is left */
    void *roomExitArg;            /* 0xF0 */
    void (*exitFunc)(void *);     /* 0xF4 run once when the scenario is released */
    void *exitArg;                /* 0xF8 */
    void *nextTask;               /* 0xFC entry the end task starts, 0 for none */
    void *nextTaskArg;            /* 0x100 */
    char unk104[4];
    unsigned char endReq;         /* 0x108 checkEnd starts the end task */
    signed char endFlagNo;        /* 0x109 bit set in D_00747A8C at the end, 0..63 */
    char unk10A[2];
    int scriptTaskNo;             /* 0x10C task slot the script runs in */
    unsigned char fadeOnEnd;      /* 0x110 fade the screen out at the end */
    unsigned char camOn;          /* 0x111 a setCam camera move is running */
    unsigned short messNo;        /* 0x112 SCENARIO_NO_MESS when none */
} cScenario;

#define SCENARIO_OFFSET(field) ((int)&((cScenario *)0)->field)
typedef char cScenario_chk_task[SCENARIO_OFFSET(task) == 0x1C ? 1 : -1];
typedef char cScenario_chk_flags[SCENARIO_OFFSET(task.flags) == 0x48 ? 1 : -1];
typedef char cScenario_chk_script[SCENARIO_OFFSET(script) == 0xD4 ? 1 : -1];
typedef char cScenario_chk_depth[SCENARIO_OFFSET(softEventDepth) == 0xE8 ? 1 : -1];
typedef char cScenario_chk_slot[SCENARIO_OFFSET(scriptTaskNo) == 0x10C ? 1 : -1];
typedef char cScenario_chk_upcut[SCENARIO_OFFSET(upCutAsTask) == 0xE4 ? 1 : -1];
typedef char cScenario_chk_mess[SCENARIO_OFFSET(messNo) == 0x112 ? 1 : -1];

/* The game's one scenario. */
extern cScenario *D_003C2F84;

/* Methods, in address order. */
void cScenario_move(cScenario *self);
void cScenario_release(cScenario *self);
int cScenario_taskExec_2C3890(cScenario *self, void *entry, int slot);
int cScenario_taskExec_2C38D8(cScenario *self, void *entry, void *arg, int slot);
int cScenario_taskExec(cScenario *self, void *entry, void *arg, int slot);
void cScenario_clearTaskData(cScenario *self, int no);
void cScenario_startSoftEvent(cScenario *self, int type);
void cScenario__endSoftEvent(cScenario *self);
int cScenario_isEventStartOk(cScenario *self);
void cScenario_waitEventStartOk(cScenario *self);
int cScenario_setCam(cScenario *self, const char *name);
int cScenario_startCamMotion(cScenario *self, int camData);
void cScenario_resetCam(cScenario *self);
int cScenario_isCamEnd(cScenario *self);
void cScenario_waitCam(cScenario *self);
void cScenario_execUpCut(cScenario *self, unsigned short no, const char *camName, int asTask,
                         unsigned char arg, int slot);
void cScenario_execUpCutData(cScenario *self, int no, int camData, int asTask,
                             unsigned char arg, int slot);
void cScenario_setMess(cScenario *self, unsigned int mess);
int cScenario_isMessOn(cScenario *self);
void cScenario_endMess(cScenario *self);
void cScenario_waitMess(cScenario *self);
void cScenario_moveObjPos(cScenario *self, char *gameObj, float x, float y, float z, float angle);
void cScenario_SetRoomExitFunc(cScenario *self, void (*func)(void *), void *arg);
void cScenario_SetExitFunc(cScenario *self, void (*func)(void *), void *arg);
void cScenario_runExitFunc(cScenario *self);
void cScenario_runRoomExitFunc(cScenario *self);
int cScenario_checkEnd(cScenario *self);
void cScenario_endTask(void);
void cScenario_setOmSuspend(cScenario *self, int suspend);
int cScenario_isOmBreak(cScenario *self, struct cOmBase *om);
int cScenario_isOmBreak_2C5168(cScenario *self, const char *name);
int cScenario_isOmBreak_2C51E8(cScenario *self, long name);
int cScenario_isOmBreak_2C5220(cScenario *self, unsigned short no, const char *name);
int cScenario_isOmBreak_2C5288(cScenario *self, unsigned short no, long name);
void cScenario_setOmBreak(cScenario *self, const char *name);
void cScenario_setOmBreak_2C5318(cScenario *self, long name);

#endif /* GODHAND_CSCENARIO_H */
