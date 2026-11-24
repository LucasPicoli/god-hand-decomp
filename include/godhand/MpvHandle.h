/* include/godhand/MpvHandle.h - the MPEG video decoder handle of CRI libmpv (MPV) and the calls that take it.
 *
 * MPV handles are 0x440-byte records in a pool (mpvlib_InitObjTbl). The
 * header decoder (mpvhdec_*) parses the stream into the handle. With an
 * MPEG-2 stream the M2V side (MPVM2V_*, mpvm2v_*) programs the M2V decoder
 * from it through the hooks at 0x36CDC0.. and copies the picture
 * attributes back.
 *
 * Field names are ours; offsets are exact. A field nobody has named yet
 * stays as unkNNN padding.
 */
#ifndef GODHAND_MPVHANDLE_H
#define GODHAND_MPVHANDLE_H

#include "godhand/criSjIf.h"
#include "godhand/MpvPicAtr.h"

/* MpvHandle.stat */
#define MPV_HN_FREE         1
#define MPV_HN_USED         2

/* MpvHandle.codec, 0 until mpvhdec_GetCodec has seen a sequence header. */
#define MPV_CODEC_M1V       1
#define MPV_CODEC_M2V       2

/* MPV_CheckDelim results: the start code at the pointer. */
#define MPV_DLM_SLICE       0x03    /* slice of row 1; a slice of any row tests (r & MPV_DLM_SLICE) */
#define MPV_DLM_SLICE_NEXT  0x01    /* slice of a later row */
#define MPV_DLM_PSC         0x04    /* picture */
#define MPV_DLM_GSC         0x08    /* group of pictures */
#define MPV_DLM_ESC         0x10    /* extension */
#define MPV_DLM_UDSC        0x20    /* user data */
#define MPV_DLM_SHC         0x40    /* sequence header */
#define MPV_DLM_SEC         0x80    /* sequence end */

/* One stream-joint output channel of the user data writers (mpvhdec_AnalyUd, m2vhdec_AnalyUd). */
typedef struct SfdSjCh {
    SjObj *sj;                          /* 0x00 */
    void (*cb)(int arg, int ch);        /* 0x04 */
    int arg;                            /* 0x08 */
} SfdSjCh;
typedef char SfdSjCh_size_check[(sizeof(SfdSjCh) == 0xC) ? 1 : -1];

/* The picture user data buffer (MPV_SetPicUsrBuf). */
typedef struct MpvPicUsr {
    char *buf;                  /* 0x00 */
    int size;                   /* 0x04 */
    int len;                    /* 0x08 bytes stored */
} MpvPicUsr;
typedef char MpvPicUsr_size_check[(sizeof(MpvPicUsr) == 0xC) ? 1 : -1];

typedef int (*MpvErrFn)(void *obj, int code);

/* The error block: one in each handle, and D_003F1AA0 for calls made
 * without a handle. func_00369E80 clears its five words. */
typedef struct MpvErr {
    MpvErrFn fn;                /* 0x00 */
    void *obj;                  /* 0x04 */
    int code;                   /* 0x08 last error code */
    int unk0C;                  /* 0x0C */
    int unk10;                  /* 0x10 */
} MpvErr;
typedef char MpvErr_size_check[(sizeof(MpvErr) == 0x14) ? 1 : -1];

typedef struct MpvHandle {
    char unk000[0x188];
    int stat;                   /* 0x188 MPV_HN_* */
    int unk18C;                 /* 0x18C */
    int cond[16];               /* 0x190 MPV_SetCond values */
    MpvPicAtr picAtr;           /* 0x1D0 */
    MpvErr err;                 /* 0x250 */
    char unk264[0x2A8 - 0x264];
    int bitRate;                /* 0x2A8 */
    int blocks;                 /* 0x2AC */
    char unk2B0[4];
    int d;                      /* 0x2B4 */
    int e;                      /* 0x2B8 */
    int c;                      /* 0x2BC */
    char unk2C0[0x35C - 0x2C0];
    int codec;                  /* 0x35C MPV_CODEC_* */
    int unk360;                 /* 0x360 */
    int unk364;                 /* 0x364 */
    int unk368;                 /* 0x368 */
    char unk36C[0x384 - 0x36C];
    int unk384;                 /* 0x384 */
    int unk388;                 /* 0x388 */
    SjChunk ck;                 /* 0x38C chunk being decoded */
    char unk394[4];
    int unk398;                 /* 0x398 */
    char unk39C[0x3A8 - 0x39C];
    int unk3A8;                 /* 0x3A8 */
    char unk3AC[0x3B4 - 0x3AC];
    int dev;                    /* 0x3B4 M2V handle */
    int cur;                    /* 0x3B8 user data channel */
    SfdSjCh ch[4];              /* 0x3BC user data channels */
    MpvPicUsr usr;              /* 0x3EC */
    char unk3F8[0x408 - 0x3F8];
    int stopReq;                /* 0x408 */
    char unk40C[0x440 - 0x40C];
} MpvHandle;
typedef char MpvHandle_size_check[(sizeof(MpvHandle) == 0x440) ? 1 : -1];

extern MpvErr D_003F1AA0;
extern MpvHandle *D_00766D44;

