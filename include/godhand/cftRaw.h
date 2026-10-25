/* include/godhand/cftRaw.h - CRI Sofdec raw8-to-ARGB conversion records (cygnus code at 0x363528).
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CFTRAW_H
#define GODHAND_CFTRAW_H

#define CFT_MB_SIZE         16      /* macroblock edge in pixels */
#define CFT_MB_DST_STEP     0x180   /* ARGB bytes one macroblock row of the output advances */
#define CFT_MB_SRC_STEP     0x400   /* source bytes one macroblock consumes */
#define CFT_ROW_BYTES_UNIT  24      /* output bytes per stride unit of a macroblock row */

/* The output surface: its base pointer and row stride in macroblock rows. */
typedef struct CftDst {
    char unk00[4];
    char *base;                 /* 0x04 */
    char unk08[4];
    int stride;                 /* 0x0C */
} CftDst;

/* The source frame: pixel pointer and its size in pixels. */
typedef struct CftSrc {
    char unk00[4];
    char *pix;                  /* 0x04 */
    int height;                 /* 0x08 */
    int width;                  /* 0x0C */
} CftSrc;

extern void cftraw_CnvMbRAW8toARGB(char *dst, char *src, int ctx);

#endif
