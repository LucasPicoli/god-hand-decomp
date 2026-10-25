/* include/godhand/adxPly.h - an ADX player handle (cygnus code at 0x3298F0).
 *
 * The handle is 0xC8 bytes. It owns an amp, a stream, up to two channels of
 * stream joints in three banks, one main joint and two helper objects. The
 * destroy call hands each of them back and clears the handle.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXPLY_H
#define GODHAND_ADXPLY_H

#include "godhand/criSj.h"

#define ADXPLY_SIZE     0xC8
#define ADXPLY_CH_MAX   2       /* channels per joint bank */

#define ADXPLY_STAT_RUN 1       /* stat: playing */

typedef struct AdxPly {
    signed char stat;                   /* 0x00 0 when the handle is free */
    char unk01[2];
    signed char maxnch;                 /* 0x03 number of channels in use */
    void *rsv04;                        /* 0x04 helper released by func_00326718 */
    int stm;                            /* 0x08 stream */
    void *rsv0C;                        /* 0x0C helper released by the tramp chain */
    SjObj *sjo;                         /* 0x10 main joint */
    char unk14[4];
    SjObj *sjiA[ADXPLY_CH_MAX];         /* 0x18 first joint bank */
    char unk20[0x74 - 0x20];
    void *amp;                          /* 0x74 */
    SjObj *sjiB[ADXPLY_CH_MAX];         /* 0x78 second joint bank */
    SjObj *sjiC[ADXPLY_CH_MAX];         /* 0x80 third joint bank */
    char unk88[0x94 - 0x88];
    void *rsv94;                        /* 0x94 */
    char unk98[ADXPLY_SIZE - 0x98];
} AdxPly;

#endif
