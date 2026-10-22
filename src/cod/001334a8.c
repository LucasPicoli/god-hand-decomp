/* sn-2.95.3-136: func_001334A8, debug draw of a triangle or quad of world points in one colour; each corner goes
 * through the screen matrix and nothing is drawn if one falls behind the camera or off the 4096 by 4096 screen. */
#include "godhand/cOmBase.h"
#include "godhand/reachObj.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

extern void func_0030A538(cVec *dst, cVec *src);
extern void *Gp_draw_poly3(void *v, int color, int count, int a4, int a5);
extern void *Gp_draw_poly4(void *v, int color, int count, void *ctx, int a5, int a6);

__attribute__((section(".text.func_001334A8")))
void func_001334A8(cVec *pts, int quad, int color)
{
    cVec v[4];
    cVec s;
    unsigned int n;
    unsigned int i;

    if (quad == 0) {
        func_0030A538(&v[0], &pts[0]);
        func_0030A538(&v[1], &pts[1]);
        func_0030A538(&v[2], &pts[2]);
        n = 3;
    } else {
        func_0030A538(&v[0], &pts[0]);
        func_0030A538(&v[1], &pts[1]);
        func_0030A538(&v[2], &pts[2]);
        func_0030A538(&v[3], &pts[3]);
        n = 4;
    }
    for (i = 0; i < n; i++) {
        VU0_SQC2_VF0_MEM(&s, 0);
        sceVu0ApplyMatrix(&s, D_005CAFF0, &v[i]);
        if (s.w == 0.0f) {
            return;
        }
        s.z = s.w;
        s.x = s.x / s.w;
        s.y = s.y / s.w;
        if (s.w < 0.0f) {
            return;
        }
        if (s.x < 0.0f) {
            return;
        }
        if (s.y < 0.0f) {
            return;
        }
        if (4096.0f < s.x) {
            return;
        }
        if (4096.0f < s.y) {
            return;
        }
    }
    if (quad == 0) {
        Gp_draw_poly3(v, color, 0, 2, 2);
    } else {
        Gp_draw_poly4(v, color, 0, 0, 2, 2);
    }
}
