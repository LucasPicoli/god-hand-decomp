/* sn-2.95.3-136 */

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

/* The TIM2 picture header . */
typedef struct Tim2PicHdr {
    char pad00[0x8];
    int imageSize;              /* 0x08 */
    unsigned short headerSize;  /* 0x0C */
    char pad0E[0x13 - 0xE];
    unsigned char imageType;    /* 0x13 */
    unsigned short width;       /* 0x14 */
    unsigned short height;      /* 0x16 */
    GsTex0 tex0;                /* 0x18 */
} Tim2PicHdr;

extern int D_0041EE70[];        /* GS pixel format of each TIM2 image type, from 1 (second table) */
extern int D_0041EE88[];        /* GS pixel format of each TIM2 image type, from 1 */
extern int func_00309C30(unsigned int psm, int w);
extern void func_0015E510(void *work, int psm, int tbp, int tbw, int w, int h, char *data);
extern void func_0015E708(void *work, int psm, int tbp, int tbw, int w, int h, char *data);
extern void func_0015E8B8(void *work, int psm, int tbp, int tbw, int w, int h, char *data);

/* Load the first picture of a TIM2 file (header at 0x10, or at 0x80 when the format byte is set): image at tbp, CLUT at cbp (16x16 for 8-bit images, 8x2 otherwise), and
 * build its TEX0 register in out. */
__attribute__((section(".text.func_0015E0A0")))
void func_0015E0A0(void *work, Tim2FileHdr *tim, int tbp, int cbp, GsTex0 *out)
{
    Tim2PicHdr *pic;
    int psm;
    int w;
    int h;
    int tbw;
    char *image;
    char *clut;

    if (tim->format == 0) {
        pic = (Tim2PicHdr *)(tim + 1);
    } else {
        pic = (Tim2PicHdr *)((char *)tim + 0x80);
    }
    psm = D_0041EE70[pic->imageType - 1];
    pic->tex0.PSM = psm;
    *out = pic->tex0;
    w = pic->width;
    image = (char *)pic + pic->headerSize;
    h = pic->height;
    tbw = func_00309C30(psm, w);
    out->TBP0 = tbp;
    out->TBW = tbw;
    out->TCC = 1;
    func_0015E510(work, psm, tbp, tbw, w, h, image);
    out->CPSM = 0;
    out->CSM = 0;
    out->CSA = 0;
    out->CLD = 1;
    out->CBP = cbp;
    clut = (char *)pic + pic->headerSize + pic->imageSize;
    if (pic->imageType == 5) {
        func_0015E8B8(work, 0, cbp, 1, 16, 16, clut);
    } else {
        func_0015E8B8(work, 0, cbp, 1, 8, 2, clut);
    }
}

/* Load the first picture of a TIM2 file: image at tbp, CLUT at cbp (16x16 for 8-bit images, 8x2 otherwise), and
 * build its TEX0 register in out. */
__attribute__((section(".text.func_0015E2E0")))
void func_0015E2E0(void *work, Tim2FileHdr *tim, int tbp, int cbp, GsTex0 *out)
{
    Tim2PicHdr *pic;
    int psm;
    int w;
    int h;
    int tbw;
    char *image;
    char *clut;

    pic = (Tim2PicHdr *)(tim + 1);
    psm = D_0041EE88[pic->imageType - 1];
    pic->tex0.PSM = psm;
    *out = pic->tex0;
    w = pic->width;
    image = (char *)pic + pic->headerSize;
    h = pic->height;
    tbw = func_00309C30(psm, w);
    out->TBP0 = tbp;
    out->TBW = tbw;
    out->TCC = 1;
    func_0015E708(work, psm, tbp, tbw, w, h, image);
    out->CPSM = 0;
    out->CSM = 0;
    out->CSA = 0;
    out->CLD = 1;
    out->CBP = cbp;
    clut = (char *)pic + pic->headerSize + pic->imageSize;
    if (pic->imageType == 5) {
        func_0015E8B8(work, 0, cbp, 1, 16, 16, clut);
    } else {
        func_0015E8B8(work, 0, cbp, 1, 8, 2, clut);
    }
}
