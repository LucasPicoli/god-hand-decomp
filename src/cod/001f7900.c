/* sn-2.95.3-136 matched TU. */

#include "godhand/cDoor.h"
#include "godhand/cE3.h"
#include "godhand/classFADE.h"
#include "godhand/cActionButton.h"
#include "godhand/cMessCommon.h"
#include "godhand/cGame.h"

extern int D_00747A44;
extern float *func_002BEB00(cRoomJump *self, unsigned short id, unsigned char kind);
extern cE3World D_007474A0;
extern int D_0061A990;
extern int D_00747A24;
extern char D_0042C7D0[];
extern void *D_003C2F84;
extern void cWorldTime_getGlobalHMS(void *clock, int a, unsigned int *out, int b);
extern void cScenario_debugPrint(void *printer, char *fmt, int value);
extern void cE3_setEnding(cE3 *self, int kind);
extern unsigned int D_00747A78;
extern void Set_bg_mode(int a, int b, int c, int d);
extern void Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(cActionButton *self, int priority, cActionButtonEnt *ent);
extern int D_005685B0[];
extern unsigned short D_00568650[];
extern unsigned char D_005686A0[];
extern cE3Sys D_00747A2C;
extern int D_00752CF0;
extern char D_00585038[];
extern int D_005CAFF4;
extern void *D_003BD930;
extern void cE3_exec(void *e3);
extern void func_002A6FF8(cGame *self);
extern void *Getplayer(void);
extern int pl00_CkSubScreen(void *player);
extern void cSubScr_SubScrOn(void *scr, int a, int b, int c);
extern void Move(void);
extern void Trans(void);

/* Look up jump point `id` of the given kind and take it as the landing
 * place. A point that is not in the table lands at the origin. */
__attribute__((section(".text.cDoor_setCasinoJumpPoint")))
void cDoor_setCasinoJumpPoint(cDoor *self, unsigned short id, unsigned char kind) {
    float *src;
    float w;
    cRoomJump_setTblAddr(&self->roomJump, D_00747A44);
    src = func_002BEB00(&self->roomJump, id, kind);
    if (src != 0) {
        self->point[1].pos[0] = src[0];
        self->point[1].pos[1] = src[1];
        self->point[1].pos[2] = src[2];
        w = src[3];
        if (w < -CDOOR_PI) {
            self->point[1].angle = w * CDOOR_DEG2RAD;
        } else if (w > CDOOR_PI) {
            self->point[1].angle = w * CDOOR_DEG2RAD;
        } else {
            self->point[1].angle = w;
        }
    } else {
        self->point[1].pos[0] = 0;
        self->point[1].pos[1] = 0;
        self->point[1].pos[2] = 0;
        self->point[1].angle = 0;
    }
    self->point[1].id = id;
    self->point[1].kind = CDOOR_NO_KIND;
}

/* Demo step: while no stage blocks it, compare the world clock against the
 * time limit (the cursor, in minutes) and end the demo when it runs out; show the
 * time left. Cheat bit 3 of D_00747A24 ends the demo too. */
__attribute__((section(".text.cE3_stepMenuClock")))
void cE3_stepMenuClock(cE3 *self) {
    cE3World *w = &D_007474A0;
    unsigned int hms[4];
    unsigned long cheat;
    if (w->room == CE3_ROOM_END) return;
    if ((w->flags5E4 & CE3_W_NO_CLOCK) == 0) {
        if ((w->flags5E4 & CE3_W_BLOCKED) != 0) return;
    }
    if (w->unk58C < 0) return;
    if ((signed char)self->cursor > 0) {
        cWorldTime_getGlobalHMS(&D_0061A990, 0, hms, 0);
        if (hms[0] >= (signed char)self->cursor) {
            cE3_setEnding(self, 1);
        }
        cScenario_debugPrint(D_003C2F84, D_0042C7D0, (signed char)self->cursor * 0x708 - D_0061A990);
    }
    cheat = D_00747A24;
    if (((cheat >> 3) & 1UL) == 1UL) {
        cE3_setEnding(self, 1);
    }
}

/* Demo run: fade out (the ending kind picks the fade colours), wait for the
 * fade to end, then lock the screen state and stop the fade; the last phase
 * swaps the cheat flags. */
__attribute__((section(".text.cE3_runDemo")))
void cE3_runDemo(cE3 *self) {
    switch (self->phase) {
    case 0:
        if (self->ending != 0) {
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 0x3C);
        } else {
            classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0xFF000000, 0x3C);
        }
        self->phase++;
    case 1:
        if (((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) != 0) {
            /* one |= per bit: retail keeps one constant register per bit */
            D_00747A78 |= 0x80000000;
            D_00747A78 |= 0x40000000;
            D_00747A78 |= 0x20000000;
            D_00747A78 |= 0x10000000;
            D_00747A78 |= 0x8000000;
            D_00747A78 |= 0x4000000;
            D_00747A78 |= 0x804000;
            Set_bg_mode(1, 0, 0, 0);
            classFADE_kill(&D_00747470);
            self->phase++;
        }
        break;
    case 2:
        D_00747A24 = (D_00747A24 & ~8) | 0x8000;
        break;
    }
}

