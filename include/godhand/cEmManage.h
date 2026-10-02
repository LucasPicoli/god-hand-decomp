/* include/godhand/cEmManage.h - cEmManage, the enemy manager.
 *
 * One cEmManage (D_005864F0) keeps every enemy in the room. EntryEm puts a
 * new enemy into one of 64 slots and links the slot into a doubly linked
 * list; ReleaseEm unlinks it. Main runs once a frame: it counts every wait
 * timer down by one, drops actor pointers whose actor is dead, and copies
 * the speed rate to each listed enemy. SetSpeedRate lasts one frame, Main
 * puts the rate back to 1.0 at its end.
 *
 * Method names are the game's own, from the symbol table and the script
 * function table in the retail ELF. Field names are ours, taken from the
 * methods that read and write them. Offsets are exact. A field we can't
 * name yet keeps its offset as its name (unkNNN); the record is at least
 * 0x5B6 bytes and its real size is not known.
 */
#ifndef GODHAND_CEMMANAGE_H
#define GODHAND_CEMMANAGE_H

#include "godhand/cOmBase.h"
#include "godhand/cEmWrap.h"

#define EM_SLOT_NUM   64      /* slots in the manager */
#define EM_SLOT_USED  1       /* cEmSlot.used: the slot holds an enemy */
#define EM_KIND_NONE  (-1)    /* cEmSlot.kind of an empty slot */
#define EM_ENTRY_NONE 0xFF    /* GetEm: no entry number */

#define EM_SPEED_RATE_NORMAL  1.0f

/* Frame counts the Set* methods start their waits at. */
#define EM_PL_BOMB_HIT_TIME   0x3C
#define EM_PL_CATCHED_TIME    2
#define EM_PL_SORRY_TIME      2
#define EM_BIG_HIT_EFF_TIME   2

/* The five enemies with emNo 0x270..0x274 that the manager keeps by number. */
#define EM_SPECIAL_NO_FIRST   0x270
#define EM_SPECIAL_NUM        5

/* What a room's enemy table hands to EntryEm (the game's SET_EM_DATA). */
typedef struct SET_EM_DATA {
    int objId;                      /* 0x00 actor to create and whose data to load */
    char unk04[0xC];
    cVec pos;                       /* 0x10 where to put it (w is 0) */
    float rot;                      /* 0x20 heading in radians */
    unsigned int flags;             /* 0x24 copied from the room entry's flags */
    int seBank;                     /* 0x28 passed on to cDataManager_loadSeWait */
    int seNo;                       /* 0x2C */
    unsigned char appPattern;       /* 0x30 how it appears */
    unsigned char entryNo;          /* 0x31 copied to cEmActor.entryNo */
} SET_EM_DATA;

/* One enemy slot. A used slot sits in the manager's list. */
typedef struct cEmSlot {
    struct cEmSlot *prev;           /* 0x00 */
    struct cEmSlot *next;           /* 0x04 */
    cEmActor *em;                   /* 0x08 */
    int kind;                       /* 0x0C EntryEm's kind, EM_KIND_NONE when empty */
    unsigned char used;             /* 0x10 EM_SLOT_USED */
    char unk11[3];
} cEmSlot;

/* The list of used slots, in entry order. */
typedef struct cEmList {
    cEmSlot *top;                   /* 0x0 */
    cEmSlot *last;                  /* 0x4 */
} cEmList;

