/* ee-2.9-991111 matched TU. */

#include "godhand/sif.h"

/* The DMA descriptors as this function fills them: four plain words. With
 * sceSifDmaData's pointer fields the stores take another alias set and the
 * scheduler moves the D_0077E520 load and the mode store (61 against 57 words). */
typedef struct SifDmaWords {
    unsigned int data;
    unsigned int addr;
    unsigned int size;
    unsigned int mode;
} SifDmaWords;

#define SIF_CMD_PKT_MIN  0x10           /* a packet is 16 to 112 bytes */
#define SIF_CMD_PKT_MAX  0x70

/* _sceSifSendCmd: send command packet pkt (and, when size > 0, size bytes of
 * data from src to dest) to the IOP in one or two SIF DMA transfers. Returns
 * the DMA id, or 0 when pktsize is out of range. */
__attribute__((section(".text._sceSifSendCmd")))
unsigned int _sceSifSendCmd(unsigned int fid, int mode, void *pkt, int pktsize,
                            void *src, void *dest, int size)
{
    SifDmaWords dma[2];
    sceSifCmdHdr *hdr = pkt;
    int n;

    if ((unsigned int)(pktsize - SIF_CMD_PKT_MIN) > SIF_CMD_PKT_MAX - SIF_CMD_PKT_MIN)
        return 0;
    n = 0;
    if (size > 0) {
        n = 1;
        dma[0].data = (unsigned int)src;
        hdr->dsize = size;
        dma[0].addr = (unsigned int)dest;
        hdr->daddr = dest;
        dma[0].size = size;
        dma[0].mode = 0;
        if (mode & SIF_CMD_M_WBDC)
            func_003B2850(src, size);
    } else {
        hdr->dsize = 0;
        hdr->daddr = 0;
    }
    dma[n].data = (unsigned int)pkt;
    dma[n].addr = (unsigned int)D_0077E520;
    dma[n].size = pktsize;
    hdr->fcode = fid;
    hdr->psize = pktsize;
    dma[n].mode = SIF_DMA_ERT | SIF_DMA_INT_O;
    n++;
    func_003B2850(pkt, pktsize);
    if (mode & SIF_CMD_M_INTR)
        return isceSifSetDma((sceSifDmaData *)dma, n);
    return SifSetDma((sceSifDmaData *)dma, n);
}
