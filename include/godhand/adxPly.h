/* include/godhand/adxPly.h - the ADXT handle (cygnus code at 0x329490..).
 *
 * Sixteen handles of 0xC8 bytes at D_003C7420. adxt_Create (0x329490)
 * hands out the first one whose `used` byte is 0 and clears all 0xC8 bytes;
 * the destroy call (0x3298F0) hands back everything the handle owns and
 * clears it again. The handle owns an ADXSJD decoder, a stream, an RNA
 * output, up to two channels of stream joints in three banks, one main
 * joint, an amp and one helper object.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXPLY_H
#define GODHAND_ADXPLY_H

#include "godhand/criSj.h"
#include "godhand/adxsjd.h"

#define ADXPLY_SIZE     0xC8
#define ADXPLY_CH_MAX   2       /* channels per joint bank */

#define ADXPLY_USED     1       /* used: the handle is allocated */

/* AdxPly.stat */
#define ADXT_STAT_PLAYING   3
#define ADXT_STAT_DECEND    4
#define ADXT_STAT_PLAYEND   5

typedef struct AdxPly {
    signed char used;                   /* 0x00 0 when the handle is free */
    signed char stat;                   /* 0x01 ADXT_STAT_* */
    char unk02;
    signed char maxnch;                 /* 0x03 number of channels in use */
    AdxSjd *sjd;                        /* 0x04 decoder, released by ADXSJD_Destroy */
    int stm;                            /* 0x08 stream */
    void *rna;                          /* 0x0C RNA output, released by the tramp chain */
    SjObj *sjo;                         /* 0x10 main joint */
    char unk14[4];
    SjObj *sjiA[ADXPLY_CH_MAX];         /* 0x18 first joint bank, the decoder output */
    char unk20[0x48 - 0x20];
    unsigned int flush;                 /* 0x48 */
    char unk4C[0x70 - 0x4C];
    char busy;                          /* 0x70 */
    char unk71;                         /* 0x71 */
    signed char pause;                  /* 0x72 set by func_0032B340; holds the vsync clock */
    char unk73;
    void *amp;                          /* 0x74 */
    SjObj *sjiB[ADXPLY_CH_MAX];         /* 0x78 second joint bank */
    SjObj *sjiC[ADXPLY_CH_MAX];         /* 0x80 third joint bank */
    int ofs;                            /* 0x88 added to every time */
    char unk8C[0x94 - 0x8C];
    void *rsv94;                        /* 0x94 */
    char unk98[0x9C - 0x98];
    unsigned int baseCount;             /* 0x9C the sample count at baseVsync */
    int baseVsync;                      /* 0xA0 the vsync count at baseCount */
    int base;                           /* 0xA4 added to the sample-clock time */
    int sub;                            /* 0xA8 */
    char unkAC[ADXPLY_SIZE - 0xAC];
} AdxPly;                               /* 0xC8 */

typedef char AdxPly_size_check[sizeof(AdxPly) == ADXPLY_SIZE ? 1 : -1];

/* The handle's time, from the sample clock: count and count units per second. */
extern void func_0032A018(AdxPly *adxt, int *pos, int *rate);
/* The same on the vsync clock, when that clock is in use. */
extern void adxt_GetTime(AdxPly *adxt, int *ncount, int *tscale);
/* Samples waiting in output channel ch. */
extern int ADXT_GetNumSmplObuf(AdxPly *adxt, int ch);
/* Count one resynchronisation of the vsync clock (D_003D1428). */
extern int Obj0000_PostInc_D_003D1428_32A148(void);

#endif