typedef struct cEmManage {
    cEmSlot slot[EM_SLOT_NUM];      /* 0x000 */
    cEmList list;                   /* 0x500 */
    int emNum;                      /* 0x508 listed enemies */
    int kindNum;                    /* 0x50C kinds with at least one listed enemy */
    int unk510;                     /* 0x510 wait, raised by func_00292018 */
    int slotWait;                   /* 0x514 SetSlotWait */
    unsigned char darkWorld;        /* 0x518 DarkWorldCk */
    char unk519[7];
    cVec unk520;                    /* 0x520 position stored with unk530 */
    int unk530;                     /* 0x530 wait that goes with unk520 */
    char unk534[4];
    signed char bigHitEffWait;      /* 0x538 SetBigHitEffWait */
    signed char unk539;             /* 0x539 wait, func_00292F18 */
    signed char unk53A;             /* 0x53A wait */
    signed char plBombHit;          /* 0x53B SetPlBombHit */
    signed char plCatched;          /* 0x53C SetPlCatched */
    signed char plSorry;            /* 0x53D SetPlSorry */
    signed char unk53E;
    unsigned char unk53F;           /* 0x53F reset: a random number 0..4 */
    signed char unk540;             /* 0x540 wait */
    signed char unk541;             /* 0x541 wait */
    short unk542;                   /* 0x542 wait, func_00294A88 */
    float unk544;                   /* 0x544 wait, counted down by speedRate */
    float speedRate;                /* 0x548 SetSpeedRate, back to 1.0 every frame */
    int unk54C;
    int turnBehind;                 /* 0x550 set to 2 by func_00292F70: the target is behind the player */
    int turnPlus;                   /* 0x554 set to 2: it is to the player's positive-turn side */
    int turnMinus;                  /* 0x558 set to 2: it is to the other side */
    int nextNo;                     /* 0x55C getNextNo */
    cEmActor *unk560[5];            /* 0x560 */
    cEmActor *specialEm[EM_SPECIAL_NUM];  /* 0x574 emNo 0x274, then 0x270..0x273 */
    cEmActor *unk588[4];            /* 0x588 */
    char unk598[8];
    unsigned char unk5A0;           /* 0x5A0 Main: unk5A3 == 3 */
    unsigned char unk5A1;           /* 0x5A1 Main: unk5A4 == 3 */
    unsigned char unk5A2;           /* 0x5A2 Main: unk5A5 != 0 */
    unsigned char unk5A3;           /* 0x5A3 bits */
    unsigned char unk5A4;           /* 0x5A4 bits */
    unsigned char unk5A5;           /* 0x5A5 bits */
    char unk5A6[6];
    cEmActor *unk5AC[2];            /* 0x5AC */
    char unk5B4;
    unsigned char unk5B5;           /* 0x5B5 */
} cEmManage;

#define EMMANAGE_OFFSET(field) ((int)&((cEmManage *)0)->field)
typedef char SET_EM_DATA_chk_size[sizeof(SET_EM_DATA) == 0x34 ? 1 : -1];
typedef char SET_EM_DATA_chk_pos[(int)&((SET_EM_DATA *)0)->pos == 0x10 ? 1 : -1];
typedef char SET_EM_DATA_chk_flags[(int)&((SET_EM_DATA *)0)->flags == 0x24 ? 1 : -1];
typedef char cEmSlot_chk_size[sizeof(cEmSlot) == 0x14 ? 1 : -1];
typedef char cEmManage_chk_top[EMMANAGE_OFFSET(list.top) == 0x500 ? 1 : -1];
typedef char cEmManage_chk_vec[EMMANAGE_OFFSET(unk520) == 0x520 ? 1 : -1];
typedef char cEmManage_chk_wait[EMMANAGE_OFFSET(bigHitEffWait) == 0x538 ? 1 : -1];
typedef char cEmManage_chk_rate[EMMANAGE_OFFSET(speedRate) == 0x548 ? 1 : -1];
typedef char cEmManage_chk_turn[EMMANAGE_OFFSET(turnBehind) == 0x550 ? 1 : -1];
typedef char cEmManage_chk_no[EMMANAGE_OFFSET(nextNo) == 0x55C ? 1 : -1];
typedef char cEmManage_chk_special[EMMANAGE_OFFSET(specialEm) == 0x574 ? 1 : -1];
typedef char cEmManage_chk_flags[EMMANAGE_OFFSET(unk5A0) == 0x5A0 ? 1 : -1];
typedef char cEmManage_chk_5ac[EMMANAGE_OFFSET(unk5AC) == 0x5AC ? 1 : -1];
typedef char cEmManage_chk_5b5[EMMANAGE_OFFSET(unk5B5) == 0x5B5 ? 1 : -1];

