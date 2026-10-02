/* include/godhand/cEmWrap.h - cEmWrap, a handle that resolves to an enemy actor.
 *
 * A cEmWrap is a small record whose word at 0x04 points at the enemy actor.
 * FindResolveActor_295978 checks the handle is still live, and every method
 * does nothing (or returns a default) when it is not. cEmActor lists only the
 * fields the wrapper methods touch. The virtual calls go through the actor's
 * table at 0x214, whose entries are g++ 2.x delta/pfn pairs.
 * cEmManage reads the dead bit, the enemy number and the entry number.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CEMWRAP_H
#define GODHAND_CEMWRAP_H

#define EMACTOR_FLAG_NOSCRCOLL  4   /* in scrFlags: screen collision off */
#define EMACTOR_FLAG_DEAD  0x80000000   /* in objFlags: the actor is gone */

/* The actor's method table: each entry is a g++ delta (short) and a pfn. */
typedef struct cEmActorVt {
    char unk00[0x60];
    short suspendDelta;         /* 0x60 */
    short pad62;
    void (*suspend)(void *self, int flag);          /* 0x64 */
    char unk68[8];
    short setPosDelta;          /* 0x70 */
    short pad72;
    void (*setPos)(void *self, int pos);            /* 0x74 */
    short setScaleDelta;        /* 0x78 */
    short pad7A;
    void (*setScale)(void *self, void *scale);      /* 0x7C */
    char unk80[0x98 - 0x80];
    short entryDelta;           /* 0x98 */
    short pad9A;
    int (*entry)(void *self, void *data, void *parent);  /* 0x9C set up from a SET_EM_DATA */
    char unkA0[0xD8 - 0xA0];
    short startDelta;           /* 0xD8 */
    short padDA;
    void (*startAction)(void *self);                /* 0xDC */
} cEmActorVt;

typedef struct cEmActor {
    char unk000[0x100];
    float rot[3];               /* 0x100 */
    char unk10C[0x214 - 0x10C];
    cEmActorVt *vt;             /* 0x214 */
    char unk218[0x250 - 0x218];
    int objFlags;               /* 0x250 EMACTOR_FLAG_DEAD once the actor is gone */
    char unk254[0x2FE - 0x254];
    unsigned short actorId;     /* 0x2FE */
    char unk300[0x4AC - 0x300];
    int kind;                   /* 0x4AC */
    char unk4B0[0x548 - 0x4B0];
    short vitalMax;             /* 0x548 */
    short vital;                /* 0x54A */
    char unk54C[0x560 - 0x54C];
    int dropItem;               /* 0x560 */
    int emNo;                   /* 0x564 enemy number, 0x270..0x274 are the five cEmManage keeps */
    char unk568[0x5A0 - 0x568];
    int scrFlags;               /* 0x5A0 */
    char unk5A4[4];
    float speedRate;            /* 0x5A8 copied from cEmManage every frame */
    char unk5AC[0x640 - 0x5AC];
    unsigned short entryNo;     /* 0x640 the room table's number for it, cEmManage_GetEm's key */
} cEmActor;

typedef struct cEmWrap {
    int unk00;
    cEmActor *actor;            /* 0x04 */
} cEmWrap;

#define EMACTOR_OFFSET(field) ((int)&((cEmActor *)0)->field)
typedef char cEmActor_chk_flags[EMACTOR_OFFSET(objFlags) == 0x250 ? 1 : -1];
typedef char cEmActor_chk_kind[EMACTOR_OFFSET(kind) == 0x4AC ? 1 : -1];
typedef char cEmActor_chk_emno[EMACTOR_OFFSET(emNo) == 0x564 ? 1 : -1];
typedef char cEmActor_chk_entry[EMACTOR_OFFSET(entryNo) == 0x640 ? 1 : -1];
typedef char cEmActorVt_chk_entry[(int)&((cEmActorVt *)0)->entry == 0x9C ? 1 : -1];

#endif
