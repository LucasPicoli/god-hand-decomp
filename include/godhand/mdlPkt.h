/* include/godhand/mdlPkt.h - model packs and the GIF packets built from them.
 *
 * SN only: `long long` is 128-bit (one quadword) and `unsigned long` 64-bit.
 * Offsets are exact; unnamed fields stay as padding.
 */
#ifndef GODHAND_MDLPKT_H
#define GODHAND_MDLPKT_H

typedef union PktQw {
    long long all;              /* 128-bit in SN */
    struct {
        unsigned long lo;
        unsigned int w8;
        unsigned int wC;
    } s;
    struct {
        unsigned long data;
        unsigned long addr;     /* GS register the A+D data goes to */
    } ad;
} PktQw;

#define MDL_PKT_VTX_PER_BLOCK  24     /* vertices that share one packet block */
#define MDL_PKT_HEADER         0x10   /* bytes in front of the first packet block */

typedef struct MdlPack {
    char pad00[0x20];
    int ofs[1];                 /* 0x20 record offsets from the pack start */
} MdlPack;

typedef struct MdlRec {
    int ofsVtx;                 /* 0x00 */
    int unk04;
    int ofsNrm;                 /* 0x08 */
    int ofsUv;                  /* 0x0C */
    int unk10;
    unsigned short nVtx;        /* 0x14 */
    unsigned char texNo;        /* 0x16 texture of the record, within the object's bank */
} MdlRec;

typedef struct PackRef {
    MdlPack *base;
    MdlRec *rec;
} PackRef;

typedef struct MdlObj {
    char pad000[0x300];
    PktQw *pkt[2][16];          /* 0x300 packet start per buffer and record */
    int flags;                  /* 0x380 */
    unsigned char texBank;      /* 0x384 first texture of the object */
    char pad385[3];
    MdlPack *pack;              /* 0x388 */
} MdlObj;

typedef struct GifTagEnt {
    unsigned int w0;
    unsigned int w1;
} GifTagEnt;

typedef struct MdlPktBuf {
    unsigned long q[22];        /* 0xB0, double-buffered */
} MdlPktBuf;

extern GifTagEnt D_004A5D80[];
extern MdlPktBuf D_00747BB8[];  /* texture set-up packets, one per texture */

/* A 64-bit packet tag built from a two-word table entry: w0 is the upper word (low 28 bits),
 * w1 the lower word with 0x30000000 set. */
#define TAG64(e) ((unsigned int)((e).w1 | 0x30000000) | ((unsigned long)((e).w0 & 0x0FFFFFFF) << 32))

/* Record idx's vertex packet body at q; returns the qword after it. buf is not read. */
PktQw *func_00155800(MdlObj *self, PktQw *q, int idx, int buf);

#endif
