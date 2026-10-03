#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void func_002A74E0(void *a0, void *a1, int a2);

#include "godhand/vu0.h"


extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0,
                         float f12, float f13, float f14);








/* Phase machine on the step byte, 7 case labels. Calls aligned, VU0_LQC2, VU0_SQC2, func_00291010,
 * func_002A8578, moveMotion and 5 more. */
__attribute__((section(".text.func_00286AA8"))) void func_00286AA8(cEm00 *self)
{
    float buf[4] __attribute__((aligned(16)));
    int s1 = 1;
    int a;
    int bb;
    float *v1;

    {
        float *q = (float *)self->pos;
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, buf, 0);
    }
    if (func_00291010(&D_005864F0, buf, 0, 1, 0, self->rot.y, 10.0f, 3.14159274f) == 0) {
        s1 = 0;
    }
    switch (self->step) {
        case 0:
            self->gotoFlags = self->gotoFlags | 1;
            switch (self->stepArg) {
                case 0:
                default: {
                    int b = self->resource;
                    a = EM_RES_REC(b, 0xC0);
                    bb = EM_RES_REC(b, 0xC4);
                } break;
                case 1: {
                    int b = self->resource;
                    a = EM_RES_REC(b, 0xC8);
                    bb = EM_RES_REC(b, 0xCC);
                } break;
                case 2: {
                    int b = self->resource;
                    a = EM_RES_REC(b, 0xD0);
                    bb = EM_RES_REC(b, 0xD4);
                } break;
                case 3: {
                    int b = self->resource;
                    a = EM_RES_REC(b, 0xD8);
                    bb = EM_RES_REC(b, 0xDC);
                } break;
                case 4: {
                    int b = self->resource;
                    a = EM_RES_REC(b, 0x148);
                    bb = EM_RES_REC(b, 0x14C);
                } break;
            }
            func_002A8578(self, a, bb, 0.0f, 0xA, 0, 0);
            {
                float *dst = (float *)(&self->home);
                float *src = (float *)self->pos;

                if (dst != src) {
                    self->home.x = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                }
            }
            self->step++;
            /* fallthrough */
        case 1:
            v1 = (float *)self->pos;
            v1[0] = v1[0] * 0.99f + self->home.x * 0.01f;
            {
                float *p2 = (float *)self->pos;

                p2[2] = p2[2] * 0.99f + self->home.z * 0.01f;
            }
            if (0.0f < self->animRate) {
                moveMotion(self);
                cModel_calcNullPart(self);
                Add_nullspeed(self);
            }
            if (*(unsigned char *)((char *)self + 0x1560) != 5) {
                if (self->playerDist < 16.0f) {
                    if (func_00289328(self) != 0)
                        goto doit;
                }
                if (s1 == 0)
                    goto doit;
            }
            if ((self->gotoFlags & 8) == 0)
                break;
        doit:
            func_002A74E0(self, &self->unk1590, 1);
            func_002A7CA0(self, &self->unk1570);
            self->stepArg = 0;
            self->mode = 0;
            self->step = 0;
            self->phase = 4;
            break;
        default:
            break;
    }
}
