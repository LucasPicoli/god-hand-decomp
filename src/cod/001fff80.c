/* sn-2.95.3-136: cDoor_setDoorJump, start a door jump: close the messages, fade to white or black,
 * lock the game flags and make the player drop what it holds. */
#include "godhand/cDoor.h"
#include "godhand/classFADE.h"
#include "godhand/cScenario.h"
#include "godhand/player.h"

#define SYS_FLAG_DOOR_STEP  0x2000000   /* D_00747A84: the door step is running */
#define SYS_MODE_KEEP_MESS  0x100       /* D_00747A24: keep the open messages once */
#define DOOR_FADE_WHITE     0x1
#define DOOR_FADE_BLACK     0x2
#define DOOR_FADE_TIME      30
#define STAGE_NOPLAYER      0x20

/* Words of the game work block, addressed from D_00747A84 (its 0x5E4) as retail does;
 * as their own symbols (D_00747A24 and the rest) the code changes. */
#define SYS_MODE()         (*(int *)((char *)&D_00747A84 - 0x60))             /* D_00747A24 */
#define SYS_STAGE()        (*(unsigned short *)((char *)&D_00747A84 - 0x34))  /* D_00747A50 */
#define SYS_LOCK()         (*(int *)((char *)&D_00747A84 - 0xC))              /* D_00747A78 */
#define SYS_LOCK2()        (*(int *)((char *)&D_00747A84 - 0x4))              /* D_00747A80 */

typedef struct cMessage cMessage;

extern int D_00747A84;
extern cMessage *D_003C23A4;
extern short D_005CAE40;

extern void cMessage_closeAll(cMessage *self);
extern void KeyStop(void);
extern void pl00_DiscardWeapon(void *pl);
extern void pl00_DiscardThrowObj(void *pl);

__attribute__((section(".text.cDoor_setDoorJump")))
void cDoor_setDoorJump(cDoor *self)
{
    int kind;

    if (D_00747A84 & SYS_FLAG_DOOR_STEP)
        return;
    if (SYS_MODE() & SYS_MODE_KEEP_MESS)
        SYS_MODE() &= ~SYS_MODE_KEEP_MESS;
    else
        cMessage_closeAll(D_003C23A4);
    kind = self->point[0].arg2;
    if (kind & DOOR_FADE_WHITE) {
        classFADE_start(&D_00747470, 0, 10, 0, 0xA0A0A0, 0x80A0A0A0, DOOR_FADE_TIME);
        D_005CAE40 = DOOR_FADE_TIME;
    } else if (kind & DOOR_FADE_BLACK) {
        classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, DOOR_FADE_TIME);
        D_005CAE40 = DOOR_FADE_TIME;
    }
    self->step = 0;
    self->phase = 0;
    D_00747A84 |= SYS_FLAG_DOOR_STEP;
    KeyStop();
    SYS_LOCK() |= 0x800000;
    SYS_LOCK() |= 0x4000000;
    SYS_LOCK() |= 0x400000;
    SYS_LOCK() |= 0x100000;
    SYS_LOCK2() |= 0x100000;
    D_003C2F84->task.flags |= 1;
    if (SYS_STAGE() != STAGE_NOPLAYER) {
        cGameObj *pl = Getplayer();

        pl00_DiscardWeapon(pl);
        pl00_DiscardThrowObj(pl);
        pl->hitFlash = 1000.0f;
    }
}
