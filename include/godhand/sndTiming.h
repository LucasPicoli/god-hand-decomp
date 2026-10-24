/* include/godhand/sndTiming.h - the sound system's timing block at D_0076A790 (sn code at 0x375380..0x377BC8).
 *
 * A version name copied in at reset (func_00377BC8), the frame counter and transfer time of the
 * per-frame update (func_00375380), and the timing peaks kept by func_00375500.
 */
#ifndef GODHAND_SNDTIMING_H
#define GODHAND_SNDTIMING_H

typedef struct SndTiming {
    char name[14];              /* 0x00 */
    char unk0E[2];
    int frame;                  /* 0x10 */
    int unk14;                  /* 0x14 */
    char unk18[4];
    int unk1C;                  /* 0x1C */
    short unk20;                /* 0x20 */
    char unk22[2];
    unsigned char nKind1;       /* 0x24 live voices of kind 1 */
    unsigned char nKind2;       /* 0x25 kind 2 */
    unsigned char nKind4;       /* 0x26 kind 4 */
    unsigned char nTotal;       /* 0x27 */
    char unk28[0x84 - 0x28];
    int unk84;                  /* 0x84 */
    char unk88[4];
    unsigned int time;          /* 0x8C */
    unsigned int timeMax;       /* 0x90 */
    unsigned int hblanks;       /* 0x94 */
    unsigned int hblanksMax;    /* 0x98 */
    unsigned int usec;          /* 0x9C */
    unsigned int usecMax;       /* 0xA0 */
    char unkA4[4];
    unsigned int unkA8;         /* 0xA8 */
    char unkAC[0x18];
} SndTiming;                    /* 0xC4 */

typedef char SndTiming_size_check[(sizeof(SndTiming) == 0xC4) ? 1 : -1];

extern SndTiming D_0076A790;

#endif /* GODHAND_SNDTIMING_H */
