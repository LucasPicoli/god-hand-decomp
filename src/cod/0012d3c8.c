/* sn-2.95.3-136 matched TU. */
#include "godhand/cGrid.h"
#include "godhand/cVec.h"
#include "godhand/drawPrim.h"

/* Debug draw of a quad body: its outline, and with fill set the face filled
 * too. Mode 0 colours it by face kind, mode 1 by the face's colour class, and
 * modes 2..31 by whether the face's attributes have bit mode - 2. The
 * outline runs through the four corners and back to the first; the fill takes
 * them in strip order 0, 3, 1, 2. */
__attribute__((section(".text.func_0012D3C8")))
void func_0012D3C8(cCollBody *self, int mode, int fill)
{
    cVec line[5];
    cVec strip[4];
    cVec *p;
    int i;
    int j;
    unsigned short kind;
    unsigned int lineColor;
    unsigned int fillColor;

    p = line;
    i = 4;
    do {
        CVEC_ZERO(*p);
        p++;
    } while (--i != -1);
    CVEC_ASSIGN(line[0], &self->u.quad.corner[0]);
    CVEC_ASSIGN(line[1], &self->u.quad.corner[1]);
    CVEC_ASSIGN(line[2], &self->u.quad.corner[2]);
    CVEC_ASSIGN(line[3], &self->u.quad.corner[3]);
    CVEC_ASSIGN(line[4], &self->u.quad.corner[0]);
    p = strip;
    j = 3;
    do {
        CVEC_ZERO(*p);
        p++;
    } while (--j != -1);
    CVEC_ASSIGN(strip[0], &self->u.quad.corner[0]);
    CVEC_ASSIGN(strip[1], &self->u.quad.corner[3]);
    CVEC_ASSIGN(strip[2], &self->u.quad.corner[1]);
    CVEC_ASSIGN(strip[3], &self->u.quad.corner[2]);

    switch (mode) {
    case 0:
        kind = self->u.quad.face.kind;
        if (kind & 1) {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x80FF0000, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x20FF0000);
            }
        } else if (kind & 2) {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x20FFFFFF);
            }
        } else if (kind & 4) {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x8000FFFF, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x2000FFFF);
            }
        } else {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x80808080, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x80808080);
            }
        }
        break;
    case 1:
        if (fill == 0) {
            switch (self->u.quad.face.colorClass) {
            case 1: lineColor = 0x8000FFFF; break;
            case 2: lineColor = 0x80FF0000; break;
            case 3: lineColor = 0x80808080; break;
            case 4: lineColor = 0x8000FF00; break;
            case 5: lineColor = 0x80FFFFFF; break;
            case 0: case 6: case 7: case 8: case 9: /* retail's table covers 0..9 */
            default: lineColor = 0x800000FF; break;
            }
            Draw_Line2(line, 5, lineColor, 1);
        } else if (fill == 1) {
            switch (self->u.quad.face.colorClass) {
            case 1: fillColor = 0x2000FFFF; break;
            case 2: fillColor = 0x20FF0000; break;
            case 3: fillColor = 0x20808080; break;
            case 4: fillColor = 0x2000FF00; break;
            case 5: fillColor = 0x20FFFFFF; break;
            case 0: case 6: case 7: case 8: case 9:
            default: fillColor = 0x200000FF; break;
            }
            Draw_Line2(line, 5, 0x80FFFFFF, 1);
            func_001334A8(strip, 1, fillColor);
        }
        break;
    case 2 ... 31: {
        int n = mode - 2;
        int bits[32];

        __builtin_memcpy(bits, D_0041D2E0, sizeof(bits));
        if (self->u.quad.face.attr & bits[n]) {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x20FFFFFF);
            }
        } else {
            if (fill == 0) {
                Draw_Line2(line, 5, 0x800000FF, 1);
            } else if (fill == 1) {
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, 0x200000FF);
            }
        }
        break;
    }
    }
}
