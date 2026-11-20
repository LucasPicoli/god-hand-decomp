/* include/godhand/cCockGetPoint.h - cCockGetPoint, the cockfight point markers.
 *
 * cCockGetPoint is a cIDBase display object (vtable 0x0041DFB4) with eight
 * marker slots, each its own cIDBase display, and the marker id each slot
 * shows (MARKER_NONE when unused).
 */
#ifndef GODHAND_CCOCKGETPOINT_H
#define GODHAND_CCOCKGETPOINT_H

#include "godhand/cIDBase.h"
#include "godhand/cVecType.h"

#define MARKER_NUM   8
#define MARKER_NONE  (-1)               /* slot unused */
#define MARKER_LIFE  0x24               /* ids from here on are released after one draw */

/* A marker's display record, a cIDBase in a 0x50-byte slot. */
typedef struct cCockGetPointMark {
    cIDBaseObj id;                      /* 0x00 */
    char pad48[0x50 - sizeof(cIDBaseObj)];
} cCockGetPointMark;

typedef struct cCockGetPoint {
    cIDBaseObj base;                    /* 0x000 */
    char unk48[0x90 - sizeof(cIDBaseObj)];
    cCockGetPointMark rec[MARKER_NUM];  /* 0x090 display records */
    char unk310[0x33C - 0x310];
    signed char id[MARKER_NUM];         /* 0x33C marker id per slot, MARKER_NONE if unused */
} cCockGetPoint;

typedef char cCockGetPointMark_size_check[sizeof(cCockGetPointMark) == 0x50 ? 1 : -1];
typedef char cCockGetPoint_id_check[((int)&((cCockGetPoint *)0)->id == 0x33C) ? 1 : -1];

/* Show the points won at pos. Retail's body is empty: no parameter is read. */
void cCockGetPoint_setData(cCockGetPoint *self, cVec *pos, unsigned short point, short kind);

#endif
