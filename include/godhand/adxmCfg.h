/* include/godhand/adxmCfg.h - the ADX manager configuration block (cygnus code at 0x325638).
 *
 * The manager keeps one configuration record at D_003C80B0. The init call
 * either copies a caller's record into it or fills in the defaults. Words 0
 * to 2 of the caller's record go to fields a, b and d; the block holds a
 * word c that the init never writes. The ADX server thread runs at
 * `prio`.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXMCFG_H
#define GODHAND_ADXMCFG_H

#define ADXM_DEF_A     1
#define ADXM_DEF_B     8
#define ADXM_DEF_D     0x10
#define ADXM_DEF_E     0x12
#define ADXM_DEF_PRIO  0x18
#define ADXM_DEF_G     0x19

/* What the caller hands to the init call. */
typedef struct AdxmInitArg {
    int a;                              /* 0x00 */
    int b;                              /* 0x04 */
    int d;                              /* 0x08 */
    int e;                              /* 0x0C */
    int prio;                           /* 0x10 */
    int g;                              /* 0x14 */
} AdxmInitArg;

/* The block the init fills in (D_003C80B0). */
typedef struct AdxmCfg {
    int a;                              /* 0x00 */
    int b;                              /* 0x04 */
    int unk08;                          /* 0x08 never written by the init */
    int d;                              /* 0x0C */
    int e;                              /* 0x10 */
    int prio;                           /* 0x14 thread priority of the server */
    int g;                              /* 0x18 */
} AdxmCfg;

#endif
