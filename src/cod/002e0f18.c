/* sn-2.95.3-136 matched TU. */
#include "godhand/fileBuf.h"
#include "godhand/cScrSpriteDraw.h"
#include "godhand/drawPrim.h"
#include "godhand/gsPacket.h"
#include "godhand/globals.h"

/* Draw str from (x, y): one sprite per character, its 8x8 cell of the font
 * texture picked by sp_char_ck; '\n' moves to the next line, ' ' only
 * advances. Stops once the frame's character count is used up; otherwise leaves the
 * cursor after the string. */
__attribute__((section(".text.func_002E0F18")))
void func_002E0F18(char *str, int x, int y, unsigned int color, int depth)
{
    cScrVtx v[2];
    cScrTexCfg cfg;
    unsigned int w;
    unsigned int h;
    int noAlphaTest;
    unsigned int z;
    unsigned int cell;
    unsigned int u;
    unsigned int t;
    char ch;

    w = D_0061B280.charW;
    h = D_0061B280.charH;
    if (color < 0x10) {
        if (color & 8)
            noAlphaTest = 0;
        else
            noAlphaTest = 1;
        color = D_003C3B60[color & 7];
    } else {
        noAlphaTest = 1;
    }
    z = 0xFFFF - depth;
    while (*str != 0) {
        if (D_0061B280.drawn > FILEBUF_DRAWN_MAX)
            return;
        ch = *str;
        if (ch == '\n') {
            x = D_0061B280.curX = D_0061B280.lineX;
            y = D_0061B280.curY += 8;
        } else {
            if (ch != ' ') {
                cell = sp_char_ck(ch) - 0x20;
                u = (cell & 0x1F) * 8;
                t = (cell & 0xE0) >> 2;
                v[0].x = x;
                v[0].y = y;
                cfg.mode = 0;
                v[0].z = z;
                v[0].w = 1.0f;
                v[1].x = x + w;
                v[1].y = y + h;
                v[1].z = z;
                v[1].w = 1.0f;
                cfg.u0 = u * (1.0f / 256.0f);
                cfg.v0 = t * (1.0f / 32.0f);
                cfg.u1 = (u + 8) * (1.0f / 256.0f);
                cfg.v1 = (t + 8) * (1.0f / 32.0f);
                cfg.mode = SCR_TEX_RECT;
                if (noAlphaTest) {
                    cfg.mode = SCR_TEX_RECT | SCR_TEX_TEST;
                    cfg.test = GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, GS_ZTST_GEQUAL);
                }
                func_0015DB30(v, color, 0, &cfg, 8, 1);
                D_0061B280.drawn++;
            }
            x += D_0061B280.charW;
        }
        str++;
    }
    D_0061B280.curX = x;
}
