#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00282460"))) void func_00282460(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                if (*(unsigned char *)((char *)self + 0x15B0)) {
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xAC), EM_RES_REC(res, 0xB4), 0.0f, 5, 0,
                                  0);
                } else {
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xA0), EM_RES_REC(res, 0xA8), 0.0f, 5, 0,
                                  0);
                }
            } else {
                if (*(unsigned char *)((char *)self + 0x15B0)) {
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xAC), EM_RES_REC(res, 0xB0), 0.0f, 5, 0,
                                  0);
                } else {
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xA0), EM_RES_REC(res, 0xA4), 0.0f, 5, 0,
                                  0);
                }
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
