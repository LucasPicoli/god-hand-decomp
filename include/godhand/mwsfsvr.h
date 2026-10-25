/* include/godhand/mwsfsvr.h - the Sofdec server work area (CRI libmwsfd, src/cod/00344*..0034a*).
 *
 * GetD003EC7E0_3452B0 returns the one 0x1890-byte work area. Field names are
 * ours, taken from the matched accessors; offsets are exact. A field nobody
 * has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_MWSFSVR_H
#define GODHAND_MWSFSVR_H

#define MWSFSVR_WORK_SIZE   0x1890
#define MWSFSVR_DEF_FPS     59.94f

/* Frame timing as the caller hands it over; the default is NTSC video. */
typedef struct MwsfsvrTiming {
    float fps;                          /* 0x00 frames per second */
    int num;                            /* 0x04 */
    int den;                            /* 0x08 */
    int drop;                           /* 0x0C */
} MwsfsvrTiming;

typedef struct MwsfsvrWork {
    char unk00[4];
    MwsfsvrTiming time;                 /* 0x04 */
    char unk14[0x14];
    void *alloc;                        /* 0x28 */
    void *freep;                        /* 0x2C */
    void *obj;                          /* 0x30 */
    char unk34[4];
    int active;                         /* 0x38 */
    int unk3C;                          /* 0x3C */
    char unk40[0x1C];
    int unk5C;                          /* 0x5C */
    char unk60[0x182C];
    int flg;                            /* 0x188C */
} MwsfsvrWork;                          /* 0x1890 */

extern MwsfsvrWork *GetD003EC7E0_3452B0(void);
extern void MWSFSVR_SetMwsfdSvrFlg(int flg);
extern void func_003A52F0(void *dst, int val, int n);

#endif
