/* include/godhand/StageBuf.h - a 0x94-byte staging record over a caller-supplied buffer (src/cod/0035f*).
 *
 * The init routine aligns the buffer start up to 32 bytes and carves three
 * 0x400-byte windows behind the aligned start. Field names are ours, taken
 * from the init routine; offsets are exact. A field nobody has named yet
 * stays as unkNNN padding.
 */
#ifndef GODHAND_STAGEBUF_H
#define GODHAND_STAGEBUF_H

#define STAGEBUF_SIZE       0x94
#define STAGEBUF_ALIGN      0x20
#define STAGEBUF_WIN_LEN    0x400
#define STAGEBUF_WIN_NUM    3

typedef struct StageBuf {
    int active;                         /* 0x00 */
    int unk04;                          /* 0x04 */
    int unk08;                          /* 0x08 */
    int unk0C;                          /* 0x0C */
    char unk10[0x18];
    int one28;                          /* 0x28 */
    int unk2C;                          /* 0x2C */
    char unk30[4];
    int unk34;                          /* 0x34 */
    int base;                           /* 0x38 buffer start, 32-byte aligned */
    int win[STAGEBUF_WIN_NUM];          /* 0x3C 0x40 0x44 windows, base + 0x400 * n */
    char unk48[8];
    int srcBuf;                         /* 0x50 raw buffer as given */
    int srcSize;                        /* 0x54 */
    int id;                             /* 0x58 -1 until a stream is attached */
    char unk5C[8];
    int unk64;                          /* 0x64 */
    char unk68[0x2C];
} StageBuf;                             /* 0x94 */

extern void func_003A52F0(void *dst, int val, int n);

#endif
