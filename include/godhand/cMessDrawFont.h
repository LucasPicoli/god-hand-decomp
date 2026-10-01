/* include/godhand/cMessDrawFont.h - the message window text drawer.
 *
 * cMessDrawFont draws one message, one character at a time. It holds a
 * read cursor into the message body and one into the ruby (furigana) text,
 * a count of how many characters are drawn so far, and the layout settings
 * (position, scale, line spacing). Method names are the game's own; field
 * names are ours, taken from the setters and from cMessDrawFont_draw.
 * Offsets are exact: every body that uses this header builds
 * byte-identical to retail. A field we can't name yet stays as unkNNN.
 */
#ifndef GODHAND_CMESSDRAWFONT_H
#define GODHAND_CMESSDRAWFONT_H

#define MESSDRAWFONT_COUNT_NONE  0x0FFFFFFF  /* "draw it all" limit */

typedef struct cMessDrawFont {
    unsigned int flags;             /* 0x00 bit 0 = ruby text is drawn */
    void *body;                     /* 0x04 message text, as handed in */
    void *ruby;                     /* 0x08 ruby text, as handed in */
    void *bodyStart;                /* 0x0C first character of the message */
    void *bodyEnd;                  /* 0x10 end of the message, 0 = none */
    void *rubyStart;                /* 0x14 first ruby character */
    int drawCount;                  /* 0x18 characters drawn so far */
    int drawLimit;                  /* 0x1C stop after this many */
    float posX;                     /* 0x20 */
    float posY;                     /* 0x24 */
    unsigned int alignFlags;        /* 0x28 bit 0 = centre X, bit 1 = centre Y */
    float unk2C[2];                 /* 0x2C */
    float unk34[2];                 /* 0x34 */
    float charW;                    /* 0x3C */
    float charH;                    /* 0x40 */
    float zoomX;                    /* 0x44 */
    float zoomY;                    /* 0x48 */
    int unk4C[2];                   /* 0x4C */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
    int unk5C;                      /* 0x5C */
    float unk60;                    /* 0x60 */
    char *cursor;                   /* 0x64 read cursor in the body */
    char *rubyCursor;               /* 0x68 read cursor in the ruby */
    int charNum;                    /* 0x6C characters consumed */
    float sizeW;                    /* 0x70 laid out width */
    float sizeH;                    /* 0x74 laid out height */
    float unk78;                    /* 0x78 */
    float unk7C;                    /* 0x7C */
    float unk80;                    /* 0x80 */
    float unk84;                    /* 0x84 */
    float unk88;                    /* 0x88 */
    float unk8C;                    /* 0x8C */
} cMessDrawFont;                    /* at least 0x90 */

#endif
