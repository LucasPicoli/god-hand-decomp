/* include/godhand/SfdPlay.h - the Sofdec player handle fields the 0x35D0 wrappers read
 * (cygnus code at 0x35D4A8). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDPLAY_H
#define GODHAND_SFDPLAY_H

#include "godhand/Sfd.h"

#define SFDPLAY_STAT_SETUP_A  3  /* states 3 and 4 accept a track call */
#define SFDPLAY_STAT_SETUP_B  4

typedef struct SfdPlay {
    char unk00[0x48];
    int stat;                   /* 0x48 */
    char unk4C[0x20D8 - 0x4C];
    int trno;                   /* 0x20D8 the track the player drives */
} SfdPlay;

extern int SfdTrack_callIfIdle(SfdHandle *self, int trno, int arg1, int arg2);

#endif
