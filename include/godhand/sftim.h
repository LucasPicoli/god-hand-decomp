/* include/godhand/sftim.h - Sofdec timing and picture-decode work areas.
 *
 * SftimHn is the Sofdec handle seen from the timing (0xD30) and picture
 * decode (0x1FC0) code. Offsets are exact; unnamed fields stay as unkNNN
 * padding. Field names are ours, taken from the functions that use them.
 */
#ifndef GODHAND_SFTIM_H
#define GODHAND_SFTIM_H

#include "godhand/criSj.h"

typedef struct SfdErr {
    char unk00[0x8];
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    char unk10[0x2C - 0x10];
    int err;                    /* 0x2C */
} SfdErr;

typedef struct SfdCnt {
    char unk00[0xC];
    int f0C;                    /* 0x0C */
    int f10;                    /* 0x10 */
} SfdCnt;

typedef struct SfdPrf {
    char unk00[0x20];
} SfdPrf;

/* A timecode: rate index, drop-frame flag, h:m:s:f and two half-field counts. */
typedef struct SftimTc {
    int rate;                   /* 0x00 index into D_004596C8 */
    int drop;                   /* 0x04 drop-frame */
    int hour;                   /* 0x08 */
    int min;                    /* 0x0C */
    int sec;                    /* 0x10 */
    int frame;                  /* 0x14 */
    int frameAdd;               /* 0x18 */
    short fieldA;               /* 0x1C */
    short fieldB;               /* 0x1E */
} SftimTc;

extern int D_004596C8[];        /* frames per second by rate index */

/* One timing record: valid flag, the timecode it was taken at, and that timecode as time/unit. */
typedef struct SftimRec {
    int valid;                  /* 0x00 */
    SftimTc tc;                 /* 0x04 */
    int time;                   /* 0x24 */
    int unit;                   /* 0x28 */
} SftimRec;

typedef struct SftimFld {
    short unk0;
    short fieldB;
} SftimFld;

/* The timing work area of the Sofdec handle, at +0xD30. */
typedef struct SftimWork {
    char unk000[0x1C];
    SftimTc tc;                 /* 0x1C current timecode */
    SftimRec rec[6];            /* 0x3C start, 0x68 longest, 0x94, 0xC0 last, 0xEC, 0x118 */
    char unk144[0x160 - 0x144];
    int f160;                   /* 0x160 */
    int f164;                   /* 0x164 */
    char unk168[0x284 - 0x168];
    int f284;                   /* 0x284 latest frame time */
    int f288;                   /* 0x288 its unit */
    char unk28C[0x4B0 - 0x28C];
    SftimFld fld[1];            /* 0x4B0, indexed by channel */
} SftimWork;

typedef struct SftimHn {
    char unk000[0x38];
    int mode;                   /* 0x38 */
    char unk03C[0x950 - 0x3C];
    struct SfdErr errInf;       /* 0x950 */
    char unk980[0x9F8 - 0x980];
    struct SfdCnt cnt;          /* 0x9F8 */
    char unkA0C[0xD30 - 0xA0C];
    SftimWork tim;              /* 0xD30 */
    char unk11E4[0x1FC0 - 0x11E4];
    struct SfdWork *work;       /* 0x1FC0 */
    char unk1FC4[0x36B0 - 0x1FC4];
    int f36B0;                  /* 0x36B0 */
    char unk36B4[0x36C0 - 0x36B4];
    struct SfdPrf prf[4];       /* 0x36C0 decode time by picture type */
} SftimHn;

/* User data buffer: pointer and length. */
typedef struct SfdUsrBuf {
    unsigned char *buf;         /* 0x00 */
    int len;                    /* 0x04 */
} SfdUsrBuf;

/* Decoded picture info, copied into each frame. */
typedef struct SfdPicInf {
    int width;                  /* 0x00 */
    int height;                 /* 0x04 */
    char unk08[0x10 - 0x08];
    int rate;                   /* 0x10 */
    char unk14[0x18 - 0x14];
    unsigned int picType;       /* 0x18 1 I, 2 P, 3 B */
    char unk1C[0x38 - 0x1C];
    int f38;                    /* 0x38 */
    char unk3C[0x58 - 0x3C];
    unsigned int picStruct;     /* 0x58 0 none, 1-2 field, 3 frame */
    char unk5C[0x6C - 0x5C];
    signed char progressive;    /* 0x6C */
    char unk6D[0x80 - 0x6D];
} SfdPicInf;

typedef struct SfdFrm {
    union {
        int state;              /* 0 free, 1 busy, 2/4 decoded */
        long word;
    } h;                        /* 0x00 */
    unsigned char *buf;         /* 0x08 */
    SftimRec rec;               /* 0x0C */
    int time;                   /* 0x38 */
    int unit;                   /* 0x3C */
    int x;                      /* 0x40 */
    int y;                      /* 0x44 */
    int f48;                    /* 0x48 */
    int ptsTime;                /* 0x4C */
    int dispTime;               /* 0x50 */
    SfdUsrBuf *usr;             /* 0x54 */
    int f58;                    /* 0x58 */
    SfdPicInf pic;              /* 0x5C */
    char unkDC[0xE0 - 0xDC];
    long long decTime;          /* 0xE0 */
    int count;                  /* 0xE8 */
} SfdFrm;

