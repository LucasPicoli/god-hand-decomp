/* include/godhand/sftimTrk.h - the time tracker of the Sofdec timing code (0x3520D8).
 *
 * One tracker follows the stream clock for one channel: it counts the
 * frames seen since the clock last jumped (count), the longest run it saw
 * (span) and the clock stamp it saw last. A new stamp starts a fresh run.
 * Times are 64-bit.
 *
 * Field names are ours, from the one function that uses the record.
 */
#ifndef GODHAND_SFTIMTRK_H
#define GODHAND_SFTIMTRK_H

typedef struct SftimStamp {
    long time;                          /* 0x00 */
    long unit;                          /* 0x08 */
} SftimStamp;

typedef struct SftimTrk {
    int origin;                         /* 0x00 frame number the run started at */
    int count;                          /* 0x04 runs finished */
    int span;                           /* 0x08 longest run in frames */
    char unk0C[4];
    SftimStamp stamp;                   /* 0x10 the clock stamp last seen */
} SftimTrk;
typedef char SftimTrk_size_check[sizeof(SftimTrk) == 0x20 ? 1 : -1];

/* The stream clock offset the tracker keeps in the handle (-1 = unset). */
#define SFTIM_HN_CLOCKBASE(hn)  (*(long *)((char *)(hn) + 0x150))

#endif
