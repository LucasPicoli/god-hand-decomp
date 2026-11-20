/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cOmBase.h"
#include "godhand/DispMgr.h"

extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int sel, int on);
extern int D_0044CE48[];
extern void cSndSeVoice_CheckEnd(cSnd *self, int slot);
extern cSndSeEntry *cSnd_GetSeData(cSnd *self, int slot);
extern void cSeData_Release(cSndSeEntry *e);
extern void KeyStop(void);
extern float capVu0Cos(float rad);
extern char D_0044A518[];
extern char D_0044A520[];
extern void *SearchData(void *pack, void *name, int c);
extern int cModel_setupModel(void *self, void *a, void *b, int c, int d);
extern int D_00747A2C;
extern void func_001ED490(void *display, int gold);

/* An ID owner: a flag word at 0 and two counters at 0x918 and 0x91C. */
typedef struct IdOwnerB {
    unsigned int flags;                 /* 0x000 bit 0: the displays are cleared */
    char unk004[0x914];
    int count918;                       /* 0x918 */
    int count91C;                       /* 0x91C */
} IdOwnerB;

#define IDOWNER_CLEARED  0x01

/* Hide displays 0, 1, 0xB and 0xC, clear the two counters and set the cleared flag. */
__attribute__((section(".text.CustomIDOwner_hideAll")))
void CustomIDOwner_hideAll(IdOwnerB *self) {
    SetCustomIDDispOneOrAll_1F29C0(self, 0, 0);
    SetCustomIDDispOneOrAll_1F29C0(self, 1, 0);
    SetCustomIDDispOneOrAll_1F29C0(self, 0xB, 0);
    SetCustomIDDispOneOrAll_1F29C0(self, 0xC, 0);
    self->count918 = 0;
    self->count91C = 0;
    self->flags |= IDOWNER_CLEARED;
}

/* For each of the 12 emergency-pool slots, check whether its voice ended and release the slot data. */
__attribute__((section(".text.cSnd_releaseEmSeAll")))
void cSnd_releaseEmSeAll(cSnd *self) {
    int *slot = D_0044CE48;
    unsigned int i = 0;
    do {
        cSndSeVoice_CheckEnd(self, *slot);
        cSeData_Release(cSnd_GetSeData(self, *slot));
        i++;
        slot++;
    } while (i < 0xC);
}

#define CASINO_ACTIVE   0x01            /* bit of the flag word at 0x600: the ticket screen runs */

/* An actor with a flag word at 0x600 past cObj. */
typedef struct TicketObj {
    COBJ_FIELDS
    char unk310[0x2F0];
    int flags;                          /* 0x600 */
} TicketObj;

/* Stop key input, take one casino ticket and show the new count, then enter mode 1 phase 0 with the active flag set. */
__attribute__((section(".text.cOm_takeCasinoTicket")))
void cOm_takeCasinoTicket(TicketObj *self) {
    KeyStop();
    cCoreSave_addCasinoTicket(&D_00569B70, -1);
    D_003BD6E8->item.ticketSeed = (short)cCoreSave_getCasinoTicketNum(&D_00569B70);
    self->mode = 1;
    self->phase = 0;
    self->flags = self->flags | CASINO_ACTIVE;
}

extern float func_003A19F8(float x);    /* sin */


/* Build the quaternion q = (axis * sin(angle / 2), cos(angle / 2)) for a rotation of angle radians about axis. */
__attribute__((section(".text.Quaternion_SetRotationAxis")))
void Quaternion_SetRotationAxis(cVec *q, cVec *axis, float angle)
{
    float half = angle * 0.5f;
    float s = func_003A19F8(half);

    q->x = axis->x * s;
    q->y = axis->y * s;
    q->z = axis->z * s;
    q->w = capVu0Cos(half);
}

/* Look up two named entries in the actor's data pack and, when the second exists, set up the model from both. */
__attribute__((section(".text.cModel_setupFromPack")))
int cModel_setupFromPack(struct cObj *self) {
    void *first = SearchData(self->pack, D_0044A518, 0);
    void *second = SearchData(self->pack, D_0044A520, 0);
    if (second != 0) {
        return cModel_setupModel(self, first, second, 0, 0);
    }
    return 0;
}

/* A gold screen with a display element at 0x210. */
typedef struct GoldScreen {
    char unk000[0x210];
    char display[1];                    /* 0x210 */
} GoldScreen;

#define PAD_PRESS_ANY  0x33000000000L   /* button bits of the pad word 0x3DC bytes before D_00747A2C */
#define SYS_PAY_GOLD   0x200            /* bit of D_00747A2C: the pay prompt is on */
#define GOLD_PAYOUT    1000

/* On a pad press while the pay prompt is on, pay 1000 gold and show the new total in the display. */
__attribute__((section(".text.cCoreSave_payGoldOnPress")))
void cCoreSave_payGoldOnPress(GoldScreen *self) {
    if ((D_00747A2C & SYS_PAY_GOLD) != 0) {
        if ((*(long *)((char *)&D_00747A2C - 0x3DC) & PAD_PRESS_ANY) != 0) {
            cCoreSave_addGold(&D_00569B70, GOLD_PAYOUT, 0);
            func_001ED490(self->display, cCoreSave_getGold(&D_00569B70));
        }
    }
}
