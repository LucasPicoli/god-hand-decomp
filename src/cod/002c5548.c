/* sn-2.95.3-136 */
#include "godhand/cScrSpriteDraw.h"
#include "godhand/capVu0.h"
#include "godhand/drawPrim.h"

/* Draw sprite no of the draw state's sprite table rotated by angle and
 * anchored at (x, y) by mode (0 centre, 1 top left, 2 top right, 3 bottom
 * left, 4 bottom right), scaled by scale about the screen's vertical centre
 * line and tinted by the packed colour. */
__attribute__((section(".text.func_002C5548")))
void func_002C5548(cScrSpriteDraw *self, int no, unsigned int color, unsigned int mode,
                   float x, float y, float angle, float scale)
{
    cScrVtx v[4];
    cScrTexCfg cfg;
    cScrSprite *sp = &((cScrSprite *)self->sprites)[no];
    float px = x + self->shiftX;
    float py = y + self->shiftY;
    float c = capVu0Cos(angle);
    float s = capVu0Sin(angle);
    float hw = sp->w * self->scaleX;
    float hh = sp->h * self->scaleY;
    float wc = hw * c;
    float ws = -hw * s;
    float hs = hh * s;
    float hc = hh * c;
    unsigned int a, b, g, r;
    struct Tim2FileHdr *tex;
    void *pkt;
    int i;

    switch (mode) {
    case 0:
        hw = sp->w * self->scaleX * 0.5f;
        hh = sp->h * self->scaleY * 0.5f;
        wc = hw * c;
        ws = -hw * s;
        hs = hh * s;
        hc = hh * c;
        v[0].x = px - wc - hs;
        v[0].y = py - ws - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = px + wc - hs;
        v[1].y = py + ws - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = px - wc + hs;
        v[2].y = py - ws + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = px + wc + hs;
        v[3].y = py + ws + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 1:
        v[0].x = px;
        v[0].y = py;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = px + wc;
        v[1].y = py - ws;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = px - hs;
        v[2].y = py + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = px + wc - hs;
        v[3].y = py - ws + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 3:
        v[0].x = px + hs;
        v[0].y = py - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = px + wc + hs;
        v[1].y = py - ws - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = px;
        v[2].y = py;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = px + wc;
        v[3].y = py - ws;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 2:
        v[0].x = px - wc;
        v[0].y = py + ws;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = px;
        v[1].y = py;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = px - wc - hs;
        v[2].y = py + ws + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = px - hs;
        v[3].y = py + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 4:
        v[0].x = px - wc + hs;
        v[0].y = py + ws - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = px + hs;
        v[1].y = py - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = px - wc;
        v[2].y = py + ws;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = px;
        v[3].y = py;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    }
    for (i = 0; i < 4; i++) {
        v[i].x = v[i].x * scale + D_003C1184 * (1.0f - scale) * 0.5f;
    }
    cfg.mode = 1;
    cfg.u0 = sp->u0;
    cfg.v0 = sp->v0;
    cfg.u1 = sp->u1;
    cfg.v1 = sp->v1;
    a = SCR_CHAN(color, 24, self->alphaScale);
    b = SCR_CHAN(color, 16, self->blueScale);
    g = SCR_CHAN(color, 8, self->greenScale);
    r = SCR_CHAN(color, 0, self->redScale);
    tex = (struct Tim2FileHdr *)(((int *)self->texBase)[sp->tex] + (int)self->texBase);
    pkt = Gp_draw_polyFT4(v, (a << 24) | (b << 16) | (g << 8) | r, 1, tex, D_003C11B0, 0x1CF0, &cfg,
                          self->colorNo, self->fontNo);
    if (pkt != 0) *(long *)((char *)pkt + 0x1A0) = SCR_PKT_TAG;
}
