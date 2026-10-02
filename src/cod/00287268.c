/* sn-2.95.3-136 matched TU. */

/* func_00287268: an enemy that holds one pose and growls at random intervals
 * while any actor is active. */
#include "godhand/cEm00.h"

extern void func_002A8578(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern int IsAnyActorActive_289418(void *a0);
extern float fRand0_1(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern char D_00462FC0[];
extern char D_005FEE00[];

__attribute__((section(".text.func_00287268")))
void func_00287268(cEm00 *self)
{
    int res;
    float t;

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
    case 0:
        self->gotoFlags = self->gotoFlags | 0x10;
        res = self->resource;
        func_002A8578(self, EM_RES_REC(res, 0x120), EM_RES_REC(res, 0x124), 0xA, 0.0f, 0, 0);
        self->timer = 10.0f;
        self->step = self->step + 1;
    case 1:
        self->hitFlash = 3.0f;
        moveMotion(self);
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    }
    if (IsAnyActorActive_289418(self) != 0) {
        t = self->timer - self->speedRate;
        self->timer = t;
        if (t <= 0.0f) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x60, self, 0, 0, 0, 0);
            self->timer = fRand0_1() * 30.0f + 60.0f;
        }
    } else {
        self->timer = 10.0f;
    }
}
