/* include/godhand/adxbPrm.h - the ADXB decoder's stream parameters (CRI libadxe, 0x33CC50).
 *
 * ADXB_SetDefPrm fills these fields with the defaults a raw PCM stream plays
 * with before a header is parsed; the header parsers (ADXB_DecodeHeaderAc3 at
 * 0x33AD08) fill the same fields from the stream. This is the same 0x104-byte
 * object as ADX_BASIC in criStm.h and AdxbSte in adxbSte.h; only the fields
 * these functions write are named.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXBPRM_H
#define GODHAND_ADXBPRM_H

#define ADXB_DEF_BPS        0x10        /* 16-bit samples */
#define ADXB_DEF_NCH        2
#define ADXB_DEF_BLKLEN     0x400       /* samples per decode block */
#define ADXB_DEF_SFREQ      48000
#define ADXB_DEF_TOTAL      0x7FFFFFFF  /* no end */
#define ADXB_DEF_LEVEL      0x7F

typedef struct AdxbPrm {
    char unk00[2];
    short mode;                         /* 0x02 set to 1 by every parameter fill */
    char unk04[0x0D - 0x04];
    unsigned char bps;                  /* 0x0D bits per sample */
    unsigned char nch;                  /* 0x0E channels */
    unsigned char level;                /* 0x0F */
    int blkLen;                         /* 0x10 samples per decode block */
    int sfreq;                          /* 0x14 sample rate in Hz */
    int total;                          /* 0x18 total samples */
    short lpType;                       /* 0x1C loop fields, all cleared */
    char unk1E[2];
    int lpStart;                        /* 0x20 */
    short lpFlag;                       /* 0x24 */
    short lpCount;                      /* 0x26 */
    int lpStartOfst;                    /* 0x28 */
    int lpEnd;                          /* 0x2C */
    int lpEndOfst;                      /* 0x30 */
    int lpLen;                          /* 0x34 */
    char unk38[0x3C - 0x38];
    int pcmbuf;                         /* 0x3C the output ring */
    int pcmbsize;                       /* 0x40 ring length in samples */
    int pcmbdist;                       /* 0x44 distance between the channel rings */
    char unk48[0x50 - 0x48];
    int wkNch;                          /* 0x50 decode work block (AdxbSteWork at 0x48) */
    int wkLevel;                        /* 0x54 */
    int wkBlkLen;                       /* 0x58 */
    int wkBuf;                          /* 0x5C */
    int wkSize;                         /* 0x60 */
    int wkDist;                         /* 0x64 */
    char unk68[0x88 - 0x68];
    int decPos;                         /* 0x88 cleared on every reset */
    int decCnt;                         /* 0x8C */
    char unk90[0x98 - 0x90];
    short fmt;                          /* 0x98 stream format id */
    unsigned short defFmt;              /* 0x9A format used when no header is parsed */
    char unk9C[0x104 - 0x9C];
} AdxbPrm;
typedef char AdxbPrm_size_check[sizeof(AdxbPrm) == 0x104 ? 1 : -1];

#endif /* GODHAND_ADXBPRM_H */
