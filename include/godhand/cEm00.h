/* include/godhand/cEm00.h - the enemy object record.
 *
 * cEm00 is the base class of the enemies: every enemy object starts with this
 * record and a derived enemy appends its own state after it. The record is
 * at least 0x1870 bytes. Most of an enemy's behaviour is a phase machine: an
 * AI function reads the speed rate, calls the motion code and switches on
 * the step byte (0x2F6), moving to the next step when a motion ends.
 *
 * The first words follow cOmBase: the four state bytes at 0x2F4, the flag
 * word at 0x250, the hit points at 0x54A, the enemy number at 0x564 and the
 * speed rate at 0x5A8 have the same names in cEmWrap.h. The method table at
 * 0x214 belongs to a second base class; its entries are g++ 2.x delta and
 * pfn pairs, and CEM00_VCALL makes the call.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_CEM00_H
#define GODHAND_CEM00_H

#include "godhand/cOmBase.h"

/* The address of a record in the resource blob. The blob starts with a
 * table of offsets from its own start; res is the blob's address as an int
 * and off the table slot. */
#define EM_RES_REC(res, off) (*(int *)((res) + (off)) + (res))

/* The method table at 0x214. Each method is a short delta, added to this
 * before the call, a short index and a pfn. */
typedef struct cEm00Vt {
    char unk00[0x60];
    short suspendDelta;                     /* 0x60 */
    short pad62;
    void (*suspend)(void *self, int flag);  /* 0x64 */
    char unk68[8];
    short setPosDelta;                      /* 0x70 */
    short pad72;
    void (*setPos)(void *self, void *pos);  /* 0x74 */
    short setScaleDelta;                    /* 0x78 */
    short pad7A;
    void (*setScale)(void *self, void *scale); /* 0x7C */
    char unk80[0xA8 - 0x80];
    short hitDelta;                         /* 0xA8 */
    short padAA;
    void (*hit)(void *self, int power, void *attacker, int a, int b); /* 0xAC */
} cEm00Vt;

/* Call method m of the object's table: the delta of entry m goes to this. */
#define CEM00_VCALL(self, m, args...) \
    ((self)->vt->m((char *)(self) + (self)->vt->m##Delta, args))

/* The low byte of a word field (the record is little endian). */
#define CEM00_LOBYTE(field) (*(unsigned char *)&(field))

typedef struct cEm00 {
    char unk000[0xD0];
    cVec *anchor;                           /* 0x0D0 the vector the body is pinned to */
    char unk0D4[0x1C];
    cVec *pos;                              /* 0x0F0 the enemy's live position */
    char unk0F4[0xC];
    cVec rot;                               /* 0x100 rotation, rot.y is the facing angle */
    char unk110[0x104];
    cEm00Vt *vt;                            /* 0x214 method table of the second base; entries are delta/pfn pairs */
    char unk218[0x34];
    float animRate;                         /* 0x24C 1.0 normal */
    int objFlags;                           /* 0x250 EMACTOR_FLAG_DEAD once the actor is gone */
    char unk254[0xA0];
    unsigned char mode;                     /* 0x2F4 0x2F4..0x2F7 are the four state bytes, as in cOmBase */
    unsigned char phase;                    /* 0x2F5 */
    unsigned char step;                     /* 0x2F6 the phase machines switch on this byte */
    unsigned char stepArg;                  /* 0x2F7 */
    char unk2F8[0x6];
    unsigned short actorId;                 /* 0x2FE */
    char unk300[0x4];
    int resource;                           /* 0x304 address of the enemy's resource blob; motion records are offsets from it */
    char unk308[0xA4];
    unsigned short moveFlags;               /* 0x3AC bits the move code sets: bit 0 and 1 end of a motion, 0x10 */
    char unk3AE[0xE2];
    cVec posA;                              /* 0x490 position copy */
    char unk4A0[0xA8];
    short vitalMax;                         /* 0x548 */
    short vital;                            /* 0x54A hit points */
    float hitFlash;                         /* 0x54C 3.0 right after a hit */
    char unk550[0x10];
    int dropItem;                           /* 0x560 */
    int emNo;                               /* 0x564 enemy number */
    short unk568;                           /* 0x568 set when a hit lands; the end-of-motion code clears it and calls the hit method */
    char unk56A[0x36];
    int scrFlags;                           /* 0x5A0 */
    char unk5A4[0x4];
    float speedRate;                        /* 0x5A8 copied from cEmManage every frame; timers count down by it */
    char unk5AC[0x8];
    int unk5B4;                             /* 0x5B4 */
    char unk5B8[0x8];
    cVec home;                              /* 0x5C0 the point the position is eased toward */
    char unk5D0[0x30];
    float timer;                            /* 0x600 countdown, counted down by speedRate */
    char unk604[0x14];
    float playerDist;                       /* 0x618 distance to the player */
    char unk61C[0x24];
    unsigned short entryNo;                 /* 0x640 the room table's number for it */
    char unk642[0x106];
    int sub0;                               /* 0x748 child object, its own state bytes follow the enemy's */
    int sub1;                               /* 0x74C */
    int sub2;                               /* 0x750 */
    char unk754[0xC];
    float unk760;                           /* 0x760 */
    char unk764[0xDFC];
    int unk1560;                            /* 0x1560 the low byte is also read and cleared as a byte, see CEM00_LOBYTE */
    char unk1564[0xC];
    cVec unk1570;                           /* 0x1570 */
    struct cEm00 *target;                   /* 0x1580 the enemy this one watches */
    char unk1584[0xC];
    cVec unk1590;                           /* 0x1590 */
    cVec gotoPos;                           /* 0x15A0 goal of a goto, see cEma2_gotoSwitch */
    int gotoFlags;                          /* 0x15B0 bit 0x80 is set by cEma2_gotoSwitch */
    float unk15B4;                          /* 0x15B4 */
    char unk15B8[0x4];
    float unk15BC;                          /* 0x15BC countdown, restarts at a random 90 to 180 frames */
    char unk15C0[0x110];
    int emFlags;                            /* 0x16D0 */
    char unk16D4[0x20];
    float unk16F4;                          /* 0x16F4 the float argument of the motion start, always stored as the int 0 */
    char unk16F8[0xD4];
    float unk17CC;                          /* 0x17CC set to 150.0 by func_0026F120, tested positive by func_0026F1D8 */
    char unk17D0[0xA0];
} cEm00;

typedef char cEm00_size_check[(sizeof(cEm00) == 0x1870) ? 1 : -1];

#endif
