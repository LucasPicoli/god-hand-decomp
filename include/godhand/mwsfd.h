/* include/godhand/mwsfd.h - Sofdec (MWSFD) handle views used by the cygnus code at 0x347008..
 *
 * Field names are ours; offsets are exact. The SFX side stores its converted
 * values as an enum and the decoder side keeps three pointer-typed words.
 */
#ifndef GODHAND_MWSFD_H
#define GODHAND_MWSFD_H

#include "godhand/sftim.h"
#include "godhand/criSj.h"

/* Frame info as the decoder hands it over (at 0x88 of the handle). */
typedef struct MwsfdFrmInf {
    unsigned int fmtA;          /* 0x00 */
    unsigned int fmtB;          /* 0x04 */
    void *w08;
    void *w0C;
    void *w10;
    unsigned int flagA;         /* 0x14 */
    unsigned int flagB;         /* 0x18 */
} MwsfdFrmInf;

/* A sub-object the handle owns; destroy is vtable slot 3. */
typedef struct MwsfSubObj MwsfSubObj;

typedef struct MwsfSubVtbl {
    void *unk00[3];
    void (*destroy)(MwsfSubObj *self);  /* 0x0C */
} MwsfSubVtbl;

struct MwsfSubObj {
    MwsfSubVtbl *vt;
};

/* One of the handle's two stream slots (0x20 bytes). */
typedef struct MwsfdSlot {
    int flag;                   /* 0x00 1 = open */
    int id;                     /* 0x04 */
    int opened;                 /* 0x08 */
    int base;                   /* 0x0C */
    int limit;                  /* 0x10 */
    SjObj *sj;                  /* 0x14 */
    char *buf;                  /* 0x18 */
    int made;                   /* 0x1C */
} MwsfdSlot;

typedef struct MwsfdHn {
    int used;                   /* 0x000 */
    int stat;                   /* 0x004 */
    int unk08;                  /* 0x008 */
    char unk0C[0x3C - 0x0C];
    void *sfd;                  /* 0x03C the SFD handle */
    void *unk40;                /* 0x040 */
    char unk44[4];
    void *stm;                  /* 0x048 the ADX stream reading the file */
    char unk4C[0x70 - 0x4C];
    signed char busy;           /* 0x070 */
    signed char stopReq;        /* 0x071 */
    signed char pause;          /* 0x072 */
    char unk73;
    int nreq;                   /* 0x074 read requests queued */
    int hdrSize;                /* 0x078 */
    char unk7C[0x84 - 0x7C];
    int unk84;                  /* 0x084 */
    MwsfdFrmInf frm;            /* 0x088 */
    char unkA4[0xA8 - 0xA4];
    void *unkA8;                /* 0x0A8 */
    char unkAC[0xB8 - 0xAC];
    int fileType;               /* 0x0B8 */
    char unkBC[0x1C0 - 0xBC];
    MwsfSubObj *sub1C0;         /* 0x1C0 */
    char unk1C4[0x1E0 - 0x1C4];
    MwsfSubObj *sub1E0;         /* 0x1E0 */
    char unk1E4[0x284 - 0x1E4];
    MwsfdSlot slot[2];          /* 0x284 */
    char unk2C4[0x2CC - 0x2C4];
    int unk2CC;                 /* 0x2CC */
    void *unk2D0;               /* 0x2D0 */
    int latch;                  /* 0x2D4 status, set once */
    char unk2D8[4];
    int unk2DC;                 /* 0x2DC */
    int unk2E0;                 /* 0x2E0 */
    int unk2E4;                 /* 0x2E4 */
    int unk2E8;                 /* 0x2E8 */
    char unk2EC[0x2FC - 0x2EC];
    int unk2FC;                 /* 0x2FC */
    int unk300;                 /* 0x300 */
} MwsfdHn;

typedef enum { MWSFSFX_VAL_0 } MwsfsfxVal;

typedef struct MwsfsfxFrmInf {
    MwsfsfxVal fmtA;            /* 0x00 */
    MwsfsfxVal fmtB;            /* 0x04 */
    void *w08;
    void *w0C;
    void *w10;
    MwsfsfxVal flagA;           /* 0x14 */
    MwsfsfxVal flagB;           /* 0x18 */
} MwsfsfxFrmInf;

