/* include/godhand/SndSlide.h - a sound voice's slide record.
 *
 * The record holds the voice, the slide's target value and the rate that
 * scales the base value into a start point; a rate of 0.0 means the slide
 * starts at half the target. Names are ours. Offsets are exact. A field we
 * can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SNDSLIDE_H
#define GODHAND_SNDSLIDE_H

typedef struct SndSlide {
    char unk000[8];
    void *voice;                /* 0x008 */
    char unk00C[0x118 - 0x0C];
    int target;                 /* 0x118 */
    char unk11C[0x1E4 - 0x11C];
    float rate;                 /* 0x1E4 */
} SndSlide;

#endif /* GODHAND_SNDSLIDE_H */
