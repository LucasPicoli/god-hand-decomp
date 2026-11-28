#ifndef GODHAND_SCEDMA_H
#define GODHAND_SCEDMA_H

/* An EE DMA channel's registers (libdma sceDmaChan); each register sits in its own 16-byte slot.
 * The transfer setups write them as plain memory; the waits read them through a volatile pointer. */
typedef struct {
    int chcr;                   /* 0x00 */
    unsigned int pad04[3];
    void *madr;                 /* 0x10 */
    unsigned int pad14[3];
    int qwc;                    /* 0x20 */
    unsigned int pad24[3];
    void *tadr;                 /* 0x30 */
} sceDmaChan;

/* The GIF channel's registers. The vendor's SCE_DMA_GIF is the channel id 2. */
#define DMA_GIF_CHAN ((sceDmaChan *)0x1000A000)

/* Spin until the channel stops; pause it if that takes too long. */
void WaitDma(volatile sceDmaChan *chan);
/* Stop the channel; returns CHCR as it was. */
unsigned int sceDmaPause(volatile sceDmaChan *chan);
/* Turn a scratchpad address (0x7xxxxxxx) into the DMA's scratchpad form (bit 31 set). */
unsigned int CheckAddress(unsigned int addr);
/* sceDmaSync: mode 0 waits for the channel to stop, mode 1 only tests it; nonzero while it runs. */
int sceDmaSync(volatile sceDmaChan *chan, int mode, int timeout);
/* sceDmaSend: start a chain transfer at the tag. */
void sceDmaSend(sceDmaChan *chan, void *tag);
/* 00346510.c and 003465e8.c keep their own declarations of sceDmaRecvN and sceDmaSendN, with a
 * local view of the channel that reaches SADR at 0x80: their channel comes from sceDmaGetChan's
 * untyped table, not from a sceDmaChan. */
/* sceDmaSendN: send qwc quadwords from addr. */
void sceDmaSendN(sceDmaChan *chan, void *addr, int qwc);
/* sceDmaRecvN: receive qwc quadwords into addr. */
void sceDmaRecvN(sceDmaChan *chan, void *addr, int qwc);

#endif
