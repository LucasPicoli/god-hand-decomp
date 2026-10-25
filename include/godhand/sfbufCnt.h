/* include/godhand/sfbufCnt.h - the supply-count view of a Sofdec track buffer (CRI libsfd, src/cod/0034c*.c).
 *
 * A track record is 0x74 bytes at handle + 0x1310; its buffer record starts
 * 0x10 into it. The buffer keeps two running byte counts (one per supply
 * mode) that are only advanced while they are not negative. Field names are
 * ours, taken from the matched routines; offsets are exact. A field nobody
 * has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SFBUFCNT_H
#define GODHAND_SFBUFCNT_H

#define SFBUF_TRACK_OFS    0x1310
#define SFBUF_TRACK_SIZE   0x74
#define SFBUF_BUF_OFS      0x10
#define SFBUF_ERR_SUPPLY   0xFF00040B

typedef struct SfbufBuf {
    int unk00;
    void *sj;                           /* 0x04 supply object (a vtable object) */
    char unk08[0x18];
    int cntA;                           /* 0x20 bytes supplied in mode 0 */
    int cntB;                           /* 0x24 bytes supplied in mode 1 */
    char unk28[0x3C];
} SfbufBuf;                             /* 0x64 */

typedef struct SfbufTrack {
    char unk00[4];
    int ready;                          /* 0x04 */
    char unk08[8];
    SfbufBuf buf;                       /* 0x10 */
} SfbufTrack;                           /* 0x74 */

typedef struct SfbufHn {
    char unk0000[0x44];
    int dirty;                          /* 0x44 */
    char unk48[SFBUF_TRACK_OFS - 0x48];
    SfbufTrack track[1];                /* 0x1310 indexed by track number */
} SfbufHn;

extern int Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680(void *obj, int mode, int len);
extern int func_0034DD70(void *hn, int code);
extern void sfbuf_ResetConti(void *buf);

#endif
