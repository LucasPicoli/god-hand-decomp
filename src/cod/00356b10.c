/* cygnus-2.96 matched TU. */

#include "godhand/sftim.h"

extern int ReturnK_Neg1_369FB0(void);
extern int viBufAddDMA(ViBuf *b);
extern int sceMpegGetPicture(void *m, unsigned int addr, int mode);
extern int sceMpegGetPictureRAW8(void *m, unsigned int addr, int mode);

/* CRI Sofdec: header-chunk scan loop. */
#define SFHDR_F_HAS_INFO 0x20000   /* a chunk carried the 32 B info block */
#define SFHDR_INFO_SLOTS_OFFSET 0x48

typedef struct { unsigned char b[0x20]; } SfInfo32;

typedef struct SfInfoSrc {
    unsigned char unk0[8];
    int slot0Used;   /* 0x8 */
    int slot1Used;   /* 0xC */
} SfInfoSrc;



/* Parses chunks until fewer than 4 bytes remain or a chunk ends the header,
 * then copies the 32 B info block at +0x28 into the first free info slot. */
__attribute__((section(".text.sfhdr_ScanChunks")))
int sfhdr_ScanChunks(char *hdr, char *buf, int len, int *nread, unsigned int *flags)
{
    int used;
    unsigned int fl;
    int more;
    unsigned int prev;
    int slot;
    SfInfoSrc *src;

    while (len >= 4) {
        more = func_00366FE0(hdr, buf, len, &used, &fl);
        prev = *flags;
        buf += used;
        len -= used;
        *nread += used;
        *flags = prev | fl;
        if (more == 0)
            break;
    }
    if (*flags & SFHDR_F_HAS_INFO) {
        src = (SfInfoSrc *)(hdr + 0x28);
        slot = 0;
        if (src->slot0Used == 0) {
            if (src->slot1Used != 0)
                slot = 1;
            else
                slot = 2;
        }
        *(SfInfo32 *)(hdr + slot * 0x20 + SFHDR_INFO_SLOTS_OFFSET) = *(SfInfo32 *)src;
    }
    return 0;
}

/* CRI Sofdec: decode one picture from the video-input buffer. */


#define SFD_VIDCTL_OFS   0x1128
#define SFD_MPEG_OFS     0x1150   /* the sceMpeg object */
#define SFD_MODE_RGB32   2        /* SftimHn.mode: decode to 32-bit RGB, else RAW8 */
#define SFD_ERR_BUSY     (-3)
#define MB_SIZE          16

typedef struct SfdVidCtl {
    char unk00[0x14];
    int pending;                  /* 0x14 a decode is in flight */
    int busy;                     /* 0x18 */
} SfdVidCtl;

typedef struct SfdOutBuf {
    char unk00[0x20];
    unsigned int addr;            /* 0x20 destination of the decoded picture */
} SfdOutBuf;

#define SFD_WORK_VIDCTL(w) ((SfdVidCtl *)((char *)(w) + SFD_VIDCTL_OFS))
#define SFD_VIDCTL_VIBUF(c) ((ViBuf *)((char *)(c) + 0x70))   /* the ViBuf follows the control block */











/* Decodes the next picture into out->addr, sized from the frame setup in macroblocks. */
__attribute__((section(".text.sfdmpv_DecodePicture")))
int sfdmpv_DecodePicture(void *obj, void *a1, SfdOutBuf *out, SftimHn *hn)
{
    SfdWork *w;
    SfdVidCtl *ctl;
    ViBuf *vb;
    SfdFrmCfg *cfg;
    int r;
    int nmb;
    int mode;

    if (func_00356358(hn) == 0)
        return ReturnK_Neg1_369FB0();
    w = hn->work;
    r = (int)func_00369FB8(obj, a1, out);
    vb = SFD_WORK_VIBUF(w);
    ctl = SFD_WORK_VIDCTL(w);
    cfg = &w->cfg;
    func_00355F88(vb);
    viBufAddDMA(vb);
    mode = hn->mode;
    ctl->pending = 1;
    nmb = (cfg->maxW / MB_SIZE) * (cfg->maxH / MB_SIZE);
    if (mode == SFD_MODE_RGB32)
        sceMpegGetPicture((char *)w + SFD_MPEG_OFS, out->addr, nmb);
    else
        sceMpegGetPictureRAW8((char *)w + SFD_MPEG_OFS, out->addr, nmb);
    ctl->pending = 0;
    func_00355E88(SFD_VIDCTL_VIBUF(ctl));
    func_00356E80((char *)hn);
    if (ctl->busy != 0)
        return SFD_ERR_BUSY;
    return r;
}
