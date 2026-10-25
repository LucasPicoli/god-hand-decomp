/* include/godhand/TexChan.h - GS texture channels (sn code at 0x3090F8).
 *
 * The texture loader keeps a table of 0xB0-byte channel records at
 * D_00747BA0. One channel holds one texture of a bank: where it sits in GS
 * memory, its size and its TEX0 and MIPTBP words. The same table is also
 * seen as D_00747BC0, shifted by 0x20, where the MIPTBP words start.
 * A bank is a run of texture headers, each starting with the offset of the
 * next one.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_TEXCHAN_H
#define GODHAND_TEXCHAN_H

#define TEXCHAN_SIZE      0xB0
#define TEXCHAN_ADDR_BIAS 0x1C00     /* GS addresses below this are page-based */
#define TEXFMT_CLUT4      4          /* header format: 16-colour palette */
#define TEXFMT_CLUT8      5          /* header format: 256-colour palette */

/* One texture header of a bank. */
typedef struct TexHdr {
    int next;                           /* 0x00 byte offset of the next header */
    char unk04[0xA];
    unsigned short clutNum;             /* 0x0E palette entries, 0 for none */
    char unk10[3];
    unsigned char fmt;                  /* 0x13 TEXFMT_* */
    unsigned short w;                   /* 0x14 */
    unsigned short h;                   /* 0x16 */
    long tex0;                          /* 0x18 */
    long mip1;                          /* 0x20 */
    char unk28[0x18];
} TexHdr;

/* A bank header: the number of textures and a mode byte at 0x5, then the
 * texture headers at 0x10 (mode 0) or 0x80 (mode 1). */
typedef struct TexBank {
    char unk00[5];
    unsigned char mode;                 /* 0x05 */
    unsigned short num;                 /* 0x06 */
} TexBank;

typedef struct TexChan {
    unsigned char used;                 /* 0x00 */
    unsigned char ready;                /* 0x01 */
    unsigned char clutBlocks;           /* 0x02 palette size in 16-entry or 256-entry blocks */
    unsigned char tbp;                  /* 0x03 low byte of the texture base */
    unsigned short w;                   /* 0x04 */
    unsigned short h;                   /* 0x06 */
    TexHdr *hdr;                        /* 0x08 */
    char unk0C[4];
    unsigned short nch;                 /* 0x10 */
    unsigned short len;                 /* 0x12 GS words the texture takes */
    char unk14[4];
    long tex0;                          /* 0x18 */
    char unk20[TEXCHAN_SIZE - 0x20];
} TexChan;

/* The same table, seen from the MIPTBP words at 0x20 of each channel. */
typedef struct TexChanMip {
    long mip1;                          /* 0x00 */
    char unk08[TEXCHAN_SIZE - 8];
} TexChanMip;

extern TexChan D_00747BA0[];
extern TexChanMip D_00747BC0[];

#endif
