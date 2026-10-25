/* include/godhand/sndCurveSel.h - looking a value up on a sound bank curve (sn code at 0x3781F8).
 *
 * A bank's table starts with a header of offsets. One leads to an array of
 * 4-byte selector records, one per sound: byte 0 names the curve to use in the
 * normal output mode and byte 2 the curve for surround; a negative curve
 * means no curve. Another offset leads to the curve entries. A curve is a
 * list of (x, y) points sorted by x. A lookup returns the y of a point with
 * the same x, the last y past the end, or interpolates linearly between the
 * two points around the value.
 *
 * SndCurve.h describes the table of a sibling routine and uses other
 * offsets for the same bytes, so this header keeps its own records.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SNDCURVESEL_H
#define GODHAND_SNDCURVESEL_H

#define SNDCURVE_OUT_SURROUND  2    /* result of the output-mode query */

typedef struct SndCurveTblHdr {
    int unk00;
    int recOfs;                         /* 0x04 offset of the selector records */
    int curveOfs;                       /* 0x08 offset of the curve entries */
} SndCurveTblHdr;

typedef struct SndCurveSelRec {
    signed char curve;                  /* 0x00 curve index in the normal mode */
    signed char unk01;
    signed char curveSurround;          /* 0x02 curve index in surround mode */
    signed char unk03;
} SndCurveSelRec;

typedef struct SndCurveHead {
    int ptsOfs;                         /* 0x00 offset of the points from the table header */
    short unk04;
    unsigned short num;                 /* 0x06 number of points */
} SndCurveHead;

typedef struct SndCurveXY {
    short x;                            /* 0x00 */
    unsigned short y;                   /* 0x02 */
} SndCurveXY;

#endif
