/* include/godhand/SfdDec.h - the Sofdec decoder manager record (cygnus code at 0x3547B0).
 *
 * The record sits in the Sofdec handle at 0x23A8. It holds a copy of the
 * decoder configuration, the table of stream ids, a request queue, the
 * timing window and 16 stream slots (StmSlot, 0xF0 bytes each). Each slot
 * points at one 8-byte entry of the table at 0x109C.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDDEC_H
#define GODHAND_SFDDEC_H

#include "godhand/criStm.h"

#define SFDDEC_SLOT_NUM     16
#define SFDDEC_DEF_BUFCNT   5
#define SFDDEC_DEF_BUFSIZE  0xC0

/* The configuration words the init copies from D_00766BA8, D_00766BD0 and D_00766BD8. */
typedef struct SfdDecCfgA { int w[9]; } SfdDecCfgA;
typedef struct SfdDecCfgB { int w[2]; } SfdDecCfgB;
typedef struct SfdDecIds { int w[SFDDEC_SLOT_NUM]; } SfdDecIds;

typedef struct SfdDecEnt {
    int unk0, unk4;
} SfdDecEnt;

typedef struct SfdDecMgr {
    int unk00;                          /* 0x00 cleared */
    SfdDecCfgA cfgA;                    /* 0x04 */
    SfdDecCfgB cfgB;                    /* 0x28 */
    SfdDecIds ids;                      /* 0x30 stream id of each slot */
    int unk70;                          /* 0x70 cleared */
    int bufCnt;                         /* 0x74 SFDDEC_DEF_BUFCNT */
    int bufSize;                        /* 0x78 SFDDEC_DEF_BUFSIZE */
    int unk7C, unk80, unk84, unk88;     /* 0x7C cleared */
    char que[0x10C - 0x8C];             /* 0x8C request queue */
    int unk10C;                         /* 0x10C -1 */
    int unk110;                         /* 0x110 cleared */
    int unk114;                         /* 0x114 0x7FFFFFFF */
    char win[0x138 - 0x118];            /* 0x118 timing window */
    int unk138;                         /* 0x138 cleared */
    int unk13C;                         /* 0x13C 1 */
    char unk140[0x160 - 0x140];
    int unk160, unk164, unk168, unk16C, unk170, unk174;     /* 0x160 cleared */
    int num;                            /* 0x178 */
    int unk17C;
    StmSlot slot[SFDDEC_SLOT_NUM];      /* 0x180 */
    char work[0x109C - 0x1080];         /* 0x1080 */
    SfdDecEnt ent[SFDDEC_SLOT_NUM];     /* 0x109C */
} SfdDecMgr;

typedef char SfdDecMgr_chk_slot[((int)&((SfdDecMgr *)0)->slot == 0x180) ? 1 : -1];
typedef char SfdDecMgr_chk_ent[((int)&((SfdDecMgr *)0)->ent == 0x109C) ? 1 : -1];

#endif
