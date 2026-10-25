/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cSceAtManager.h"
#include "godhand/cFontTex.h"

extern void *SearchData(void *name, void *table, int which);
extern void cSndSeVoice_CheckEnd(void *snd, int handle);
extern int cSnd_ReserveSeSlot(void *snd, void *data);
extern char D_005FEE00[];
extern cSceAtManager D_005FEA60;
extern int FindNodeByHit_2C2490(cSceAtManager *mgr, cVec *shape, float *out);
extern int SetEffect(int kind, int id, void *owner, int param, int handle, unsigned int owner2);
extern int D_00747A2C;

extern char D_0044B1E0[];               /* name of the sound data to look up */


typedef struct Owner2B2E80 {
    char unk000[0x304];
    void *packed;                       /* 0x304 */
} Owner2B2E80;

typedef struct SeTrack2B2E80 {
    char unk00[0x18];
    Owner2B2E80 *owner;                 /* 0x18 */
    void *data;                         /* 0x1C the sound data in use */
    int slot;                           /* 0x20 reserved sound slot */
    char unk24[0xC];
    unsigned char count;                /* 0x30 */
    char unk31[0x7C - 0x31];
    int copyB;                          /* 0x7C */
    char unk80[4];
    int copyA;                          /* 0x84 */
    unsigned short key;                 /* 0x88 */
    int src8C;                          /* 0x8C */
    int src90;                          /* 0x90 */
} SeTrack2B2E80;

/* Switches the track to the sound data found for its owner: ends the old
 * voice, reserves a slot for the new data, then resets the track's key and
 * copies its two source words. */
__attribute__((section(".text.func_002B2E80")))
void func_002B2E80(SeTrack2B2E80 *self)
{
    void *data;
    if (self->owner == 0) {
        data = 0;
    } else {
        data = SearchData(self->owner->packed, D_0044B1E0, 0);
    }
    if (data != self->data) {
        if (self->data != 0) {
            cSndSeVoice_CheckEnd(D_005FEE00, self->slot);
        }
        if (data != 0) {
            self->slot = cSnd_ReserveSeSlot(D_005FEE00, data);
        }
        self->data = data;
    }
    /* both arms are identical: the owner test only keeps retail's reload of the owner pointer */
    if (self->owner != 0) {
        self->key = 0xFFFF;
    } else {
        self->key = 0xFFFF;
    }
    self->copyA = self->src90;
    self->copyB = self->src8C;
    self->count++;
}

#define EM_OFFSET_HITCD   0x15D0        /* float countdown of the area hit, not named in cEm00 yet */
#define EM_OFFSET_HITOUT  0x15E0        /* hit record the area test fills */
#define EM_HITCD(self)    (*(float *)((char *)(self) + EM_OFFSET_HITCD))
#define GAME_FLAG_BIT3    3             /* bit of D_00747A2C that blocks the hit */
#define HIT_COOLDOWN      90.0f
#define HIT_EFFECT_ID     0x4B
#define MODE_HIT          1
#define PHASE_HIT         7
#define HIT_DAMAGE        0x19
#define VITAL_LOW         11

/* Area hit on the enemy: skipped while a countdown or a hit flash runs or
 * game flag bit 3 is set. When the enemy's position lies in an area unit it
 * starts the 90 frame countdown, spawns the hit effect in mode 5, takes 25
 * hit points (down to 1, or to 0 when it had 10 or less) and switches to
 * phase 7. Returns 1 when it hit. */
__attribute__((section(".text.func_0012CAE0")))
int func_0012CAE0(cEm00 *self)
{
    int hit;
    int ok; /* one register serves the mode store and the return value */
    unsigned long gameFlags;
    unsigned long bit3;

    if (0.0f < EM_HITCD(self))
        return 0;
    if (0.0f < self->hitFlash)
        return 0;
    gameFlags = D_00747A2C;
    bit3 = gameFlags >> GAME_FLAG_BIT3;
    if ((unsigned char)(bit3 & 1))
        return 0;
    hit = FindNodeByHit_2C2490(&D_005FEA60, self->pos, (float *)((char *)self + EM_OFFSET_HITOUT));
    if (hit == 1) {
        EM_HITCD(self) = HIT_COOLDOWN;
        if (((unsigned char *)&D_00747A2C)[0x25] == 5)
            SetEffect(0, HIT_EFFECT_ID, self, 0, -1, 0xFFFFFFFFu);
        if (self->vital >= VITAL_LOW) {
            self->vital = self->vital - HIT_DAMAGE;
            if (self->vital <= 0)
                self->vital = hit;
        } else {
            self->vital = 0;
        }
        self->phase = PHASE_HIT;
        self->stepArg = 0;
        self->step = 0;
        ok = MODE_HIT;
        self->mode = ok;
        return ok;
    }
    return 0;
}

