/* include/godhand/messPanel.h - a message panel: a framed window with a pointer tail and its text
 * (sn code at 0x201A00, 0x2B1890, 0x2B1C80).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MESSPANEL_H
#define GODHAND_MESSPANEL_H

#define PANEL_F_FRAME   0x08            /* flags: draw the frame */
#define PANEL_F_TEXT    0x10            /* flags: draw the text */
#define PANEL_F_COLOUR  0x20            /* flags: draw the text in colour unk94 */

typedef struct Panel {
    char unk00[0x14];
    int flags;                          /* 0x14 PANEL_F_* */
    char unk18[0x54 - 0x18];
    float scaleA;                       /* 0x54 text scale x */
    float scaleB;                       /* 0x58 text scale y */
    short ofsX;                         /* 0x5C text offset, 1 in the start pose */
    short ofsY;                         /* 0x5E -20 in the start pose */
    signed char align;                  /* 0x60 */
    char unk61;
    unsigned short tail;                /* 0x62 corner the pointer tail is drawn at, 0..3 */
    char unk64[0x68 - 0x64];
    int unk68;                          /* 0x68 */
    char unk6C[0x74 - 0x6C];
    unsigned short *body;               /* 0x74 text */
    unsigned short *rubyTop;            /* 0x78 ruby records */
    unsigned short *bodyEnd;            /* 0x7C end of the text shown so far */
    unsigned short *ruby;               /* 0x80 first ruby record past the shown text */
    int unk84;                          /* 0x84 */
    char unk88[4];
    int unk8C;                          /* 0x8C */
    char unk90[4];
    short unk94;                        /* 0x94 */
    char unk96[0x98 - 0x96];
    float frameW;                       /* 0x98 frame size in 24-pixel cells */
    float frameH;                       /* 0x9C */
    char unkA0[0xA4 - 0xA0];
    unsigned char kind;                 /* 0xA4 */
    char unkA5;
    unsigned short savedX;              /* 0xA6 start pose position */
    unsigned short savedY;              /* 0xA8 */
    char unkAA[4];
    unsigned short curX;                /* 0xAE position */
    unsigned short curY;                /* 0xB0 */
} Panel;

extern void func_002B1890(Panel *self);
extern void func_002B1C80(Panel *self);

#endif /* GODHAND_MESSPANEL_H */
