/* include/godhand/sndStream.h - a sound stream's buffer and handle (func_00373BA8, func_00374210). */
#ifndef GODHAND_SNDSTREAM_H
#define GODHAND_SNDSTREAM_H

typedef struct SndStream {
    void *handle;                       /* 0x00 */
    void *buf;                          /* 0x04 */
    int size;                           /* 0x08 */
    int unk0C;
    int nch;                            /* 0x10 */
} SndStream;

#endif /* GODHAND_SNDSTREAM_H */
