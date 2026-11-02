#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_002821F0"))) void func_002821F0(cEm00 *self)
{
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x3C), EM_RES_REC(v, 0x40), 5, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x14), EM_RES_REC(v, 0x18), 5, 0.0f, t0, 0);
            }
            self->step++;
        case 1:
            moveMotion(self);
            break;
        case 2:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x44), EM_RES_REC(v, 0x48), 5, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x1C), EM_RES_REC(v, 0x20), 5, 0.0f, t0, 0);
            }
            self->step++;
        case 3:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        case 4:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x4C), EM_RES_REC(v, 0x50), 5, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x24), EM_RES_REC(v, 0x28), 5, 0.0f, t0, 0);
            }
            self->step++;
        case 5:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
