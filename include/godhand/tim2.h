/* include/godhand/tim2.h - the TIM2 texture file and the GS TEX0 register built from it. */
#ifndef GODHAND_TIM2_H
#define GODHAND_TIM2_H

typedef struct GsTex0 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
} GsTex0;

/* The TIM2 file header. */
typedef struct Tim2FileHdr {
    char id[4];                 /* 0x00 "TIM2" */
    unsigned char version;      /* 0x04 */
    unsigned char format;       /* 0x05 0: pictures follow at 0x10, else at 0x80 */
    unsigned short pictures;    /* 0x06 */
    char pad08[8];
} Tim2FileHdr;

/* The TIM2 picture header. */
typedef struct Tim2PicHdr {
    unsigned int totalSize;     /* 0x00 */
    unsigned int clutSize;      /* 0x04 */
    unsigned int imageSize;     /* 0x08 */
    unsigned short headerSize;  /* 0x0C */
    char pad0E[0x13 - 0xE];
    unsigned char imageType;    /* 0x13 */
    unsigned short width;       /* 0x14 */
    unsigned short height;      /* 0x16 */
    GsTex0 tex0;                /* 0x18 */
} Tim2PicHdr;

extern int D_0041ED80[];        /* GS pixel format of each TIM2 image type, from 1 (texture bank loads) */

/* GS buffer width (in 64-pixel units) of a width-pixel image of format psm. */
int func_00309C30(unsigned int psm, int width);

/* Build the upload of the texture file tim (image at tbp, CLUT at cbp) into
 * work and its TEX0 register in out, one builder per file kind 0, 1, 2. */
void func_0015E0A0(void *work, Tim2FileHdr *tim, int tbp, int cbp, GsTex0 *out);
void func_0015E2E0(void *work, Tim2FileHdr *tim, int tbp, int cbp, GsTex0 *out);

/* One block of a texture upload file: data points at the block's prebuilt
 * GS register set-up, with the pixels after it (an offset from the block
 * index until the file is first loaded). */
typedef struct TexUpBlock {
    int unk0;
    char *data;                 /* 0x04 */
    int unk8;
    int unkC;
} TexUpBlock;

/* A texture upload file (the third kind the texture loaders take): indexes
 * of image and CLUT blocks and the TEX0 register to draw with. */
typedef struct TexUpFile {
    int flags;                  /* 0x00 sign bit: the block pointers are relocated */
    int unk4;
    int images;                 /* 0x08 offset of the image block index */
    int cluts;                  /* 0x0C offset of the CLUT block index */
    unsigned short imageNum;    /* 0x10 */
    unsigned short clutNum;     /* 0x12 */
    char pad14[0x20 - 0x14];
    GsTex0 tex0;                /* 0x20 */
} TexUpFile;

struct TexUpPacket;
void func_0015DDF8(struct TexUpPacket *pkt, TexUpFile *file, int tbp, int cbp, GsTex0 *out);

#endif
