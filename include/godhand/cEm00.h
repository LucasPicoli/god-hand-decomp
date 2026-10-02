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
    short getPosDelta;                      /* 0x80 */
    short pad82;
    cVec *(*getPos)(void *self);            /* 0x84 pointer to the object's position */
    short getScaleDelta;                    /* 0x88 */
    short pad8A;
    cVec *(*getScale)(void *self);          /* 0x8C */
    char unk90[0xA8 - 0x90];
    short hitDelta;                         /* 0xA8 */
    short padAA;
    int (*hit)(void *self, int power, void *attacker, int a, int b); /* 0xAC */
} cEm00Vt;

/* Call method m of the object's table: the delta of entry m goes to this. */
#define CEM00_VCALL0(self, m) \
    ((self)->vt->m((char *)(self) + (self)->vt->m##Delta))
#define CEM00_VCALL(self, m, args...) \
    ((self)->vt->m((char *)(self) + (self)->vt->m##Delta, args))

/* The low byte of a word field (the record is little endian). */
#define CEM00_LOBYTE(field) (*(unsigned char *)&(field))

/* Emits no code in the object. gcc reduces the pair to a byte load and a
 * store of the same value, which it deletes only after register allocation.
 * While it exists the byte holds a register, so the pointers of the next
 * vector copy move to other registers; func_0025AB70 needs a0 and v1 there
 * and no other spelling of the pointers gave them. Put it between two
 * statements and score. */
#define CEM00_REGALLOC_NUDGE(self) (self)->phase++; (self)->phase--

typedef struct cEm00 {
    char unk000[0xD0];
    cVec *anchor;                           /* 0x0D0 the vector the body is pinned to */
    char unk0D4[0x1C];
    cVec *pos;                              /* 0x0F0 the enemy's live position */
    char unk0F4[0xC];
    cVec rot;                               /* 0x100 rotation, rot.y is the facing angle */
    float unk110;                           /* 0x110 x of a second vector, scaled by 0.0902 in step 6 */
    float unk114;                           /* 0x114 */
    float unk118;                           /* 0x118 z of that vector, scaled by 1.8281 in step 6 */
    char unk11C[0xF8];
    cEm00Vt *vt;                            /* 0x214 method table of the second base; entries are delta/pfn pairs */
    char unk218[0x34];
    float animRate;                         /* 0x24C 1.0 normal */
    int objFlags;                           /* 0x250 EMACTOR_FLAG_DEAD once the actor is gone */
    char unk254[0x24];
    struct cEm00 **children;                /* 0x278 child object list */
    char unk27C[0x38];
    unsigned char childNum;                 /* 0x2B4 number of children */
    char unk2B5[0x3F];
    unsigned char mode;                     /* 0x2F4 0x2F4..0x2F7 are the four state bytes, as in cOmBase */
    unsigned char phase;                    /* 0x2F5 */
    unsigned char step;                     /* 0x2F6 the phase machines switch on this byte */
    unsigned char stepArg;                  /* 0x2F7 */
    char unk2F8[0x4];
    unsigned char unk2FC;                   /* 0x2FC low 3 bits are compared with D_007476B0 */
    char unk2FD[0x1];
    unsigned short actorId;                 /* 0x2FE */
    char unk300[0x4];
    int resource;                           /* 0x304 address of the enemy's resource blob; motion records are offsets from it */
    char unk308[0x28];
    cVec stepVec;                           /* 0x330 this frame's step: the 0x580 vector scaled by speedRate */
    char unk340[0x6C];
    unsigned short moveFlags;               /* 0x3AC bits the move code sets: bit 0 and 1 end of a motion, 0x10 */
    char unk3AE[0x86];
    unsigned short unk434;                  /* 0x434 flag word, bit 3 is set before each move */
    char unk436[0x5A];
    cVec posA;                              /* 0x490 position copy */
    char unk4A0[0xA8];
    short vitalMax;                         /* 0x548 */
    short vital;                            /* 0x54A hit points */
    float hitFlash;                         /* 0x54C 3.0 right after a hit */
    char unk550[0x10];
    int dropItem;                           /* 0x560 */
    int emNo;                               /* 0x564 enemy number */
    short unk568;                           /* 0x568 set when a hit lands; the end-of-motion code clears it and calls the hit method */
    short unk56A;                           /* 0x56A countdown beside unk568 */
    char unk56C[0x14];
    cVec unk580;                            /* 0x580 */
    cVec unk590;                            /* 0x590 */
    int scrFlags;                           /* 0x5A0 */
    char unk5A4[0x4];
    float speedRate;                        /* 0x5A8 copied from cEmManage every frame; timers count down by it */
    char unk5AC[0x4];
    int unk5B0;                             /* 0x5B0 flag word of the derived enemy, bit 0 is set when the step ends */
    int unk5B4;                             /* 0x5B4 */
    char unk5B8[0x8];
    cVec home;                              /* 0x5C0 the point the position is eased toward */
    cVec posB;                              /* 0x5D0 the point the turn aims at (cOmBase posB) */
    short unk5E0;                           /* 0x5E0 cleared with unk5E2 when a motion starts */
    short unk5E2;                           /* 0x5E2 cleared every frame while the counter at 0x15B4 runs */
    char unk5E4[0xC];
    int timerA;                             /* 0x5F0 countdown of the turn toward the target, one per frame */
    int timerB;                             /* 0x5F4 second counter */
    int unk5F8;                             /* 0x5F8 set again when moveFlags bit 0 is clear; the first set bit calls the effect once */
    int timerC;                             /* 0x5FC third counter, also used as a 0 or 1 latch like 0x5F8 */
    float timer;                            /* 0x600 countdown, counted down by speedRate */
    float timer2;                           /* 0x604 second countdown */
    float timer3;                           /* 0x608 third countdown, counted down by speedRate */
    float unk60C;                           /* 0x60C zeroed when a hit step starts */
    char unk610[0x7];
    unsigned char unk617;                   /* 0x617 set to 1 when the step starts */
    float playerDist;                       /* 0x618 distance to the player */
    char unk61C[0x24];
    unsigned short entryNo;                 /* 0x640 the room table's number for it */
    char unk642[0x6];
    unsigned char unk648;                   /* 0x648 set to 0x14 while the 0x640 link is held */
    char unk649[0x2F];
    void *unk678;                           /* 0x678 link record of the enemy it works with, its 0x34 field is the target object */
    char unk67C[0x1C];
    void *unk698;                           /* 0x698 link record, its 0x34 field is the enemy being watched */
    char unk69C[0x18];
    struct cEm00 *foe;                      /* 0x6B4 the other enemy this one works with */
    char unk6B8[0x18];
    cVec unk6D0;                            /* 0x6D0 */
    float unk6E0;                           /* 0x6E0 copied to the facing angle (rot.y) at the start of a step */
    char unk6E4[0x8];
    int unk6EC;                             /* 0x6EC handle released by ReleaseField6ECByTag564_26B1E8 */
    int fx0;                                /* 0x6F0 effect handle */
    char unk6F4[0x4];
    int fx2;                                /* 0x6F8 effect handle */
    int fx3;                                /* 0x6FC effect handle */
    int fx4;                                /* 0x700 effect handle */
    int fx5;                                /* 0x704 effect handle */
    int fx6;                                /* 0x708 effect handle */
    char unk70C[0x24];
    int unk730;                             /* 0x730 effect handle, released when moveFlags bit 0 is set */
    char unk734[0xC];
    int subA;                               /* 0x740 child object started with a variant number */
    int unk744;                             /* 0x744 */
    int sub0;                               /* 0x748 child object, its own state bytes follow the enemy's */
    int sub1;                               /* 0x74C */
    int sub2;                               /* 0x750 */
    char unk754[0xC];
    float unk760;                           /* 0x760 */
    char unk764[0x4];
    float unk768;                           /* 0x768 angle tested against pi/4 before the attack */
    char unk76C[0x194];
    int unk900;                             /* 0x900 countdown of the derived enemy, ticks down once per frame */
    char unk904[0xC5C];
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
    char unk15C0[0x4];
    int unk15C4;                            /* 0x15C4 handle of the item this enemy dropped, 0 while none */
    char unk15C8[0x2C];
    int unk15F4;                            /* 0x15F4 flag word of the derived enemy, 0x10000 is set while the counter runs */
    char unk15F8[0xB];
    unsigned char unk1603;                  /* 0x1603  */
    char unk1604[0x10];
    unsigned char unk1614;                  /* 0x1614 selector of the derived enemy, 0 to 2 */
    char unk1615[0xB];
    int unk1620;                            /* 0x1620 sound handle, stopped with cSnd_SeStop */
    char unk1624[0x20];
    int flags1644;                          /* 0x1644 flag word, bit 0x800000 keeps the body down */
    char unk1648[0x48];
    cVec wallPoint;                         /* 0x1690 the wall point the dodge checks against */
    cVec unk16A0;                           /* 0x16A0 */
    char unk16B0[0x20];
    int emFlags;                            /* 0x16D0 */
    int emFlags2;                           /* 0x16D4 */
    unsigned int unk16D8;                   /* 0x16D8 */
    int unk16DC;                            /* 0x16DC  */
    int unk16E0;                            /* 0x16E0  */
    float idleTimer;                        /* 0x16E4 countdown set when a motion ends: 150 to 300 frames */
    int unk16E8;                            /* 0x16E8 */
    int unk16EC;                            /* 0x16EC */
    char unk16F0[0x4];
    float unk16F4;                          /* 0x16F4 the float argument of the motion start, always stored as the int 0 */
    int unk16F8;                            /* 0x16F8 */
    char unk16FC[0x10];
    float unk170C;                          /* 0x170C scaled by 10.0 into unk1710 on a hard hit */
    int unk1710;                            /* 0x1710 cleared at the start of a step */
    char unk1714[0xC];
    float unk1720;                          /* 0x1720 */
    char unk1724[0xC];
    float unk1730;                          /* 0x1730 */
    char unk1734[0xC];
    float unk1740;                          /* 0x1740 */
    char unk1744[0x24];
    float unk1768;                          /* 0x1768 */
    char unk176C[0x34];
    int unk17A0;                            /* 0x17A0 the object this enemy turns toward, cleared when its motion ends */
    char unk17A4[0x17];
    unsigned char unk17BB;                  /* 0x17BB */
    char unk17BC[0x7];
    unsigned char unk17C3;                  /* 0x17C3 */
    char unk17C4[0x6];
    unsigned short unk17CA;                 /* 0x17CA 30 before a motion ends */
    float unk17CC;                          /* 0x17CC set to 150.0 by func_0026F120, tested positive by func_0026F1D8 */
    char unk17D0[0x94];
    unsigned char unk1864;                  /* 0x1864 */
    char unk1865[0x5];
    unsigned char unk186A;                  /* 0x186A */
    unsigned char unk186B;                  /* 0x186B a scalar byte */
    char unk186C[0x4];
} cEm00;

typedef char cEm00_size_check[(sizeof(cEm00) == 0x1870) ? 1 : -1];

#endif
