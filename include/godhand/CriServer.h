/* include/godhand/CriServer.h - the CRI stream server's callback and timing record.
 *
 * The server runs at a caller-set frequency in Hz. From it the setter derives
 * how many server calls one 1536-sample block of 144000 Hz audio spans,
 * rounded up by one.
 */
#ifndef GODHAND_CRISERVER_H
#define GODHAND_CRISERVER_H

#define CRISVR_SAMPLE_RATE  144000
#define CRISVR_BLOCK_SIZE   1536

typedef struct CriServer {
    char unk00[0x10];
    void *callback;                     /* 0x10 */
    void *context;                      /* 0x14 passed to the callback */
    int callsPerBlock;                  /* 0x18 */
} CriServer;

#endif
