/* include/godhand/SndSlotInit.h - starting a sound slot from a request descriptor (sn code at 0x376080).
 * SndSlotHead is the first 0x40 bytes of a SndSlot (SndSlot.h), SndDesc is the descriptor
 * the caller fills. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SNDSLOTINIT_H
#define GODHAND_SNDSLOTINIT_H

#include "godhand/sndBank.h"

#define SNDSLOT_LIVE        1       /* SndSlotHead.state of a started slot */
#define SNDSLOT_ERR_FULL    (-1)

typedef struct SndDesc {
    char unk00[4];
    int id;                     /* 0x04 */
    char unk08[8];
    unsigned short bank;        /* 0x10 key fields read by the slot search */
    unsigned short prog;        /* 0x12 */
    unsigned short idx;         /* 0x14 */
    unsigned char vol;          /* 0x16 */
    unsigned char pan;          /* 0x17 */
    unsigned char prio;         /* 0x18 */
    char unk19[3];
    unsigned short flagsA;      /* 0x1C */
    unsigned short flagsB;      /* 0x1E */
    unsigned short pitch;       /* 0x20 */
    char unk22[6];
    unsigned short volL;        /* 0x28 */
    unsigned short volR;        /* 0x2A */
    unsigned short fadeIn;      /* 0x2C */
    char unk2E[6];
    unsigned short fadeOut;     /* 0x34 */
} SndDesc;

typedef struct SndSlotHead {
    unsigned short state;       /* 0x00 */
    char unk02[2];
    int id;                     /* 0x04 */
    short bank;                 /* 0x08 */
    short prog;                 /* 0x0A */
    short idx;                  /* 0x0C */
    unsigned char vol;          /* 0x0E */
    unsigned char pan;          /* 0x0F */
    unsigned char prio;         /* 0x10 */
    char unk11;
    short unk12;                /* 0x12 cleared */
    unsigned short flagsA;      /* 0x14 */
    unsigned short flagsB;      /* 0x16 */
    short pitch;                /* 0x18 */
    short unk1A;                /* 0x1A cleared */
    short unk1C;                /* 0x1C cleared */
    short unk1E;                /* 0x1E cleared */
    unsigned short volL;        /* 0x20 */
    short volR;                 /* 0x22 */
    short gainL;                /* 0x24 */
    short gainR;                /* 0x26 */
    unsigned short fadeIn;      /* 0x28 */
    unsigned short fadeOut;     /* 0x2A */
    char *seq;                  /* 0x2C script start */
    char *pc;                   /* 0x30 script cursor */
    char *seqEnd;               /* 0x34 */
    int wait;                   /* 0x38 */
    unsigned char kind;         /* 0x3C */
    unsigned char sub;          /* 0x3D */
} SndSlotHead;

extern SndSlotHead *FindSlotEntry_376A10(SndDesc *key);
extern short func_003780B0(short a, short b);
extern void func_003761D0(SndSlotHead *slot);

#endif
