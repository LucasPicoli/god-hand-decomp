#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00282A18"))) void func_00282A18(cEm00 *self)
{
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x120), EM_RES_REC(v, 0x124), 2, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x108), EM_RES_REC(v, 0x10C), 2, 0.0f, t0, 0);
            }
            self->step++;
            goto L_mm;
        case 2:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x128), EM_RES_REC(v, 0x12C), 2, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x110), EM_RES_REC(v, 0x114), 2, 0.0f, t0, 0);
            }
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            if (*(unsigned char *)((char *)self + 0x15B0)) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x130), EM_RES_REC(v, 0x134), 2, 0.0f, t0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x118), EM_RES_REC(v, 0x11C), 2, 0.0f, t0, 0);
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
