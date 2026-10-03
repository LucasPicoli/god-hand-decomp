#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern unsigned char D_005FEE00[];

/* func_00281D98 */


/* Phase machine on the step byte, 4 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00281D98"))) void func_00281D98(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            switch (self->stepArg) {
                case 0:
                default:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x2C), EM_RES_REC(res, 0x30), 0.0f, 5, t0,
                                  0);
                    break;
                case 1:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x34), EM_RES_REC(res, 0x38), 0.0f, 5, t0,
                                  0);
                    break;
            }
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F6B0"))) void func_0027F6B0(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x3C), EM_RES_REC(res, 0x44), 0.0f, 5, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x3C), EM_RES_REC(res, 0x40), 0.0f, 5, 0, 0);
            }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00281E60"))) void func_00281E60(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x54), EM_RES_REC(res, 0x5C), 0.0f, 5, t0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x54), EM_RES_REC(res, 0x58), 0.0f, 5, t0, 0);
            }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027FD00"))) void func_0027FD00(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x80), EM_RES_REC(res, 0x88), 0.0f, 5, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x80), EM_RES_REC(res, 0x84), 0.0f, 5, 0, 0);
            }
            self->timerA = 1;
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}

/* Phase machine on the step byte, 4 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00280688"))) void func_00280688(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x158), EM_RES_REC(res, 0x15C), 0.0f, 2, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x160), EM_RES_REC(res, 0x164), 0.0f, 2, 0, 0);
            self->step = self->step + 1;
        case 3:
            moveMotion(self);
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls cSnd_SeCall_2CBA48, func_002A8578,
 * moveMotion. */
__attribute__((section(".text.func_0027C790"))) void func_0027C790(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 12, self, 0, 0, 0, 0);
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x40), EM_RES_REC(res, 0x44), 0.0f, 0, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x38), EM_RES_REC(res, 0x3C), 0.0f, 0, 0, 0);
            }
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
