/* sn-2.95.3-136 */
#include "godhand/drawPrim.h"
#include "godhand/gameWork.h"
#include "godhand/gsPacket.h"
#include "godhand/sceVu0.h"

#define SYS_NO_LINES     0x40000000     /* D_00747A2C.unk00: Draw_Line_sc draws nothing */
#define GS_WINDOW_MAX    4095.9f        /* last GS window coordinate a point may have */
#define LINE_PT_OUT      0x80           /* the point is outside the GS window */
#define LINE_SCREEN      1              /* Gp_draw_line: the points are screen coordinates */
#define LINE_LIST        8              /* Gp_draw_line's list kind; it takes the position as given */
#define LINE_LIST_POS    2              /* the line's position in that list */

/* Draw a screen-space polyline: offset each point into GS window coordinates, flag points
 * outside the 0..4095.9 window and draw a segment only when both ends are inside. */
__attribute__((section(".text.Draw_Line_sc")))
void Draw_Line_sc(float (*pts)[4], unsigned int count, unsigned int color, int depthTest)
{
    LineAttr attr;
    float v[4];
    unsigned int i;
    int out;
    int prev;

    if (D_00747A2C.unk00 & SYS_NO_LINES)
        return;
    attr.flags = 0;
    if (!depthTest) {
        attr.flags = LINE_ATTR_TEST;
        attr.test = GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, GS_ZTST_ALWAYS);
    }
    count++;
    prev = 0;
    for (i = 0; i < count; i++) {
        v[0] = pts[i][0] + (float)(GS_WINDOW_CENTER - D_003C1180 / 2);
        v[1] = pts[i][1] + (float)D_00586B80;
        v[2] = pts[i][2];
        v[3] = 1.0f;
        sceVu0DivVector(v, v, 1.0f);
        out = 0;
        if (v[0] < 0.0f || GS_WINDOW_MAX < v[0] || v[1] < 0.0f || GS_WINDOW_MAX < v[1])
            out = LINE_PT_OUT;
        if (i != 0 && out == 0 && prev == 0)
            Gp_draw_line(&pts[i - 1], color, LINE_SCREEN, LINE_LIST, LINE_LIST_POS, &attr);
        prev = out;
    }
}