typedef struct MwsfsfxFrm {
    char unk00[0x60];
    MwsfsfxFrmInf frm;          /* 0x60 */
} MwsfsfxFrm;

/* Channel ids of a playback handle; SFD_CH_NONE if unused. */
/* Stream joints by channel id 0xBC..0xFF. */
typedef struct SfdSjTbl {
    char unk000[0x40];
    void *sj[0x44];             /* 0x040 */
    int unk150;                 /* 0x150 */
    int unk154;                 /* 0x154 */
} SfdSjTbl;

typedef struct SfdChSet {
    char unk00[8];
    SfdSjTbl *sjTbl;            /* 0x08 */
    int unk0C;
    void *sj;                   /* 0x10 the input stream joint */
    int chB;                    /* 0x14 */
    int chA;                    /* 0x18 */
    int chC;                    /* 0x1C */
} SfdChSet;

typedef struct SfdBufInf {
    char unk00[0xC];
    int minFill;                /* 0xC */
} SfdBufInf;

typedef struct SfdBufCfg {
    char unk00[0x58];
    int maxFill;                /* 0x58 */
} SfdBufCfg;

/* Time parameters (initial and current). */
typedef struct SfdTimPrm {
    int unk00[9];
    int valid;                  /* 0x24 negative until set */
    int unk28;                  /* 0x28 */
} SfdTimPrm;

typedef struct SfdSeek {
    char unk00[0x10];
    int index;                  /* 0x10 */
    char unk14[0x20 - 0x14];
    int hdrOfs;                 /* 0x20 negative until found */
} SfdSeek;

/* The ADX side record SfdHn.adxt points at. */
typedef struct SfdAdxt {
    void *adxt;                 /* 0x00 the ADXT handle */
    char unk04[0x38 - 0x04];
    int lead;                   /* 0x38 audio samples played ahead of the video */
    void (*step)(void *a0, int a1, int a2, int *a3);  /* 0x3C next step, func_0034A038 once in sync */
} SfdAdxt;

typedef struct SfdHn {
    char unk0000[8];
    int fill;                   /* 0x0008 */
    char unk000C[0x28 - 0xC];
    int unk0028;                /* 0x0028 */
    char unk002C[0x60 - 0x2C];
    int stop;                   /* 0x0060 */
    char unk0064[0x990 - 0x64];
    long total0;                /* 0x0990 */
    long total1;                /* 0x0998 */
    char unk09A0[0x9C8 - 0x9A0];
    long discarded;             /* 0x09C8 ADX bytes dropped to catch up with the video */
    char unk09D0[0xA0C - 0x9D0];
    SfdBufCfg cfg;              /* 0x0A0C */
    char unk0A68[0xD30 - 0xA68];
    char tim[0xD98 - 0xD30];    /* 0x0D30 the timing work, SftimHn.tim */
    SfdTimPrm init;             /* 0x0D98 */
    SfdTimPrm cur;              /* 0x0DC4 */
    char unk0DF0[0x1F74 - 0xDF0];
    SfdChSet ch;                /* 0x1F74 */
    char unk1F94[0x1FB8 - 0x1F94];
    SfdSeek seek;               /* 0x1FB8 */
    char unk1FDC[0x2004 - 0x1FDC];
    void **adxt;                /* 0x2004 the ADXT handle */
    char unk2008[0x37A0 - 0x2008];
    void (*readCb)(void *obj, char *ptr, int len);  /* 0x37A0 */
    void *readCbObj;            /* 0x37A4 */
    int readPos;                /* 0x37A8 */
    char *lastRead;             /* 0x37AC */
} SfdHn;

extern void MWSFSVM_Error(const char *fmt, ...);
extern int func_0034CA30(SfdHn *hn, int ch);
extern void func_0034CA00(SfdHn *hn, int ch, int arg);
extern SfdBufInf *func_0034E988(SfdHn *hn);
extern int func_0034C7F0(SfdHn *hn, int arg);

/* One stream-joint output channel of the SFD writers (0x36B888, 0x36EE90). */
typedef struct SfdSjCh {
    SjObj *sj;                          /* 0x00 */
    void (*cb)(int arg, int ch);        /* 0x04 */
    int arg;                            /* 0x08 */
} SfdSjCh;

#endif
