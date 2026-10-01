/* include/godhand/ColiseumBattle.h - the coliseum (fighting ring) result screen.
 *
 * ColiseumBattle runs the scene that follows a fighting-ring match: it counts
 * the prize money up, sets the cleared-ring flags in the save record and fades
 * to the next room. The object is a state machine (state/timer) wrapped
 * around one embedded UI object at 0x60 that the func_001F28C0 family drives.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNNN padding. The object size
 * is not known, so there is no size check, only the offsets below.
 */
#ifndef GODHAND_COLISEUMBATTLE_H
#define GODHAND_COLISEUMBATTLE_H

/* flags bits */
#define COLISEUM_FLAG_ENTERED   0x01    /* result screen started */
#define COLISEUM_FLAG_FADE      0x02    /* a screen fade is running */
#define COLISEUM_FLAG_CTRL_OFF  0x04    /* player control is switched off */
#define COLISEUM_FLAG_BONUS     0x10    /* final ring cleared this visit */

#define COLISEUM_UI_SIZE        0xB00

/* The enemy list the arena keeps: a node per enemy object. */
/* One g++ 2.x vtable slot: this-adjust, index, function. */
typedef struct ColiseumVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self);
} ColiseumVtEnt;

#define COLISEUM_EM_KIND_FIRST   0x200  /* object kinds 0x200..0x2FF are enemies */
#define COLISEUM_EM_KIND_END     0x300
#define COLISEUM_EM_KIND_BOSS    0x2A0  /* 0x2A0..0x2FF are bosses */
#define COLISEUM_EM_VSLOT_DEFEAT 27     /* vtable slot at +0xD8 */

typedef struct ColiseumEm {
    char unk00[0x214];
    ColiseumVtEnt *vt;          /* 0x214 */
    char unk218[0xE6];
    unsigned short kind;        /* 0x2FE */
    char unk300[0x24A];
    short hp;                   /* 0x54A */
} ColiseumEm;

typedef struct ColiseumEmNode {
    int unk00;
    struct ColiseumEmNode *next;    /* 0x04 */
    ColiseumEm *em;                 /* 0x08 */
} ColiseumEmNode;

/* The fighting-ring rules record, copied from a 0x28-byte table row when the
 * scene starts. -1 in a *Lv field means "leave the player's value alone". */
typedef struct ColiseumRing {
    short ringNo;               /* 0x00 */
    char unk02[6];
    short gameLevel;            /* 0x08 */
    short unk0A;                /* 0x0A */
    int timeLimit;              /* 0x0C seconds, 0 = untimed */
    int prize;                  /* 0x10 gold */
    short vitalLv;              /* 0x14 life upgrade level */
    short vitalPct;             /* 0x16 starting life, percent */
    short heatLv;               /* 0x18 heat gauge level */
    char unk1A[2];
    float heatPct;              /* 0x1C starting heat, percent */
    short statLv;               /* 0x20 byte 156 of the save record */
    unsigned char godItemNum;   /* 0x22 god items handed out */
    char unk23;
    int bgm;                    /* 0x24 */
} ColiseumRing;

typedef struct ColiseumBattle {
    char unk00[4];
    int mode;                   /* 0x004 handed back to the caller when done */
    int state;                  /* 0x008 */
    int unk0C;                  /* 0x00C */
    int timer;                  /* 0x010 frames left in this state */
    char unk14[0x40];
    unsigned int flags;         /* 0x054 COLISEUM_FLAG_* */
    char unk58[8];
    char ui[COLISEUM_UI_SIZE];  /* 0x060 embedded result UI object */
    ColiseumRing ring;          /* 0xB60 */
    int unkB88;                 /* 0xB88 */
    int enemyNum;               /* 0xB8C live enemies at the start */
    int unkB90;                 /* 0xB90 */
    int phase;                  /* 0xB94 */
    float countdown;            /* 0xB98 frames left on the clock */
    int unkB9C;                 /* 0xB9C */
    int phaseTimer;             /* 0xBA0 */
    int prizeLeft;              /* 0xBA4 bonus gold still to pay out */
    int prizeSteps;             /* 0xBA8 thousands of gold left to count up */
    int unkBAC;                 /* 0xBAC */
    char unkBB0[0x20];
    unsigned char vec[9][16];   /* 0xBD0 cleared by the constructor */
    int unkC60;
    int unkC64[30];             /* 0xC64 cleared by Initialize */
} ColiseumBattle;

#endif
