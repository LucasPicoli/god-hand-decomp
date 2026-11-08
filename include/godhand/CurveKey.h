/* include/godhand/CurveKey.h - keyed Hermite curve track (0x159xxx).
 *
 * A track is an array of 16-byte keys. Each key holds a time and three
 * floats: the value, and the two tangents the cubic blend reads. A track is
 * found through a header record that holds the key count and the byte offset
 * of the first key from the base pointer the caller passes.
 */
#ifndef GODHAND_CURVEKEY_H
#define GODHAND_CURVEKEY_H

typedef struct CurveKey {
    unsigned short time;                /* 0x0 key time, compared as a float */
    unsigned short pad02;
    float value;                        /* 0x4 */
    float tanIn;                        /* 0x8 */
    float tanOut;                       /* 0xC */
} CurveKey;                             /* 0x10 */

typedef struct CurveTrack {
    char unk00[2];
    unsigned short count;               /* 0x2 number of keys */
    char unk04[4];
    int keyOfs;                         /* 0x8 byte offset of the first key from the base */
} CurveTrack;

typedef char CurveKey_chk_size[sizeof(CurveKey) == 0x10 ? 1 : -1];

#endif
