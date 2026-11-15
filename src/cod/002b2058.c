/* sn-2.95.3-136 matched TU. */
#include "godhand/cScrSpriteDraw.h"

/* Draws cell idx of a sprite sheet over the rectangle at (x, y) of size (w, h). */
__attribute__((section(".text.cScrSheet_drawCell")))
void cScrSheet_drawCell(cScrSheet *sheet, int idx, unsigned int color, float x, float y, float w, float h)
{
    cScrSheet_drawCellBox(sheet, idx, color, x, y, x + w, y + h);
}
