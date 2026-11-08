/* include/godhand/SpritePacket.h - a 0xA0-byte DMA packet that draws one
 * screen-space sprite: a PRIM/RGBAQ/UV/XYZ2 A+D block built from a colour
 * word, two corner vectors and an optional texture-info record. The packet is
 * taken from the queue at D_00566E10 and queued with func_0031A650.
 * Offsets are exact; fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_SPRITEPACKET_H
#define GODHAND_SPRITEPACKET_H

typedef struct SpritePacket {
    unsigned long dmaTag;               /* 0x00 */
    int vifFlush;                       /* 0x08 */
    int vifDirect;                      /* 0x0C */
    unsigned long gifA[2];              /* 0x10 A+D header, 1 register: TEST */
    unsigned long testData;             /* 0x20 */
    unsigned long testAddr;             /* 0x28 */
    unsigned long gifB[2];              /* 0x30 A+D header of the sprite block */
    unsigned long rgbaq;                /* 0x40 colour plus Q */
    unsigned long rgbaqAddr;            /* 0x48 */
    float uv[2];                        /* 0x50 */
    unsigned long uvAddr;               /* 0x58 */
    unsigned long xyz1;                 /* 0x60 first corner */
    unsigned long xyz1Addr;             /* 0x68 */
    float st[2];                        /* 0x70 */
    unsigned long stAddr;               /* 0x78 */
    unsigned long xyz2;                 /* 0x80 second corner */
    unsigned long xyz2Addr;             /* 0x88 */
    unsigned long endTag;               /* 0x90 */
    int endVifFlush;                    /* 0x98 */
    int pad9C;                          /* 0x9C */
} SpritePacket;

/* Texture-info record: bit 0 sets uv and st, bit 5 replaces the TEST word. */
typedef struct SpriteInfo {
    unsigned int flags;                 /* 0x00 */
    float uv[2];                        /* 0x04 */
    float st[2];                        /* 0x0C */
    char unk14[0x30 - 0x14];
    unsigned long testData;             /* 0x30 */
} SpriteInfo;

typedef char SpritePacket_size_check[(sizeof(SpritePacket) == 0xA0) ? 1 : -1];

#endif
