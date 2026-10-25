/* include/godhand/MemFile.h - the memory-file reader handle (CRI libadxe, src/cod/00336*.c).
 *
 * One handle reads a file mapped in memory sector by sector. Field names are
 * ours, taken from the matched readers; offsets are exact. A field nobody has
 * named yet stays as unkNNN padding.
 */
#ifndef GODHAND_MEMFILE_H
#define GODHAND_MEMFILE_H

/* Request codes of the control entry point. */
#define MEMFILE_CTL_TELL      0xC9    /* bytes read so far */
#define MEMFILE_CTL_SIZE_A    0xCB    /* file length */
#define MEMFILE_CTL_SIZE_B    0xCD    /* file length, second spelling */
#define MEMFILE_CTL_OPEN      0x12B   /* nothing to report */
#define MEMFILE_CTL_QUERY     0x191   /* always 1 */

typedef struct MemFileReader {
    char unk00;
    signed char stat;                   /* 0x01 1 = idle, 2 = busy */
    char unk02[2];
    int sctSize;                        /* 0x04 */
    char unk08[4];
    int nsct;                           /* 0x0C file length in sectors */
    int pos;                            /* 0x10 current sector */
    int rdBytes;                        /* 0x14 */
    int rdSct;                          /* 0x18 */
    char map[0x14];                     /* 0x1C */
    int off;                            /* 0x30 */
    int size;                           /* 0x34 */
} MemFileReader;                        /* 0x38 */

extern int func_00336510(MemFileReader *h);
extern int func_00336AC0(MemFileReader *h);

#endif