/* One output plane pair: luma, chroma, buffer base and both strides. */
typedef struct SfdPlane {
    unsigned char *y;           /* 0x00 */
    unsigned char *c;           /* 0x04 */
    unsigned char *base;        /* 0x08 */
    short cPitch;               /* 0x0C */
    short yPitch;               /* 0x0E */
} SfdPlane;

typedef struct SfdOut {
    SfdPlane cur;               /* 0x00 */
    SfdPlane ref;               /* 0x10 */
    unsigned char *buf;         /* 0x20 */
    SfdPicInf *pic;             /* 0x24 */
    int f28;                    /* 0x28 */
    int f2C;                    /* 0x2C */
} SfdOut;

/* Channel ids of the SFD ring buffer; SFD_CH_NONE when absent. */
#define SFD_CH_NONE 8

typedef struct SfdChIds {
    char unk00[0x14];
    int audio;                  /* 0x14 */
    int video;                  /* 0x18 */
    int other;                  /* 0x1C */
} SfdChIds;

/* The picture frame buffer setup in SfdWork. */
typedef struct SfdFrmCfg {
    int unk00;
    int unk04;
    int maxW;                   /* 0x08 largest picture the buffers fit */
    int maxH;                   /* 0x0C */
    int unk10;
    int bufW;                   /* 0x14 */
    int bufH;                   /* 0x18 */
    int nbuf;                   /* 0x1C */
    char *buf;                  /* 0x20 frame buffer area, or 0 */
} SfdFrmCfg;

typedef struct SfdWork {
    void *dec;                  /* 0x000 */
    SfdFrmCfg cfg;              /* 0x004 */
    char unk028[0x30 - 0x28];
    char *frmBuf[16];           /* 0x030 each frame's buffer */
    char unk070[0x7C - 0x70];
    int f7C;                    /* 0x07C */
    char unk080[0x84 - 0x80];
    int f84;                    /* 0x084 */
    int f88;                    /* 0x088 */
    SfdPicInf pic;              /* 0x08C */
    char unk10C[0x138 - 0x10C];
    int curIdx;                 /* 0x138 */
    int refIdx;                 /* 0x13C */
    SfdPlane plane[2];          /* 0x140 */
    SfdFrm *cur;                /* 0x160 */
    SfdFrm *ref;                /* 0x164 */
    SfdFrm *hold;               /* 0x168 */
    int f16C;                   /* 0x16C */
    int f170;                   /* 0x170 */
    int xOfs;                   /* 0x174 */
    int nfrm;                   /* 0x178 */
    int unk17C;
    SfdFrm frm[16];             /* 0x180 frame pool */
    char unk1080[0x108C - 0x1080];
    SfdUsrBuf usr0;             /* 0x108C */
    SfdUsrBuf usr;              /* 0x1094 */
    char unk109C[0x1120 - 0x109C];
    long long time;             /* 0x1120 */
    char unk1128[0x1F74 - 0x1128];
    SfdChIds ch;                /* 0x1F74 */
} SfdWork;

typedef struct ViBuf ViBuf;

#define SFD_WORK_VIBUF(w) ((ViBuf *)((char *)(w) + 0x1198))

/* Frame-pool lock guard enter/leave (16-byte guard on the caller stack). */
extern void Thunk_func_0033B658(char *guard);
extern void Thunk_func_0033B670(char *guard);
extern SfdFrm *func_003555A8(SftimHn *hn);

extern int D_00459730[];        /* picture/extension type by 3-bit code */
extern int D_003EE2F0;          /* delimiter search error count */

/* Timecode source info passed to func_00352790. */
typedef struct SftimInfo {
    char unk00[0x10];
    int rate;                   /* 0x10 */
    int ofs;                    /* 0x14 frame offset, also the channel */
    int unk18;
    int drop;                   /* 0x1C */
    char unk20[0x10];
    int f30;                    /* 0x30 */
    char unk34[0x57 - 0x34];
    signed char f57;            /* 0x57 */
} SftimInfo;

/* Drop-frame layout for one frame rate, in frames. */
typedef struct SftimDf {
    int perHour;                /* 0x00 */
    int perTenMin;              /* 0x04 */
    int firstMin;               /* 0x08 first minute of each ten (no drop) */
    int perMin;                 /* 0x0C other minutes */
    int firstSec;               /* 0x10 first second of a dropped minute */
    int perSec;                 /* 0x14 */
    int minPerTen;              /* 0x18 */
    int dropped;                /* 0x1C frames skipped at a minute start */
} SftimDf;

extern int D_00459920[];        /* frame rate * 1000 by rate index */
extern SftimDf D_004596F0;      /* 29.97 */
extern SftimDf D_00459710;      /* 59.94 */
extern long long func_0036C990(long long a, long long b, long long c);    /* a * b / c */

extern void SFTIM_Tc2Time(SftimTc *tc, int *time, int *unit);
extern int GetArrayElemA0C_35A1C8(void *hn, int idx);      /* SFSET_GetCond */
extern int func_0034DD70(SftimHn *hn, int code);
extern int Obj34D8_GetTri78_Times100(void *hn);
extern void func_0035A000(void *hn, int idx, int val);      /* SFSET_SetCond */

#endif
