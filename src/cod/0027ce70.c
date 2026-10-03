#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int moveMotion(void *a0);

/* Phase machine on the step byte, 4 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F5F0"))) void func_0027F5F0(cEm00 *self)
{
    int res;

    switch (self->step) {
        case 0:
            switch (self->stepArg) {
                default:
                case 0:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x2C), EM_RES_REC(res, 0x30), 5, 0.0f, 0,
                                  0);
                    break;
                case 1:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x34), EM_RES_REC(res, 0x38), 5, 0.0f, 0,
                                  0);
                    break;
            }
            self->step++;
        case 1:
            moveMotion(self);
            break;
    }
}

/* Phase machine on the step byte, 5 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027CE70"))) void func_0027CE70(cEm00 *self)
{
    int res;

    switch (self->step) {
        case 0:
            switch (self->stepArg) {
                default:
                case 1:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x78), EM_RES_REC(res, 0x7C), 0, 0.0f, 0,
                                  0);
                    break;
                case 0:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x78), EM_RES_REC(res, 0x7C), 0, 0.0f, 0,
                                  0);
                    break;
                case 2:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0x78), EM_RES_REC(res, 0x7C), 0, 0.0f, 0,
                                  0);
                    break;
            }
            *(int *)((char *)self + 0x15D4) = 0;
            self->step++;
        case 1:
            moveMotion(self);
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00282120"))) void func_00282120(cEm00 *self)
{
    int res;

    switch (self->step) {
        case 0:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x8C), EM_RES_REC(res, 0x90), 5, 0.0f, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x84), EM_RES_REC(res, 0x88), 5, 0.0f, 0, 0);
            }
            self->step++;
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
__attribute__((section(".text.func_0027FDD8"))) void func_0027FDD8(cEm00 *self)
{
    int res;

    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x8C), EM_RES_REC(res, 0x94), 5, 0.0f, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x8C), EM_RES_REC(res, 0x90), 5, 0.0f, 0, 0);
            }
            self->timerA = 1;
            self->step++;
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
__attribute__((section(".text.func_00282388"))) void func_00282388(cEm00 *self)
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
                func_002A8578(self, EM_RES_REC(res, 0x94), EM_RES_REC(res, 0x9C), 5, 0.0f, t0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x94), EM_RES_REC(res, 0x98), 5, 0.0f, t0, 0);
            }
            self->step++;
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
__attribute__((section(".text.func_00282928"))) void func_00282928(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;

    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x158), EM_RES_REC(res, 0x15C), 2, 0.0f, t0, 0);
            self->step++;
        case 1:
            moveMotion(self);
            break;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x160), EM_RES_REC(res, 0x164), 2, 0.0f, t0, 0);
            self->step++;
        case 3:
            moveMotion(self);
            break;
    }
}
