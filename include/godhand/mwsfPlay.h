/* include/godhand/mwsfPlay.h - the playback record MWSF builds at start (cygnus code at 0x344948).
 *
 * func_00344948 turns the caller's play request (MwsfPlayReq) into the
 * playback record the server keeps (MwsfPlayRec): it converts the format
 * codes, scales the frame times by the stream rate, and copies the request's
 * trailing block of 64-bit words unchanged.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MWSFPLAY_H
#define GODHAND_MWSFPLAY_H

/* Seven 64-bit words the request carries through unchanged (a struct copy, so ld/sd runs). */
typedef struct MwsfTail {
    long w[7];
} MwsfTail;

typedef struct MwsfPlayReq {
    int fmtA;                           /* 0x00 */
    int w04;
    int w08;
    int w0C;
    int fmtB;                           /* 0x10 */
    int unk14;
    int unitA;                          /* 0x18 time scale */
    int fmtC;                           /* 0x1C */
    int w20;                            /* 0x20 copied to the record head */
    int w24;                            /* 0x24 */
    int w28;                            /* 0x28 */
    int timeC;                          /* 0x2C */
    int timeB;                          /* 0x30 */
    int timeA;                          /* 0x34 */
    char unk38[0x48 - 0x38];
    MwsfTail tail;                      /* 0x48 copied to the record 0x50 */
} MwsfPlayReq;

typedef struct MwsfPlayRec {
    int w00;                            /* 0x00 */
    char unk04[4];
    int fmtC;                           /* 0x08 */
    int a0C;                            /* 0x0C */
    int a10;                            /* 0x10 */
    int a14;                            /* 0x14 */
    int a18;                            /* 0x18 */
    int fmtB;                           /* 0x1C */
    int rate;                           /* 0x20 the stream rate */
    int scaledB;                        /* 0x24 */
    int timeA;                          /* 0x28 */
    int unitA;                          /* 0x2C */
    int timeC;                          /* 0x30 */
    int scaledA;                        /* 0x34 */
    int timeB;                          /* 0x38 */
    int w3C;                            /* 0x3C */
    int w40;                            /* 0x40 */
    char unk44[8];
    int dataLen;                        /* 0x4C */
    MwsfTail tail;                      /* 0x50 */
    int payload;                        /* 0x88 */
    int payloadLen;                     /* 0x8C */
} MwsfPlayRec;
typedef char MwsfPlayRec_size_check[sizeof(MwsfPlayRec) == 0x90 ? 1 : -1];

#endif
