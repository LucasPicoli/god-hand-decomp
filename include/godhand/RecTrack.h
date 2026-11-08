/* include/godhand/RecTrack.h - a keyframe track cursor over a packed record.
 *
 * The cursor holds the kind of the record (1, 3 or 5), the position of the
 * current key in the blob, the key times that bracket the sampled time, and
 * the four floats of the cubic blend. RecDecode_readHeader fills it from a
 * record header; func_00159DA0 reads the key values once the cursor moved.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_RECTRACK_H
#define GODHAND_RECTRACK_H

#define RECTRACK_KIND_BYTES   1         /* keys are 4 bytes apart */
#define RECTRACK_KIND_SHORTS  3         /* 8 bytes apart */
#define RECTRACK_KIND_SHORTS2 5         /* 16 bytes apart */

typedef struct RecTrack {
    unsigned char kind;                 /* 0x00 0 when the track is empty */
    char unk01[3];
    char *src;                          /* 0x04 */
    char *cur;                          /* 0x08 current key */
    unsigned short t0;                  /* 0x0C key time at or before the sample */
    unsigned short t1;                  /* 0x0E next key time */
    float v0;                           /* 0x10 value at t0 */
    float v1;                           /* 0x14 value at t1 */
    float tanIn;                        /* 0x18 */
    float tanOut;                       /* 0x1C */
} RecTrack;

#endif
