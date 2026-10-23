/* include/godhand/sndStream.h - a sound stream and the buffer it plays from (sn code at 0x373BA8, 0x374210).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SNDSTREAM_H
#define GODHAND_SNDSTREAM_H

typedef struct SndStream {
    void *handle;                       /* 0x00 the stream, created on buf */
    void *buf;                          /* 0x04 taken from the sound heap */
    int size;                           /* 0x08 bytes in buf */
    int unk0C;
    int nch;                            /* 0x10 channels */
} SndStream;

#endif /* GODHAND_SNDSTREAM_H */
