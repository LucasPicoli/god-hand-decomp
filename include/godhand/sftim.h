/* include/godhand/sftim.h - Sofdec timing and picture-decode work areas.
 *
 * SftimHn is the Sofdec handle seen from the timing (0xD30) and picture
 * decode (0x1FC0) code. Offsets are exact; unnamed fields stay as unkNNN
 * padding. Field names are ours, taken from the functions that use them.
 */
#ifndef GODHAND_SFTIM_H
#define GODHAND_SFTIM_H

#include "godhand/criSj.h"
#include "godhand/Sfd.h"
#include "godhand/MpvPicAtr.h"

struct MpvHandle;

typedef struct SfdErr {
    int nDec;                   /* 0x00 pictures decoded (SFPLY_AddDecPic) */
    int nSkip;                  /* 0x04 pictures skipped (SFPLY_AddSkipPic) */
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    char unk10[0x2C - 0x10];
    int err;                    /* 0x2C */
} SfdErr;
typedef char SfdErr_size_check[(sizeof(SfdErr) == 0x30) ? 1 : -1];

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

/* The movie info: picture size and rates from the first picture header. */
typedef struct SfdMvInf {
    int width;                  /* 0x00 */
    int height;                 /* 0x04 */
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    int bitRate;                /* 0x10 */
    int rate;                   /* 0x14 */
    char unk18[0x20 - 0x18];
    int vbv;                    /* 0x20 */
} SfdMvInf;
typedef char SfdMvInf_size_check[(sizeof(SfdMvInf) == 0x24) ? 1 : -1];

/* The stream header info (SFHDS_ProcessHdr): the raw header sfhds_SetHdrRaw copies, and what is read from it. */
typedef struct SfdHdInf {
    int valid;                  /* 0x00 nonzero once the header is read */
    char unk04[0x7C - 0x04];
    int f7C;                    /* 0x7C */
    char unk80[0x90 - 0x80];
    int len;                    /* 0x90 bytes in raw */
    char raw[0x800];            /* 0x94 */
} SfdHdInf;
typedef char SfdHdInf_size_check[(sizeof(SfdHdInf) == 0x894) ? 1 : -1];

typedef struct SftimHn {
    char unk000[0x38];
    int mode;                   /* 0x38 */
    char unk03C[0x78 - 0x3C];
    SfdHdInf hdr;              /* 0x78 */
    SfdMvInf mv;                /* 0x90C */
    char unk930[0x950 - 0x930];
    struct SfdErr errInf;       /* 0x950 */
    char unk980[0x9A8 - 0x980];
    long rtotSj;                /* 0x9A8 bytes read from the stream joint */
    char unk9B0[0x9F8 - 0x9B0];
    struct SfdCnt cnt;          /* 0x9F8 */
    char unkA0C[0xD30 - 0xA0C];
    SftimWork tim;              /* 0xD30 */
    char unk11E4[0x1310 - 0x11E4];
    SfdTrack track[8];          /* 0x1310 one per track (ring buffer channel) */
    char unk16B0[0x1FC0 - 0x16B0];
    struct SfdWork *work;       /* 0x1FC0 */
    char unk1FC4[4];
    int vidCh;                  /* 0x1FC8 track of the video stream */
    char unk1FCC[0x36B0 - 0x1FCC];
    int f36B0;                  /* 0x36B0 */
    char unk36B4[0x36C0 - 0x36B4];
    struct SfdPrf prf[4];       /* 0x36C0 decode time by picture type */
} SftimHn;
typedef char SftimHn_size_check[(sizeof(SftimHn) == 0x3740) ? 1 : -1];

/* User data buffer: pointer and length. */
typedef struct SfdUsrBuf {
    unsigned char *buf;         /* 0x00 */
    int len;                    /* 0x04 */
} SfdUsrBuf;

/* The picture user data area: buffer size, then buffer and stored length. */
typedef struct SfdUsrRec {
    char unk00[0x8];
    int size;                   /* 0x08 */
    SfdUsrBuf buf;              /* 0x0C */
} SfdUsrRec;
typedef char SfdUsrRec_size_check[(sizeof(SfdUsrRec) == 0x14) ? 1 : -1];

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
    MpvPicAtr pic;              /* 0x5C */
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
    MpvPicAtr *pic;             /* 0x24 */
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

/* The video input ring buffer (viBuf*), SfdWork.vi. */
typedef struct ViBuf {
    /* 0x00 */ unsigned int base;
    /* 0x04 */ unsigned int tagp;
    /* 0x08 */ int nblk;
    /* 0x0C */ int rd;
    /* 0x10 */ int rdofs;
    /* 0x14 */ int wr;
    /* 0x18 */ int size;
    /* 0x1C */ unsigned int f1C;
    /* 0x20 */ unsigned int f20;
    /* 0x24 */ unsigned int f24;
    /* 0x28 */ unsigned int f28;
    /* 0x2C */ unsigned int f2C;
    /* 0x30 */ unsigned int f30;
    /* 0x34 */ unsigned int f34;
    /* 0x38 */ unsigned int f38;
    /* 0x3C */ unsigned int f3C;
    /* 0x40 */ int sema;
    /* 0x44 */ int active;
    /* 0x48 */ long total;
    /* 0x50 */ void *ent;
    /* 0x54 */ int nent;
    /* 0x58 */ int f58;
    /* 0x5C */ int f5C;
} ViBuf;
typedef char ViBuf_size_check[(sizeof(ViBuf) == 0x60) ? 1 : -1];

