/* include/godhand/cWorldTime.h - cWorldTime, the game clock.
 *
 * The object holds two tick counters. func_002D9D50 splits a counter into
 * hours, minutes and seconds. Offsets are exact; every body that uses this
 * header builds byte-identical to retail.
 */
#ifndef GODHAND_CWORLDTIME_H
#define GODHAND_CWORLDTIME_H

typedef struct cWorldTime {
    unsigned int globalTime;    /* 0x00 ticks since the game started */
    unsigned int stageTime;     /* 0x04 ticks since the stage started */
} cWorldTime;

#endif
