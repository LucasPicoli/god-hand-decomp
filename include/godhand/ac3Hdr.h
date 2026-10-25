/* include/godhand/ac3Hdr.h - the AC-3 frame header record and its lookup tables (CRI libsfd, src/cod/003ba3d8..).
 *
 * The parser accepts a frame in either byte order (0B 77 or 77 0B), then
 * reads the sample-rate code (top two bits) and the frame-size code (low six
 * bits) of the next byte. Field names are ours, taken from the parser;
 * offsets are exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_AC3HDR_H
#define GODHAND_AC3HDR_H

#define AC3_SYNC_HI        0x0B
#define AC3_SYNC_LO        0x77
#define AC3_FSCOD_NUM      3       /* valid sample-rate codes */
#define AC3_FRMSIZ_NUM     0x26    /* valid frame-size codes */
#define AC3_FRMSIZ_STRIDE  40      /* table row length, in words */

typedef struct Ac3Hdr {
    char unk00[0x28];
    int swapped;                        /* 0x28 1 = bytes in 0B 77 order, 2 = swapped */
    int sampleRate;                     /* 0x2C */
    int bitRate;                        /* 0x30 */
    int frameBytes;                     /* 0x34 frame length in bytes */
} Ac3Hdr;

extern int D_003FC518[AC3_FSCOD_NUM];
extern int D_003FC528[AC3_FRMSIZ_NUM];
extern int D_003FC5C8[];
extern char D_00460978[];
extern char D_004609A8[];
extern char D_004609D8[];
extern void func_003B9DE0(const char *msg);

#endif
