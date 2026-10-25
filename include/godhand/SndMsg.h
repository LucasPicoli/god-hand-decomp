/* include/godhand/SndMsg.h - sound message nodes (sn code at 0x375EF8).
 *
 * The sound driver queues work as 0x44-byte message nodes taken from a pool
 * (func_0037D170). A builder fills one node from a playing sound (the
 * source), a request record and a row of the bank's sound table, then hands
 * it to func_00376CF8.
 *
 * Field names are ours, taken from the builders that fill the nodes.
 * Offsets are exact. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_SNDMSG_H
#define GODHAND_SNDMSG_H

#define SNDMSG_ROW_SIZE     0x30    /* one row of a bank's sound table */
#define SNDMSG_KIND_HIT     3       /* node kind set by the hit-message builder */
#define SNDMSG_ROW_OFF      0x8000  /* row flag: the row is switched off */

/* A playing sound as the builders read it. */
typedef struct SndMsgSrc {
    char unk00[2];
    unsigned short id;                  /* 0x02 */
    int handle;                         /* 0x04 */
    short bank;                         /* 0x08 index into D_0076EA50 */
    char unk0A[4];
    unsigned char prio;                 /* 0x0E */
    unsigned char vol;                  /* 0x0F */
    char unk10[4];
    unsigned short pitch;               /* 0x14 */
} SndMsgSrc;

/* The request that asks for a message. */
typedef struct SndMsgReq {
    char unk00[2];
    unsigned short bias;                /* 0x02 low byte is added to the source volume */
    int handle;                         /* 0x04 */
    unsigned short volL;                /* 0x08 */
    short row;                          /* 0x0A row of the bank's sound table */
    unsigned short vara;                /* 0x0C */
    unsigned short varb;                /* 0x0E */
    unsigned short varc;                /* 0x10 */
} SndMsgReq;

/* One row of a bank's sound table. */
typedef struct SndMsgRow {
    char unk00[4];
    unsigned short base;                /* 0x04 */
    char unk06[8];
    unsigned short flags;               /* 0x0E SNDMSG_ROW_OFF */
    char unk10[8];
    unsigned short lo;                  /* 0x18 */
    unsigned short hi;                  /* 0x1A */
    char unk1C[0x14];
} SndMsgRow;                            /* 0x30 */

typedef struct SndMsgNode {
    short kind;                         /* 0x00 */
    char unk02[2];
    int handle;                         /* 0x04 request handle */
    int srcHandle;                      /* 0x08 */
    unsigned char prio;                 /* 0x0C */
    unsigned char mode;                 /* 0x0D */
    short ofsA;                         /* 0x0E */
    short ofsB;                         /* 0x10 */
    unsigned short srcId;               /* 0x12 */
    unsigned short reqBias;             /* 0x14 */
    char unk16[0xA];
    unsigned short volL;                /* 0x20 */
    unsigned short row;                 /* 0x22 */
    unsigned short base;                /* 0x24 */
    unsigned char vol;                  /* 0x26 */
    unsigned char unk27;                /* 0x27 */
    unsigned char level;                /* 0x28 */
    unsigned char unk29;                /* 0x29 */
    short unk2A;                        /* 0x2A */
    unsigned short pitch;               /* 0x2C */
    short code;                         /* 0x2E */
    unsigned short vara;                /* 0x30 */
    unsigned short varaCopy;            /* 0x32 */
    unsigned short varb;                /* 0x34 */
    short unk36;                        /* 0x36 */
    unsigned short lo;                  /* 0x38 */
    unsigned short hi;                  /* 0x3A */
    unsigned short varc;                /* 0x3C */
    signed char tail;                   /* 0x3E */
    char unk3F;
    unsigned char z40, z41, z42, z43;   /* 0x40 */
} SndMsgNode;                           /* 0x44 */

extern SndMsgNode *func_0037D170(void);
extern void func_00376CF8(SndMsgSrc *src, SndMsgNode *node);

#endif
