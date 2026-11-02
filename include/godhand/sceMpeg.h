/* include/godhand/sceMpeg.h - pieces of SCE libmpeg (0x399xxx..0x3A0xxx) shared between its units. */
#ifndef GODHAND_SCEMPEG_H
#define GODHAND_SCEMPEG_H

/* What is left of a picture for the channel 4 (to-IPU) handler to send. */
typedef struct MpegDmaRest {
    unsigned int qwc;           /* 0x00 quadwords still to send */
    unsigned int madr;          /* 0x04 next address */
} MpegDmaRest;

/* What the channel 3 (from-IPU) handler _ch3dmaCSC steps through while a
 * picture is colour-converted in 1023-macroblock commands. */
typedef struct MpegCscWork {
    volatile int n;             /* 0x00 commands done, counted by the handler */
    int err;                    /* 0x04 set by the handler when a transfer is left over */
    unsigned int rem;           /* 0x08 macroblocks */
    unsigned int madr;          /* 0x0C next output address */
    int total;                  /* 0x10 commands needed */
} MpegCscWork;

/* The decoder fields the colour-conversion units read. */
typedef struct MpegCscDec {
    char unk000[0xEC];
    unsigned int outBuf;        /* 0x0EC colour-converted image */
    char unk0F0[0x828 - 0xF0];
    int cmdIdle;                /* 0x828 0 after a BDEC, VDEC or FDEC command */
    int cmd;                    /* 0x82C last IPU command */
    char unk830[0x868 - 0x830];
    void *cbList;               /* 0x868 */
} MpegCscDec;

/* Callback data passed to func_0039AB20. */
typedef struct MpegCbData {
    int type;                   /* 0x00 */
    char unk04[0x20 - 0x04];
} MpegCbData;

/* _sceMpegError: report msg through the decoder's callback. */
int func_0039C390(int m, int msg);
/* _sceMpegDispatchMpegCallback: cb points at the callback data's type word. */
int func_0039AB20(void *m, int *cb);
/* Channel 4 handler: send the next 0xFFFF-quadword piece of rest. */
int func_0039C140(int chan, MpegDmaRest *rest);
int _ch3dmaCSC(int chan, MpegCscWork *w);
/* Colour-convert mbCount macroblocks into buf in 1023-macroblock commands. */
void func_0039B960(MpegCscDec *dec, unsigned int buf, int mbCount);

#endif /* GODHAND_SCEMPEG_H */
