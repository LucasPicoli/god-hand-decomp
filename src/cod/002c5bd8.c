/* sn-2.95.3-136 matched TU. */

#include "godhand/cScrSpriteDraw.h"

extern unsigned int func_0031ED08(float f12);
extern void *Gp_draw_polyG4(void *verts, unsigned int *colors, int n, int colorNo, int fontNo);

extern int D_003C118C;                  /* screen height in pixels */



/* Draw a flat quad at (x, y) of size (w, h) in the packed colour, with the
 * draw state's shift, scales and per-channel colour scales applied. */
__attribute__((section(".text.cScrSpriteDraw_drawPolyF")))
void cScrSpriteDraw_drawPolyF(cScrSpriteDraw *self, unsigned int color,
                              float x, float y, float w, float h) {
    cScrVtx v[4];
    unsigned int col[4];
    unsigned int a, b, g, r;
    void *pkt;
    float k = (float)D_003C118C / SCR_BASE_HEIGHT;
    float x0 = x + self->shiftX;
    float y0 = (y + self->shiftY) * k;
    float y1 = y0 + h * (self->scaleY * (float)D_003C118C / SCR_BASE_HEIGHT);

    cScrVtx_set(&v[0], x0, y0, self->clip);
    cScrVtx_set(&v[1], x0, y1, self->clip);
    cScrVtx_set(&v[2], x0 + w * self->scaleX, y0, self->clip);
    cScrVtx_set(&v[3], x0 + w * self->scaleX, y1, self->clip);
    a = SCR_CHAN(color, 24, self->alphaScale);
    b = SCR_CHAN(color, 16, self->blueScale);
    g = SCR_CHAN(color, 8, self->greenScale);
    r = SCR_CHAN(color, 0, self->redScale);
    color = (a << 24) | (b << 16) | (g << 8) | r;
    col[3] = color;
    col[2] = color;
    col[1] = color;
    col[0] = color;

    pkt = Gp_draw_polyG4(v, col, 1, self->colorNo, self->fontNo);
    if (pkt != 0) *(long *)((char *)pkt + 0x40) = SCR_PKT_TAG;
}

extern int D_003C118C;                  /* screen height in pixels */
extern int D_003C11B0;                  /* draw mode word passed to the packet builders */




#define SCR_TIM2_MAGIC  0x324D4954      /* "TIM2" */

/* Draw texture `tex` into the rectangle at (x, y) of size (w, h), tinted by
 * the packed colour. TIM2 textures go through one builder, the rest through
 * the other. */
__attribute__((section(".text.cScrSpriteDraw_drawTex")))
void cScrSpriteDraw_drawTex(cScrSpriteDraw *self, unsigned int tex, unsigned int color,
                            float x, float y, float w, float h,
                            float u0, float v0, float u1, float v1) {
    cScrVtx v[2];
    cScrTexCfg cfg;
    unsigned int a, b, g, r;
    void *pkt;
    float k = (float)D_003C118C / SCR_BASE_HEIGHT;
    float x0 = x + self->shiftX;
    float y0 = (y + self->shiftY) * k;
    float y1 = y0 + h * self->scaleY * k;

    v[0].z = (float)self->clip;
    v[0].w = 1.0f;
    v[1].x = x0 + w * self->scaleX;
    v[1].y = y1;
    v[1].z = (float)self->clip;
    v[1].w = 1.0f;
    cfg.mode = 1;
    cfg.u0 = u0;
    cfg.v0 = v0;
    cfg.u1 = u1;
    cfg.v1 = v1;
    v[0].x = x0;
    v[0].y = y0;

    a = SCR_CHAN(color, 24, self->alphaScale);
    b = SCR_CHAN(color, 16, self->blueScale);
    g = SCR_CHAN(color, 8, self->greenScale);
    r = SCR_CHAN(color, 0, self->redScale);
    color = (a << 24) | (b << 16) | (g << 8) | r;
    if (*(int *)tex == SCR_TIM2_MAGIC)
        pkt = func_0015D6E8(v, color, 0, (void *)tex, D_003C11B0, 0x1CF0, &cfg, self->colorNo, self->fontNo);
    else
        pkt = func_0015D168(v, color, 0, (void *)tex, D_003C11B0, 0x1CF0, &cfg, self->colorNo, self->fontNo);
    if (pkt != 0) *(long *)((char *)pkt + 0x1A0) = SCR_PKT_TAG;
}
