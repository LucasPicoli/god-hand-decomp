/* sn-2.95.3-136 matched TU. */

#include "godhand/cActionButton.h"
#include "godhand/cOmBase.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

extern void func_001CFE88(void *weapon, int arg);
extern unsigned short D_00747A50;
extern char D_005FEA60[];
extern int FindEntityAtPosition_2C2638(void *mgr, cVec *pos, cVec *center, float *extent);

#define EM_NO_WEAPON_HOLDER  0x211      /* emNo of the enemy that holds the weapons */
#define EM_WEAPON_NUM        8

/* The enemy record: the number at 0x564 and the weapon handle array at 0x710. */
typedef struct EmWeaponHolder {
    char unk000[0x564];
    int emNo;                           /* 0x564 */
    char unk568[0x1A8];
    void *weapon[EM_WEAPON_NUM];        /* 0x710 weapon handles, 0 = empty slot */
} EmWeaponHolder;



/* Enemy 0x211: drop up to `count` of its held weapons, in slot order, and forget their handles. */
__attribute__((section(".text.EmWeaponHolder_dropWeapons")))
void EmWeaponHolder_dropWeapons(EmWeaponHolder *self, unsigned int count, int arg)
{
    unsigned int i;
    unsigned int dropped;

    if ((self->emNo ^ EM_NO_WEAPON_HOLDER) == 0) {
        i = 0;
        dropped = 0;
        if (count != 0) {
            do {
                if (self->weapon[i] != 0) {
                    dropped++;
                    func_001CFE88(self->weapon[i], arg);
                    self->weapon[i] = 0;
                }
                i++;
            } while (i < EM_WEAPON_NUM && dropped < count);
        }
    }
}

#define ACTBTN_ENT_NUM    8
#define ACTBTN_ENT_UNK0C  0xC
#define ACTBTN_ENT_UNK2C  0x2C
#define ACTBTN_ENT_WORD(ent, off)  (*(int *)((char *)(ent) + (off)))

/* The prompt manager: eight entries from 0x104. */
typedef struct ActionButtonMgr {
    char unk000[0x104];
    cActionButtonEnt ent[ACTBTN_ENT_NUM];   /* 0x104 */
} ActionButtonMgr;

extern void func_001F77D0(ActionButtonMgr *self);

/* Reset the manager: clear its free list, then put all eight entries in
 * the unused state. */
__attribute__((section(".text.cActionButton_resetEntries")))
void cActionButton_resetEntries(ActionButtonMgr *self)
{
    cActionButtonEnt *ent;
    unsigned int i;

    func_001F77D0(self);
    ent = self->ent;
    for (i = 0; i < ACTBTN_ENT_NUM; i++) {
        ent->flags &= ~ACTBTN_ENT_USED;
        ACTBTN_ENT_WORD(ent, ACTBTN_ENT_UNK0C) = 1;
        ent->unk10 = 0;
        ent->unk14 = 0;
        ent->priority = 0;
        ent->life = ACTBTN_DEFAULT_LIFE - 1;
        ent->kind = 0;
        ent->unk20 = 0;
        ent->matrix = 0;
        ACTBTN_ENT_WORD(ent, ACTBTN_ENT_UNK2C) = 0x1F;
        ent->unk30 = 0;
        ent->cmdNum = 0;
        ent->unk35 = 0;
        ent->unk32 = 0;
        ent->unk36 = 0;
        ent->cmdTbl = 0;
        ent->idTbl = 0;
        ent->argTbl = 0;
        ent++;
    }
}

/* The holder being classified; its layout is not needed here. */
typedef struct PartHolder {
    char unk00[4];
} PartHolder;

enum PartKind {
    PART_KIND_SEQUENCE,
    PART_KIND_2B8,
    PART_KIND_4C0,
    PART_KIND_BOTH,
    PART_KIND_FOUND,
    PART_KIND_798,
    PART_KIND_980,
    PART_KIND_AD8,
    PART_KIND_C30,
    PART_KIND_NONE
};

extern int PartHolder_markIfSequence(PartHolder *self);


extern int SlotObj_markIfBothKinds(PartHolder *self);
extern int PartHolder_markIfFound(PartHolder *self);





/* Classify the holder: the first test that accepts it names its kind;
 * PART_KIND_NONE when none does. Each test marks the holder as a side effect. */
