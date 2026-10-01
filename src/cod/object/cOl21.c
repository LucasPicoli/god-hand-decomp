/* TU: cOl21 [object] - recovered C++ class. */
#include "godhand/vu0.h"
#include "godhand/cOl21.h"
extern float fRand0_1(void);
extern unsigned int Rnd(void);


static __inline__ void cpy3(float *d, float *s) {
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

/* Set up a straight run: start at the current position, aim from goal towards end at speed ang, and start a random fraction of the way along it (mirrored half the time). */
__attribute__((section(".text.cOl21_initMove")))
void cOl21_initMove(cOl21 *self, float *goal, float *end, float ang) {
    unsigned char frame[0x20];
    float r, k, dx, dz;

    cpy3(self->start, self->pos);
    cpy3(self->goal, goal);
    cpy3(self->end, end);

    VU0_SQC2_VF0(frame, 0x10);
    VU0_LQC2(4, end, 0);
    VU0_LQC2(5, goal, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, frame + 0x10, 0);
    VU0_SQC2(4, frame, 0);

    r = fRand0_1();
    k = ang * r;
    dx = *(float *)(frame + 0) / ang;
    self->dir[1] = 0.0f;
    dz = *(float *)(frame + 8) / ang;
    self->dir[0] = dx;
    self->dir[2] = dz;
    self->pos[0] = goal[0] + self->dir[0] * k;
    self->pos[2] = goal[2] + self->dir[2] * k;
    if (((Rnd() ^ 1) & 1) != 0) {
        self->dir[0] = -self->dir[0];
        self->dir[2] = -self->dir[2];
    }
}
