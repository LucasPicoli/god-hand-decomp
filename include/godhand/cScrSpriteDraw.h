/* include/godhand/cScrSpriteDraw.h - the screen sprite draw state.
 *
 * cScrSpriteDraw is not a long-lived object. Callers keep one 0x34-byte
 * record on the stack, reset it with cScrSpriteDraw_drawInit (every scale
 * 1.0, colour table 6, font 5, no clip) and hand it to the draw methods as
 * `this`. The methods read the record to move, scale and tint what they
 * draw, then queue one packet each.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read the record.
 * Offsets are exact; a field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSCRSPRITEDRAW_H
#define GODHAND_CSCRSPRITEDRAW_H

typedef struct cScrSpriteDraw {
    char unk00[8];
    float shiftX;                       /* 0x08 added to x before the screen scale */
    float shiftY;                       /* 0x0C added to y */
    float scaleX;                       /* 0x10 multiplies the width */
    float scaleY;                       /* 0x14 multiplies the height */
    float alphaScale;                   /* 0x18 multiplies bits 24..31 of the packed colour */
    float redScale;                     /* 0x1C bits 0..7 */
    float greenScale;                   /* 0x20 bits 8..15 */
    float blueScale;                    /* 0x24 bits 16..23 */
    int colorNo;                        /* 0x28 colour table index */
    int fontNo;                         /* 0x2C */
    short clip;                         /* 0x30 0xFFFF = no clip */
    char unk32[2];
} cScrSpriteDraw;                       /* 0x34 */

typedef char cScrSpriteDraw_size_check[(sizeof(cScrSpriteDraw) == 0x34) ? 1 : -1];

extern void cScrSpriteDraw_drawTex(cScrSpriteDraw *self, unsigned int tex, unsigned int color,
                                   float x, float y, float w, float h,
                                   float u0, float v0, float u1, float v1);

#endif
