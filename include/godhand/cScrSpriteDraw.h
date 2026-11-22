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
    char *sprites;                      /* 0x00 sprite records, 0x1C bytes each */
    char *texBase;                      /* 0x04 texture offset table; the textures follow it */
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
    unsigned short clip;                /* 0x30 0xFFFF = no clip */
    char unk32[2];
} cScrSpriteDraw;                       /* 0x34 */

/* The draw methods build their packets in this shape: a screen vertex is
 * (x, y, depth, 1.0), where the depth is the draw state's clip value. */
#define SCR_BASE_HEIGHT  448.0f         /* layout height the draw coordinates assume */
#define SCR_PKT_TAG      0x3001D        /* tag word written into the packet that comes back */

/* One sprite record: which texture, its texel window, and its size. */
typedef struct cScrSprite {
    unsigned char tex;                  /* 0x00 index into the texture offset table */
    char unk01[3];
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
    float w;                            /* 0x14 width, before the draw state's scale */
    float h;                            /* 0x18 */
} cScrSprite;                           /* 0x1C */

/* Bits of cScrTexCfg.mode (func_0015DB30 tests them). */
#define SCR_TEX_RECT  0x01              /* use the texel window u0..v1 */
#define SCR_TEX_TEST  0x20              /* use test as the packet's GS TEST value */

/* The texture draw config the packet builders take: a mode word, then the
 * texel window. The callers keep the whole 0x50 bytes on the stack. */
typedef struct cScrTexCfg {
    int mode;                           /* 0x00 SCR_TEX_* */
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
    char unk14[0x30 - 0x14];
    unsigned long test;                 /* 0x30 GS TEST register value */
    char unk38[0x50 - 0x38];
} cScrTexCfg;

typedef char cScrTexCfg_size_check[sizeof(cScrTexCfg) == 0x50 ? 1 : -1];

typedef struct cScrVtx {
    float x;
    float y;
    float z;
    float w;
} cScrVtx;

static __inline__ void cScrVtx_set(cScrVtx *v, float x, float y, int z) {
    v->x = x;
    v->y = y;
    v->z = (float)z;
    v->w = 1.0f;
}

extern float D_003C1184;                /* screen width (512.0) */
extern int D_003C11B0;                  /* draw mode word passed to the packet builders */

/* Float to unsigned int (definition in 001c8f30.c). */
unsigned int func_0031ED08(float f12);

/* One colour channel of the packed colour, scaled and clamped back to a byte
 * (func_0031ED08 does the clamp). */
#define SCR_CHAN(color, shift, scale) \
    func_0031ED08((float)(unsigned int)(((color) >> (shift)) & 0xFF) * (scale))

typedef char cScrSpriteDraw_size_check[(sizeof(cScrSpriteDraw) == 0x34) ? 1 : -1];

extern void cScrSpriteDraw_drawTex(cScrSpriteDraw *self, unsigned int tex, unsigned int color,
                                   float x, float y, float w, float h,
                                   float u0, float v0, float u1, float v1);

/* cScrSheet and its two functions are project names: the ELF names no such class.
 * One cell of a sprite sheet: its texture (-1 = the sheet's default) and its UV rectangle. */
typedef struct cScrSheetCell {
    int tex;                            /* 0x00 index into the system data file's offset table */
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
} cScrSheetCell;                        /* 0x14 */

typedef struct cScrSheet {
    int tex;                            /* 0x00 default texture */
    cScrSheetCell *cell;                /* 0x04 */
} cScrSheet;

/* Draw cell idx of a sheet over (x0, y0)-(x1, y1). */
void cScrSheet_drawCellBox(cScrSheet *sheet, int idx, unsigned int color, float x0, float y0, float x1, float y1);
/* The same with a size instead of the far corner. */
void cScrSheet_drawCell(cScrSheet *sheet, int idx, unsigned int color, float x, float y, float w, float h);

extern cScrSheetCell D_003C2478[]; /* its ten cells */
extern cScrSheet D_005E75A0; /* the panel frame's sheet */

#endif
