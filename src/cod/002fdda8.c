/* sn-2.95.3-136 */
#include "godhand/sceVu0.h"

/* A screen position from sceVu0FTOI4Vector: 12.4 fixed point x/y, z. */
typedef struct ScreenPos {
    int x, y, z, w;
} __attribute__((aligned(16))) ScreenPos;

/* A cVec with the 16-byte alignment VU0 loads and stores need. */
typedef cVec ViewVec __attribute__((aligned(16)));

extern void sceVu0DivVector(void *a0, void *a1, float s);
extern void sceVu0FTOI4Vector(void *a0, void *a1);

/* Projects the origin of `m` to the screen. Writes a depth-based sort value
 * to *depth; returns 0 when the point lands inside the drawing area and in
 * front of the camera, -1 otherwise. */
__attribute__((section(".text.func_002FDDA8")))
int func_002FDDA8(void *m, int *depth)
{
    ViewVec v;
    ViewVec origin = { 0.0f, 0.0f, 0.0f, 1.0f };
    ScreenPos pos;
    int x, y;

    sceVu0ApplyMatrix(&v, m, &origin);
    *depth = (int)(v.w * 10.0f) + 50;
    sceVu0DivVector(&v, &v, v.w);
    sceVu0FTOI4Vector(&pos, &v);
    if (pos.z < 0) {
        return -1;
    }
    x = pos.x;
    y = pos.y;
    if (x < 0xA0 || x > 0xFF60) {
        return -1;
    }
    if (y >= 0xA0 && y <= 0xFF60) {
        return 0;
    }
    return -1;
}
