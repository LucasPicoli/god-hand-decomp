/* include/godhand/M2vHn.h - the Sofdec MPEG-2 video decoder handle (M2V).
 *
 * An M2V handle holds the decoder state for one stream. Two parts matter
 * here: the info record at 0x58 (0x80 bytes) that the caller reads back,
 * and the parsed sequence state at 0x160 that the info record is filled
 * from. M2V_FillInfo copies the sequence fields into the info record and
 * looks one byte up in a table indexed by three flags.
 *
 * Field names are ours: the fields were named by offset until the stream
 * layout is known. Offsets are exact: every body that uses this header
 * builds byte-identical to retail.
 */
#ifndef GODHAND_M2VHN_H
#define GODHAND_M2VHN_H

#define M2V_INFO_OFS   0x58
#define M2V_SEQ_OFS    0x160

/* The info record the caller reads back. */
typedef struct M2vInfo {
    int f00, f04, f08, f0C;             /* 0x00 */
    int f10, f14, f18, f1C;             /* 0x10 */
    int f20, f24, f28, f2C;             /* 0x20 */
    int f30, f34, f38, f3C;             /* 0x30 */
    int f40;                            /* 0x40 cleared */
    int f44;                            /* 0x44 set to 1 */
    int f48, f4C;                       /* 0x48 */
    unsigned short h50, h52;            /* 0x50 */
    unsigned char b54;                  /* 0x54 table lookup result */
    unsigned char b55, b56, b57;        /* 0x55 */
    unsigned char b58, b59, b5A, b5B;   /* 0x58 */
    unsigned char b5C, b5D, b5E, b5F;   /* 0x5C */
    unsigned char b60, b61, b62, b63;   /* 0x60 */
    unsigned char b64;                  /* 0x64 */
    char pad65[3];
    int f68;                            /* 0x68 */
    char pad6C[0x14];
} M2vInfo;                              /* 0x80 */

/* The parsed sequence state. Only the fields the info record needs are
 * named, by offset from the start of this record (handle + 0x160). Some
 * words are also read as a byte (b-fields of the same offset are casts). */
typedef struct M2vSeq {
    unsigned char b00;                 /* 0x00 */
    char pad01[0xB];
    unsigned char b0C;                 /* 0x0C */
    char pad0D[0x3];
    int f10;                           /* 0x10 */
    char pad14[0xC];
    unsigned char b20;                 /* 0x20 */
    char pad21[0x23];
    unsigned char b44;                 /* 0x44 */
    char pad45[0x3];
    int f48;                           /* 0x48 */
    int f4C;                           /* 0x4C */
    char pad50[0x10];
    unsigned char b60;                 /* 0x60 */
    char pad61[0x3];
    unsigned char b64;                 /* 0x64 */
    char pad65[0x3];
    unsigned char b68;                 /* 0x68 */
    char pad69[0x3];
    unsigned char b6C;                 /* 0x6C */
    char pad6D[0x3];
    unsigned char b70;                 /* 0x70 */
    char pad71[0x3];
    unsigned char b74;                 /* 0x74 */
    char pad75[0x3];
    unsigned char b78;                 /* 0x78 */
    char pad79[0x3];
    unsigned char b7C;                 /* 0x7C */
    char pad7D[0x3];
    unsigned short h80;                /* 0x80 */
    char pad82[0x2];
    unsigned short h84;                /* 0x84 */
    char pad86[0x36];
    int fBC;                           /* 0xBC */
    int fC0;                           /* 0xC0 */
    int fC4;                           /* 0xC4 */
    int fC8;                           /* 0xC8 */
    int fCC;                           /* 0xCC */
    char padD0[0xC];
    int fDC;                           /* 0xDC */
    int fE0;                           /* 0xE0 */
    char padE4[0x34];
    int f118;                          /* 0x118 */
    int f11C;                          /* 0x11C */
    char pad120[0x14];
    int f134;                          /* 0x134 */
    char pad138[0x4];
    unsigned char b13C;                /* 0x13C */
    char pad13D[0x187];
    int f2C4;                          /* 0x2C4 */
    int f2C8;                          /* 0x2C8 */
    int f2CC;                          /* 0x2CC */
    int f2D0;                          /* 0x2D0 */
    int f2D4;                          /* 0x2D4 */
    int f2D8;                          /* 0x2D8 */
    char pad2DC[0xE8];
    unsigned char b3C4;                /* 0x3C4 */
    char pad3C5[0x67];
    int f42C;                          /* 0x42C */
    char pad430[0xC];
    int f43C;                          /* 0x43C */
    char pad440[0x6C];
    int f4AC;                          /* 0x4AC */
} M2vSeq;

typedef struct M2vHandle {
    char unk00[M2V_INFO_OFS];
    M2vInfo info;                       /* 0x58 */
    char unkD8[M2V_SEQ_OFS - M2V_INFO_OFS - sizeof(M2vInfo)];
    M2vSeq seq;                         /* 0x160 */
} M2vHandle;

#endif
