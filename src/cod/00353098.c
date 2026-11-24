/* cygnus-2.96: sfmpv_ChkBufSiz, check the configured frame size against
 * the work buffer, then split the buffer into per-frame pointers. */
#include "godhand/criStm.h"
#include "godhand/sftim.h"

extern void sfmpv_InitFrmObj(StmSlot *s, int *ids, int n);

static inline unsigned int frmBufSize(int mode, int w, int h)
{
    int mbw = w / 16;
    int mbh = h / 16;

    if (mode == 2)
        return mbw * mbh * 1024 + 64;
    return mbw * mbh * 384 + 64;
}

__attribute__((section(".text.sfmpv_ChkBufSiz")))
int sfmpv_ChkBufSiz(SftimHn *hn, SfdMvInf *mv)
{
    SfdWork *w = hn->work;
    SfdFrmCfg *cfg = &w->cfg;
    int mode = hn->mode;
    int n = cfg->nbuf;
    unsigned int size;
    int mbw;
    int mbh;
    char *buf;
    int i;

    if (cfg->maxW * cfg->maxH < mv->width * mv->height)
        return func_0034DD70(hn, 0xFF000F17);
    size = frmBufSize(mode, mv->width, mv->height);
    /* frmBufSize() here instead changes the register allocation */
    mbw = cfg->bufW / 16;
    mbh = cfg->bufH / 16;
    if ((mode == 2 ? mbw * mbh * 1024 : mbw * mbh * 384) + 64 < size)
        return func_0034DD70(hn, 0xFF000F18);
    buf = cfg->buf;
    if (buf != 0) {
        for (i = 0; i < n; i++)
            w->frmBuf[i] = buf + i * size;
    } else {
        for (i = 0; i < n; i++)
            ; /* retail keeps this empty loop: dropping it changes the code */
    }
    w->nfrm = n;
    /* StmSlot is the stream view of the same 0xF0-byte SfdFrm; its id at 0x08 is SfdFrm.buf */
    sfmpv_InitFrmObj((StmSlot *)w->frm, (int *)w->frmBuf, n);
    return 0;
}
