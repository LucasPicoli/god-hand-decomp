/* sn-2.95.3-136 matched TU. */

#include "godhand/cScrSpriteDraw.h"

/* Draw a texture centred on (x, y): move the corner back by half the scaled size. */
__attribute__((section(".text.func_002C6550")))
void func_002C6550(cScrSpriteDraw *self, unsigned int tex, unsigned int color,
                   float x, float y, float w, float h,
                   float u0, float v0, float u1, float v1) {
    cScrSpriteDraw_drawTex(self, tex, color,
                           x - w * self->scaleX * 0.5f, y - h * self->scaleY * 0.5f,
                           w, h, u0, v0, u1, v1);
}