typedef struct SfdWork {
    struct MpvHandle *dec;      /* 0x000 */
    SfdFrmCfg cfg;              /* 0x004 */
    char unk028[0x30 - 0x28];
    char *frmBuf[16];           /* 0x030 each frame's buffer */
    char unk070[0x78 - 0x70];
    unsigned int f78;           /* 0x078 picture types to time */
    int f7C;                    /* 0x07C */
    char unk080[0x84 - 0x80];
    int f84;                    /* 0x084 */
    int f88;                    /* 0x088 */
    MpvPicAtr pic;              /* 0x08C */
    int f10C;                   /* 0x10C */
    int f110;                   /* 0x110 set when f10C changed */
    int f114;                   /* 0x114 */
    char unk118[0x138 - 0x118];
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
    SfdUsrRec usrRec;           /* 0x1080 */
    SfdUsrBuf usr;              /* 0x1094 */
    char unk109C[0x1120 - 0x109C];
    long time;                  /* 0x1120 */
    char unk1128[0x1198 - 0x1128];
    ViBuf vi;                   /* 0x1198 the video input ring buffer */
    char unk11F8[0x1F74 - 0x11F8];
    SfdChIds ch;                /* 0x1F74 */
} SfdWork;
typedef char SfdWork_size_check[(sizeof(SfdWork) == 0x1F98) ? 1 : -1];   /* ch ends at 0x1F94; the long fields round it to 8 */

/* Frame-pool lock guard enter/leave (16-byte guard on the caller stack). */
extern void Thunk_func_0033B658(char *guard);
extern void Thunk_func_0033B670(char *guard);
extern SfdFrm *SFMPVF_AllocFrm(SftimHn *hn);

extern int D_00459730[];        /* picture/extension type by 3-bit code */
extern int D_003EE2F0;          /* delimiter search error count */

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
extern long long UTY_MulDivRound64(long long a, long long b, long long c);    /* a * b / c */

extern void SFTIM_Tc2Time(SftimTc *tc, int *time, int *unit);
extern int GetArrayElemA0C_35A1C8(void *hn, int idx);      /* SFSET_GetCond */
extern int func_0034DD70(SftimHn *hn, int code);
extern int Obj34D8_GetTri78_Times100(void *hn);
extern void SFSET_SetCond(void *hn, int idx, int val);      /* SFSET_SetCond */

/* Picture header decode. */
extern int sfmpv_ChkMpvErr(SftimHn *hn, int st, int n, int code);
extern void sfmpv_ReadPtsQue(SftimHn *hn, MpvPicAtr *pic, Sint8 *psc, long *pts, long *time, int update);
extern void sfmpv_CalcRepeatField(SftimHn *hn, MpvPicAtr *pic, int update);
extern void sfmpv_ReformTc(SftimHn *hn, MpvPicAtr *info, long time, int update);
extern int sfmpv_DetectTcErr(SftimHn *hn, MpvPicAtr *info);
extern void Sftim_setTimecode(SftimHn *hn, MpvPicAtr *info, long time, int update);
extern void sfmpv_Pts2Tc(long time, int rate, int drop, int ofs, SftimTc *tc);
extern void sfmpv_SetHeadTtu(SftimHn *hn, MpvPicAtr *pic);
extern void SftimHn_recordLastFrame(SftimHn *hn, MpvPicAtr *pic);
extern int sfmpv_FirstPicAtr(SftimHn *hn, struct MpvHandle *mpv, MpvPicAtr *pic, SjChunk *ck);
extern void sfmpv_SetMvInf(SfdMvInf *mv, int bitRate, MpvPicAtr *pic, int vbv);
extern int sfmpv_ChkBufSiz(SftimHn *hn, SfdMvInf *mv);
extern void sfmpv_AddRtotSj(SftimHn *hn, int n);
extern void SFBUF_AddRtotSj(SftimHn *hn, int ch, int n);
extern void sfmpv_SetSkipTtu(SftimHn *hn);
/* The stream header. */
extern int sfhds_GetHd(void *hn);       /* the address of the header copy in the MPS work, or 0 */
extern void func_0034D318(SfdHdInf *dst, SfdHdInf *src);
extern void func_0034D2D8(SftimHn *hn);
extern int sfhds_SetHdrRaw(SftimHn *hn, char *raw, int len);
extern void SFHDS_ReprocessHdr(SftimHn *hn);

/* The picture count callbacks (conditions 0x24 and 0x25). */
typedef void (*SfdPicCntFn)(SftimHn *hn, int picType, SfdErr *inf);
extern void SFPLY_AddDecPic(SftimHn *hn, int n, int picType);
extern void SFPLY_AddSkipPic(SftimHn *hn, int n, int picType);

#endif
