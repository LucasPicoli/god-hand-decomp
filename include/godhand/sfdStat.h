/* include/godhand/sfdStat.h - the Sofdec playback statistics dump (cygnus code at 0x35CC80).
 *
 * When logging is on (D_003EE320 non-zero), func_0035CC80 formats the
 * handle's counters into one line (func_003A6C58 is sprintf) and appends
 * it to the log ring D_003EE328 (func_003A57C4 is strcat), wrapping the
 * write position when the ring is nearly full.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDSTAT_H
#define GODHAND_SFDSTAT_H

#define SFDSTAT_LINE_MAX  0x100         /* the format buffer on the caller's stack */

typedef struct SfdStat {
    char unk000[4];
    unsigned int stat4;                 /* 0x004 */
    unsigned int stat8;                 /* 0x008 */
    char unk00C[0x108 - 0x00C];
    long t108;                          /* 0x108 */
    char unk110[0x118 - 0x110];
    long t118;                          /* 0x118 */
    long t120;                          /* 0x120 */
    long t128;                          /* 0x128 */
    char unk130[0x188 - 0x130];
    long t188;                          /* 0x188 */
    int c190;                           /* 0x190 */
    int c194;                           /* 0x194 */
    int c198;                           /* 0x198 */
    int c19C;                           /* 0x19C */
    int c1A0;                           /* 0x1A0 */
    int c1A4;                           /* 0x1A4 */
    int c1A8;                           /* 0x1A8 */
    int c1AC;                           /* 0x1AC */
    int c1B0;                           /* 0x1B0 */
    int c1B4;                           /* 0x1B4 */
    int c1B8;                           /* 0x1B8 */
} SfdStat;

#endif
