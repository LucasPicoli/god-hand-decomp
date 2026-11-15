/* sn-2.95.3-136: func_002B1890, draw a message panel's frame as a nine-slice box plus its pointer tail. */
#include "godhand/cMessDrawFont.h"
#include "godhand/messPanel.h"
#include "godhand/cScrSpriteDraw.h"

extern cMessDrawFont D_005E7510;
extern cScrSheet D_005E75A0;            /* the panel frame's sheet */
extern cScrSheetCell D_003C2478[];      /* its ten cells */
extern unsigned int D_003C254C;         /* the frame colour */

__attribute__((section(".text.func_002B1890")))
void func_002B1890(Panel *self)
{
    long t;
    float x0, y0, w, h;
    float xe, x1, x2, wm, y1, hm, y2;
    cMessDrawFont *font;
    cScrSheet *spr;

    t = self->flags;
    if ((((unsigned long)t >> 3) & 1UL) == 0)    /* PANEL_F_FRAME */
        return;
    font = &D_005E7510;
    spr = &D_005E75A0;
    w = font->sizeW + self->frameW * 24.0f;
    x0 = (float)(short)self->savedX - 12.0f;
    y0 = (float)(short)self->savedY - 12.0f;
    h = font->sizeH + self->frameH * 24.0f;
    spr->cell = D_003C2478;
    x1 = x0 + 21.0f;
    wm = w - 42.0f;
    cScrSheet_drawCell(spr, 0, D_003C254C, x0, y0, 21.0f, 21.0f);
    xe = x0 + w;
    x2 = xe - 21.0f;
    cScrSheet_drawCell(spr, 1, D_003C254C, x1, y0, wm, 21.0f);
    y1 = y0 + 21.0f;
    hm = h - 42.0f;
    cScrSheet_drawCell(spr, 2, D_003C254C, x2, y0, 21.0f, 21.0f);
    cScrSheet_drawCell(spr, 3, D_003C254C, x0, y1, 21.0f, hm);
    cScrSheet_drawCell(spr, 4, D_003C254C, x1, y1, wm, hm);
    cScrSheet_drawCell(spr, 5, D_003C254C, x2, y1, 21.0f, hm);
    y2 = y0 + h - 21.0f;
    cScrSheet_drawCell(spr, 6, D_003C254C, x0, y2, 21.0f, 21.0f);
    cScrSheet_drawCell(spr, 7, D_003C254C, x1, y2, wm, 21.0f);
    cScrSheet_drawCell(spr, 8, D_003C254C, x2, y2, 21.0f, 21.0f);
    switch (self->tail) {
    case 1:
        cScrSheet_drawCell(spr, 9, D_003C254C, x0 - 42.0f, y1, self->frameW * 42.0f, self->frameH * 42.0f);
        break;
    case 2:
        cScrSheet_drawCell(spr, 9, D_003C254C, xe + 42.0f, y1, self->frameW * -42.0f, self->frameH * 42.0f);
        break;
    case 3:
        cScrSheet_drawCell(spr, 9, D_003C254C, x0 - 42.0f, y2, self->frameW * 42.0f, self->frameH * -42.0f);
        break;
    case 4:
        cScrSheet_drawCell(spr, 9, D_003C254C, xe + 42.0f, y2, self->frameW * -42.0f, self->frameH * -42.0f);
        break;
    }
}
