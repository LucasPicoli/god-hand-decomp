/* include/godhand/IopXfer.h - the EE to IOP transfer slots (cygnus code at 0x332178..).
 *
 * Sixteen slots of 0x44 bytes at D_003D84C0. A slot owns one DMA buffer: the
 * fill callback writes the next block, the pump sends it to the IOP and the
 * receive callback runs when the IOP has consumed it. Field names are ours;
 * offsets are exact.
 */
#ifndef GODHAND_IOPXFER_H
#define GODHAND_IOPXFER_H

#define IOPXFER_SLOTS       16
#define IOPXFER_ALIGN_BUF   0x3F        /* buffer and size alignment mask */
#define IOPXFER_ALIGN_DEST  0x1F        /* IOP address alignment mask */
#define IOPXFER_HDR_LEN     0x40        /* trailer after the data: the sequence header */
#define IOPXFER_UNCACHED    0x20000000

typedef struct IopXferHdr {
    char unk00[0x3C];
    int seq;                            /* 0x3C */
} IopXferHdr;

typedef struct IopXferDma {
    unsigned int data;                  /* 0x00 */
    unsigned int addr;                  /* 0x04 */
    unsigned int size;                  /* 0x08 */
    unsigned int mode;                  /* 0x0C */
} IopXferDma;

typedef void (*IopXferCb)(int arg, char *buf, int size);

typedef struct IopXfer {
    signed char used;                   /* 0x00 slot is allocated */
    signed char state;                  /* 0x01 1 while a send is in flight */
    signed char active;                 /* 0x02 */
    char unk03;
    int rmt;                            /* 0x04 remote object handle */
    int count;                          /* 0x08 blocks sent */
    char *buf;                          /* 0x0C data buffer */
    int size;                           /* 0x10 data length */
    IopXferHdr *hdr;                    /* 0x14 uncached sequence header */
    unsigned int dest;                  /* 0x18 IOP address */
    unsigned int dsize;                 /* 0x1C bytes sent per block */
    IopXferCb recv;                     /* 0x20 */
    int recvArg;                        /* 0x24 */
    IopXferCb fill;                     /* 0x28 */
    int fillArg;                        /* 0x2C */
    IopXferDma dma;                     /* 0x30 */
    int id;                             /* 0x40 */
} IopXfer;

extern IopXfer D_003D84C0[IOPXFER_SLOTS];

#endif
