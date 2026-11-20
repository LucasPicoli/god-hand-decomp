/* include/godhand/StageBuf.h - a 0x94-byte staging record over a caller-supplied buffer (src/cod/0035f*).
 *
 * The init routine aligns the buffer start up to 32 bytes and carves three
 * 0x400-byte windows behind the aligned start. func_0035F970 sets one up
 * as an SFX handle and stores its Z and A handles at 0x24 and 0x30. Field
 * names are ours, taken from the init routine and func_0035F970; offsets
 * are exact. A field nobody has named yet stays as unkNNN padding.
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
    char unk10[0x14];
    void *zhn;                          /* 0x24 SfxZHn handle */
    int one28;                          /* 0x28 */
    int unk2C;                          /* 0x2C */
    void *ahn;                          /* 0x30 SfxAHn handle */
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

/* Clear the record and carve three windows out of the 32-byte aligned buffer. */
void StageBuf_init(StageBuf *self, int buf, int size);

/* A free handle record, or 0. */
void *func_0035FA88(void);
/* 1 when size is enough work for a handle. Retail passes three arguments; only the size is read. */
int func_0035FB78(int size, int a1, int a2);
/* Create the Z and the A handle. */
void *func_0035FEF0(void);
void *func_0036CAB0(void);
/* Close a handle opened by func_0035F970. */
void func_0035FB88(int a0);

#endif