/* Take a free entry and fill it from `list`: priority, matrix and the first
 * `num` commands split into the three tables. Returns the entry, or 0 when
 * none is free. The entry finder takes the manager too: with it passed, the
 * manager pointer has the same number of references as the priority and keeps
 * retail's register order. */
__attribute__((section(".text.cActionButton_setCommandList")))
cActionButtonEnt *cActionButton_setCommandList(cActionButton *self, int priority, void *matrix, COMMAND_LIST *list, unsigned int num) {
    cActionButtonEnt *ent = func_001F7798(self);
    unsigned int i;
    if (ent == 0) return 0;
    ent->cmdTbl = D_005685B0;
    ent->idTbl = D_00568650;
    ent->argTbl = D_005686A0;
    ent->flags = ent->flags | ACTBTN_ENT_USED;
    ent->life = ACTBTN_DEFAULT_LIFE;
    ent->kind = ACTBTN_DEFAULT_KIND;
    ent->matrix = matrix;
    ent->unk10 = 0;
    ent->unk14 = 0;
    ent->priority = priority;
    ent->unk35 = 0;
    ent->unk30 = 0;
    ent->cmdNum = num;
    for (i = 0; i < num; i++) {
        ent->cmdTbl[i] = list[i].cmd;
        ent->idTbl[i] = list[i].id;
        ent->argTbl[i] = list[i].arg;
    }
    Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(self, priority, ent);
    return ent;
}

/* 1 when the control code ends the page. Printable codes (below 0x8000) never do;
 * the test is written as a shift because retail emits srl, not a compare. */
__attribute__((section(".text.cMessCommon_isPageEndCode")))
int cMessCommon_isPageEndCode(unsigned short code) {
    if ((code >> 15) == 0) return 0;
    switch (code & MESS_CODE_KIND_MASK) {
    case MESS_END_80:
    case MESS_END_81:
    case MESS_END_82:
    case MESS_END_83:
    case MESS_END_89:
    case MESS_END_90:
    case MESS_END_A1:
    case MESS_END_A5:
    case MESS_END_A6:
    case MESS_END_A7:
    case MESS_END_D2:
    case MESS_END_D9:
    case MESS_END_DA:
    case MESS_END_E2:
    case MESS_END_E4:
    case MESS_END_E5:
    case MESS_END_E7:
        return 1;
    default:
        return 0;
    }
}

/* The state block D_007474A0 is D_00747A2C - 0x58C: retail forms it that way. */
typedef struct cGameWorld {
    char unk000[0x1A0];
    long flags1A0;                      /* 0x1A0 */
    char unk1A8[0x5D8 - 0x1A8];
    unsigned int flags5D8;              /* 0x5D8 */
    char unk5DC[8];
    unsigned int flags5E4;              /* 0x5E4 */
} cGameWorld;














/* The first read of the sub screen wait goes through a helper so it is a
 * pseudo of its own: without it the later test of the same field is threaded
 * into the first and retail's reload disappears. */
static __inline__ short cGame_waitOf(cGame *g) {
    return g->subScrWait;
}

/* One frame: step the scene, open the sub screen when the pad asks for it and
 * nothing blocks it, count the wait down, run the move and draw passes and
 * leave the frame time (timer ticks) in D_00752CF0. */
__attribute__((section(".text.cGame_gameLoop")))
void cGame_gameLoop(cGame *self) {
    cE3Sys *sys = &D_00747A2C;
    cGameWorld *w;
    int start = *(volatile int *)CGAME_TIMER_COUNT;
    int idle;
    D_00752CF0 = start;
    if ((sys->flags & 0x800) != 0) {
        cE3_exec(D_00585038);
    }
    func_002A6FF8(self);
    w = (cGameWorld *)((char *)sys - 0x58C);
    if ((w->flags1A0 & 0x200000) != 0) {
        idle = self->subScrWait == 0;
        if (cGame_waitOf(self) == 0) {
            if ((w->flags5E4 & 0x200000) == 0) {
                if ((w->flags5E4 & 0x4000) == 0) {
                    if ((w->flags5E4 & 0x2000000) == 0) {
                        if ((w->flags5D8 & 0x2000000) == 0) {
                            if (pl00_CkSubScreen(Getplayer()) == idle) {
                                cSubScr_SubScrOn(D_003BD930, 0, 0, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    if (self->subScrWait != 0) {
        self->subScrWait = self->subScrWait - 1;
    }
    Move();
    D_005CAFF4 = 0;
    Trans();
    D_00752CF0 = D_00752CF0 - *(volatile int *)CGAME_TIMER_COUNT;
}
