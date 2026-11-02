/* sn-2.95.3-136 */
#include "godhand/tim2.h"

/* A view of gsLoadImage.h's GsLoadImagePacket (0xB0 bytes): this loader
 * copies the prebuilt register set-up at 0x10..0x6F by quadword and patches
 * BITBLTBUF's destination word and reads the IMAGE tag's NLOOP as 32-bit
 * words, which the header's 64-bit fields don't give. */
typedef union TexUpRegs {
    long long qw[6];                    /* 128-bit in SN */
    struct {
        unsigned long gifTag[2];        /* 0x00 A+D, 4 registers */
        unsigned int bitbltbufSrc;      /* 0x10 BITBLTBUF source half */
        unsigned int bitbltbufDst;      /* 0x14 BITBLTBUF destination half (DBP in the low bits) */
        char pad18[0x50 - 0x18];
        unsigned int imageTagLo;        /* 0x50 IMAGE GIF tag, NLOOP in the low 15 bits */
        char pad54[0x60 - 0x54];
    } r;
} TexUpRegs;

typedef struct TexUpPacket {
    unsigned long dmaTag;               /* 0x00 cnt, 6 qwords */
    int vifFlush;                       /* 0x08 */
    int vifDirect;                      /* 0x0C DIRECT 6 */
    TexUpRegs regs;                     /* 0x10 */
    unsigned long refTag;               /* 0x70 ref to the pixel data */
    int vifNop;                         /* 0x78 */
    int vifDirectImage;                 /* 0x7C DIRECT qwc */
    unsigned long endTag;               /* 0x80 cnt, 2 qwords */
    int endVifFlush;                    /* 0x88 */
    int endVifDirect;                   /* 0x8C DIRECT 2 */
    unsigned long endGifTag[2];         /* 0x90 A+D, 1 register */
    unsigned long texflush;             /* 0xA0 */
    unsigned long texflushAddr;         /* 0xA8 */
} TexUpPacket;

/* Build the two uploads of a prebuilt texture upload file into pkt[0] (its
 * first image, at tbp) and pkt[1] (its first CLUT, at cbp), relocating the
 * file's block pointers the first time, and copy its TEX0 register to out. */
__attribute__((section(".text.func_0015DDF8")))
void func_0015DDF8(TexUpPacket *pkt, TexUpFile *file, int tbp, int cbp, GsTex0 *out)
{
    TexUpBlock *img = (TexUpBlock *)((char *)file + file->images);
    TexUpBlock *clut = (TexUpBlock *)((char *)file + file->cluts);
    TexUpBlock *top;
    TexUpRegs *s;
    unsigned int i;

    if (file->flags >= 0) {
        top = img;
        for (i = 0; i < file->imageNum; i++, img++)
            img->data += (unsigned int)top;
        top = clut;
        for (i = 0; i < file->clutNum; i++, clut++)
            clut->data += (unsigned int)top;
        file->flags |= 0x80000000;
    }
    img = (TexUpBlock *)((char *)file + file->images);
    clut = (TexUpBlock *)((char *)file + file->cluts);

    s = (TexUpRegs *)img->data;
    pkt[0].dmaTag = 0x10000006;
    pkt[0].vifFlush = 0x11000000;
    pkt[0].vifDirect = 0x50000006;
    pkt[0].regs.qw[0] = s->qw[0];
    pkt[0].regs.r.gifTag[0] = 0x1000000000000004;
    pkt[0].regs.qw[1] = s->qw[1];
    pkt[0].regs.r.bitbltbufDst += tbp;
    pkt[0].regs.qw[2] = s->qw[2];
    pkt[0].regs.qw[3] = s->qw[3];
    pkt[0].regs.qw[4] = s->qw[4];
    pkt[0].regs.qw[5] = s->qw[5];
    pkt[0].refTag = (s->r.imageTagLo & 0x7FFF) | 0x30000000 | ((unsigned long)((unsigned int)(s + 1) & 0x0FFFFFFF) << 32);
    pkt[0].vifNop = 0;
    pkt[0].vifDirectImage = (s->r.imageTagLo & 0x7FFF) | 0x50000000;
    pkt[0].endTag = 0x10000002;
    pkt[0].endVifFlush = 0;
    pkt[0].endVifDirect = 0x50000002;
    pkt[0].endGifTag[0] = 0x1000000000008001;
    pkt[0].endGifTag[1] = 0xE;
    pkt[0].texflush = 0xFF;
    pkt[0].texflushAddr = 0x3F;

    s = (TexUpRegs *)clut->data;
    pkt[1].dmaTag = 0x10000006;
    pkt[1].vifFlush = 0x11000000;
    pkt[1].vifDirect = 0x50000006;
    pkt[1].regs.qw[0] = s->qw[0];
    pkt[1].regs.r.gifTag[0] = 0x1000000000008004;
    pkt[1].regs.qw[1] = s->qw[1];
    pkt[1].regs.r.bitbltbufDst = cbp;
    pkt[1].regs.qw[2] = s->qw[2];
    pkt[1].regs.qw[3] = s->qw[3];
    pkt[1].regs.qw[4] = s->qw[4];
    pkt[1].regs.qw[5] = s->qw[5];
    pkt[1].refTag = (s->r.imageTagLo & 0x7FFF) | 0x30000000 | ((unsigned long)((unsigned int)(s + 1) & 0x0FFFFFFF) << 32);
    pkt[1].vifNop = 0;
    pkt[1].vifDirectImage = (s->r.imageTagLo & 0x7FFF) | 0x50000000;
    pkt[1].endTag = 0x10000002;
    pkt[1].endVifFlush = 0;
    pkt[1].endVifDirect = 0x50000002;
    pkt[1].endGifTag[0] = 0x1000000000008001;
    pkt[1].endGifTag[1] = 0xE;
    pkt[1].texflush = 0xFF;
    pkt[1].texflushAddr = 0x3F;

    *out = file->tex0;
}
