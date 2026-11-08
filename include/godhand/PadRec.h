/* include/godhand/PadRec.h - the pad record the input layer builds each frame.
 *
 * func_0031AFE0 turns one raw controller sample (PadSample) into a PadRec:
 * it keeps the previous frame's bit sets, maps the raw button words through
 * a 64 entry mask table into 64 bit sets, sets the stick direction bits and
 * derives the pressed and released edges.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_PADREC_H
#define GODHAND_PADREC_H

#define PAD_DIR_RIGHT_ST   0x80         /* dir bits set from the stick bytes */
#define PAD_DIR_LEFT_ST    0x40
#define PAD_DIR_UP_ST      0x10
#define PAD_DIR_DOWN_ST    0x20
#define PAD_DIR_A_POS      0x08
#define PAD_DIR_A_NEG      0x04
#define PAD_DIR_B_POS      0x01
#define PAD_DIR_B_NEG      0x02

/* One raw controller sample. */
typedef struct PadSample {
    unsigned int held;                  /* 0x00 raw button word 0 */
    char unk04[0x14];
    unsigned int heldB;                 /* 0x18 raw button word 1 */
    unsigned int heldC;                 /* 0x1C raw button word 2 */
    char unk20[0x40];
    unsigned char analog[0x14];         /* 0x60 analog bytes; the last four are the stick axes */
    float stickX;                       /* 0x74 */
    float stickY;                       /* 0x78 */
} PadSample;

typedef struct PadRec {
    unsigned long state;                /* 0x00 copy of held */
    unsigned int dir;                   /* 0x08 stick direction bits */
    unsigned int dirOld;                /* 0x0C last frame's dir */
    unsigned int dirNew;                /* 0x10 dir bits that came on this frame */
    char unk14[4];
    unsigned long held;                 /* 0x18 mapped button bits */
    unsigned long heldOld;              /* 0x20 last frame's held */
    unsigned long pressed;              /* 0x28 held bits that came on */
    unsigned long released;             /* 0x30 held bits that went off */
    unsigned long setC;                 /* 0x38 mapped from heldC */
    unsigned long setB;                 /* 0x40 mapped from heldB */
    char unk48[0x20];
    unsigned char analog[0x14];         /* 0x68 */
    float stickX;                       /* 0x7C */
    float stickY;                       /* 0x80 */
} PadRec;                              /* 0x84 used, rounded to 8 */

/* Byte offset of a PadRec or PadSample field, for the bodies that only match with a raw cast: a typed
 * member access lets the scheduler move loads across the plain int globals around it (func_0031AFE0). */
#define PADREC_OFFSET(field)    ((int)&((PadRec *)0)->field)
#define PADSAMPLE_OFFSET(field) ((int)&((PadSample *)0)->field)

typedef char PadRec_size_check[(sizeof(PadRec) == 0x88) ? 1 : -1];

#endif
