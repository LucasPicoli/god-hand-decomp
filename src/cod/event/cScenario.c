/* TU: cScenario [event] - recovered C++ class. */
#include "godhand/cScenario.h"

extern int func_002D5580(cTaskManager *task, void *entry, void *arg, int slot);
extern void cTaskWork_sleep(cTaskWork *work, int a1);
extern int SearchCameraData(const char *name);

extern void *cObjBaseArray_SearchOM(char *arr, long mask);

extern int D_00747A84;
extern char D_00754C58[];
extern char D_00583EC0[];
extern int D_003C264C;
extern int D_00747A24;
extern char D_005E8658[];
extern int ForwardCheckedRequest_2BED60();

__attribute__((section(".text.cScenario_waitEventStartOk")))
/* Sleep the script task until an event may start. */
void cScenario_waitEventStartOk(cScenario *self) {
    cTaskManager *task = &self->task;
    while (cScenario_isEventStartOk(self) == 0) {
        cTaskWork_sleep(task->cur, 1);
    }
}

__attribute__((section(".text.cScenario_setCam")))
/* Start the camera move stored under `name`. */
int cScenario_setCam(cScenario *self, const char *name) {
    return cScenario_startCamMotion(self, SearchCameraData(name));
}
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

__attribute__((section(".text.cScenario_taskExec")))
/* Start entry(arg) as a script task in `slot`; returns its index or -1. */
int cScenario_taskExec(cScenario *self, void *entry, void *arg, int slot) {
    int no = func_002D5580(&self->task, entry, arg, slot);
    do {
        cScenario_clearTaskData(self, no);
        return no;
    } while (0);
}
__attribute__((section(".text.cScenario_isEventStartOk")))
/* 0 while events are locked out or the player cannot take one. */
int cScenario_isEventStartOk(cScenario *self)
{
    if (D_00747A84 & 0x40000000)
        return 0;
    return pl00_CkSubScreenOrForced(Getplayer()) != 0;
}


__attribute__((section(".text.cScenario_beginRoomJump")))
void cScenario_beginRoomJump(int a0, unsigned char a1, unsigned char a2, int a3, unsigned char a4)
{
    SetColorRgba_1FFE60(D_00583EC0, a1, a2, a3, a4);
}


/* The scenario keeps the return point of a battle at its start: a position, a heading (0x10) and a room
 * number (0x16). */
#define SCENARIO_RETURN_POS(s)    ((cVec *)(s))
#define SCENARIO_RETURN_ANGLE(s)  (*(float *)((char *)(s) + 0x10))
#define SCENARIO_RETURN_ROOM(s)   (*(short *)((char *)(s) + 0x16))

extern void cSaveManager_setCheckPoint(int mgr, int a1, int a2, int a3);

/* cGameObj method 0x88, called right after the lock-on position: the player's rotation vector. */
#define GAMEOBJ_VT_GETROT(vt)       (((cVtEnt *)(vt))[0x88 / 8])

/* The player's lock-on position and its rotation vector, through its method table. */
static __inline__ cVec *Player_lockOnPos(cGameObj *pl)
{
    cGameObjVt *vt = cGameObj_vt(pl);
    return ((cVec *(*)(void *))vt->lockOn)((char *)pl + vt->lockOnDelta);
}

static __inline__ cVec *Player_rotVec(cGameObj *pl)
{
    cGameObjVt *vt = cGameObj_vt(pl);
    return ((cVec *(*)(void *))GAMEOBJ_VT_GETROT(vt).pfn)((char *)pl + GAMEOBJ_VT_GETROT(vt).delta);
}

/* cScenario_beginCasinoBattle: start the casino battle: set save flag 0x04000000, remember the player's
 * position and heading as the return point (room 0), set a checkpoint and set bit 0x8000000 of D_00747A24. */
__attribute__((section(".text.cScenario_beginCasinoBattle")))
void cScenario_beginCasinoBattle(void)
{
    cVec saved[2];
    cVec *v;
    int *flags;

    flags = (int *)&D_00569B70.data->flags;
    *flags = *flags | 0x04000000;
    v = Player_lockOnPos(Getplayer());
    VU0_LQC2(4, v, 0);
    VU0_SQC2(4, saved, 0x0);
    v = Player_rotVec(Getplayer());
    VU0_LQC2(4, v, 0);
    VU0_SQC2(4, saved, 0x10);
    SCENARIO_RETURN_ROOM(D_003C2F84) = 0;
    cVec_copy3(SCENARIO_RETURN_POS(D_003C2F84), &saved[0]);
    SCENARIO_RETURN_ANGLE(D_003C2F84) = saved[1].y;
    cSaveManager_setCheckPoint(D_003C264C, 0, 0, 0);
    D_00747A24 = D_00747A24 | 0x8000000;
}

