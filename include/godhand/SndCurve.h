/* include/godhand/SndCurve.h - sound bank curves (sn code at 0x378398).
 *
 * A bank's table (SndBank.tbl) starts with a small header of offsets. One
 * offset leads to an array of 4-byte records, one per sound; each record
 * names, in two signed bytes, the curve to use (one for the normal mode,
 * one for the stereo mode). Another offset leads to the curve entries. A
 * curve is a list of (x, y) points sorted by x; looking a value up finds
 * the two points around it and interpolates linearly between their y.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SNDCURVE_H
#define GODHAND_SNDCURVE_H

#define SNDCURVE_MODE_STEREO  2     /* result of the output-mode query */

typedef struct SndCurveHdr {
    int unk00;
    int recOfs;                         /* 0x04 offset of the SndCurveRec array */
    int unk08;
    int curveOfs;                       /* 0x0C offset of the SndCurveEnt array */
} SndCurveHdr;

typedef struct SndCurveRec {
    signed char unk00;
    signed char curveMono;              /* 0x01 curve index in the normal mode, <0 for none */
    signed char unk02;
    signed char curveStereo;            /* 0x03 curve index in the stereo mode */
} SndCurveRec;

typedef struct SndCurveEnt {
    int ofs;                            /* 0x00 offset of the points */
    short unk04;
    unsigned short num;                 /* 0x06 number of points */
} SndCurveEnt;

typedef struct SndCurvePt {
    short x;                            /* 0x00 */
    unsigned short y;                   /* 0x02 */
} SndCurvePt;

/* The caller's sound: bank number and record index. */
typedef struct SndCurveRef {
    short bank;                         /* 0x00 index into D_0076DF10 */
    char unk02[0x1C];
    signed char rec;                    /* 0x1E */
} SndCurveRef;

#endif
