/* sn-2.95.3-136 */
#include "godhand/cCollisionSolid.h"
#include "godhand/drawPrim.h"
#include "godhand/sceVu0.h"

/* Draw one edge of the box, from corner a to corner b. A macro: as an inline
 * function the corner addresses are computed once and the code shrinks. */
#define BOX_EDGE(self, line, a, b, color)                  \
    {                                                      \
        cVec_copy3(&(line)[0], &(self)->corner[a]);        \
        cVec_copy3(&(line)[1], &(self)->corner[b]);        \
        Draw_Line2((line), 2, (color), 1);                 \
    }

/* Debug draw of a box body: its twelve edges in color. */
__attribute__((section(".text.func_00133DA0")))
void func_00133DA0(cCollisionSolidBox *self, unsigned int color)
{
    cVec line[2];
    cVec *v;
    int i;

    /* the array constructor of line: zero both entries */
    v = line;
    i = 1;
    do {
        cVec_zero(v);
        v++;
    } while (--i != -1);
    BOX_EDGE(self, line, 0, 1, color);
    BOX_EDGE(self, line, 1, 2, color);
    BOX_EDGE(self, line, 2, 3, color);
    BOX_EDGE(self, line, 3, 0, color);
    BOX_EDGE(self, line, 4, 5, color);
    BOX_EDGE(self, line, 5, 6, color);
    BOX_EDGE(self, line, 6, 7, color);
    BOX_EDGE(self, line, 7, 4, color);
    BOX_EDGE(self, line, 0, 4, color);
    BOX_EDGE(self, line, 1, 5, color);
    BOX_EDGE(self, line, 2, 6, color);
    BOX_EDGE(self, line, 3, 7, color);
}
