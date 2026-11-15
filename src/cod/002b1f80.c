/* sn-2.95.3-136 matched TU. */
#include "godhand/cScrSpriteDraw.h"
#include "godhand/gameWork.h"
#include "godhand/drawPrim.h"

/* Draws cell idx of a sprite sheet over the rectangle (x0, y0)-(x1, y1); the texture is
 * the system data file entry the cell (or the sheet) names. */
__attribute__((section(".text.cScrSheet_drawCellBox")))
void cScrSheet_drawCellBox(cScrSheet *sheet, int idx, unsigned int color, float x0, float y0, float x1, float y1)
{
    cScrTexCfg cfg;
    cScrVtx v[2];
    cScrSheetCell *cell = &sheet->cell[idx];
    int tex = cell->tex;
    char *sys;
    char *data;

    if (tex == -1) {
        tex = sheet->tex;
    }
    sys = D_007474A0.sysData;
    data = (char *)(((int *)sys)[tex] + (int)sys);
    cfg.mode = 1;
    cfg.u0 = cell->u0;
    cfg.v0 = cell->v0;
    cfg.u1 = cell->u1;
    cfg.v1 = cell->v1;
    v[0].x = x0;
    v[0].y = y0;
    v[0].z = 65535.0f;
    v[0].w = 1.0f;
    v[1].x = x1;
    v[1].y = y1;
    v[1].z = 65535.0f;
    v[1].w = 1.0f;
    func_0015D168(v, color, 1, data, 0x3B00, 0x1CF0, &cfg, 6, 2);
}
