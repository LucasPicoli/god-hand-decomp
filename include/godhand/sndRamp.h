/* include/godhand/sndRamp.h - a sound parameter ramped toward a target. */
#ifndef GODHAND_SNDRAMP_H
#define GODHAND_SNDRAMP_H

/* A ramped parameter: the current value moves by step toward target. */
typedef struct SndRamp {
    short cur;                  /* 0x00 */
    short target;               /* 0x02 */
    short step;                 /* 0x04 */
    unsigned short count;       /* 0x06 steps taken */
} SndRamp;

/* The sound object whose four ramps func_00377688 steps. */
typedef struct SndRampOwner {
    char pad00[0x10];
    unsigned short flags;       /* 0x10 bit 0: a ramp moved this frame */
    char pad12[0x38 - 0x12];
    SndRamp ramp[4];            /* 0x38 */
    int active;                 /* 0x58 one bit per ramp still moving */
} SndRampOwner;

/* Move r one step toward its target, clamped there, and count the step. */
void func_00378070(SndRamp *r);

/* Step ramp no of self, clearing its active bit once it is at its target. */
void func_00377688(SndRampOwner *self, int no);

#endif /* GODHAND_SNDRAMP_H */
