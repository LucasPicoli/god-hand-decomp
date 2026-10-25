/* include/godhand/adxbLoop.h - fields of an ADX_BASIC handle past its AINF area
 * (cygnus code at 0x33CFF8). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXBLOOP_H
#define GODHAND_ADXBLOOP_H

/* The ADPCM decoder the handle owns (target of the 0x33F8 store helpers). */
typedef struct AdxbDec AdxbDec;

typedef struct AdxbLoop {
    short used;                 /* 0x00 */
    char unk02[6];
    AdxbDec *dec;               /* 0x08 */
    char unk0C[0xA6 - 0x0C];
    short loopStartX;           /* 0xA6 */
    short loopStartY;           /* 0xA8 */
    short loopStartZ;           /* 0xAA */
    unsigned short loopA;       /* 0xAC */
    unsigned short loopAHi;     /* 0xAE */
    unsigned short loopB;       /* 0xB0 */
    unsigned short loopBHi;     /* 0xB2 */
} AdxbLoop;

#endif
