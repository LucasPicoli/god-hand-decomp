/* include/godhand/MpvDec.h - the MPEG video decoder queue slot of a Sofdec handle (CRI libsfd, src/cod/00352f40.c).
 *
 * func_003553C8 hands out the slot. The reader stores the picture attributes
 * block and a 0x200-byte work area into it, then sets busy; the consumer copies
 * the block back into the handle. Field names are ours, taken from the matched
 * routines; offsets are exact. A field nobody has named yet stays as unkNNN
 * padding.
 */
#ifndef GODHAND_MPVDEC_H
#define GODHAND_MPVDEC_H

#define MPV_WORK_LEN        0x200
#define MPV_ERR_PICATR      0xFF000F1B

typedef struct MpvBlk {
    int w[11];                          /* picture attribute words */
} MpvBlk;

typedef struct MpvWork {
    char buf[MPV_WORK_LEN];
    int size;                           /* 0x200 */
} MpvWork;

typedef struct MpvDec {
    int busy;                           /* 0x00 set once the slot is filled */
    int rate;                           /* 0x04 */
    int on;                             /* 0x08 */
    MpvBlk blk;                         /* 0x0C */
    MpvWork work;                       /* 0x38 */
} MpvDec;

typedef struct MpvSub {
    char pad0[0x3C];
    MpvBlk blk;                         /* 0x3C */
} MpvSub;

typedef struct MpvHn {
    char pad0[0xD30];
    MpvSub sub;                         /* 0xD30 */
} MpvHn;

/* What MPV_DecodePicAtr takes: the work area and its used length. */
typedef struct MpvPicSrc {
    MpvWork *work;
    int size;
} MpvPicSrc;

extern MpvDec *func_003553C8(MpvHn *hn);
extern int MPV_DecodePicAtr(int pic, MpvPicSrc *src, int *out);
extern int func_0034DD70(MpvHn *hn, int code);

#endif