__attribute__((section(".text.cScenario_endCasinoBattle")))
void cScenario_endCasinoBattle(void)
{
    int *flags;
    func_002C0038(D_003C264C);
    D_00747A24 = D_00747A24 & 0xF7FFFFFF;
    /* An int view of save flags: the struct-typed load is scheduled above
     * the D_00747A24 store. */
    flags = (int *)&D_00569B70.data->flags;
    *flags = *flags & ~0x04000000;
}

extern unsigned int D_00568240;
extern void cScenario_beginRoomJump_2C4548(cScenario *self, int room, float angle, void *pos, int a3, unsigned int t0, int t1);

/* cScenario_beginKurohukuBattle: start the Kurohuku battle: mark it in D_00568240, remember the return
 * point (4.2, 0, -44.2, heading -pi/2, room 0), set a checkpoint, set bit 0x8000000 of D_00747A24 and jump to
 * room 0x4F at the origin. */
__attribute__((section(".text.cScenario_beginKurohukuBattle")))
void cScenario_beginKurohukuBattle(void)
{
    cVec ret;
    cVec dest;
    cVec *d;
    float one;

    D_00568240 = D_00568240 | 0x8;
    ret.x = 4.2f;
    ret.y = 0.0f;
    ret.z = -44.2f;
    one = 1.0f;
    ret.w = one;
    SCENARIO_RETURN_ROOM(D_003C2F84) = 0;
    cVec_copy3(SCENARIO_RETURN_POS(D_003C2F84), &ret);
    SCENARIO_RETURN_ANGLE(D_003C2F84) = -1.5707964f;
    cSaveManager_setCheckPoint(D_003C264C, 0, 0, 0);
    D_00747A24 = D_00747A24 | 0x8000000;
    d = &dest;
    dest.x = 0.0f;
    dest.y = 0.0f;
    dest.z = 0.0f;
    d->w = one;
    cScenario_beginRoomJump_2C4548(D_003C2F84, 0x4F, 0.0f, d, 0, 0x80000000, 1);
}

/* A room-jump target: the arrival position, the heading and the room number. */
typedef struct RoomJumpTarget {
    float pos[4];               /* 0x00 */
    float angle;                /* 0x10 */
    char unk14[2];
    unsigned short roomNo;      /* 0x16 */
} RoomJumpTarget;

extern void func_002C02E8(int a0);

/* cScenario_endKurohukuBattle: leave the Kurohuku battle: jump to the target room (fade-in kind 2 when bit 4
 * of D_00568240 is set, 0 otherwise), clear bit 0x8000000 of D_00747A24, then clear the battle bits 0x8 and
 * 0x10 of D_00568240. */
__attribute__((section(".text.cScenario_endKurohukuBattle")))
void cScenario_endKurohukuBattle(RoomJumpTarget *target)
{
    float pos[4];
    unsigned short room;
    float angle;
    long t;
    long x;
    int v;

    room = target->roomNo;
    VU0_LQC2(4, target, 0);
    VU0_SQC2(4, pos, 0);
    angle = target->angle;
    func_002C02E8(D_003C264C);
    x = D_00568240;
    t = (x >> 4) & 1;
    if (t != 0) {
        cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 2, 1);
    } else {
        cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 0, 1);
    }
    D_00747A24 = D_00747A24 & 0xF7FFFFFF;
    v = D_00568240;
    v = v & ~0x8;
    v = v & ~0x10;
    D_00568240 = v;
}

/* The object name is packed into a 64-bit key one byte at a time, then looked
   up.  The table base must be bound at block top: it stays live across the
   loop, and no call intervenes. */
__attribute__((section(".text.cScenario_isOmBreak_2C5168")))
/* isOmBreak for the object with this name. */
int cScenario_isOmBreak_2C5168(cScenario *self, const char *name)
{
    char *arr = D_00754C58;
    long acc = 0;
    int i = 0;
    if (*name != 0) {
        do {
            acc |= (long)*name << (i * 8);
            i++;
            name++;
            if (i >= 8) break;
        } while (*name != 0);
    }
    return cScenario_isOmBreak(self, cObjBaseArray_SearchOM(arr, acc));
}

__attribute__((section(".text.cScenario_isOmBreak_2C5220")))
/* Break-list check of entry `no` under this name. */
int cScenario_isOmBreak_2C5220(cScenario *self, unsigned short no, const char *name)
{
    char *arr = D_005E8658;
    long acc = 0;
    int i = 0;
    if (*name != 0) {
        do {
            acc |= (long)*name << (i * 8);
            i++;
            name++;
            if (i >= 8) break;
        } while (*name != 0);
    }
    return ForwardCheckedRequest_2BED60(arr, no, acc);
}

__attribute__((section(".text.cScenario_isOmBreak_2C5288")))
/* Break-list check of entry `no` under a packed name. */
int cScenario_isOmBreak_2C5288(cScenario *self, unsigned short no, long name)
{
    return ForwardCheckedRequest_2BED60(D_005E8658, no, name);
}