/* Handle checks and errors. */
extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(MpvHandle *hn);    /* CRI CheckHn */
extern int func_00369F20(MpvHandle *hn, int code);                         /* CRI ERR_SetCode */
extern int func_00369F70(MpvErr *err, int code);
extern void func_00369E80(MpvErr *err);
extern void Obj0000_Get_Field_3B4_Via_func_0036CD98(MpvHandle *hn, int id, int val);
extern void Obj0000_Set_Field_3BC_Triple(MpvHandle *hn, int no, SjObj *sj, void (*cb)(int arg, int ch), int arg);

/* Decoding conditions (MpvHandle.cond, or the defaults when hn is 0). */
extern int MPV_GetCond(MpvHandle *hn, int id, int *val);

/* Picture attributes and user data. */
extern int MPV_DecodePicAtrSj(MpvHandle *hn, SjObj *sj);
extern int MPV_GetPicAtr(MpvHandle *hn, MpvPicAtr *atr);
extern void MPV_SetPicUsrBuf(MpvHandle *hn, char *buf, int size);
extern void MPV_GetPicUsr(MpvHandle *hn, char **buf, int *len);
extern int MPV_GetBitRate(MpvHandle *hn, unsigned int *rate);
extern int MPV_GetVbvBufSiz(MpvHandle *hn, int *p1, int *p2, int *p3);
extern int func_00369FB8(MpvHandle *hn, SjObj *sj);

/* Start codes. */
extern Sint8 *MPV_SearchDelim(Sint8 *buf, int len, int mask);
extern int MPV_CheckDelim(unsigned char *b);
extern unsigned int MPV_GoNextDelimSj(SjObj *sj);

/* The header decoder. */
extern int mpvhdec_GetCodec(MpvHandle *hn, SjChunk *ck);
extern int mpvhdec_GetCurDelim(SjObj *sj);
extern int mpvhdec_RecoverSj(MpvHandle *hn, int mask, SjObj *sj);
extern int mpvhdec_DecShcSj(MpvHandle *hn, SjObj *sj);
extern int mpvhdec_DecGscSj(MpvHandle *hn, SjObj *sj);
extern int mpvhdec_DecPscSj(MpvHandle *hn, SjObj *sj);
extern int mpvhdec_DecEscSj(MpvHandle *hn, SjObj *sj, int prev);
extern int mpvhdec_DecUdscSj(MpvHandle *hn, SjObj *sj, int prev);
extern int mpvhdec_AnalyUd(MpvHandle *hn, char *data, int n);
extern int mpvhdec_DecSeqUdsc(MpvHandle *hn, char *buf, int size);

/* The M2V side. */
extern int MPVM2V_DecodePicAtr(MpvHandle *hn, SjObj *sj);
extern int MPVM2V_RequestStop(MpvHandle *hn);
extern void mpvm2v_CopyPicAtr(MpvHandle *hn);

/* The M2V decoder interface entries the hooks call; M2V_Setup (0x36CF30) installs them. */
typedef void (*MpvM2vSetCondFn)(int dev, int id, int val);
typedef void (*MpvM2vSetUsrSjFn)(int dev, int no, SjObj *sj, void (*cb)(int arg, int ch), int arg);
typedef void (*MpvM2vSetPicUsrBufFn)(int dev, char *buf, int size);
typedef void (*MpvM2vGetPicUsrFn)(int dev, char **buf, int *len);
typedef int (*MpvM2vDecodePicAtrFn)(int dev, SjObj *sj);
typedef void (*MpvM2vGetPicAtrFn)(int dev, MpvPicAtr *atr);
typedef void (*MpvM2vGetBitRateFn)(int dev, int *bitRate);
typedef void (*MpvM2vGetVbvBufSizFn)(int dev, int *b, int *c, int *x);
typedef void (*MpvM2vGetLinkFlgFn)(int dev, int *d, int *e);

extern MpvM2vSetCondFn D_003F200C;
extern MpvM2vSetUsrSjFn D_003F2024;
extern MpvM2vSetPicUsrBufFn D_003F2028;
extern MpvM2vGetPicUsrFn D_003F202C;
extern MpvM2vDecodePicAtrFn D_003F2030;
extern MpvM2vGetPicAtrFn D_003F2034;
extern MpvM2vGetBitRateFn D_003F2038;
extern MpvM2vGetVbvBufSizFn D_003F203C;
extern MpvM2vGetLinkFlgFn D_003F2040;

/* The M2V decoder hooks, each a no-op until its pointer is set; dev is MpvHandle.dev. */
extern int Obj0000_Get_D_003F1FF0_36CCA8(void);
extern void func_0036CD98(int dev, int id, int val);
extern void func_0036CDC0(int dev, int no, SjObj *sj, void (*cb)(int arg, int ch), int arg);
extern void func_0036CDE8(int dev, char *buf, int size);
extern void func_0036CE10(int dev, char **buf, int *len);
extern int func_0036CE38(int dev, SjObj *sj);
extern void func_0036CE68(int dev, MpvPicAtr *atr);
extern void func_0036CE90(int dev, int *bitRate);
extern void func_0036CEB8(int dev, int *b, int *c, int *x);
extern void func_0036CEE0(int dev, int *d, int *e);

#endif /* GODHAND_MPVHANDLE_H */