/* Takes slot out of the list. Does nothing for a null slot. */
static __inline__ void cEmList_unlink(cEmList *list, cEmSlot *slot)
{
    cEmSlot *prev;
    cEmSlot *next;

    if (slot != 0) {
        prev = slot->prev;
        next = slot->next;
        if (prev == 0)
            list->top = next;
        else
            prev->next = next;
        if (next == 0)
            list->last = prev;
        else
            next->prev = prev;
    }
}

/* The game's one enemy manager. */
extern cEmManage D_005864F0;

/* Methods, in address order. */
cEmSlot *cEmManage_constructSlot(cEmSlot *slot);
void cEmManage_clearSlot(cEmSlot *slot);
void cEmManage_setSlot(cEmSlot *slot, cEmActor *em, int kind);
cEmManage *cEmManage_construct(cEmManage *self);
void cEmManage_reset(cEmManage *self);
void cEmManage_Main(cEmManage *self);
cEmActor *cEmManage_EntryEm(cEmManage *self, SET_EM_DATA *data, int kind, void *parent);
int cEmManage_ReleaseEm(cEmManage *self, cEmActor *em);
cEmActor *cEmManage_GetEm(cEmManage *self, unsigned char entryNo);
void cEmManage_ReleaseEmAll(cEmManage *self);
int cEmManage_findFreeSlot(cEmManage *self);
int cEmManage_countKind(cEmManage *self, int kind);
int cEmManage_ChkActiveEm(cEmManage *self, cEmActor *em);
int func_002919C0(cEmManage *self, int unused, int emNo);
int cEmManage_DarkWorldCk(cEmManage *self);
int func_00291FD8(cEmManage *self);
void func_00291FE8(cEmManage *self, cVec *pos, int wait);
void func_00292018(cEmManage *self, int wait);
void cEmManage_SetSlotWait(cEmManage *self, int wait);
void cEmManage_setBigHitEff(cEmManage *self);
void cEmManage_SetBigHitEffWait(cEmManage *self, int wait);
int cEmManage_CkBigHitEffWait(cEmManage *self);
int func_00292F18(cEmManage *self);
void cEmManage_SetSpeedRate(cEmManage *self, float rate);
float cEmManage_GetSpeedRate(cEmManage *self);
int cEmManage_getNextNo(cEmManage *self);
void Obj293_SetByte_53A_2(cEmManage *self);
void cEmManage_SetPlBombHit(cEmManage *self);
int cEmManage_CkPlBombHit(cEmManage *self);
void cEmManage_SetPlCatched(cEmManage *self);
int cEmManage_CkPlCatched(cEmManage *self);
void cEmManage_SetPlSorry(cEmManage *self);
int cEmManage_CkPlSorry(cEmManage *self);
cEmSlot *cEmManage_getTop(cEmManage *self);
void Obj293_OrByte_5A3(cEmManage *self, unsigned int bits);
void Obj293_ClearBytes_5A0_5A3(cEmManage *self);
void Obj293_OrByte_5A4(cEmManage *self, unsigned int bits);
void Obj293_OrByte_5A5_1(cEmManage *self);
void func_00293760(cEmManage *self, cEmActor *em);
void func_00294898(cEmManage *self, cEmActor *actor);
cEmActor *func_002948C8(cEmManage *self, unsigned int no);
void func_00294968(cEmManage *self, float wait);
int func_00294970(cEmManage *self);
void func_002949C8(cEmManage *self);
int func_00294A68(cEmManage *self);
int func_00294A78(cEmManage *self);
void func_00294A88(cEmManage *self);

#endif /* GODHAND_CEMMANAGE_H */
