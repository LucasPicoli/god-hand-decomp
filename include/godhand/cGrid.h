/* include/godhand/cGrid.h - a uniform grid over an axis-aligned box (sn code at 0x12F288..0x133948).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CGRID_H
#define GODHAND_CGRID_H

#include "godhand/cOmBase.h"

typedef struct cGrid {
    char unk00[0x30];
    cVec min;                           /* 0x30 */
    cVec max;                           /* 0x40 */
    cVec cell;                          /* 0x50 cell size */
    unsigned int num[3];                /* 0x60 cells per axis */
    int lo[3];                          /* 0x6C first cell the query box covers */
    int hi[3];                          /* 0x78 last cell */
    char unk84[0xC];
    cVec boxMin;                        /* 0x90 query box */
    cVec boxMax;                        /* 0xA0 */
} cGrid;

extern void func_00133948(void *self, void *boxMin, void *boxMax);
extern int func_00133408(void *unused, float *min, float *max, float *boxMin, float *boxMax);

#endif /* GODHAND_CGRID_H */
