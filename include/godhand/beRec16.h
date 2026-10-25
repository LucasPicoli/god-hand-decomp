/* include/godhand/beRec16.h - a 16-byte big-endian record unpacked to host order (cygnus code at 0x32F988).
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_BEREC16_H
#define GODHAND_BEREC16_H

#define BEREC16_SIZE  0x10

typedef struct BeRec16 {
    unsigned int w0;            /* 0x00 */
    unsigned int w4;            /* 0x04 */
    unsigned char b8;           /* 0x08 */
    unsigned char b9;           /* 0x09 */
    unsigned short h0A;         /* 0x0A */
    unsigned int wC;            /* 0x0C */
} BeRec16;

#define BE32(p) (((unsigned int)(p)[0] << 24) | ((unsigned int)(p)[1] << 16) | ((unsigned int)(p)[2] << 8) | (p)[3])
#define BE16(p) (((unsigned int)(p)[0] << 8) | (p)[1])

#endif
