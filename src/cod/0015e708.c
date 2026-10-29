/* sn-2.95.3-136 */
#include "godhand/gsLoadImage.h"

/* Build the DMA chain that uploads a 4- or 8-bit w x h image to tbp as a
 * 32-bit image: half the width, and a quarter (4-bit) or half (8-bit) of
 * the rows. tbw is not read; the buffer width follows from w. */
__attribute__((section(".text.func_0015E708")))
void func_0015E708(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data)
{
    int width = w / 2;
    int qwc;

    if (psm == 0x14) {
        h = h / 4;
    } else if (psm == 0x13) {
        h = h / 2;
    }
    qwc = width * h >> 2;

    pkt->dmaTag = 0x10000006;
    pkt->vifFlush = 0x11000000;
    pkt->vifDirect = 0x50000006;
    pkt->gifTag[0] = 0x1000000000008004L;
    pkt->gifTag[1] = 0xE;
    pkt->bitbltbuf = (unsigned long)tbp << 32 | (unsigned long)(width / 64) << 48;
    pkt->bitbltbufAddr = 0x50;
    pkt->trxpos = 0;
    pkt->trxposAddr = 0x51;
    pkt->trxreg = (unsigned long)width | (unsigned long)h << 32;
    pkt->trxregAddr = 0x52;
    pkt->trxdir = 0;
    pkt->trxdirAddr = 0x53;
    pkt->imageTag[0] = (unsigned long)(unsigned int)(qwc | 0x8000) | (unsigned long)0x8000 << 44;
    pkt->imageTag[1] = 0;
    pkt->refTag = (unsigned long)(unsigned int)(qwc | 0x30000000) | (unsigned long)((int)data & 0x0FFFFFFF) << 32;
    pkt->vifNop = 0;
    pkt->vifDirectImage = qwc | 0x50000000;
    pkt->endTag = 0x10000002;
    pkt->endVifFlush = 0x11000000;
    pkt->endVifDirect = 0x50000002;
    pkt->endGifTag[0] = 0x1000000000008001L;
    pkt->endGifTag[1] = 0xE;
    pkt->texflush = 0xFF;
    pkt->texflushAddr = 0x3F;
}
