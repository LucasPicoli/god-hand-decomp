/* include/godhand/cHeatSys.h - the battle heat gauge.
 *
 * cHeatSys is the player's heat gauge. One instance sits at D_005CB000.
 * `cur` fills when the player hits things and drains with time; `lv` is
 * 0, 1 or 2 depending on how full the gauge is (under 50 %, up to 75 %,
 * above). `floor` is a lower bound that trails `cur` and stops the gauge
 * from draining past it. cHeatSys_GetHeatLv compares `cur` against `threshold`.
 *
 * Method names are the game's own (symbol table). Field names are ours,
 * read off the methods. Offsets are exact.
 */
#ifndef GODHAND_CHEATSYS_H
#define GODHAND_CHEATSYS_H

#define HEATSYS_LV_LOW_RATIO   0.5f
#define HEATSYS_LV_MID_RATIO   0.75f
#define HEATSYS_THRESHOLD_INIT 120.0f  /* initial threshold */
#define HEATSYS_MAX_BASE       120     /* max = 120 + 30 * (a byte of the player record) */
#define HEATSYS_MAX_STEP       30

typedef struct cHeatSys {
    float max;              /* 0x00 gauge capacity */
    float cur;              /* 0x04 current heat */
    float floor;            /* 0x08 cur cannot drain below this */
    float threshold;        /* 0x0C heat for lv 1 (GetHeatLv); heat mode puts floor at cur - threshold */
    unsigned char mode;     /* 0x10 nonzero while heat mode is active */
    char pad11[3];
    int lv;                 /* 0x14 0..2, see top comment */
} cHeatSys;                 /* 0x18 */

typedef char cHeatSys_size_check[sizeof(cHeatSys) == 0x18 ? 1 : -1];

#endif
