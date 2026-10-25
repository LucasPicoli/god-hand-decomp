/* include/godhand/SfdVidSetup.h - the video setup of a Sofdec work area (cygnus code at 0x3563B8).
 *
 * The setup sizes the picture buffers from the configured picture size,
 * creates the MPEG decoder object (at 0x1150) and its four callbacks, and
 * creates the video-input ring buffer (at 0x1198). The control block at
 * 0x1128 is then cleared and marked ready.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDVIDSETUP_H
#define GODHAND_SFDVIDSETUP_H

#include "godhand/sftim.h"

#define SFDVID_ALIGN         0x40       /* buffer alignment, bytes */
#define SFDVID_EXTRA         0x2800     /* decoder bytes beyond the 4:2:0 picture */
#define SFDVID_RING_PAD      0x8003F    /* ring buffer bytes plus alignment slack */
#define SFDVID_RING_TAG_PAD  0x104F     /* tag area bytes plus alignment slack */
#define SFDVID_VIBUF_BLK     0x100      /* ring buffer block size */
#define SFDVID_VIBUF_TAGBLK  0x200      /* tag block size */
#define SFDVID_CB_NUM        4

typedef struct SfdVibufCtl {
    int state;                          /* 0x00 1 once the setup is done, 0 when video is off */
    int unk04, unk08, unk0C;            /* 0x04 */
    unsigned char b10, b11, b12;        /* 0x10 */
    char pad13;
    int unk14, unk18, unk1C;            /* 0x14 */
    int unk20;                          /* 0x20 */
    char pad24[4];
} SfdVibufCtl;                          /* 0x28 */

/* The video block at 0x1128: the control words, the MPEG decoder object and the ring buffer. */
typedef struct SfdVidBlock {
    SfdVibufCtl ctl;                    /* 0x00 */
    char mpeg[0x70 - 0x28];             /* 0x28 the MPEG decoder object */
    char vibuf[0xD0 - 0x70];            /* 0x70 the ViBuf */
} SfdVidBlock;                          /* 0xD0 */

typedef struct SfdVidSetupTail {
    int id;                             /* 0x00 -1 after the setup */
    int cnt;                            /* 0x04 */
} SfdVidSetupTail;

typedef struct SfdVidSetup {
    void *dec;                          /* 0x000 */
    SfdFrmCfg cfg;                      /* 0x004 */
    int bufLo;                          /* 0x028 first buffer, aligned */
    int bufHi;                          /* 0x02C end of the first buffer, aligned */
    char unk030[0x1128 - 0x30];
    SfdVidBlock blk;                    /* 0x1128 */
    SfdVidSetupTail tail;               /* 0x11F8 */
} SfdVidSetup;

typedef struct SfdVidSetupHn {
    char unk0000[0x1FC0];
    SfdVidSetup *work;                  /* 0x1FC0 */
} SfdVidSetupHn;

typedef char SfdVidSetup_chk_ctl[((int)&((SfdVidSetup *)0)->blk == 0x1128) ? 1 : -1];
typedef char SfdVidSetup_chk_tail[((int)&((SfdVidSetup *)0)->tail == 0x11F8) ? 1 : -1];

#endif
