/* include/godhand/StreamBuf.h - a streaming sound buffer: EE reads into one
 * or two slots, and in two-slot mode each finished read is sent on to SPU2.
 *
 * StreamBuf_startRead (0x1E3858 TU) starts the EE reads; func_002D34A8 steps
 * the whole stream once per frame; func_002D3220 clears the 0xC0-byte record.
 * Field names are ours; offsets are exact. A field nobody has named yet
 * stays as unkNN padding.
 */
#ifndef GODHAND_STREAMBUF_H
#define GODHAND_STREAMBUF_H

/* Bits of StreamBuf.flags. */
#define STREAMBUF_F_USED     0x01       /* the record is in use (func_002D3210) */
#define STREAMBUF_F_STARTED  0x02       /* the first read has been started */

/* Values of StreamBuf.state[]. */
#define STREAMBUF_ST_IDLE    0          /* start an EE read into this slot */
#define STREAMBUF_ST_READING 1          /* EE read in flight */
#define STREAMBUF_ST_SPU     2          /* SPU2 transfer in flight */
#define STREAMBUF_ST_DONE    3          /* nothing left for this slot */

#define STREAMBUF_NSLOT      2

/* One EE read: len bytes from src to dst. */
typedef struct StreamRec {
    int src;                            /* 0x00 address of the next bytes */
    int dst;                            /* 0x04 where they go */
    int len;                            /* 0x08 length of this read */
    int zero;                           /* 0x0C */
} StreamRec;

typedef struct StreamBuf {
    unsigned int flags;                 /* 0x00 STREAMBUF_F_* */
    int dual;                           /* 0x04 nonzero: two slots, dst from bufDst[] */
    int srcBase;                        /* 0x08 start of the source data */
    int dstBase;                        /* 0x0C start of the single destination */
    int state[4];                       /* 0x10 STREAMBUF_ST_* per slot */
    char unk20[0x20];
    StreamRec rec[2];                   /* 0x40 */
    int handle[2];                      /* 0x60 EE read id per slot */
    unsigned int limit;                 /* 0x68 largest read and largest SPU2 transfer */
    int spuBase;                        /* 0x6C SPU2 address of the stream */
    int pos;                            /* 0x70 bytes already read */
    unsigned int left;                  /* 0x74 bytes still to read */
    int spuPos;                         /* 0x78 SPU2 offset of the next transfer */
    unsigned int spuLeft;               /* 0x7C bytes still to send to SPU2 */
    int unk80;
    void *bufDst[2];                    /* 0x84 EE buffer per slot when dual, freed when done */
    int busy;                           /* 0x8C STREAMBUF_ST_SPU while a transfer is in flight */
    unsigned int spuLen;                /* 0x90 length of that transfer */
    char unk94[0xC0 - 0x94];
} StreamBuf;                            /* 0xC0 */

typedef char StreamBuf_size_check[(sizeof(StreamBuf) == 0xC0) ? 1 : -1];

#endif /* GODHAND_STREAMBUF_H */
