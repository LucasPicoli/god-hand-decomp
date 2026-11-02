#ifndef GODHAND_GSLOADIMAGE_H
#define GODHAND_GSLOADIMAGE_H

/* A DMA chain that uploads one image to GS memory: BITBLTBUF/TRXPOS/TRXREG/TRXDIR through A+D,
 * an IMAGE GIF tag, a reference tag to the pixels, then TEXFLUSH. */
typedef struct GsLoadImagePacket {
    unsigned long dmaTag;           /* 0x00 cnt, 6 qwords */
    int vifFlush;                   /* 0x08 */
    int vifDirect;                  /* 0x0C DIRECT 6 */
    unsigned long gifTag[2];        /* 0x10 A+D, 4 registers */
    unsigned long bitbltbuf;        /* 0x20 */
    unsigned long bitbltbufAddr;    /* 0x28 */
    unsigned long trxpos;           /* 0x30 */
    unsigned long trxposAddr;       /* 0x38 */
    unsigned long trxreg;           /* 0x40 */
    unsigned long trxregAddr;       /* 0x48 */
    unsigned long trxdir;           /* 0x50 */
    unsigned long trxdirAddr;       /* 0x58 */
    unsigned long imageTag[2];      /* 0x60 IMAGE mode GIF tag */
    unsigned long refTag;           /* 0x70 ref to the pixel data */
    int vifNop;                     /* 0x78 */
    int vifDirectImage;             /* 0x7C DIRECT qwc */
    unsigned long endTag;           /* 0x80 cnt, 2 qwords */
    int endVifFlush;                /* 0x88 */
    int endVifDirect;               /* 0x8C DIRECT 2 */
    unsigned long endGifTag[2];     /* 0x90 A+D, 1 register */
    unsigned long texflush;         /* 0xA0 */
    unsigned long texflushAddr;     /* 0xA8 */
} GsLoadImagePacket;

extern void func_0015E510(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data);
extern void func_0015E708(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data);

#endif
