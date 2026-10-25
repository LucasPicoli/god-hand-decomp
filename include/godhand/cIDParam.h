/* include/godhand/cIDParam.h - the CustomID parameter record.
 *
 * cIDParam is a 0x2E0-byte record that cIDParam_initialize clears and then
 * fills with its defaults: a 256 x 224 screen, unit scales, a grey 0x80808080
 * tint and the default font settings. Names are ours, taken from the
 * defaults the initialiser writes. Offsets are exact. A field we can't name
 * yet stays as unkNNN padding.
 */
#ifndef GODHAND_CIDPARAM_H
#define GODHAND_CIDPARAM_H

#define CIDPARAM_SCREEN_W    256.0f
#define CIDPARAM_SCREEN_H    224.0f
#define CIDPARAM_TINT_GREY   0x80808080u
#define CIDPARAM_SIZE        0x2E0

typedef struct cIDParam {
    char unk00[2];
    char unk02;                 /* 0x02 starts at -1 */
    char unk03;                 /* 0x03 starts at -1 */
    char unk04[4];
    float screenW;              /* 0x08 */
    float screenH;              /* 0x0C */
    int unk10;                  /* 0x10 */
    int unk14;                  /* 0x14 */
    int unk18;                  /* 0x18 */
    char unk1C[0x28 - 0x1C];
    float scale28;              /* 0x28 starts at 1.0 */
    float scale2C;              /* 0x2C starts at 1.0 */
    float scale30;              /* 0x30 starts at 1.0 */
    char unk34[0x48 - 0x34];
    float scale48;              /* 0x48 starts at 1.0 */
    float scale4C;              /* 0x4C starts at 1.0 */
    unsigned int tint;          /* 0x50 */
    char unk54[4];
    char kind;                  /* 0x58 */
    char unk59;
    short level;                /* 0x5A */
    char unk5C[0x69 - 0x5C];
    char flag69;                /* 0x69 starts at 1 */
    char flag6A;                /* 0x6A starts at 1 */
    char flag6B;                /* 0x6B starts at 1 */
    short word6C;               /* 0x6C */
    short word6E;               /* 0x6E */
    char unk70[0x1B0 - 0x70];
    short word1B0;              /* 0x1B0 */
    char unk1B2[0x214 - 0x1B2];
    short word214;              /* 0x214 */
    char unk216[0x278 - 0x216];
    short word278;              /* 0x278 */
    char unk27A[0x2DC - 0x27A];
    unsigned int tint2DC;       /* 0x2DC */
} cIDParam;                     /* 0x2E0 */

typedef char cIDParam_size_check[sizeof(cIDParam) == CIDPARAM_SIZE ? 1 : -1];

#endif /* GODHAND_CIDPARAM_H */
