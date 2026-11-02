/* ee-2.9-991111 */
#include "godhand/gameWork.h"
#include "godhand/eeKernel.h"
#include "godhand/sceMpeg.h"

#define IPU_CMD     (*(volatile unsigned int *)0x10002000)
#define IPU_CTRL    (*(volatile int *)0x10002010)
#define D3_CHCR     (*(volatile unsigned int *)0x1000B000)
#define D3_MADR     (*(volatile unsigned int *)0x1000B010)
#define D3_QWC      (*(volatile unsigned int *)0x1000B020)
#define D4_CHCR     (*(volatile unsigned int *)0x1000B400)
#define D4_MADR     (*(volatile unsigned int *)0x1000B410)
#define D4_QWC      (*(volatile unsigned int *)0x1000B420)
#define D_STAT      (*(volatile unsigned int *)0x1000E010)

#define IPU_CTRL_ECD    0x4000          /* error code detected */
#define IPU_CTRL_RST    0x40000000
#define IPU_CMD_CSC     0x70000000
#define DMA_CH_IPU_FROM 3
#define DMA_CH_IPU_TO   4

/* The decoded picture: its macroblock data and size in macroblocks. */
typedef struct MpegCscPic {
    unsigned int data;                  /* 0x00 */
    char unk04[0x0C - 0x04];
    int mbWidth;                        /* 0x0C */
    int mbHeight;                       /* 0x10 */
} MpegCscPic;

/* Colour-convert the whole picture in one IPU CSC command, waiting for it. */
static __inline__ void MpegCsc_run(MpegCscDec *dec, unsigned int buf, int mbCount)
{
    MpegCbData cb;
    unsigned int qwc = mbCount << 6;
    unsigned int cmd;
    int oldstat;

    while (IPU_CTRL < 0)
        ;
    oldstat = func_003B63A0();
    D3_MADR = buf & 0x0FFFFFFF;
    D3_QWC = qwc;
    D3_CHCR = 0x100;
    if (oldstat)
        EIntr();
    cmd = mbCount | IPU_CMD_CSC;
    IPU_CMD = cmd;
    dec->cmd = cmd & 0xF0000000;
    if (dec->cmd == 0x20000000 || dec->cmd == 0x30000000 || dec->cmd == 0x40000000)
        dec->cmdIdle = 0;
    else
        dec->cmdIdle = 1;
    cb.type = 4;
    func_0039AB20(dec->cbList, &cb.type);
    while (D3_CHCR >> 8 & 1)
        ;
    while (IPU_CTRL < 0)
        ;
}

/* Send the decoded picture to the IPU (in 0xFFFF-quadword pieces through the
 * channel 4 handler when it is larger) and colour-convert it into the output
 * buffer, in one command when it has fewer than 0x400 macroblocks. */
__attribute__((section(".text.func_0039BB20")))
void func_0039BB20(MpegCscDec *dec, MpegCscPic *pic)
{
    MpegCbData cb;
    MpegDmaRest rest;
    int mbCount = pic->mbWidth * pic->mbHeight;
    int oneCmd;
    int hid;
    int oldstat;

    cb.type = 2;
    func_0039AB20(dec->cbList, &cb.type);
    if (IPU_CTRL & IPU_CTRL_ECD)
        IPU_CTRL = IPU_CTRL_RST;
    oneCmd = mbCount < 0x400;
    while (IPU_CTRL < 0)
        ;
    IPU_CMD = 0;
    dec->cmdIdle = 1;
    dec->cmd = 0;
    while (IPU_CTRL < 0)
        ;
    FlushCache(0);
    rest.qwc = mbCount * 0x18;
    rest.madr = pic->data & 0x0FFFFFFF;
    if (rest.qwc > 0xFFFF) {
        hid = AddDmacHandler2(DMA_CH_IPU_TO, (int (*)(int, void *))func_0039C140, 0, &rest);
        D_STAT = 0x10;
        func_003B0810(DMA_CH_IPU_TO);
        oldstat = func_003B63A0();
        D4_MADR = rest.madr;
        D4_QWC = 0xFFFF;
        D4_CHCR = 0x101;
        if (oldstat)
            EIntr();
        rest.madr = (rest.madr + 0xFFFF0) & 0x0FFFFFFF;
        rest.qwc -= 0xFFFF;
        if (oneCmd)
            MpegCsc_run(dec, dec->outBuf, mbCount);
        else
            func_0039B960(dec, dec->outBuf, mbCount);
        func_003B07A8(DMA_CH_IPU_TO);
        RemoveDmacHandler(DMA_CH_IPU_TO, hid);
    } else {
        oldstat = func_003B63A0();
        D4_MADR = pic->data & 0x0FFFFFFF;
        D4_QWC = rest.qwc;
        D4_CHCR = 0x101;
        if (oldstat)
            EIntr();
        rest.qwc = 0;
        if (oneCmd)
            MpegCsc_run(dec, dec->outBuf, mbCount);
        else
            func_0039B960(dec, dec->outBuf, mbCount);
    }
    cb.type = 3;
    func_0039AB20(dec->cbList, &cb.type);
}
