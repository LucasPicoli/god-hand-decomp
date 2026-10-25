/* include/godhand/adxHdr.h - the ADX file header and its AINF chunk (cygnus code at 0x33E8A0..).
 *
 * An ADX header is big-endian. It starts with the magic 0x8000 and a copy
 * offset (the header length minus 4). Version 3 headers keep their loop
 * block at 0x14, version 4 headers at 0x20; a 16-bit flag there says
 * whether a 0x14-byte loop block follows. Then comes the optional AINF
 * chunk: the tag 'AINF', a 32-bit length, a 16-byte sound id, a 16-bit
 * volume and two 16-bit pan values.
 *
 * The reading macros are the shapes the compiler turns into the retail
 * byte loads (see the sibling decoders at 0x33E8A0 and 0x33EA98).
 */
#ifndef GODHAND_ADXHDR_H
#define GODHAND_ADXHDR_H

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

#define ADXHDR_MAGIC         0x8000
#define ADXHDR_TAG_AINF      0x41494E46          /* 'AINF' */
#define ADXHDR_VER4          4
#define ADXHDR_MIN_V3        0x3C                /* shortest header with an AINF chunk, version 3 */
#define ADXHDR_MIN_V4        0x48                /* the same for version 4 */
#define ADXHDR_LOOP_V3       0x14                /* offset of the loop block, version 3 */
#define ADXHDR_LOOP_V4       0x20                /* offset of the loop block, version 4 */
#define ADXHDR_LOOP_SIZE     0x14

#define ADXHDR_ERR_SHORT     (-1)
#define ADXHDR_ERR_FORMAT    (-2)

/* Byte-swapped reads of a big-endian field. */
#define ADXHDR_SWAP16(x)   ((((Uint16)(x)) >> 8) | ((((Uint16)(x)) << 8) & ~0xff))
#define ADXHDR_SWAP16B(p)  (((Uint8 *)(p))[1] | ((*(Uint16 *)(p) << 8) & ~0xff))
#define ADXHDR_SWAP32(x)   ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))
#define ADXHDR_GB(p, i)    ((Uint8)(p)[i])
#define ADXHDR_GET32(p)    ((ADXHDR_GB(p, 0) << 24) | (ADXHDR_GB(p, 1) << 16) | (ADXHDR_GB(p, 2) << 8) | ADXHDR_GB(p, 3))

/* The 16-byte sound id of the AINF chunk. */
typedef struct AdxAinfId {
    Uint8 b[16];
} AdxAinfId;

extern Sint32 ADX_DecodeInfoExVer(Sint8 *ibuf, Sint32 hdlen, Uint8 *ver, Uint8 *rev);

#endif