#define CMD_FRAME_TICKS    0x1E     /* script ticks per frame */
#define CMD_SEC_TICKS      0x384    /* script ticks per second */

/* The script state: tables of words (from 0xBDC) and halves (from 0xBEE). */
typedef struct ScriptState {
    char unk000[0xBDC];
    int word[4];                /* 0xBDC */
    char unkBEC[2];
    unsigned short half;        /* 0xBEE */
} ScriptState;

extern ScriptState *D_003C23A4;
extern unsigned short D_003C23A8;       /* the wait length the last 0x8700 command set */

/* A script command: bit 15 of the first half marks it as a command, the high byte picks the kind. */
typedef struct ScriptCmd {
    unsigned short code;        /* 0x00 */
    unsigned short arg;         /* 0x02 */
} ScriptCmd;

/* Length in script ticks of one command: 0x1E for plain data, 0 for most kinds, and for the wait kinds a count taken
 * from the command, the script state or the last set length (0x8700 sets it and takes no time). */
__attribute__((section(".text.func_002AF218")))
int func_002AF218(ScriptCmd *cmd)
{
    int kind; /* signed: retail compares the kind with slt, not sltu */

    if ((cmd->code >> 15) != 0) {
        kind = cmd->code & 0xFF00;
        switch (kind) {
        case 0xA400:
            return (cmd->arg * CMD_SEC_TICKS) & 0xFFFC;
        case 0xA900:
            return (D_003C23A8 * CMD_SEC_TICKS) & 0xFFFC;
        case 0x8000:
        case 0xA000:
        case 0xA100:
        case 0xA300:
        case 0xA500:
            return 0;
        /* the order of these arms is retail's layout: the zero-time kinds sit before the 0x93xx arms */
        default:
            return 0;
        case 0x9300:
            return (func_002AF348(D_003C23A4->word[cmd->arg]) * CMD_FRAME_TICKS) & 0xFFFE;
        case 0x9400:
            return (func_002AF380(D_003C23A4->half) * CMD_FRAME_TICKS) & 0xFFFE;
        case 0x8700:
            D_003C23A8 = cmd->arg;
            return 0;
        }
    } else {
        return CMD_FRAME_TICKS;
    }
}

/* The slot table starts at the beginning of the cFont record. */
typedef struct cFontTexOwner {
    cFontTexSlot slot[1];
} cFontTexOwner;

/* Registers texture `res` with its `info` in slot `idx`, after checking that
 * every size and count in both is nonzero, and turns the offsets in the two
 * entry lists into addresses once (the CFONTTEX_FIXED flag marks it done). */
__attribute__((section(".text.cFont_setTextureAddr")))
void cFont_setTextureAddr(cFontTexOwner *self, int idx, cFontTexRes *res, cFontTexInfo *info)
{
    cFontTexEnt *ent;
    char *base;
    unsigned int i;

    if (res == 0 || info == 0)
        return;
    if (info->h0 == 0 || info->h2 == 0 || info->h4 == 0 || info->b6 == 0 || info->b7 == 0)
        return;
    if (res->flags == 0 || res->w4 == 0 || res->w6 == 0 || res->offA == 0 || res->offB == 0)
        return;
    self->slot[idx].res = res;
    self->slot[idx].info = info;
    self->slot[idx].h8 = info->h2;
    self->slot[idx].hA = info->h4;
    self->slot[idx].hC = info->b6;
    self->slot[idx].hE = info->b7;
    if ((int)res->flags < 0)
        return;
    base = (char *)res + res->offA;
    for (i = 0, ent = (cFontTexEnt *)base; i < res->numA; i++, ent++)
        ent->addr += (int)base;
    ent = (cFontTexEnt *)((char *)res + res->offB);
    base = (char *)ent;
    for (i = 0; i < res->numB; i++, ent++)
        ent->addr += (int)base;
    res->flags |= CFONTTEX_FIXED;
}
