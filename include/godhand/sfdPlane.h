/* include/godhand/sfdPlane.h - the plane records of the Sofdec picture converters (CRI libsfd, src/cod/003666*..).
 *
 * A source plane describes a decoded picture (size in pixels and its data), a
 * destination plane the interleaved target (data pointer, row pitch). Field
 * names are ours, taken from the matched converters; offsets are exact.
 */
#ifndef GODHAND_SFDPLANE_H
#define GODHAND_SFDPLANE_H

typedef struct SfdSrcPlane {
    int unk00;
    unsigned char *data;                /* 0x04 */
    int height;                         /* 0x08 pixels */
    int width;                          /* 0x0C pixels */
} SfdSrcPlane;

typedef struct SfdDstPlane {
    int unk00;
    unsigned char *data;                /* 0x04 */
    char unk08[8];
    int pitch;                          /* 0x10 bytes between block rows */
} SfdDstPlane;

#endif