__attribute__((section(".text.PartHolder_classify")))
int PartHolder_classify(PartHolder *self)
{
    if (PartHolder_markIfSequence(self))
        return PART_KIND_SEQUENCE;
    if (func_001DC2B8(self))
        return PART_KIND_2B8;
    if (func_001DC4C0(self))
        return PART_KIND_4C0;
    if (SlotObj_markIfBothKinds(self))
        return PART_KIND_BOTH;
    if (PartHolder_markIfFound(self))
        return PART_KIND_FOUND;
    if (func_001DC798(self))
        return PART_KIND_798;
    if (func_001DC980(self))
        return PART_KIND_980;
    if (func_001DCAD8(self))
        return PART_KIND_AD8;
    if (func_001DCC30(self))
        return PART_KIND_C30;
    return PART_KIND_NONE;
}

#define EM_MODE_ROOM_HIT  0x700         /* D_00747A50 value this probe runs in */
#define EM_PHASE_HIT_AIM  0x37






/* In room mode 0x700, look for a hit unit at the enemy's position unless
 * the lock byte is set; when found, aim at its centre (unk580) and extent
 * (unk590.z) and switch to phase 0x37. Returns 1 when it did. */
__attribute__((section(".text.cEm00_startRoomHitAim")))
int cEm00_startRoomHitAim(cEm00 *self)
{
    cVec center;
    float extent;

    VU0_SQC2_VF0(&center, 0);
    if (D_00747A50 != EM_MODE_ROOM_HIT)
        return 0;
    if (FindEntityAtPosition_2C2638(D_005FEA60, self->pos, &center, &extent) == 0)
        return 0;
    if (D_005CB010 != 0)
        return 0;
    cVec_copy3(&self->unk580, &center);
    self->unk590.z = extent;
    self->phase = EM_PHASE_HIT_AIM;
    self->mode = 0;
    self->step = 0;
    self->stepArg = 0;
    return 1;
}

/* A script command: the high bit of its first halfword marks a wait command. */
typedef struct ScriptCmd {
    unsigned short word;                /* 0x00 */
} ScriptCmd;

/* A script runner: the channel byte at 0x2C, the next command pointer at
 * 0x8C and the next command's time at 0x90. */
typedef struct ScriptRun {
    char unk00[0x2C];
    unsigned char channel;              /* 0x2C */
    char unk2D[0x5F];
    ScriptCmd *cmd;                     /* 0x8C */
    int cmdTime;                        /* 0x90 */
} ScriptRun;

#define STEP_ADVANCE  0
#define STEP_STOP     1
#define STEP_DONE     2

extern void *D_003C23A4;                /* script manager */


extern void func_002B4768(ScriptRun *run, int *time, ScriptCmd **cmd);

/* Run the commands of a channel that is not busy: advance past each
 * finished command until a wait command ends the run. Returns 0 when the
 * channel is busy or a step asks to stop, 1 otherwise. */
__attribute__((section(".text.ScriptRun_runChannel")))
int ScriptRun_runChannel(ScriptRun *run)
{
    if (func_002AEDC0(D_003C23A4, run->channel) >= 2)
        return 0;
    for (;;) {
        if ((run->cmd->word >> 15) == 0)
            return 1;
        switch (func_002B2638(run)) {
        case STEP_ADVANCE:
            func_002B4768(run, &run->cmdTime, &run->cmd);
            break;
        case STEP_STOP:
            return 0;
        case STEP_DONE:
            return 1;
        }
    }
}

#define UV_WRAP 2.0f                    /* the scroll wraps into -2..2 */

/* A texture-scroll object: position and speed of the u and v offsets. */
typedef struct UvScroll {
    char unk000[0x2B8];
    float u;                            /* 0x2B8 */
    float v;                            /* 0x2BC */
    float du;                           /* 0x2C0 per-call step of u */
    float dv;                           /* 0x2C4 per-call step of v */
} UvScroll;

extern void func_002FBED0(UvScroll *self);

/* Step u and v by their speeds, fold both back into -2..2, then run the base update. */
__attribute__((section(".text.UvScroll_step")))
void UvScroll_step(UvScroll *self)
{
    self->u += self->du;
    self->v += self->dv;
    if (self->u > UV_WRAP)
        self->u -= UV_WRAP;
    if (self->v > UV_WRAP)
        self->v -= UV_WRAP;
    if (self->u < -UV_WRAP)
        self->u += UV_WRAP;
    if (self->v < -UV_WRAP)
        self->v += UV_WRAP;
    func_002FBED0(self);
}
