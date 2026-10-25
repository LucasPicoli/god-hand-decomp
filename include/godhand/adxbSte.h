/* include/godhand/adxbSte.h - the ADXB decoder's output-buffer wrap (CRI libadxe, 0x33D598).
 *
 * After a block is decoded, func_0033D598 works out how many samples the
 * output ring still has to hold and, when the write position has run past
 * the end of the ring, copies the overhang back to the start (stereo copies
 * both channels). This is the same 0x104-byte object as ADX_BASIC in
 * criStm.h; only the fields this function reads are named.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXBSTE_H
#define GODHAND_ADXBSTE_H

/* The decode work block at +0x48. */
typedef struct AdxbSteWork {
    int unk00;
    int unk04;
    int nch;                            /* 0x08 channels, 2 = stereo */
    int perFrame;                       /* 0x0C samples per frame */
    int frameLen;                       /* 0x10 samples per decode block */
    short *obuf;                        /* 0x14 the output ring */
    int unk18;
    int unk1C;
    int wpos;                           /* 0x20 write position in samples */
    int unk24;
    int total;                          /* 0x28 samples still to decode */
} AdxbSteWork;

typedef struct AdxbSte {
    char unk00[8];
    void *xpd;                          /* 0x08 */
    char unk0C[0x40 - 0x0C];
    int ringLen;                        /* 0x40 ring length in samples */
    int ringDist;                       /* 0x44 distance between the two channels' rings */
    AdxbSteWork work;                   /* 0x48 */
    char unk74[0x90 - 0x74];
    int outLen;                         /* 0x90 samples this block adds */
    int outGain;                        /* 0x94 */
    char unk98[0xE8 - 0x98];
    int unkE8;                          /* 0xE8 nonzero: copy as stereo */
    char unkEC[0x104 - 0xEC];
} AdxbSte;
typedef char AdxbSte_size_check[sizeof(AdxbSte) == 0x104 ? 1 : -1];

#endif
