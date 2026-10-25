/* include/godhand/adxFilter.h - the 12-bit fixed-point stereo mixer (0x3407A0).
 *
 * One call mixes one sample pair. The input sample is scaled by two table
 * gains, the pair is turned by a 2x2 rotation held as constants, and the
 * result is added to the sample the delay lines held and written back into
 * them. The output pair is clamped to 16 bits. The delay lines are two
 * int arrays walked by one ring index.
 *
 * Field names are ours, from the one function that uses the record.
 */
#ifndef GODHAND_ADXFILTER_H
#define GODHAND_ADXFILTER_H

#define ADXFILTER_SHIFT   12            /* gains are 12-bit fixed point */
#define ADXFILTER_COS     3567          /* 0xDEF */
#define ADXFILTER_SIN     2006          /* 0x7D6 */

extern int D_00456B18[];                /* gain table */

typedef struct AdxFilter {
    char unk00[8];
    int *lineL;                         /* 0x08 delay line, left */
    int *lineR;                         /* 0x0C delay line, right */
    char unk10[4];
    int pos;                            /* 0x14 ring index */
    int len;                            /* 0x18 ring length */
    int gainA;                          /* 0x1C index into D_00456B18 */
    int gainB;                          /* 0x20 */
    int gainOutA;                       /* 0x24 gain for the feedback pair */
    int gainOutB;                       /* 0x28 */
} AdxFilter;

#endif
