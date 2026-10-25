/* include/godhand/sfdVidCtl.h - the video-side control block of a Sofdec work area (CRI libsfd).
 *
 * A handle holds a pointer to its work area at +0x1FC0. Inside that area, the
 * control block sits at +0x1128 and the video-input ring buffer (ViBuf) at
 * +0x1198. Field names are ours, from the methods that touch them; offsets are
 * exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SFDVIDCTL_H
#define GODHAND_SFDVIDCTL_H

#define SFD_WORK_PTR_OFS   0x1FC0
#define SFD_VIDCTL_OFS     0x1128
#define SFD_VIBUF_OFS      0x1198

typedef struct ViBuf {
    unsigned int base;                  /* 0x00 */
    unsigned int tagp;                  /* 0x04 */
    int nblk;                           /* 0x08 */
    int rd;                             /* 0x0C */
    int rdofs;                          /* 0x10 */
    int wr;                             /* 0x14 */
    int size;                           /* 0x18 */
    unsigned char pad1C[0x40 - 0x1C];
    int sema;                           /* 0x40 */
    int active;                         /* 0x44 */
} ViBuf;

typedef struct SfdVidCtl {
    char unk00[0x14];
    int pending;                        /* 0x14 */
    int busy;                           /* 0x18 1 = a put is in flight */
    int unk1C;                          /* 0x1C */
    int unk20;                          /* 0x20 */
    char unk24[4];
} SfdVidCtl;                            /* 0x28 */

typedef struct SfdVidWork {
    char unk0000[SFD_VIDCTL_OFS];
    SfdVidCtl ctl;                      /* 0x1128 */
    char sub[SFD_VIBUF_OFS - SFD_VIDCTL_OFS - sizeof(SfdVidCtl)]; /* 0x1150 object released by the busy path */
    ViBuf vibuf;                        /* 0x1198 */
} SfdVidWork;

typedef struct SfdVidHn {
    char unk0000[SFD_WORK_PTR_OFS];
    SfdVidWork *work;                   /* 0x1FC0 */
} SfdVidHn;

#endif
