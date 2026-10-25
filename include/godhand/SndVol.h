/* include/godhand/SndVol.h - a sound voice's volume record.
 *
 * Holds the voice the volume belongs to, the current volume and the volume
 * limit, both 16-bit and scaled by 2048 when handed to the voice. Names are
 * ours. Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SNDVOL_H
#define GODHAND_SNDVOL_H

#define SNDVOL_SHIFT    11      /* the voice takes the volume times 2048 */

typedef struct SndVol {
    char unk00[8];
    void *voice;                /* 0x08 */
    char unk0C[0x3C - 0x0C];
    short vol;                  /* 0x3C current volume */
    short volLimit;             /* 0x3E */
} SndVol;

#endif /* GODHAND_SNDVOL_H */
