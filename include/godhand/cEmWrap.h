/* include/godhand/cEmWrap.h - cEmWrap, a handle that resolves to an enemy actor.
 *
 * A cEmWrap is a small record whose word at 0x04 points at the enemy actor.
 * FindResolveActor_295978 checks the handle is still live, and every method
 * does nothing (or returns a default) when it is not. cEmActor lists only the
 * fields the wrapper methods touch. The virtual calls go through the actor's
 * table at 0x214, whose entries are g++ 2.x delta/pfn pairs.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CEMWRAP_H
#define GODHAND_CEMWRAP_H

#define EMACTOR_FLAG_NOSCRCOLL  4   /* in scrFlags: screen collision off */

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
    char unk80[0xD8 - 0x80];
    short startDelta;           /* 0xD8 */
    short padDA;
    void (*startAction)(void *self);                /* 0xDC */
} cEmActorVt;

typedef struct cEmActor {
    char unk000[0x100];
    float rot[3];               /* 0x100 */
    char unk10C[0x214 - 0x10C];
    cEmActorVt *vt;             /* 0x214 */
    char unk218[0x4AC - 0x218];
    int kind;                   /* 0x4AC */
    char unk4B0[0x548 - 0x4B0];
    short vitalMax;             /* 0x548 */
    short vital;                /* 0x54A */
    char unk54C[0x560 - 0x54C];
    int dropItem;               /* 0x560 */
    char unk564[0x5A0 - 0x564];
    int scrFlags;               /* 0x5A0 */
} cEmActor;

typedef struct cEmWrap {
    int unk00;
    cEmActor *actor;            /* 0x04 */
} cEmWrap;

#endif
