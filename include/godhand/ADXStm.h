/* include/godhand/ADXStm.h - the ADX stream object (ADXSTM, CRI).
 *
 * An ADXSTM reads a source through a stream joint (SJ) in 0x800-byte
 * sectors. ADXSTM_Create-style init fills it in between the lock and unlock
 * trampolines. Names are ours, from CRI's ADXSTM. Offsets are exact. A field
 * we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_ADXSTM_H
#define GODHAND_ADXSTM_H

#include "godhand/criSj.h"

#define ADXSTM_SECTOR_SIZE  0x800
#define ADXSTM_SECTOR_SHIFT 11

typedef struct ADXStm {
    unsigned char used;         /* 0x00 */
    unsigned char stat;         /* 0x01 */
    unsigned char unk02;        /* 0x02 */
    char unk03;
    SjObj *sj;                  /* 0x04 */
    int unk08;                  /* 0x08 */
    int unk0C;                  /* 0x0C */
    int size;                   /* 0x10 source size in bytes */
    int nsct;                   /* 0x14 size in sectors, rounded up */
    int ndata0;                 /* 0x18 */
    int ndata1;                 /* 0x1C */
    char unk20[0x2C - 0x20];
    int sctsize;                /* 0x2C */
    int nsct2;                  /* 0x30 */
    char unk34[0x40 - 0x34];
    int ndata2;                 /* 0x40 */
    unsigned char unk44;        /* 0x44 */
    char unk45[0x58 - 0x45];
    int unk58;                  /* 0x58 */
    int limit;                  /* 0x5C */
} ADXStm;

#endif /* GODHAND_ADXSTM_H */
